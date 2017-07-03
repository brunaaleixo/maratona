#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <set>
#include <unordered_map>

#define pii pair<int, int>
#define pb push_back

using namespace std;

int main() {
    int n;

    cin >> n;

    while (n != 0) {
        char s1[27];
        char s2[27];

        for (int i = 0; i < n; i++) {
            cin >> s1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s2[i];
        }

        stack<char > pilha;
        int cont = 0;
        for (int i = 0; i < n; i++) {
            pilha.push(s1[i]);
            cout << "I";

            while (pilha.size() > 0 and s2[cont]==pilha.top()){
                cont++;
                pilha.pop();
                cout << "R";
            }
        }

        if (pilha.size() != 0) {
            cout << " Impossible";
        }

        cout << endl;

        cin >> n;
    }
    
    return 0;
}