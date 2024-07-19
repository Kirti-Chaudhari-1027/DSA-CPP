// Find the "Kth" max and min element of an array 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int k;
    cin>>k;

    vector<int> vec = {4,5,1,7,9,10,32,0,6};

    int n = vec.size();

    sort(vec.begin(),vec.end());

    //for kth max
    int i = n-k;

    cout<<"kth max = "<<vec[i]<<endl;

    //for kth min
    cout<<"kth min = "<<vec[k];
    
}