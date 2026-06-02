#include <bits/stdc++.h>
using namespace std;

int find(int u, int parent[]){
    if(parent[u] == u){
        return u;
    }
    return find(parent[u], parent);
}

void onion(int u, int v, int parent[], int rank[]){
    int u1 = find(u, parent);
    int v1 = find(v, parent);
    if(rank[u1] > rank[v1]){
        parent[v1] = u1;
    }else if(rank[v1] > rank[u1]){
        parent[u1] = v1;
    }else{
        parent[v1] = u1;
        rank[u1]++;
    }
}

int main(){
    int n, m, u, v, ans; int total = 0;
    vector<pair<int, int> >vec;
    cin >> n >> m;
    vector<int>arr[n + 1]; int parent[n + 1]; int rank[n + 1];
    for(int i = 1; i <= n; i++){
        parent[i] = i; 
        rank[i] = 0;
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        onion(u, v, parent, rank);
    }
    for(int i = 1; i <= n; i++){
        if(parent[i] == i){
            ans = parent[i];
            total++;
        }
    }
    cout << total - 1 << "\n";
    for(int i = ans - 1; i >= 1; i--){
        if(parent[i] == i){
            cout << ans << ' ' << i << "\n";
        }
    }
}