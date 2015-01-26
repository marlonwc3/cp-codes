map<key,value>::iterator it = mapa[a];
if (it != mapa.end()) return it-> second;
return mapa[a] = x;


int i = 0, j = 1, ans = 0;
while (i < n) {
   while (j < n && arr[j] < arr[i]){ ++j;      }
   ans = max(ans, j-i+1);
   i = j+1;
}