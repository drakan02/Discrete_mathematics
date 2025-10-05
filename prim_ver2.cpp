#include <bits/stdc++.h>

using namespace std;
struct canh{
    int u, v, w;
};
int n, m;
vector<pair<int,int>> adj[100005];
bool used[100005];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    memset(used, false, sizeof(used));
}

void prim(int u){
    // Tạo cây khung rỗng
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    int ans = 0;
    Q.push({0,u});
    while(!Q.empty()){
        int dinh = Q.top().second;
        int trongSo = Q.top().first;
        Q.pop();
        if(used[dinh]) continue;
        ans += trongSo;
        used[dinh] = true;
        for(auto it : adj[dinh]){
            int v = it.first, w = it.second;
            if(!used[v]){
                Q.push({w,v});
            }
        }
    }
    cout << ans;
}

int main() {
    inp();
    prim(1);
    return 0;
}
