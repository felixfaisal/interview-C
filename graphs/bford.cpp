#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V; 
    int** adj;
    public: 
        Graph(int V);
        void add_edge_weight(int u, int v, int w);
        void bellman_floyd();
};

Graph::Graph(int V){
    this->V = V;
    int **A = new int* [V];
    for(int i=0; i<V; i++){
        A[i] = new int[V];
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V; j++){
            A[i][j] = NULL;
        }
    }
    this->adj = A;
}
void Graph::add_edge_weight(int u, int v, int w){
    adj[u][v] = w;
}

void Graph::bellman_floyd(){
    int* distance = new int[V];
    for(int i=0; i<V; i++){
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for(int i=0; i<V; i++){
    for(int i=0;i<(V-1);i++){
        for(int j=0;j<V;j++){
            if (adj[i][j]!=NULL){
                int dist = adj[i][j] + distance[i];
                if(dist<distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }
    }

    for(int i=0;i<V;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}

int main(){
    Graph g(6);
    g.add_edge_weight(0,1,6);
    g.add_edge_weight(0,2,4);
    g.add_edge_weight(0,3,5);
    g.add_edge_weight(1,4,-1);
    g.add_edge_weight(2,1,-2);
    g.add_edge_weight(2,4,3);
    g.add_edge_weight(3,2,-2);
    g.add_edge_weight(3,5,-1);
    g.add_edge_weight(4,5,3);
    g.bellman_floyd();
    return 0;
}