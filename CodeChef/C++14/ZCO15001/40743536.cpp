#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];

bool is_palindrome(int i, int j){
    while(i <= j and i < n and j >= 0){
        if(a[i] != a[j])
            return false;
        ++i, --j;
    }
    return true;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int dp[n + 1] = {0}, cnt = 1;
    for(int i = n - 1; i >= 0; --i){
        dp[i] = cnt;
        ++cnt;
    }
    dp[n] = 0;
    for(int i = n - 1; i >= 0; --i)
        for(int j = i; j < n; ++j)
            if(is_palindrome(i, j))
                dp[i] = min(dp[i], dp[j + 1] + 1);
    cout << dp[0] << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
