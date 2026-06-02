#include <bits/stdc++.h>
using namespace std;
 
int dfs(int curr, int dest, vector<int>& val, vector<int>adj[]){
    int tot = 0;
    if(curr == dest){
        return 1;
    }
    if(val[curr] != -1){
        return val[curr];
    }
    for(int i = 0; i < adj[curr].size(); i++){
        tot += dfs(adj[curr][i], dest, val, adj);
        tot %= 1000000007;
    }
    return val[curr] = tot;
}
 
int main(){
    int n, m, u, v;
    cin >> n >> m;
    vector<int>adj[n + 1];
    vector<int>val(n + 1, -1);
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << dfs(1, n, val, adj);
}