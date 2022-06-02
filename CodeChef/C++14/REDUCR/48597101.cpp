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
    long long first = 500, ok = 1, cur = 2;
    while(ok < n){
        if(ok <= 2)
            first--;
        else{
            long long cur1 = (cur*cur*cur);
            int how = 2;
            while(how--){
                if(ok >= n) break;
                first -= cur1;
                cur1 /= cur;
                ++ok;
            }
            ++cur;
            continue;
        }
        ++ok;
    }
    cout << first << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
