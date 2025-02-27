import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int l,c,r1,r2;
        while(true){
            l = scan.nextInt();
            c = scan.nextInt();
            r1 = scan.nextInt();
            r2 = scan.nextInt();

            if(l==0 && c ==0 && r1==0 && r2==0)break;
            if(2*r1>l || 2*r1>c || 2*r2>l || 2*r2>c){
                System.out.println("N");
                continue;
            }
            if(Math.sqrt(Math.pow(c-r1-r2, 2) + Math.pow(l-r1-r2, 2)) >= (r1+r2) ){
                System.out.println("S");
                continue;
            }
            System.out.println("N");
        }
        scan.close();
    }

}