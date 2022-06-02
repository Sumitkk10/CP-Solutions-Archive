#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long n, a, b;
    cin >> n >> a >> b;
    if(b == 1 or n == 1){
        cout << "Yes\n";
        return;
    }
    if(a == 1){
        if(n == 1){
            cout << "Yes\n";
            return;
        }
        if(n % b == 1){
            cout << "Yes\n";
            return;
        }
        cout << "No\n";
        return;
    }    
    long long pre = 1;
    while(pre <= n){
        if(pre > n) break;
        if((n - pre) % b == 0){
            cout << "Yes\n";
            return;
        }
        pre *= a;
    }
    cout << "No\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}