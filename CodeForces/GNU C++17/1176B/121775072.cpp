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
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        long long int x;
        cin >> x;
        mp[x % 3]++;
    }
    long long int ans = mp[0] + min(mp[1], mp[2]);
    int mn = min(mp[1], mp[2]);
    mp[1] -= mn;
    mp[2] -= mn;
    cout << ans + mp[1]/3 + mp[2]/3 << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
