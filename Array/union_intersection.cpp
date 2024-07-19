// Find the Union and Intersection of the two sorted arrays

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int arr1[n];
    int arr2[m];


    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<endl;

    for(int j=0;j<m;j++){
        cin>>arr2[j];
    }

    //union
    vector<int> union_arr;
    vector<int> inter_arr;

    int i=0,j=0;

    while(i!=n && j!=m){

        if(arr1[i]!=arr2[j] && arr1[i]<arr2[j]){
            union_arr.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]!=arr2[j] && arr1[i]>arr2[j]){
            union_arr.push_back(arr2[j]);
            j++;
        }
        else{
            union_arr.push_back(arr1[i]);
            //intersection
            inter_arr.push_back(arr1[i]);
            i++;
            j++;
        }

    }

    cout<<"Union = ";
    for(int i=0;i<union_arr.size();i++){
        cout<<union_arr[i]<<" ";
    }
    cout<<endl;

    //intersection

    cout<<"Intersection = ";
    for(int i=0;i<inter_arr.size();i++){
        cout<<inter_arr[i]<<" ";
    }
    cout<<endl;
    


}