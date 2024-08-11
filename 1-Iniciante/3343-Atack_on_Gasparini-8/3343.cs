using System;
using System.Collections.Generic;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] data = Console.ReadLine().Split(' ');
        int qtdTitans = int.Parse(data[0]);
        int tamMur = int.Parse(data[1]);
        string atack = Console.ReadLine();
        string[] p = Console.ReadLine().Split(' ');
        int[] price = { int.Parse(p[0]), int.Parse(p[1]), int.Parse(p[2]) };

        int result = 1;

        List<int> muralhas = new List<int> { tamMur }; 

        int contadoG = 0;
        int contadoM = 0;
        int contadoP = 0;

        foreach (char i in atack)
        {
            int atual, contador;
            if (i == 'G')
            {
                atual = price[2];
                contador = contadoG;
            }
            else if (i == 'M')
            {
                atual = price[1];
                contador = contadoM;
            }
            else
            {
                atual = price[0];
                contador = contadoP;
            }

            while (contador >= muralhas.Count)
            {
                muralhas.Add(tamMur);
                result++;
            }

            int mur = muralhas[contador];

            while (atual > mur)
            {
                contador++;
                if (contador == result)
                {
                    muralhas.Add(tamMur);
                    result++;
                }

                mur = muralhas[contador];
            }

            if (i == 'G')
            {
                contadoG = contador;
            }
            else if (i == 'M')
            {
                contadoM = contador;
            }
            else
            {
                contadoP = contador;
            }

            muralhas[contador] -= atual;
        }

        Console.WriteLine(result);
    }
}
