using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        while(true){
            string[] data=Console.ReadLine().Split(' ');
            string result = "";
            
            if(data[0] == "0" && data[1] == "0"){
                break;
            }
            
            
            foreach(char i in data[1]){
                if(Convert.ToString(i) != data[0]){
                    result+=Convert.ToString(i);
                }
            }

            result=result.TrimStart('0');
            
            if (string.IsNullOrEmpty(result))
            {
                Console.WriteLine(0);
            }
            else{
                Console.WriteLine(result);
            }
            
            
        }
    }
}