#include <bits/stdc++.h>

using namespace std;
int n, m;
multimap<int,pair<int,int>> mp;
int parent[100005], sz[100005];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int u, v, w; cin >> u >> v >> w;
        mp.insert({w,{u,v}});
    }
}

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

bool Union(int a ,int b){
    a = find(a); b = find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void kruskal(){
    multimap<int,pair<int,int>> mst;
    int sum = 0;
    auto it = mp.begin();
    while(it != mp.end()){
        if(mst.size() == n-1) break;
        if(Union((*it).second.first, (*it).second.second)){
            mst.insert(*it);
            sum += (*it).first;
        }
        it++;
    }
    if(mst.size() < n-1)
        cout << "Do thi khong lien thong";
    else
        cout << sum;
}

int main() {
    inp();
    make_set();
    kruskal();
    return 0;
}
