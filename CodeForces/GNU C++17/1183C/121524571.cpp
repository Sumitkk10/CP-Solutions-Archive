#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, k, a, b;

void solve(){
    cin >> k >> n >> a >> b;
    long long int low = 0, high = n, ans = -1;
    while(low <= high){
        long long int mid = (low + high) / 2;
        if((long long) (a*mid + b*(n - mid)) < k){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
