#include <bits/stdc++.h>
using namespace std;
vector<int>arr[100001]; int flag;

void dfs(int n, stack<int>&s, int visited[]){
    int temp; visited[n] = 1;
    for(int i = 0; i < arr[n].size(); i++){
        temp = arr[n][i];
        if(visited[temp] == 0){
            dfs(temp, s, visited);
        }else if(visited[temp] == 1){
           flag = 1;
        }
    }
    visited[n] = 2;
    s.push(n);
}

int main(){
    int n, m, u, v;
    cin >> n >> m; flag = 0;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        arr[u].push_back(v);
    } 
    stack<int>s;  
    int visited[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, s, visited);
        }
    }
    if(flag == 1){
        cout << "IMPOSSIBLE";
    }else{
        while(s.size() > 0){
            cout << s.top() << ' ';
            s.pop();
        }
    }
}