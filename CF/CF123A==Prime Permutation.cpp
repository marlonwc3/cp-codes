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

#define PI acos(-1)
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int rep[3000];
int cnt[3000];
void init(int N){ fe(i,0,N+100) {rep[i] = i; cnt[i] = 1; }  }
int find(int a){
	return (rep[a] == a) ? a : (rep[a] = find(rep[a]));
}
void uni(int a, int b){
	
	int ra = find(a), rb; rb = find(b);
	if(ra == rb) return;
//	printf("ra: %d | rb: %d | c1 %d | c2 %d\n", ra, rb, cnt[ra], cnt[rb] );
	rep[ra] = rb;
	cnt[rb] += cnt[ra];
	cnt[ra] = 0;
	//printf("ra: %d | rb: %d | c1 %d | c2 %d\n", ra, rb, cnt[ra], cnt[rb] );	
}
bool iss(int a,int b){return find(a) == find(b); }
vi primes;
bool mark[2010];
void sieve(){
	mark[0] = mark[1] = 1;
	fe(i,0,2000){
		if(mark[i]) continue;
		primes.pb(i);
		if(i > 1000) break;
		for(ll j = ll(i)*ll(i); j > 0 && j <= 2000; j+=i) mark[j] = 1;
	}
}

int freq['a' +1000+ 10];

void pf(set<int> s){
	for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
		printf("%d ", (*it) );
	}
	_
}
bool used[1010];
int main (int argc, char const* argv[]){
	mst(freq,0);



	//return 0;
	sieve();
	//pv(primes,x);
	string str, res;
	getline(cin, str);
	res = str;
	int l = str.length();
	init(l);
	fr(i,0,l){ freq[str[i]]++; } 
	if(0) { fe(i,'a','z'){
		if(freq[i] <= 0 ) continue;
		printf("%c -> %d | ", i, freq[i]);
	} _
	 }
	int p;
	//printf("L: %d\n", l);
	for( int i = 0; primes[i] <= l; i++ ) {
		p = primes[i];
	//	printf("Prime %d\n" , p);
		fe(j,1,l/p){
		//	printf("unindo %d com %d\n", p, p*j);
			uni(p, p*j);
		//	printf("tamanho: %d\n", cnt[find(p)]);
		}
	}	
	//return 0;
	set<int> myset;
	fe(i,1,l){
		myset.insert(find(i));
	}
	//pf(myset);
	int k;
	int ri, x;
	bool ok = 1;
	//_
	for(set<int>::iterator it = myset.begin(); it != myset.end(); it++) {
		p = *it;
		k = cnt[p];
		if( k <= 0 ) continue;
		//printf("p: %d | k: %d\n", p, k);

		x = inf;
		ri = -1;
	if(0) { 	
	printf("ANTES [1] \n");
	fe(i,'a','z'){
		if(freq[i] <= 0 ) continue;
		printf("%c -> %d | ", i, freq[i]);
	} _
	 }	
		fe(i,'a','z'){
			if(freq[i] < k ) continue;
			if(freq[i] < x ) {
				x = freq[i];
				ri = i;
			}
		}
	if(0) { 	
	printf("DEPOIS [1] \n");
	fe(i,'a','z'){
		if(freq[i] <= 0 ) continue;
		printf("%c -> %d | ", i, freq[i]);
	} _
	 }			
		//printf("ri: %c | x: %d\n", ri ,x);
		if(ri == -1) {ok = 0; break;}
	if(0) { 	
	printf("ANTES[2] \n");
	fe(i,'a','z'){
		if(freq[i] <= 0 ) continue;
		printf("%c -> %d | ", i, freq[i]);
	} _
	 }			
		freq[ri] -= k;
	if(0) { 	
	printf("DEPOIS[2] \n");
	fe(i,'a','z'){
		if(freq[i] <= 0 ) continue;
		printf("%c -> %d | ", i, freq[i]);
	} _
	 }		
		fe(i,1,l){
		
			if(iss(i, p) ){
			//	printf("%d pertence!\n", i); 
				used[i] = 1;
				res[i-1] = ri;
			}	
		}
	}
	//return 0;
	fe(i,1,l){
		if(!used[i]){
			fe(j,'a','z') {
				if(freq[j] <= 0 ) continue;
				freq[j]--;
				res[i-1] = j;
				used[i] = 1; 
				break;
			}
		}
	}
	fe(i,1,l) if(!used[i]) { ok = 0; break; }
	if(!ok) printf("NO\n");
	else printf("YES\n%s\n", res.c_str() ) ;
	
	
	
	return 0;
}



