#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5001;
const int MOD = 1e9 + 7;
ll n, s, e[N], dp[N][N], ok[N];

ll sum(ll x){
    string ok = to_string(x);
    ll sum1 = 0;
    for(auto k : ok)
        sum1 += (k - '0');
    return (sum1 * sum1 * sum1);
}

ll solve(int i, int cnt){
    if(i >= n)
        return 0;
    if(dp[i][cnt] != -1)
        return dp[i][cnt];
    ll ans = 0;
    ll cur = ok[cnt];
    ans = max(ans, solve(i + 1, cnt + 1));
    ans = max(ans, solve(i + 1, cnt) + (cur * e[i]));
    return dp[i][cnt] = ans;
}

void pre(){
    for(int i = 0; i < N; ++i){
        if(i == 0){
            ok[0] = s;
            continue;
        }
        s += sum(s);
        ok[i] = s;
    }
}

int main(){
    fast;
    memset(dp, -1, sizeof(dp));
    cin >> n >> s;
    for(int i = 0; i < n; ++i)
        cin >> e[i];
    pre();
    cout << solve(0, 0) << '\n';
    return 0;
}
