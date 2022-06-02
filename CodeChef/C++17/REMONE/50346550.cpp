#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, b[N], a[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n - 1; ++i)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);
    if(a[n] < b[n - 1]){
        ll req = b[n - 1] - a[n], j = 1, ok = 0;
        for(int i = 1; i <= n - 1; ++i){
            if(b[j] - a[i] != req)
                ++ok;
            else
                ++j;
        }
        if(ok <= 1) cout << req << "\n";
        else cout << b[n - 1] - a[n - 1] << "\n";
    }
    else
        cout << b[n - 1] - a[n - 1] << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
