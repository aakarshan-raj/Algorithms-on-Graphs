#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void explore(bool &cycle, int vertex, vector<vector<int>> &adj, vector<int> &visited);

void dfs(bool &cycle, vector<vector<int>> &adj, vector<int> &visited);

bool acyclic(vector<vector<int>> &adj)
{
    // write your code here
    vector<int> visited(adj.size(), 0);
    bool cycle = false;

    dfs(cycle, adj, visited);
    return cycle;
}

void dfs(bool &cycle, vector<vector<int>> &adj, vector<int> &visited)
{
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            explore(cycle, i, adj, visited);
        }
    }
}

void explore(bool &cycle, int vertex, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[vertex] = 1;
    for (int &w : adj[vertex])
    {
        if (visited[w] == 1)
        {
            cycle = 1;
        }
        else
        {
            explore(cycle, w, adj, visited);
        }
    }
    visited[vertex] = 2;
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());

    for (size_t i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }

    std::cout << acyclic(adj);
}
