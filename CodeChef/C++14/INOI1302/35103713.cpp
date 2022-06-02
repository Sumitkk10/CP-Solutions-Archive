#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const ll MOD = 1e9 + 7, N = 302;
vii a[N], len;
map<ll, ll> mp;

int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        ll p;
        cin >> p;
        len.pb(p);
        for(int j = 0; j < p; ++j){
            ll x;
            cin >> x;
            a[i].pb(x);
        }
        sort(a[i].begin(), a[i].end());
    }
    vii cnt;
    cnt.pb(0);
    for(ll t = 0; t < cnt.size(); ++t){
        int eq = 0, idx = 1;
        while(true){
            for(int i = 0; i < len[cnt[t]]; ++i){   
                int pnt = 0;
                if(cnt[t] == idx) continue;
                int low = 0, high = len[idx] - 1;
                while(low <= high){
                    int mid = (low + high)/2;
                    if(a[cnt[t]][i] == a[idx][mid]){
                        ++pnt;
                        break;
                    }
                    if(a[cnt[t]][i] > a[idx][mid])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                if(pnt > 0)
                    ++eq;
            }
            if(eq >= k && mp[idx] == 0){
                cnt.pb(idx);
                mp[idx]++;
            }
            ++idx;
            eq = 0;
            if(idx >= n)
                break;
        }
    }
    cout << cnt.size();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}