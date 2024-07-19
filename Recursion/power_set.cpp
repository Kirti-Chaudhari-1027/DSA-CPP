#include<iostream>
#include<vector>
using namespace std;

void powerSet(vector<int> arr,vector<int> output,int index){
    //base case
    if(index >= arr.size()){
        cout<<"{ ";
        for(auto i:output){
            cout<<i<<" ";
        }
        cout<<"}";
        cout<<endl;

        return;
    }

    //exclude
    powerSet(arr,output,index+1);

    //include
    output.push_back(arr[index]);
    powerSet(arr,output,index+1);
}

int main(){

    vector<int> arr;
    vector<int> output;
    arr = {2,4,7,0};

    powerSet(arr,output,0);
}