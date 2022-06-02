#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, tar, dp[102][1027];
vector<int> a[N];

long long int ans(int tshirt, int k){
    if(tshirt == 101){
        if(k == tar)
            return 1;
        return 0;
    }
    if(dp[tshirt][k] != -1)
        return dp[tshirt][k];
    long long int sum = 0;
    for(int i = 0; i < n; ++i){
        if(k & (1 << i))
            continue;
        for(auto j : a[i]){
            if(j == tshirt){
                sum = (sum + ans(tshirt + 1, (k | (1 << i)))) % MOD;
                break;
            }
        }
    }
    sum = (sum + ans(tshirt + 1, k)) % MOD;
    return dp[tshirt][k] = sum;
}

void solve(){
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i){
        string ss;
        getline(cin, ss);
        stringstream s(ss);
        string num;
        while(s >> num)
            a[i].push_back(stoi(num));
    }
    memset(dp, -1, sizeof(dp));
    tar = (1 << n) - 1;
    cout << ans(1, 0) << '\n';
    for(int i = 0; i < n; ++i)
        a[i].clear();
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
