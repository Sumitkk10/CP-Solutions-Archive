#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
    fast;
    int n, t;
    cin >> n >> t;
    while(t--){
        int k, x;
        cin >> k;
        int low = 1, high = n, cur = 0, ans;
        while(low <= high){
            int mid = (low + high) / 2;
            cout << "? " << low << ' ' << mid << endl;
            cin >> x;
            if(cur + (mid - low + 1 - x) >= k){
                ans = mid;
                high = mid - 1;
            }
            else if(cur + (mid - low + 1 - x) < k){
                cur += (mid - low + 1 - x);
                low = mid + 1;
            }
        }
        cout << "! " << ans << endl;
    }
    return 0;
}
