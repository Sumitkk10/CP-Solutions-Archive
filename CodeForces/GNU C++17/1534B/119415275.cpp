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
    vector<int> a(n);
    long long ans = 0;
    for(auto &val : a)
        cin >> val;
    if(n == 1){
        cout << a[0] << '\n';
        return;
    }
    for(int i = 0; i < n; ++i)
        if(i > 0)
            ans += abs(a[i] - a[i - 1]);
    ans += a[0] + a[n - 1];
    for(int i = 0; i < n; ++i){
        if(i == 0){
            if(a[i] > a[i + 1]){
                ans -= a[i];
                ans += a[i + 1];
                a[i] = a[i + 1];
                continue;
            }
        }
        if(i == n - 1){
            if(a[i - 1] < a[i]){
                ans -= a[i];
                ans += a[i - 1];
                a[i] = a[i - 1];
                continue;
            }
        }
        if(a[i] > a[i - 1] and a[i] > a[i + 1]){
            ans -= abs(a[i] - a[i - 1]); // 17
            ans -= abs(a[i] - a[i + 1]); // 14
            ans += a[i] - max(a[i - 1], a[i + 1]); // 15
            a[i] = max(a[i - 1], a[i + 1]);
            ans += abs(a[i] - a[i - 1]); // 15 
            ans += abs(a[i] - a[i + 1]); // 17
        }
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
