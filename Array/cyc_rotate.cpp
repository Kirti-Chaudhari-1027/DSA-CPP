// Write a program to cyclically rotate an array by one.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int temp = arr[0];

    for(int i=0;i<n-1;i++){
        swap(arr[i],arr[i+1]);
    }
    arr[n-1] = temp;

    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
}