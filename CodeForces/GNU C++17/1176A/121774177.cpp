#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long n, ct = 0;
    cin >> n;
    while(n > 1){
        if(n % 5 == 0) n = (4*n)/5;
        else if(n % 3 == 0) n = (2*n)/3;
        else if(n % 2 == 0) n /= 2;
        else break;
        ++ct;
    }
    cout << (n == 1 ? ct : -1) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
