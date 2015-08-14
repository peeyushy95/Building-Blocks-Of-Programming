/*
   AUTHOR  : Peeyush Yadav
   Problem : Median(QuickSelect)
*/
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(a,b,c)                for(int a=b;a<c;a++)
#define s(x)                    scanf("%d",&x);
#define sl(x)                   scanf("%lld",&x);
#define p(x)                    printf("%d\n",x);
#define p2(x,y)                 printf("%d %d\n",x,y);
#define pl(x)                   printf("%lld\n",x);
#define pl2(x,y)                printf("%lld %lld\n",x,y);
#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
void input(){
	#ifdef Megamind
			#define DEBUG
			#define TRACE
			freopen("inp.txt","r",stdin);
			//freopen("out.txt","w",stdout);
	#endif
}
#ifdef TRACE
	#define trace(x)                       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
	#define trace2(x,y)                    cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
	#define trace3(x,y,z)                  cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#else
	#define trace(x)
	#define trace2(x,y)
	#define trace3(x,y,z)
#endif
 
inline ll power(ll a, ll b, ll m) {
	ll r = 1;
	while(b) {
		if(b & 1) r = r * a % m;
		a = (a * a)% m;
		b >>= 1;
	}
	return r;
}
inline ll power(ll a, ll b) {
	 ll r = 1;
	while(b) {
		if(b & 1) r = r * a ;
		a = a * a;
		b >>= 1;
	}
	return r;
}
 
/*........................................................END OF TEMPLATES.......................................................................*/
#define sz 1123456

 
void qsort(int *a, int fst, int last,int mid){
	//trace2(fst,last)
	int i=fst,j=last,pivot=a[fst],tmp;
	 if(fst<last){
		   
		   while(i<j){
				 while(i<last  &&  a[i] <= pivot)  i++;
				 while(j>fst   &&  a[j] >  pivot)  j--;
				 if(i<j) swap(a[i],a[j]);				
		   }
		   
		   swap(a[fst],a[j]);
		   if(j == mid)	   return; 
		   if(j > mid)     qsort(a,fst,j-1,mid);
		   if(j < mid) 	   qsort(a,j+1,last,mid);
	 }
}

int a[sz];

int main(){
	input();
    
	int n;
	s(n)
	f(i,0,n) s(a[i]);
	qsort(a,0,n-1, n/2);    // if n even then median is greater of middle two elements
	p(a[n/2]);
	
	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
} 
