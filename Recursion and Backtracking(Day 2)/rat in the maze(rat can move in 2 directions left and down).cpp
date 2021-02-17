#include<bits/stdc++.h>
using namespace std;
bool isSafe(int i,int j,int n,vector<vector<int>> &maze)
{

    return (i<n && j<n && maze[i][j]==1);
}
bool ratInMazeHelper(vector<vector<int>> &maze,vector<vector<int>> &path,int i,int j)
{
    int n=maze.size();
    if(i==n-1 && j==n-1)
    {
        path[i][j]=1;
        return true;
    }
    if(isSafe(i,j,n,maze)==true)
    {
        path[i][j]=1;
        if(ratInMazeHelper(maze,path,i+1,j)==true)
            return true;
        else if(ratInMazeHelper(maze,path,i,j+1)==true)
            return true;
        path[i][j]=0;
    }
    return false;
}
bool ratInMaze(vector<vector<int>> &maze,vector<vector<int>> path)
{
    if(ratInMazeHelper(maze,path,0,0)==false)
    {
        return false;
    }
    else
    {
        for(int i=0;i<maze.size();i++)
        {
            {
                for(int j=0;j<maze.size();j++)
                    cout<<path[i][j]<<"  ";
            }
            cout<<endl;
        }
        return true;
    }

}
int main()
{
    vector<vector<int>> maze={{1, 0, 0, 0},
                              {1, 1, 0, 1},
                              {1, 1, 0, 0},
                              {0, 1, 1, 1}};
    vector<vector<int>> path={{0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0}};
    bool out=ratInMaze(maze,path);
    cout<<endl<<out;
}
