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

int n,m,v[MAXN];
pii tree[4*MAXN]; 

pii merge(pii a, pii b) {
	if(a.fi < b.fi) return a;
	else if(a.fi > b.fi) return b;
	else return {a.fi, a.se + b.se};
}

pii single(int v) {
	return {v,1};
}

void build(int node, int l, int r) {
	if(l == r) tree[node] = single(v[l]);
	else {
		int m = (l+r)/2;
		build(2*node,l,m);
		build(2*node+1,m+1,r);
		tree[node] = merge(tree[2*node],tree[2*node+1]);
	}
}

void update(int node, int l, int r, int idx, int x) {
	if(l == r) tree[node] = {x,1};
	else {
		int m = (l+r)/2;
		if(idx <= m) update(2*node,l,m,idx,x);
		else update(2*node+1,m+1,r,idx,x);
		tree[node] = merge(tree[2*node],tree[2*node+1]);
	}
}

pii query(int node, int l, int r, int lx, int rx) {
	if(r < lx || l > rx) return {10000000000,1};
	if(l >= lx && r <= rx) return tree[node];
	int m = (l+r)/2;
	pii ql = query(2*node,l,m,lx,rx);
	pii qr = query(2*node+1,m+1,r,lx,rx);
	return merge(ql,qr); 
}

int32_t main() {
	int t,a,b;
	
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>v[i];
	build(1,0,n-1);
	for(int i=0; i<m; i++) {
		cin>>t>>a>>b;
		if(t == 1) {
			update(1,0,n-1,a,b);
		} else {
			pii ans = query(1,0,n-1,a,b-1); 
			cout<<ans.fi<<" "<<ans.se<<endl;
		}
	}
	return 0;
}