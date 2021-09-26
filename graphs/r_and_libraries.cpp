/*
Determine the minimum cost to provide library access to all citizens of HackerLand. There are cities numbered from to . Currently there are no libraries and the cities are not connected. Bidirectional roads may be built between any city pair listed in

. A citizen has access to a library if:

    Their city contains a library.
    They can travel by road from their city to a city containing a library.

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
enum find_type{path, library};
void create_path_and_iterate(int s, find_type e, int cities[6][2], int size, bool* visited, int* count){
    if(e==0){
        cout<<"Creating path"<<endl;
        visited[s-1] = true;
        for(int i=0; i<size; i++){
            if(cities[i][0] == s){
                int next = cities[i][1];
                *count = *count+5;
                if(!visited[next-1]){
                    //visited[next-1] = true;
                    create_path_and_iterate(cities[i][1],path,cities,size, visited, count);
                }
                
            }
        }
    }
    if(e==1){
        for(int i=0; i<size; i++){
            if(cities[i][0] == s){
                cout<<"Creating library"<<endl;
                *count = *count+2;
                visited[s-1]=true;
                create_path_and_iterate(cities[i][1],path,cities,size, visited, count);
                break;
            }
        }
    }
}

int main(){
    int q = 2; 
    int n = 3; 
    int size = 6;
    int c_lib = 2;
    int c_road = 5;
    int cities[6][2] = {{1,3},{3,4},{2,4},{1,2},{2,3},{5,6}};
    bool* visited = new bool[size];
    for(int i=0;i<size;i++){
        visited[i] = false;    
    }
    int* count = new int;
    *count = 0;
    create_path_and_iterate(cities[0][0],library,cities, size,visited,count);
    // We will check for any unvisited nodes
    for(int i=0;i<size;i++){
        // cout<<visited[i]<<endl;
        if(visited[i] == false){
            create_path_and_iterate(i,library,cities,size,visited,count);
        }
    }
    //create_path_and_iterate(6,path);
    int create_lib = size*c_lib; 
    cout<<"Total count is "<<*count<<endl;
    cout<<"Cost of library is "<<create_lib<<endl;

    delete count;
    delete [] visited;
    
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;    
    }
    long* count = new long;
    *count = 0;
    //create_path_and_iterate(cities[0][0],library,cities, size,visited,count);
    for(int i=0;i<n;i++){
        if(visited[i] == false){
            //create_path_and_iterate(i,library,cities,size,visited,count);
        }
    }
    long size_of_lib = n*c_lib;
    if(*count<size_of_lib) return *count;
    else return size_of_lib;
}
