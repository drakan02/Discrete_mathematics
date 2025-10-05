#include <bits/stdc++.h>

using namespace std;
int n, m;
multimap<int,int> mp[100005];
bool used[100005];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        mp[u].insert({w,v});
        mp[v].insert({w,u});
    }
    memset(used, false, sizeof(used));
}

void prim(int u){
    // Tạo cây khung rỗng
    vector<pair<int,pair<int,int>>> mst;
    int sum = 0;
    used[u] = true; // đưa đỉnh u vào cây khung
    while(mst.size() < n-1){
        int min = INT_MAX;
        int x, y;
        for(int i = 1; i <= n; i++){
            if(used[i]){
                auto it = mp[i].begin(); 
                while(it != mp[i].end()){
                    if(!used[(*it).second]){
                        if((*it).first < min){
                            min = (*it).first;
                            x = i; y = (*it).second;
                        }
                        break;
                    }
                    mp[i].erase(mp[i].begin());
                    it = mp[i].begin();
                }
            }
        }
        mst.push_back({min,{x,y}});
        sum +=  min;
        used[y] = true;
    }
    cout << sum;
}

int main() {
    inp();
    prim(1);
    
    return 0;
}
