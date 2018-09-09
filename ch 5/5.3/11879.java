import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args)
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


        int answer = 0;

        while(true)
        {
            BigInteger N = sc.nextBigInteger();

            if(BigInteger.ZERO.equals(N))
                break;

            if(N.mod(BigInteger.valueOf(17)).compareTo(BigInteger.ZERO) == 0)
                System.out.println(1);
            else
                System.out.println(0);
        }
    }
}
