import java.util.ArrayList;

public class Question {
    private String question;
    private int points;
    private ArrayList<String> answers;
    private String correctAnswer;

    // constructor
    public Question(String question, int points, ArrayList<String> answers, String correctAnswer) {
        this.question = question;
        this.points = points;
        this.answers = answers;
        this.correctAnswer = correctAnswer;
    }

    // getters
    public String getQuestion() {
        return question;
    }

    public int getPoints() {
        return points;
    }

    public ArrayList<String> getAnswers() {
        return answers;
    }

    public String getCorrectAnswer() {
        return correctAnswer;
    }
}
