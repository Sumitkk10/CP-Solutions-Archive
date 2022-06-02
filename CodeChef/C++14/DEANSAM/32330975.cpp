#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll n, min = 100000000001;
    cin >> n;
    ll a[n], dp[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    dp[0] = a[0];
    for(int i = 1; i < n; ++i){
        if(dp[i-1] < 0)
            dp[i] = a[i] + dp[i-1];
        else
            dp[i] = a[i];
        if(dp[i] < min)
            min = dp[i];
    }
    cout << min;
    return 0;
}
