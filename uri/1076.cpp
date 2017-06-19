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
#include <list>
 
using namespace std;
 
class Graph {
    int V; 
    list<int> *adj; 

    void DFSUtil(int v, vector<int> visited, int* size) {
	    visited[v] = true;
	 
	    list<int>::iterator i;
	    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
	    	(*size)++;

	        if (!visited[*i])
	            DFSUtil(*i, visited, size);
	    }
	}

public:
    Graph(int V) {
	    this->V = V;
	    adj = new list<int>[V];
	}

    void addEdge(int v, int w) {
    	int exists = find(adj[v].begin(), adj[v].end(), w) != adj[v].end();
    	if (!exists) {
		    adj[v].push_back(w); 
		    adj[w].push_back(v); 
    	}
	}

    int DFS(int v) {
    	int size = 0;
	    vector<int> visited;
	    visited.resize(V);
	    fill(visited.begin(), visited.end(), 0);
	 
	    DFSUtil(v, visited, &size);

	    return size;
	}
};

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int pontoPartida, numVertices, numArestas;
		cin >> pontoPartida >> numVertices >> numArestas;

		Graph g(numVertices);

		for (int j = 0; j < numArestas; j++) {
			int v1, v2;
			cin >> v1 >> v2;
			g.addEdge(v1, v2);
		}

		int size = g.DFS(pontoPartida);
		cout << size << endl;
	}
    
    return 0;
}