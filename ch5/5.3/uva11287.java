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
            BigInteger p = sc.nextBigInteger();
            BigInteger a = sc.nextBigInteger();

            if(a.equals(BigInteger.ZERO) && p.equals(BigInteger.ZERO))
                break;

            if(!p.isProbablePrime(10) && a.modPow(p,p).equals(a))
            {
                System.out.println("yes");
            }
            else
            {
                System.out.println("no");
            }
        }


    }
}
