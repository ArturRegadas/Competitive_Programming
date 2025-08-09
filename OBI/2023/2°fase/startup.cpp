#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node{
    public:
    int parent, salary;
    vector<int> son;
    Node():parent(-1), salary(0){}
    Node(int p, int s) : parent(p),salary(s){}
};

unordered_map<int, Node> tree;


int main(){
    int n;
    scanf("%d", &n);

    int parent, salary;
    scanf("%d%d", &parent, &salary);
    tree[1] = Node(parent, salary);
    for(int i = 2; i<=n;i++){
        scanf("%d%d", &parent, &salary);
        tree[i] = Node(parent, salary);
        tree[parent].son.push_back(i);
    }
    int current;
    vector<int> stack = {1};
    unordered_set<int> ans;
    while(!stack.empty()){
        current = stack.back();
        stack.pop_back();
        for(int i : tree[current].son){
            if(tree[i].salary > tree[current].salary)
                ans.insert(current);
            stack.push_back(i);
        }
    }
    int c;
    scanf("%d", &c);
    printf("%d\n", ans.size());
    
    for(int i =0; i<c;i++){
        scanf("%d%d", &current, &salary);
        parent = tree[current].parent;
        tree[current].salary = salary;

        if(ans.find(parent) != ans.end()){
            ans.erase(parent);
            for(int s : tree[parent].son){
                if(tree[s].salary > tree[parent].salary){
                    ans.insert(parent);
                    break;
                }
            }
        }
        else{
            if(tree[parent].salary < tree[current].salary)
                ans.insert(parent);
        }
        
        ans.erase(current);
        for(int s : tree[current].son){
            if(tree[s].salary > tree[current].salary){
                ans.insert(current);
                break;
            }
        }
        
        printf("%d\n", ans.size());
    }


    return 0;

}