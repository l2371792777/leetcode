#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int test(vector<int> nums,int target);

int main(){
    vector<int> nums={3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    cout<<test(nums,10);
    return 0;
}

int test(vector<int> nums,int target){
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<=target;i++){
        for(int j=1;j<=nums.size();j++){
            if(nums[j-1]<=i&& dp[i - nums[j-1]] < INT_MAX - dp[i]){
                dp[i]=dp[i]+dp[i-nums[j-1]];
            }
        }
    }
    return dp[target];
}