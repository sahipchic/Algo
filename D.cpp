#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector< vector< pair<long long, long long> > > ms;
set < pair<long long, long long> > q;
long long INF = (long long)1e18;
int main() {
    ifstream cin("pathbgep.in");
    ofstream cout("pathbgep.out");
    long long n, s, f, m;
    cin >> n >> m;
    vector< vector< pair<long long, long long> > > g(n);
    long long dp[n][n];
    vector<long long> d (n, INF),  p (n);
    for(int i = 0; i < n; i++){
        d[i] = INF;
    }
    for(int i = 0; i < m; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back(make_pair(b - 1, c));
        g[b - 1].push_back(make_pair(a - 1, c));
    }
    s = 0;
    d[0] = 0;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        int v = q.begin() -> second;
        q.erase(q.begin());
        for (int j = 0; j < g[v].size(); j++) {
            long long to = g[v][j].first;
            long long len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                q.insert(make_pair (d[to], to));
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
}