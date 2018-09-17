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

        final int MAX_N = 26;

        long[] catalan = new long[MAX_N+1];
        long[] superCatalan = new long[MAX_N+1];

        catalan[0] = 1;

        //http://mathworld.wolfram.com/SuperCatalanNumber.html
        for(int i=0; i<MAX_N; i++)
        {
            catalan[i+1] = catalan[i] * (2*i+2) *(2*i+1)/(i+2)/(i+1);
        }

        superCatalan[1] = superCatalan[2] = 1;

        for(int i=3; i<=MAX_N; i++)
        {
            superCatalan[i] = (superCatalan[i-1] * 3 * (2*i-3) - (i-3)*superCatalan[i-2])/i;
        }

        while(sc.hasNext())
        {
            int N = sc.nextInt();

            System.out.println(superCatalan[N] - catalan[N-1]);
        }

    }
}
