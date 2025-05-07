#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e, u, v, w;
  cout << "Enter nodes and edges: " << endl;
  cin >> n >> e;
  vector<pair<int, int>> graph[n];

  cout << "Enter u,v,weight: " << endl;
  for (int i = 0; i < e; i++)
  {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  vector<int> h(n);
  cout << "Enter heuristic value for each node: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  int start, goal;
  cout << "Enter start and goal node: " << endl;
  cin >> start >> goal;
  vector<int> f(n, INT_MAX);
  vector<int> g(n, INT_MAX);
  vector<int> parent(n, -1);
  vector<bool> visited(n, false);

  g[start] = 0;
  f[start] = g[start] + h[start];

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({f[start], start});

  while (!pq.empty())
  {
    int node = pq.top().second;
    pq.pop();

    if (visited[node])
      continue;
    visited[node] = true;

    if (node == goal)
      break;

    for (auto i : graph[node])
    {
      int child = i.first;
      int weight = i.second;

      if (!visited[child] && g[node] + weight + h[child] < f[child])
      {
        g[child] = g[node] + weight;
        f[child] = g[child] + h[child];
        pq.push({f[child], child});
        parent[child] = node;
      }
    }
  }

  if (g[goal] == INT_MAX)
  {
    cout << "No path found" << endl;
    return 0;
  }
  // vector<int> path;
  // int current = goal;
  // while (current != -1)
  // {
  //   path.push_back(current);
  //   current = parent[current];
  // }
  // reverse(path.begin(), path.end());

  vector<int> path;
  for (int at = goal; at != -1; at = parent[at])
  {
    path.push_back(at);
  }
  reverse(path.begin(), path.end());

  cout << "Path is [  ";
  for (auto n : path)
  {
    cout << n << " -> ";
  }
  cout << " ]" << endl;
  cout << "Total cost: " << g[goal] << endl;
  return 0;
}