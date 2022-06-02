#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[2*n], odd = 0, even = 0;
    for(int i = 0; i < 2*n; ++i){
        cin >> a[i];
        odd += (a[i] % 2);
        even += (a[i] % 2 == 0);
    }
    cout << (odd == n and even == n ? "Yes\n" : "No\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
