#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, fenwick_pre[N], fenwick_suf[N];

long long get(int node, bool which){
    long long ans = 0;
    if(!which){
        for(int i = node; i >= 1; i -= (i & -i))
            ans += fenwick_pre[i];
    }
    else{
        for(int i = node; i >= 1; i -= (i & -i))
            ans += fenwick_suf[i];
    }
    return ans;
}

void update(int node, int val, bool which){
    if(!which){
        for(int i = node; i <= N; i += (i & -i))
            fenwick_pre[i] += val;
    }
    else{
        for(int i = node; i <= N; i += (i & -i))
            fenwick_suf[i] += val;
    }
}

void solve(){
    cin >> n;
    long long ans = 0, pre = 0;
    for(int i = 1; i <= n; ++i){
        long long x;
        cin >> x;
        ans += ((i - 1) * x) + get(x, 0);
        for(int jump = x; jump < N; jump += x)
            update(jump, -x, 0);
        ans += pre;
        pre += x;
        for(int jump = x; jump < N; jump += x){
            int l = jump, r = min((long long) N, jump + x - 1);
            long long cur = get(r, 1) - get(l - 1, 1);
            ans -= (cur * jump/x * x);
        }
        update(x, 1, 1);
        cout << ans << ' ';
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
