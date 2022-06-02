#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 5e3 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    if(n % k == 0){
        cout << n/k << ' ' << n/k << ' ' << n/k << "\n";
        return;
    }
    if(n % 2 != 0){
        cout << (n / 2) << ' ' << (n / 2) << ' ' << "1\n";
        return;
    }
    if((n / 2) % 2 != 0){
        cout << (n / 2) - 1 << ' ' << (n / 2) - 1 << ' ' << "2\n";
        return;
    }
    cout << n/2 << ' ' << n/4 << ' ' << n/4 << "\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}