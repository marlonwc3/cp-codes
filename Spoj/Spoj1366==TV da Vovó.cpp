#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;

int arr[1005][1005];
int n, m, h, l, x, y, t;

int mod(int k, int d){
	k%=d;
	if(k<0) return k+d;
	return k;
}

void f(){
	printf("Teste %d\n", t);
	fr(i, 0, m ){
		x= mod(i + (l), m );
		fr(j , 0, n){
			y = mod(j - h, n);
			printf("%d ", arr[x][y]);
			if(j!=n-1) printf(" ");
		}
		_
	}
	_
}


int main (int argc, char const* argv[]) {
	t=0;
	while(1){
		int k;
		sc2(m, n);	
		if(!m && !n ) break;
		t++;
		fr(i, 0, m) fr(j, 0, n) sc1(arr[i][j]);
		h=l=0;
		while(1){
			sc2(x, y);
			if(!x && !y) break;
			h+=x; l+=y;
		}
		f();
	}
	return 0;
}







