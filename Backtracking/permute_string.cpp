#include<iostream>
using namespace std;

void permute(string& word,int s,int e){

    //base case
    if(s == e){
        cout<<"["<<word<<"]"<<endl;
    }

    for(int i=s;i<=e;i++){

        swap(word[s],word[i]);

        permute(word,s+1,e);

        //backtrack
        swap(word[s],word[i]);
    }
}

int main(){

    string word;
    cin>>word;

    int n = word.length()-1;

    permute(word,0,n);
}