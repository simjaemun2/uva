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


        while(sc.hasNext())
        {
            int N = sc.nextInt();
            BigInteger A = sc.nextBigInteger();

            BigInteger sum = A.add(BigInteger.ZERO);
            BigInteger t = A.add(BigInteger.ZERO);

            for(int i=2; i<=N; i++)
            {
                t = t.multiply(A);
                sum = sum.add(BigInteger.valueOf(i).multiply(t));
            }

            System.out.println(sum);
        }
    }
}
