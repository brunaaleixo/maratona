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
    char d;
    string n;

    cin >> d >> n;

    while (d != '0' && n != "0") {
        int left0 = 1;
        for (int i=0; i < n.size(); i++) {
            
            if (n.at(i) != d) {
                if (n.at(i) != '0' || !left0) {
                    cout << n.at(i);
                    left0 = 0;
                }
            }
        }
        
        if (left0 == 1) {
            cout << 0;
        }
        left0 = 1;
        cout << endl;
        cin >> d >> n;
    }
    
    return 0;
}