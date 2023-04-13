#include<bits/stdc++.h>
using namespace std;

void ViTriSo(int vt){
	switch(vt){
		case 2:
		case 8:
		case 5:
		case 11:
			cout<<"muoi ";
			break;
		case 3:
		case 9:
		case 6:
		case 12:
			cout<<"tram ";
			break;
		case 4:
			cout<<"nghin ";
			break;
		case 7:
			cout<<"trieu ";
			break;
		case 10:
			cout<<"ty ";
			break;	
	}
}

void ChuSo(int so){
	switch(so){
		case 0:
			break;
		case 1:
			cout<<"mot ";
			break;
		case 2: 
			cout<<"hai ";
			break;
		case 3:
			cout<<"ba ";
			break;
		case 4:
			cout<<"bon ";
			break;
		case 5:
			cout<<"nam ";
			break;
		case 6:
			cout<<"sau ";
			break;
		case 7:
			cout<<"bay ";
			break;
		case 8:
			cout<<"tam ";
			break;
		case 9:
			cout<<"chin ";
			break;	
	}
}

void SoHangChuc(int n, int MangSo[]){
	if(MangSo[n-1] == 0 ){
		if( MangSo[n-2]>0){
			cout<<"linh ";
			ChuSo(MangSo[n-2]);
		}
	}else{
		if(MangSo[n-1]==1){
			ViTriSo(n);
			ChuSo(MangSo[n-2]);
		}else{
			for(int i=n-1; i>=0; i--){
				ChuSo(MangSo[i]);
				ViTriSo(i+1);
			}
		}
	}
}

bool kt(int n, int MangSo[]){
	bool t=false;
	for(int i=n-1; i>=0; i--){
		if(MangSo[i]>0){
			t=true;
			break;
		}
	}
	return t;
}

void SoHangTram(int n, int MangSo[]){
	bool t=kt(n,MangSo);
	if(t==true){
		if(MangSo[n-1]==0){
		    cout<<"khong ";
		}
		ChuSo(MangSo[n-1]);
		ViTriSo(n);
		SoHangChuc(n-1,MangSo);
	}
	
}

void SoHangNghin(int n, int MangSo[]){
	bool t=kt(n,MangSo);
	if(t==true){
		ChuSo(MangSo[n-1]);
		ViTriSo(n);
		SoHangTram(n-1,MangSo);
	}else{
		ViTriSo(n);
	}
	
}

void SoHangChucNghin(int n, int MangSo[]){
	bool t=kt(n,MangSo);
	if(MangSo[n-1]==1){
		ViTriSo(n);
		if(t==true){
			SoHangNghin(n-1,MangSo);
		}
	}else{
		if(MangSo[n-1]==0){
			if(t==true){
				if(MangSo[n-2]>0){
					cout<<"linh ";
					SoHangNghin(n-1, MangSo);
				}else{
					SoHangNghin(n-1,MangSo);
				}
			}else{
				ViTriSo(n-1);
			}
		}else{
			ChuSo(MangSo[n-1]);
			ViTriSo(n);
			SoHangNghin(n-1,MangSo);
		}
	}
}

void SoHangTramNghin(int n, int MangSo[]){
	if(MangSo[n-1]>0){
		ChuSo(MangSo[n-1]);
		ViTriSo(n);
		SoHangChucNghin(n-1,MangSo);	
	}else{
		bool t=kt(n-1, MangSo);
		if(t==true){
			cout<<"khong ";
			ViTriSo(n);
			SoHangChucNghin(n-1,MangSo);
		}
	}
}

void SoHangTrieu(int n, int MangSo[]){
	ChuSo(MangSo[n-1]);
	ViTriSo(n);
	SoHangTramNghin(n-1,MangSo);
}

void SoHangChucTrieu(int n, int MangSo[]){
	bool t=kt(n, MangSo);
	if(MangSo[n-1]==0){
		if(t==true){
			if(MangSo[n-2]>0){
				cout<<"linh ";
				SoHangTrieu(n-1, MangSo);
			}else{
				SoHangTrieu(n-1,MangSo);
			}
		}else{
			ViTriSo(n-1);
		}
	}else{
		if(MangSo[n-1]==1){
			ViTriSo(n);
			SoHangTrieu(n-1,MangSo);
		}else{
			ChuSo(MangSo[n-1]);
			ViTriSo(n);
			SoHangTrieu(n-1,MangSo);	
		}
	}
}

void SoHangTramTrieu(int n, int MangSo[]){
	if(MangSo[n-1]>0){
		ChuSo(MangSo[n-1]);
		ViTriSo(n);
		SoHangChucTrieu(n-1,MangSo);	
	}else{
		bool t=kt(n-1, MangSo);
		if(t==true){
			cout<<"khong ";
			ViTriSo(n);
			SoHangChucTrieu(n-1,MangSo);
		}
	}
}

void SoHangTy(int n, int MangSo[]){
	ChuSo(MangSo[n-1]);
	ViTriSo(n);
	SoHangTramTrieu(n-1,MangSo);
}

void SoHangChucTy(int n, int MangSo[]){
	bool t=kt(n, MangSo);
	if(MangSo[n-1]==0){
		if(t==true){
			if(MangSo[n-2]>0){
				cout<<"linh ";
				SoHangTy(n-1, MangSo);
			}else{
				SoHangTy(n-1,MangSo);
			}
		}else{
			ViTriSo(n-1);
		}
	}else{
		if(MangSo[n-1]==1){
			ViTriSo(n);
			SoHangTy(n-1,MangSo);
		}else{
			ChuSo(MangSo[n-1]);
			ViTriSo(n);
			SoHangTy(n-1,MangSo);	
		}
	}
}

void SoHangTramTy(int n, int MangSo[]){
	ChuSo(MangSo[n-1]);
	ViTriSo(n);
	SoHangChucTy(n-1,MangSo);
}

void GoiHam(int n, int MangSo[]){
	switch(n){
		case 1:
			ChuSo(MangSo[n-1]);
			break;
		case 2:
			SoHangChuc(n,MangSo);
			break;
		case 3:
			SoHangTram(n,MangSo);
			break;
		case 4:
			SoHangNghin(n,MangSo);
			break;
		case 5:
			SoHangChucNghin(n,MangSo);
			break;
		case 6:
			SoHangTramNghin(n,MangSo);
			break;
		case 7:
			SoHangTrieu(n,MangSo);
			break;
		case 8:
			SoHangChucTrieu(n,MangSo);
			break;
		case 9:
			SoHangTramTrieu(n,MangSo);
			break;
		case 10:
			SoHangTy(n,MangSo);
			break;
		case 11:
			SoHangChucTy(n,MangSo);
			break;
		case 12:
			SoHangTramTy(n,MangSo);
			break;
	}
}

int main(){
	long long n;
	do{
		cout<<"Nhap 1 so bat ki: ";
		cin>>n;
		int dem=0, tmp;
		int MangSo[14];
		for(int i=0; n>0; i++){
			MangSo[i]=n%10;
			n=n/10;
			dem++;
		}
		GoiHam(dem,MangSo);
		cout<<"dong ";
		cout<<endl;
	}while(n==0);
	
}
