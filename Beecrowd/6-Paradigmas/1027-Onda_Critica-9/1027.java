import java.util.*;



public class Main{
    public static class point{
        public int x,y;
        point(int a, int b){
            this.x = a;
            this.y = b;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n, aux, auy;
        while(sc.hasNextInt()){
            n = sc.nextInt();
            point[] points = new point[n];
            for(int i =0;i<n;i++){
                aux = sc.nextInt();
                auy = sc.nextInt();
                points[i] = new point(aux, auy);
            }
            Arrays.sort(points, (a, b) ->{
                return Integer.compare(a.x, b.x);
            });
            int[] dpT = new int[n];
            int[] dpB = new int[n];
            dpB[0] = 1; dpT[0] = 1;
            for(int i = 1; i<n; i++){
                int b = 1, t =1;
                for(int j = 0;j<n;j++){
                    if(points[i].x > points[j].x && points[i].y == points[j].y+2)
                        t = Math.max(t, dpB[j]+1);
                    if(points[i].x > points[j].x && points[i].y == points[j].y-2)
                        b= Math.max(b, dpT[j]+1);
                }
                dpT[i] = t;
                dpB[i] = b;
            }
            int ans = 1;
            for(int i =0;i<n;i++){
                ans = Math.max(ans, dpT[i]);
                ans = Math.max(ans, dpB[i]);
            }
            System.out.println(ans);
        }

        sc.close();

    }
}