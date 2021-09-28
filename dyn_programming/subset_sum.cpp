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
int main(){
    int sum = 10;
    int wt[] = {5,3,2,6};
    memset(arr,-1,sizeof(arr));
    int n = sizeof(wt)/sizeof(int);
    cout<<subset(wt,sum,n)<<endl;
}