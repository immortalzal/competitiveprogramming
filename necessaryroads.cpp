#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > vec;
int tim;

void dfs(int n, int parent, vector<int> adj[], int disc[], int low[], vector<int>& visited){
    low[n] = disc[n] = ++tim; visited[n] = 1; int next;
    for(int i = 0; i < adj[n].size(); i++){
        next = adj[n][i];
        if(visited[next] == 0){
            visited[next] = 1;
            dfs(next, n, adj, disc, low, visited);
            low[n] = min(low[n], low[next]);
            if(low[next] > disc[n]){
                vec.push_back(make_pair(n, next));
            }
        }else if(parent != next){
            low[n] = min(low[n], disc[next]);
        }
    }
}

int main(){
    int n, m, a, b; tim = 0;
    cin >> n >> m;
    vector<int>adj[n + 1]; int disc[n + 1]; int low[n + 1]; vector<int> visited(n + 1, 0);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, adj, disc, low, visited);
    cout << vec.size() << "\n";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i].first << ' ' << vec[i].second << "\n";
    }
}