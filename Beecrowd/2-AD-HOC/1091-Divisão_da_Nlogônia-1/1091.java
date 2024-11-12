import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int repeat;
        int xlog, ylog;
        int xcurrent, ycurrent;

        while (true) {
            repeat = scanner.nextInt();
            if (repeat == 0) break;

            xlog = scanner.nextInt();
            ylog = scanner.nextInt();

            for (int i = 0; i < repeat; i++) {
                xcurrent = scanner.nextInt();
                ycurrent = scanner.nextInt();

                if (xcurrent == xlog || ycurrent == ylog) System.out.println("divisa");
                else if (xcurrent > xlog && ycurrent > ylog) System.out.println("NE");
                else if (xcurrent < xlog && ycurrent > ylog) System.out.println("NO");
                else if (xcurrent < xlog && ycurrent < ylog) System.out.println("SO");
                else System.out.println("SE");
            }
        }

        scanner.close();
    }
}
