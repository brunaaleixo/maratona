#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    string s;

    while(n+d){

        cin >> s;
        stack<int> pilha;
        int remove = d;
        for(const char& c : s)
        {
            if(!remove)
                pilha.push(c - '0');
            else if(pilha.empty())
                pilha.push(c - '0');
            else{
                while(!pilha.empty()){
                    while(c - '0' > pilha.top() && remove > 0){
                        pilha.pop();
                        remove--;
                        if(pilha.empty()) break;
                    }
                    pilha.push(c-'0');
                    break;
                }
            }   
        }
        string word;
        while(!pilha.empty()){
            word += ('0' + pilha.top());
            pilha.pop();
        }
        int end = word.size();
        reverse(word.begin(), word.end());
        for(int i = 0; i < end-remove; ++i){
            cout << word[i];   
        }
        cout << endl;
        cin >> n >> d;
    }
    return 0;   
}
