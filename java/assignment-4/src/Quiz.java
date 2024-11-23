import java.util.HashMap;

public class Quiz {

    private String quizId;
    private String title;
    private int duration;
    private HashMap<String, Question> questions;

    public Quiz(String quizId, String title, int duration) {
        this.quizId = quizId;
        this.title = title;
        this.duration = duration;
        this.questions = new HashMap<>();
    }

    public String getQuizId() {
        return quizId;
    }

    public String getTitle() {
        return title;
    }

    public int getDuration() {
        return duration;
    }
}