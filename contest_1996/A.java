import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        final int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            final int N = sc.nextInt();
            int x = N /4;
            int y = N % 4;
            x += y / 2;
            System.out.println(x);
        }
    }
}