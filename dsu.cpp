#include <bits/stdc++.h>

using namespace std;
int parent[100005], size_set[100005], n;

//Đặt nó là cha của chính nó
void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        size_set[i] = 1;
    }
}

//Tìm cha của đỉnh v
int find_parent(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_parent(parent[v]);
}

//Nối 2 tập hợp
void union_set(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a != b){
        if(size_set[a] < size_set[b]) swap(a, b);
        parent[b] = a;
        size_set[a] += size_set[b];
    }
}

int main() {

    return 0;
}
