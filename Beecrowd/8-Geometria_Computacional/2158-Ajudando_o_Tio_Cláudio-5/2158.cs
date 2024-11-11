using System;

class solution{
    static void Main(){
        long fp, fh;
        long edge, vertex;
        int i =1;
        
        while(true){
            try{
                string[] data = Console.ReadLine().Split(' ');
                fp = long.Parse(data[0]);
                fh = long.Parse(data[1]);

                edge = (fp*5+fh*6)/2;
                vertex = 2-(fp+fh)+edge;
                Console.WriteLine($"Molecula #{i}.:.");
                Console.WriteLine($"Possui {vertex:0} atomos e {edge:0} ligacoes\n");
                i++;
            }
            catch{
                break;
            }

        }

        }
}