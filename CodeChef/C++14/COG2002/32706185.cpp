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
        ll n, mx = 0, sum = 0;
        cin >> n;
        vector<ll> a(n), prefix_sum(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n-2; ++i){
            sum = a[i] + a[i+1] + a[i+2];
            mx = max(mx, sum);
        }
        sum = a[n-2] + a[n-1] + a[0];
        mx = max(mx, sum);
        sum = a[n-1] + a[0] + a[1];
        mx = max(mx, sum);
        cout << mx << '\n';
    }
    return 0;
}