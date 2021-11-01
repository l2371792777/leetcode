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
    int middle=(left+right)/2;
    int days=1;
    int temp=0;
    //cout<<"le "<<left<<" "<<middle<<" "<<right<<endl;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+temp<=middle){
            temp+=weights[i];
        }
        else{
            temp=weights[i];
            days++;
        }
    cout<<" "<<left<<" "<<middle<<" "<<right<<endl;
        if(days>D){
            i=0;temp=0;days=1;
            left=middle;
            middle=(left+right)/2;
        }
        else if(i==(weights.size()-1)&&days!=D){
            //cout<<"ri "<<left<<" "<<middle<<" "<<right<<endl;
            i=0;temp=0;days=1;
            right=middle;
            middle=(left+right)/2;
        }
        else if(i==(weights.size()-1)&&days==D){
            if(right-left>2){
                i=0;temp=0;days=1;
                right=middle;
                middle=(left+right)/2;
            }
        }
    }
    return middle;
}