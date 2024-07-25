#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;

void login();
void registr();
void forgot();
void electronics();
void general_Items();
void cloths();
void cosmatics();
void MainMenu();


int choose;
int price;
int quantity;
char buy;
long credit;

 void loginpage()
{
        int choice;
         HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<"\n\n\n\n\n";
        cout<<"\t\t************************************************************************\n";
        cout<<"\t\t||                     Welcome to Our Login Page                      ||\n";
        cout<<"\t\t||                                                                    ||\n";
        cout<<"\t\t************************        MENU        ****************************\n\n";
        cout<<"\t\t\t\t\t1.LOGIN"<<endl;
        cout<<"\t\t\t\t\t2.CREATE A NEW ACCOUNT"<<endl;
        cout<<"\t\t\t\t\t3.FORGOT PASSWORD (or) USERNAME"<<endl;
        cout<<"\t\t\t\t\tEnter your choice :";
        cin>>choice;
        cout<<endl;
        while(choice <1 || choice>3)
        {
            cout<<"\t\t\t\t\t\tPlease Enter a Valid Option :";
            cin>>choice;
        }
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                default:
                        system("cls");
                        cout<<"\t\t\t\t\t\tYou've made a mistake , give it a try again\n"<<endl;
                        loginpage();
        }

}

void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"\t\t\t\t\t\tPlease Enter the following Details.\n"<<endl;
        cout<<"\t\t\t\t\t\tUSERNAME :";
        cin>>user;
        cout<<"\t\t\t\t\t\tPASSWORD :";
        cin>>pass;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\t\t\t\t\t\t Hello  "<<user<<" LOGIN SUCESS\n\t\t\t\t\t\t We're glad that you're here.\n\t\t\t\t\t\t Thanks for logging in\n\n";
                cout<<"\t\t\t\t\t\t Press any key to go to the mainmenu.\n";
                cin.get();
              MainMenu();
                loginpage();
        }
        else
        {
             HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout<<"\t\t\t\t\t\tLOGIN ERROR\n\t\t\t\t\t\tPlease check your username and password\n\n\n";
                cout<<"\n\t\t\t\t\t\tPress any Key to Continue------\n\n\n";
                getch();
                loginpage();
        }


}

void registr()
{
    string reguser,regpass,ru,rp;
    system("cls");
    cout<<"\t\t\t\t\t\tEnter the username :";
    cin>>reguser;
    cout<<"\n\t\t\t\t\t\tEnter the password :";
    cin>>regpass;
    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"\n\t\t\t\t\t\tCreated Your Account  Sucessfuly\n\n\n\n";
    loginpage();
}

