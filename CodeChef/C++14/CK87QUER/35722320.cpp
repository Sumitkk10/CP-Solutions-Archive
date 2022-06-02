#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;

int main() {
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll y;
        cin >> y;
        ll sumit = 700;
        ll amit = sqrt(y), ans = 0;
        for(int i = 1; i <= min(y, sumit); ++i){
            if((y - i) > 0)
                ans += floor(sqrt(y - i));
        }
        cout << ans << "\n";
    }
    return 0;
}