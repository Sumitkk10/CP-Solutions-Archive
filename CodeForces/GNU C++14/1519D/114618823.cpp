#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const long long int N = 5005;
long long int n, a[N], b[N], pro[N][N];

long long go(int l, int r){
    if(l > r) 
        return pro[l][r] = 0;
    if(l == r)
        return pro[l][r] = a[l]*b[r];
    return pro[l][r] = ((a[l] * b[r]) + (b[l] * a[r]) + go(l + 1, r - 1));
}


int main(){
    fast;
    cin >> n;
    long long pre[n + 1], suf[n + 2];
    pre[0] = 0, suf[n + 1] = 0; 
    long long mx = 0;
    memset(pro, -1, sizeof pro);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        mx += (a[i] * b[i]);
        pre[i] = pre[i - 1] + (a[i] * b[i]);
    }
    for(int i = n; i >= 1; --i)
        suf[i] = suf[i + 1] + (a[i] * b[i]);
    go(1, n);
    for(int l = 1; l <= n; ++l){
        for(int r = l; r <= n; ++r){
            if(pro[l][r] == -1)
                go(l, r);
            if(pre[l - 1] + suf[r + 1] + pro[l][r] > mx)
                mx = pre[l - 1] + suf[r + 1] + pro[l][r];
        }
    }
    cout << mx << '\n';
    return 0;
}