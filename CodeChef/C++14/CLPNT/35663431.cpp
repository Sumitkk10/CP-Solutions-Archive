#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;

int main(){
    fast;
    ll t;
    cin >> t;   
    while(t--){
        ll n, q;
        cin >> n;
        ll a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        cin >> q;
        while(q--){
            ll x, y;
            cin >> x >> y;
            if(x == 0 && y == 0){
                cout << "0\n";
                continue;
            }
            ll sum = x + y;
            int low = 0, high = n - 1, ans = -1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(a[mid] == sum){
                    ans = 0;
                    break;
                }
                else if(a[mid] < sum) low = mid + 1;
                else high = mid - 1;
            }
            if(ans == 0){
                cout << "-1\n";
                continue;
            }
            low = 0, high = n - 1, ans = -1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(a[mid] < sum){
                    ans = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            if(ans == -1) cout << "0\n";
            else cout << ans + 1 << "\n";
        }
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}