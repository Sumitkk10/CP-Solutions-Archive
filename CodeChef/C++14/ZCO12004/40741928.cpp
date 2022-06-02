#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
int n, a[N];


void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int dp[n + 1] = {0}, dp1[n + 1] = {0};
    // dp[i] is the minimum cost to give meal to first i people along with the 1st person including the ith person.
    // dp1[i] is the minimum cost to give meal to first i people including the ith person but excluding 1st person.
    dp[0] = a[0], dp[1] = a[0] + a[1];
    dp1[0] = a[0], dp1[1] = a[1];
    for(int i = 2; i < n; ++i){
        dp[i] = a[i] + min(dp[i - 1], dp[i - 2]);
        dp1[i] = a[i] + min(dp1[i - 1], dp1[i - 2]);
    }
    cout << min({dp[n - 1], dp[n - 2], dp1[n - 1]}) << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}