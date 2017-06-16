#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> size;
vector<int> par;
vector<pair <int, pair <int, int> > > sanek_batya;
void make_set(int v){
    par[v] = v;
    size[v] = 1;
}
int find_set(int v){
    if(v == par[v]){
        return v;
    }
    else{
        return par[v] = find_set(par[v]);
    }
}
void unite_set(int v, int u){
    v = find_set(v);
    u = find_set(u);
    if(v != u){
        if(size[v] > size[u]){
            swap(v, u);
        }
        par[v] = u;
        size[u] += size[v];
    }
}
int main()
{
    ifstream cin("spantree2.in");
    ofstream cout("spantree2.out");
    int n, m, otv = 0;
    cin >> n >> m;
    size.resize(n);
    par.resize(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        sanek_batya.push_back(make_pair(c, make_pair(a - 1, b - 1)));
        //sanek_batya.push_back(make_pair(c, make_pair(b - 1, a - 1)));
    }
    for(int i = 0; i < n; i++){
        make_set(i);
    }
    sort(sanek_batya.begin(), sanek_batya.end());
    for(int i = 0; i < m; i++){
        int a, b, c;
        a = sanek_batya[i].second.first;
        b = sanek_batya[i].second.second;
        c = sanek_batya[i].first;
        if(find_set(a) != find_set(b)){
            unite_set(a, b);
            otv += c;
        }
    }
    cout << otv;
}