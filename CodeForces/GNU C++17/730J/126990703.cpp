#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N], b[N];
map<pair<int, int>, pair<int, int> > dp;

pair<int, int> go(int i, int left){
    if(i == n + 1){
         if(left <= 0)
               return make_pair(0, 0);
          return make_pair(INT_MAX, INT_MAX);
    }
    if(dp[{i, left}] != make_pair(0, 0))
        return dp[{i, left}];
    int ans = INT_MAX, ans1 = INT_MAX;
    pair<int, int> x = go(i + 1, left + a[i] - b[i]);
    if(x.first < ans){
          ans = x.first + 1;
          ans1 = x.second;
    }
    x = go(i + 1, left + a[i]);
    if(x.first == ans and ans1 > x.second + a[i])
          ans1 = x.second + a[i];
    else if(x.first < ans){
         ans = x.first;
         ans1 = x.second + a[i];
    }
    return dp[{i, left}] = make_pair(ans, ans1);

}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
     pair<int, int> ans = go(1, 0);
    cout << ans.first << " " << ans.second << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
