#include<iostream>
using namespace std;

bool isSorted(int arr[],int index,int n){
    
    //base case
    if(index >= n){
        return true;
    }
    if(arr[index] < arr[index-1]){
        return false;
    }

    return isSorted(arr,index+1,n);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    cout<<"Enter arr = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<isSorted(arr,1,n);
    
}