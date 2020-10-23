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
#define inf INT_MAX/2 //LLONG_MAX em caso de long long
#define int long long
#define MAXN 100005
using namespace std;

int n,v[MAXN],tree[4*MAXN];

void build(int node, int l, int r) {
	if(l == r) tree[node] = 1;
	else {
		int m = (l+r)/2;
		build(2*node,l,m);
		build(2*node+1,m+1,r);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

void update(int node, int l, int r, int idx) {
	if(l == r) tree[node] = (tree[node] == 0);
	else {
		int m = (l+r)/2;
		if(idx <= m) update(2*node,l,m,idx);
		else update(2*node+1,m+1,r,idx);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node, int l, int r, int k) {
	if(l == r) {
		update(1,0,n-1,l);
		return n-l;
	}
	int m = (l+r)/2;
	if(k < tree[2*node]) return query(2*node,l,m,k);
	return query(2*node+1,m+1,r,k-tree[2*node]);
}

int32_t main() {
	cin>>n;
	build(1,0,n-1);
	for(int i=1; i<=n; i++) cin>>v[i];
	for(int i=n; i>0; i--) {
		v[i] = query(1,0,n-1,v[i]);
	}
	for(int i=1; i<=n; i++) cout<<v[i]<<' ';
	cerr<<endl;

	return 0;
}