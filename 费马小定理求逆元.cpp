#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<string>
#define endl '\n'
#define longlong ll
using namespace std;

//ÊµÏÖa^n%p 
long long mypow(long long a,long long n,long long p){
	long long ans = 1;
	while(n){
		if(n&1) ans = ans* a%p;
		a = a*a%p;
		n = n>>1;
	}
	return ans;
}

int main(){
	long long n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cout<<mypow(i,p-2,p)<<endl;
	}
}
