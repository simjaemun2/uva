import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = null;

        if(args.length == 0)
            sc = new Scanner(System.in);
        else
        {
            try {
                sc = new Scanner(new File(args[0]));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }


        int N = sc.nextInt();

        for(int n=0; n<N; n++)
        {
            BigInteger b1 = new BigInteger(new StringBuilder(sc.next()).reverse().toString());
            BigInteger b2 = new BigInteger(new StringBuilder(sc.next()).reverse().toString());
            System.out.println(new BigInteger(new StringBuilder(b1.add(b2).toString()).reverse().toString()));
        }
    }
}
