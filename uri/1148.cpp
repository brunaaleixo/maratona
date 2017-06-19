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


#define INF 0x3F3F3F3F

using namespace std;

int main()
{
    const int maior = 501;
    vector<int> distancia(maior);
    int n = 1, m = 1, q, u, v, cost, a, b;

    while(n + m != 0)
    {

        scanf("%d %d", &n, &m);
        if(n+m == 0)return 0;
        set<pair<int, int> > arestas;
        vector< vector<pair<int, int> > > adjList(n+1);
        // porque pair int? 
        priority_queue< pair<int, int> > pq;

        for(int i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &u, &v, &cost);
            pair<int,int> a1(u,v);
            arestas.insert(a1);

            pair<int,int> a2(v,u);
            if (arestas.find(a1) != arestas.end() && arestas.find(a2) != arestas.end()) {
                adjList[u].push_back(make_pair(0, v));
                adjList[v].push_back(make_pair(0, u));
            } else {
                adjList[u].push_back(make_pair(cost, v));
            }
        }
        
        scanf("%d", &q);
        for(int i = 0; i < q; ++i)
        {
            scanf("%d %d", &a, &b);

            fill(distancia.begin(), distancia.end(), INF);

            distancia[a] = 0;

            pq.push(make_pair(0, a));

            while(!pq.empty())
            {
                pair<int, int> topo = pq.top();
                pq.pop();

                for(auto par : adjList[topo.second])
                {
                    if(topo.first + par.first < distancia[par.second])
                    {
                        distancia[par.second] = topo.first + par.first;
                        pq.push(make_pair(distancia[par.second], par.second)); 
                    }
                }
            }
            if(distancia[b] == INF)
                cout << "Nao e possivel entregar a carta" << endl;
            else {
                cout << distancia[b] << endl;
            }
        }

        cout << endl;
    }
    return 0;
}
