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
    long long int a[n + 1], ct = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        if(a[i] % (i + 1) != 0){
            ++ct;
            continue;
        }
        int j = i;
        while(j > 1){
            if(a[i] % j != 0) break;
            --j;
        }
        int remove1 = (i + 1) - j;
        if(ct >= remove1) ++ct;
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}