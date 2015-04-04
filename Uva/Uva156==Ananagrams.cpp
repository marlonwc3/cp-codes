#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#define pf(t) printf("%d\n", t)
using namespace std;

typedef vector<char> vc;
typedef pair<vc, vc> pvc; // second==original
typedef vector<vc> vvc; 
typedef vector<pvc> vpvc;



vvc res;
vpvc m[25];
vvc inp[25];
int n;
bool okays[25][1005];


bool eq(int l, int a, int b){
	char ca, cb;
//	printf("cmp len:%d - %d %d\n", l ,a , b);
	for(int i=0; i < l; i++){
		ca = m[l][a].first[i];
		cb = m[l][b].first[i];
	//	printf("cmp %c %c\n", ca, cb);
		if(ca != cb ) return 0;
	}
	//printf("iguais\n");
	return 1;
}




void f(){ 	
	int s; bool ok;
	for(int i=1; i <= 20; i++ ){ // tds palavras de tamanho i	
		s = m[i].size(); 
		if(!s) continue;

		for(int j=0; j < s; j++){ // palavra i com
			if(!okays[i][j]) continue;
			ok=1;

			for(int k = j+1; k < s; k++){ // tds palavras j

				if(eq(i,j,k)) { // duas iguais
					okays[i][j] = okays[i][k] = 0;
					ok=0;
				}			
			}

			if(ok) res.push_back(m[i][j].second);
		}
	}
}


void pv(int k){
	int s = res[k].size();
	for(int i=0; i <s; i++){
		printf("%c", res[k][i]);
	}
}

void pres(){

//	printf("ressize:%d\n", s);
	sort(res.begin(), res.end());
	int s = res.size();	
	for(int i=0 ;i <s;i++){
		pv(i);
		printf("\n");
	}
}


int main (int argc, char const* argv[]) {
	
	char a[25];
	memset(okays, 1, sizeof okays);
	int len;
	n=0;
	while(1){
		scanf("%s", a);
		len = strlen(a);
		if(len==1 && a[0]=='#') break;
		n++;
		vc v(a, a + len);
		
		for(int i=0; i < len; i++ ){
			v[i] += (v[i] < 'a' ) ? 32 : 0;
		}
		
		vc voriginal(a, a+len);
		sort(v.begin(), v.end());
		m[len].push_back(make_pair(v, voriginal) );			
	}

	f();
	pres();



	return 0;	
}

