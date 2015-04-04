#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

int arr[105];
int pd[50005];
int pai[50005];
int n,m;
void go(){
	int t;
	fe(i,0,m) {pd[i]=inf; pai[i]=-1;}
	pd[0]=0;
	fr(i,0,n){
		fe(j,0,m){
			t = j+arr[i];
			if( t > m  ) break;
			if(1+pd[j] < pd[t] ){
				pd[t] = 1+ pd[j];
				pai[t]= arr[i];
			}
			else if(1+pd[j] == pd[t] && pai[j] < pai[t] ){
				pai[t]= arr[i];				
			}			
		}	
	}	
}
vi v;
void go2(int m){ // pegar o caminho 
	int d;
	v.clear();
	while(pai[m] != -1 ) {
		v.pb(pai[m]);
		m = m-pai[m];
	}	
}

int main (int argc, char const* argv[]){
	while(1){
		sc1(m); iz(m);
		sc1(n);
		fr(i,0,n) sc1(arr[i]);
		
		go();
		
		n = pd[m];
		if(n<0 || n >= inf ) printf("Impossivel\n");
		else {
			printf("%d\nmoedas de [%d]:\n", n, m);
			go2(m);
			n = v.size();
			int sum = 0;
			for(int i = n-1; i>=0; i--){
				printf("%d ", v[i] );
				sum+=v[i];
			}
			_
			printf("fim sum: %d \n" , sum);
		}
	}
	return 0;
}










