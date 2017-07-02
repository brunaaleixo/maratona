/*input
3 3 1 1
1 2 3
1 3 3
1 10 1
*/
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


#define INF 0x3F3F3F3F
#define pii pair<int, int>

using namespace std;

int main() {
	int l, c, m, n;
	cin >> l >> c;
	cin >> n >> m;
	vector<vector<int> > plantacao(l, vector<int>(c));

	int i2 = 0, j2 = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			int temp;
			cin >> temp;
			plantacao[i][j] = temp;
		}
	}

	int cont = 0, maxCont = 0;
	for (int i = 0; i < l; i += n) {
		for (int j = 0; j < c; j += m) {
			for (int i2 = i; i2 < i + n; i2++) {
				for (int j2 = j; j2 < j + m; j2++) {
					cont += plantacao[i2][j2];
				}
			}
			maxCont = max(cont, maxCont);
			cont = 0;
		}
	}

	cout << maxCont << endl;

	return 0;
}