#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;

void solve(){
    string a, b;
    cin >> a >> b;
    int mn = INT_MAX;
    for(int i = 0; i < a.size(); ++i){
        int rem = a.size() - i - 1;
        for(int k = rem; k >= 0; --k){
            string cur;
            for(int j = i; j <= i + k; ++j)
                cur.push_back(a[j]);
            if(b.find(cur) != string::npos)
                mn = min(mn, (int) (a.size() - cur.size() + b.size() - cur.size()));
        }
    }
    cout << min(mn, (int) (a.size() + b.size())) << "\n";
}

int main(){
    fast;
	long long int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}