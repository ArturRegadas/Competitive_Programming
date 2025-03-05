using System;

class Program
{
    static void Main()
    {
        int cases, size, water, maxKey;
        double totalW, totalP;
        int c = 1;
        bool first = true;

        while (true)
        {
            cases = int.Parse(Console.ReadLine());
            if (cases == 0) return;
            if (!first) Console.WriteLine();
            first = false;

            int[] city = new int[210];
            totalW = 0;
            totalP = 0;
            maxKey = 0;

            for (int i = 0; i < cases; i++)
            {
                string[] input = Console.ReadLine().Split();
                size = int.Parse(input[0]);
                water = int.Parse(input[1]);
                totalP += size;
                totalW += water;
                maxKey = Math.Max(maxKey, water / size);
                city[water / size] += size;
            }

            Console.WriteLine($"Cidade# {c}:");
            for (int i = 0; i < maxKey; i++)
            {
                if (city[i] != 0) Console.Write($"{city[i]}-{i} ");
            }
            Console.WriteLine($"{city[maxKey]}-{maxKey}");
            Console.WriteLine($"Consumo medio: {Math.Floor((totalW / totalP) * 100) / 100:F2} m3.");
            c++;
        }
    }
}
