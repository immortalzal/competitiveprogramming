#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k, x, a, b, c, val, temp;
    cin >> n >> k >> x >> a >> b >> c; long long sum = x; long long ans = 0;
    deque<long long>q; q.push_back(x);
    for(int i = 1; i <= n; i++){
        if(q.size() < k){
            val = (a * q.back() + b) % c;
            q.push_back(val);
            sum += val;
        }else{
            ans ^= sum;
            sum -= q.front(); q.pop_front();
            val = (a * q.back() + b) % c;
            q.push_back(val); sum += val;
        }
    }
    cout << ans;
}