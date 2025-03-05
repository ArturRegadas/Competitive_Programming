import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            Map<Integer, List<Integer>> occurrence = new HashMap<>();

            for (int i = 1; i <= n; i++) {
                int num = sc.nextInt();
                occurrence.putIfAbsent(num, new ArrayList<>());
                occurrence.get(num).add(i);
            }

            for (int i = 0; i < m; i++) {
                int init = sc.nextInt();
                int wanted = sc.nextInt();
                
                List<Integer> positions = occurrence.getOrDefault(wanted, new ArrayList<>());
                if (positions.size() >= init) {
                    System.out.println(positions.get(init - 1));
                } else {
                    System.out.println(0);
                }
            }
        }
        sc.close();
    }
}
