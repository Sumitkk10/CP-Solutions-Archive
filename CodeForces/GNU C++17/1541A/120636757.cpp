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
    vector<int> ans;
    for(int i = 1; i <= n; ++i)
        ans.push_back(i);
    for(int i = 0; i < ans.size(); i += 2){
        if(i == ans.size() - 1){
            swap(ans[i], ans[i - 1]);
            continue;
        }
        swap(ans[i], ans[i + 1]);
    }
    for(auto k : ans) cout << k << ' ';
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
