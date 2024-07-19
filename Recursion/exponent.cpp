#include<iostream>
using namespace std;

//Approach-1

// int expo(int n,int m){
//     //base case 
//     if(m == 0){
//         return 1;
//     }

//     int ans = n * expo(n,m-1);

//     return ans;
// }

//Approach-2

int expo(int n,int m){
    //base case
    if(m == 0){
        return 1;
    }

    int ans = expo(n, m/2);

    if(m%2 == 0){
        return ans*ans;
    }
    else{
        return n*ans*ans;
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    cout<<expo(n,m);
}