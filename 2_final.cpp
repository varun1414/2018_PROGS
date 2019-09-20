<<<<<<< HEAD
#include<iostream>   //MOD
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<dos.h>

using namespace std;
class hotel
{
    int room_no;
    char name[20];
    char address[50];
    char phone[10];
    
    public:
    void main_menu();    //to dispay the main menu
    void add();        //to book a room
    void display();    //to display the customer record
    void rooms();    //to display alloted rooms
    void edit();    //to edit the customer record
    int check(int);    //to check room status
    void modify(int);    //to modify the record
    void delete_rec(int);    //to delete the record
    void getdata()  //accepting values of data members
	{
		 int r,flag;
		cout<<"\n\n\t\t\t\t\t\t\t Room no: ";
    cin>>r;
    flag=check(r);
		if(flag)
        {cout<<"\n\t\t\t\t\t\t\t\t Sorry..!!!Room is already booked";return ;}
		
		room_no=r;
        cout<<"\n\t\t\t\t\t\t Name: ";
       // cin>>name;
       gets(name);
        cout<<"\t\t\t\t\t\t Address: ";
        cin>>address;
        cout<<"\t\t\t\t\t\t Phone No: ";
        cin>>phone;
        cout<<"\n\t\t\t\t\t Room is booked!!!";
	 }
      };
 
void hotel::main_menu()
{
    int choice;
    
    while(choice!=5)
    {
        
       system("cls");
        cout<<"\n\t\t\t\t\t\t\t\t\t**********";
        cout<<"\n\t\t\t\t\t\t\t\t\t* MAIN MENU *";
        cout<<"\n\t\t\t\t\t\t\t\t\t*************";
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t1.Book A Room";
        cout<<"\n\t\t\t\t\t\t\t\t\t2.Customer Record";
        cout<<"\n\t\t\t\t\t\t\t\t\t3.Rooms Allotted";
        cout<<"\n\t\t\t\t\t\t\t\t\t4.Edit Record";
        cout<<"\n\t\t\t\t\t\t\t\t\t5.Exit";
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: add();
                    break;
            case 2: display();
                    break;
            case 3: rooms();
                    break;
            case 4: edit();
                    break;
            case 5: break;
            default:
                    {
                        cout<<"\n\n\t\t\tWrong choice!!!";
                        cout<<"\n\t\t\tPress any key to continue!!";
                        getch();
                    }
        }
    }
}
 
void hotel::add()
{
    
   
    fstream fout;
    hotel h;
	fout.open("Record.dat",ios::binary|ios::app|ios::out);
    cout<<"\n\t\t\t\t\t\t\t\t\t Enter Customer Detalis";
    cout<<"\n\t\t\t\t\t\t\t\t\t **********************";
    
    
    
         
         h.getdata();
        fout.write((char*)&h,sizeof(h));
    
   fout.close();
    cout<<"\n\t\t\t\t\t Press any key to continue!!";
    getch();
}
 
void hotel::display()
{
    system("cls");
    hotel h;
    ifstream fin;
	fin.open("Record.dat",ios::binary|ios::in);
    int r,flag=0;
    cout<<"\n\t\t\t\t\t\t\t Enter room no: ";
    cin>>r;
    while(!fin.eof())
    {
        fin.read((char*)&h,sizeof(h));
        if(h.room_no==r)
        {
            system("cls");
            cout<<"\n\t\t\t\t\t\t\t\t\t Customer Details";
            cout<<"\n\t\t\t\t\t\t\t\t\t ****************";
            cout<<"\n\n\t\t\t\t\t Room no: "<<h.room_no<<endl;
            cout<<"\n\t\t\t\t\tName: "<<h.name<<endl;
            cout<<"\n\t\t\t\t\tAddress: "<<h.address<<endl;
            cout<<"\n\t\t\t\t\tPhone no: "<<h.phone<<endl;
            flag=1;
            break;
        }
        
    }
    if(flag==0)
    cout<<"\n Sorry Room no. not found or vacant!!";
	cout<<"\n\n Press any key to continue!!";
    getch();
    fin.close();
}
 
void hotel::rooms()
{
    system("cls");
    fstream fin;
    hotel h;
	fin.open("Record.dat",ios::binary|ios::in);
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\t\t\t*********************";
    cout<<"\n\n Room No.";
     // fin.read((char*)&h,sizeof(h));
      
    while(fin.read((char*)&h,sizeof(h)))
    {
		//fin.read((char*)&h,sizeof(h));
     //fin.read((char*)&h,sizeof(h));
     cout<<"\n\n "<<h. room_no;
     /* if(!fin.eof())
       {
        cout<<"\n\n "<<room_no;
       }
    else
     break;*/
    }
    fin.close();
    cout<<"\n\n\n\t\t\tPress any key to continue!!";
    getch();
}
 
