// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the 
//destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from 
//source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), 
//‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked 
//and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be 
//travel through it. Return the list of paths in lexicographically increasing order.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, 
//the rat cannot move to any other cell.

#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int x,int y,int n,vector<vector<int>>& arr,vector<vector<bool>>& visited){
    if((x>=0 && x<n) && (y>=0 && y<n) && arr[x][y]==1 && visited[x][y]==0){
        return true;
    }
    else{
        return false;
    }
}

void solveRat(int x,int y,vector<vector<int>>& arr,int n,vector<vector<bool>>& visited,
                string path,vector<string>& ans)
{
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    //Down 
    if(isSafe(x+1,y,n,arr,visited)){
        visited[x][y] = 1;

        solveRat(x+1,y,arr,n,visited,path+'D',ans);
        visited[x][y] = 0;
    }

    //Left
    if(isSafe(x,y-1,n,arr,visited)){
        visited[x][y] = 1;

        solveRat(x,y-1,arr,n,visited,path+'L',ans);
        visited[x][y] = 0;
    }

    //Right
    if(isSafe(x,y+1,n,arr,visited)){
        visited[x][y] = 1;

        solveRat(x,y+1,arr,n,visited,path+'R',ans);
        visited[x][y] = 0;
    }

    //Up
    if(isSafe(x-1,y,n,arr,visited)){
        visited[x][y] = 1;

        solveRat(x-1,y,arr,n,visited,path+'U',ans);
        visited[x][y] = 0;
    }


}

int main(){

    int n;
    cin>>n;

     vector<vector<int>> arr(n,vector<int>(n));

    for(int i=0;i<n;i++){
        cout<<"Row "<<i<<endl;
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    vector<vector<bool>> visited(n,vector<bool>(n,0));
    vector<string> ans;
    string path = "";

    if(arr[0][0] == 0){
        cout<<"Not Possible";
    }

    else{solveRat(0,0,arr,n,visited,path,ans);
    cout<<"Answer = "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }}
}