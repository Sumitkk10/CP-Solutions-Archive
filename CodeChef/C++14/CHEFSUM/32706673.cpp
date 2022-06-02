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
        ll n, mn = 1000000000001, ans = 0, o;
        cin >> n;
        vector<ll> a(n), prefix_sum(n), suffix_sum(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        prefix_sum[0] = a[0];
        for(int i = 1; i < n; ++i)
            prefix_sum[i] = a[i] + prefix_sum[i-1];
        suffix_sum[n-1] = a[n-1];
        for(int i = n-1; i >= 0; --i)
            suffix_sum[i] = a[i] + suffix_sum[i+1];
        for(int i = 0; i < n; ++i){
            ans = prefix_sum[i] + suffix_sum[i];
            if(ans < mn){
                mn = ans;
                o = i;
            }
        }
        cout << o+1 << '\n';
    }
    return 0;
}