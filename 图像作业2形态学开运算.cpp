#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

//������=�ȸ�ʴ+������   ����ͼ��+�ṹԪ�� 
int main(){
	int hn=0,wm=0;
	int hf=0,wf=0;
	cin>>hf>>wf>>hn>>wm;
	
	//��ʴ������������Ҫ�ṹԪ�ȷ��䣬���ⷴ��ǰ���ޱ仯��ʡ�� 
	vector<vector<int>> tmp(hn,vector<int>(wm,0)) ;
	vector<vector<int>> src(hn,vector<int>(wm,0)) ;//������Ҷȶ�ֵͼ�� 
	for(int i=0;i<hn;i++){
		for(int j=0;j<wm;j++){
			cin>>src[i][j];
			tmp[i][j]=0;
		}
	}
	
	
	for(int i=hf/2;i<hn-hf/2;i++){
		for(int j=wf/2;j<wm-wf/2;j++){
			
			for(int n=0;n<hf;n++){
				for(int m=0;m<wf;m++){
					if((src[i+n][j+m]==0)||((i+n)==hn-hf/2)||((j+m)==wm-wf/2))
						goto A;
				}
			}
			tmp[i][j]=1;
			for(int n=0;n<hf;n++){
				for(int m=0;m<wf;m++){
					tmp[i+n][j+m]=255;
				}
			}
			
			A:;
		}
	}
	
	for(int i=0;i<hn;i++){
		for(int j=0;j<wm-1;j++){
			cout<<tmp[i][j]<<" ";
		}
		cout<<tmp[i][wm-1]<<endl;
	}
} 
