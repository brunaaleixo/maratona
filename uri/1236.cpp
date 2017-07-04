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
#include <regex>

using namespace std;

int main() {
    string n;
    getline(cin, n);
    for(int j = 0; j < stoi(n); j++){
        string str;
        getline(cin, str);
        
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            
            if (c == ' ' || c == '0') {
                string temp = "";
                int cont = 0;
                while (str[i + cont] == c) {
                    temp += str[i + cont];
                    cont++;
                }
                
                i += cont - 1;
                
                if (cont <= 2) {
                    cout << temp;
                } else {
                    string c = (isspace(temp[0])) ? "$" : "#";
                    string res = "";
                    
                    while (cont > 255) {
                        res += c + char(255);
                        cont -= 255;
                    }
                    
                    res += c + char(cont);
                    
                    cout << res;
                }
            } else {
                cout << c;
            }

        }
        
        cout << endl;
    }
    return 0;
}