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
    int a[n + 1];
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    int chance = 0;
    while(mp.size() != 1){
        int mx = 0, mx2 = 0, cur, cur2;
        for(auto k : mp){
            if(k.second > mx){
                mx2 = mx;
                cur2 = cur;
                mx = k.second;
                cur = k.first;
            }
            else if(k.second > mx2){
                mx2 = k.second;
                cur2 = k.first;
            }
        }
        if(cur == cur2)
            break;
        mp[cur] += mx2;
        mp.erase(cur2);
        ++chance;
    }
    cout << (chance % 2 == 0 ? "Raju\n" : "Aman\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
