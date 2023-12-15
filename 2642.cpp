#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    Graph(int n, vector<vector<int>> &edges)
    {
        graph.resize(n);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
    }

    void addEdge(vector<int> edge)
    {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        int n = graph.size();
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d != dist[node])
                continue;
            for (const auto &edge : graph[node])
            {
                int nextNode = edge.first;
                int edgeCost = edge.second;
                if (dist[node] + edgeCost < dist[nextNode])
                {
                    dist[nextNode] = dist[node] + edgeCost;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }

private:
    vector<vector<pair<int, int>>> graph;
};