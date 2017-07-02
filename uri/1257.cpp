#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <unordered_map>

#define pii pair<int, int>
#define pb push_back

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 0; i< n; i++) {
        int l;
        cin >> l;
        int cont = 0;
        for (int j = 0; j < l; j++) {
            string str;
            cin >> str;

            for (int k=0; k < str.size(); k++) {
                cont += str.at(k) - 'A' + k + j;
            }
        }
        cout << cont << endl;
    }
    
    return 0;
}