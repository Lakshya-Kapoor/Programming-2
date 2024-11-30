import java.util.ArrayList;

public class Question {
    private String question;
    private int points;
    private ArrayList<String> options;
    private String correctAnswer;

    // constructor
    public Question(String question, int points, ArrayList<String> options, String correctAnswer) {
        this.question = question;
        this.points = points;
        this.options = options;
        this.correctAnswer = correctAnswer;
    }

    // getters
    public String getQuestion() {
        return question;
    }

    public int getPoints() {
        return points;
    }

    public ArrayList<String> getOptions() {
        return options;
    }

    public String getCorrectAnswer() {
        return correctAnswer;
    }
}
