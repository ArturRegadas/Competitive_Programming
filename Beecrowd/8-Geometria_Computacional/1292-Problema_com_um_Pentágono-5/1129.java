import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final double c = Math.sin(Math.toRadians(108)) / Math.sin(Math.toRadians(63));

        while (scanner.hasNextDouble()) {
            double s = scanner.nextDouble();
            System.out.printf("%.10f%n", s * c);
        }

        scanner.close();
    }
}
