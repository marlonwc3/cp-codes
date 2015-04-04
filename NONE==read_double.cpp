int readDouble(){
	char str[1000]; 
	scanf("%s", str);
	int len = strlen(str);
	int p=len; 
	for(int i =0; i < len; i++) {
		if(str[i]=='.') {p=i; break;}
	}
	int r1 = 0, r2 = 0;
	for(int i =0; i < p; i++)r1 = (str[i]-'0') + 10*r1;
	r1 = r1*100;
	for(int i = p+1; i < len; i++) r2 = (str[i]-'0') + 10*r2;
	if( len-p == 2) r2 *= 10;
	return r1+r2;
}
