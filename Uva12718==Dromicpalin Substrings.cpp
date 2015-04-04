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
 
ll freq[1005]['z'+50]; 

ll get(int a, int b, int c){
	return freq[b][c] - freq[a-1][c];
}


bool pd[1005][1005];
ll res;

string line;
int len;
void print(int a,int b){
	fe(i,a,b) printf("%c", line[i]);
	_
}

void go(int a, int b){
	if( a<= 0 || b <= 0 || a >len || b > len ||  a>b) return;
	if(pd[a][b]) return ;
	
	bool has = 0,ok=1;
	ll k;
	fe(i, 'a','z'){
		k = get(a, b, i);
		if(k%2 == 1) {
			if(has){ ok=0; break;}
			has = 1;
		}
	}
	//print(a-1, b-1);
	if(ok) {
		//printf("%d->%d\n", a, b	);
		//print(a-1, b-1);
		res++;
	}
	
	
	pd[a][b]=1;	
	go(a+1, b);
	go(a, b-1);
	go(a+1, b-1);

}



int main (int argc, char const* argv[]){
	int caso;

	sc1(caso);
	getline(cin,line);
	fe(t,1,caso){
		getline(cin,line);
//		printf("line: %s\n", line.c_str());
		len = line.length();
		mst(freq[0], 0);
		for(int i=0, j=1; i < len; i++, j++){
			fe(l,'a','z'){ freq[j][l]=freq[j-1][l]; }
			freq[j][line[i]]++;
		}
		if(0) fe(j,1,len){
			printf("@ j: %d\n", j);
			fe(i,'a','z'){
				if(!freq[j][i]) continue;
				printf("(%c: %lld) ", i, freq[j][i]);
			}
			_
		}
		
		
		mst(pd, 0);
		res = 0;
		go(1, len);
		printf("Case %d: %lld\n", t, res);	
	}
	

	
	
	
	return 0;
}








