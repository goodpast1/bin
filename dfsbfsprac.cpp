#include <bits/stdc++.h>
using namespace std;
void bfs_traversal(int start, vector<vector<int>> adj)
{
  int n = adj.size();
  int visited[n + 1] = {0};
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  vector<int> bfs;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for (auto neighbour : adj[node])
    {
      if (!visited[neighbour])
      {
        visited[neighbour] = 1;
        q.push(neighbour);
      }
    }
  }
  cout << "BFS traversal: ";
  for (auto it : bfs)
  {
    cout << it << " ";
  }
}

void dfs_traversal(int start, vector<vector<int>> adj)
{
  int n = adj.size();
  int visited[n + 1] = {0};
  vector<int> dfs;
  stack<int> st;
  st.push(start);
  visited[start] = 1;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    dfs.push_back(node);
    for (auto neighbour : adj[node])
    {
      if (!visited[neighbour])
      {
        visited[neighbour] = 1;
        st.push(neighbour);
      }
    }
  }
  cout << "DFS traversal: ";
  for (auto it : dfs)
  {
    cout << it << " ";
  }
}
int main()
{
  vector<vector<int>> adj;
  int n, m;
  cout << "Enter number of nodes: ";
  cin >> n;
  cout << "Enter number of edges: ";
  cin >> m;
  adj.clear();
  adj.resize(n + 1);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cout << "Enter starting vertex: ";
    cin >> u;
    cout << "Enter end vertex: ";
    cin >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (auto &n : adj)
  {
    sort(n.begin(), n.end());
  }
  int start;
  cout << "Enter starting node for BFS Traversal: ";
  cin >> start;
  bfs_traversal(start, adj);
  cout << "Enter starting node for DFS Traversal: ";
  cin >> start;
  dfs_traversal(start, adj);

  return 0;
}