/*
   (o_o)
   <) )>
    / \
   AUTHOR  : Peeyush Yadav
   Problem : All pair shortest path
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
		#define trace4(w,x,y,z)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#w" = "<<w<<" | "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
	#else
		#define trace(x)
		#define trace2(x,y)
		#define trace3(x,y,z)
		#define trace4(w,x,y,z)
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
	#define TimeElapsed				(double)clock()/CLOCKS_PER_SEC
}
/*........................................................END OF TEMPLATES..................................................................*/

#define maxn 1000
#define maxv 1e9
int dist[maxn][maxn],n;

void floyd(){
  f(k,1,n+1)
    f(j,1,n+1)
      f(i,1,n+1){
        if(dist[i][j] > dist[i][k] + dist[k][j])
              dist[i][j] = dist[i][k] + dist[k][j];
      }
}



int main(){
	fast();

  int edges,x,y,c;

  s(n)
	s(edges);

  f(i,0,maxn)
    f(j,0,maxn){
          dist[i][j] = maxv;
          if(i == j) dist[i][j] = 0;
    }

	f(i,0,edges){
      s(x) s(y) s(c);
			dist[x][y] = c;
  }

  floyd();

  p2d(dist,n+1,n+1);

	trace(TimeElapsed)


}
