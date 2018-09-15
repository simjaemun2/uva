import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static Scanner getScanner(String[] args)
    {
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

        return sc;
    }


    public static void main(String[] args)
    {
        Scanner sc = getScanner(args);

        int N = Integer.valueOf(sc.nextLine());

        for(int i=0; i<N; i++)
        {
            String[] tokens = sc.nextLine().split("\\s+");

            BigInteger p = new BigInteger(tokens[0]);
            BigInteger q = new BigInteger(tokens[2]);
            BigInteger gcd = p.gcd(q);

            System.out.printf("%s / %s\n", p.divide(gcd), q.divide(gcd));

        }




    }
}
