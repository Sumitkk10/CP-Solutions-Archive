#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

void solve(){
    long double a, b, c, k;
    cin >> a >> b >> c >> k;
    long double s = (a + b + c) / 2;
    long double area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << fixed << setprecision(9) << ((area * k) / (k + 1)) << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}