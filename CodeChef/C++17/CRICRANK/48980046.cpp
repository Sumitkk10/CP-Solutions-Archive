#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int r1, c1, w1, r2, c2, w2, ct = 0, ct1 = 0;
    cin >> r1 >> c1 >> w1 >> r2 >> c2 >> w2;
    if(r1 > r2) ++ct;
    else ++ct1;
    if(w1 > w2) ++ct;
    else ++ct1;
    if(c1 > c2) ++ct;
    else ++ct1;
    cout << (ct > ct1 ? "A\n" : "B\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
