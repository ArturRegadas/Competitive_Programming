using System;

class Solution {
    static void Main() {
        int repeat;
        int xlog, ylog;
        int xcurrent, ycurrent;

        while (true) {
            repeat = int.Parse(Console.ReadLine());
            if (repeat == 0) break;

            var coords = Console.ReadLine().Split();
            xlog = int.Parse(coords[0]);
            ylog = int.Parse(coords[1]);

            for (int i = 0; i < repeat; i++) {
                coords = Console.ReadLine().Split();
                xcurrent = int.Parse(coords[0]);
                ycurrent = int.Parse(coords[1]);

                if (xcurrent == xlog || ycurrent == ylog) Console.WriteLine("divisa");
                else if (xcurrent > xlog && ycurrent > ylog) Console.WriteLine("NE");
                else if (xcurrent < xlog && ycurrent > ylog) Console.WriteLine("NO");
                else if (xcurrent < xlog && ycurrent < ylog) Console.WriteLine("SO");
                else Console.WriteLine("SE");
            }
        }
    }
}
