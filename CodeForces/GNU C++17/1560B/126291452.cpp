#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    int n = b - a;
    if(a - n >= 1){
        cout << "-1\n";
        return;
    }
    if(b + n <= 2*n){
        cout << "-1\n";
        return;
    }
    if(c <= n){
        if(c + n <= 2*n and c + n > n){
            cout << c + n << "\n";
            return;
        }
        cout << "-1\n";
        return;
    }
    else{
        if(c - n >= 1 and c - n <= n){
            cout << c - n << "\n";
            return;
        }
        cout << "-1\n";
        return;
    }   
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
