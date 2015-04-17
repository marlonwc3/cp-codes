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






#define MAX_L 10010
#define MAX_LX 10010
int L,X;
string line, str;
int len;


int matrix[5][5] = { 
	{0,0,0,0,0}, 
	{0,1,2,3,4 },  // 1
	{0,2,-1,4,-1*3}, 
	{0,3,-1*4,-1,2}, 
	{0,4,3,-1*2,-1} 
}; 


int meda(int k){
	int get[35];
	get[1] = 1;
	get[2] = 2;
	get[3] = 3;
	get[4] = 4;
	get['i'] = 2;
	get['j'] = 3;
	get['k'] = 4;
	return get[k];
}

int mult(int a, int b ) {
	if(!a) return b;
	if(!b) return a;
	int s1 = a < 0 ? -1 : 1;
	int s2 = b < 0 ? -1 : 1;
	a = meda(abs(a)); b = meda(abs(b));
	return s1*s2*matrix[a][b];
}

// 1 based
int freq[MAX_LX][MAX_LX];
int main (int argc, char const* argv[]){
	int caso;
	sc1(caso);
	fe(t,1,caso){
		sc2(L,X);
		getline(cin,line); getline(cin,line);
		str = "";		
		fr(i,0,X) str += line ;
		len = str.length();
		fr(i,0,len){
			freq[i][i] = meda(str[i]);
			fr(j,i+1,len){
				freq[i][j] = mult(freq[i][j-1], meda(str[j]));
			}
		}
		
		int s1, s2, s3, k ;		
		bool ok = 0;	
		fr(i,1,len) {
			
			s1 = freq[0][i-1];
			if( s1 != 2) continue;		
			fr(j,i+1,len){
				s2 = freq[i][j-1];
				if(s2 != 3) continue;
				s3 = freq[j][len-1];
				if(s3 != 4) continue; 
				ok = 1;
				break;
			}
			if(ok) break;
			
			
		}	

		
			
	
	
		if(ok) printf("Case #%d: YES\n", t);
		else printf("Case #%d: NO\n", t);
		
			
	
	
	}
	
	
	return 0;
}











