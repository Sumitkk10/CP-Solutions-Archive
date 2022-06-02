#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long a, b;
    cin >> a >> b;
    if(a == b){
        cout << "0 0\n";
        return;
    }
    if(a > b) swap(a, b);
    cout << abs(b - a) << ' ';
    long long res = abs(b - a);
    long long ok = b/res, okk = b/res;
    if(b % res) ok++;
    else okk--;
    cout << min(b - res*okk, res*ok - b) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
