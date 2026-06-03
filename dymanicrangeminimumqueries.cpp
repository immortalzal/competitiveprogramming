#include <bits/stdc++.h>
using namespace std;

void build(int v, int left, int right, int arr[], int tree[]){
    if(left == right){
        tree[v] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * v, left, mid, arr, tree);
    build(2 * v + 1, mid + 1, right, arr, tree);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int query(int v, int leftq, int rightq, int left, int right, int tree[]){
    if(leftq > rightq){
        return INT_MAX;
    }
    if(leftq == left && rightq == right){
        return tree[v];
    }
    int mid = (left + right) / 2;
    return min(query(2 * v, leftq, min(rightq, mid), left, mid, tree), query(2 * v + 1, max(mid + 1, leftq), rightq, mid + 1, right, tree));
}

void update(int v, int left, int right, int position, int val, int tree[]){
    if(left == right){
        tree[v] = val;
        return;
    }
    int mid = (left + right) / 2;
    if(position <= mid){
        update(2 * v, left, mid, position, val, tree);
    }else{
        update(2 * v + 1, mid + 1, right, position, val, tree);
    }
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int main(){
    int n, k, a, b, c;
    cin >> n >> k; int arr[n + 1]; int tree[4 * n + 1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, 0, n - 1, arr, tree);
    for(int i = 0; i < k; i++){
        cin >> a >> b >> c;
        if(a == 1){
            update(1, 0, n - 1, b - 1, c, tree);
        }else{
            cout << query(1, b - 1, c - 1, 0, n - 1, tree) << "\n";
        }
    }
}