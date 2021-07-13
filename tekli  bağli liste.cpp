#include<iostream>
void menu();
void dugumOlusturma(int  deger);
void BasaEkleme(int deger);
void elemanlariGosterme();
void bastakiniSilme();
void arama(int deger);
void sondakiniSilme();
void sonaEkleme(int deger);
void say();
void hepsiniSil();
void dugumdensonrakiniSilme(int deger);
using namespace std;
struct node{
	int data;
	node *next;
};
node *phead=NULL;
node *ptail=NULL;
void  menu(){
	cout <<"TEK BAGLÝ LÝSTE MENUSU" << endl;
	 cout  << "1 Dugum olusturma"<<endl;
	 cout << "2 Liste basina eleman ekleme" << endl;
	 cout << "3 Liste elemanlarini gösterme" << endl;
	 cout << "4 Liste basindaki elemanin silinmesi"<< endl;
	 cout << "5 Liste uzerinde arama"<< endl;
	 cout << "6 Liste sonundaki elemanin silinmesi"<<endl;
	 cout << "7 Liste sonuna eleman ekleme"<< endl;
	 cout << "8 Listedeki elemanlari sayma" <<endl;
	 cout <<"9 Listedeki butun elemanlari sil"<< endl;
	 cout << "0 Cir dugumden sonraki dugumu silme" << endl;
	 cout << "-1 Cikis islemleri" << endl;
}
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
				BasaEkleme( veri);
				break;
			}
			case 3:{
				cout << "elemanlari gosterme islemi" << endl;
				elemanlariGosterme();
				break;
			}
			case 4:{
				cout << "liste basindaki elemani silme islemi";
				bastakiniSilme();
				break;
			}
			case 5:{
				int veri;
				cout << "arama islemi icin aranacak elemani giriniz=";
				cin>>veri;
				arama(veri);
				break;
			}
			case 6:{
				cout << "liste sonundaki elemani silme islemi";
				sondakiniSilme();
				break;
			}
			case 7:{
				int veri;
				cout << "liste sonuna eleman ekleme islemi icin eleman giriniz=";
				cin >> veri;
				sonaEkleme(veri);
			
				break;
			}
			case 8:{
				cout << "sayma islemi";
				say();
				break;
			}
			case 9:{
				cout << "listeyi silme islemi";
				hepsiniSil();
				break;
			}
			case 0:{
				cout << "hangi dügümden sonrakini silmek istersiniz=";
				int veri;
				cin >> veri;
				dugumdensonrakiniSilme(veri);
				break;
			}
			case -1:{
				cout << "Cikmak icin 1 i tuslayiniz.";
				int veri;
				cin >> veri;
				if(veri==1){
					cikis=1;
				}
				break;
			}	
			
		}
	}
	 
	 
}

void dugumOlusturma(int  deger){
	node *p=new node();
	p->data=deger;
	p->next=NULL;
	if(phead==NULL){
		phead=p;
		ptail=p;
	}
	else{
		ptail->next=p;
		ptail=p;	
	}
	
}
void BasaEkleme(int deger){
	node *temp=new node;
	temp->data=deger;
	if(phead==NULL){
		phead->data=deger;
	}
	else{
		temp->next=phead;
		phead=temp;
	}
	
}
void elemanlariGosterme(){
	node *temp=phead;
	while(temp!=NULL){
		cout << temp->data << "   ";
		temp=temp->next;
	}
	cout << endl;
	
}
void bastakiniSilme(){
	if(phead!=NULL){
		node *temp=phead;
		phead=phead->next;
		delete temp;
	}
	else{
		cout << "liste bos";
	}
}
void arama(int deger){
	node *temp=phead;
	int a=0;
	while(temp!=NULL and temp->data==deger){
		temp=temp->next;
		a++;
	}
	cout << temp->data << " elemaný= " << a <<". sýradadadir.";
}
void sondakiniSilme(){
	node *temp=phead;
	while(temp!=NULL){
		temp=temp->next;
	}
	delete temp;
}
void sonaEkleme(int deger){
	node *temp=phead;
	while(temp!=NULL){
		temp=temp->next;
	}
	temp->data=deger;
}
void say(){
	int count=0;
	node *temp=phead;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	cout << "listedeki eleman sayisi =" << count;
}
void hepsiniSil(){
	node *temp=phead;
	while(temp!=NULL){
		
		temp=temp->next;
		delete temp;
			
	}
	
}
void dugumdensonrakiniSilme(int deger){
	node *silme= new node;
	silme=phead;
	node *temp= silme;
	while(temp!=NULL && temp->data!=deger){
		temp=silme;
		silme=silme->next;
	}
	temp->next=temp->next->next;
	delete silme;
	
}


