#include <bits/stdc++.h>
#define _ printf("\n");
#define fr(i,a,b) for(int i=(a); i <(b); i++)
#define st first
#define nd second 
#define fe(i,a,b) for(int i=(a); i <=(b); i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define EPS 1e-7
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


vi conso;
vi vogais;
int onde[100005];

char line[100005];

bool isv(char ch){
	return ch == 'a' || ch == 'e' || ch =='i' || ch =='o' || ch == 'u';

}



int main (int argc, char const* argv[]) {
	int caso;
	
	int w = -3%6;
//	printf("w: %d\n", w);
	
	sc1(caso);
	fe(t,1,caso){
		conso.clear();
		vogais.clear();
		scanf("%s", line);
		int len = strlen(line);
		for(int i =0;i<len; i++){
			if(isv(line[i])) {
				vogais.pb(i);
				onde[i] = vogais.size()-1; 
			}
			else{
				conso.pb(i);
				onde[i] = conso.size()-1;
			}
		}
		int q, a, b;
		ll coff=0, voff=0;
		
		printf("Caso #%d:\n", t);
		sc1(q);
		while(q--){
			sc1(a);
			if(a==0 || a==1) sc1(b);
			
			if(a==0){
				if(vogais.size() >=  1 ){
					voff =  (voff+b)%vogais.size();
				}
			}
			else if (a==1){
				if(conso.size() >= 1){
					coff = (coff+b)%conso.size();
				}
			}
			else{
			//	printf("voff %lld coff %lld\n", voff, coff);
				char ch;
				int p, d;
				for(int i =0 ; i<len; i++){
					ch = line[i];
					if(isv(ch)){
						p = onde[i];
						int lol = vogais.size();
						if(lol){
						
						
						
						d = (p-voff);
					
						if( d < 0 ) d += vogais.size() ;
						//printf("v g d: %d\n", d);
						
						}
						else d = p;
						d = vogais[d];
						ch = line[d];
					}
					else{
						
						p = onde[i];
						int lol = conso.size();
						
						//printf("p: %d | cof: %lld | p-coff %lld | res %lld \n", p, coff, p - coff, (p-coff)%lol);
						
						if(lol){
						d = (p-coff)%lol;
						if( d < 0 ) d += conso.size();		
							
						//printf("c s d: %d\n", d);
						} else d = p;
						d = conso[d];
						ch = line[d];	
							
							
										
					}
				printf("%c", ch);
				}	
				_
				
			
			}
			
		
		}
		
		
		
		
	}
	
	
	
	
	return 0;
}














