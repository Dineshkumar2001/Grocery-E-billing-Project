// E-billing Project By Rahul
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<fstream>

using namespace std;

fstream file, file1;

class Product{
	int p_no;
	string name;
	float price, qty, tax, dis;
	public:
		void create();
		void show();
		void write();
		void display();
		void admin();
		void search(int n);
		void modify(int n);
		void del(int n);
		void order();
		void menu();
};

//for creation of new product:

void Product::create(){
	cout<<"\n\n Please Enter The Product No. Of The Product \n";
	cin>>p_no;
	cout<<"\n\n Please Enter The Product Name Of The Product \n";
	cin>>name;
	cout<<"\n\n Please Enter The Product Price Of The Product \n";
	cin>>price;
	cout<<"\n\n Please Enter The Product Discount Of The Product \n";
	cin>>dis;
}

//showing specific product:

void Product:: show(){
	cout<<"\n The Product No. of The Product : "<<p_no;
	cout<<"\n The Name of the Product : "<<name;
	cout<<"\n The Price Of The Product : "<< price;
	cout<<" \n Discount : "<<dis<<"%";
}

//writing a product details:

void Product:: write(){
	file.open("shop.txt",ios::out|ios::app);
	create();
	file<<" "<<p_no<<" "<<name<<" "<<price<<" "<<dis;
	file.close();
	cout<<"\n\nThe Product Has Been Created ";
	getch();
}

//display all products:

void Product::display(){
	system("cls");
	cout<<"n\n\n\tDisplay All Record !!!\n\n";
	file.open("shop.txt",ios::in);
	if(!file)
		admin();
	file>>p_no>>name>>price>>dis;
	while(!file.eof()){
		show();
		cout<<"\n\n==============================\n";
		file>>p_no>>name>>price>>dis;
	}
	file.close();
	getch();
}

//admin access section

void Product::admin(){
	system("cls");
	int choice;
	cout<<"\n\n\n\tADMIN MENU";
	cout<<"\n\n\n\tCREATE PRODUCT";
	cout<<"\n\n\n\tDISPLAY ALL PRODUCT";
	cout<<"\n\n\n\tSEARCH PRODUCT";
	cout<<"\n\n\n\tMODIFY PRODUCT";
	cout<<"\n\n\n\tDELETE PRODUCT";
	cout<<"\n\n\n\tVIEW PRODUCT MENU";
	cout<<"\n\n\n\tBACK TO MAIN MENU";
	cout<<"\n\n\n\tPlease Enter Your Choice (1-7)";
	cin>>choice;
	switch(choice){
		case 1: system("cls");
			write();
			break;
		case 2: display();
			break;
		case 3:
			int num;
			system("cls");
			cout<<"\n\n\tPlease Enter The  Product No.";
			cin>>num;
			search(num);
			break;
		case 4:
			system("cls");
			cout<<"\n\n\t Please Enter The Product No.";
			cin>>num;
			search(num);
			break;
	}

}

//seaching an a product:

void Product::search(int n){
	int found=0;
	file.open("shop.txt",ios::in);
	if(!file)
		admin();
	file>>p_no>>name>>price>>dis;
	while(!file.eof()){
		if(p_no==n){
			system("cls");
			show();
			found=1;
		}
		file>>p_no>>name>>price>>dis;
	}
	file.close();
	if(found==0)
		cout<<"\n\nrecord not extst";
	getch();
}

//modify the product details:

void Product::modify(int n){
	int found=0;
	system("cls");
	cout<<"\n\n\tTo Modify";
	file.open("shop.txt",ios::in);
	if(!file)
		admin();
	file1.open("shop1.txt",ios::out|ios::app);
	file>>p_no>>name>>price>>dis;
	while(!file.eof()){
		if(p_no==n){
			show();
			cout<<"\n\n Please Enter The New Details";
			create();
			file1<<" "<<p_no<<" "<<name<<" "<<price<<" "<<dis;
			cout<<"\n\n\t Record Updated";
			found=1;
		}
		else
			file<<" "<<p_no<<" "<<name<<" "<<price<<" "<<dis;
		file>>p_no>>name>>price>>dis;
	}
	file.close();
	file1.close();
	remove("shop.txt");
	rename("shop1.txt","shop.txt");
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}

//deltion of a product from list:

void Product::del(int n){
	int found=0;
	file.open("shop.txt",ios::in);
	if(!file)
		admin();
	file1.open("shop1.txt",ios::out);
	file>>p_no>>name>>price>>dis;
	while(!file.eof()){
		if(p_no==n){
			cout<<"\n\n\t Record Deleted";
			found=1;
		}
		else
			file1<<" "<<p_no<<" "<<name<<" "<<price<<" "<<dis;
		file>>p_no>>name>>price>>dis;
	}
	file.close();
	file1.close();
	remove("shop.txt");
	rename("shop1.txt","shop.txt");
	if(found==0)
		cout<<"\n\n Record Not Found";
	getch();
}

//menu of product:

void Product::menu(){
	system("cls");
	file.open("shop.txt",ios::in);
	cout<<"\n\n\t\tProduct Menu\n\n";
	cout<<"================================\n";
	cout<<"P.NO.\t\tNAME\t\t PRICE\n";
	cout<<"================================\n";
	file>>p_no>>name>>price;
	while(!file.eof()){
		cout<<p_no<<"\t\t"<<name<<"\t\t"<<price<<"\n"<<"\t\t"<<dis;
		file>>p_no>>name>>price>>dis;
	}
	file.close();
}

//orders:

void Product:: order(){
	int order_arr[50],quan[50],c=0;
	float amt=0,damt=0,total=0;
	char ch;
	file.open("shot.txt",ios::in);
	if(file){
		file.close();
		menu();
		cout<<"\n========================";
		cout<<"\n    Place Your Order";
		cout<<"\n========================\n";
		do{
			cout<<"\n\n Enter The Product No. Of the Required Product:";
			cin>> order_arr[c];
			cout<<"\n Quantity in number: ";
			cin>>quan[c];
			c++;
			cout<<"\n Do You Want To Order Another Product";
			cin>>ch;
		}
		while(ch=='y'|| ch=='Y');
		cout<<"\n\n Thank You For Placing The Order:";
		getch();
		cout<<"\n\n*****************************";
		cout<<"\n Product No. \t Product Name\t Quantity\tPrice \tAmount \tAmount after discount";
		for(int x=0;x<=c;x++){
			file.open("shop.txt",ios::in);
			file>>p_no>>name>>price>>dis;
			while(!file.eof()){
				if(p_no==order_arr[x]){
					amt=price*quan[x];
					damt=amt-(amt/100*dis);
					cout<<"\n"<<order_arr[x]<<"\t"<<name;
					total+=damt;
				}
				file>>p_no>>name>>price>>dis;
			}
			file.close();
		}
		cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
	getch();
}

int main() 
{
	Product p;
	h:
		int choice;
			system("cls");
			cout<<"\n\n\n\t MAIN MENU";
			cout<<"\n\n\t01. CUSTOMER";
			cout<<"\n\n\t02. ADMIN";
			cout<<"\n\n\t03. EXIT";
			cout<<"\n\n\tPlease Select Your Option (1-3)";
			cin>>choice;
			switch(choice){
				case 1: system("cls");
						p.order();
					getch();
					break;
				case 2: p.admin();
						break;
				case 3: exit(0);
				default : cout<<"\a";
			}
			goto h;

}