/*input
10 10
2 2
3
3 3 3
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

int adjacente(int i1, int j1, int i2, int j2) {
	return (abs(i1 - i2) == 1 || abs(j1 - j2) == 1);
}

int main() {
	int n, m, micI, micJ, mov, posI = 0, posJ = 0, cont = 0;
	cin >> n >> m;
	cin >> micI >> micJ;
	cin >> mov;

	unordered_map <int, pii>  mapa;

	mapa[1] = make_pair(0, 1);
	mapa[2] = make_pair(0, -1);
	mapa[3] = make_pair(-1, 0);
	mapa[4] = make_pair(1, 0);

	if (adjacente(posI, posJ, micI, micJ)) {
		cont++;
	}

	for (int i = 0; i < mov; ++i) {
		int dir;
		cin >> dir;

		if (posI + mapa[dir].first >= 0 && posI + mapa[dir].first <= n && posJ + mapa[dir].second >= 0 && posJ + mapa[dir].second <= m) {
			posI += mapa[dir].first;
			posJ += mapa[dir].second;
		}

		if (adjacente(posI, posJ, micI, micJ)) {
			cont++;
		}
		
	}

	cout << cont << endl;

	return 0;
}