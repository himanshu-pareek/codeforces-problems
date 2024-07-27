import java.util.Scanner;

public class F {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        final int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                b[i] = sc.nextInt();
            }

            int low = 0;
            int high = (int) 1e9;
            while (low <= high) {
                int x = low + (high - low) / 2;
                long numOperations = countOperations(a, b, x);
                // System.out.printf("x = %d, numOperations = %d\n", x, numOperations);
                if (numOperations > k) {
                    low = x + 1;
                } else {
                    high = x - 1;
                }
            }

            // System.out.println("Taking " + low);
            // low is optimal x
            long answer = countScore(a, b, low, k);
            System.out.println(answer);
        }
    }

    private static long countOperations(int[] a, int[] b, int x) {
        long count = 0L;
        for (int i= 0; i < a.length; i++) {
            // a, a - b, a - 2 * b, ..., a - n * b
            // a - nb < x
            // nb > a - x
            // n > (a - x) / b
            count += Math.max(0L, Math.ceil((double) (a[i] - x + 1) / b[i]));
        }
        return count;
    }

    private static long countScore(int[] a, int[] b, int x, int k) {
        long score = 0L;
        int remaining = k;
        for (int i = 0; i < a.length; i++) {
            int n = (int) Math.max(0L, Math.ceil((double) (a[i] - x + 1) / b[i]));
            remaining -= n;
            // a, a - b, a - 2 * b, ..., a - (n - 1) b
            // AM with a = a, d = -b, n =n
            // Sn = n/2 (2a+(n−1)d)
            // System.out.println("Taking " + n + " elementf for index " + i);
            score += ((long) n * (2 * a[i] - (long) (n - 1) * b[i])) / 2;
        }
        score += (long) Math.max(0, x - 1) * remaining;
        return score;
    }
}