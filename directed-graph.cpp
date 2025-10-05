#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<pair<int,int>>> a;

int main() {
    cin >> n >> m;
    a.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        //do thi co huong
        a[u].push_back({v,w});
    }
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(pair y : a[i]){
            cout << y.first << "-" << y.second << " ";
        }
        cout << endl;
    }
    return 0;
}
