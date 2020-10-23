#include<bits/stdc++.h>
#define all(A) A.begin(),A.end()
#define mset(A,X) memset(A,X,sizeof A)
#define endl '\n'
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define ok cerr<<"OK"<<endl
#define bb binary_search
#define fi first
#define se second
#define inf INT_MAX/2 //LLONG_MAX
#define MAXN 100005
using namespace std;

int n,v[MAXN], tree[4*MAXN]; 

void build(int node, int l, int r) {
	if(l == r) tree[node] = v[l];
	else {
		int m = (l+r)/2;
		build(2*node,l,m);
		build(2*node+1,m+1,r);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

void update(int node, int l, int r, int idx, int x) {
	if(l == r) tree[node] = x;
	else {
		int m = (l+r)/2;
		if(idx <= m) update(2*node,l,m,idx,x);
		else update(2*node+1,m+1,r,idx,x);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node, int l, int r, int lx, int rx) {
	if(r < lx || l > rx) return 0;
	if(l >= lx && r <= rx) return tree[node];
	int m = (l+r)/2;
	int ql = query(2*node,l,m,lx,rx);
	int qr = query(2*node+1,m+1,r,lx,rx);
	return ql + qr;
}

int32_t main() {
	int x;
	cin>>n;
	int ans = 0;
	for(int i=1; i<=n; i++) {
		cin>>x;
		cout<<query(1,1,n,x,n)<<" ";
		update(1,1,n,x,1);
	}
	cout<<endl;

	return 0;
}
