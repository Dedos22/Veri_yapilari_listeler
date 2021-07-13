#include<iostream>
using namespace std;
void basaEkleme(int deger);
void sonaEkleme(int deger);
void dugumOlusturma(int deger);
void dugumleriGoster();
void elemanArama(int deger);

void  menu(){
	cout<<endl <<"DAÝRESEL BAGLÝ LÝSTE MENUSU" << endl;
	 cout  << "1 Dugum olusturma"<<endl;
	 cout << "2 Liste basina eleman ekleme" << endl;
	 cout << "3 Liste elemanlarini gösterme" << endl;
	 cout << "4 ssona eleman ekleme"<< endl;
	 cout << "5 elemanlari arama"<<endl;
	 cout << "-1 Cikis islemleri" << endl;
}
struct Node{
	int data;
	Node *next;
};
Node *phead=NULL;
Node *ptail=NULL;
int main(){
		bool cikis=0;
		while(cikis!=1){
				menu();
		int secim;
		cout << "hangi islemi yapmak istiyorsunuz=";
		cin >>secim;
		switch(secim){
			case 1:{
				cout << "dugum olusturma islemi " << endl <<"ne kadar eleman girmek istersiniz=";
				int n;
				cin>>n;
				for(int i=0;i<n;i++){
					int veri;
					cout << "eleman giriniz=";
					cin >> veri;
					dugumOlusturma(veri);	
				}
				break;
			}
			case 2:{
				int veri;
				cout << "liste basina eleman ekleme iþlemi için eleman giriniz=";
				cin>> veri;
				basaEkleme(veri);
				break;
			}
				case 4:{
				int veri;
				cout << "liste sonuna eleman ekleme iþlemi için eleman giriniz=";
				cin>> veri;
				sonaEkleme(veri);
				break;
			}
			case 5:{
				int veri;
				cout << "arama islemi icin aranacak elemani giriniz=";
				cin>>veri;
				elemanArama(veri);
				break;
			}
			case 3:{
				cout << "elemanlari gosterme islemi" << endl;
				dugumleriGoster();
				break;
			}
			case -1:{
				cout << "Cikmak icin 1 i tuslayiniz.";
				int veri;
				cin >> veri;
				if(veri==1){
					cikis=1;
				}
				break;			}
				
	}

		}
	
}
void dugumOlusturma(int deger){
	Node *p=new Node;
	p->data=deger;
	p->next=NULL;
	if(phead==NULL){
		phead=p;
		ptail=p;
	}else{
		ptail->next=p;
		ptail=p;
		ptail->next=phead;
		
	}
	
	
	
}
void dugumleriGoster(){
	Node *p=phead;

	do{
		cout << p->data <<" ";
		p=p->next;
	
	}
	while(p!=phead);
	
	
	
}
void basaEkleme(int deger){
	Node *p=new Node;
	
	p->data=deger;
	p->next=NULL;
	if(phead==NULL){
		phead=p;
		ptail=p;
		
	}else{
		p->next=phead;
		phead=p;
		ptail->next=phead;	
	}
	
}
void sonaEkleme(int deger){
	Node *p=new Node;
	p->data=deger;
	if(phead==NULL){
		phead->next=p;
		ptail=p;
		ptail->next=phead;
	}else{
		ptail->next=p;
		ptail=p;
		ptail->next=phead;	
	}
}
void elemanArama(int deger){
	Node *p=phead;
	int a=0;
	while(p!=NULL and p->data!=deger){
		 p=p->next;
		 a++;
		}
		cout << a <<" siradadir.";
	}

