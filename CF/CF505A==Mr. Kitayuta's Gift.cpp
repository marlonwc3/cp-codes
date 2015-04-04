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

bool isPalindrome(string s){
	int len = s.length();
	int i = 0 , j = len-1;
	while ( i <= j ) {
		if(s[i]!=s[j])return 0;
		i++, j--;
	}
	return 1;
}


string line, aux, aux2, aux3;
int main(int argc, char const *argv[]) {
	getline(cin,line);
	//printf("LINE: %s\n", line.c_str() );
	int len = line.length();
	bool ok = 0;
	fe(i,0,len){
		fe(k,'a','z'){
			aux2 = k;
			aux = "";
			if(!i){
				aux = aux2+line;
				if(k=='r'){
					//printf("%s\n", aux.c_str() );
				}					
				if(isPalindrome(aux)) { ok=1;  goto fim;}
			}
			else{

				fr(j,0,i){
					aux += line[j];
				}
				aux += aux2;
				fr(j,i,len){aux += line[j];}


				if(k=='r'){
				//	printf("%s\n", aux.c_str() );
				}				
				
				if(isPalindrome(aux)) { ok=1;  goto fim;}
			}			
		}

	}
	fim:;
	if(ok) printf("%s\n", aux.c_str());
	else printf("NA\n");
	return 0;
}
