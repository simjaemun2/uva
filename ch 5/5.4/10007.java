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

        while(true)
        {
            int N = sc.nextInt();

            if(N == 0)
                break;

            BigInteger result = BigInteger.valueOf(2*N);

            for(int i=2; i<=N; i++)
            {
                result = result.multiply(BigInteger.valueOf(2*N-i+1));
            }

            result = result.divide(BigInteger.valueOf(N+1));

            System.out.println(result);
        }

    }
}
