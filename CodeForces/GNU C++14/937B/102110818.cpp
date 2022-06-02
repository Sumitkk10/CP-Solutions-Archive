#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 105;
const int MOD = 1e9 + 7;

bool ok(ll y, ll p){
    for(int i = 2; i * i <= y; ++i){
        if(i > p)
            break;
        if(y % i == 0)
            return false;
    }
    return true;
}

void solve(){
    ll p, y;
    cin >> p >> y;
    while(y > p){
        if(ok(y, p)){
            cout << y << '\n';
            return;
        }
        --y;
    }
    cout << "-1\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
