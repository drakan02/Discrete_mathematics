#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> a[1001];
bool visited[1001];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u){
    cout << u << " ";
    //danh dau u da dc tham
    visited[u] = true;
    for(int v : a[u]){
        //neu v chua duoc tham
        if(!visited[v]){
            DFS(v);
        }
    }
}

int main() {
    inp();
    DFS(1);
    return 0;
}
