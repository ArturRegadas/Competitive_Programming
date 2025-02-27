using System;

class Solution {
    static void Main() {
        decimal c = 1.06739568171118186925926376267113212m;
        
        string input;
        while ((input = Console.ReadLine()) != null) {
            decimal s = decimal.Parse(input);
            Console.WriteLine("{0:F10}", s * c);
        }
    }
}
