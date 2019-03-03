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

        while(sc.hasNext())
        {
            int N = sc.nextInt();

            int result = 1;

            for(int n=1; n<=N; n++)
            {
                result = result * (2*N-n+1) / n;
            }

            result /= N+1;

            System.out.println(result);

            if(sc.hasNext())
                System.out.println();
        }

    }
}
