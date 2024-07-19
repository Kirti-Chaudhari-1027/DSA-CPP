// Find the maximum and minimum element in an array 

#include<iostream>
using namespace std;

int main(){

    int max = -1;
    int min = 999;

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }

    cout<<"Min = "<<min<<endl;
    cout<<"Max = "<<max<<endl;
}