#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1001, M = 1001;
ll n, m, a[N][M], cnt, ans, ans1, box;

void go(int idx, int id){
    if(idx < 0 || idx >= n || id < 0 || id >= m || a[idx][id] != box){
        if(cnt > ans){
            ans = cnt;
            ans1 = box;
        }
        if(cnt == ans){
            ans = cnt;
            ans1 = min(ans1, box);
        }
        return;
    }
    ++cnt;
    a[idx][id] = 0;
    go(idx + 1, id);
    go(idx - 1, id);
    go(idx, id + 1);
    go(idx, id - 1);
}

int main(){
    fast;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j] == 0) continue;
            box = a[i][j];
            go(i, j);
            cnt = 0;
        }
    }
    cout << ans1 << " " << ans;
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}