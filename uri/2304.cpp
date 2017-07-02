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
	int vinicial, ops;
	cin >> vinicial >> ops;
	unordered_map <char, int>  mapa;
	mapa['F'] = vinicial;
	mapa['E'] = vinicial;
	mapa['D'] = vinicial;

	for (int i = 0; i < ops; i++) {
		char op, pessoa;
		cin >> op >> pessoa;

		int val;

		switch (op) {
			case 'C':
				cin >> val;
				mapa[pessoa] -= val;

				break;
			case 'V':
				cin >> val;
				mapa[pessoa] += val;

				break;
			case 'A':
				char pessoa2;
				cin >> pessoa2;
				cin >> val;

				mapa[pessoa2] -= val;
				mapa[pessoa] += val;
				break;
		}

	}

	vector<int > values(3, 0);
	int i = 0;
	for (auto &p: mapa) {
		values[i] = p.second;
		i++;
	}

	for (i = 0; i < 3; i++) {
		cout << values[i];
		if (i != 2) {
			cout << " ";
		}
	}

	cout << endl;

	return 0;
}