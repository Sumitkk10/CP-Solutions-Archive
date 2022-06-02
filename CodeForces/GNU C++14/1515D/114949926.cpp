#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    int col[n];
    for(int i = 0; i < n; ++i)
        cin >> col[i];
    if(l <= r){
        int ans = 0;
        map<int, int> mp, right;
        ans += abs(n/2 - l);
        int left =  abs(n/2 - l);
        for(int i = 0; i < l; ++i)
            mp[col[i]]++;
        for(int i = l; i < n; ++i)
            right[col[i]]++;
        for(int i = l; i < n; ++i){
            if(mp[col[i]] > 0){
                mp[col[i]]--;
                right[col[i]]--;
            }
        }
        for(auto k : right){
            if(k.second % 2){
                for(int i = 0; i < k.second - 1; ++i){
                    if(mp[k.first] > 0)
                        mp[k.first]--;
                    else if(left){
                        left--;
                        mp[k.first]++;
                    }
                }
            }
            else{
                for(int i = 0; i < k.second; ++i){
                    if(mp[k.first] > 0)
                        mp[k.first]--;
                    else if(left){
                        left--;
                        mp[k.first]++;
                    }
                }
            }
        }
        ans += left;
        for(auto k : mp)
            ans += k.second;
        cout << ans << '\n';
    }
    else{
        int ans = 0;
        map<int, int> mp, lft;
        ans += abs(n/2 - l);
        int left =  abs(n/2 - l);
        for(int i = l; i < n; ++i)
            mp[col[i]]++;
        for(int i = 0; i < l; ++i)
            lft[col[i]]++;
        for(int i = 0; i < l; ++i){
            if(mp[col[i]] > 0){
                mp[col[i]]--;
                lft[col[i]]--;
            }
        }
        for(auto k : lft){
            if(k.second % 2){
                for(int i = 0; i < k.second - 1; ++i){
                    if(mp[k.first] > 0)
                        mp[k.first]--;
                    else if(left){
                        left--;
                        mp[k.first]++;
                    }
                }
            }
            else{
                for(int i = 0; i < k.second; ++i){
                    if(mp[k.first] > 0)
                        mp[k.first]--;
                    else if(left){
                        left--;
                        mp[k.first]++;
                    }
                }
            }
        }
        ans += left;
        for(auto k : mp)
            ans += k.second;
        cout << ans << '\n';
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
