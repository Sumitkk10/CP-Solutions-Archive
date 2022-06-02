#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long int n, m, x, y;
    cin >> n >> m >> x >> y;
    long long dis = abs(x - 1) + abs(y - 1), dis1 = abs(x - 1) + abs(y - m);
    long long dis2 = abs(x - n) + abs(y - 1), dis3 = abs(x - n) + abs(y - m);
    set<pair<long long int, pair<long long int, int> > > s, s1; 
    vector<pair<long long int, pair<long long int, int> > > a, a1;
    s.insert({dis, {1, 1}});
    s.insert({dis1, {1, m}});
    s.insert({dis2, {n, 1}});
    s.insert({dis3, {n, m}});
    for(auto k : s)
        a.push_back(k);
    long long int mx = 0, sec_mx = 0, idx1, idx2;
    if(a.size() <= 1){
        cout << "1 1 1 1\n";
        return;
    }
    for(int i = 0; i < a.size(); ++i){
        if(a[i].first >= mx){
            sec_mx = mx;
            mx = a[i].first;
            idx2 = idx1;
            idx1 = i;
        }
        else if(a[i].first > sec_mx){
            sec_mx = a[i].first;
            idx2 = i;
        }
    }
    cout << a[idx1].second.first << ' ' << a[idx1].second.second << ' ';
    long long x1 = x, y1 = y;
    x = a[idx1].second.first;
    y = a[idx1].second.second;
    dis = abs(x - 1) + abs(y - 1) + abs(1 - x1) + abs(1 - y1), dis1 = abs(x - 1) + abs(y - m) + abs(1 - x1) + abs(m - y1);
    dis2 = abs(x - n) + abs(y - 1) + abs(n - x1) + abs(1 - y1), dis3 = abs(x - n) + abs(y - m) + abs(n - x1) + abs(m - y1);
    s1.insert({dis, {1, 1}});
    s1.insert({dis1, {1, m}});
    s1.insert({dis2, {n, 1}});
    s1.insert({dis3, {n, m}});
    for(auto k : s1)
        a1.push_back(k);
    mx = 0, sec_mx = 0, idx1, idx2;
    for(int i = 0; i < a1.size(); ++i){
        if(a1[i].first >= mx){
            mx = a1[i].first;
            idx1 = i;
        }
    }
    cout << a1[idx1].second.first << ' ' << a1[idx1].second.second << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
