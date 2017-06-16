#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector < vector<int> > g, h;
vector<bool> used;
vector<int> topsort, strong;
vector<int> otv;
int answer = 0, q = 0;
void dfs1 (int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
            dfs1(g[v][i]);
    topsort.push_back(v);
}
 
void dfs2 (int v, int k) {
    used[v] = true;
    otv[v] = k;
    strong.push_back(v);
    for (int i = 0; i < h[v].size(); i++)
        if (!used[h[v][i]])
            dfs2(h[v][i], k);
}
int main()
{
    ifstream cin("fire.in");
    ofstream cout("fire.out");
    int n, m;
    cin >> n >> m;
    g.resize(n);
    otv.resize(n);
    h.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        h[b - 1].push_back(a - 1);
    }
    used.resize(n);
    for(int i = 0; i < n; i++)
        used[i] = false;
 
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1 (i);
 
    for(int i = 0; i < n; i++)
        used[i] = false;
 
    int k = 1;
    reverse(topsort.begin(), topsort.end());
    for (int i = 0; i < n; i++) {
        int v = topsort[i];
        if (!used[v]){
            dfs2(v, k);
            /*for(int j = 0; j < strong.size(); j++){
                otv.push_back(k);
            }*/
            k++;
            //strong.clear();
        }
    }
    /*cout << k - 1 << endl;
    for(int i = 0; i < n; i++){
        cout << otv[i] << " ";
    }*/
    k--;
    int r = 0;
    vector< vector <bool> > b(k, vector <bool> (k, false));
    for(int i = 0; i < k; i++)
        b[i][i] = true;
    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            if(!(b[otv[i] - 1][otv[g[i][j]] - 1])){
                r++;
                b[otv[i] - 1][otv[g[i][j]] - 1] = true;
            }
        }
    }
 
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(b[i][j] == true){
                q++;
            }
            if(q == 2)
                break;
            else continue;
        }
        if(q == 1) answer++;
        q = 0;
    }
    cout << answer;
}
