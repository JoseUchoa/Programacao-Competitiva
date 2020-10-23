#include<bits/stdc++.h>
#define endl '\n'
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define ok cerr<<"OK"<<endl
#define bb binary_search
#define all(A) A.begin(),A.end()
#define fi first
#define se second
#define int long long
using namespace std;

#define MAXN 100000

struct item {
	int sum,seg,pref,suf;
};

int n,m,v[MAXN];
item tree[4*MAXN];

item merge(item a, item b) {
	return {
		a.sum + b.sum,							//sum
		max(a.seg, max(b.seg, a.suf + b.pref)),	//seg
		max(a.pref, a.sum + b.pref),			//pref
		max(b.suf, b.sum + a.suf)				//suf
	};
}

item single(int v) {
	if(v > 0) return {v,v,v,v};
	else return {v,0,0,0};
}

void build(int node, int l, int r) {
	if(l == r) tree[node] = single(v[l]);
	else {
		int m = (l+r)/2;
		build(2*node,l,m);
		build(2*node+1,m+1,r);
		tree[node] = merge(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int l, int r, int idx, int x) {
	if(l == r) tree[node] = single(x);
	else {
		int m = (l+r)/2;
		if(idx <= m) update(2*node,l,m,idx,x);
		else update(2*node+1,m+1,r,idx,x);
		tree[node] = merge(tree[2*node], tree[2*node+1]);
	}
}

item query(int node, int l, int r, int lx, int rx) {
	if(r < lx || l > rx) return {0,0,0,0};
	if(l >= lx && r <= rx) return tree[node];
	int m = (l+r)/2;
	item ql = query(2*node,l,m,lx,rx);
	item qr = query(2*node+1,m+1,r,lx,rx);
	return merge(ql,qr);
}
int32_t main() {
	int t,a,b;
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>v[i];
	build(1,0,n-1);
	cout<<query(1,0,n-1,0,n-1).seg<<endl;
	for(int i=0; i<m; i++) {
		int a,b;
		cin>>a>>b;
		update(1,0,n-1,a,b);
		cout<<query(1,0,n-1,0,n-1).seg<<endl;
	}
	return 0;
}