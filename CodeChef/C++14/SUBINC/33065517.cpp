#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n), dp(n);
        for(int i = 0; i < n; ++i){
            dp[i] = 1;
            cin >> a[i];
        }
        ll sum = 1;
        for(int i = 1; i < n; ++i){
            if(a[i] >= a[i-1])
                dp[i] = dp[i-1] + 1;
            sum += dp[i];
        }
        cout << sum << endl;
    }
    return 0;
}