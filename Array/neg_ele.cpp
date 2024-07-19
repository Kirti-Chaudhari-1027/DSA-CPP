// Move all the negative elements to one side of the array 

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int i=0;
    int j=n-1;

    while(i<j){
        if(arr[i]<0){
            i++;
        }
        else if(arr[j]>0){
            j++;
        }
        else{
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}