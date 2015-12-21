/*
   (•_•)
   <) )>
    / \
   AUTHOR  : Peeyush Yadav {~_~}
   Problem : Topological sorting.
*/
#include<bits/stdc++.h>
using namespace std; typedef long long ll; typedef pair<int,int> grp;
inline ll power(ll a,ll b)     { ll r=1; while(b){ if(b&1) r=r*a    ; a=a*a    ; b>>=1;} return r;}
inline ll power(ll a,ll b,ll m){ ll r=1; while(b){ if(b&1) r=(r*a)%m; a=(a*a)%m; b>>=1;} return r;}
void fast(){	
	#ifdef Megamind
		freopen("inp.txt","r",stdin);
		//freopen("out.txt","w",stdout);
		#define trace(x)            cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
		#define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
		#define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
	#else
		#define trace(x)
		#define trace2(x,y)
		#define trace3(x,y,z)
	#endif
	
	#define fi						first
	#define se						second
	#define mp						make_pair
	#define pb(x)					push_back(x)
	#define s(x)					scanf("%d",&x);
	#define sl(x)					scanf("%lld",&x);
	#define p(x)					printf("%d\n",x);
	#define f(a,b,c)				for(int a=b;a<c;a++)
	#define r(a,b,c)				for(int a=b;a>c;a--)
	#define p2(x,y)					printf("%d %d\n",x,y);
	#define pl(x)					printf("%lld\n",x);
	#define pl2(x,y)				printf("%lld %lld\n",x,y);
	#define p1d(a,n)				for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
	#define p2d(a,n,m)				for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
}
/*........................................................END OF TEMPLATES.......................................................................*/
#define sz 112345
vector <int> v[sz];
int dis[sz],fin[sz],tym;
bool visited[sz];

void dfs(int u){
	visited[u]=1;
	dis[u]=++tym;

	f(i,0,v[u].size())	
		if(!visited[v[u][i]])	
						dfs(v[u][i]);


	fin[u] = ++tym;
}

void topological(){
	grp p[sz];
	int ind= 0;
	f(i,0,sz) if(fin[i] != 0) p[ind++] = mp(fin[i],i);

	sort(p,p+ind);
	reverse(p,p+ind);

	f(i,0,ind) cout<<p[i].se<<" ";
}

int main(){
	fast(); 
	
	int n,m,x,y;
	s(n)
	s(m)

	f(i,0,m){
		s(x)
		s(y)
		v[x].push_back(y);
	}

	f(i,1,n+1) 
		if(!visited[i])
					dfs(i);

	topological();

	#ifdef Megamind
		cerr << "\nIime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif
}  
