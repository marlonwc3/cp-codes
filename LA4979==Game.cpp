#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a; i < b; i++)
#define _ printf("\n")
using namespace std;

char matrix[5][5];
int des[8][2] = {{1,0} , {-1,0}, {0,1},{-1,0}, {1,-1}, {1, 1}, {-1, 1}, {-1, -1} };
int f(int a, int b){
	int da, db;
	for(int i=0; i < 8; i++){
		int cont=1;
		da = a; db =b;
		for(int j=0; j < 2; j++){
			da = da+des[i][0];
			db = db+des[i][1];		
			if(da<0 || db < 0 || da >= 5 || db >= 5) break;			
			if(matrix[da][db] == matrix[a][b]) cont++;
			if(cont>=3) return matrix[a][b];
		}
	}
	return 0;
}

int main (int argc, char const* argv[]) {
	
	int t, k, res;
	char c; 
	bool aw, bw;
	scanf("%d", &t);
	while(t--){
		for(int i=0; i < 5; i++){
			scanf("%s", matrix[i]);
		}
		aw=bw=0;
		for(int i=0;i < 5;i++){
			for(int j=0; j < 5; j++){
				if(aw && matrix[i][j]=='A') continue;
				if(bw && matrix[i][j]=='B') continue;
				res = f(i,j);
				if(res=='A') aw=1;
				if(res=='B') bw=1;
				if(aw && bw) goto fim;			
			}
		}
		fim:
		
		if(aw && bw) printf("draw\n");
		else if (aw) printf("A wins\n");
		else printf("B wins\n");
	}
	return 0;
}
