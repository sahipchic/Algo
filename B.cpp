#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector< vector< pair<long long, long long> > > ms;
long long INF = (long long)1e15;
int main() {
    ifstream cin("pathmgep.in");
    ofstream cout("pathmgep.out");
    int n, s, f;
    cin >> n >> s >> f;
    ms.resize(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            if(i != j){
                if(a != -1){
                    ms[i].push_back(make_pair(j, a));
                }
            }
        }
    }
    long long dp[n];
    bool used[n];
    dp[s - 1] = 0;
    for(int i = 0; i < n; i++){
        if(i != s - 1)
            dp[i] = INF;
        used[i] = false;
    }
    for(int i = 0; i < n; i++){
        long long v = -1;
        for(int j = 0; j < n; j++){
            if (!used[j] && (v == -1 || dp[j] < dp[v]))
                v = j;
        }
        if(dp[v] == INF)
            break;
        used[v] = true;
        for (int j = 0; j < ms[v].size(); j++) {
            int to = ms[v][j].first;
            long long len = ms[v][j].second;
            if (dp[v] + len < dp[to]) {
                dp[to] = dp[v] + len;
            }

        }
    }
    if(dp[f - 1] != INF)
        cout << dp[f - 1];
    else cout << -1;
}
