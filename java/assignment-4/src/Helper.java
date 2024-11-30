import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Helper {
    public <T> void print(T message) {
        System.out.println(message);
    }

    private ArrayList<String> parseOptions(String options) {
        ArrayList<String> answers = new ArrayList<>();
        Matcher matcher = Pattern.compile("[^;]+").matcher(options);
        while (matcher.find()) {
            answers.add(matcher.group());
        }

        return answers;
    }

    public void processCommand(HashMap<String, User> users, HashMap<String, User> activeUsers,
            HashMap<String, Quiz> quizzes, Scanner scanner) {
        ConcurrentHashMap<String, BlockingQueue<String>> userCommands = new ConcurrentHashMap<>();
        // HashMap<String, Thread> quizThreads = new HashMap<>();
        // HashMap<String, QuizSession> quizSessions = new HashMap<>();
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine();
            String[] inputs = parseCommand(command);

            switch (inputs[0]) {
                case "REGISTER_STUDENT":
                    String userId = inputs[1];
                    String name = inputs[2];
                    String email = inputs[3];
                    String password = inputs[4];

                    // TODO: check if userId already exists

                    User user = new Student(userId, name, email, password);
                    users.put(userId, user);
                    print("Student Registered: " + userId + " " + name);
                    break;

                case "REGISTER_ADMIN":
                    userId = inputs[1];
                    name = inputs[2];
                    email = inputs[3];
                    password = inputs[4];

                    // TODO: check if userId already exists

                    user = new Admin(userId, name, email, password);
                    users.put(userId, user);
                    print("Admin Registered: " + userId + " " + name);
                    break;

                case "LOGIN":
                    userId = inputs[1];
                    password = inputs[2];

                    // TODO: check if user already logged in

                    user = users.get(userId);
                    if (user == null || !user.getPassword().equals(password)) {
                        print("Invalid userId or password");
                        break;
                    }

                    activeUsers.put(userId, user);
                    print("User " + userId + " logged in");
                    break;

                case "LOGOUT":
                    userId = inputs[1];

                    activeUsers.remove(userId);
                    print("User " + userId + " logged out");
                    break;

                case "CREATE_MCQ_QUIZ":
                    userId = inputs[1];
                    String quizId = inputs[2];
                    String title = inputs[3];
                    int duration = Integer.parseInt(inputs[4]);

                    user = activeUsers.get(userId);
                    if (user == null || user instanceof Student) {
                        print("Error: Access Denied for user " + userId);
                        break;
                    }

                    // TODO: check if quizId already exists

                    Quiz quiz = new Quiz(quizId, title, duration);
                    quizzes.put(quizId, quiz);
                    print("MCQ Quiz Created: " + quizId + " " + title);
                    break;

                case "ADD_MCQ_QUESTION":
                    userId = inputs[1];
                    quizId = inputs[2];
                    String questionId = inputs[3];
                    String questionText = inputs[4];
                    int points = Integer.parseInt(inputs[5]);
                    String options = inputs[6];
                    String answer = inputs[7];

                    user = activeUsers.get(userId);
                    if (user == null || user instanceof Student) {
                        print("Error: Access Denied for user " + userId);
                        break;
                    }

                    quiz = quizzes.get(quizId);
                    if (quiz == null) {
                        print("Error: Quiz " + quizId + " not found");
                        break;
                    }

                    ArrayList<String> answers = parseOptions(options);

                    Question question = new Question(questionText, points, answers, answer);
                    try {
                        quiz.addQuestion(questionId, question);
                        print("MCQ Question Added: " + questionId);
                    } catch (RuntimeException e) {
                        print(e.getMessage());
                        break;
                    }
                    break;

                case "START_QUIZ":
                    userId = inputs[1];
                    quizId = inputs[2];

                    user = activeUsers.get(userId);
                    if (user == null || user instanceof Admin) {
                        print("Error: Access Denied for user " + userId);
                        break;
                    }

                    quiz = quizzes.get(quizId);
                    if (quiz == null) {
                        print("Error: Quiz " + quizId + " not found");
                        break;
                    }

                    BlockingQueue<String> commandQueue = new LinkedBlockingQueue<>();
                    userCommands.put(userId, commandQueue);
                    QuizSession quizSession = new QuizSession((Student) user, quiz, commandQueue);
                    Thread quizThread = new Thread(quizSession);
                    quizThread.start();
                    break;

                case "ANSWER_QUESTION":
                    userId = inputs[1];
                    quizId = inputs[2];
                    questionId = inputs[3];
                    answer = inputs[4];

                    userCommands.get(userId).offer("answer:" + questionId + ":" + answer);
                    break;

                case "VIEW_SCORE":
                    userId = inputs[1];
                    quizId = inputs[2];

                    userCommands.get(userId).offer("score");
                    break;

                case "EXIT":
                    return;

                default:
                    break;
            }
        }
    }

    // Helper method to parse commands with quoted strings
    public String[] parseCommand(String command) {
        ArrayList<String> tokens = new ArrayList<>();
        Matcher matcher = Pattern.compile("\"([^\"]*)\"|(\\S+)").matcher(command);

        while (matcher.find()) {
            if (matcher.group(1) != null) {
                // Add quoted strings
                tokens.add(matcher.group(1));
            } else {
                // Add unquoted words
                tokens.add(matcher.group(2));
            }
        }

        return tokens.toArray(new String[0]);
    }
}
