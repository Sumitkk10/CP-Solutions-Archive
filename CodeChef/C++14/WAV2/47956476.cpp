#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, q;
    cin >> n >> q;
    long long a[n + 1], pos = 0, neg = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    while(q--){
        long long x;
        cin >> x;
        int low = 1, high = n, ok = n + 1;
        bool wut = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(a[mid] == x){
                wut = 1;
                break;
            }
            else if(a[mid] > x){
                ok = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(wut) cout << "0\n";
        else{
            long long neg = n - ok + 1;
            long long pos = ok - 1;
            cout << (neg % 2 == 0 ? "POSITIVE\n" : "NEGATIVE\n");
        }
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
