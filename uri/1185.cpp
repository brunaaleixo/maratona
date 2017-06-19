#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n)fr(i,0,n)
#define pb push_back
#define mp make_pair

constexpr int maxn = 0;

typedef pair<int, int> ii;

char mat[101][101];
int visited[101][101] = {{0}};

bool valid(int i, int j, int altura, int largura)
{
	return (i >= 0 && i < altura && j >= 0 && j < largura);
}

bool ehSeta(char c)
{
	return(c == '^' || c == '<' || c == '>' || c == 'v');
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int largura, altura;
	cin >> largura >> altura;
	map<char, pair<int, int> > dir;
	dir['>'] = mp(0,1);
	dir['<'] = mp(0,-1);
	dir['v'] = mp(1, 0);
	dir['^'] = mp(-1,0);

	rp(i, altura){
		rp(j, largura){
			cin >> mat[i][j];
		}
	}
	int curI = 0, curJ = 0;
	ii curDir;
	while(true)
	{
		if(visited[curI][curJ] && ehSeta(mat[curI][curJ]))
		{
			cout << "!" << endl;
			return 0;
		}
		if(!valid(curI, curJ, altura, largura))
		{
			cout << "!" << endl;
			return 0;
		}
		if(mat[curI][curJ] == '*')
		{
			cout << "*" << endl;
			return 0;
		}
		if(ehSeta(mat[curI][curJ]))
		{
			curDir = dir[mat[curI][curJ]];
		}
		visited[curI][curJ] = 1;
		curI += curDir.fi;
		curJ += curDir.se;
	}

	return 0;


}
