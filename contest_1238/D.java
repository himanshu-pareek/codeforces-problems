import java.util.*;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        long n = sc.nextLong();
        String s = sc.next();
        long bad = 0L;
        int currentIndex = 1;
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                currentIndex++;
            } else {
                bad += currentIndex;
                currentIndex = 1;
            }
        }
        currentIndex = 1;
        for (int i = (int) n - 2; i >= 0; i--) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                currentIndex++;
            } else {
                bad += currentIndex - 1;
                currentIndex = 1;
            }
        }
        long good = 1L * n * (n - 1) / 2;
        good -= bad;
        System.out.println(good);
        sc.close();
    }
}