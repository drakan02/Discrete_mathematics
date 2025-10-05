#include <bits/stdc++.h>

using namespace std;
int n, m, s, t;
int d[100005], p[100005];
vector<pair<int,int>> luu[100005];
multimap<int,int> mp;

int main() {
    cin >> n >> m;
    for (int k = 1; k <= m; k++) {
        int u, v, w;
        cin >> u >> v >> w;
        luu[u].push_back({w,v});
    }
    cin >> s >> t;
    fill(d, d + n + 1, INT_MAX);
    fill(p, p + n + 1, -1);
    d[s] = 0;
    mp.insert({d[s],s});
    while(!mp.empty()){
        int u = (*mp.begin()).second;
        int dist_u = (*mp.begin()).first;
        mp.erase(mp.begin());
        if(dist_u > d[u]) continue;
        for(auto &i : luu[u]){
            int v = i.second;
            int w = i.first;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                p[v] = u;
                mp.insert({d[v], v});
            }
        }
    }
    if (d[t] != INT_MAX)
        cout << d[t] << endl;
    else
        cout << -1 << endl;
    return 0;
}
