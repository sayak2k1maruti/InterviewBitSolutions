#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int Solution::solve(vector<vector<int>> &A);
};
/*
Link : https://www.interviewbit.com/problems/water-flow/
*/
void dfs(pair<int, int> node, vector<vector<int>> &A, int R, int C, map<pair<int, int>, bool> &visited)
{
    if (visited[node])
        return;
    visited[node] = true;
    int i = node.first;
    int j = node.second;
    if (j - 1 >= 0 && A[i][j - 1] >= A[i][j])
        dfs(make_pair(i, j - 1), A, R, C, visited);
    if (j + 1 < C && A[i][j + 1] >= A[i][j])
        dfs(make_pair(i, j + 1), A, R, C, visited);
    if (i - 1 >= 0 && A[i - 1][j] >= A[i][j])
        dfs(make_pair(i - 1, j), A, R, C, visited);
    if (i + 1 < R && A[i + 1][j] >= A[i][j])
        dfs(make_pair(i + 1, j), A, R, C, visited);
}
int Solution::solve(vector<vector<int>> &A)
{
    int R = A.size();
    int C = A[0].size();
    // map <pair<int,int>,vector<pair<int,int>>> adj;
    /*for(int i = 0 ; i<R;i++){
        for(int j = 0 ; j < C ; j++){
            if(j-1>=0 && A[i][j-1] <= A[i][j])
                adj[make_pair(i,j-1)].push_back(make_pair(i,j));
            if(j+1<C && A[i][j+1] <= A[i][j])
                adj[make_pair(i,j+1)].push_back(make_pair(i,j));
            if(i-1>=0 && A[i-1][j] <= A[i][j])
                adj[make_pair(i-1,j)].push_back(make_pair(i,j));
            if(i+1<R && A[i+1][j] <= A[i][j])
                adj[make_pair(i+1,j)].push_back(make_pair(i,j));
        }
    }*/
    map<pair<int, int>, bool> blueVisited;
    map<pair<int, int>, bool> redVisited;

    for (int i = 0; i < R; i++)
    {
        if (!blueVisited[make_pair(i, 0)])
            dfs(make_pair(i, 0), A, R, C, blueVisited);
    }
    for (int i = 0; i < C; i++)
    {
        if (!blueVisited[make_pair(0, i)])
            dfs(make_pair(0, i), A, R, C, blueVisited);
    }
    for (int i = 0; i < R; i++)
    {
        if (!redVisited[make_pair(i, C - 1)])
            dfs(make_pair(i, C - 1), A, R, C, redVisited);
    }
    for (int i = 0; i < C; i++)
    {
        if (!redVisited[make_pair(R - 1, i)])
            dfs(make_pair(R - 1, i), A, R, C, redVisited);
    }
    int count = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (blueVisited[make_pair(i, j)] && redVisited[make_pair(i, j)])
            {
                count++;
            }
        }
    }
    return count;
}
