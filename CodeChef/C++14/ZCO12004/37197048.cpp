#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 3;
const int MOD = 1e9 + 7;
ll n, a[N], dp[N], dpp[N];

ll go(int i){
    ll mn = 1e18;
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    mn = min(mn, a[i] + min(go(i + 1), go(i + 2)));
    return dp[i] = mn;
}

ll goo(int i){
    ll mn = 1e18;
    if(i < 0) return 0;
    if(dpp[i] != -1) return dpp[i];
    mn = min(mn, a[i] + min(goo(i - 1), goo(i - 2)));
    return dpp[i] = mn;
}

int main(){
    fast;   
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(dpp, -1, sizeof(dpp));
    for(int i = 0; i < n; ++i) cin >> a[i];
    cout << min(go(0), goo(n - 1));
    return 0;
}
