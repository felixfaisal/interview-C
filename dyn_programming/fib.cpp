// C++ program to demonstrate functionality of unordered_map
#include <iostream>
#include <unordered_map>
using namespace std;

int fib(int n, unordered_map<int,int>* umap){
    if(umap.find(n) != umap.end()){
        return umap[n];
    }
    if(n<=2) return 1;
    umap[n] = fib(n-1, umap) + fib(n-2,umap);
    return umap[n];
}
int main()
{
    unordered_map<int, int> umap;
	cout<<"Hello World\n";
    cout<<fib(10, &umap);
}
