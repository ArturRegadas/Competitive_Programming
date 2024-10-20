import java.util.*;
import java.lang.*;
import java.io.*;
import java.text.DecimalFormat;


// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.next();
        Double b = scanner.nextDouble();
        Double c = scanner.nextDouble();
        DecimalFormat formatador = new DecimalFormat("0.##");

        String n = formatador.format(b + (c * .15));
        if (n.contains(String.valueOf('.'))){
            n+="00";
        }
        else{
            n+=".00";
        }
        float result=Float.parseFloat(n);
        System.out.printf("TOTAL = R$ %.2f\n",result );
    }
}