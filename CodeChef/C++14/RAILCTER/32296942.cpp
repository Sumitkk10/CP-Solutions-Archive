#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll MOD = 1e9 + 7;

int main(){
    fast;
    ll n, k, mx = -1e7;
    cin >> n >> k;
    vector<ll> a(n + 1), prefix_sum(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    ll min = 0;
    prefix_sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        prefix_sum[i] = prefix_sum[i-1]+a[i];
    }
    for(int i = k; i <= n; ++i){
        if(prefix_sum[i-k] < min)
            min = prefix_sum[i-k];
        mx = max(mx, prefix_sum[i] - min);
    }
    cout << mx;
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#