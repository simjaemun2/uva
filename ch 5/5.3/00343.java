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


        while(sc.hasNext())
        {
            String X = sc.next();
            String Y = sc.next();

            int bx=0;
            int by=0;

            boolean isImpossible = true;

            for(bx=2;bx <= 36 && isImpossible; bx++) {
                for (by=2; by <= 36; by++) {
                    try {
                        if (new BigInteger(X, bx).equals(new BigInteger(Y, by))) {
                            isImpossible = false;
                            break;
                        }

                    } catch (Exception e) {

                    }
                }
            }

            if(isImpossible)
                System.out.printf("%s is not equal to %s in any base 2..36\n", X, Y);
            else
                System.out.printf("%s (base %d) = %s (base %d)\n",X,bx-1,Y,by);
        }
    }
}
