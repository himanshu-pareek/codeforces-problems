import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        final int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            final int n = sc.nextInt();
            int q = sc.nextInt();

            String a = sc.next();
            String b = sc.next();

            int[][] A = new int[n + 1][26];
            int[][] B = new int[n + 1][26];

            for (int i = 0; i < n; i++) {
                int d = a.charAt(i) - 'a';
                for (int j = 0; j < 26; j++) {
                    A[i + 1][j] = A[i][j];
                    B[i + 1][j] = B[i][j];
                }
                A[i + 1][d] += 1;

                d = b.charAt(i) - 'a';
                B[i + 1][d] += 1;
            }

            // for (int i = 0; i <= n; i++) {
            //     for (int j = 0; j < 26; j++) {
            //         System.out.print(A[i][j] + ", ");
            //     }
            //     System.out.println();
            // }

            // for (int i = 0; i <= n; i++) {
            //     for (int j = 0; j < 26; j++) {
            //         System.out.print(B[i][j] + ", ");
            //     }
            //     System.out.println();
            // }

            while (q-- > 0) {
                int l = sc.nextInt();
                int r = sc.nextInt();

                int sum = 0;
                for (int i = 0; i < 26; i++) {
                    sum += Math.abs(
                        (A[r][i] - A[l - 1][i]) -
                        (B[r][i] - B[l - 1][i])
                    );
                }
                System.out.println(sum / 2);
            }
        }
    }
}