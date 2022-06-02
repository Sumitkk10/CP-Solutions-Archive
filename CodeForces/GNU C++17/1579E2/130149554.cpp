#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int fenwick[N], ct;

void upd(int node, int val){
    for(int i = node; i <= ct; i += (i & -i))
        fenwick[i] += val;
}

int query(int node){
    long long int sum = 0;
    for(int i = node; i >= 1; i -= (i & -i))
        sum += fenwick[i];
    return sum;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    /*
    now the values can be upto 10^9 but observe that we don't really need values 
    so we can compress the values to uptil 10^6.
    */
    vector<pair<int, int> > comp;
    for(int i = 0; i < a.size(); ++i)
        comp.push_back({a[i], i});
    sort(comp.begin(), comp.end());
    ct = 1;
    a[comp[0].second] = ct;
    for(int i = 1; i < comp.size(); ++i){
        if(comp[i].first != comp[i - 1].first)
            ++ct;
        a[comp[i].second] = ct;
    }
    for(int i = 0; i <= ct; ++i)
        fenwick[i] = 0;
    long long ans = 0;
    map<int, int> mp;
    mp[a[0]]++;
    upd(a[0], 1);
    for(int i = 1; i < n; ++i){
        int x = query(a[i] - 1);
        int xx = i - x - mp[a[i]];
        ans += min(x, xx);
        upd(a[i], 1);
        mp[a[i]]++;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
