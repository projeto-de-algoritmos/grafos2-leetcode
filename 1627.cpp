#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries)
    {
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }

        for (int i = threshold + 1; i <= n; ++i)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                parent[find(parent, j)] = find(parent, i);
            }
        }

        vector<bool> result;
        for (const auto &query : queries)
        {
            result.push_back(find(parent, query[0]) == find(parent, query[1]));
        }

        return result;
    }

private:
    int find(vector<int> &parent, int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};