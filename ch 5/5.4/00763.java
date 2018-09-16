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

    static BigInteger[] list = new BigInteger[106];

    public static BigInteger fiboTiBigint(String s)
    {
        BigInteger sum = BigInteger.ZERO;

        for(int i = 0; i < s.length(); i++)
        {
            if(s.charAt(i) == '1')
                sum = sum.add(list[s.length() - i - 1]);
        }

        return sum;
    }

    public static String bigintToFibo(BigInteger b){
        StringBuilder builder = new StringBuilder();

        int startIndex;

        for(startIndex=105; startIndex>=0; startIndex--)
        {
            if(b.compareTo(list[startIndex]) >= 0)
                break;
        }

        if(startIndex == -1)
            return "0";

        for(int i = startIndex; i>=0; i--)
        {
            if(b.compareTo(list[i]) >= 0)
            {
                b = b.subtract(list[i]);
                builder.append(1);
            }
            else
            {
                builder.append(0);
            }
        }

        return builder.toString();
    }

    public static void main(String[] args)
    {
        Scanner sc = getScanner(args);


        list[0] = BigInteger.ONE;
        list[1] = BigInteger.valueOf(2);

        for(int i=2; i<1000; i++)
        {
            list[i] = list[i-1].add(list[i-2]);
        }

        while(sc.hasNext())
        {
            System.out.println(bigintToFibo(fiboTiBigint(sc.next()).add(fiboTiBigint(sc.next()))));
            if(sc.hasNext())
                System.out.println();
        }

    }
}
