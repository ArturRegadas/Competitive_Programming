import java.util.*;

public class Main {
    public static void main(String[] args){
        int s, t, ant, current, ans;
        Scanner scan = new Scanner(System.in);
        s = scan.nextInt();t = scan.nextInt();
        int[] days = new int[s];
        for(int i =0;i<s;i++)days[i] =  scan.nextInt();
        ans = 0;
        ant = current = days[0];
        for(int i =1;i<s;++i){
            if((current>days[i] && current-days[i]>=t) || ant>days[i]){
                ans = Math.max(ans, ans+current-ant-t);
                current = ant = days[i];
            }
            if(days[i]>current)current=days[i];
        }
        ans=Math.max(ans, ans+current-ant-t);
        System.out.println(ans);

    }
}
