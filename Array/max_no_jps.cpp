//Minimum no. of Jumps to reach end of an array

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> vec(n);

    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    int ans;
    int des = n-1;
    int coverage = 0;
    int totalJumps = 0;
    int lastJumpIndex = 0;

    //base case 
    if(n==1){
        ans = 1;
    }

    for(int i=0;i<n;i++){
        coverage = max(coverage , vec[i]+i);

        if(lastJumpIndex == i){
            lastJumpIndex = coverage;
            totalJumps++;
        

            if(coverage >= des){
                ans = totalJumps;
                break;
            }

        }
    }

    cout<<"ans = "<<ans;
    
}