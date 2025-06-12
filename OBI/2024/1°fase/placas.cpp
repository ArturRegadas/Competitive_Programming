#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
unordered_set<char> nums = {'1','2','3','4','5','6','7','8','9','0'};
unordered_set<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

bool isNum(char c){
    return nums.find(c) != nums.end();
}

bool isAlpha(char c){
    return letters.find(c) != letters.end();
}

int main(){
    
    string a;
    cin>>a;
    if (a.size() == 8){
        if(isAlpha(a[0]) && isAlpha(a[1]) && isAlpha(a[2]) && a[3] == '-' && 
            isNum(a[4]) && isNum(a[5]) && isNum(a[6]) && isNum(a[7])){
                printf("1\n");
            }
        else{
            printf("0\n");
        }
    }
    else if(a.size() == 7){
        if(isAlpha(a[0]) && isAlpha(a[1]) && isAlpha(a[2]) && isNum(a[3]) &&
            isAlpha(a[4]) && isNum(a[5]) && isNum(a[6])){
                printf("2\n");
            }
        else{
            printf("0\n");
            }
    }
    else{
        printf("0\n");
    }
}