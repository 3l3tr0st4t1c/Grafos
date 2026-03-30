#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct No{
    int vertice;
    struct No* prox;
} No;
typedef struct{
    int numVertices;
    No*listaAdj[MAX];
} Grafo;
Grafo* criarGrafo(int vertices){
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    if(g== NULL){
        printf("Memory Error!/n");
        exit(1);
    }
    g->numVertices = vertices;
    
    for (int i = 0; i<vertices; i++){
        g->listaAdj[i]=NULL;
    }
    return g;
}
No* criarNo(int v){
    No* novo = (No*) malloc(sizeof(No));
    novo->vertice=v;
    novo->prox=NULL;
    return novo;
}

void adicionarAresta(Grafo* g, int v1, int v2) {
    if(v1 >= g-> numVertices|| v2 >= g->numVertices){
        printf("Invalid Vertex!/n");
        return;
    }
    No* novo = criarNo(v2);
    novo-> prox = g->listaAdj[v1];
    g->listaAdj[v1] = novo;
}

void imprimirGrafo(Grafo* g) {
    printf("\nAdjacency list:\n");
    for (int i = 0; i < g-> numVertices; i++) {
        printf("%d -> ", i);
        No* temp = g->listaAdj[i];
        while (temp != NULL) {
            printf("%d ->", temp->vertice);
            temp = temp -> prox;
        }
    printf("NULL\n");
    }
}

void liberarGrafo(Grafo* g) {
    for (int i = 0; i < g->numVertices; i++) {
        No* temp = g->listaAdj[i];
        while (temp != NULL) {
            No* aux = temp;
            temp = temp->prox;
            free(aux);
        }
    }
    free(g);
}

int main() {
    int vertices, aresta;
    int v1, v2;
    printf("Vertex Numbers: ");
    scanf("%d", &vertices);
    
    Grafo* g = criarGrafo(vertices);
    
    printf("Edges Numbers: ");
    scanf("%d", &aresta);
    
    for (int i = 0; i < aresta; i++) {
        printf("Edge %d (origem destino): ", i + 1);
        scanf("%d %d", &v1, &v2);
        
        adicionarAresta(g, v1, v2);
    }
    imprimirGrafo(g);
    liberarGrafo(g);
    return 0;
}
