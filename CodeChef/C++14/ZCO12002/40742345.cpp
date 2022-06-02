#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll seg_tree[4*N];
pair<int, int> a[N];

void build(int vertex, int l, int r){
    if(l == r)
        seg_tree[vertex] = a[l].second;
    else{
        int mid = (l + r) / 2;
        build(2 * vertex, l, mid);
        build((2 * vertex) + 1, mid + 1, r);
        seg_tree[vertex] = min(seg_tree[2 * vertex], seg_tree[(2 * vertex) + 1]);
    }
}

ll min_query(int vertex, int l, int r, int x, int y){
    if(r < x || l > y || l > r) 
        return INT_MAX;
    if(x <= l && r <= y)
        return seg_tree[vertex];
    int mid = (l + r) / 2;
    long long int ans = min_query(2 * vertex, l, mid, x, y);
    long long int ans1 = min_query((2 * vertex) + 1, mid + 1, r, x, y);
    return min(ans, ans1);
}

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    int v[x], w[y];
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    for(int i = 0; i < x; ++i)
        cin >> v[i];
    for(int i = 0; i < y; ++i)
        cin >> w[i];
    sort(a, a + n);
    sort(v, v + x);
    sort(w, w + y);
    build(1, 0, n - 1);
    // 5 10
    // 7 25
    // 15 21
    // 2 4 14 25
    // 13 21
    int ans = INT_MAX;
    for(int i = 0; i < x; ++i){
        int low = 0, high = n - 1, idx = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(a[mid].first >= v[i]){
                idx = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        } 
        if(idx == -1) continue;
        int mn = min_query(1, 0, n - 1, idx, n - 1);
        low = 0, high = y - 1, idx = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(w[mid] >= mn){
                idx = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(idx == -1) continue;
        ans = min(ans, w[idx] - v[i] + 1);
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
