import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder ans = new StringBuilder();
        boolean first = true;

        while (scanner.hasNextLine()) {
            int axu = 0;
            StringBuilder result = new StringBuilder();
            String line = scanner.nextLine();

            for (char c : line.toCharArray()) {
                if (c == ' ') {
                    result.append(" ");
                    continue;
                }
                
                if(Character.isLetter(c))axu++;
                
                result.append(axu % 2 == 1 ? Character.toUpperCase(c) : Character.toLowerCase(c));
            }

            if (!first) {
                ans.append("\n");
            }
            first = false;
            ans.append(result);
        }

        System.out.println(ans);
        scanner.close();
    }
}
