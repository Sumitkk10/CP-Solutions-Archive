#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int a[3];
    for(int i = 0; i < 3; ++i)
        cin >> a[i];
    sort(a, a + 3);
    if(a[0] == 1){
        cout << "YES\n";
        return;
    }
    if(a[0] == 2 and a[1] == 2){
        cout << "YES\n";
        return;
    }
    if(a[0] == 3 and a[1] == 3 and a[2] == 3){
        cout << "YES\n";
        return;
    }
    if(a[0] == 2 and a[1] == 4 and a[2] == 4){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
