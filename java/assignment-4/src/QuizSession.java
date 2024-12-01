import java.util.concurrent.BlockingQueue;

public class QuizSession implements Runnable {

    private final Student student;
    private final Quiz quiz;
    private int score;
    private final BlockingQueue<String> commands;
    private boolean running = true;

    public QuizSession(Student student, Quiz quiz, BlockingQueue<String> commands) {
        this.student = student;
        this.quiz = quiz;
        this.score = 0;
        this.commands = commands;
    }

    private String[] parseCommand(String command) {
        String[] tokensArray = command.split(":");
        return tokensArray;
    }

    public void stop() {
        running = false;
    }

    @Override
    public void run() {
        System.out.println("Quiz Started: " + quiz.getQuizId() + " " + quiz.getTitle() + " by " + student.getUserId());
        long endTime = System.currentTimeMillis() + quiz.getDuration() * 60 * 1000;
        while (running && System.currentTimeMillis() < endTime) {
            try {
                String command = commands.poll();
                if (command != null) {
                    String[] inputs = parseCommand(command);

                    switch (inputs[0]) {
                        case "answer":
                            String questionId = inputs[1];
                            String answer = inputs[2];
                            if (quiz.answerQuestion(questionId, answer)) {
                                score += quiz.getQuestion(questionId).getPoints();
                            }
                            System.out.println("Answer Submitted for " + questionId + " by " + student.getUserId());
                            break;
                        case "score":
                            System.out.println(
                                    "Score for " + student.getUserId() + " in " + quiz.getQuizId() + ": " + score);
                            break;
                    }
                }
                Thread.sleep(100);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        System.out.println("Quiz Ended for " + student.getUserId());
    }

}
