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
    int a[4 * n + 1];
    for(int i = 1; i <= 4 * n; ++i)
        cin >> a[i];
    sort(a + 1, a + 4 * n + 1);
    bool ok = 1;
    int area = a[1] * a[4 * n];
    for(int i = 1; i <= n; ++i){
        if(a[2*i - 1] != a[2 * i] or a[4 * n - 2 * i + 1] != a[4 * n - 2 * i + 2] or a[2 * i - 1] * a[4 * n - 2 * i + 2] != area){
            ok = 0;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}