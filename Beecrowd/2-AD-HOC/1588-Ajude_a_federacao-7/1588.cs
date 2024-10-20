using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            var times = new Dictionary<string, int[]>();
            var info = Console.ReadLine().Split(' ');

            int numTimes = int.Parse(info[0]);
            int numJogos = int.Parse(info[1]);

            for (int g = 0; g < numTimes; g++)
            {
                string time = Console.ReadLine();
                times[time] = new int[] { 0, 0, 0 };
            }

            for (int g = 0; g < numJogos; g++)
            {
                var jogo = Console.ReadLine().Split(' ');

                int golTime1 = int.Parse(jogo[0]);
                int golTime2 = int.Parse(jogo[2]);
                string time1 = jogo[1];
                string time2 = jogo[3];

                if (golTime1 > golTime2)
                {
                    times[time1][0] += 3;
                    times[time1][1] += 1;
                }
                else if (golTime1 < golTime2)
                {
                    times[time2][0] += 3;
                    times[time2][1] += 1;
                }
                else
                {
                    times[time1][0] += 1;
                    times[time2][0] += 1;
                }

                times[time1][2] += golTime1;
                times[time2][2] += golTime2;
            }

            var timesOrdenados = times.OrderByDescending(t => t.Value[0])
                                      .ThenByDescending(t => t.Value[1])
                                      .ThenByDescending(t => t.Value[2]);

            foreach (var time in timesOrdenados)
            {
                Console.WriteLine(time.Key);
            }
        }
    }
}