#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    long long int a[n];
    vector<long long int> even, odd;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] % 2)
        	odd.push_back(a[i]);
    	else
    		even.push_back(a[i]);
    }
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());
    long long int i = 0, j = 0, alice = 0, bob = 0, cnt = 0;
    while(i < even.size() or j < odd.size()){
    	if(cnt % 2){
    		if(j >= odd.size())
    			++i;
    		else if(i >= even.size()){
    			bob += odd[j];
    			++j;
    		}
    		else if(odd[j] >= even[i]){
    			bob += odd[j];
    			++j;
    		}
    		else
    			++i;
    	}
    	else{
    		if(j >= odd.size()){
    			alice += even[i];
    			++i; 
    		}
    		else if(i >= even.size())
    			++j;
    		else if(even[i] >= odd[j]){
    			alice += even[i];
    			++i;
    		}
    		else
    			++j;
    	}
    	++cnt;
    }
   	if(alice == bob){
   		cout << "Tie\n";
   		return;
   	}
   	cout << (alice > bob ? "Alice\n" : "Bob\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
