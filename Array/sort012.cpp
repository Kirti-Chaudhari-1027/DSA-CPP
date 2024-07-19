// Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;

    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            count_0++;
        }
        else if(arr[i] == 1){
            count_1++;
        }
        else{
            count_2++;
        }
    }

    for(int i=0;i<count_0;i++){
        arr[i] = 0;
    }

    for(int i=count_0;i<count_0+count_1;i++){
        arr[i] = 1;
    }

    for(int i=count_0+count_1;i<count_0+count_1+count_2;i++){
        arr[i] = 2;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}