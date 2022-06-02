#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int a[3], b[3], sum = 0, sum1 = 0;
    for(int i = 0; i < 3; ++i){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < 3; ++i){
        cin >> b[i];
        sum1 += b[i];
    }
    cout << (sum == sum1 ? "Pass\n" : "Fail\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * Read other problems if stuck on this one.
*/
