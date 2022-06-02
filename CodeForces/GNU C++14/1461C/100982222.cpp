#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, q;
    cin >> n >> q;
    int a[n], pos = -1;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] != i + 1)
            pos = i;
    }
    double ans = 1.0;
    if(pos == -1)
        ans = 0.0;
    while(q--){
        int r;
        double p;
        cin >> r >> p;
        if(r > pos)
            ans *= (1 - p);
    }
    cout << fixed << setprecision(6) << (1 - ans) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}