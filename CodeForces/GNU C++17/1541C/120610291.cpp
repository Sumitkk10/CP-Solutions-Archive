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
    long long int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    if(n == 2){
        cout << "0\n";
        return;
    }
    sort(a + 1, a + n + 1);
    long long ans = 0, pre[n + 1];
    pre[1] = 0;
    for(int i = 2; i <= n; ++i){
        pre[i] = ((i - 1) * (a[i] - a[i - 1])) + (pre[i - 1]);
        ans += pre[i];
    }
    cout << -(ans - a[n]) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
