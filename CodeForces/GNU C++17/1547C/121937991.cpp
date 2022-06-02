#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int k, n, m;
    cin >> k >> n >> m;
    // initially there were k lines.
    // n --> monocarp
    // m --> polycarp
    int a[n + 1], b[m + 1], ct = 0, mx = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ct += (a[i] == 0);
        mx = max(mx, a[i]);
    }
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
        ct += (b[i] == 0);
        mx = max(mx, b[i]);
    }
    if(mx > ct + k){
        cout << "-1\n";
        return;
    }
    int i = 1, j = 1, cur = 1, pages = k;
    vector<int> ans;
    while(cur <= n + m){
        if(i <= n and pages >= a[i]){
            if(a[i] == 0){ 
                ans.push_back(0);
                ++pages;
            }
            else ans.push_back(a[i]);
            ++i;
        }
        else if(j <= m and pages >= b[j]){
            if(b[j] == 0){ 
                ans.push_back(0);
                ++pages;
            }
            else ans.push_back(b[j]);
            ++j;
        }
        else{
            cout << "-1\n";
            return;
        }
        ++cur;
    }
    for(auto k : ans)
        cout << k << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
