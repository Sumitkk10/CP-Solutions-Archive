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
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int pos = -1;
    for(int i = 1; i <= n; ++i){
        if(a[i] == 1){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        for(int i = 1; i <= n + 1; ++i)
            cout << i << " ";
        cout << "\n";
        return;
    }
    bool ok = 0;
    for(int i = pos + 1; i <= n; ++i){
        if(a[i] == 1)
            ok = 1;
    }
    for(int i = 1; i <= pos - 1; ++i)
        cout << i << " ";
    cout << n + 1 << " ";
    for(int i = pos; i <= n; ++i)
        cout << i << " ";
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
