using System;
using System.Collections.Generic;

class Program {
    static void Main() {
        string line;
        while ((line = Console.ReadLine()) != null) {
            string[] parts = line.Split();
            int n = int.Parse(parts[0]), m = int.Parse(parts[1]);

            Dictionary<int, List<int>> occurrence = new Dictionary<int, List<int>>();
            string[] array = Console.ReadLine().Split();
            
            for (int i = 0; i < n; i++) {
                int num = int.Parse(array[i]);
                if (!occurrence.ContainsKey(num)) {
                    occurrence[num] = new List<int>();
                }
                occurrence[num].Add(i + 1);
            }

            for (int i = 0; i < m; i++) {
                string[] query = Console.ReadLine().Split();
                int init = int.Parse(query[0]), wanted = int.Parse(query[1]);

                if (occurrence.ContainsKey(wanted) && occurrence[wanted].Count >= init) {
                    Console.WriteLine(occurrence[wanted][init - 1]);
                } else {
                    Console.WriteLine(0);
                }
            }
        }
    }
}
