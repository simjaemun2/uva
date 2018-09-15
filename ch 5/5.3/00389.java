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
            String s = sc.next();
            int from = sc.nextInt();
            int to = sc.nextInt();

            try{
                String result = new BigInteger(s, from).toString(to);
                if(result.length() > 7)
                    throw new Exception();
                System.out.printf("%7s\n", result.toUpperCase());
            }
            catch(Exception e)
            {
                System.out.println("  ERROR");
            }
        }
    }
}
