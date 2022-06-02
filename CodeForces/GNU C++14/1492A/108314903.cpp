#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;

void solve(){
    long long int p, a, b, c;
    cin >> p >> a >> b >> c;
    long long div1, div2, div3;
    if(p % a == 0)  div1 = p / a;
    else div1 = (p / a) + 1;
    if(p % b == 0) div2 = p / b;
    else div2 = (p / b) + 1;
    if(p % c == 0) div3 = p / c;
    else div3 = (p / c) + 1;
    div1 *= a;
    div2 *= b;
    div3 *= c;
    /*
    if(a > p)
        div1 = a;
    if(b > p)
        div2 = b;
    if(c > p)
        div3 = c;
    */
    cout << min(div1 - p, min(div2 - p, div3 - p)) << "\n";
    // what if a, b, c, > p ??
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}