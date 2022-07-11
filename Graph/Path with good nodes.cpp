#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int Solution::solve(vector<int> &A, vector<vector<int>> &B, int C);
};
/*
Link : https://www.interviewbit.com/problems/path-with-good-nodes/
*/
void dfs(int node, int &ans, unordered_map<int, vector<int>> &adj, vector<int> &A, unordered_map<int, bool> &visited, int C)
{
    visited[node] = true;
    if (A[node - 1] == 1)
    {
        C--;
    }
    if (C < 0)
        return;
    for (auto n : adj[node])
    {
        if (!visited[n])
        {
            visited[n] = true;
            dfs(n, ans, adj, A, visited, C);
        }
    }
    if (adj[node].size() == 1 && C >= 0)
        ans++;
}

int Solution::solve(vector<int> &A, vector<vector<int>> &B, int C)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < B.size(); i++)
    {
        int a = B[i][0];
        int b = B[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    unordered_map<int, bool> visited;
    int ans = 0;
    dfs(1, ans, adj, A, visited, C);
    return ans;
}
