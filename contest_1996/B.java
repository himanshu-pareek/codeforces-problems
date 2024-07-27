import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        final int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            final int n = sc.nextInt();
            final int k = sc.nextInt();

            String[] G = new String[n];
            for (int i = 0; i < G.length; i++) {
                G[i] = sc.next();
            }

            for (int i = 0; i < n; i += k) {
                for (int j = 0; j < n; j += k) {
                    System.out.print(G[i].charAt(j));
                }
                System.out.println();
            }
        }
    }
}