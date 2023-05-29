package LearningRecord.exception.exceptiondemo2;

public class NameFormatException extends RuntimeException{

    public NameFormatException() {
    }

    public NameFormatException(String message) {
        super(message);
    }
}
