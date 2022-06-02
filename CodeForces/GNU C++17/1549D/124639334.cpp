#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, a[N], b[N], seg_tree1[N];

void build1(int vertex, int l, int r){
    if(l == r){
        seg_tree1[vertex] = b[l];
        return;
    }
    else{
        int mid = (l + r) / 2;
        build1(2 * vertex, l, mid);
        build1((2 * vertex) + 1, mid + 1, r);
        seg_tree1[vertex] = __gcd(seg_tree1[2 * vertex], seg_tree1[(2 * vertex) + 1]);
    }
}

ll gcd_query(int vertex, int l, int r, int x, int y){
    if(r < x || l > y || l > r) 
        return 0;
    if(x <= l && r <= y)
        return seg_tree1[vertex];
    int mid = (l + r) / 2;
    long long int ans = gcd_query(2 * vertex, l, mid, x, y);
    long long int ans1 = gcd_query((2 * vertex) + 1, mid + 1, r, x, y);
    return __gcd(ans, ans1);
}

bool check(int mid){
    for(int i = 2; i <= n - mid + 1; ++i)
        if(gcd_query(1, 1, n, i, i + mid - 1) > 1) return true;
    return false;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    if(n == 1){
        cout << "1\n";
        return;
    }
    for(int i = 1; i <= n; ++i)
        b[i] = abs(a[i] - a[i - 1]);
    b[1] = LLONG_MAX;
    build1(1, 1, n);
    ll low = 1, high = n - 1, ans = 1;
    while(low <= high){
        ll mid = (low + high) / 2;
        if(check(mid)){
            ans = mid + 1;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
