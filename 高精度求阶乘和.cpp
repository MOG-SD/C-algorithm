#include<iostream>
#include<cstring>
using namespace std;
/*
int n,a[90],b[90],c[90],f[90],d=0,len_a,len_b=1,len_c=1,len_ans,m=1;
string s;
int main(){
    cin>>n;
    b[0]=1; //��ʼ��
    for(int i=1;i<=n;i++){ //����i�Ľ׳ˣ��Ѿ������i-1�Ľ׳�
        len_a=0; //i�ĳ���
        int p=i;
        while(p>0){ //��i���a����
            a[len_a++]=p%10;
            p/=10;
        }
        for(int j=0;j<len_a;j++) //����a*b��i*��i-1���Ľ׳ˣ�����i�Ľ׳ˣ������������ϲ飬��Ҳ��֪��Ϊʲô
            for(int k=0;k<=len_b;k++)
                c[j+k]+=a[j]*b[k];
        for(int j=0;j<len_c;j++) //��Ҫ��λ�ľͽ�λ
            if(c[j]>9) c[j+1]+=c[j]/10,c[j]%=10;
        if(c[len_c]) len_c++; //�����λҪ��Ҫ��λ
        len_ans=len_b,len_b=len_c,m=max(m,len_c); //��len_b��ֵ��len_ans���޸�len_b��ֵ��mΪi�׳˵ĳ��ȣ�����û�н�λ
        for(int k=len_c-1;k>=0;k--) b[k]=c[k]; //��c���b���飬�����i�Ľ׳ˣ��´�ѭ��bΪi-1�Ľ׳�
        len_c=len_a+len_ans;
        memset(c,0,sizeof(c)); //����c���飬׼�������¸��׳�
        for(int j=0;j<m;j++){ //�߾��ӣ�ֱ����ģ��
            f[j]+=b[j];
            if(f[j]>9) f[j+1]+=f[j]/10,f[j]%=10; //��λ��ע�ⲻҪд��f[j+1]++��f[j]-=10;����Ϊ����wa��һ����
        }
    }
    while(!f[m]&&m>0) m--; //ȥ���׵���
    for(int i=m;i>=0;i--) cout<<f[i]; //�������
    return 0; //Բ������
}
*/
int main(){
	int n,a[100],b[100]={1,0},c[100]={0},r[100]={0},len_a=0,len_b=1,len_c=1,len_t;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m=i;
		len_a=0;
		for(int j=0;m!=0;j++){
			a[j]=m%10,m/=10,len_a++;
		}
		for(int j=0;j<len_a;j++){
			for(int k=0;k<len_b;k++){
				c[j+k]+=a[j]*b[k];
			}
		}
		for(int j=0;j<len_c;j++){
			if(c[j]>9) c[j+1]+=c[j]/10,c[j]%=10;
		}
		for(int j=0;j<len_c;j++){
			b[j]=c[j];
		}
		memset(c,0,sizeof(c));
		
		len_t=len_c,len_c=len_a+len_t,len_b=len_t;
		for(int j=0;j<=len_c;j++){
			r[j]+=b[j];
			if(r[j]>9) r[j+1]+=r[j]/10,r[j]%=10;
		}
	}
	while(!r[len_c])
		len_c--;
	for(int i=len_c;i>=0;i--)
		cout<<r[i];
	return 0;
}
