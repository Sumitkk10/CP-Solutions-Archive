#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n], dp[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    dp[0] = a[0];
    if(n >= 2)
        dp[1] = a[0]+a[1];
    if(n >= 3)
        dp[2] = max(dp[1], max(a[0]+a[2], a[1]+a[2]));
    for(int i = 3; i < n; ++i){
        dp[i] = max(dp[i-1], max(a[i]+dp[i-2],a[i]+a[i-1]+dp[i-3]));
    }
    cout << dp[n-1];
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#