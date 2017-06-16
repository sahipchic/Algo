#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct cycle{
    double start, finish, price;
};
map<double, string> ma;
map<double, string>::iterator it;
vector<cycle> ms;
vector<double> path;
vector<double> d, p;
vector< vector<double> > g;
double INF = 1e40; 
vector<bool> used;
void dfs(double v){
    ma[v] = "-";
    for(double i = 0; i < g[v].size(); i++){
        if(!used[g[v][i]]){
            used[g[v][i]] = true;
            ma[g[v][i]] = "-";
            dfs(g[v][i]);
        }
    }
}
int main() {
    ifstream cin("path.in");
    ofstream cout("path.out");
    double n, s, f, m, v;
    cin >> n >> m >> v;
    g.resize(n);
    used.assign(n, false);
    for(double i = 0; i < m; i++){        
            double a, b, c;
            cin >> a >> b >> c;                       
            g[a - 1].push_back(b - 1);
            ms.push_back({a - 1, b - 1, c});                                         
    }
    s = 0;
    d.resize(n, INF);
    d[v - 1] = 0;
    p.assign(n, -1);
    for (double i = 0; i < n; i++) {
        s = -1;
        for (double j = 0; j < ms.size(); j++)
        if(d[ms[j].start] < INF)
            if (d[ms[j].finish] > d[ms[j].start] + ms[j].price) {
                d[ms[j].finish] = max((double)-INF, d[ms[j].start] + ms[j].price);
                p[ms[j].finish] = ms[j].start;
                s = ms[j].finish;
            }
    }
   
    if (s == -1){
        for(double i = 0; i < n; i++){
            if(d[i] != INF){
                cout << (long long)d[i] << endl;
            }
            else cout << "*" << endl;
        }
    }
        //cout << "NO";
    else {
        f = s;
        for (double i = 0; i < n; ++i)
            f = p[f];
   
          
        for (double cur = f; ; cur = p[cur]) {
            path.push_back(cur);
            if (cur == f && path.size() > 1)  break;
        }
        reverse (path.begin(), path.end());
        //sort(path.begin(), path.end());
        for(double i = 0; i < path.size() - 1; i++){
            dfs(path[i]);
        }
        //cout << path.size() << endl;
        /*for (double i = 0; i < path.size() - 1; i++)
        {
            cout << path[i] + 1 << " ";
            ma[path[i]] = "-";
        }    
            cout << endl;
        */
        for(double i = 0; i < n; i++){
            if(d[i] != INF){
                if(ma[i] != "-")
                cout << (long long)d[i] << endl;
                else cout << "-" << endl;
            }
            else cout << "*" << endl;
        }
    }
      
}