#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        long long int r, b, d;
        cin >> r >> b >> d;
        if(d == 0){
            cout << (r == b ? "YES\n" : "NO\n");
            continue;
        }
        long long mn = min(r, b), mx = max(r, b);
        mx -= mn;
        if(((mx / d) + (mx % d != 0)) > mn)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
