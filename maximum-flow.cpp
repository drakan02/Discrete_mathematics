#include <bits/stdc++.h>

using namespace std;

int n, u, v, w, ans, trc[5003], f[5003][5003];
vector<int> a[5003];
queue<int> qu;

bool BFS(){
    for (int i = 1; i <= n; i++) trc[i] = 0;
    qu.push(1);
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        if(trc[n]) continue;
        for (int y : a[x]){
            if(f[x][y] && !trc[y]){
                trc[y] = x;
                qu.push(y);
            }
        }
    }
    return trc[n];
}

int main()
{
    cin >> n;
    while(cin >> u >> v >> w){
        a[u].push_back(v);
        a[v].push_back(u);
        f[u][v]=w;
    }
    while(BFS()){
        int t = n;
        int mini = INT_MAX;
        while(t!=1){
            int v = trc[t];
            mini = min(mini, f[v][t]);
            t = v;
        }
        t = n;
        while(t!=1){
            int v = trc[t];
            f[t][v] += mini;
            f[v][t] -= mini;
            t = v;
        }
        ans += mini;
    }
    cout << ans;
    return 0;
}
