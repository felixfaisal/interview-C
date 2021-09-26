#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V; 
    int** adj;
    public: 
        Graph(int V);
        void add_edge_weight(int u, int v, int w);
        void floyd_warshall();
};

Graph::Graph(int V){
    this->V = V;
    int **A = new int* [V];
    for(int i=0; i<V; i++){
        A[i] = new int[V];
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V; j++){
            if(i == j) A[i][j] = 0;
            A[i][j] = INT_MAX;
        }
    }
    this->adj = A;
}
void Graph::add_edge_weight(int u, int v, int w){
    adj[u][v] = w;
}
void Graph::floyd_warshall(){
    int **A = new int* [V];
    for(int i=0; i<V; i++){
        A[i] = new int[V];
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V; j++){
            if(i == j) A[i][j] = 0;
            A[i][j] = adj[i][j];
        }
    }
    for(int k =0; k<V; k++){
        // Picking vertices 
        for(int i=0;i<V;i++){
            // Source vertic 
            for(int j=0;j<V; j++){
                if(i == j){
                    A[i][j] = 0;
                    continue;
                }
                if (A[i][j] > (A[i][k] + A[k][j])
                    && (A[k][j] != INT_MAX
                        && A[i][k] != INT_MAX))
                    A[i][j] = A[i][k] + A[k][j];
            }
        }
    }
    for(int i =0; i<V; i++){
        for(int j=0; j<V; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    Graph g(4);
    g.add_edge_weight(0,1,9);
    g.add_edge_weight(1,0,6);
    g.add_edge_weight(1,3,2);
    g.add_edge_weight(2,0,-4);
    g.add_edge_weight(3,2,1);
    g.floyd_warshall();
    return 0;
}