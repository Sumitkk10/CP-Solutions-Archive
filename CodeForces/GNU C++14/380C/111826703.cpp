#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
string s;

struct ok{
	int ans, l, r;
};

ok seg_tree[4 * N];

void build(int vertex, int l, int r){
	if(l == r){
		seg_tree[vertex].ans = 0;
		if(s[l] == '('){
			seg_tree[vertex].l = 1;
			seg_tree[vertex].r = 0;
 		}
 		else{
 			seg_tree[vertex].l = 0;
 			seg_tree[vertex].r = 1;
		}
		return;
	}
	int mid = (l + r) / 2;
	build(2 * vertex, l, mid);
	build(2 * vertex + 1, mid + 1, r);
	int xtra = min(seg_tree[2 * vertex].l, seg_tree[2 * vertex + 1].r);
	seg_tree[vertex].ans = seg_tree[2 * vertex].ans + seg_tree[2 * vertex + 1].ans + 2*xtra;
	seg_tree[vertex].l = seg_tree[2 * vertex].l + seg_tree[2 * vertex + 1].l - xtra;
	seg_tree[vertex].r = seg_tree[2 * vertex].r + seg_tree[2 * vertex + 1].r - xtra;
}

ok query(int vertex, int l, int r, int x, int y){
	if(l > y or r < x)
		return {0, 0, 0};
	if(l >= x and r <= y){
		return seg_tree[vertex];
	}
	int mid = (l + r) / 2;
	ok lq = query(2 * vertex, l, mid, x, y), rq = query(2 * vertex + 1, mid + 1, r, x, y);
	int wow = min(lq.l, rq.r);
	ok cur = {lq.ans + rq.ans + 2*wow, lq.l + rq.l - wow, lq.r + rq.r - wow};
	return cur;
}

void solve(){
	cin >> s;

	// we will construct a seg tree in which range l..r contains the maximum correct bracket subsequence.

	build(1, 0, s.size() - 1);

	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << query(1, 0, s.size() - 1, l, r).ans << "\n";
	}
}

int main(){
    fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}