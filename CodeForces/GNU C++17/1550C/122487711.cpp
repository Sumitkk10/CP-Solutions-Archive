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
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = n + n - 1;
    for(int i = 1; i <= n - 2; ++i){
        int x = a[i + 1], y = a[i + 2];
        if(x >= a[i] and y >= x) continue;
        if(x <= a[i] and y <= x) continue;
        ++ans;
    }
    for(int i = 1; i <= n - 3; ++i){
        int x = a[i + 1], y = a[i + 2], z = a[i + 3];
        if(x >= a[i] and y >= x) continue;
        if(x <= a[i] and y <= x) continue;
        if(x >= a[i] and z >= x) continue;
        if(x <= a[i] and z <= x) continue;
        if(y >= a[i] and z >= y) continue;
        if(y <= a[i] and z <= y) continue;
        if(y >= x and z >= y) continue;
        if(y <= x and z <= y) continue;
        ++ans;
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
