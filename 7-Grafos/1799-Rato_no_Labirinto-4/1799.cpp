// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

bool in(std::vector<std::string> arr, std::string pro){
    for(std::string i : arr){
        if (i  == pro){
            return true;
        }
    }
    return false;
    
}

int bfs(std::string ini, std::string end,std::unordered_map<std::string, std::vector<std::string>> graph){
std::string current;
    std::vector<std::string> queue = {ini};
    std::vector<std::string> processed;

    std::unordered_map<std::string, int> price;
    price[ini]=0;
    
    while (queue.size() != 0){
        current=queue[0];
        for(std::string neighbor : graph[current]){
            bool inq, infpro;
            inq=in(queue, neighbor);
            infpro=in(processed, neighbor);
            if(not inq && not infpro){
                queue.push_back(neighbor);
                price[neighbor]=price[current]+1;
                if (neighbor==end){
                    return price[neighbor];
                }
            }
}
            processed.push_back(current);
            queue.erase(queue.begin()+0);

  
    }
    return 0;

}


int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    int vertic, repeat;
    std::string a, b;
    
    std::cin>>vertic;
    std::cin>>repeat;
    for(int i=0; i<repeat; i++){
        std::cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //BFS
        int result;
        result+=bfs("Entrada","*", graph);
        result+=bfs("*","Saida", graph);
        std::cout<<result<<std::endl;
    
    
    

    return 0;
}