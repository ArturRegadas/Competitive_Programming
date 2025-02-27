using System;

class Solution {
    static void Main() {
        string input;
        while ((input = Console.ReadLine()) != null) {
            string[] values = input.Split();
            double r1 = double.Parse(values[0]);
            double x1 = double.Parse(values[1]);
            double y1 = double.Parse(values[2]);
            double r2 = double.Parse(values[3]);
            double x2 = double.Parse(values[4]);
            double y2 = double.Parse(values[5]);

            double distance = Math.Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

            Console.WriteLine(distance + r2 <= r1 ? "RICO" : "MORTO");
        }
    }
}
