#include<iostream.h>
#include<string>
void find(char a[],char b[]);
void main(){
	char a[256],b[256];
	cout<<"ÇëÊäÈë×Ö·û´®"<<endl;
	cin>>a;
	cout<<"ÇëÊäÈëÐ¡×Ö·û´®"<<endl;
	cin>>b;
	find(a,b);
}

void find(char a[],char b[]){
	int i=0,t=0,l1=strlen(a),l2=strlen(b);
	char *p1=a,*p2=b;
	if(l1<l2){
		cout<<"error"<<endl;
	}else{
		for(;i<l1;i++,p1++){
			if(*p1==*p2){
				if(l1-i<l2){
					cout<<"error"<<endl;
				}else{
					for(;t<l2;t++,p1++,p2++){
						if(*p1!=*p2){
							cout<<"error"<<endl;
							break;
							break;
						}
					}
					cout<<i+1<<endl;
				}
			}
		}
	}
}
