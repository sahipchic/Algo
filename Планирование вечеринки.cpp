#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
vector < vector<int> > g, gt;
vector<bool> used;
vector<int> order, comp;
map<string, int> m1;
map<int, string> m2;
map<string, int>::iterator it1;
map<string, int>::iterator it2;
int conv(int n){
    if(n >= 0)
        return 2 * n - 2;
    else return 2 * n * (-1) - 1;
}
 
void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs1 (to);
    }
    order.push_back(v);
}
 
void dfs2 (int v, int cl) {
    comp[v] = cl;
    for (size_t i=0; i<gt[v].size(); ++i) {
        int to = gt[v][i];
        if (comp[to] == -1)
            dfs2 (to, cl);
    }
}
string toName(string s){
    return "+" + s;
}
string toNotName(string s){
    return "-" + s;
}
vector<string> otvet;
int main() {
    //... ?????? n, ????? g, ?????????? ????? gt ...
    int m;
    cin >> n >> m;
    string names[n];
    string name;
    for(int i = 0; i < n; i++){
        cin >> name;
        names[i] = name;
        string nename = "-" + name;
        name = "+" + name;
        it1 = m1.find(name);
        it2 = m1.find(nename);
        if(it1 == m1.end() && it2 == m1.end()){
        m1[name] = conv(i + 1);
        m1[nename] = conv(-1 * (i + 1));
        }
    }
    g.resize(2 * n);
    gt.resize(2 * n);
 
    for(int i = 0; i < m; i++){
        char c1, c2, c;
        cin >> c1;
        string s1, s2, s;
        cin >> s1;
        cin >> s;
        cin >> c2;
        cin >> s2;
        int a, b;
        if(c1 == '-')
            a = m1[toNotName(s1)];
        else a = m1[toName(s1)];
        if(c2 == '-')
            b = m1[toNotName(s2)];
        else b = m1[toName(s2)];
       // cout << a << " " << (a ^ 1) << " " << " " << b << " " << (b ^ 1) << endl;
 
        g[a].push_back(b);
        gt[b].push_back(a);
 
        g[b ^ 1].push_back(a ^ 1);
        gt[a ^ 1].push_back(b ^ 1);
    }
    /*for(int i = 0; i < 2 * n; i++){
        for(int j = 0; j < g[i].size(); j++){
            cout << i << "=>" << g[i][j] << " ";
        }
        //cout << endl;
    }*/
    used.assign (3 * n, false);
    for (int i=0; i<2*n; ++i)
        if (!used[i])
            dfs1 (i);
 
    comp.assign (3 * n, -1);
    for (int i=0, j=0; i<2*n; ++i) {
        int v = order[2*n-i-1];
        if (comp[v] == -1)
            dfs2 (v, j++);
    }
 
    for (int i=0; i<2*n; i += 2)
        if (comp[i] == comp[i^1]) {
            puts ("-1");
            return 0;
        }
    int c = 0;
    vector<int> answer;
    answer.assign(n, 0);
    for (int i=0; i<2*n; i += 2) {
           // cout << comp[i] << " " << comp[i^1] << endl;
        answer[i / 2] = comp[i] > comp[i^1];
        if(comp[i] > comp[i^1]) c++;
        //int ans = comp[i] > comp[i^1] ? i : i^1;
        //cout << m2[ans] << " ";
        //cout << ans << " ";
    }
    //cout << endl;
    cout << c << endl;
    for(int i = 0; i < n; i++){
        if(answer[i]) cout << names[i] << endl;
    }
        //cout << answer[i] << " ";
}
