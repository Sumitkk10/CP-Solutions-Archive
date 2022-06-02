#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;

ll binary_search(ll n, ll m, vector<ll>& a, ll val){
    int low = n, high = m;
    while(low < high){
        int mid = (low+high)/2;
        if(a[mid] == val)
            return mid;
        else if(a[mid] > val)
            high = mid;
        else
            low = mid + 1;
    }
    return -1;
}

int main(){
    fast;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0, cnt = 0;
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            cnt = 0;
            ll diff = a[j] - a[i];
            ++cnt;
            ll k = a[i] + ((cnt+1)*diff);
            ll e = binary_search(j, n, a, k);
            // cout << e << ' ';
            while(e != -1){
                ++cnt;
                k = a[i] + ((cnt+1)*diff);
                e = binary_search(e, n, a, k);
            }
            ans = max(ans, cnt+1);
        }
    }
    cout << ans;
    return 0;
}
//                                      **!!_Sumit_!!**