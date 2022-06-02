#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
void solve(){
    int n, m;
    cin >> n >> m;
    if(n < m){
        int ans = 0;
        while(m != n){
            if(m % 2 or m < n) ++m;
            else m /= 2;
            ++ans;
        }
        cout << ans << '\n';
    }
    else
        cout << abs(m - n) << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}