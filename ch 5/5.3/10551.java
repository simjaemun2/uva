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
            int b = sc.nextInt();

            if(b == 0)
                break;

            String p = sc.next();
            String m = sc.next();

            System.out.println(new BigInteger(p, b).mod(new BigInteger(m, b)).toString(b));

        }
    }
}
