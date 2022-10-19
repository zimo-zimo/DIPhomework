#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

//Àƒ…·ŒÂ»Î 
int rounding(int temp,int avg){
	double tmp= ((double)temp/avg+0.5);
	return (int)tmp;
}

vector<vector<int>> blur(vector<vector<int>> src,  
    int hf,
    int wf)
{
    vector<vector<int>> rst=src ;
    int hs=src.size();
    int ws=src[0].size();
    
	for(int i=0;i<hs;i++){
		for(int j=0;j<ws;j++){
			int temp=0;
			for(int m=-hf/2;m<=hf/2;m++){
				for(int n=-wf/2;n<=wf/2;n++){
					if((i+m)<0 || (i+m)>=hs ||(j+n)<0 || (j+n)>=ws)
						continue;
					else temp+=src[i+m][j+n];
				} 
			} 
			rst[i][j]=rounding(temp,hf*wf);
		}
	}
	return rst;
}

int main(){
	int hs,ws,hf,wf;
	cin>>hs>>ws>>hf>>wf;
	
	vector<vector<int>> src(hs,vector<int>(ws,0)) ;
	vector<vector<int>> rst(hf,vector<int>(wf,0)) ;
	for(int i=0;i<hs;i++){
		for(int j=0;j<ws;j++){
			cin>>src[i][j];
		}
	}
	
	rst=blur(src,hf,wf);
	
	for(int i=0;i<hs;i++){
		for(int j=0;j<ws;j++){
			cout<<rst[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
