#include <bits/stdc++.h>
using namespace std;

void build(int v, int arr[], int tree[], int left ,int right){
    if(left == right){
        tree[v] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * v, arr, tree, left, mid);
    build(2 * v + 1, arr, tree, mid + 1, right);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int query(int v, int queryl, int queryr, int leftptr, int rightptr, int tree[]){
    if(queryl > queryr){
        return INT_MAX;
    }
    if(queryl == leftptr && queryr == rightptr){
        return tree[v];
    }
    int mid = (leftptr + rightptr) / 2;
    return min(query(2 * v, queryl, min(mid, queryr), leftptr, mid, tree), query(2 * v + 1, max(mid + 1, queryl), queryr, mid + 1, rightptr, tree));
}

int main(){
    int n, q, u, v;
    cin >> n >> q; int arr[n + 1]; int tree[4 * n + 1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, arr, tree, 0, n - 1);
    for(int i = 0; i < q; i++){
        cin >> u >> v;
        cout << query(1, u - 1, v - 1, 0, n - 1, tree) << "\n";
    }
}


