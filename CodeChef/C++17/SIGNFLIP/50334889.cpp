#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k, a[N];

void solve(){
    vector<int> neg;
    ll ans = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] < 0)
            neg.push_back(abs(a[i]));
        else
            ans += a[i];
    }
    sort(neg.rbegin(), neg.rend());
    for(int i = 0; i < min((int) neg.size(), k); ++i)
        ans += neg[i];
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
