#include <bits/stdc++.h>
using namespace std;
#define MAXN 1e6
int n; // ????? ??????
vector<int> g[(int)1e5]; // ????
bool used[(int)1e5];
vector<int> ans;
vector<char> cl;
vector<int> p;
int cycle_st, cycle_end;
 
bool isCycle (int v) {
    cl[v] = 1;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (cl[to] == 0) {
            p[to] = v;
            if (isCycle (to))  return true;
        }
        else if (cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}
void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
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
int main(){
    ifstream cin("topsort.in");
    ofstream cout("topsort.out");
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    p.assign (n, -1);
    cl.assign (n, 0);
    cycle_st = -1;
    for (int i=0; i<n; ++i)
        if (isCycle(i))
            break;
    if (cycle_st == -1){
    topological_sort();
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
    }
    else cout << -1;
}
