#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

//开运算=先腐蚀+后膨胀   输入图像+结构元素 
int main(){
	int hn=0,wm=0;
	int hf=0,wf=0;
	cin>>hf>>wf>>hn>>wm;
	
	//腐蚀和膨胀运算需要结构元先反射，本题反射前后并无变化故省略 
	vector<vector<int>> tmp(hn,vector<int>(wm,0)) ;
	vector<vector<int>> src(hn,vector<int>(wm,0)) ;//待处理灰度二值图像 
	vector<vector<int>> out(hn,vector<int>(wm,0)) ;
	
	for(int i=0;i<hn;i++){
		for(int j=0;j<wm;j++){
			cin>>src[i][j];
			tmp[i][j]=0;
		}
	}
	//腐蚀运算
	for(int i=0;i<hn;i++){
		for(int j=0;j<wm;j++){
			
			for(int m=-hf/2;m<=hf/2;m++){
				for(int n=-wf/2;n<=wf/2;n++){
					if((i+m)<0||(n+j)<0||(i+m)>=hn||(j+n)>=wm||!src[i+m][j+n]) goto A; 
				}	
			}
			tmp[i][j]=255;
			A:;
		} 
	} 
	
	
	//膨胀运算
	for(int i=0;i<hn;i++){
		for(int j=0;j<wm;j++){
			if(!tmp[i][j]) continue;
			for(int m=-hf/2;m<=hf/2;m++){
				for(int n=-wf/2;n<=wf/2;n++){
					if((i+m)<0||(n+j)<0||(i+m)>=hn||(j+n)>=wm) continue; 
					out[i+m][j+n]=255;
				}	
			}
		} 
	}
	
	/* 
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
	*/
	
	for(int i=0;i<hn;i++){
		for(int j=0;j<wm-1;j++){
			cout<<out[i][j]<<" ";
		}
		cout<<out[i][wm-1]<<endl;
	}
} 
