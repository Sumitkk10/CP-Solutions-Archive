#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
map<int, int> mp;

void solve(){
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 3;
    mp[4] = 1;
    mp[5] = 3;
    mp[6] = 2;
    mp[7] = 1;
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for(int i = 1; i <= 7; ++i){
        // i start at this day;
        int how_1 = a / 3, how_2 = b / 2, how_3 = c / 2;
        int mn = min({how_1, how_3, how_2});
        int cur_a = a - 3*mn;
        int cur_b = b - 2*mn;
        int cur_c = c - 2*mn;
        int j = i;
        int ok = 7*mn;
        while(true){
            if(mp[j] == 1){
                if(cur_a > 0){
                    ++ok;
                    --cur_a;
                }
                else
                    break;
            }
            else if(mp[j] == 2){
                if(cur_b > 0){
                    ++ok;
                    --cur_b;
                }
                else
                    break;
            }
            else{
                if(cur_c > 0){
                    ++ok;
                    --cur_c;
                }
                else
                    break;
            }
            ++j;
            j = j%8;
            if(j == 0) ++j;
        }
        // cout << i << ' ' <<  ok << '\n';
        ans = max(ans, ok);
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
