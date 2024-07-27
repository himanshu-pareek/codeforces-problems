import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        while (T-- > 0) {
            final int N = sc.nextInt();
            final long M = sc.nextLong();

            long[] A = new long[N];
            for (int i = 0; i < N; i++) {
                A[i] = sc.nextLong();
            }

            long[] C = new long[N];
            for (int i = 0; i < N; i++) {
                C[i] = sc.nextLong();
            }

            Arrays.sort(A);

            long answer = 0L;
            // long previous = -1;
            // for (int i = 0; i < N; i++) {
            //     if (A[i] == previous) {
            //         continue;
            //     }
            //     long a = A[i];
            //     long b = A[i] + 1;
            //     long c = 0;
            //     long d = 0;
            //     for (int j = i; j < N; j++) {
            //         if (A[j] == a) {
            //             ++c;
            //         } else if (A[j] == b) {
            //             ++d;
            //         } else {
            //             break;
            //         }
            //     }
            //     answer = Math.max (answer, calculate(a, b, c, d, M));
            // }

            int start = 0;
            long sum = 0L;
            for (int end = 0; end < N; end++) {
                if (A[end] > M) {
                    break;
                }
                sum += A[end];
                while (A[start] < A[end] - 1 || sum > M) {
                    sum -= A[start];
                    ++start;
                }
                answer = Math.max (answer, sum);
            }

            System.out.println(answer);
        }
    }

    private static long calculate(long a, long b, long c, long d, long m) {
        long answer = 0L;
        for (long x = 0; x <= c; x++) {
            if (a * x > m) {
                break;
            }
            long y = Math.min (d, (m - a * x) / b);
            answer = Math.max (answer, a * x + b * y);
        }
        return answer;
    }
}
