#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 1;
vector< vector<int> > g;
int n;
vector<bool> used;
vector<int> ans;
map< pair<int, int> , int> ma;
map< pair<int, int> , int>::iterator it;
int timer;
vector<int> tin, fup;
/*void IS_BRIDGE(int v, int to){
    /*for(it = ma.begin(); it != ma.end(); ++it){
        if(it->second.first == v && it->second.second == to){
            ans.push_back(it->first);
        }
    }
    cout << v << " " << to;
    cout << endl;
}*/
void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
                //IS_BRIDGE(v,to);
                ans.push_back(ma[make_pair(v, g[v][i])]);
        }
    }
}
 
void find_bridges() {
    timer = 0;
 
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs(i);
}
int main()
{
    ifstream cin("bridges.in");
    ofstream cout("bridges.out");
    int m;
    cin >> n >> m;
    g.resize(n);
    tin.resize(n);
    fup.resize(n);
    used.resize(n, false);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
        ma[make_pair(a - 1, b - 1)] = i + 1;
        ma[make_pair(b - 1, a - 1)] = i + 1;
    }
    //cout << -1 << endl;
    find_bridges();
    //cout << -1 << endl;
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
