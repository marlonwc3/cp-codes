#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
//#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll , ll> pll;

int matrix[500][500];
int row[500],col[500] ,n, m;

bool val(){
	fr(i,0,n){
		fr(j,1,m){
			if(((matrix[i][j]-1)/m) != (matrix[i][0]-1)/m ) return 0; 
		}
		row[i] = (matrix[i][0]-1)/m;
	}
	fr(i,0,m){
		fr(j,1,n){
			if(matrix[j][i]%m != matrix[0][i]%m ) return 0;
		}
		col[i] = ( (matrix[0][i]-1) %m);
	}
	return 1;
}

int go(bool rows, int N){
	int pos[500], arr[500];
	int sum, k;
	sum = 0; // resposta
	fr(i,0,N){
		k = (rows) ? row[i] : col[i];
		pos[k]=i;
		arr[i] = k;
	}
	fr(i,0,N){
		if(i==arr[i])continue;
		sum++;
		swap(arr[i], arr[pos[i]]);
		pos[arr[pos[i]]] = pos[i];
	}
	return sum;

}


int main (int argc, char const* argv[]) {
	while(sc2(n,m)==2){
		fr(i,0,n) fr(j,0,m) sc1(matrix[i][j]);
		bool ok = val();
		if(0){
			printf("LInha\n");
			fr(i,0,n){ 
				printf("%d ", row[i]);
			} _
				printf("Col\n");		
			fr(j,0,m){
				printf("%d ", col[j] );
			} _
		}
		if(!ok) printf("*\n");
		else {
//			printf("ok\n");
			int a = go(1, n);
			int b = go(0, m);
//			printf("a: %d | b: %d\n", a, b);
			int r = a+b;
			printf("%d\n", r);
		}
	}
	
	
	
	
	return 0;
}






