#include<bits/stdc++.h>
//11 12 13    31 21 11
//21 22 23    32 22 12
//31 32 33    33 23 13 
using namespace std;
char t[11][11],c[11][11],a[11][11],b[11][11];
int n;
void method1(char a[11][11],char b[11][11]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			b[j][n-1-i]=a[i][j];
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++)
//			if(b[i][j]==c[i][j]) continue;
//			else return 0;
//	}
//	return 1;
}
void method2(char a[11][11],char b[11][11]){
	method1(a,b);
	copy(b,b+n*n,t);
	method1(t,b);
}
void method3(char a[11][11],char b[11][11]){
	method1(a,b);
	copy(b,b+n*n,t);
	method1(t,b);
	copy(b,b+n*n,t);
	method1(t,b);
}
void method4(char a[11][11],char b[11][11]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
    		b[i][n-1-j]=a[i][j];
	}
}
bool method5(char a[11][11],char b[11][11]){
	bool flag=true;
	method4(a,b);
	copy(b,b+n*n,t);
	method1(t,b);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(b[i][j]==c[i][j]) continue;
			else{
				flag=false;
				break;
			} 
	}
	copy(b,b+n*n,t);
	method1(t,b);
	if(!flag)for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(b[i][j]==c[i][j]) continue;
			else{
				flag=false;
				break;
			} 
	}
	copy(b,b+n*n,t);
	method1(t,b);
	if(!flag)for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(b[i][j]==c[i][j]) continue;
			else{
				flag=false;
				break;
			} 
	}
	return flag;
}
bool method6(char a[11][11],char b[11][11])
{
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++)
    		if(b[i][j]!=c[i][j])
    		return 0;
    return 1;
}
bool judge(char a[11][11],char b[11][11]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(b[i][j]==c[i][j]) continue;
			else return 0;
	}
	return 1;
}

int main(){
	char a[11][11],b[11][11];
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c[i][j];
		}
	}
	method1(a,b);
	if(judge(a,b)){
		cout<<1;
		return 0;
	}
	method2(a,b);
	if(judge(a,b)){
		cout<<2;
		return 0;
	}
	method3(a,b);
	if(judge(a,b)){
		cout<<3;
		return 0;
	}
	method4(a,b);
	if(judge(a,b)){
		cout<<4;
		return 0;
	}
	if(method5(a,b)){
		cout<<5;
		return 0;
	}
	if(method6(a,b)){
		cout<<6;
		return 0;
	}
	cout<<7;
	return 0;
} 

