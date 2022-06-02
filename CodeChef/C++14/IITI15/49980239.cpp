#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, q, a[N], fenwick[N], block = 317, ans, res[N];

struct st{
    int l, r, idx;
};

bool cmp(st a, st b){
    if(a.l/block == b.l/block)
        return a.r < b.r;
    return a.l < b.l;
}

void update(int node, int val){
    for(int i = node; i < N; i += (i & -i))
        fenwick[i] += val;
}

int get(int x){
    int ans = 0;
    for(int i = x; i >= 1; i -= (i & -i))
        ans += fenwick[i];
    return ans;
}

void remove_L(int node){
    int x = get(a[node] - 1);
    ans -= x;
    update(a[node], -1);
}

void add_L(int node){
    int x = get(a[node] - 1);
    ans += x;
    update(a[node], 1);
}

void remove_R(int node){
    int x = get(100006) - get(a[node]);
    ans -= x;
    update(a[node], -1);
}

void add_R(int node){
    int x = get(100006) - get(a[node]);
    ans += x;
    update(a[node], 1);
}

void solve(){
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        v[i - 1].first = a[i];
        v[i - 1].second = i;
    }
    sort(v.begin(), v.end());
    a[v[0].second] = 1;
    int ct = 1;
    for(int i = 1; i < n; ++i){
        if(v[i].first != v[i - 1].first)
            ++ct;
        a[v[i].second] = ct;
    }
    cin >> q;
    st queries[q + 1];
    for(int j = 1; j <= q; ++j){
        cin >> queries[j].l >> queries[j].r;
        queries[j].idx = j;
    }
    sort(queries + 1, queries + q + 1, cmp);
    int str = 1, end1 = 1;
    for(int j = 1; j <= q; ++j){
        int lft = queries[j].l, rgt = queries[j].r, x = queries[j].idx;
        // cout << str << " " << lft << " " << end1 << " " << rgt << "\n";
        while(str < lft){
            remove_L(str);
            // cout << str << "\n";
            ++str;
        }
        while(str > lft){
            --str;
            add_L(str);
        }
        while(end1 <= rgt){
            add_R(end1);
            ++end1;
        }
        while(end1 > rgt + 1){
            --end1;
            remove_R(end1);
        }
        res[x] = ans;
    }
    for(int i = 1; i <= q; ++i)
        cout << res[i] << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}