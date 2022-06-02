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
    int a[n];
    int ans = n - 1, sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        sum += a[i];
        bool ok = 1;
        int sum1 = 0, cnt = 1;
        for(int j = i + 1; j < n; ++j){
            sum1 += a[j];
            if(sum1 == sum){
                sum1 = 0;
                ++cnt;
            }
            if(sum1 > sum){
                ok = false;
                break;
            }
        }
        if(sum1) ok = false;
        if(ok)
            ans = min(ans, n - cnt);
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
