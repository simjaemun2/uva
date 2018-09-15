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

        while(true)
        {
            int N = sc.nextInt();

            if(N == 0)
                break;

            for(int i=0; i<N; i++)
            {
                System.out.println(new BigInteger(sc.next()).modPow(new BigInteger(sc.next()), new BigInteger(sc.next())));
            }
        }




    }
}
