#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

//n==1000
typedef long long int lli;
int m[1005][1005];
lli cols[1005], rows[1005], da, db, sum;

bool mark[1000005];



int n;
bool qm(){
	bool ok = true;
	da=db=0;
	sum=0;
	memset(cols, 0, sizeof cols);
	memset(rows, 0, sizeof  rows);
	memset(mark, 0, sizeof mark);
	lli k; int duble = pow(n, 2.0);
	
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			//k = m[i][j];
			scanf("%d", &m[i][j]);
			k = m[i][j];
			if(!ok) {continue;}
			if( mark[k] ) ok= false; 
			mark[k]=true;
			if(k > duble) ok= false;
			cols[j]+=k;
			rows[i]+=k;
			if(i==j) da+=k;
			if( (i+j) == (n-1) ) db+=k;

		}
		
		if(i==0) {
			sum = rows[i];
	//		printf("sum:%lld\n", sum);
		}
		else  { // 0 < i < n-1
			if(rows[i] != sum) ok= false;
		}
	}
//	printf("chegou da:%lld db:%lld\n", da, db);	
	if(da != sum || db != sum ) ok= false;
	for(int i=0; i < n && ok; i++){
		if(cols[i] != sum) ok= false;
	} 
	return ok;
}



int main (int argc, char const* argv[]) {
	while(scanf("%d", &n) > 0 ){
		memset(m, 0, sizeof m);

		if(qm()) printf("%lld\n", sum);
		else printf("0\n");
	}
	return 0;
}
