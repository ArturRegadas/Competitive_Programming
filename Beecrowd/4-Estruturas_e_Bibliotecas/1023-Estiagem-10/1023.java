import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases, size, water, maxKey;
        double totalW, totalP;
        int c = 1;
        boolean first = true;

        while (true) {
            cases = scanner.nextInt();
            if (cases == 0) return;
            if (!first) System.out.println();
            first = false;

            int[] city = new int[210];
            totalW = 0;
            totalP = 0;
            maxKey = 0;

            for (int i = 0; i < cases; i++) {
                size = scanner.nextInt();
                water = scanner.nextInt();
                totalP += size;
                totalW += water;
                maxKey = Math.max(maxKey, water / size);
                city[water / size] += size;
            }

            System.out.printf("Cidade# %d:\n", c);
            for (int i = 0; i < maxKey; i++) {
                if (city[i] != 0) System.out.printf("%d-%d ", city[i], i);
            }
            System.out.printf("%d-%d\n", city[maxKey], maxKey);
            System.out.printf("Consumo medio: %.2f m3.\n", Math.floor((totalW / totalP) * 100) / 100);
            c++;
        }
    }
}
