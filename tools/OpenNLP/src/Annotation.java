/**
 * Created by octak on 6/7/2017.
 */
public class Annotation {
    private int annotationType;
    private int startOffset;
    private int endOffset;


    public int getAnnotationType(){
        return this.annotationType;
    }

    public void setAnnotationType(int annotationType){
        this.annotationType = annotationType;
    }

    public int getStartOffset(){
        return this.startOffset;
    }

    public void setStartOffset(int startOffset){
        this.startOffset = startOffset;
    }

    public int getEndOffset(){
        return this.endOffset;
    }

    public void setEndOffset(int endOffset){
        this.endOffset = endOffset;
    }
}
