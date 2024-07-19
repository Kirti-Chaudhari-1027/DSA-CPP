#include<iostream>
using namespace std;

int waysToReach(int n){

    //base case
    if(n < 0){
        return 0;
    }
    if(n == 0 || n == 1){
        return 1;
    }

    return waysToReach(n-1) + waysToReach(n-2) + waysToReach(n-3);
}

int main(){
    int n;
    cin>>n;

    cout<<waysToReach(n);
}