#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e7 + 5;
bool prime[N];
vector<int> ok;

void sieve(){
	for(int i = 2; i <= N; ++i){
		if(!prime[i]){
			for(int j = i + i; j <= N; j += i)
				prime[j] = true;
			ok.push_back(i);
		}
	}
}

void solve(){
	int n;
	cin >> n;
  	if(n == 2){
      	cout << "1\n";
      	return;
    }
  	if(n == 3){
      	cout << "2\n";
      	return;
    }
	int low = 0, high = ok.size() - 1, cur = ok.size() - 1;
	while(low <= high){
		int mid = (low + high) / 2;
      	if(ok[mid] > n)
          	high = mid - 1;
		else if(ok[mid]*2 > n){
			cur = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	low = 0, high = ok.size() - 1;
	int cur1 = ok.size();
	while(low <= high){
		int mid = (low + high) / 2;
		if(ok[mid] > n){
			cur1 = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << cur1 - cur + 1 << '\n';
}

int main() {
	fast;
	sieve();
	int t = 1;
 	cin >> t;
	while(t--)
		solve();
	return 0;
}