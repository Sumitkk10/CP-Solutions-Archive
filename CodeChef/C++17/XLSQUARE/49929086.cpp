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
    ll ok = 0;
    for(int i = 1; i <= a; ++i){
        if(i*i <= a)
            ok = i;
        else
            break;
    }
    cout << ok*b << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
