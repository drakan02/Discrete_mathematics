#include <bits/stdc++.h>

using namespace std;
int n, m, s, t;
vector<pair<int,int>> adj[100005];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v , w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    cin >> s >> t;
}

void dijkstra(int s){
    //Mảng lưu khoảng cách đường đi
    vector<long long> d(n+1, LLONG_MAX);
    d[s] = 0;
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0,s});
    while(!Q.empty()){
        //Chọn ra đỉnh có khoảng cách từ s nhỏ nhất
        int u = Q.top().second;
        int kc = Q.top().first; Q.pop();
        //Loại bỏ đỉnh đã xét
        if(kc > d[u]) continue;
        //Cập nhật kc từ s 
        for(auto it : adj[u]){
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    cout << d[t];
}

int main() {
    inp();
    dijkstra(s);
    return 0;
}
