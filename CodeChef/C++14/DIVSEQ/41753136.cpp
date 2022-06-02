#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 15746;
const int N = 1e6 + 5;

int main(){
    fast;
    int n;
    cin >> n;
    map<int, int> mp;
    int a[n + 1], dp[n + 1] = {0};
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[1] = 1;
    mp[a[1]] = 1;
    for(int i = 2; i <= n; ++i){
        int mx = 0;
        for(long long int j = 1; j * j <= a[i]; ++j){
            if(a[i] % j == 0){
                if(mp[j]) mx = max(mx, dp[mp[j]]);
                if(a[i] / j != j)
                    if(mp[a[i] / j]) mx = max(mx, dp[mp[a[i] / j]]);
            }
        }
        mp[a[i]] = i;
        dp[i] = mx + 1;
    }
    cout << *max_element(dp + 1, dp + n + 1) << '\n';
    return 0;
}