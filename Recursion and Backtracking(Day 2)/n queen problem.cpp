#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<bool>> &board,int row,int col,int n)
{
    int r,c;
    for(r=0;r<col;r++)
    {
        if(board[row][r])
            return false;
    }
    for(r=row,c=col;r>=0 && c>=0;r--,c--)
    {
        if(board[r][c])
            return false;
    }
    for(r=row,c=col;c>=0 && r<n;r++,c--)
    {
        if(board[r][c])
            return false;
    }
    return true;
}
bool generateNQueenBoardHelper(vector<vector<bool>> &board,int col,int n)
{
    if(col>=n)
        return true;
    for(int row=0;row<n;row++)
    {
        if(isSafe(board,row,col,n))
        {
            board[row][col]=true;
            if(generateNQueenBoardHelper(board,col+1,n))
                return true;
            board[row][col]=false;
        }
    }
    return false;
}
bool generateNQueenBoard(int n)
{
    vector<vector<bool>> board(n,vector<bool>(n,false));
    if(!generateNQueenBoardHelper(board,0,n))
        return false;
    else
    {
        for(vector<bool> row:board)
        {
            for(int cell:row)
            {
                cout<<(cell==true ? 1:0)<<"\t";
            }
            cout<<"\n";
        }
        return true;
    }
}
int main()
{
    generateNQueenBoard(8);
}
