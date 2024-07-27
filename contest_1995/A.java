import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        final int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            final int N = sc.nextInt();
            int K = sc.nextInt();
            boolean shouldDecrement = true;
            int currentSize = N;
            int answer = 0;
            while (K > 0) {
                ++answer;
                K -= currentSize;
                if (shouldDecrement) {
                    --currentSize;
                }
                shouldDecrement = !shouldDecrement;
            }
            System.out.println(answer);
        }
    }
}