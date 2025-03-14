import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            double r1 = scanner.nextDouble();
            double x1 = scanner.nextDouble();
            double y1 = scanner.nextDouble();
            double r2 = scanner.nextDouble();
            double x2 = scanner.nextDouble();
            double y2 = scanner.nextDouble();

            double distance = Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

            System.out.println(distance + r2 <= r1 ? "RICO" : "MORTO");
        }
        scanner.close();
    }
}
