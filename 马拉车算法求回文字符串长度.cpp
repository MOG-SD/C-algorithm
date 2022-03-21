#include <bits/stdc++.h>
using namespace std;

//求出字符串s每个字符为中心作回文字符串分别对应的长度 
void manacher(string s,int *length){
	int R=0,C=0;
	for(int i = 0;s[i] !='\0';++i){
		if(i>R){
			length[i] = 1;
		}else{
			length[i] = length[2*C-i]>R-i+1 ? R-i+1 : length[2*C-i];
		}
		while(s[i+length[i]] == s[i-length[i]]&&i+length[i]<s.length()&&i-length[i]>=0){
			length[i]++;
		}
		length[i]--;
		if(i+length[i]-1>R){
			R = i+length[i]-1;
			C = i;
		}
	}
}

int main(){
	int ans = 0,length[2001];
	string s;
	cin>>s;
	for(int i=s.length();i>=0;i--)
		s.insert(i,"#");
	manacher(s,length);
	for(int i=0;s[i] != '\0';i++)
		ans = max(ans,length[i]);
	cout<<ans;
}
