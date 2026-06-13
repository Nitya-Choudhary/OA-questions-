//Every valid substring must:

//Have even length
//Contain only one character

//Since the whole string length is even, we can process pairs:

int valid(string s){
  int n= s.size();
  int ans=0;
  for(int i=0;i<n;i++){
    if(s[i+1]!=s[i]){
      ans= ans+1;
    }
  }
  return ans;
}
