import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
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

        int T = sc.nextInt();


        for(int tc=0;tc<T;tc++)
        {
            int N = sc.nextInt();
            int K = sc.nextInt();

            for(int k=0; k<K; k++)
            {
                N -= sc.nextInt();
            }

            N++;

            if(N < K)
            {
                System.out.println(0);
                continue;
            }


            if(K > N - K)
                K = N - K;

            BigInteger sum = BigInteger.ONE;

            for(int i=1; i<=K; i++)
            {
                sum = sum.multiply(BigInteger.valueOf(N-i+1)).divide(BigInteger.valueOf(i));
            }

            System.out.println(sum);
        }
    }
}
