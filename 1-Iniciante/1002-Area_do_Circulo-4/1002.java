import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Double num1 = scanner.nextDouble();
        System.out.printf("A=%.4f%n", ((num1*num1)*3.14159));
    }
}