#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, a[N];
vector<int> seg_tree[4 * N];

vector<int> merge(vector<int> l, vector<int> r){
    vector<int> ans;
    int i = 0, j = 0;
    if(l.size() > r.size())
        swap(l, r);
    // l is shorter.
    while(i < l.size() and j < r.size()){
        if(l[i] <= r[j]){
            ans.push_back(l[i]);
            ++i;
        }
        else{
            ans.push_back(r[j]);
            ++j;
        }
    }
    while(i < l.size()){
        ans.push_back(l[i]);
        ++i;
    }
    while(j < r.size()){
        ans.push_back(r[j]);
        ++j;
    }
    return ans;
}


void build(int vertex, int l, int r){
    if(r < l)
        return;
    if(l == r) {
        seg_tree[vertex].push_back(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * vertex, l, mid);
    build(2 * vertex + 1, mid + 1, r);
    seg_tree[vertex] = merge(seg_tree[2 * vertex], seg_tree[2 * vertex + 1]);
}

int query(int vertex, int l, int r, int str, int end, int find){
    if(l > end or r < str)
        return 0;
    if(l >= str and r <= end){
        int ok = -1, low = 0, high = seg_tree[vertex].size();
        while(low <= high){
            int mid = (low + high) / 2;
            if(seg_tree[vertex][mid] >= find){
                ok = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(ok == -1)
            return 0;
        return seg_tree[vertex].size() - ok;
    }
    int mid = (l + r) / 2;
    int ans = query(2 * vertex, l, mid, str, end, find);
    ans += query(2 * vertex + 1, mid + 1, r, str, end, find);
    return ans;
}

int main(){
    fast;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    build(1, 0, n - 1);
    cout << "1\n";
    for(int i = 1; i < n; ++i)
        cout << query(1, 0, n - 1, 0, i - 1, a[i]) + 1 << '\n';
    return 0;
}