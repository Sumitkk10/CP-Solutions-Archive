#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int f[4];
    for(int i = 0; i < 4; ++i)
        cin >> f[i];
    sort(f, f + 4);
    int sum = f[3], a = f[0], b = f[1], c = f[2];
    int z = sum - a;
    int y = sum - b;
    int x = sum - c;
    cout << x << ' ' << y << ' ' << z << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
