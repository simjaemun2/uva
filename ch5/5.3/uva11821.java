import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigDecimal;
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

        int N = Integer.valueOf(sc.nextLine());

        for(int i=0; i<N; i++)
        {
            BigDecimal sum = BigDecimal.ZERO;

            while(true)
            {
                BigDecimal bd = new BigDecimal(sc.next());
                if(bd.equals(BigDecimal.ZERO))
                    break;
                sum = sum.add(bd);

            }

            System.out.println(sum.stripTrailingZeros().toPlainString());
        }




    }
}
