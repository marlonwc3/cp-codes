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
typedef pair<ll , ll> pll;


int main (int argc, char const* argv[]){
	int n;
	sc1(n);
	string l1, l2;
	getline(cin,l1);
	while(n--){
		getline(cin,l1);
		getline(cin,l2);
		//printf("l1: %s | l2: %s\n", l1.c_str(), l2.c_str());
		int len1 = l1.length(), len2 = l2.length();
		int p1 = -1, p2 = -1, p3 = -1, p4 = -1;
		fr(i,0,len1){
			if(l1[i] == '<' || l1[i] == '>' ) {
				if(l1[i]=='<'){
					if(p1 == -1) p1 = i;
					else if(p2 == -1 ) p2 = i;
				}
				else{
					if(p3 == -1) p3 = i;
					else if(p4 == -1 ) p4 = i;				
				}
				
				continue;
			}
			printf("%c", l1[i]);
		
		}
		_
		fr(i,0,len2){
			if(l2[i] == '.') break;
			printf("%c", l2[i]);
		
		}
		fr(i,p2+1,p4) printf("%c", l1[i]);
		fr(i,p3+1,p2) printf("%c", l1[i]);
		fr(i,p1+1,p3) printf("%c", l1[i]);
		fr(i,p4+1,len1) printf("%c", l1[i]);						
_
	
	}
	
	
	
	return 0;
}

