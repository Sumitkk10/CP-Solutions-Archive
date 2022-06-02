#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long n;
    cin >> n;
    long long a[n + 1], res1 = 0, res = LLONG_MAX;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        long long ans = 0;
        for(int j = 1; j <= n; ++j)
            ans = (ans | (a[j] ^ a[i]));
        if(ans < res){
            res = ans;
            res1 = a[i];
        }
    }
    cout << res1 << " " << res << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
