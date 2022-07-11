#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int solve(int A, vector<vector<int>> &B);
};

unordered_map<int, vector<int>> createAdjacencyList(vector<vector<int>> &B)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < B.size(); i++)
    {
        int a = B[i][0];
        int b = B[i][1];
        adj[a].push_back(b);
    }
    return adj;
}
bool bfs(int A, unordered_map<int, vector<int>> &adj)
{
    unordered_map<int, bool> visited;
    int front = 1;
    queue<int> q;
    q.push(front);
    visited[front] = true;
    while (!q.empty())
    {
        int curr = q.front();
        if (curr == A)
            return true;
        q.pop();
        for (auto n : adj[curr])
        {
            if (!visited[n])
            {
                q.push(n);
                visited[n] = true;
            }
        }
    }
    return false;
}
int Solution::solve(int A, vector<vector<int>> &B)
{
    unordered_map<int, vector<int>> adj = createAdjacencyList(B);
    return bfs(A, adj);
}