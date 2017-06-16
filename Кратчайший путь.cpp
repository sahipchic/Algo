#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
vector< vector < pair <int, int > > > g;
bool used[(int)1e5 + 1];
vector<int> ans;
set< pair<int, int> > huynya;
 
void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        if (!used[to])
            dfs(to);
    }
    ans.push_back (v);
}
 
void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ans.begin(), ans.end());
}
//int w[(int)20000][(int)20000];
 
int main()
{
    ifstream cin("shortpath.in");
    ofstream cout("shortpath.out");
    int m, s, t;
    cin >> n >> m >> s >> t;
 
    g.resize(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b;
        cin >> c;
        g[a - 1].push_back(make_pair(b - 1, c));
        huynya.insert(make_pair(a - 1, b - 1));
    }
 
    vector<int> d;
    d.resize(n, (int)1e8 + 1);
    //d.assign (n, INT_MAX);
    d[s - 1] = 0;
    topological_sort();
    //for(int i = 0; i < ans.size(); i++)
      //  cout << ans[i] << " ";
    //cout << endl;
    //cout << w[0][1] << endl;
    bool b = false;
    for(int i = 0; i < n; i++){
        if(ans[i] == s - 1){
            b = true;
            d[ans[i]] = 0;
        }
        if(!b) continue;
        for(int j = 0; j < g[ans[i]].size(); j++){
                int q1, q2;
                q1 = g[ans[i]][j].first;
                q2 = g[ans[i]][j].second;
            d[q1] = min(d[q1], d[ans[i]] + q2);
        }
    }
    /*for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            //cout << huynya.count(make_pair(ans[i], ans[j])) << " ";
            if(huynya.count(make_pair(ans[i], ans[j])) > 0){
                d[j] = min(d[j], d[ans[i]] + w[ans[i]][j]);
            }
        }
    }*/
    //for(int i = 0; i < n; i++)
      //  cout << d[i] << " ";
    //cout << endl;
    if(d[t - 1] != (int)1e8 + 1)
        cout << d[t - 1];
    else cout << "Unreachable";
}
