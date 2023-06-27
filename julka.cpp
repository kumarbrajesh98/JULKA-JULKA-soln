#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
char digitToChar(int digit){
     return digit + '0';
}
 
int charToDigit(char ch){
     return ch - '0';
}
 
string addNumbers(string n1, string n2){
 
     if(n1.length() > n2.length()){
          swap(n1,n2);
     }

     string result ="";

     reverse(n1.begin(),n1.end());
     reverse(n2.begin(),n2.end());
 
     int carry = 0;
 
     for(int i=0; i < n1.length(); i++){
          int d1 = charToDigit(n1[i]);
          int d2 = charToDigit(n2[i]);
          int sum = d1 + d2 + carry;
          int output_digit = sum % 10;
          carry = sum/10;
 
          result.push_back(digitToChar(output_digit));
     }
 
 
     for(int i = n1.length(); i < n2.length(); i++){
          int d2 = charToDigit(n2[i]);
          int sum = d2 + carry;
          int output_digit = sum % 10;
          carry = sum/10;
          result.push_back(digitToChar(output_digit));
     }
 
     if(carry)
     {
          result.push_back('1');
     }
 
     reverse(result.begin(), result.end());
     return result;
}
 
string subnumbers(string n1,string n2){
     int k=0;
     string res="";
     string ans="";
 
     reverse(n1.begin(), n1.end());
     reverse(n2.begin(), n2.end());
 
     for (int i = 0; i < n2.length(); ++i)
     {
          if(n1[i]<n2[i]){
               n1[i+1]--;
               ans.push_back(digitToChar(n1[i]-n2[i]+10));
          }
          else{
               ans.push_back(digitToChar(n1[i]-n2[i]));
          }
     }
 
     for (int i = n2.length(); i < n1.length(); ++i) ans.push_back(n1[i]);
 
     reverse(ans.begin(), ans.end());
 
     for (; k < ans.length(); ++k)
     {
          if(ans[k]!='0') break;
     }
 
     for (int i = k; i < ans.length(); ++i)
     {
          res.push_back(ans[i]);
     } 
 
    if(res.size()==0){return "0";}
 
    return res;
}
 
string divideby2(string s){
     string ans="";
     int d=0;
 
     for (int i = 0; i < s.length(); ++i)
     {
         int x=d*10+charToDigit(s[i]);
         if(x%2){
            ans.push_back(digitToChar(x/2)); d=1;
         }
         else{
            ans.push_back(digitToChar(x/2)); d=0;
         }
     }
     if(ans[0]=='0') ans.erase(ans.begin());
 
     return ans;
}
 
int32_t main(){
    int t=10;

    while(t--){
    string s1,s2; cin>>s1>>s2;
 
    string x=addNumbers(s1,s2);
    string y=subnumbers(s1,s2);
 
    string ll=divideby2(x);
    string yy=subnumbers(s1,ll);
 
    cout<<ll<<' '<<yy<<'\n';    
    }
} 