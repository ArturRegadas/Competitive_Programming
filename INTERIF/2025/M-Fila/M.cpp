#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> queue;
    vector<string> priority_queue;
    string cmd, name;
    int age;
    cin>> cmd>>name>>age;
    if(age > 54)
        priority_queue.push_back(name);
    
    else
        queue.push_back(name);
    while(priority_queue.size() > 0 || queue.size() > 0){
        cin>>cmd;
        if(cmd=="CHEGADA"){
            cin>>name>>age;
            if(age > 54)
                priority_queue.push_back(name);
            
            else
                queue.push_back(name);
            }
        else{
            if(priority_queue.size()>0){
                cout<<priority_queue[0]<<endl;
                priority_queue.erase(priority_queue.begin());
            }
            else{
                cout<<queue[0]<<endl;
                queue.erase(queue.begin());
            }

        }
    }

    return 0;
}