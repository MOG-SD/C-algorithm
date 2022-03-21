#include <bits/stdc++.h>
using namespace std;

int cnt=0;

//�жϵ�row�У�line���ǲ��ǲ��ܷ�����
bool IsDanger(int row,int line,char (*chess)[9]){
	for(int i=1,j=line;i<9;i++){//�ж��� 
		if(chess[i][j]!='0') return true;
	}
	for(int i=row,j=line;i>0&&j>0;i--,j--){//�ж����� 
		if(chess[i][j]!='0') return true;
	}
	for(int i=row,j=line;i>0&&j<9;i--,j++){//�ж����� 
		if(chess[i][j]!='0') return true;
	}
	for(int i=row,j=line;i<9&&j>0;i++,j--){//�ж����� 
		if(chess[i][j]!='0') return true;
	}
	for(int i=row,j=line;i<9&&j<9;i++,j++){//�ж����� 
		if(chess[i][j]!='0') return true;
	}
	return false;
}
//�ڵ�row���Һ��ʵ��н������ӷ��� 
void EightQueen(int row,char (*chess)[9]){//���ﲻ�����԰ٶȡ�c��������ô�ö�ά������Ϊ����������
	char chess2[9][9];
	for(int i=1;i<9;i++){
		for(int j=1;j<9;j++){
			chess2[i][j]=chess[i][j];
		}
	}
	if(row == 9){
		printf("��%d�ֽⷨ\n",++cnt);
		for(int i=1;i<9;i++){
			for(int j=1;j<9;j++){
				printf("%c ",chess2[i][j]);
			}
			printf("\n");
		}
	}else{
		for(int j=1;j<9;j++){
			if(IsDanger(row,j,chess)){
				continue;
			}else{
				memset(chess2[row],'0',sizeof(chess2[0]));
				chess2[row][j]='1';
				EightQueen(row+1,chess2);
			}
		}
	}
}
int main() {
	char chess[9][9];
	memset(chess,'0',sizeof(chess));
	EightQueen(1,chess);
	return 0;
}
