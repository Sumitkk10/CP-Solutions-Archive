#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n], ans = 0, dp[n], max = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        dp[i] = 1;
    }
    for(int i = 1; i < n; ++i){
        for(int j = i-1; j >= 0; --j){
            if(a[i]%a[j] == 0){
                if((dp[j]+1) > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(dp[i] > max)
            max = dp[i];
    }
    cout << max;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