void forgot()
{
        int ch;
         HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_RED | FOREGROUND_INTENSITY);
        system("cls");
        cout<<"\t\t\t\t\t\tForgotten ? We're here for help\n";
        cout<<"\t\t\t\t\t\t1.Search your id by username"<<endl;
        cout<<"\t\t\t\t\t\t2.Search your id by password"<<endl;
        cout<<"\t\t\t\t\t\t3.Main menu"<<endl;
        cout<<"\t\t\t\t\t\tEnter your choice :";
        cin>>ch;
        while(ch <1 || ch>3)
        {
            cout<<"\t\t\t\t\t\tPlease Enter a Valid Option :";
            cin>>ch;
        }
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\n\t\t\t\t\t\tEnter your remembered username :";
                        cin>>searchuser;
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\n\t\t\t\t\t\tYour, account found\n";
                                cout<<"\n\t\t\t\t\t\tYour password is "<<sp;
                                system("cls");

                        }
                        else
                        {
                                cout<<"\n\t\t\t\t\t\tSorry, Your userID is not found in our database\n";
                                cout<<"\n\t\t\t\t\t\tPlease kindly contact your system administrator for more details \n";
                                cout<<"\n\n\n\t\t\t\t\t\tPress any Key to Continue -------\n\n\n";
                                loginpage();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\n\t\t\t\t\t\tEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\n\t\t\t\t\t\tYour password is found in the database \n";
                                cout<<"\n\t\t\t\t\t\tYour Id is : "<<su2;
                                system("cls");
                                loginpage();
                        }
                        else
                        {
                                cout<<"\t\t\t\t\t\tSorry, We cannot found your password in our database \n";
                                cout<<"\n\t\t\t\t\t\tkindly contact your administrator for more information\n";
                                cout<<"\n\n\n\t\t\t\t\t\tPress any Key to Continue -------\n\n\n";
                               loginpage();
                        }

                        break;
                }

                case 3:
                {
                    cout<<"\n\n\n\n";
                         loginpage();
                }
        }
}
int main()
{
    loginpage();
    MainMenu();
    return 0;
}
void MainMenu()
{
void electronics();
void general_Items();
void cloths();

    label1:
         HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_RED | FOREGROUND_INTENSITY);
    system("cls");
    cout<<"\t\t\t\t\t\t***************************************************\n";
    cout<<"\t\t\t\t\t\t||      Welcome To Online Shopping System        ||\n";
    cout<<"\t\t\t\t\t\t***************************************************";
    cout<<"\n\n\n\t\t\t\t\t\tChoose anyone from below :"<<endl<<endl<<
    "\n\t\t\t\t\t\t1. Electronics Product :"<<endl<<
    "\n\t\t\t\t\t\t2. General Items :"<<endl<<
    "\n\t\t\t\t\t\t3.Cloths :"<<endl

    <<endl<<endl<<"\n\t\t\t\t\t\tYour choice :";
    cin>>choose;
   while(choose <1 || choose>3)
    {
        cin.clear();
        cout<<"\n\t\t\t\t\t\tPlease Enter a Valid Option :";
        cin>>choose;
    }
    switch(choose)
    {
        case 1:
            electronics();
            break;
            case 2:
                general_Items();
                break;
                case 3:
                    cloths();
                     break;
    }

}
    void electronics()
    {

         HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        system("cls");
        cout<<"\t\t\t\t\t\t***************************************************\n";
        cout<<"\t\t\t\t\t\t||                Electronics Product          ||\n";
        cout<<"\t\t\t\t\t\t***************************************************";
        cout<<"\n\n\n\t\t\t\t\t\tChoose anyone from below :"<<endl<<endl<<
          "\n\t\t\t\t\t\t1. Fridge:"<<endl<<
          "\n\t\t\t\t\t\t2. TV :"<<endl<<
          "\n\t\t\t\t\t\t3.Computer/Laptop :"<<endl<<
          "\n\t\t\t\t\t\t4. Smart Phones :"<<endl<<endl;
         cout<<"\t\t\t\t\t\t5. back to main mainu:\n\n";
        cout<<endl<<"\t\t\t\t\t\tYour choice :";
        cin>>choose;
         while(choose <1 or choose>5)
        {
            cin.clear();
            cout<<"\t\t\t\t\t\tPlease Enter a Valid Option :";
            cin>>choose;
        }
        if(choose==5)
        {
            MainMenu();
        }
        else if(choose==1)
        {
             HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_RED | FOREGROUND_INTENSITY);
           system("cls");
           price=15000;
           cout<<"\t\t\t***************************************************\n";
           cout<<"\t\t\t||                  Fridge Area                  ||\n";
           cout<<"\t\t\t***************************************************";
           cout<<"\n\n\t\t\tYou are about to purchase the Fridge .\n";
           cout<<"\n\t\t\t Price :"<<price;
           cout<<"\n\t\t\t press 0 to back  \n\n";
           cout<<"\n\t\t\tHow many items you want to purchase :";
           cin>>quantity;
             if(quantity==0)
        {
          electronics();
        }

           cout<<"\n\t\t\t\t\t\tYou want to buy Fridge your items are ("<<quantity<<")"<<endl;
           cout<<"\n\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
           cout<<"\n\t\t\t\t\t\tDo you want to buy ( Y or N ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"\n\t\t\t\t\t\tEnter your credit card number  :";
            cin>>credit;
            cout<<"\n\t\t\t\t\t\tYou have entered this credit card Number :"<<credit<<endl;
            cout<<"\n\t\t\t\t\t\tPress 1 to buy\n\n\t\t\t\t\t\t Press any key to go to the Main Menu\n\n\n\t\t\t\t\t\tYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"\n\n\t\t\t\t\t\tYou have Successfully bought the fridge :";
                system("pause");
              MainMenu();
               }
               else
               {
                cout<<"\t\t\t\t\t\t";
                MainMenu();
               }
           }
           else
           {
            MainMenu();
           }

        }
        else if(choose==2)
        {
           price=20000;
            HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
           system("cls");
           cout<<"\t\t\t\t\t\t***************************************************\n";
           cout<<"\t\t\t\t\t\t||                     TV Area                   ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
           cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the TV\n";
           cout<<"\n\t\t\t\t\t\tPrice :"<<price<<endl;
           cout<<"\n\t\t\t\t\t\tpress 0 to back  \n\n";
           cout<<"\n\t\t\t\t\t\tHow many items you want to purchase:";
           cin>>quantity;
               if(quantity==0)
        {
          electronics();
        }
           cout<<"\n\t\t\t\t\t\tYou want to buy TV your items are ("<<quantity<<")"<<endl;
           cout<<"\n\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
           cout<<"\n\t\t\t\t\t\tDo you want to buy ( Yes or No ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"\n\t\t\t\t\t\tEnter your credit card number :";
            cin>>credit;
            cout<<"\n\t\t\t\t\t\tYou have entered this credit card Number :"<<credit<<endl;
            cout<<"\n\t\t\t\t\t\tPress 1 to buy\n\n\t\t\t\t\t\t Press any key to go to the Main Menu\n\n\n\t\t\t\t\t\tYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"\n\t\t\t\t\t\tYou have Successfully bought the TV :";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
            else
           {
            MainMenu();
           }
        }
        else if(choose==3)
        {
            price=60000;
             HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            system("cls");
           cout<<"\t\t\t\t\t\t***************************************************\n";
           cout<<"\t\t\t\t\t\t||                  Computer Area                  ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
           cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the COMPUTER\n";
           cout<<"\n\t\t\t\t\t\tPrice :"<<price<<endl;
           cout<<"\n\t\t\t\t\t\tpress 0 to back  \n\n";
           cout<<"\n\t\t\t\t\t\tHow many items you want to purchase:";
           cin>>quantity;
           if(quantity==0)
        {
          electronics();
        }
           cout<<"\n\t\t\t\t\t\tYou want to buy COMPUTER your items are ("<<quantity<<")"<<endl;
           cout<<"\n\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
           cout<<"\n\t\t\t\t\t\tDo you want to buy ( Yes or No ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"\n\t\t\t\t\t\tEnter your credit card number :";
            cin>>credit;
            cout<<"\n\t\t\t\t\t\tYou have entered this credit card Number :"<<credit<<endl;
            cout<<"\n\t\t\t\t\t\tPress 1 to buy\n\n\t\t\t\t\t\t Press any key to go to the Main Menu\n\n\n\t\t\t\t\t\tYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"\n\t\t\t\t\t\tYou have Successfully bought the COMPUTER ";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
            else
           {
            MainMenu();
           }
        }
        else if(choose==4)
        {
           price=8000;
            HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
           system("cls");
           cout<<"\t\t\t\t\t\t***************************************************\n";
           cout<<"\t\t\t\t\t\t||              Smart Phone Area                  ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
           cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the SMART PHONE\n";
           cout<<"\n\t\t\t\t\t\tPrice :"<<price<<endl;
           cout<<"\n\t\t\t\t\t\tpress 0 to back  \n\n";
           cout<<"\n\t\t\t\t\t\tHow many items you want to purchase:";
           cin>>quantity;
           if(quantity==0)
        {
          electronics();
        }
           cout<<"\n\t\t\t\t\t\tYou want to buy SMART PHONE your items are ("<<quantity<<")"<<endl;
           cout<<"\n\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
           cout<<"\n\t\t\t\t\t\tDo you want to buy ( Yes or No )";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"\n\t\t\t\t\t\tEnter your credit card number";
            cin>>credit;
            cout<<"\n\t\t\t\t\t\tYou have entered this credit card Number :"<<credit<<endl;
            cout<<"\n\t\t\t\t\t\tPress 1 to buy\n \t\t\t\t\t\tPress any key to go to the Main Menu\n\n\n\t\t\t\t\t\tYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"\n\t\t\t\t\t\tYou have Successfully bought the SMART PHONE ";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
           else
           {
            MainMenu();
           }
        }
    }
    void general_Items()
    {
        HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        system("cls");
           cout<<"\t\t\t\t\t\t***************************************************\n";
           cout<<"\t\t\t\t\t\t||                 GENERAL ITEMS                 ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
        cout<<"\n\n\n\t\t\t\t\t\tChoose anyone from below :"<<endl<<endl<<
          "\n\t\t\t\t\t\t1. BALL:"<<endl<<
          "\n\t\t\t\t\t\t2. PIZZA :"<<endl<<
          "\n\t\t\t\t\t\t3. BURGER :"<<endl<<
          "\n\t\t\t\t\t\t4. SHOSE :"<<endl<<endl;
         cout<<"\t\t\t\t\t\t5. back to main mainu:\n\n";
         cout<<"\n\t\t\t\t\t\tYour choice:";
        cin>>choose;
          while(choose <1 or choose>5)
        {
            cin.clear();
            cout<<"\t\t\t\t\t\tPlease Enter a Valid Option :";
            cin>>choose;
        }
        if(choose==5)
        {
            MainMenu();
        }
        else if(choose==1)
        {
           system("cls");
           price=500;
           cout<<"\t\t\t\t\t\t***************************************************\n";
           cout<<"\t\t\t\t\t\t||                   BALL  Area                  ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
           cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the BALL :\n";
           cout<<"\t\t\t\t\t\tPrice :"<<price<<endl;
           cout<<"\t\t\t\t\t\tHow many items you want to purchase:";
           cin>>quantity;
           cout<<"\t\t\t\t\t\tYou want to buy BALL your items are : ("<<quantity<<")"<<endl;
           cout<<"\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
           cout<<"\t\t\t\t\t\tDo you want to buy ( Yes or No )";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"Enter your credit card number :";
            cin>>credit;
            cout<<"You have entered this credit card Number :"<<credit<<endl;
            cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"You have Successfully bought the BALL ";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }

        }
        else if(choose==2)
        {
           price=600;
           system("cls");
           cout<<"\n\t\t\t\t\t\t***************************************************";
           cout<<"\n\n\t\t\t\t\t||                  PIZZA Area                   ||";
           cout<<"\n\t\t\t\t\t\t***************************************************";
           cout<<"\n\nYou are about to purchase the PIZZA\n";
           cout<<"Price :"<<price<<endl;
           cout<<"How many items you want to purchase:";
           cin>>quantity;
           cout<<"you want to buy PIZZA your items are :("<<quantity<<")"<<endl;
           cout<<"Your total Price :"<<quantity*price<<endl;
           cout<<"Do you want to buy ( Yes or No ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"Enter your credit card number :";
            cin>>credit;
            cout<<"You have entered this credit card Number :"<<credit<<endl;
            cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice";
            cin>>choose;
            if(choose==1)
            {
                cout<<"You have Successfully bought the PIZZA ";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
        }
        else if(choose==3)
        {
            price=700;
            system("cls");
            cout<<"***************************************************";
           cout<<"\n\n BURGER Area\n\n";
           cout<<"***************************************************";
           cout<<"\n\nYou are about to purchase the  BURGER\n";
           cout<<"Price :"<<price<<endl;
           cout<<"How many items you want to purchase :";
           cin>>quantity;
           cout<<"you want to buy  BURGER your items are :("<<quantity<<")"<<endl;
           cout<<"Your total Price :"<<quantity*price<<endl;
           cout<<"Do you want to buy ( Yes or No ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"Enter your credit card number :";
            cin>>credit;
            cout<<"You have entered this credit card Number :"<<credit<<endl;
            cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"You have Successfully bought the  BURGER ";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
        }
        else if(choose==4)
        {
           price=800;
           system("cls");
           cout<<"***************************************************";
           cout<<"\n\nSHOSE Area\n\n";
           cout<<"***************************************************";
           cout<<"\n\nYou are about to purchase the SHOSE\n";
           cout<<"Price :"<<price<<endl;
           cout<<"How many items you want to purchase:";
           cin>>quantity;
           cout<<"you want to buy SMART PHONE your items are ("<<quantity<<")"<<endl;
           cout<<"Your total Price :"<<quantity*price<<endl;
           cout<<"Do you want to buy ( Yes or No ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"Enter your credit card number :";
            cin>>credit;
            cout<<"You have entered this credit card Number :"<<credit<<endl;
            cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"You have Successfully bought the SHOSE ";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
        }
    }
    void cloths()
    {
 HANDLE b=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        system("cls");
        cout<<"***************************************************";
        cout<<"\n\n\n\t\tCLOTHES SECTION\n\n\n";
        cout<<"***************************************************";
        cout<<"\n\n\nChoose anyone from below :"<<endl<<endl<<
          "1. SHIRT:"<<endl<<
          "2. T.SHIRT :"<<endl<<
          "3.JEANS :"<<endl<<
          "4. Jacket :"<<endl;
          cout<<"5. back to main mainu:\n\n";
        cout<<"Your choice :";
        cin>>choose;
         while(choose <1 or choose>5)
        {
            cin.clear();
            cout<<"\t\t\t\t\t\tPlease Enter a Valid Option :";
            cin>>choose;
        }
        if(choose==5)
        {
            MainMenu();
        }

       else if(choose==1)
        {
           system("cls");
           price=1000;
           cout<<"***************************************************";
           cout<<"\n\n SHIRT\n\n";
           cout<<"***************************************************";
           cout<<"\n\nYou are about to purchase the  SHIRT\n";
           cout<<"Price :"<<price<<endl;
           cout<<"How many items you want to purchase:";
           cin>>quantity;
           cout<<"you want to buy  SHIRT your items are :("<<quantity<<")"<<endl;
           cout<<"Your total Price :"<<quantity*price<<endl;
           cout<<"Do you want to buy ( Yes or No ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"Enter your credit card number :";
            cin>>credit;
            cout<<"You have entered this credit card Number :"<<credit<<endl;
            cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"You have Successfully bought the  SHIRT";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }

        }
        else if(choose==2)
        {
           price=2000;
           system("cls");
           cout<<"***************************************************";
           cout<<"\n\nT.SHIRT Area\n\n";
           cout<<"***************************************************";
           cout<<"\n\nYou are about to purchase the T.SHIRT\n";
           cout<<"Price :"<<price<<endl;
           cout<<"How many items you want to purchase:";
           cin>>quantity;
           cout<<"you want to buy AC your items are ("<<quantity<<")"<<endl;
           cout<<"Your total Price :"<<quantity*price<<endl;
           cout<<"Do you want to buy ( Yes or No )";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"Enter your credit card number :";
            cin>>credit;
            cout<<"You have entered this credit card Number :"<<credit<<endl;
            cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"You have Successfully bought the T.SHIRT ";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
        }
        else if(choose==3)
        {
            price=3000;
            system("cls");
            cout<<"***************************************************";
           cout<<"\n\nJEANS\n\n";
           cout<<"***************************************************";
           cout<<"\n\nYou are about to purchase the JEANS\n";
           cout<<"Price :"<<price<<endl;
           cout<<"How many items you want to purchase:";
           cin>>quantity;
           cout<<"you want to buy JEANS your items are : ("<<quantity<<")"<<endl;
           cout<<"Your total Price :"<<quantity*price<<endl;
           cout<<"Do you want to buy ( Yes or No ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"Enter your credit card number :";
            cin>>credit;
            cout<<"You have entered this credit card Number :"<<credit<<endl;
            cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"You have Successfully bought the JEANS";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
        }
        else if(choose==4)
        {
           price=4000;
           system("cls");
           cout<<"***************************************************";
           cout<<"\n\n Jacket  Area\n\n";
           cout<<"***************************************************";
           cout<<"\n\nYou are about to purchase the Jacket \n";
           cout<<"Price :"<<price<<endl;
           cout<<"How many items you want to purchase :";
           cin>>quantity;
           cout<<"you want to buy Jacket  your items are : ("<<quantity<<")"<<endl;
           cout<<"Your total Price :"<<quantity*price<<endl;
           cout<<"Do you want to buy ( Yes or No ) :";
           cin>>buy;
           if(buy=='y'||buy=='Y')
           {
            cout<<"Enter your credit card number :";
            cin>>credit;
            cout<<"You have entered this credit card Number :"<<credit<<endl;
            cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
            cin>>choose;
            if(choose==1)
            {
                cout<<"You have Successfully bought the Jacket ";
                system("pause");
                MainMenu();
               }
               else
               {
                MainMenu();
               }
           }
        }
    }
