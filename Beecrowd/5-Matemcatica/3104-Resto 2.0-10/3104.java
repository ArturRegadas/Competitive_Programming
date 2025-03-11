import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.next();
        long B = sc.nextLong();
        long ans = 0;
        for(char c : A.toCharArray()){
            ans = (ans * 10 + (c - '0')) % B;
        }
        System.out.println(ans);
    }
}