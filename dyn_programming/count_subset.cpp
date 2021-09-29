#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int subset_sum(int arr[], int sum, int n){
    if(sum==0 && n==0){
        return 1;
    }
    else if(sum==0){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    if(arr[n-1]<=sum){
        return subset_sum(arr,sum-arr[n-1],n-1) + subset_sum(arr,sum,n-1);
    }
    else{
        return subset_sum(arr,sum,n-1);
    }
}

int main(){
    int arr[] = {2,3,5,6,8,10};
    int sum = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<subset_sum(arr,sum,n)<<endl;
    return 0;
}