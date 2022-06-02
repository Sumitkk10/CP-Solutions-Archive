#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1000000 + 5;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k, mx = 0, b, d = 0, sum = 0, c;
        cin >> n >> k;
        vector<ll> prefix_sum(n+1), a(n+1);
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        prefix_sum[0] = 0;
        for(int i = 1; i <= n; ++i){
            prefix_sum[i] = prefix_sum[i-1] + a[i];
        }
        for(int i = k; i <= n; ++i){
            b = prefix_sum[i] - prefix_sum[i-k];
            if(b > mx)
                mx = b;
        }
        for(int i = 1; i <= k; ++i){
            sum = prefix_sum[n] - prefix_sum[n-(k-i)];
            c = prefix_sum[i] + sum;
            if(c > d)
                d = c;
            sum = 0;
        }
        cout << max(mx, d) << '\n';
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
