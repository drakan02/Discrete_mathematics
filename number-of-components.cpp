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
    visited[u] = true;
    for(int x : a[u]){
        if(!visited[x]) DFS(x);
    }
}

void connected(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        if(!visited[i]){
            DFS(i);
            ans++;
        }
    }
    cout << "Số thành phân liên thông của đồ thị là: " << ans;
    if(ans == 1) cout << "\n--> Đồ thị liên thông";
    else cout << "\n--> Đồ thị không liên thông";
}

int main() {
    inp();
    connected();
    return 0;
}
