#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector< vector< pair<long long, long long> > > ms;
long long INF = (long long)1e15; 
int main() {
    ifstream cin("pathsg.in");
    ofstream cout("pathsg.out");
    int n, s, f, m;
    cin >> n >> m;
    //long long ms[n][n];
    long long dp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        dp[a - 1][b - 1] = c;
    }
     
    bool used[n];
     
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
     
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] != INF)
                cout << dp[i][j];
            else cout << -1;
            cout << " ";
        }
        cout << endl;
    }
}