import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Double x = scanner.nextDouble();
        Double x1 = scanner.nextDouble();
        Double x2 = scanner.nextDouble();
        System.out.printf("MEDIA = %.1f%n", ((x*2+x1*3+x2*5)/10));
    }
}