#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int a[4];
    for(int i = 0; i < 4; ++i)
        cin >> a[i];
    if(a[0] + a[2] == 180 and a[1] + a[3] == 180) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
