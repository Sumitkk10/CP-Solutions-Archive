#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long ans = 0;
    for(int i = 1; i < n; ++i){
        ans = max(ans, a[i]*a[i - 1]);
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
