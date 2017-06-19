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
 
typedef  pair<int, int> pii;
 
struct Graph
{
    int V, E;
    set< pair<int, pii> > edges;
 
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
 
    void addEdge(int u, int v, int w)
    {
        pii conection(u,v);
        pair<int, pii> edge(w, conection);
        edges.insert(edge);
    }

    int totalSavings();
};
 
struct DisjointSets
{
    int *parent, *rnk;
    int n;
 
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
 
        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
 
            //every element is parent of itself
            parent[i] = i;
        }
    }
 
    // Find the parent of a node 'u'
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
 
    int merge(int x, int y)
    {
        x = find(x), y = find(y);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (x == y) {
            return 0;
        }

        /* Make tree with smaller height
           a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else 
            parent[x] = y;
 
        if (rnk[x] == rnk[y])
            rnk[y]++;

        return 1;
    }
};
 
 /* Returns total weight of edges not included in the 
  Minimum Spanning Tree */
 
int Graph::totalSavings()
{
    int economy = 0;
  
    DisjointSets ds(V);
 
    for(auto par : edges)
    {
        int u = par.second.first;
        int v = par.second.second;
 
        int merged = ds.merge(u, v);

        if (!merged) {
            economy += par.first;
        }
    }
 
    return economy;
}

int main()
{
    int vertices, edges, n, m, a, b, p; 
    n = m = 1;
 
    while(n + m != 0) {
        cin >> vertices;
        cin >> edges;

        Graph g(vertices, edges);
        
        for (int i = 0; i<edges; i++) {
            scanf("%d %d %d", &a, &b, &p);

            g.addEdge(a, b, p);
        }

        scanf("%d %d", &n, &m);

        int economy = g.totalSavings();
 
        cout << economy << endl;
    }
    
 
    return 0;
}