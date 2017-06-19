#include <stdio.h>
int visitado[110]; // vetor de visitação
int adj[110][110];
void dfs(int u) {
    int v;
    if (visitado[u])
        return;
    visitado[u] = 1;
    for (v=1; v < 110; v++) if (adj[u][v]) {
        dfs(v);
    }
}

int main() {
    int i, j, vertices, arestas, a1, a2, cont = 1, flag = 0;
    
    scanf("%d %d", &vertices, &arestas);
    
    while (vertices != 0 && arestas != 0) {
        for (i=1; i<110; i++) {
            for (j=1; j<110; j++) {
                adj[i][j] = 0;
            }
        }
        
        for (i=0; i<arestas; i++) {
            scanf("%d %d", &a1, &a2);
            adj[a1][a2] = 1;
            adj[a2][a1] = 1;
        }
        
        // limpa todas as marcas de visitação
        for (i=0; i < 110; i++) visitado[i] = 0;
        
        // inicia busca no nó de índice 1
        dfs(1);
        
        // testa se todos os nós foram visitados com uma única busca
        for (i=1; i <= vertices; i++) {
            if (!visitado[i]) {
                printf("Teste %d\nfalha\n\n", cont);
                flag = 1;
                break;
            }
            
        }
        
        if (!flag) {
            printf("Teste %d\nnormal\n\n", cont);
        }
        
        flag = 0;
        
        cont++;
        
        scanf("%d %d", &vertices, &arestas);
    }

 
    return 0;
}