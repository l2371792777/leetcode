#include<iostream>
#include<vector>

using namespace std;

int test(int n);
int min(int i,int j,int k);

int main(int argc,char* argv[]){
   cout<<test(10);
   return 0;
}

int min(int i,int j,int k){
   int temp=0;
   if(i<j){
      temp=i;
   }
   else{
      temp=j;
   }
   if(temp>k){
      temp=k;
   }
   return temp;
}
int test(int n){
   vector<int> init;
   vector<int> num2={2,0},num3={3,0},num5={5,0};
   int temp=1;
   init.push_back(temp);
   for(int i=1;i<n;i++){
      temp=min(init[num2[1]]*num2[0],init[num3[1]]*num3[0],init[num5[1]]*num5[0]);
      if(temp==init[num2[1]]*num2[0]){
         num2[1]++;
      }
      else if(temp==init[num3[1]]*num3[0]){
         num3[1]++;
      }
      else if(temp==init[num5[1]]*num5[0]){
         num5[1]++;
      }
      if(init[i-1]!=temp){
         init.push_back(temp);
      }
      else{
         i--;
      }
   }
   return temp;
}
