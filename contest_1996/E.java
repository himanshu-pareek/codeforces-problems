import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class E {

    private static int MOD = (int) 1e9 + 7;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        final int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            String s = sc.next();
            final int n = s.length();

            Map<Integer, List<Integer>> sumToIndices = new HashMap<>();

            int sum = 0;
            sumToIndices.computeIfAbsent(sum, x -> new ArrayList<>()).add(-1);
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '1') {
                    ++sum;
                } else {
                    --sum;
                }
                sumToIndices.computeIfAbsent(sum, x -> new ArrayList<>()).add(i);
            }

            // System.out.println(sumToIndices);

            
            int answer = 0;

            for (List<Integer> indices: sumToIndices.values()) {
                sum = 0;
                for (int index: indices) {
                    answer = add (answer, mul (sum, n - index));
                    sum = add (sum, index + 2);
                }
            }
            System.out.println(answer);
        }
    }

    private static int add (int a, int b) {
        a += b;
        if (a >= MOD) {
            a -= MOD;
        }
        return a;
    }

    private static int mul (int a, int b) {
        long c = (long) a * b;
        c %= MOD;
        return (int) c;
    }
}