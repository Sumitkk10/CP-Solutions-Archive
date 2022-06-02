#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n;
	cin >> n;
	map<string, int> scores;
	for(int i = 0; i < n; ++i){
		string s;
		int score;
		cin >> s >> score;
		scores[s] = max(scores[s], score);
	}
	cout << scores.size() << '\n';
	for(auto k : scores){
		int his_score = k.second;
		int cnt = 0;
		cout << k.first << ' ';
		for(auto kk : scores)
			cnt += (kk.second <= his_score); 
		string ans;
		if (cnt * 100 < 50 * scores.size()) ans = "noob";
		else if (cnt * 100 < 80 * scores.size()) ans = "random";
		else if (cnt * 100 < 90 * scores.size()) ans = "average";
		else if (cnt * 100 < 99 * scores.size()) ans = "hardcore";
		else if (cnt * 100 >= 99 * scores.size()) ans = "pro";
		cout << ans << '\n';
	}
	return 0;
}
//								Worst Problem Ever!!