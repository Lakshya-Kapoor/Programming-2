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

    public void addQuestion(String questionId, Question question) {
        if (questions.containsKey(questionId)) {
            throw new RuntimeException("Question " + questionId + " already exists");
        }

        questions.put(questionId, question);
    }

    public Question getQuestion(String questionId) {
        return questions.get(questionId);
    }

    public boolean answerQuestion(String questionId, String answer) {
        Question question = questions.get(questionId);
        return question.getCorrectAnswer().equals(answer);
    }

}