void hotel::edit()
{
    system("cls");
    int choice,r;
    
    cout<<"\n\t\t\t\t\t\t\t\t\t\t *********";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t EDIT MENU";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t *********";
    cout<<"\n\n\t\t\t\t\t\t\t 1.Modify Customer Record";
    cout<<"\n\t\t\t\t\t\t\t 2.Delete Customer Record";
    cout<<"\n\n\t\t\t\t\t\t\t Enter your choice: ";
    cin>>choice;
    cout<<"\n Enter room no: ";
    cin>>r;
    
    switch(choice)
    {
        case 1: modify(r);
                break;
        case 2: delete_rec(r);
                break;
        default: cout<<"\n\t\t\t\t\t\t Wrong Choice!!";
    }
    
    cout<<"\n Press any key to continue!!!";
    getch();
}
 
int hotel::check(int r)
{
    int flag=0;
    hotel h;
    ifstream fin;
	fin.open("Record.dat",ios::binary|ios::in);
    while(!fin.eof())
    {
        fin.read((char*)&h,sizeof(h));
        if(room_no==r)
        {
            flag=1;
            break;
        }
    }
    fin.close();
    return(flag);
}
 
void hotel::modify(int r)
{
    long pos,flag=0;
    hotel h;
    fstream file;
	file.open("Record.dat",ios::in|ios::out|ios::binary);
    
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)&h,sizeof(h));
        if(h.room_no==r)
        {
            cout<<"\n Enter New Details";
            cout<<"\n *****************";
            cout<<"\n Name: ";
            cin>>h.name;
            cout<<" Address: ";
            cin>>h.address;
            cout<<" Phone no: ";
            cin>>h.phone;
            
            file.seekg(pos);
            file.write((char*)&h,sizeof(h));
            cout<<"\n Record is modified!!";
            flag=1;
            break;
        }
    }
    
    if(flag==0)
        cout<<"\n Sorry Room no. not found or vacant!!";
        
    file.close();
}
 
void hotel::delete_rec(int r)
{
	hotel h;
    ifstream fin;
	fin.open("Record.dat",ios::binary|ios::in);
    ofstream fout;
	fout.open("temp.dat",ios::binary|ios::out);
     
    	fin.read((char*)&h, sizeof(h));
		while(!fin.eof())
		{
			if(h.room_no!=r)
			{
				fout.write((char*)&h, sizeof(h));
			}
			else
			{
				 cout<<endl<<"DELETED"<<endl;
				 cout<<"Press Any Key...."<<endl;
				 getch();
			}
			fin.read((char*)&h, sizeof(h));
		}
	
	fout.close();
	fin.close();
	remove("Record.dat");
	rename("temp.dat", "Record.dat");

 }
 int main()
{
    hotel h;
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t****************************";
    cout<<"\n\t\t\t\t\t\t\t\t* HOTEL MANAGEMENT PROJECT *";
    cout<<"\n\t\t\t\t\t\t\t\t****************************";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\tMade By:";
    cout<<" DHANANJAY PAWAR  1024\n\n";
    cout<<" \t\t\t\t\t\t\t\tUseless People:";
    cout<<" AZIZ SHAIKH  1041\n";
    cout<<"  \t\t\t\t\t\t\t\t\t\tSRISTHI KOLVEKAR  1019\n";
    cout<<"\n\n\n\t\t\t\t\t\t\t\tPress any key to continue!!";
    getch();
    h.main_menu();
}




//void hotel::rooms()
//{
//    system("cls");
//    fstream fin;
//    hotel h;
//	fin.open("Record.dat",ios::binary|ios::in);
//    cout<<"\n\t\t\tList Of Rooms Allotted";
//    cout<<"\n\t\t\t*********************";
  //  cout<<"\n\n Room No.";
 //   while(!fin.eof())
 //   {
  //   fin.read((char*)&h,sizeof(h));
   //   if(!fin.eof())
  //     {
   //     cout<<"\n\n "<<room_no;
   //    }
   // else
  //   break;
  //  }
  //  fin.close();
  //  cout<<"\n\n\n\t\t\tPress any key to continue!!";
