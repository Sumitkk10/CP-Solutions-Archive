#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        ll k, ans;
        cin >> k;
        ll x = a[k];
        sort(a.begin(), a.end());
        for(int i = 1; i <= n; ++i){
            if(a[i] == x){
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!