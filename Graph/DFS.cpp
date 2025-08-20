#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node])
        if (!visited[neighbor])
            DFSUtil(neighbor, adj, visited);
}

void DFS(int start, vector<vector<int>> &adj, int n) {
    vector<bool> visited(n, false);
    DFSUtil(start, adj, visited);
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    cout << "DFS starting from node 0: ";
    DFS(0, adj, n);
    return 0;
}
