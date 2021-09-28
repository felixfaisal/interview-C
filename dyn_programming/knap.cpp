#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int kmap[100][1000];
int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int *wt, int *vl, int W, int n){
    if(n==0 || W==0){
        return 0;
    }
    if(kmap[n][W]!=-1){
        return kmap[n][W];
    }
    if(wt[n-1]>W){
        return kmap[n][W]=knapsack(wt, vl, W, n-1);
    }
    else{
        return kmap[n][W]=max(vl[n-1] + knapsack(wt,vl,W-wt[n-1], n-1), knapsack(wt,vl,W,n-1));
        //return k;
    }
}
//Driver Code
int main(){
    int W = 7; 
    int vl[] = { 1, 4, 5, 7 };
    int wt[] = { 1, 3, 4, 5 };
    int n = sizeof(vl) / sizeof(vl[0]);
    memset(kmap, -1, sizeof(kmap));
    cout<<knapsack(wt,vl,W,n)<<endl;
    return 0;
}