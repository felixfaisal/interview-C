#include<iostream>
#include<vector> 
using namespace std; 
int findmaxSubArray(vector<int>& nums, int size, int max){
    if(size<0){
        cout<<max<<endl;
        return max;
    }
    return std::max(findmaxSubArray(nums,size-1, max+nums[size]), findmaxSubArray(nums, size-1, max)); 
}
 int maxSubArray(vector<int>& nums) {
    vector<int>::iterator ptr;
    int max = 0; 
    for (ptr = nums.begin(); ptr < nums.end(); ptr++){
        int new_max = max+*ptr; 
        max = std::max(max,new_max);    
    }
    return max; 
}
int arr[46];
int climbstaris(int n){
    if(n==0){
        return 1; 
    }
    if(arr[n]!= 0){
        return arr[n];
    }
    if(n>=2){
        return arr[n] = climbstaris(n-2) + climbstaris(n-1);
    }
    else{
        return arr[n] = climbstaris(n-1);
    }
}

int main(){
    vector<int> vect{5,4,-1,7,8};
    int size = vect.size();
    for(int i=0; i<46;i++){
            arr[i] = 0; 
    }
    //cout<<maxSubArray(vect);
    cout<<climbstaris(38)<<endl;
    return 0; 
}
// Max Array question asked in RedHat