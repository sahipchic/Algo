#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector < vector<int> > g; // ????
int n; // ????? ??????
int s = 0; // ????????? ???????
int main()
{
    ifstream cin("pathbge1.in");
    ofstream cout("pathbge1.out");
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    queue<int> q;
    q.push (s);
    vector<bool> used (n, false);
    vector<int> d (n);
    used[s] = true;
    d[s] = 0;
    //d[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            if (!used[to])
            {
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
 
            }
        }
    }
 
    for(int i = 0; i < n; i++){
        cout << d[i] << " ";
    }
}
