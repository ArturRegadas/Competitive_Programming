using System;


class Program {
    public static void Main(string[] args) {
        string[] data = Console.ReadLine().Split(' ');
        double radix= double.Parse(data[0]);
        double gas = double.Parse(data[1]);

        double area =  (4.0/3.0) * (3.1415*(radix*radix*radix));
        Console.WriteLine((int)(gas/area));
    }
}
