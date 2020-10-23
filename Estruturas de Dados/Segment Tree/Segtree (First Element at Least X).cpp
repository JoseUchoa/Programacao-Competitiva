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
using namespace std;

#define MAXN 100000

int n,m,v[MAXN],tree[4*MAXN];

void build(int node, int l, int r) {
	if(l == r) tree[node] = v[l];
	else {
		int m = (l+r)/2;
		build(2*node,l,m);
		build(2*node+1,m+1,r);
		tree[node] = max(tree[2*node],tree[2*node+1]);
	}
}

void update(int node, int l, int r, int idx, int x) {
	if(l == r) tree[node] = x;
	else {
		int m = (l+r)/2;
		if(idx <= m) update(2*node,l,m,idx,x);
		else update(2*node+1,m+1,r,idx,x);
		tree[node] = max(tree[2*node],tree[2*node+1]);
	}
}

int query(int node, int l, int r, int x) {
	if(tree[node] < x) return -1;
	if(l == r) return l;
	int m = (l+r)/2;
	int ans = query(2*node,l,m,x);
	if(ans == -1) return query(2*node+1,m+1,r,x);
	return ans;
}

int32_t main() {
	int t,a,b;
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>v[i];
	build(1,0,n-1);
	for(int i=0; i<m; i++) {
		int t,a,b;
		cin>>t>>a;
		if(t == 1) {
			cin>>b;
			update(1,0,n-1,a,b);
		} else {
			cout<<query(1,0,n-1,a)<<endl;
		}
	}
	return 0;
}