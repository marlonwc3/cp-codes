string pd[300][300];
bool mark[300][300];
string  a, b; // params

string lcs(int i, int j){
	if(i==a.length() || j == b.length() ) return "";
	if(mark[i][j]) return pd[i][j];
	if(a[i]==b[j]) return a[i] + lcs(i+1, j+1);
	string r1 = lcs(i+1, j);
	string r2 = lcs(i, j+1);
	mark[i][j]=1; 
	return pd[i][j] = (r1.length() > r2.length() ) ? r1 : r2;
} 
