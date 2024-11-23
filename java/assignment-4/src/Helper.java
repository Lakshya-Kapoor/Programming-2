import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Helper {
    public <T> void print(T message) {
        System.out.println(message);
    }

    public void processCommand(HashMap<String, User> users, HashMap<String, User> activeUsers,
            HashMap<String, Quiz> quizzes, Scanner scanner) {
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

                    User newStudent = new Student(userId, name, email, password);
                    users.put(userId, newStudent);
                    print("Student Registered: " + newStudent);
                    break;

                case "REGISTER_ADMIN":
                    userId = inputs[1];
                    name = inputs[2];
                    email = inputs[3];
                    password = inputs[4];

                    // TODO: check if userId already exists

                    User newAdmin = new Admin(userId, name, email, password);
                    users.put(userId, newAdmin);
                    print("Admin Registered: " + newAdmin);
                    break;

                case "LOGIN":
                    userId = inputs[1];
                    password = inputs[2];

                    // TODO: check if user already logged in

                    User user = users.get(userId);
                    if (user == null || !user.getPassword().equals(password)) {
                        print("Invalid userId or password");
                        break;
                    }

                    activeUsers.put(userId, user);
                    print("User " + userId + " logged in");
                    break;

                case "LOGOUT":
                    userId = inputs[1];

                    // TODO: check if user already logged out

                    activeUsers.remove(userId);
                    print("User " + userId + " logged out");
                    break;

                case "CREATE_MCQ_QUIZ":
                    String quizId = inputs[1];
                    String title = inputs[2];
                    int duration = Integer.parseInt(inputs[3]);

                    // TODO: check if admin is creating the quiz
                    // TODO: check if quizId already exists

                    Quiz newQuiz = new Quiz(quizId, title, duration);
                    quizzes.put(quizId, newQuiz);
                    print("Quiz Created: " + quizId + " " + title);
                    break;

                case "ADD_MCQ_QUESTION":

                    break;

                default:
                    break;
            }
        }
    }

    // Helper method to parse commands with quoted strings
    private String[] parseCommand(String command) {
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
