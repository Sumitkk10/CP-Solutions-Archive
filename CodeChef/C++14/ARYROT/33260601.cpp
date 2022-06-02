#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1000000007; 

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;
        d = n-d;
        vector<ll> a(n), ans;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i){
            ans.push_back(a[d]);
            ++d;
            if(d == n)
                d = 0;
        }
        for(int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
    }
    return 0;
}