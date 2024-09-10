#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

std::string FindPosfixo(const std::string& prefixo, const std::string& infixo) {
    int n = prefixo.length();
    std::vector<char> resultado;
    std::stack<std::tuple<int, int, int>> pilha;

    pilha.push(std::make_tuple(0, 0, n));

    while (!pilha.empty()) {
        auto [pre_idx, in_start, in_end] = pilha.top();
        pilha.pop();

        if (in_start >= in_end) {
            continue;
        }

        char raiz = prefixo[pre_idx];
        int in_idx = infixo.find(raiz);

        pilha.push(std::make_tuple(pre_idx + 1, in_start, in_idx));
        pilha.push(std::make_tuple(pre_idx + (in_idx - in_start) + 1, in_idx + 1, in_end));

        resultado.push_back(raiz);
    }

    std::reverse(resultado.begin(), resultado.end());
    return std::string(resultado.begin(), resultado.end());
}

int main() {
    std::string prefixo, infixo;
    
    while (std::cin >> prefixo >> infixo) {
        std::string posfixo = FindPosfixo(prefixo, infixo);
        std::cout << posfixo << std::endl;
    }

    return 0;
}
