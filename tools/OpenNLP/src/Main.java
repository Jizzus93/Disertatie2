import com.google.gson.Gson;
import opennlp.tools.sentdetect.SentenceDetectorME;
import opennlp.tools.sentdetect.SentenceModel;
import opennlp.tools.util.InvalidFormatException;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * Created by octak on 6/7/2017.
 */


public class Main {

    static String readFile(String path, Charset encoding)
            throws IOException
    {
        byte[] encoded = Files.readAllBytes(Paths.get(path));
        return new String(encoded, encoding);
    }

    public static void main(String [] args)throws InvalidFormatException,
            IOException {

        if(args.length== 0)
        {
            System.err.println("please pass arguments");
            System.exit(1);
        }
        else{

            if(args[0].equals("-clause"))
            {

                String paragraph = readFile("nodeset1627.txt", StandardCharsets.UTF_8);
                InputStream is = new FileInputStream("da-sent.bin");
                SentenceModel model = new SentenceModel(is);
                SentenceDetectorME sdetector = new SentenceDetectorME(model);

                String sentences[] = sdetector.sentDetect(paragraph);

                AnnotationObject ao = new AnnotationObject();

                System.out.println(sentences.length);
                int startOffset = -1;

                for(String s: sentences)
                {
                    startOffset = paragraph.indexOf(s, startOffset + 1 );
                    int endOffset = startOffset + s.length();

                    ClauseAnnotation annotation = new ClauseAnnotation(startOffset,endOffset);
                    ao.addAnnotation(annotation);
                }

                System.out.println("Annotation Object");
                ao.print();

                Gson gson = new Gson();

                FileWriter file = new FileWriter("output3.json");
                String json = gson.toJson(ao);
                file.write(json);
                file.close();
                System.out.println(json);
                is.close();
            }


        }

        String paragraph = "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "\n" +
                "Clifford Longley: Yes, hello. Aren’t the people you\n" +
                "represent, nowadays called the consumer finance industry, traditionally known\n" +
                "as usurers? And isn’t the reason Dante confined them to the lowest\n" +
                "circle of hell because they made a big profit at the expense of very poor\n" +
                "people, which was widely regarded, quite rightly in my view, as shameful?\n" +
                "\n" +
                "\n" +
                "\n" +
                "John Lamiday: So, lending money at interest is\n" +
                "shameful? Well, then that takes away most of the ability of society to\n" +
                "use future income to fund an unaffordable product right now.\n" +
                "\n";

        // always start with a model, a model is learned from training data

    }
}
