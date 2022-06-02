#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll n;
    cin >> n;
    pair<ll, ll> a[n], b[n];
    vector<ll> dp(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        b[i].first = a[i].first;
        b[i].second = a[i].first + a[i].second;
        dp[i] = 1;
    }
    sort(b, b+n);
    for(int i = 0; i < n; ++i){
        // cout << b[i].first << ' ' << b[i].second << ' ' << '\n';
        for(int j = i-1; j >= 0; --j){
            if(b[i].first > b[j].second){
                dp[i] += dp[j];
                break;
            }
        }
    }
    ll max = 0;
    for(int i = 0; i < n; ++i){
        // cout << dp[i] << ' ';
        if(dp[i] > max)
            max = dp[i];
    }
    cout << max; 
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#