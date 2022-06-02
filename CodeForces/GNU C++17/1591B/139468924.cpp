#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 1e6 + 5;

void solve(){
    int n;
    cin >> n;
    int a[n], mx = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if(a[n - 1] == mx){
        cout << "0\n";
        return;
    }
    int ans = 1, mxx = a[n - 1];
    for(int i = n - 2; i >= 1; --i){
        if(a[i] > mxx){
            ++ans;
            mxx = a[i];
        }
        if(mxx == mx){
            --ans;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
