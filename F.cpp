#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct cycle{
    int start, finish, price;
};
vector<cycle> ms;
vector<long long> path;
vector<long long> d, p;
int INF = (int)1e9; 
int main() {
    ifstream cin("negcycle.in");
    ofstream cout("negcycle.out");
    long long n, s, f, m = 0;
    cin >> n;
  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;         
            if(a != INF){
                ms.push_back({i, j, a});
            }            
        }
          
    }
    s = 0;
    d.resize(n);
    p.assign(n, -1);
    for (int i = 0; i < n; i++) {
        s = -1;
        for (int j = 0; j < ms.size(); j++)
            if (d[ms[j].finish] > d[ms[j].start] + ms[j].price) {
                d[ms[j].finish] = max(-LONG_LONG_MAX, d[ms[j].start] + ms[j].price);
                p[ms[j].finish] = ms[j].start;
                s = ms[j].finish;
            }
    }
   
    if (s == -1)
        cout << "NO";
    else {
        f = s;
        for (int i = 0; i < n; ++i)
            f = p[f];
   
          
        for (int cur = f; ; cur = p[cur]) {
            path.push_back(cur);
            if (cur == f && path.size() > 1)  break;
        }
        reverse (path.begin(), path.end());
   
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (int i = 0; i < path.size(); i++)
            cout << path[i] + 1 << " ";
    }
      
}