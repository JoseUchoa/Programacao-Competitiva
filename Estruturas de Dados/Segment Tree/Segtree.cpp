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

int n,m,v[MAXN],tree[4*MAXN]; 
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
	int t,a,b;
	
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>v[i];
	build(1,0,n-1);
	for(int i=0; i<m; i++) {
		cin>>t>>a>>b;
		if(t == 1) {
			update(1,0,n-1,a,b);
		} else {
			cout<<query(1,0,n-1,a,b-1)<<endl;
		}
	}
	return 0;
}