#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, seg_tree[4 * N];
vector<int> a(N), ans(N);

void update(int vertex, int l, int r, int str, int upd){
    if(r < str or l > str)
        return;
    if(l == str and r == str){
        seg_tree[vertex] += upd;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * vertex, l, mid, str, upd);
    update(2 * vertex +  1, mid + 1, r, str, upd);
    seg_tree[vertex] = seg_tree[2 * vertex] + seg_tree[2 * vertex + 1];
}

int query(int vertex, int l, int r, int str, int end){
    if(l > end or r < str)
        return 0;
    if(l >= str and r <= end)
        return seg_tree[vertex];
    int mid = (l + r) / 2;
    int ans = query(2 * vertex, l, mid, str, end);
    ans += query(2 * vertex + 1, mid + 1, r, str, end);
    return ans;
}

int main(){
    fast;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = n; i >= 1; --i){
        int x = a[i];
        int low = 1, high = n;
        while(low <= high){
            int mid = (low + high) / 2;
            if((n - mid) - query(1, 1, n, mid + 1, n) == x){
                if(!ans[mid]){
                    ans[mid] = i;
                    update(1, 1, n, mid, 1);
                    break;
                }
                else
                    high = mid - 1;
            }
            if((n - mid) - query(1, 1, n, mid + 1, n) > x)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}