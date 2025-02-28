import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int repeat = sc.nextInt();

        for (int r = 0; r < repeat; r++) {
            int ans = 0;
            int size = sc.nextInt();
            int[] disparos = new int[size];
            
            for (int i = 0; i < size; i++) {
                disparos[i] = sc.nextInt();
            }
            
            String jumps = sc.next();
            
            for (int i = 0; i < size; i++) {
                if ((jumps.charAt(i) == 'S' && disparos[i] <= 2) || 
                    (jumps.charAt(i) == 'J' && disparos[i] > 2)) {
                    ans++;
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}
