
//      https://www.iarcs.org.in/inoi/online-study-material/topics/dp-tiling.php

#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1000000 + 5;

ll dps[N], dpl[N];

ll solve(ll n);

ll ltile(ll n){
    if(n == 2 || n == 1) return 1;
    if(dpl[n] != -1) return dpl[n];
    ll ans = ltile(n - 1) + solve(n - 2);
    if(ans > 9999)
        ans %= 10000;
    return dpl[n] = ans;
}

ll solve(ll n){
    if(n == 1 || n == 2) return n;
    if(dps[n] != -1) return dps[n];
    ll ans = solve(n - 1) + solve(n - 2) + 2 * ltile(n - 1);
    if(ans > 9999)
        ans %= 10000;
    return dps[n] = ans;
}

int main(){
    fast;
    ll n;
    cin >> n;
    memset(dps, -1, sizeof dps);
    memset(dpl, -1, sizeof dpl);
    cout << solve(n);
}
//                                     #!!{*[$um1t_Kum@r]*}!!#