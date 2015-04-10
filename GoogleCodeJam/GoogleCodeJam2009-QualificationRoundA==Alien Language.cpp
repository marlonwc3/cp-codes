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
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int L, D, N, cnt[5000],sum;
char str[90000], line[90000];
vector<pair<string, bool> > vs;
vector<string> words;
void go(int p, int k){
	if( k>= L){
		sum = 0;
		fr(i,0,D) sum += cnt[i] >= L;
		return;
	}
	if(vs[p].nd ) {
		fr(i,0,vs[p].st.length() ) fr(j,0,D)cnt[j] += words[j][k+i] == vs[p].st[i];
		go(p+1, k + vs[p].st.length() );
		return;
	}
	fr(i,0,vs[p].st.length() ) fr(j,0,D) cnt[j] += words[j][k] == vs[p].st[i];
	go(p+1, k+1);
}

int main (int argc, char const* argv[]){
	int res;
	sc3(L,D,N);
	words.clear();
	fr(i,0,D){
		scanf("%s", str);
		words.pb(str);
	}
	fr(j,0,N){
		scanf("%s", line);
		vs.clear();		
		mst(cnt, 0);
		string str, aux;
		bool ob;
		int i = 0;
		while(  line[i] ) { 
			str = "";
			ob = 0;
			if(line[i]=='('){
				i++;
				while( line[i] && line[i] != ')' ){
					aux = line[i]; 
					str += aux;
					i++;
				}
				i++;
			}
			else{
				ob = 1;
				do{
					aux = line[i]; 
					str += aux;
					i++;
				}while(line[i] && line[i] != '(' );
			}
			vs.pb(mp(str, ob));
		}		
		sum = 0;
		go(0, 0);
		printf("Case #%d: %d\n", (j+1), sum);
	}
	
	return 0;
}







