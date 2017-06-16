#include <bits/stdc++.h>
using namespace std;
#define MAXN 1e6
int n; // ????? ??????
int s;
vector<int> g[(int)1e5]; // ????
vector<int> h[(int)1e5]; // ????
bool used[(int)1e5];
vector<int> ans;
set< pair<int, int> > huynya;
 
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
    reverse (ans.begin(), ans.end());
}
bool b = false;
/*void search(int v){
    used1[v] = true;
    if(!win_loose[v]){
        for(int i = 0; i < h[v].size(); i++){
            win_loose[h[v][i]] = true;
            if(h[v][i] == s){
                cout << "First player wins";
                b = true;
                break;
            }
            int to = h[v][i];
            if (!used1[to]){
                search(to);
            }
        }
    }
    else{
        for(int i = 0; i < h[v].size(); i++){
            win_loose[h[v][i]] = false;
            if(h[v][i] == s){
                cout << "Second player wins";
                b = true;
                break;
            }
            int to = h[v][i];
            if (!used1[to]){
                search(to);
            }
            //dfs (to);
        }
    }
}
*/
int main(){
    ifstream cin("hamiltonian.in");
    ofstream cout("hamiltonian.out");
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        huynya.insert(make_pair(a - 1, b - 1));
        g[a - 1].push_back(b - 1);
        //h[b - 1].push_back(a - 1);
    }
    bool x = true;
    topological_sort();
    for(int i = 0; i < ans.size() - 1; i++){
        if(huynya.count(make_pair(ans[i], ans[i + 1])) == 0){
             x = false;
            break;
        }
    }
    if(x){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    //for(int i = 0; i < ans.size(); i++)
      //  cout << ans[i] + 1 << " ";
 
    //cout << endl;
    /*for(int i = 0; i < n; i++)
        win_loose[i] = false;
    win_loose[ans[0]] = false;
    for(int i = 0; i < ans.size(); i++){
        search(ans[i]);
        break;
    }*/
    //if(win_loose[s - 1]) cout << "First player wins";
    //else cout << "Second player wins";
 
}
