using System;

class Program {
    static void Main() {
        int cases = int.Parse(Console.ReadLine());
        for (int r = 0; r < cases; ++r) {
            string[] input = Console.ReadLine().Split();
            int rook = int.Parse(input[0]);
            int size = int.Parse(input[1]);
            int[] lake = new int[size];
            
    
            if(rook>0){
                string[] command = Console.ReadLine().Split(' ');
                foreach (string i in command) {
                string[] rookInput = i.Split('-');
                char c = rookInput[0][0];
                int x = int.Parse(rookInput[1]);
                lake[x - 1] = (c == 'S') ? 1 : 2;
            }}

            int ansI = 0, current = 0;
            bool skip = false;

            for (int i = 0; i < size; ++i) {
                current++;
                ansI = Math.Max(ansI, current);
                if (lake[i] == 1) {
                    if (!skip) {
                        lake[i] = 2;
                    } else {
                        current = 0;
                    }
                    skip = !skip;
                } else if (lake[i] == 2) {
                    current = 0;
                }
            }

            current = 0;
            int ansV = 0;
            for (int i = 0; i < size; i++) {
                current++;
                ansV = Math.Max(ansV, current);
                if (lake[i] == 2) current = 0;
            }

            Console.WriteLine($"Case {r + 1}: {Math.Max(ansI, ansV)}");
        }
    }
}
