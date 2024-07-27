import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        final int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            final int n = sc.nextInt();
            final int x = sc.nextInt();

            long answer = 0L;
            for (int a = 1; a <= n; a++) {
                int nBya = n / a;
                for (int b = 1; b <= nBya; b++) {
                    int ab = a * b;
                    int limit1 = (n - ab) / (a + b);
                    int limit2 = x - (a + b);
                    answer += Math.max (0, Math.min (limit1, limit2));
                }
            }

            System.out.println(answer);
        }
    }
}