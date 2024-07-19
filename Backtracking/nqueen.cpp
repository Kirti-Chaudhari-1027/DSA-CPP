#include<iostream>
#include<vector>

using namespace std;

void addSolution(vector<vector<int>>& board, vector<vector<int>>& ans,int n){
    vector<int> temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int>>& board, int n){
    int x = row;
    int y = col;

    //row backward
    while(y>=0)//error
    {
        if(board[x][y] == 1)
            return false;
        y--;
    }

    //error
    x = row;
    y = col;

    //upper backward diagonal
    while(x>=0 && y>=0){
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    //error
    x = row;
    y = col;
    //lower backward diagonal
    while(x<n && y>=0)//error
    {
        if(board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}

void Solve(int col,vector<vector<int>>& board,vector<vector<int>>& ans,int n){

    //base case
    if(col == n){
        addSolution(board,ans,n);
        return;
    }

    //Solve 1 case else recursion will solve
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            //recursive call
            Solve(col+1,board,ans,n);
            //backtracking
            board[row][col]=0;
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;

    Solve(0,board,ans,n);

    cout<<"Solution = "<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)//error
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}