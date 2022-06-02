#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
bool vis[N];

void solve(){
    int n;
    cin >> n;
    set<int> s;
    int a[n];
    for(int i = 1; i <= n; ++i)
        vis[i] = false;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        vis[a[i]] = true;
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            s.insert(i);
    int i = 0;
    cout << a[i] << ' ';
    ++i;
    while(i < n){
        if(a[i] == a[i - 1]){
            cout << *s.begin() << ' ';
            s.erase(*s.begin());
        }
        else
            cout << a[i] << ' ';
        ++i;
    }
    cout << "\n";
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            s.insert(i);
    i = 0;
    cout << a[i] << ' ';
    ++i;
    while(i < n){
        if(a[i] == a[i - 1]){
            cout << *(--s.lower_bound(a[i])) << ' ';
            s.erase(*(--s.lower_bound(a[i])));
        }
        else
            cout << a[i] << ' ';
        ++i;
    }
    cout << "\n";
}

int main(){
     fast;
	long long int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}