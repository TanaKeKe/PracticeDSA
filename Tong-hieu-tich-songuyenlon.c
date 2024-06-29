#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void tong(char a[],char b[]){
	int len1=strlen(a),len2=strlen(b);
	if(len1>len2){
		for(int i=len2;i<len1;++i) b[i]='0';
	}
	else{
		if(len1<len2){
			for(int i=len1;i<len2;++i){
				a[i]='0';
			}
		}
	}
	int max=len1;
	if(max<len2) max=len2;
	int add[max+5],cnt=0;
	int nho=0;
	for(int i=0;i<max;++i){
		int sum=a[i]-'0'+b[i]-'0'+nho;
		add[cnt++]=sum%10;
		nho=sum/10;
	}
	if(nho!=0) add[cnt++]=nho;
	while(add[cnt-1]==0) --cnt;
	for(int i=cnt-1;i>=0;--i) printf("%d",add[i]);
}
void hieu(char a[],char b[]){
	int len1=strlen(a),len2=strlen(b);
	if(len1>len2){
		for(int i=len2;i<len1;++i) b[i]='0';
	}
	else{
		if(len1<len2){
			for(int i=len1;i<len2;++i){
				a[i]='0';
			}
		}
	}
	strrev(a);strrev(b);
	if(strcmp(a,b)==0) printf("0");
	else{
		if(strcmp(a,b)>0){
			strrev(a);strrev(b);
			int len1=strlen(a),len2=strlen(b);
			int c[len1+5],cnt=0,nho=0;
			for(int i=0;i<len1;++i){
				if(a[i]<b[i]+nho){
					int hieu1=(a[i]-'0')+10-(b[i]-'0')-nho;
					c[cnt++]=hieu1%10;
					nho=1;
				}
				else{
					int hieu1=a[i]-b[i]-nho;
					c[cnt++]=hieu1%10;
					nho=0;
				}
			}
			while(c[cnt-1]==0) --cnt;
			for(int i=cnt-1;i>=0;--i) printf("%d",c[i]);
		}
		else{
			strrev(a);strrev(b);
			int len1=strlen(a),len2=strlen(b);
			int c[len1+5],cnt=0,nho=0;
			for(int i=0;i<len1;++i){
				if(b[i]<a[i]+nho){
					int hieu1=(b[i]-'0')+10-(a[i]-'0')-nho;
					c[cnt++]=hieu1%10;
					nho=1;
				}
				else{
					int hieu1=b[i]-a[i]-nho;
					c[cnt++]=hieu1%10;
					nho=0;
				}
			}
			while(c[cnt-1]==0) --cnt;
			printf("-");
			for(int i=cnt-1;i>=0;--i) printf("%d",c[i]);	
		}
	}
}
int x[1000005],y[1000005],tich123[1000005];
void tich(char a[],char b[]){
	int len1=strlen(a),len2=strlen(b);
	// day dau tien dem di cong
	int nho=0,x1=0;
	for(int j=0;j<len1;++j){
		int tich1=(b[0]-'0')*(a[j]-'0')+nho;
		x[x1++]=tich1%10;
		nho=tich1/10;
	}
	if(nho!=0) x[x1++]=nho;
	// cac day tiep theo
	for(int i=1;i<len2;++i){
		int y1=i,nho=0;
		for(int j=0;j<y1;++j) y[j]=0;
		for(int j=0;j<len1;++j){
			int tich1=(b[i]-'0')*(a[j]-'0')+nho;
			y[y1++]=tich1%10;
			nho=tich1/10;
		}
		if(nho!=0) y[y1++]=nho;
		while(x1<=y1) x[x1++]=0;
		while(y1<=x1) y[y1++]=0;
		int nho1=0,cnt=0;
		// tong 2 day
		for(int z=0;z<x1;++z){
			int sum=x[z]+y[z]+nho1;
			tich123[cnt++]=sum%10;
			nho1=sum/10;
		}
		if(nho1!=0) tich123[cnt++]=nho1;
		// reset
		for(int j=0;j<x1;++j) x[j]=0;
		x1=0;
		for(int j=0;j<y1;++j) y[j]=0;
		y1=0;
		// gan tong lan nhau vao x[]
		for(int j=0;j<cnt;++j){
			x[x1++]=tich123[j];
		}
		// reset
		for(int j=0;j<cnt;++j) tich123[j]=0;
	}
	while(x[x1-1]==0) --x1;
	for(int i=x1-1;i>=0;--i) printf("%d",x[i]);
}
int main(){
	char a[1000005],b[1000005];
	gets(a);
	gets(b);
	strrev(a);strrev(b);
	tong(a,b);
	printf("\n");
	hieu(a,b);
	printf("\n");
	tich(a,b);
}