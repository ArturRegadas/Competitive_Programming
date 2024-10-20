using System;

class Program {
    static double[] bin(double num){
        double[] bits = new double[33];
        for(int i=32; i>-1; i--){
            double resto = num%2;
            bits[i]=resto;
            num = Math.Floor(num/2);
        }
        return bits;
        
    }
    public static void Main(string[] args) {
        while(true){      
            try{
                string[] nuns = Console.ReadLine().Split(' '); 
                double x =double.Parse(nuns[0]);
                double x1=double.Parse(nuns[1]);
                double[] n1=bin(x);
                double[] n2=bin(x1);
                double resultado=0;
                for(int i =0; i<33; i++){
                    double cv=n1[i]+n2[i];
                    if(cv==2){
                        cv=0;
                    }
                    resultado+=cv*(Math.Pow(2, 32-i));
                }
                Console.WriteLine(resultado);}
            catch{
                break;
            }
            }
        
    }
}
