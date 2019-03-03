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


        final int MAX_N = 40;
        long cache[] = new long[MAX_N+1];
        cache[0] = 1;
        cache[1] = 1;
        cache[2] = 5;

        for(int i=3; i<=MAX_N; i++)
        {
            cache[i] = cache[i-1] + 4*cache[i-2] + 2*cache[i-3];
        }

        int T = sc.nextInt();

        for(int t=0;t<T;t++)
            System.out.println(cache[sc.nextInt()]);

    }
}
