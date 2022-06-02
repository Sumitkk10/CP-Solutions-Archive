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
    int a[10];
    for(int i = 1; i <= 9; ++i)
        cin >> a[i];
    if(n < *min_element(a + 1, a + 10)){
        cout << "-1\n";
        return;
    }
    int mn = *min_element(a + 1, a + 10);
    int len = n / mn, dig;
    for(int i = 1; i <= 9; ++i){
        if(a[i] == mn)
            dig = i;
    }
    string ans;
    for(int i = 0; i < len; ++i)
        ans.push_back(dig + '0');
    int left = n % mn;
    for(int i = 0; i < ans.size(); ++i){
        int cur = -1;
        for(int j = 1; j <= 9; ++j){
            if(a[j] <= (left + a[ans[i] - '0'])){
                cur = j;
            }
        }
        if(cur == -1) break;
        if(cur < (ans[i] - '0')) continue;
        left -= a[cur] - a[ans[i] - '0'];
        ans[i] = (cur + '0');
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
