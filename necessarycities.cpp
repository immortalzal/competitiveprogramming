#include <bits/stdc++.h>
using namespace std;

int tim;
set<int>s;

void dfs(int n, int parent, int disc[], int low[], vector<int>adj[], vector<int>& visited){
    low[n] = disc[n] = ++tim; int child = 0; int next; visited[n] = 1;
    for(int i = 0; i < adj[n].size(); i++){
        next = adj[n][i];
        if(visited[next] == 0){
            visited[next] = 1; child++;
            dfs(next, n, disc, low, adj, visited);
            low[n] = min(low[n], low[next]); //low[n] -> earliest node you can reach from n
            if(low[next] >= disc[n] && parent != 0 || parent == 0 && child > 1){
                s.insert(n);
            }
        }else{ //there is a cycle
            low[n] = min(low[n], disc[next]); //if next visited, may be ancestor of n
        }
    }

}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<int> adj[n + 1]; tim = 0; vector<int> visited(n + 1, 0);
    int disc[n + 1]; int low[n + 1];
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, disc, low, adj, visited);
    set<int>::iterator it;
    cout << s.size() << "\n";
    for(it = s.begin(); it != s.end(); it++){
        cout << *it << ' ';
    }

}