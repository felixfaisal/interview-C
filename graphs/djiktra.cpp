#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    int** adj;

    public: 
        Graph(int V);
        void add_edge_weight(int u, int v, int w);
        void DFS(int s);
        void djikstra(int s);
        int findMinVertex(int *distance, bool* visisted);
};

Graph::Graph(const int V){
    this->V = V;
    int **a = new int*[V];
    for(int i=0; i<V;i++){
        a[i] = new int[V];
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V; j++){
            a[i][j] = NULL;
        }
    }
    this->adj = a;
}
void Graph::add_edge_weight(int u, int v,int w){
    adj[u][v] = w;
    adj[v][u] = w;
}
int Graph::findMinVertex(int* distance, bool* visited){
    int minVertex = -1;
    for(int i=0; i<V; i++){
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void Graph::djikstra(int s){
    int* distance = new int[V];
    bool* visited = new bool[V];

    for(int i=0;i<V; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[s] = 0;
    for(int i=0; i<V-1; i++){
        int minVertex = findMinVertex(distance, visited);
        cout<<"Min Vertex for "<<i<<" is "<<minVertex<<endl; 
        visited[minVertex] = true;
        for(int j =0; j<V; j++){
            if(adj[minVertex][j]!=NULL && !visited[j]){
                int dist = distance[minVertex] + adj[minVertex][j];
                if(dist<distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }
    for(int i=0; i<V; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
}

void Graph::DFS(int s){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(adj[i][j]!=NULL){
                cout<<adj[i][j]<<endl;
            }
        }
    }
}
int main(){
    Graph g(5);
    g.add_edge_weight(0,1,4);
    g.add_edge_weight(0,2,8);
    g.add_edge_weight(1,2,2);
    g.add_edge_weight(1,3,5);
    g.add_edge_weight(2,3,5);
    g.add_edge_weight(2,4,9);
    g.add_edge_weight(3,4,4);
    g.add_edge_weight(0,4,1);
    g.djikstra(1);
    return 0;
}