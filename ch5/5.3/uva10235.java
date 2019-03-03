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



        while(sc.hasNext())
        {
            BigInteger bi = sc.nextBigInteger();
            System.out.print(bi);

            if(bi.isProbablePrime(10))
            {
                BigInteger bbi = new BigInteger(new StringBuilder(bi.toString()).reverse().toString());
                if(!bi.equals(bbi) && bbi.isProbablePrime(10))
                {
                    System.out.println(" is emirp.");
                }
                else
                {
                    System.out.println(" is prime.");
                }
            }
            else
            {
                System.out.println(" is not prime.");
            }
        }


    }
}
