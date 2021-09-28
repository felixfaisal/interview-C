#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int *wt, int *vl, int W, int n){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(wt, vl, W, n-1);
    }
    else{
        return max(vl[n-1] + knapsack(wt,vl,W-wt[n-1], n-1), knapsack(wt,vl,W,n-1));
        //return k;
    }
}
//Driver Code
int main(){
    int W = 7; 
    int vl[] = { 1, 4, 5, 7 };
    int wt[] = { 1, 3, 4, 5 };
    int n = sizeof(vl) / sizeof(vl[0]);
    cout<<knapsack(wt,vl,W,n)<<endl;
    return 0;
}