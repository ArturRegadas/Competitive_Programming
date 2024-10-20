import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Double num1 = scanner.nextDouble();
        Double num2 = scanner.nextDouble();
        System.out.printf("MEDIA = %.5f%n", ((num1*3.5 + num2*7.5)/11));
    }
}