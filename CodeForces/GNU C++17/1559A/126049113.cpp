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
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = INT_MAX;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            int andd = a[i];
            for(int k = i + 1; k <= j; ++k)
                andd = (andd & a[k]);   
            ans = min(ans, andd);
        }
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
