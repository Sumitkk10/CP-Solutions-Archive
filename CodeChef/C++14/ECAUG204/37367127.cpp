#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t = 1;
	cin >> t;
	while(t--){
		ll n; cin >> n;
		ll a[n];
		map<int, int> mp;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			mp[a[i]]++;
		}
		sort(a,a+n);
        int i = 0;
        for(i=0;i<n-1;++i)
         {
             if(a[i]<a[i+1])
               continue;
               
             else
               break;
         }
         
         if(i==n-1)
           cout<<"Yes"<<endl;
           
         else
           cout<<"No"<<endl;
	}
	return 0;
}