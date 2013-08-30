import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int n;
        Scanner s = new Scanner(System.in);
        PrintWriter p = new PrintWriter(System.out);
        n = s.nextInt();
        BigInteger prev, cur;
        BigInteger one = BigInteger.valueOf(1);
        BigInteger two = BigInteger.valueOf(2);
        cur = two;
        for(int i = 0; i < n; i++) {
            p.println(cur.toString());
            prev = cur;
            cur = prev.subtract(one).multiply(prev).add(one);
        }
        p.flush();
    }
}
