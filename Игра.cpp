#include <bits/stdc++.h>
using namespace std;
#define MAXN 1e6
int n; // ????? ??????
int s;
vector<int> g[(int)1e5]; // ????
vector<int> h[(int)1e5]; // ????
bool used[(int)1e5];
vector<int> ans;
bool win_loose[(int)1e5];
bool used1[(int)1e5];
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
    //reverse (ans.begin(), ans.end());
}
bool b = false;
void search(int v){
    used1[v] = true;
    if(!win_loose[v]){
        for(int i = 0; i < h[v].size(); i++){
            win_loose[h[v][i]] = true;
        }
    }
 
}
 
int main(){
    ifstream cin("game.in");
    ofstream cout("game.out");
    int m;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        h[b - 1].push_back(a - 1);
    }
 
    topological_sort();
    //for(int i = 0; i < ans.size(); i++)
      //  cout << ans[i] + 1 << " ";
 
    //cout << endl;
    for(int i = 0; i < n; i++)
        win_loose[i] = false;
    //win_loose[ans[0]] = false;
    for(int i = 0; i < ans.size(); i++){
        search(ans[i]);
        //break;
    }
    if(win_loose[s - 1]) cout << "First player wins";
    else cout << "Second player wins";
}
