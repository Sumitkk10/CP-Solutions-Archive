#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

void solve(){
    int n;
    cin >> n;
    int l = 1, r = n;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        int x = query(l, r);
        if(x < mid){
            int xx = query(l, mid);
            if(xx == x)
                r = mid;
            else
                l = mid;
        }
        else{
            int xx = query(mid, r);
            if(xx == x) l = mid;
            else r = mid;
        }
    }
    int ans = query(l, r);
    if(ans == l) ans = r;
    else    ans = l;
    cout << "! " << ans << endl;
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
