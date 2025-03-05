import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();

        for (int r = 0; r < cases; ++r) {
            int rook = sc.nextInt();
            int size = sc.nextInt();
            int[] lake = new int[size];

            for (int i = 0; i < rook; ++i) {
                String move = sc.next();
                char c = move.charAt(0);
                int x = Integer.parseInt(move.substring(2));
                lake[x - 1] = (c == 'S') ? 1 : 2;
            }

            int ansI = 0, current = 0;
            boolean skip = false;

            for (int i = 0; i < size; ++i) {
                current++;
                ansI = Math.max(ansI, current);
                if (lake[i] == 1) {
                    if (!skip) {
                        lake[i] = 2;
                    } else {
                        current = 0;
                    }
                    skip = !skip;
                } else if (lake[i] == 2) {
                    current = 0;
                }
            }

            current = 0;
            int ansV = 0;
            for (int i = 0; i < size; i++) {
                current++;
                ansV = Math.max(ansV, current);
                if (lake[i] == 2) current = 0;
            }

            System.out.printf("Case %d: %d\n", r + 1, Math.max(ansI, ansV));
        }
        
        sc.close();
    }
}
