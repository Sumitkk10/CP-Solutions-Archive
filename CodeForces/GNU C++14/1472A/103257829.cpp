#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int w, h, n;
    cin >> w >> h >> n;
    int cnt = 1, cnt1 = 1;
    if(n == 1){
        cout << "YES\n";
        return;
    }
    while(w % 2 == 0){
        cnt *= 2;
        w /= 2;
    }
    while(h % 2 == 0){
       	cnt1 *= 2;
        h /= 2;
    }
    cout << (cnt * cnt1 >= n ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}