#include <iostream>
#include <vector>

using std::vector;

void explore(vector<vector<int>> adj, int node, vector<bool> &visited)
{
  visited[node] = true;
  for (auto const &x : adj[node])
  {
    if (!visited[x])
    {
      explore(adj, x, visited);
    }
  }
}

int reach(vector<vector<int>> &adj, int x, int y)
{
  vector<bool> visited(adj.size(), false);
  explore(adj, x, visited);
  return visited[y] ? 1 : 0;
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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
