#include<iostream>
using namespace std;

void word(int n){
    //base case
    if(n <= 0){
        return;
    }

    //process
    string arr[10] = { "zero" , "one" , "two" , "three" , "four" , "five" , 
                        "six" , "seven" , "eight" , "nine" };

    int rem = n%10;
    word(n/10);

    cout<<arr[rem]<<" ";
}

int main(){
    int n;

    cin>>n;

    word(n);

}