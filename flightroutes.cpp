#include <bits/stdc++.h>
using namespace std;

//kth shortest paths problem
void dijk(int source, int dest, vector<int>& visited, int k, vector<pair<int,int> > adj[]){
    long long u, v, w, d;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
    pq.push(make_pair(0, source));
    while(pq.size() > 0 && visited[dest] < k){
        u = pq.top().second; d = pq.top().first; pq.pop(); visited[u]++; 
        if(u == dest){
            cout << d << ' ';
        }
        if(visited[u] > k){
            continue;
        }
        for(int i = 0; i < adj[u].size(); i++){
            v = adj[u][i].first; w = adj[u][i].second;
            pq.push(make_pair(d + w, v));
        }
    }
    
}

int main(){
    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    vector<pair<int,int> > adj[n + 1];
    vector<int>visited(n + 1, 0);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
    dijk(1, n, visited, k, adj);
}