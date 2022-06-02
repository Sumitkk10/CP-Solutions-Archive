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
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    for(int i = 1; i <= n; ++i){
        if(a[i] <= b[i]){
            if(a[i] == 0) cout << b[i] << ' ';
            else cout << a[i] << b[i] << ' ';
        }
        else{
            if(b[i] == 0) cout << a[i] << ' ';
            else cout << b[i] << a[i] << ' ';
        }
    }
    cout << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
