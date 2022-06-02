#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

// we will place our box only in the corners of the grid.
// shit problem

void solve(){
    ll l, b;
    cin >> b >> l;
    ll x1, y1, x2, y2, w, h, ans = INT_MAX;
    cin >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if((h + (y2 - y1)) > l and b < (w + (x2 - x1))){
        cout << "-1\n";
        return;
    }
    if((h + (y2 - y1)) <= l and b >= (w + (x2 - x1))){
        ans = min(ans, min(max(0ll, h - y1), max(0ll, w - x1)));
        ans = min(ans, min(max(0ll, y2 - (l - h)), max(0ll, w - x1)));
        ans = min(ans, min(max(0ll, y2 - (l - h)), max(0ll, x2 - (b - w))));
        ans = min(ans, min(max(0ll, h - y1), max(0ll, x2 - (b - w))));
    }
    else if((h + (y2 - y1)) <= l){
        ans = min(ans, max(0ll, h - y1));
        ans = min(ans, max(0ll, y2 - (l - h)));
    }
    else if(b >= (w + (x2 - x1))){
        ans = min(ans, max(0ll, w - x1));
        ans = min(ans, max(0ll, x2 - (b - w)));
    }
    cout << fixed << setprecision(6) << (ld) ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
