import java.util.*;

public class Main{
    public static void reverse(int[] arr) {
        int i = 0, j = arr.length - 1;
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    public static void main(String[] args){
        int idx, midle, ans,ans2, size, cases;
        Scanner scan = new Scanner(System.in);
        cases = scan.nextInt();
        for(int r = 0;r<cases;r++){
            size=scan.nextInt();
            int nuns[] = new int[size];
            for(int i =0;i<size;i++)nuns[i] = scan.nextInt();
            Arrays.sort(nuns);
            int[] newNuns = new int[size];
            midle = (size/2);
            if(size%2==0)midle--;
            ans = 0;
            idx=0;
            for(int i = size-1; i>midle; i--){
                newNuns[idx] = nuns[i-midle-1];
                idx++;
                newNuns[idx] = nuns[i];
                idx++;
            }
            
            if(size%2==1)newNuns[idx] = nuns[midle];
            for(int i =1;i<size;++i)ans+= Math.abs(newNuns[i-1] - newNuns[i]);


            reverse(nuns);
            idx=0;
            int[] newNuns2 = new int[size];
            for(int i = size-1; i>midle; i--){
                newNuns2[idx] = nuns[i-midle-1];
                idx++;
                newNuns2[idx] = nuns[i];
                idx++;
            }
            ans2 =0;
            if(size%2==1)newNuns2[idx] = nuns[midle];
            for(int i =1;i<size;++i)ans2+= Math.abs(newNuns2[i-1] - newNuns2[i]);
            
            
            
            System.out.printf("Case %d: %d\n", r+1, Math.max(ans, ans2));
        }
        scan.close();

    }
}
