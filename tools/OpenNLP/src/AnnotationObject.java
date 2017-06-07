import java.util.ArrayList;

/**
 * Created by octak on 6/7/2017.
 */
public class AnnotationObject {
    ArrayList<Annotation> annotationList;

    AnnotationObject(){
        this.annotationList = new ArrayList<Annotation>();
    }

    public void addAnnotation(Annotation annotation)
    {
        this.annotationList.add(annotation);
    }

    public void print(){
        for(Annotation a: annotationList){
            System.out.println(a.getAnnotationType());
            System.out.println(a.getStartOffset());
            System.out.println(a.getEndOffset());

        }
    }
}
