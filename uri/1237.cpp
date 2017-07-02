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

using namespace std;

int main() {
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);

        int LCSuff[s1.size()+1][s2.size()+1];
        int result = 0; 
     
        for (int i=0; i<=s1.size(); i++) {
            for (int j=0; j<=s2.size(); j++) {
                if (i == 0 || j == 0)
                    LCSuff[i][j] = 0;
     
                else if (s1.at(i-1) == s2.at(j-1))
                {
                    LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                    result = max(result, LCSuff[i][j]);
                }
                else LCSuff[i][j] = 0;
            }
        }
        cout << result << endl;
    }
    

    return 0;
}