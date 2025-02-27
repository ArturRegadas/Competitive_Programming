using System;

class Solution {
    static void Main() {
        string input;
        while ((input = Console.ReadLine()) != null) {
            int axu = 0;

            foreach (char c in input) {
                if (c == ' ') {
                    Console.Write(" ");
                    continue;
                }

                axu++;

                if (axu % 2 == 1) {
                    Console.Write(char.ToUpper(c));
                } else {
                    Console.Write(char.ToLower(c));
                }
            }
            Console.WriteLine();
        }
    }
}
