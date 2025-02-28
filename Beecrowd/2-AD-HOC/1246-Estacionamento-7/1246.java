import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int size = sc.nextInt();
            int cases = sc.nextInt();
            int[] estacionamento = new int[size];
            Map<Integer, Integer> position = new HashMap<>();
            int ans = 0;

            for (int r = 0; r < cases; r++) {
                char command = sc.next().charAt(0);
                if (command == 'C') {
                    int placa = sc.nextInt();
                    int sizeCar = sc.nextInt();
                    boolean aux;
                    for (int i = 0; i <= size - sizeCar; i++) {
                        if (estacionamento[i] == 0) {
                            aux = true;
                            for (int j = i + 1; j < i + sizeCar; j++) {
                                if (estacionamento[j] > 0) {
                                    aux = false;
                                    break;
                                }
                            }
                            if (aux) {
                                estacionamento[i] = sizeCar;
                                ans++;
                                position.put(placa, i);
                                break;
                            }
                        } else {
                            i += estacionamento[i] - 1;
                        }
                    }
                } else {
                    int placa = sc.nextInt();
                    if (position.containsKey(placa)) {
                        estacionamento[position.get(placa)] = 0;
                        position.remove(placa);
                    }
                }
            }
            System.out.println(ans * 10);
        }
        sc.close();
    }
}
