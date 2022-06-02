#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
int n, a[N], dp[N][3];

int ans(int i, int cnt){
    if(i >= n)
        return 0;
    if(dp[i][cnt] != -1)
        return dp[i][cnt];
    int mx = 0;
    if(cnt <= 1)
        mx = max(mx, ans(i + 1, cnt + 1) + a[i]);
    mx = max(mx, ans(i + 1, 0));
    return dp[i][cnt] = mx;
}

void solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << ans(0, 0) << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}