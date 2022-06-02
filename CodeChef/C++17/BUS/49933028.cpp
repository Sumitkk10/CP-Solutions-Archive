#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, m, q, ct = 0;
    cin >> n >> m >> q;
    map<int, char> pre;
    for(int i = 1; i <= n; ++i)
        pre[i] = '#'; 
    bool ok = 1;
    while(q--){
        char a;
        int x;
        cin >> a >> x;
        if(a == '+') ++ct;
        else --ct;
        if(ct > m or ct < 0) ok = 0;
        if(a == '-')
            if(pre[x] != '+')
                ok = 0;
        pre[x] = a;
    }
    cout << (ok ? "Consistent\n" : "Inconsistent\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}