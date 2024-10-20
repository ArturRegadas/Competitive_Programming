// Online C# Editor for free
// Write, Edit and Run your C# code using C# Online Compiler

using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        bool thebol;
        int cont=0;
        string[] repeat = Console.ReadLine().Split(' ');
        
        string[] matriz = new string [int.Parse(repeat[0])];
        
        for (int i = 0; i<int.Parse(repeat[0]); i++){
            matriz[i]=Console.ReadLine();
        }
        
        for (int y = 0; y<matriz.Length; y++){
            for (int x = 0 ; x<matriz[y].Length; x++){
                thebol=true;
                if (matriz[y][x] == '#'){
                    if (y != 0){
                        if (matriz[y-1][x]=='.'){
                            thebol=false;
                            cont++;
                            }
                        }
                    
                    else{
                        if (thebol){
                            thebol=false;
                            cont++;
                        }
                    }
                    if (y != int.Parse(repeat[0])-1 & thebol){
                        if (matriz[y+1][x]=='.'){
                            thebol=false;
                            cont++;
                        }
                    }
                    else{
                        if (thebol){
                            thebol=false;
                            cont++;
                        }
                    }
                    if (x != 0 & thebol){
                        if (matriz[y][x-1]=='.'){
                            thebol=false;
                            cont++;
                        }
                    }
                    else{
                        if (thebol){
                            thebol=false;
                            cont++;
                        }
                    }
                    if (x != int.Parse(repeat[1])-1 & thebol){
                        if (matriz[y][x+1]=='.'){
                            thebol=false;
                            cont++;
                        }
                    }
                    else{
                        if (thebol){
                            thebol=false;
                            cont++;
                        }
                    }
                }
                
            }
        }
        Console.WriteLine(cont);
        
    }
}