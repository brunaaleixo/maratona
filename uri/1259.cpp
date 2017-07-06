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
    int n, d;

    cin >> n;
    vector<int > pares;
    vector<int > impares;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp % 2 == 0) {
            pares.pb(temp);
        } else {
            impares.pb(temp);
        }
    }

    sort (pares.begin(), pares.end());
    sort (impares.begin(), impares.end());
    reverse (impares.begin(), impares.end());

    for (int i = 0; i < pares.size(); i++) {
        cout << pares[i] << endl;
    }
    for (int i = 0; i < impares.size(); i++) {
        cout << impares[i] << endl;
    }
    
    return 0;
}
