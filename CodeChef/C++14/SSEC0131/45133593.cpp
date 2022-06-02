#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
    fast;
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= m; ++i)
        mp[a[i]]++;
    int ans = mp.size();
    for(int i = m + 1; i <= n; ++i){
        mp[a[i - m]]--;
        if(mp[a[i - m]] == 0)
            mp.erase(a[i - m]);
        mp[a[i]]++;
        ans = max(ans, (int) mp.size());
    }
    cout << ans << '\n';
    return 0;
}
