#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 500 + 5;
const int MOD = 1e9 + 7;

long long bin_pow(long long int num, int x){
    long long ans = 1;
    while(x > 0){
        if(x & 1)
            ans = (ans * num) % MOD;
        num = (num * num) % MOD;
        x >>= 1;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    cout << bin_pow(2, n - 1) << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}