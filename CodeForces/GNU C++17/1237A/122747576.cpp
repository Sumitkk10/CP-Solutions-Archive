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
    int a[n + 1], flg = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] % 2 == 0){
            cout << a[i]/2 << '\n';
            continue;
        }
        cout << (a[i]+flg)/2 << '\n';
        flg *= -1;
        
    }

}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
