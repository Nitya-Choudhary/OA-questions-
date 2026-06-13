int solve(string str){
  vector<int>freq(26,0);
  for(int i=0;i<str.size();i++){
    freq[i-'a']++;
  }
  for(int i=0;i<str.size();i++){
    if(freq[i-'a']==1){
      return i;
    }
  }
  return -1;
}
