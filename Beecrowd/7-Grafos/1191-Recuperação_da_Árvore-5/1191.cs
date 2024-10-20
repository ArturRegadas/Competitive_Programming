using System;
using System.Collections.Generic;

class Program {
    static string FindPosfixo(string prefixo, string infixo) {
        int n = prefixo.Length;
        List<char> resultado = new List<char>();
        Stack<(int pre_idx, int in_start, int in_end)> pilha = new Stack<(int, int, int)>();
        
        pilha.Push((0, 0, n));
        
        while (pilha.Count > 0) {
            var (pre_idx, in_start, in_end) = pilha.Pop();
            
            if (in_start >= in_end) {
                continue;
            }
            
            char raiz = prefixo[pre_idx];
            int in_idx = infixo.IndexOf(raiz);
            
            pilha.Push((pre_idx + 1, in_start, in_idx));
            pilha.Push((pre_idx + (in_idx - in_start) + 1, in_idx + 1, in_end));
            
            resultado.Add(raiz);
        }
        
        resultado.Reverse();
        return new string(resultado.ToArray());
    }

    static void Main() {
        

        while(true) {
            try{
                string[] inputs = Console.ReadLine().Split();
                string prefixo = inputs[0];
                string infixo = inputs[1];
                
                string posfixo = FindPosfixo(prefixo, infixo);
                Console.WriteLine(posfixo);
            }
            catch{
                break;
            }
        }
    }
}
