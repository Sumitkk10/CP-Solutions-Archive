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
        ll n, mod = 1e9 + 7;
        cin >> n;
        ll a[n], ans = 0;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a+n, greater<>());
        for(int i = 0; i < n; ++i){
            if(a[i] == 0 || a[i] < i)
                a[i] = 0;
            else
                a[i] = ((a[i]%mod) -(i%mod)+mod)%mod; 
            ans = (((ans%mod)+a[i]%mod)%mod);
        }
        cout << ans << '\n';
    }
    return 0;
} 