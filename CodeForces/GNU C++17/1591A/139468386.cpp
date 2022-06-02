#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 1e6 + 5;

void solve(){
    int n;
    cin >> n;
    int a[n], ans = 1;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ans += (a[0] == 1);
    for(int i = 1; i < n; ++i){
        if(a[i] == 0 and a[i - 1] == 0){
            cout << "-1\n";
            return;
        }
        if(a[i] == 1 and a[i - 1] == 1)
            ans += 5;
        else if(a[i] == 1)
            ++ans;
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
