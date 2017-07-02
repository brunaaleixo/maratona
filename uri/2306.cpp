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
	int n, numPedras = 0;
	cin >> n;
	vector<int > pedras(n);

	for (int i = 0; i< n; i++) {
		int temp;
		cin >> temp;
		pedras[i] = temp;
		numPedras += temp;
	}

	int qtdMax = ((2*numPedras / n) + n - 1)/2;

	int cont = 0, j = n - 1, tot = 0;
	for (int i = qtdMax; j >= 0; i--) {
		tot += i;
		if (pedras[j] - i > 0) {
			cont += pedras[j] - i;
		}
		j--;
	}

	if (tot != numPedras) {
		cout << -1 << endl;
		return 0;
	}

	cout << cont << endl;

	return 0;
}