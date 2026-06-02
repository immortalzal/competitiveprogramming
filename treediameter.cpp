#include <bits/stdc++.h>
using namespace std;

int ans;

int bfs(int source, vector<int>adj[], int n){
    int u, v, end; end = source;
    vector<int> dist(n + 1, -1);
    queue<int>q; q.push(source); dist[source] = 0;
    while(q.size() > 0){
        u = q.front(); q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            v = adj[u][i];
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
                if(dist[v] > ans){
                    ans = max(ans, dist[v]);
                    end = v;
                }
            }
        }
    }
    return end;
}

int main(){
    int n, u, v;
    cin >> n; ans = 0;
    vector<int>adj[n + 1];
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int first = bfs(1, adj, n);
    int second = bfs(first, adj, n);
    cout << ans;
}