using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int jus = int.Parse(Console.ReadLine());
        for(int g = 0 ; g<jus; g++){
            string str1 = Console.ReadLine();
            char[] str = str1.ToCharArray();
            string n = "";
            for(int i = str.Length-1; i>-1;i--){
                if(Char.IsLetter(str[i])){
                    int k=(int)str[i];
                    char l =Convert.ToChar(k+3);
                    n+=Convert.ToString(l);
                }
                else{
                    n+=Convert.ToString(str[i]);
                }
            }
            string m = n.Substring(0, (int)n.Length/2);
            string rep = n.Substring((int)n.Length/2);
            foreach(char b in rep){
                int k=(int)b;
                char l =Convert.ToChar(k-1);
                m+=Convert.ToString(l);
            }
            
            
            Console.WriteLine(m);
        }
        
    }
}