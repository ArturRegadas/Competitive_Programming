import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        double radix = scanner.nextDouble();
        double gas = scanner.nextDouble();
        
    
        double area = (4.0 / 3.0) * (3.1415 * (radix * radix * radix));
        
        System.out.println((int)(gas / area));

    }
}
