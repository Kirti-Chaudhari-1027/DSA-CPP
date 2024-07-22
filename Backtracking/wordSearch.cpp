// Given an m x n grid of characters board and a string word, return true if word exists 
// in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent 
// cells are horizontally or vertically neighboring. The same letter cell may not be used more 
// than once.

// example: A B C E   word->"SEE"
//          S F C S
//          A D E E

#include<iostream>
#include<vector>
using namespace std;


bool isSafe(int x,int y,int wrd_idx, vector<vector<char>>& board, string& word, int row,int col){

    if((x>=0 && x<row) && (y>=0 && y<col) && board[x][y] == word[wrd_idx] && board[x][y]!='$'){
        return true;
    }
    else{
        return false;
    }
}

bool Solve(int x,int y,int wrd_idx,vector<vector<char>>& board, string& word,int row,int col){
    //base case
    if(wrd_idx == word.length()){
        return true;
    }
    if(!isSafe(x,y,wrd_idx,board,word,row,col)){
        return false;
    }

    char temp = board[x][y];
    board[x][y] = '$';

    if(Solve(x+1,y,wrd_idx+1,board,word,row,col) || 
       Solve(x-1,y,wrd_idx+1,board,word,row,col) || 
       Solve(x,y+1,wrd_idx+1,board,word,row,col) || 
       Solve(x,y-1,wrd_idx+1,board,word,row,col)){
            
        return true;
    }

    //backtracking
    board[x][y] = temp;
    return false;
}

bool isPresent(vector<vector<char>>& board, string& word){

   int row = board.size();
   int col = board[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            if(board[i][j] == word[0] && Solve(i,j,0,board,word,row,col)){
                return true;
            }
        }
    }

    return false;

}

int main(){

    int row;
    cout<<"row = ";
    cin>>row;

    int col;
    cout<<"col = ";
    cin>>col;

    vector<vector<char>> board(row,vector<char>(col));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>board[i][j];
        }
        cout<<endl;
    }

    string word;
    cout<<"word = ";
    cin>>word;

    if(isPresent(board,word)){
        cout<<"Present";
    }
    else{
        cout<<"Not Present";
    }


}