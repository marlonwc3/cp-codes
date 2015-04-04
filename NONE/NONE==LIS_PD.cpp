vi v;
int l, k, cnt;
int pd[100];
int go(int p){
	if(p==l) return 0;
	pd[p]=1;
	fr(i,0,p){
		if(v[p] > v[i] ) {
			if(pd[i]+1 > pd[p]){
				pd[p] = pd[i]+1;
			}	
		}
	}
	printf("p: %d | pd[p]: %d \n", p , pd[p]);
	cnt = max(cnt, pd[p]);
	go(p+1);
}

