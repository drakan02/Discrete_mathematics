#include <bits/stdc++.h>

using namespace std;
struct edge{
    int u , v, w;
};
int n, m;
int parent[100005], sz[100005];
vector<edge> canh;

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int u, v, w; cin >> u >> v >> w;
        edge e;
        e.u = u; e.v = v; e.w = w;
        canh.push_back(e);
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
    if(a == b) return false; // Không thể gộp a và b với nhau
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    //Chọn cây khung cực tiểu rỗng
    vector<edge> mst;
    int sum = 0;
    //sort danh sách cạnh theo độ dài tăng dần
    sort(canh.begin(), canh.end(), cmp);
    for(int i = 0; i < m; i++){
        if(mst.size() == n-1) break;
        //Chọn cạnh e là cạnh nhỏ nhất
        edge e = canh[i];
        if(Union(e.u, e.v)){
            mst.push_back(e);
            sum += e.w;
        }
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
