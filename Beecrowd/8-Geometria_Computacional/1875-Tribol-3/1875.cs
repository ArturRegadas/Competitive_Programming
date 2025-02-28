using System;

class Program {
    static string CalcS(int[] points) {
        if (points[0] == points[1] && points[0] == points[2]) return "trempate";
        if (points[0] > points[1] && points[0] > points[2]) return "red";
        if (points[1] > points[0] && points[1] > points[2]) return "green";
        if (points[2] > points[1] && points[2] > points[0]) return "blue";
        return "empate";
    }

    static void Main() {
        int repeat = int.Parse(Console.ReadLine());
        for (int r = 0; r < repeat; r++) {
            int[] point = new int[3];
            int l = int.Parse(Console.ReadLine());
            for (int i = 0; i < l; i++) {
                string[] input = Console.ReadLine().Split();
                char m = input[0][0];
                char s = input[1][0];

                if (m == 'R') {
                    if (s == 'G') point[0]++;
                    point[0]++;
                } else if (m == 'G') {
                    if (s == 'B') point[1]++;
                    point[1]++;
                } else {
                    if (s == 'R') point[2]++;
                    point[2]++;
                }
            }
            Console.WriteLine(CalcS(point));
        }
    }
}
