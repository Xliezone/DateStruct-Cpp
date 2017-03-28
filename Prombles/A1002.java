import java.util.Scanner;

/**
 * Main
 */
public class A1002 {
public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    
    int row = 0;
    double[] array = new double[1001];
    while(row++ < 2) {
        int K = in.nextInt();
        while(K-- > 0){
            int exp = in.nextInt();
            double coeff = in.nextDouble();
            array[exp] += coeff;
        }
    }
    int count = 0;
    for (int i = 0; i < 1001; i++){
        if (array[i] != 0){
            count++;
        }
    }
    System.out.print(count);
    for (int i = 1000; i >= 0; i--){
        if (array[i] != 0)
        System.out.format(" %d %.1f", i, array[i]);
    }
}
}