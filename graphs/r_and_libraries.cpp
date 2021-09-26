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

void create_path_and_iterate(int s,int n, int c_lib, int c_road, vector<vector<int>> cities, bool* visited, long* count, find_type e){
    if(e==0){
        //*count = *count + 1;
        // cout<<"Creating edge"<<endl;
        visited[s-1] = true;
        for(int i=0; i<n; i++){
            if(cities[i][0] == s){
                int next = cities[i][1];
                *count = *count+1;
                cout<<*count<<endl;
                if(!visited[next-1]){
                    // cout<<"Correct batch"<<endl;
                     //*count = *count+c_road;
                    //visited[next-1] = true;
                    create_path_and_iterate(cities[i][1],n,c_lib,c_road,cities,visited,count, path);
                    //continue;
                }
                continue;
                
            }
            else if(cities[i][1] == s){
                
                int next = cities[i][0];
                if(!visited[next-1]){
                    //cout<<"Bad Batch"<<endl;
                    //visited[next-1] = true;
                    *count = *count+c_road;
                    create_path_and_iterate(next,n,c_lib,c_road,cities,visited,count, path);
                }   
            }
        }
    }
    else{
        for(int i=0; i<n; i++){
            if(cities[i][0] == s){
                cout<<"Creating libraries"<<endl;
                *count = *count+c_lib;
                cout<<*count<<endl;
                visited[s-1]=true;
                // create_path_and_iterate(cities[i][1],path,cities,size, visited, count);
                create_path_and_iterate(cities[i][1],n,c_lib,c_road,cities,visited,count, path);
                break;
            }
        }
    }
}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;    
    }
    long* count = new long;
    *count = 0;
    create_path_and_iterate(cities[0][0],n,c_lib,c_road,cities,visited,count, library);
    cout<<*count<<endl;
    for(int i=0;i<n;i++){
        //cout<<visited[i]<<endl;
        if(visited[i] == false){
            create_path_and_iterate(i+1,n,c_lib,c_road,cities,visited,count, library);
        }
    }
    delete[] visited;
    long size_of_lib = n*c_lib;
    if(*count<size_of_lib) return *count;
    else return size_of_lib;
}


int main(){
    int n = 3;
    int c_lib = 2;
    int c_road = 1;
    vector<vector<int>> vect
    {
        {1,2},
        {3,1},
        {2,3},
    };
    long cost = roadsAndLibraries(n,c_lib,c_road,vect);
    cout<<cost<<endl;
}


