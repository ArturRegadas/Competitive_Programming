import java.util.Scanner;

public class Main {
    static String calcS(int[] points) {
        if (points[0] == points[1] && points[0] == points[2]) return "trempate";
        if (points[0] > points[1] && points[0] > points[2]) return "red";
        if (points[1] > points[0] && points[1] > points[2]) return "green";
        if (points[2] > points[1] && points[2] > points[0]) return "blue";
        return "empate";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int repeat = sc.nextInt();
        for (int r = 0; r < repeat; r++) {
            int[] point = new int[3];
            int l = sc.nextInt();
            for (int i = 0; i < l; i++) {
                char m = sc.next().charAt(0);
                char s = sc.next().charAt(0);

                if (m == 'R') {
                    if (s == 'G') point[0]++;
                    point[0]++;
                } else if (m == 'G') {
                    if (s == 'B') point[1]++;
                    point[1]++;
                } else {
                    if (s == 'R') point[2]++;
                    point[2]++;
                }
            }
            System.out.println(calcS(point));
        }
        sc.close();
    }
}
