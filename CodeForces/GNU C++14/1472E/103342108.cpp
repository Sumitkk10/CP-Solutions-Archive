#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
pair<long long int, pair<long long int, long long int> > persons[N], persons1[N];
int n, seg_tree[4 * N], seg_tree1[4 * N];

void build(int vertex, int l, int r){
    if(l == r)
        seg_tree[vertex] = persons[l].second.first;
    else{
        int mid = (l + r) / 2;
        build(2 * vertex, l, mid);
        build((2 * vertex) + 1, mid + 1, r);
        seg_tree[vertex] = min(seg_tree[2 * vertex], seg_tree[(2 * vertex) + 1]);
    }
}

void build1(int vertex, int l, int r){
    if(l == r)
        seg_tree1[vertex] = persons1[l].second.first;
    else{
        int mid = (l + r) / 2;
        build1(2 * vertex, l, mid);
        build1((2 * vertex) + 1, mid + 1, r);
        seg_tree1[vertex] = min(seg_tree1[2 * vertex], seg_tree1[(2 * vertex) + 1]);
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

ll min_query1(int vertex, int l, int r, int x, int y){
    if(r < x || l > y || l > r) 
        return INT_MAX;
    if(x <= l && r <= y)
        return seg_tree1[vertex];
    int mid = (l + r) / 2;
    long long int ans = min_query1(2 * vertex, l, mid, x, y);
    long long int ans1 = min_query1((2 * vertex) + 1, mid + 1, r, x, y);
    return min(ans, ans1);
}


void solve(){
    int n;
    cin >> n;   
    map<ll, pair<ll, ll> > mp, mp1;
    for(int i = 0; i < n; ++i){
        long long int w, h;
        cin >> h >> w;
        persons[i].first = h;
        persons[i].second.first = w;
        persons[i].second.second = i + 1;
        persons1[i].second.first = h;
        persons1[i].first = w;
        persons1[i].second.second = i + 1;
        if(!mp[h].second)
            mp[h] = {w, i + 1};
        if(!mp1[w].second)
            mp1[w] = {h, i + 1};
        if(mp[h].first > w)
            mp[h] = {w, i + 1};
        if(mp1[w].first > h)
            mp1[w] = {h, i + 1};
    }
    sort(persons, persons + n);
    sort(persons1, persons1 + n);
    build(1, 0, n - 1), build1(1, 0, n - 1);
    vector<int> ans(n + 1, 0);
    for(int i = 0; i < n; ++i){
        int id = persons[i].second.second;
        if(i - 1 >= 0){
            int low = 0, high = i - 1, idx = -1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(persons[mid].first < persons[i].first){
                    idx = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            if(idx != -1){
                ll mnn = min_query(1, 0, n - 1, 0, idx);
                if(mnn < persons[i].second.first)
                    ans[id] = mp1[mnn].second;
            }
        }
        if(!ans[id]){
            int low = 0, high = n - 1, idx = -1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(persons1[mid].first < persons[i].first){
                    idx = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            if(idx != -1){
                ll mnn = min_query1(1, 0, n - 1, 0, idx);
                if(mnn < persons[i].second.first)
                    ans[id] = mp[mnn].second;
            }
        }
        if(!ans[id])
            ans[id] = -1;
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    for(int i = 0; i < 4 * n; ++i)
        seg_tree[i] = seg_tree1[i] = 0;
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}