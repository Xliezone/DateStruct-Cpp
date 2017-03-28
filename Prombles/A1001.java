import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Main
 */
public class A1001 {

    public static void main(String[] args) throws IOException{

        Reader.init(System.in);

        int a = Reader.nextInt();
        int b = Reader.nextInt();

        System.out.format("%,d", a + b);

    }
}

/**
 * Reader  
 */
class Reader {
    
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input){
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException{
        while (! tokenizer.hasMoreTokens()){
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException{
        return Integer.parseInt(next());
    }

    static double nextDouble() throws IOException{
        return Double.parseDouble(next());
    }
}