//    getch();
//}
=======
#include<iostream>   //MOD
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<dos.h>

using namespace std;
class hotel
{
    int room_no;
    char name[20];
    char address[50];
    char phone[10];
    
    public:
    void main_menu();    //to dispay the main menu
    void add();        //to book a room
    void display();    //to display the customer record
    void rooms();    //to display alloted rooms
    void edit();    //to edit the customer record
    int check(int);    //to check room status
    void modify(int);    //to modify the record
    void delete_rec(int);    //to delete the record
    void getdata()  //accepting values of data members
	{
		 int r,flag;
		cout<<"\n\n\t\t\t\t\t\t\t Room no: ";
    cin>>r;
    flag=check(r);
		if(flag)
        {cout<<"\n\t\t\t\t\t\t\t\t Sorry..!!!Room is already booked";return ;}
		
		room_no=r;
        cout<<"\n\t\t\t\t\t\t Name: ";
       // cin>>name;
       gets(name);
        cout<<"\t\t\t\t\t\t Address: ";
        cin>>address;
        cout<<"\t\t\t\t\t\t Phone No: ";
        cin>>phone;
        cout<<"\n\t\t\t\t\t Room is booked!!!";
	 }
      };
 
void hotel::main_menu()
{
    int choice;
    
    while(choice!=5)
    {
        
       system("cls");
        cout<<"\n\t\t\t\t\t\t\t\t\t**********";
        cout<<"\n\t\t\t\t\t\t\t\t\t* MAIN MENU *";
        cout<<"\n\t\t\t\t\t\t\t\t\t*************";
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t1.Book A Room";
        cout<<"\n\t\t\t\t\t\t\t\t\t2.Customer Record";
        cout<<"\n\t\t\t\t\t\t\t\t\t3.Rooms Allotted";
        cout<<"\n\t\t\t\t\t\t\t\t\t4.Edit Record";
        cout<<"\n\t\t\t\t\t\t\t\t\t5.Exit";
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: add();
                    break;
            case 2: display();
                    break;
            case 3: rooms();
                    break;
            case 4: edit();
                    break;
            case 5: break;
            default:
                    {
                        cout<<"\n\n\t\t\tWrong choice!!!";
                        cout<<"\n\t\t\tPress any key to continue!!";
                        getch();
                    }
        }
    }
}
 
void hotel::add()
{
    
   
    fstream fout;
    hotel h;
	fout.open("Record.dat",ios::binary|ios::app|ios::out);
    cout<<"\n\t\t\t\t\t\t\t\t\t Enter Customer Detalis";
    cout<<"\n\t\t\t\t\t\t\t\t\t **********************";
    
    
    
         
         h.getdata();
        fout.write((char*)&h,sizeof(h));
    
   fout.close();
    cout<<"\n\t\t\t\t\t Press any key to continue!!";
    getch();
}
 
void hotel::display()
{
    system("cls");
    hotel h;
    ifstream fin;
	fin.open("Record.dat",ios::binary|ios::in);
    int r,flag=0;
    cout<<"\n\t\t\t\t\t\t\t Enter room no: ";
    cin>>r;
    while(!fin.eof())
    {
        fin.read((char*)&h,sizeof(h));
        if(h.room_no==r)
        {
            system("cls");
            cout<<"\n\t\t\t\t\t\t\t\t\t Customer Details";
            cout<<"\n\t\t\t\t\t\t\t\t\t ****************";
            cout<<"\n\n\t\t\t\t\t Room no: "<<h.room_no<<endl;
            cout<<"\n\t\t\t\t\tName: "<<h.name<<endl;
            cout<<"\n\t\t\t\t\tAddress: "<<h.address<<endl;
            cout<<"\n\t\t\t\t\tPhone no: "<<h.phone<<endl;
            flag=1;
            break;
        }
        
    }
    if(flag==0)
    cout<<"\n Sorry Room no. not found or vacant!!";
	cout<<"\n\n Press any key to continue!!";
    getch();
    fin.close();
}
 
void hotel::rooms()
{
    system("cls");
    fstream fin;
    hotel h;
	fin.open("Record.dat",ios::binary|ios::in);
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\t\t\t*********************";
    cout<<"\n\n Room No.";
     // fin.read((char*)&h,sizeof(h));
      
    while(fin.read((char*)&h,sizeof(h)))
    {
		//fin.read((char*)&h,sizeof(h));
     //fin.read((char*)&h,sizeof(h));
     cout<<"\n\n "<<h. room_no;
     /* if(!fin.eof())
       {
        cout<<"\n\n "<<room_no;
       }
    else
     break;*/
    }
    fin.close();
    cout<<"\n\n\n\t\t\tPress any key to continue!!";
    getch();
}
 
