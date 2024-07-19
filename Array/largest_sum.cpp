// find Largest sum contiguous Subarray

#include<iostream>
#include <limits.h>
using namespace std;

int main(){
    int n,sum_1=0;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        sum_1 = sum_1 + arr[i];
    }

    int max_sum = sum_1;

    if(n<=1){
        max_sum = arr[0];
    }
    else{
        int k=2;
        int sum;
        while(k!=n){
            for(int i=0;i<n-k;i++){
                sum=0;
                for(int j=i;j<i+k;j++){
                    sum = sum + arr[j];
                }

                if(max_sum < sum){
                    max_sum = sum;
                }
            }
            k++;
        }
    }

    cout<<"Max sum = "<<max_sum;
}