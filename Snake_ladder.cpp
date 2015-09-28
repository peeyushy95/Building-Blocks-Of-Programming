/*
   AUTHOR  : Peeyush Yadav
   Problem : https://www.hackerrank.com/challenges/the-quickest-way-up
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
#define sz 109

vector<grp> v[sz];

int dijkstra(int s, int dest){
	  vector<int> dist(sz, 9876543);  
	  priority_queue<grp,vector<grp>, greater<grp> > Q; 
     
	  dist[s] = 0;
	  Q.push(grp(0,s));

	  while(!Q.empty()) {

			grp top = Q.top();
			Q.pop();
					
			int parent = top.se, d = top.fi;

			if(d <= dist[parent]) {
				  for(vector<grp> :: iterator it = v[parent].begin(); it != v[parent].end(); it++){
						int child = it->fi, cost = it->se;
						if(dist[child] > dist[parent] + cost) {
							  dist[child] = dist[parent] + cost;
							  Q.push(grp(dist[child],child));
						}
				  }
			}
	  }
	  return dist[100];
}

int main(){
	fast();
	
	int t,n,x,y,m,j;
	s(t)
	while(t--){
		f(i,1,101){
			f(j,i+1,i+7) {
				if(j>100) break;
				v[i].pb(grp(j,1));
			}
		}
		
		s(n)
		f(i,0,n){
			s(x)
			s(y)
			v[x].pb(grp(y,0));
		}
		s(m)
		f(i,0,m){
			s(x)
			s(y)
			v[x].clear();
			v[x].pb(grp(y,0));
		}
		
		int ans = dijkstra(1,1);
		if(ans > 100) p(-1)
		else 		  p(ans);
		f(i,1,102) 	v[i].clear();
		
	}
	
	
	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif
}  
