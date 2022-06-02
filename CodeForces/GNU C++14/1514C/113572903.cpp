#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
    fast;
    int n;
    cin >> n;
    long long pro = 1;
    vector<int> ans;
    for(int i = 1; i <= n - 1; ++i){
        if(__gcd(i, n) == 1){
            pro *= i;
            pro %= n;
            ans.push_back(i);
        }
    }
    if(pro != 1){
        cout << ans.size() - 1 << '\n';
        for(auto k : ans){
            if(k == pro) continue;
            cout << k << ' ';
        }
        return 0;
    }
    cout << ans.size() << '\n';
    for(auto k : ans)
        cout << k << ' ';
    return 0;
}
