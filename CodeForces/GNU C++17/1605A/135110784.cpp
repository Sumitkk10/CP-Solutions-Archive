#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long a, b, c;
    cin >> a >> b >> c;
    if(2*b == a + c){
        cout << "0\n";
        return;
    }
    long long x = a + c, ans = 0;
    if(2 * b > x){
        ll low = 0, high = 1e9;
        while(low <= high){
            ll mid = (low + high) / 2;
            if(2*b - 2*mid >= x + mid){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << min(1ll, abs((2*b - 2*ans) - (x + ans))) << '\n'; 
        return;
    }
    ll low = 0, high = 1e9;
    while(low <= high){
        ll mid = (low + high) / 2;
        if(x - mid >= 2*b + 2*mid){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << min(1ll, abs((2*b + 2*ans) - (x - ans))) << '\n'; 
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
