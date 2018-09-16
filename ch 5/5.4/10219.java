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
            int n = sc.nextInt();
            int k = sc.nextInt();

            if(n-k < k)
                k = n-k;

            BigInteger result = BigInteger.valueOf(n);

            for(int i=1; i<k; i++)
            {
                result = result.multiply(BigInteger.valueOf(n-i)).divide(BigInteger.valueOf(i+1));
            }

            System.out.println(result.toString().length());
        }





    }
}
