#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[n], ans = 0;
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(*max_element(a, a+n) > k) cout << "-1\n";
        else{
            for(int i = 0; i < n; ++i){
                int sum = a[i];
                while(sum <= k && i < n){
                    ++i;
                    sum += a[i];
                    if(sum > k){
                        --i;
                        break;
                    }
                }
                ++ans;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
