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
        ll x, y, k, n, c = 0;
        cin >> x >> y >> k >> n;
        ll ans = x-y;
        pair<ll, ll> a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i].second >> a[i].first;
            // cout << a[i].first << ' ' << a[i].second << '\n';
        }
        sort(a, a+n);
        for(int i = 0; i < n; ++i){
            // cout << a[i].first << ' ' << a[i].second << ' ';
            if(a[i].first > k){
                cout << "Not Found\n";
                ++c;
                break;
            }
            else if(a[i].first <= k){
                if(a[i].second < ans)
                    continue;
                else{
                    cout << "Found\n";
                    ++c;
                    break;
                }
            }
        }
        if(c == 0)
            cout << "Not Found\n";
    }
    return 0;
}
