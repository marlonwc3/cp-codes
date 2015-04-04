#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
typedef long double lb;

vector<string> esp;
string res;

bool test(string a){
	int l = esp.size(), len;
	fr(i,0,l){
		len = esp[i].length();
		if(len!=a.length() ) continue; 
		bool ok =1;
		fr(j,0,len){
			if( esp[i][j]!=a[j] &&  esp[i][j]+32!=a[j] &&  esp[i][j]-32!=a[j] ) ok = 0;
		}
		if(ok) return 1;
	}
	return 0;
}



int main (int argc, char const* argv[]) {
	int t, n, f;
	//printf("a: %d   A:%d   a-A:%d\n", int('a'),int('A'), int(fabs(int('a'-'A')) ) );
	sc1(t);
	char str[300];
	string a, line;
	int len;
	while(t--){
			a = "";
			esp.clear();
			sc2(n,f);
			getline(cin, line);
			getline(cin, line);
			len = line.length();
			fr(i,0,len){
				if(line[i]==' ' || line[i] == '-' || line[i] == '.'){
					if(!a.empty() ){ 
						esp.pb(a);
						a = "";
					}
				}
				else a+= line[i]; 
			}
			if(a.length() > 0 ){
				esp.pb(a);
			}
			fr(i,0,f){
				int cnt = 0;
				char c;
				res = "";
				a = "";
				getline(cin, line);
				
				len = line.length();
				//printf("line: %s  len:%d\n", line.c_str(), len);	
				bool ok = 1;
				fr(j,0,len+1){
					if(j==len || line[j]==' ' || line[j] == '-' || line[j] == '.'){
						//printf("Encontrou: %s\n", a.c_str());
						if(!a.empty()){

							ok = test(a);
							//printf("ok->%d  \n ", ok);
							c = a[0];							
							if(ok){
								if(!cnt) goto label;
								if(c >= 'A' && c <= 'Z') c+=32;
								ok=0; 
							}	
							else {
								if (c>='a' && c<='z' ) c-=32; 
							}
							//printf("c->%c\n", c);
							res +=c;
							label:;
							a = "";
							cnt++;
						}
					}
					else { if(j < len) a += line[j];}
				}
				//if(!a.empty()) goto label;
				printf("%s\n", res.c_str());
				
			}
			_
	
	}
	
	return 0;
}
