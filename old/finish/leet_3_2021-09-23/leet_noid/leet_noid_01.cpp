#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int test(vector<int> weights,int D);
int sums(vector<int> weights,int i,int j);

int main(){
    vector<int> nums={3,2,2,4,1,4};
    cout<<test(nums,3);
    return 0;
}

int sums(vector<int> weights,int i,int j){
    int sum=0;
    for(;i<j;i++){
        sum+=weights[i];
    }
    return sum;
}
int max(vector<int> weights){
    int temp=0;
    for(int i=0;i<weights.size();i++){
        if(temp<weights[i]){
            //cout<<temp<<endl;
            temp=weights[i];
        }
    }
    return temp;
}
int test(vector<int> weights,int D){
    int left=max(weights);
    int right=sums(weights,0,weights.size());
    while(left<right){
    int middle=(left+right)/2;
    int days=1;
    int temp=0;
    for(auto it:weights){
        if(temp+it>middle){
            ++days;
            temp=0;
        }
        temp+=it;
    }
    if(days<=D){
        right=middle;
    }
    else{
        left=middle+1;
    }
    }
    return left;
}