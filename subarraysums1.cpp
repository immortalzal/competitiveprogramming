#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, leftptr, rightptr;
    leftptr = 0; rightptr = 0;
    cin >> n >> m; int total = 0; int sum = 0;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    while(leftptr < n){
        if(sum < m){
            sum += arr[rightptr];
            rightptr++;
        }else if(sum > m){
            sum -= arr[leftptr];
            leftptr++;
        }else{
            total++;
            sum -= arr[leftptr];
            leftptr++;
        }
    }
    cout << total;
}