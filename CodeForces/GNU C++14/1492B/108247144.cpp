#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    map<int, int> pos;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        pos[a[i]] = i;
    }
    sort(b, b + n, greater<int>());
    int mx = n;
    for(int i = 0; i < n; ++i){
        int x = pos[b[i]];
        if(x > mx) continue;
        for(int i = x; i < mx; ++i)
            cout << a[i] << ' ';
        mx = min(mx, x);
    }
    cout << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}