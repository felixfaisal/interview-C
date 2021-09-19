// C++ program to demonstrate functionality of unordered_map
#include <iostream>
#include <unordered_map>
using namespace std;

unsigned int fib(int n, unordered_map<int,unsigned int>* umap){
    //unordered_map<int,int> map = umap;
    if((*umap).find(n) != (*umap).end()){
        // cout<<"Found in map +"<<n<<":"<<(*umap)[n]<<endl;
        return (*umap)[n];
    }
    if(n<=2) return 1;
    (*umap).insert(make_pair(n,fib(n-1, umap) + fib(n-2,umap)));
    // map[n] = ;
    return (*umap)[n];
}
int main()
{
    unordered_map<int, unsigned int> map;
    unordered_map<int, unsigned int>* umap = &map;
	cout<<"Hello World\n";
    cout<<fib(50, umap);
   
}
