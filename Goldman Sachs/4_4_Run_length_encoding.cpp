string encode(string s)
{     
  int n = s.length();
  string ans = "";
  ans+=s[0];
  int c=1,i=1;
  while(i<n)
  {
      if(s[i]==s[i-1])
      {
          c++;
      }
      else
      {
          ans+=(c+'0');
          ans+=s[i];
          c=1;
      }
      i++;
  }
  ans+=(c+'0');
  return ans;
}     
 
