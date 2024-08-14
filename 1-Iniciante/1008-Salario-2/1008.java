import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String x = scanner.next();
        Double x1 = scanner.nextDouble();
        Double x2 = scanner.nextDouble();
        System.out.printf("NUMBER = %s%nSALARY = U$ %.2f%n", x,(x1*x2));
    }
}