void hotel::edit()
{
    system("cls");
    int choice,r;
    
    cout<<"\n\t\t\t\t\t\t\t\t\t\t *********";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t EDIT MENU";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t *********";
    cout<<"\n\n\t\t\t\t\t\t\t 1.Modify Customer Record";
    cout<<"\n\t\t\t\t\t\t\t 2.Delete Customer Record";
    cout<<"\n\n\t\t\t\t\t\t\t Enter your choice: ";
    cin>>choice;
    cout<<"\n Enter room no: ";
    cin>>r;
    
    switch(choice)
    {
        case 1: modify(r);
                break;
        case 2: delete_rec(r);
                break;
        default: cout<<"\n\t\t\t\t\t\t Wrong Choice!!";
    }
    
    cout<<"\n Press any key to continue!!!";
    getch();
}
 
int hotel::check(int r)
{
    int flag=0;
    hotel h;
    ifstream fin;
	fin.open("Record.dat",ios::binary|ios::in);
    while(!fin.eof())
    {
        fin.read((char*)&h,sizeof(h));
        if(room_no==r)
        {
            flag=1;
            break;
        }
    }
    fin.close();
    return(flag);
}
 
void hotel::modify(int r)
{
    long pos,flag=0;
    hotel h;
    fstream file;
	file.open("Record.dat",ios::in|ios::out|ios::binary);
    
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)&h,sizeof(h));
        if(h.room_no==r)
        {
            cout<<"\n Enter New Details";
            cout<<"\n *****************";
            cout<<"\n Name: ";
            cin>>h.name;
            cout<<" Address: ";
            cin>>h.address;
            cout<<" Phone no: ";
            cin>>h.phone;
            
            file.seekg(pos);
            file.write((char*)&h,sizeof(h));
            cout<<"\n Record is modified!!";
            flag=1;
            break;
        }
    }
    
    if(flag==0)
        cout<<"\n Sorry Room no. not found or vacant!!";
        
    file.close();
}
 
void hotel::delete_rec(int r)
{
	hotel h;
    ifstream fin;
	fin.open("Record.dat",ios::binary|ios::in);
    ofstream fout;
	fout.open("temp.dat",ios::binary|ios::out);
     
    	fin.read((char*)&h, sizeof(h));
		while(!fin.eof())
		{
			if(h.room_no!=r)
			{
				fout.write((char*)&h, sizeof(h));
			}
			else
			{
				 cout<<endl<<"DELETED"<<endl;
				 cout<<"Press Any Key...."<<endl;
				 getch();
			}
			fin.read((char*)&h, sizeof(h));
		}
	
	fout.close();
	fin.close();
	remove("Record.dat");
	rename("temp.dat", "Record.dat");

 }
 int main()
{
    hotel h;
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t****************************";
    cout<<"\n\t\t\t\t\t\t\t\t* HOTEL MANAGEMENT PROJECT *";
    cout<<"\n\t\t\t\t\t\t\t\t****************************";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\tMade By:";
    cout<<" DHANANJAY PAWAR  1024\n\n";
    cout<<" \t\t\t\t\t\t\t\tUseless People:";
    cout<<" AZIZ SHAIKH  1041\n";
    cout<<"  \t\t\t\t\t\t\t\t\t\tSRISTHI KOLVEKAR  1019\n";
    cout<<"\n\n\n\t\t\t\t\t\t\t\tPress any key to continue!!";
    getch();
    h.main_menu();
}




//void hotel::rooms()
//{
//    system("cls");
//    fstream fin;
//    hotel h;
//	fin.open("Record.dat",ios::binary|ios::in);
//    cout<<"\n\t\t\tList Of Rooms Allotted";
//    cout<<"\n\t\t\t*********************";
  //  cout<<"\n\n Room No.";
 //   while(!fin.eof())
 //   {
  //   fin.read((char*)&h,sizeof(h));
   //   if(!fin.eof())
  //     {
   //     cout<<"\n\n "<<room_no;
   //    }
   // else
  //   break;
  //  }
  //  fin.close();
  //  cout<<"\n\n\n\t\t\tPress any key to continue!!";
//    getch();
//}
>>>>>>> 70e037906fd395f4ca392475691199fffbfa7816
