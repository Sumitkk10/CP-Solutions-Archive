#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, d;
    cin >> n >> d;
    int a[n];
    bool ok = 1;
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
        if(a[i] > d)
            ok = 0;
    }
    if(ok == 1){
        cout << "YES\n";
        return;
    }
    sort(a, a + n);
    if(a[0] + a[1] <= d)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();    
    return 0;
}
