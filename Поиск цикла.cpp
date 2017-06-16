#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
vector < vector<int> > g;
vector<int> isCycle;
vector<int> p;
int begin_cycle, end_cycle;
 
bool dfs(int v) {
    isCycle[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (isCycle[to] == 0) {
            p[to] = v;
            if (dfs(to))
                return true;
        }
        else
            if (isCycle[to] == 1) {
            end_cycle = v;
            begin_cycle = to;
            return true;
        }
    }
    isCycle[v] = 2;
    return false;
}
 
int main() {
    ifstream cin("cycle.in");
    ofstream cout("cycle.out");
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    p.assign (n, -1);
    isCycle.assign (n, 0);
    begin_cycle = -1;
    for (int i = 0; i < n; i++)
        if (dfs (i))
            break;
 
    if (begin_cycle == -1)
        cout << "NO";
    else {
        cout << "YES";
        cout << endl;
        vector<int> cycle;
        cycle.push_back (begin_cycle);
        for (int v = end_cycle; v != begin_cycle; v = p[v]){
            cycle.push_back (v);
        }
        cycle.push_back(begin_cycle);
        reverse (cycle.begin(), cycle.end());
        for (int i = 0; i < cycle.size() - 1; i++)
            cout << cycle[i] + 1 << " ";
    }
}
