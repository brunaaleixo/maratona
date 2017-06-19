/*input
7 7 15
#######
#<#* *#
#*# # #
# #*#*#
#*# # #
# * #*#
#######
DWWWWRWWUWWWWRW
3 10 10
##########
#<*******#
##########
WLRUDRWWWW
0 0 0
*/
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <utility>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n)fr(i,0,n)
#define all(v) (v).begin(), (v).end()


using namespace std;



pair<int, int> u(-1, 0);
pair<int, int> d(1, 0);
pair<int, int> r(0, 1);
pair<int, int> l(0, -1);
pair<int, int> f(0, 0);


pair<int, int> getDir(char dir) {
    if (dir == 'D') {
        return d;
    }
    if (dir == 'U') {
        return u;
    }
    if (dir == 'R') {
        return r;
    }
    if (dir == 'L') {
        return l;
    }
    return f;
}

int main()
{
    int lin, col, inst, l1, c;
    cin >> lin >> col >> inst;
    
    while(lin + col + inst != 0)
    {
        vector<vector<char>> mat(lin, vector<char>(col, ' '));
        cin.ignore(256, '\n');
        
        fr(i, 0, lin) {
            string s;
            getline(cin, s);
            fr(j, 0, col) {
                
                mat[i][j] = s[j];
                
                if (s[j] == '<') {
                    l1 = i;
                    c = j;
                }
            }
        }
        
        int cont = 0;
        char lastDir = 'R';
        rp (i, inst) 
        {
            char dir;
            cin >> dir;
            
            if (dir == 'W') {
                dir = lastDir;
                pair<int, int> d1 = getDir(dir);

                if (d1.first + l1 < lin || d1.second + c < col) {
                    if (mat[d1.first + l1][d1.second + c] == '*') {
                        cont++;
                        mat[d1.first + l1][d1.second + c] = ' ';
                        l1 += d1.first;
                        c += d1.second;
                    } else if (mat[d1.first + l1][d1.second + c] == ' ') {
                        l1 += d1.first;
                        c += d1.second;
                    }
                }
                
            }

            lastDir = dir;
           
        }
        
        cout << cont << endl;
        
        cin >> lin >> col >> inst;
    }
	return 0;
    
}