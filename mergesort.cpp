/*
   AUTHOR  : Peeyush Yadav
   Problem : Merge Sort
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
	
	#define fi 			first
	#define se 			second
	#define mp 			make_pair
	#define pb(x) 			push_back(x)
	#define s(x)                    scanf("%d",&x);
	#define sl(x)                   scanf("%lld",&x);
	#define p(x)                    printf("%d\n",x);
	#define f(a,b,c)                for(int a=b;a<c;a++)
	#define r(a,b,c)		for(int a=b;a>c;a--)
	#define p2(x,y)                 printf("%d %d\n",x,y);
	#define pl(x)                   printf("%lld\n",x);
	#define pl2(x,y)                printf("%lld %lld\n",x,y);
	#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
	#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
}
/*........................................................END OF TEMPLATES.......................................................................*/
#define sz 12345
ll a[sz];
 
void merge(int strt, int mid , int last){
	ll b[sz];
	int i = strt,j=mid+1,k=0;
	while(i <= mid && j <= last){
		if(a[i] < a[j]) b[k++]=a[i++];
		else			b[k++]=a[j++];
	}
	
	while(i <= mid)  b[k++] = a[i++];
	while(j <= last) b[k++] = a[j++];
	
	f(temp,0,k) a[temp + strt] = b[temp];
}

 
void msort(int first, int last){
	if(first < last){
		
		msort(first,(first+last)/2);
		msort((first+last)/2 + 1,last);
		merge(first,(first+last)/2,last);
	}
} 
 

int main(){
	fast();
	
	int n;
	s(n)
	f(i,0,n) sl(a[i]);
	
	msort(0,n-1);
	
	p1d(a,n)
	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif
}  
