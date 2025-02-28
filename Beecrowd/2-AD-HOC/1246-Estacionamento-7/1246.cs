using System;
using System.Collections.Generic;

class Program {
    static void Main() {
        string input;
        while ((input = Console.ReadLine()) != null) {
            string[] tokens = input.Split();
            int size = int.Parse(tokens[0]);
            int cases = int.Parse(tokens[1]);

            int[] estacionamento = new int[size];
            Dictionary<int, int> position = new Dictionary<int, int>();
            int ans = 0;

            for (int r = 0; r < cases; r++) {
                string[] cmd = Console.ReadLine().Split();
                char command = cmd[0][0];

                if (command == 'C') {
                    int placa = int.Parse(cmd[1]);
                    int sizeCar = int.Parse(cmd[2]);
                    bool aux;
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
                                position[placa] = i;
                                break;
                            }
                        } else {
                            i += estacionamento[i] - 1;
                        }
                    }
                } else {
                    int placa = int.Parse(cmd[1]);
                    if (position.ContainsKey(placa)) {
                        estacionamento[position[placa]] = 0;
                        position.Remove(placa);
                    }
                }
            }
            Console.WriteLine(ans * 10);
        }
    }
}
