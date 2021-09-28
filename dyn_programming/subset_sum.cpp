#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][1000];
bool subset(int wt[], int sum, int n){
    if(n==0 && sum==0){
        return true;
    }
    else if(sum==0){
        return true;
    }
    else if(n==0){
        return false;
    }
    if(arr[n][sum]!=-1){
        return arr[n][sum];
    }
    if(wt[n-1]<=sum){
        return arr[n][sum]=subset(wt,sum-wt[n-1],n-1) || subset(wt,sum,n-1);
    }
    else{
        return arr[n][sum]=subset(wt,sum,n-1);
    }
}
bool subset_topdown(int wt[], int sum, int n){
    bool t[n+1][sum+1];
    //initialization
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j] = true;
            }
        }
    }
    // Choice diagram
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(wt[i-1]<=j){
                t[i][j] = t[i-1][j-wt[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    int sum = 10;
    int wt[] = {5,3,2,6};
    memset(arr,-1,sizeof(arr));
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<subset(wt,sum,n)<<endl;
    cout<<subset_topdown(wt,sum,n)<<endl;
    return 0;
}