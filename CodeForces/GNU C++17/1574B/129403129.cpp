#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int a[3], m;
    for(int i = 0; i < 3; ++i)
        cin >> a[i];
    cin >> m;
    sort(a, a + 3);
    if(a[0] + a[1] + a[2] - 3 < m){
        cout << "NO\n";
        return;
    }
    if((a[0] == a[1] and a[1] == a[2]) or (a[2] == a[0] + a[1])){
        cout << "YES\n";
        return;
    }
    if(a[2] > a[0] + a[1]){
        cout << (m >= a[2] - (a[0] + a[1]) - 1 ? "YES\n" : "NO\n");
        return;
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