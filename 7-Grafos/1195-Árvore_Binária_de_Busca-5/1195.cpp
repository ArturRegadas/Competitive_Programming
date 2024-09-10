#include <iostream>
#include <vector>
#include <map>

void insere_arvore(std::map<int, std::vector<int>>& tree, int root, int value) {
    if (value < root) {
        if (tree[root][0] == -1) {
            tree[root][0] = value;
            tree[value] = {-1, -1};
        } else {
            insere_arvore(tree, tree[root][0], value);
        }
    } else {
        if (tree[root][1] == -1) {
            tree[root][1] = value;
            tree[value] = {-1, -1};
        } else {
            insere_arvore(tree, tree[root][1], value);
        }
    }
}

void prefixo(const std::map<int, std::vector<int>>& tree, int root, std::vector<int>& resultado) {
    if (root != -1) {
        resultado.push_back(root);
        prefixo(tree, tree.at(root)[0], resultado);
        prefixo(tree, tree.at(root)[1], resultado);
    }
}

void infixo(const std::map<int, std::vector<int>>& tree, int root, std::vector<int>& resultado) {
    if (root != -1) {
        infixo(tree, tree.at(root)[0], resultado);
        resultado.push_back(root);
        infixo(tree, tree.at(root)[1], resultado);
    }
}

void posfixo(const std::map<int, std::vector<int>>& tree, int root, std::vector<int>& resultado) {
    if (root != -1) {
        posfixo(tree, tree.at(root)[0], resultado);
        posfixo(tree, tree.at(root)[1], resultado);
        resultado.push_back(root);
    }
}

void resolver_casos(int casos) {
    for (int caso = 1; caso <= casos; ++caso) {
        int n;
        std::cin >> n;
        std::vector<int> valores(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> valores[i];
        }
        
        std::map<int, std::vector<int>> tree;
        int root = valores[0];
        tree[root] = {-1, -1};

        for (int i = 1; i < n; ++i) {
            insere_arvore(tree, root, valores[i]);
        }

        std::vector<int> pre_resultado, in_resultado, post_resultado;
        prefixo(tree, root, pre_resultado);
        infixo(tree, root, in_resultado);
        posfixo(tree, root, post_resultado);

        std::cout << "Case " << caso << ":\n";
        std::cout << "Pre.:";
        for (size_t i = 0; i < pre_resultado.size(); ++i) {
            std::cout << (i == 0 ? " " : " ") << pre_resultado[i];
        }
        std::cout << "\nIn..:";
        for (size_t i = 0; i < in_resultado.size(); ++i) {
            std::cout << (i == 0 ? " " : " ") << in_resultado[i];
        }
        std::cout << "\nPost:";
        for (size_t i = 0; i < post_resultado.size(); ++i) {
            std::cout << (i == 0 ? " " : " ") << post_resultado[i];
        }
        std::cout << "\n\n";
    }
}

int main() {
    int c;
    std::cin >> c;
    resolver_casos(c);
    return 0;
}
