#include <iostream>
#include <vector>

using std::vector;

void explore(vector<vector<int>> adj, vector<int> &visited, int node)
{
  visited[node] = true;
  for (const int &x : adj[node])
  {
    if (!visited[x])
    {
      explore(adj, visited, x);
    }
  }
}

int number_of_components(vector<vector<int>> &adj)
{
  int res = 0;
  vector<int> visited(adj.size(),false);
  for (int i = 0; i < adj.size(); i++)
  {
    if(!visited[i]){
      res++;
      explore(adj,visited,i);
    }
  }
  return res;
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
  std::cout << number_of_components(adj);
}
