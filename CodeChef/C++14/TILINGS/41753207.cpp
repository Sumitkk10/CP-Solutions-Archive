#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 10000;
const int N = 1e6 + 5;

int main(){
    fast;
    int n;
    cin >> n;
    int f[n + 1], h[n + 1];
    f[1] = 1;
    h[1] = 1;
    f[2] = 2;
    h[2] = 2;
    for(int i = 3; i <= n; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + (2 * h[i - 2])) % MOD;
        h[i] = (f[i - 1] + h[i - 1]) % MOD;
    }
    cout << f[n] << '\n';
    return 0;
}