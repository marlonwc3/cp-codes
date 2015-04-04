#define LSOne(S) (S & (-S) )
vll t;
void ft_create (int n) {  t.assign(n+1, 0); }   
ll ft_rsq(int b) {
    ll sum = 0; for(; b; b -= LSOne(b) ) sum += t[b];
return sum; }
int ft_rsq(int a, int b) { return ft_rsq(b) - (a==1 ? 0 : ft_rsq(a-1)); }
void ft_adjust(int k, ll v) { for(; k<= (int)t.size(); k+= LSOne(k)  ) t[k]+=v; }
