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

        ArrayList<BigInteger> list = new ArrayList<BigInteger>();

        for(int i=2; i<=10000; i++) {
            BigInteger bi = BigInteger.valueOf(i);

            if(bi.isProbablePrime(10)) {
                list.add(bi);
            }
        }

        while(true)
        {
            BigInteger b = sc.nextBigInteger();

            if(b.equals(BigInteger.ZERO))
                break;

            BigInteger two = BigInteger.valueOf(2);

            int count = b.isProbablePrime(10)?1:0;

            for(int i=0; i<list.size(); i++)
            {
                BigInteger startBi = list.get(i);

                if(b.divide(two).compareTo(startBi) == -1)
                    break;

                BigInteger sum = new BigInteger(startBi.toString());

                for(int j=i+1; j < list.size(); j++)
                {
                    sum = sum.add(list.get(j));

                    int result = sum.compareTo(b);

                    if(result == 0){
                        count++;
                        break;
                    }
                    else if(result == 1)
                        break;

                }
            }

            System.out.println(count);
        }
    }
}
