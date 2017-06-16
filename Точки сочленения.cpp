#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = (int)1e5 + 1;
vector< vector<int> > g;
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
map<int, int> ma;
int n, c = 0;
vector<int> otv;
void iscut(int v){
    if(ma[v] < 1){
            ma[v]++;
    otv.push_back(v + 1);
    c++;
    }
}
void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1)
                iscut(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        iscut(v);
}
 
int main() {
    ifstream cin("points.in");
    ofstream cout("points.out");
    int m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    dfs(0);
    cout << c << endl;
    sort(otv.begin(), otv.end());
    for(int i = 0; i < otv.size(); i++){
        cout << otv[i] << " ";
    }
}
