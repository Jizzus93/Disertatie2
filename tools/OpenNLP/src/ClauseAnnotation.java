import javafx.util.Pair;

import java.util.ArrayList;

/**
 * Created by octak on 6/7/2017.
 */
public class ClauseAnnotation extends Annotation {


    ClauseAnnotation(int startOffset, int endOffset)
    {
        setAnnotationType(0);
        setStartOffset(startOffset);
        setEndOffset(endOffset);
    }

}
