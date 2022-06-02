#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int ans[N], n, fenwick[N];

int update(int node, int upd){
    for(int i = node; i <= n; i += (i & -i))
        fenwick[i] += upd;
}

int sum(int node){
    int ok = 0;
    for(int i = node; i >= 1; i -= (i & -i))
        ok += fenwick[i];
    return ok;
}

int query(int i){
    cout << "? 1 " << i << endl;
    int x;
    cin >> x;
    return x;
}

int solve(int k){
    int low = 1, high = n, cur;
    while(low <= high){
        int mid = (low + high) / 2, ones = 0;
        if(ans[mid] != -1){
            ones = ans[mid] + sum(mid);
        }
        else{
            ones = query(mid);
            ans[mid] = ones - sum(mid);
        }
        if(mid - ones >= k){
            cur = mid;
            high = mid - 1; 
        }
        else
            low = mid + 1;
    }
    update(cur, 1);
    return cur;
}

int main(){
    fast;
    int t;
    cin >> n >> t;
    memset(ans, -1, sizeof ans);
    while(t--){
        int k;
        cin >> k;
        cout << "! " << solve(k) << endl;
    }
    return 0;
}
