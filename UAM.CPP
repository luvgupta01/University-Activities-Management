#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
#include<math.h>
#include <time.h>
#define xx(x) (50*(x-1) )
#define yy(y) (45*(y-1))
void deoscreen(char *A);
void adminfile();
void adminscreen(char *A);
void deo();
void admin();
void homescreen();
void view();
void design();
void exita();
void deoadd(char *A);
void details(int mm,int y);
void guestscreen();
void login();
void insertadmin(char *A);
void insertdeo(char *A);
void update(char *A);
void signup();
void reminder(char *A);
void adminpassupdate(char *A);
void deopassupdate(char *A);
void viewrem(char *A);
class Temp
{
public:
void admin();
void deo();
void view();
void exita();
};
int main()
{
   clrscr();
   int gdriver = DETECT, gmode;
   int i;
   initgraph(&gdriver, &gmode, "C:\\Turboc3\\bgi");
   setcolor(RED);
   rectangle(80,40,565,440);
   setcolor(GREEN);
   rectangle(70,30,575,450);
   settextstyle(1,0,5);
   setcolor(MAGENTA);
   outtextxy(223,80,"University");
   outtextxy(230,130,"Activities");
   outtextxy(200,180,"Management");
   setcolor(BLUE);
   rectangle(169,299,476,311);
   rectangle(170,300,475,310);
   settextstyle(1,0,2);
   for(i=0;i<304;i++)
   {
   setcolor(GREEN);
   line(171+i,301,171+i,309);
   delay(0);
   setcolor(LIGHTGRAY);
   outtextxy(275,325,"Loading");
   outtextxy(350,325,"...");
   delay(5);
   setcolor(BLACK);
   delay(5);
   outtextxy(350,325,"...");
   delay(5);
   setcolor(LIGHTGRAY);
   outtextxy(350,325,".  ");
   delay(5);
   outtextxy(350,325,"..");
   delay(5);
   }
   setcolor(BLACK);
   outtextxy(275,325,"Loading");
   outtextxy(350,325,"...");
   setcolor(LIGHTGRAY);
   outtextxy(230,325,"Loading Completed");
   setcolor(YELLOW);
   rectangle(210,370,435,400);
   setcolor(CYAN);
   outtextxy(220,370,"Press 0 to continue");
   char j=getche();
   if(j=='0')
   {
   adminfile();
   homescreen();
   }
   else
{  Temp t4;
   t4.exita();
   }
   return 0;
}
void adminfile()
{
   char *data;
   ofstream outfile;
   outfile.open("adminlog.txt");
   data="admin";
   outfile << data << endl;
   outfile << data << endl;
   outfile.close();
}
void design()
{
   cleardevice();
   setcolor(RED);
   rectangle(80,40,565,440);
   setcolor(GREEN);
   rectangle(70,30,575,450);
   setcolor(BLUE);
   outtextxy(150,80,"University Activities Management");
}
void homescreen()
{
   design();
   setcolor(CYAN);
   outtextxy(200,200,"1 For Administrator");
   outtextxy(200,220,"2 For Data Entry Operator");
   outtextxy(200,240,"3 For Guest User");
   outtextxy(200,260,"4 For Exit");
   setcolor(WHITE);
   outtextxy(230,410,"Enter your choice...");
   char j=getche();
   switch(j)
{
case '1': Temp t1;
t1.admin();
break;
case '2': Temp t2;
t2.deo();
break;
case '3': Temp t3;
t3.view();
break;
case '4': Temp t4;
t4.exita();
break;
default:
homescreen();
}
}
void Temp::exita()
{
design();
setcolor(LIGHTGRAY);
outtextxy(210,230,"Thanks for using....");
setcolor(MAGENTA);
outtextxy(235,310,"Developed By:");
setcolor(WHITE);
outtextxy(248,335,"Luv Gupta");
outtextxy(243,360,"Love Gupta");
getch();
exit(0);
}
void Temp::deo()
{
   char *id,*pd;
   char *di,*dp;
   design();
   setcolor(RED);
   gotoxy(37,11);
   cout<<"Login";
   gotoxy(31,13);
   cout<<"Enter the user id";
   gotoxy(31,16);
   cout<<"Enter the password";
   rectangle(280,295,330,315);
   setcolor(YELLOW);
   outtextxy(295,292,"OK");
   gotoxy(31,14);
   gets(id);
   gotoxy(31,17);
   gets(pd);
   int flag=0;
   ifstream infile;

   infile.open("deologin.txt",fstream::app);
   while (!infile.eof())
   {
   infile >> di;
   if(stricmp(id,di)==0)
   {
   infile >> dp;
   if(stricmp(pd,dp)==0)
   {
 flag=1;
   deoscreen(id);

   break;
   }
   }
   }
   infile.close();
   if(flag!=1)
   {
   setcolor(LIGHTGRAY);
   outtextxy(190,330,"Invalid user id or password");
   getch();
   homescreen();
   }
}
void deoscreen(char *A)
{
   design();
   setcolor(CYAN);
   outtextxy(200,220,"1 For Update password");
   outtextxy(200,240,"2 For View");
   outtextxy(200,260,"3 For Insert the Information");
   outtextxy(200,280,"4 For Exit");
   setcolor(WHITE);
   outtextxy(230,410,"Enter your choice...");
   char j=getch();
   switch(j)
   {
   case '1':
   deopassupdate(A);
   break;
   case '2': Temp t3;
   t3.view();
   break;
   case '3':
   insertdeo(A);
   break;
   case '4':
   homescreen();
   break;
   default:
   deoscreen(A);
   }
}
void Temp::admin()
{
   design();
   char *id,*pd;
   char *di,*dp;
   ifstream infile;
   infile.open("adminlog.txt");
   setcolor(RED);
   gotoxy(37,11);
   cout<<"Login";
   gotoxy(31,13);
   cout<<"Enter the user id";
   gotoxy(31,16);
   cout<<"Enter the password";
   rectangle(280,295,330,315);
   setcolor(YELLOW);
   outtextxy(295,292,"OK");
   gotoxy(31,14);
   gets(id);
   gotoxy(31,17);
   gets(pd);
   int flag=0;
   while (!infile.eof())
   {
   infile >> di;
   if(stricmp(id,di)==0)
   {
   infile >> dp;
   if(stricmp(pd,dp)==0)
   {
   flag=1;
   adminscreen(id);

   break;
   }
   }
   }
   infile.close();
   if(flag!=1)
   {
   setcolor(LIGHTGRAY);
   outtextxy(190,330,"Invalid user id or password");
   getch();
   homescreen();
   }
}

void adminscreen(char *A)
{
   design();
   setcolor(CYAN);
   outtextxy(200,170,"1 For to add more DEO");
   outtextxy(200,190,"2 For Update password");
   outtextxy(200,210,"3 For View");
   outtextxy(200,230,"4 For Insert the Information");
   outtextxy(200,250,"5 For Update the Information");
   outtextxy(200,270,"6 For View the Remainder");
   outtextxy(200,290,"7 For Exit");
   setcolor(WHITE);
   outtextxy(230,410,"Enter your choice...");
   char j=getch();
   switch(j)
   {
   case '1':
   deoadd(A);
   break;
   case '2':
   adminpassupdate(A);
   break;
   case '3': Temp t3;
   t3.view();
   break;
   case '4':
   insertadmin(A);
   break;
   case '5':
   update(A);
   break;
   case '6':
   viewrem(A);
   break;
   case '7':
   homescreen();
   break;
   default:
   adminscreen(A);
   }
}

void Temp::view()
{
cleardevice();
void calendar(int , int);
void days(int , int);
int getkey;
int month,year=0;
char *date;
time_t timer;
timer=time(NULL);
int i,a[4],j=0;
date = asctime(localtime(&timer));
for(i=20;i<24;i++)
a[j++]=date[i]-48;
for(i=0;i<4;i++)
year=(year*10)+a[i];
switch(date[4])
{
case 'J':
month=1;break;
case 'F':
month=2;break;
case 'S':
month=9;break;
case 'N':
month=11;break;
case 'D':
month=12;break;
case 'O':
month=10;break;
default:
case 'A':
if(date[5]=='p')
month=4;
else
month=8;
break;
deflault:
if(date[4]=='M')
{
if(date[6]=='r')
month=3;
if(date[6]=='y')
month=5;
if(date[6]=='n')
month=6;
if(date[6]=='l')
month=7;
}
}

do{
 days(month, year);
calendar(year, month);
label:getkey=getch();
if(getch)
cleardevice();
if(month==1&&getkey==75) {year=year-1;month=12;}
else if(month==12&&getkey==77) {year=year+1;month=1;}
else if(getkey==13){details(month,year);}
else if(getkey==80){year=year+1;}
else if(getkey==72) year=year-1;
else if(getkey==75) month=month-1;
else if(getkey==77) month=month+1;
else if(getkey==27) homescreen();
else goto label;}
while(getkey!=27);
}

void calendar(int year,int month)
{
void dates(int , int , int);
int i,a,b,c,d,e,f,startday;
int monthcodes[]={1,4,4,0,2,5,0,3,6,1,4,6};
int years[]={1700,1800,1900,2000};
int yearcodes[]={4,2,0,6};
a=year%100;
b=a/4;
c=b+1;
d=c+monthcodes[month-1];
if((year%4==0)&&(month==1||month==2))
d=d-1;
int ayear=year;
while(ayear>2099)
{ayear=ayear-400;}
while(ayear<1700)
{ayear=ayear+400;}
i=0;
while(!(ayear-years[i]<100)||!(ayear-years[i]>0))
{i++;}
e=d+yearcodes[i];
f=e+a;
startday=f%7;
startday=fabs(startday);
dates(startday,year,month);
}
void days(int month,int year)
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C:\\Turboc3\\bgi");
char *ss;
setcolor(RED);
rectangle(80,40,565,440);
setcolor(GREEN);
rectangle(70,30,575,450);
 rectangle(70,30,575,450);
   setcolor(YELLOW);
   settextstyle(1,0,2);
   outtextxy(150,80,"University Activities Management");
int i;

char months[]={"JanFebMarAprMayJunJulAugSepOctNovDec"};
int m=3*(month-1);
char Z[4];
Z[0]=months[m];
Z[1]=months[m+1];
Z[2]=months[m+2];
Z[3]='\0';
setcolor(MAGENTA);
settextstyle(1,0,1);
outtextxy(270,105,Z);
itoa(year,ss,10);
outtextxy(303,105,ss);

setcolor(LIGHTGRAY);
settextstyle(1,0,2);
outtextxy(163,140,"SUN MON TUE WED THU FRI SAT");
}
void dates(int startday,int year,int month)
{
char *S;

int ld[]={31,28,31,30,31,30,31,31,30,31,30,31};
if(year%4==0)    ld[1]=29;
if(startday==0)    startday=7;int a=1;
//settextstyle(1,0,2);
for(int i=0;i<6;i++)//For rows
{

for(int j=1;j<=7;j++)//For Coloumns
{

if(a<=ld[month-1])//For printing dates
{
while(i==0&&j<startday)//For spacing before first date
{
j++;
}
itoa(a,S,10);
if(j==1)
setcolor(RED);
else
setcolor(WHITE);
if(a<10)
outtextxy(xx(j+3.5),yy(i+5),S);
else
outtextxy(xx(j+3.25),yy(i+5),S);
a++;
}
else continue;
}
}
}
void details(int mm,int y)
{
   design();
char ss[10],s[10];
char months[]={"JanFebMarAprMayJunJulAugSepOctNovDec"};
int m=3*(mm-1);
char Z[4];
Z[0]=months[m];
Z[1]=months[m+1];
Z[2]=months[m+2];
Z[3]='\0';
setcolor(MAGENTA);
settextstyle(1,0,1);
outtextxy(270,105,Z);
itoa(y,ss,10); // puts(ss);
outtextxy(303,105,ss);
itoa(mm,s,10);       //    puts(s);
char data[30];int flag=0;
int j=0;
char venue[30],detail[30],name[30],date[30];

int i,k=0;
char a[5],b[3],c[3];
  ifstream infile;
   infile.open("details.txt");
   while (1)
   {
	if(!infile)
	break;
infile >> date >>name>>detail>>venue;
if(!infile)
break;
strcpy(data,date);
for(i=6;i<10;i++)
a[j++]=data[i];
a[j]='\0';
j=0;
for(i=3;i<5;i++)
b[j++]=data[i];
b[j]='\0';
j=0;
for(i=0;i<2;i++)
c[j++]=data[i];
c[j]='\0';
j=0;
if(strcmpi(b,s)==0)
{
  if(strcmpi(ss,a)==0)
{

    setcolor(YELLOW);
    outtextxy(128,400,"Press Esc for return  Enter for Remainder");
	 setcolor(LIGHTGRAY);
		   outtextxy(170,160+k,"DAY :");
		   setcolor(3);
      outtextxy(250,160+k,c);
       setcolor(7);
      outtextxy(170,180+k,"Name :");
		  setcolor(3);
	outtextxy(250,180+k,name);
	 setcolor(7);
	outtextxy(170,200+k,"Details :");
		    setcolor(3);
       outtextxy(250,200+k,detail);
	setcolor(7);
       outtextxy(170,220+k,"Venue :");
	setcolor(3);
       outtextxy(250,220+k,venue);
 k=k+120;
flag=1;
}
}
 }
   char ch;
   infile.close();
    if(flag==0)
    {
    setcolor(LIGHTGRAY);
    outtextxy(195,220,"No Details are available......");
    outtextxy(230,400,"Press Esc for return");
    ch=getch();
if(ch==27)
return;
}
else
{
ch=getch();
if(ch==13)
guestscreen();
else
return;
}
}
void guestscreen()
{
design();
settextstyle(1,0,2);
setcolor(LIGHTGRAY);
outtextxy(245,200,"1 for Login");
outtextxy(245,220,"2 for Sign up");
setcolor(MAGENTA);
outtextxy(230,380,"Press your choice.....");
char c=getch();
if(c=='1')
login();
else if(c=='2')
signup();
}

void login()
{
   char *id,*pd;
   char *di,*dp;
   design();
   setcolor(RED);
   gotoxy(37,11);
   cout<<"Login";
   gotoxy(31,13);
   cout<<"Enter the user id";
   gotoxy(31,16);
   cout<<"Enter the password";
   rectangle(280,295,330,315);
   setcolor(YELLOW);
   outtextxy(295,292,"OK");
   gotoxy(31,14);
   gets(id);
   gotoxy(31,17);
   gets(pd);
   int flag=0;
   ifstream infile;
   infile.open("guestlog.txt",fstream::app);
   while (!infile.eof())
   {
   infile >> di;
   if(stricmp(id,di)==0)
   {
   infile >> dp;
   if(stricmp(pd,dp)==0)
   {
   flag=1;
   reminder(id);
   break;
   }
   }
   }
   infile.close();
   if(flag!=1)
   {
   setcolor(LIGHTGRAY);
   outtextxy(210,330,"Invalid user id or password");
   getch();
   guestscreen();
   }
}
void signup()
{
design();
char *id,*pass,*email;
 setcolor(RED);
   ofstream outfile;
   outfile.open("guestlog.txt",fstream::app);
   gotoxy(36,9);
   cout<<"Sign in";
   gotoxy(31,11);
   cout<<"Enter the user id";
   gotoxy(31,14);
   cout<<"Enter the password";
   gotoxy(31,17);
   cout<<"Enter the email id";

   rectangle(280,325,330,345);
   setcolor(YELLOW);
   outtextxy(295,322,"OK");
   gotoxy(31,12);
   gets(id);
   gotoxy(31,15);
   gets(pass);
   gotoxy(31,18);
   gets(email);

   outfile << id << endl;
outfile << pass << endl;


   outfile << email << endl;

   outfile.close();

 setcolor(GREEN);
   outtextxy(230,410,"Sign up successfully!");

getch();
guestscreen();
}
void reminder(char *A)
{
design();
   char rem[30],id[30];
   setcolor(RED);
   gotoxy(32,11);
   cout<<"Set Reminder";
   gotoxy(31,13);
   cout<<"Enter the event";
   rectangle(280,275,330,295);
   setcolor(YELLOW);
   outtextxy(295,272,"OK");
   gotoxy(31,14);
   gets(rem);
   ifstream infile;
   infile.open("guestlog.txt");
   while (!infile.eof())
   {
   infile >> id;
   if(stricmp(id,A)==0)
   {
   infile >> id;
   infile >> id;
   break;
}
}
   fstream outfile;
   outfile.open("remaind.txt",fstream::app);
   outfile << id << endl;
   outfile << rem << endl;
   outfile.close();
   setcolor(GREEN);
   outtextxy(210,410,"Reminder set successfully!");
   getch();
   guestscreen();
}
void insertadmin(char *A)
{
design();
   char date[30],name[30],detail[30],venue[30];
   setcolor(RED);
   gotoxy(33,9);
   cout<<"Add Information";
   gotoxy(31,11);
   cout<<"Enter the date";
   gotoxy(31,14);
   cout<<"Enter the name";
   gotoxy(31,17);
   cout<<"Enter the details";
   gotoxy(31,20);
   cout<<"Enter the venue";
   rectangle(280,355,330,375);
   setcolor(YELLOW);
   outtextxy(295,352,"OK");
   gotoxy(31,12);
   gets(date);
   gotoxy(31,15);
   gets(name);
   gotoxy(31,18);
   gets(detail);
   gotoxy(31,21);
   gets(venue);
   ofstream outfile;
   outfile.open("details.txt",ios::app);
   outfile<<" "<<date<<" "<<name<<" "<<detail<<" "<<venue<<"\n";
   outfile.close();
   setcolor(GREEN);
   outtextxy(200,410,"Data entered successfully!");
   getch();
   adminscreen(A);
}
void insertdeo(char *A)
{
   design();
   char date[30],name[30],detail[30],venue[30];
   setcolor(RED);
   gotoxy(33,9);
   cout<<"Add Information";
   gotoxy(31,11);
   cout<<"Enter the date";
   gotoxy(31,14);
   cout<<"Enter the name";
   gotoxy(31,17);
   cout<<"Enter the details";
   gotoxy(31,20);
   cout<<"Enter the venue";
   rectangle(280,355,330,375);
   setcolor(YELLOW);
   outtextxy(295,352,"OK");
   gotoxy(31,12);
   gets(date);
   gotoxy(31,15);
   gets(name);
   gotoxy(31,18);
   gets(detail);
   gotoxy(31,21);
   gets(venue);
   ofstream outfile;
   outfile.open("details.txt",ios::app);
   outfile<<" "<<date<<" "<<name<<" "<<detail<<" "<<venue<<"\n";
   outfile.close();
   setcolor(GREEN);
   outtextxy(200,410,"Data entered successfully!");
   getch();
   deoscreen(A);
}

void update(char *A)
{
     design();
   char date[30],newdate[30],name[30],name1[30],detail[30],detail1[30],venue1[30],venue[30],olddate[30];
   setcolor(RED);
   gotoxy(31,8);
   cout<<"Update Information";
   gotoxy(31,10);
   cout<<"Enter the old date";
   gotoxy(31,13);
   cout<<"Enter the new date";
   gotoxy(31,16);
   cout<<"Enter the new name";
   gotoxy(31,19);
   cout<<"Enter the new details";
   gotoxy(31,22);
   cout<<"Enter the new venue";
   rectangle(280,370,330,390);
   setcolor(YELLOW);
   outtextxy(295,367,"OK");
   gotoxy(31,11);
   gets(olddate);
   gotoxy(31,14);
   gets(newdate);
   gotoxy(31,17);
   gets(name1);
   gotoxy(31,20);
   gets(detail1);
   gotoxy(31,23);
   gets(venue1);
   ifstream infile;
   ofstream outfile;
   outfile.open("login12.txt",ios::app);
   infile.open("details.txt");
   int i=0;
   while (1)
   {

   if(!infile)
   break;
    infile>>date>>name>>detail>>venue;
   if(strcmp(date,olddate)==0)
   {
   strcpy(date,newdate);
   strcpy(name,name1);
   strcpy(venue,venue1);
   strcpy(detail,detail1);
   outfile<<" "<<date << " " << name <<" "<< detail <<" "<< venue << "\n";
   i=1;
   }
   else
   {
      outfile<<" "<< date << " " << name <<" "<< detail <<" "<< venue << "\n";
   }
   }
	    infile.clear();
   infile.seekg(0,ios::beg);

   outfile.close();
   infile.close();

  remove("details.txt");

   if(i==1&&rename("login12.txt","details.txt")==0)
   {
   setcolor(GREEN);
   outtextxy(195,410,"Information Updated");
  }
   getch();
   adminscreen(A);
}
void deoadd(char *A)
{
   char *id,*pd;
   design();
   setcolor(RED);
   gotoxy(34,11);
   cout<<"Add more Deo";
   gotoxy(31,13);
   cout<<"Enter the user id";
   gotoxy(31,16);
   cout<<"Enter the password";
   rectangle(280,295,330,315);
   setcolor(YELLOW);
   outtextxy(295,292,"OK");
   gotoxy(31,14);
   gets(id);
   gotoxy(31,17);
   gets(pd);
   ofstream outfile;
   outfile.open("deologin.txt",fstream::app);
   outfile << id << endl;
   outfile << pd << endl;
   outfile.close();
   setcolor(GREEN);
   outtextxy(210,330,"Data entered successfully!");
   getch();
   adminscreen(A);
}
void adminpassupdate(char *A)
{
   design();
   char *id,*old,*new1;
   setcolor(RED);
   gotoxy(30,11);
   cout<<"Admin password update";
   gotoxy(28,13);
   cout<<"Enter the new password";
   gotoxy(28,16);
   cout<<"Enter the confirm password";
   rectangle(280,295,330,315);
   setcolor(YELLOW);
   outtextxy(295,292,"OK");
   gotoxy(28,14);
   gets(old);
   gotoxy(28,17);
   gets(new1);
   if(stricmp(old,new1)==0)
   {
   ifstream infile;
   ofstream outfile;
   outfile.open("login.txt",fstream::app);
   infile.open("adminlog.txt",fstream::app);
   while (!infile.eof())
   {
   infile >> id;
   if(stricmp(id,A)==0)
   {
   outfile << id << endl;
   infile >> id;
   id=old;
   outfile << id << endl;
   }
   else
   {
   outfile << id << endl;
   infile >> id;
   outfile << id << endl;
   }
   }
   outfile.close();
   infile.close();
   remove("adminlog.txt");
   rename("login.txt","adminlog.txt");
   setcolor(LIGHTGRAY);
   outtextxy(230,410,"Password Changed");
   getch();
   adminscreen(A);
   }
   else
   {
   setcolor(LIGHTGRAY);
   outtextxy(105,410,"New and confirm password does not match");
   getch();
   adminscreen(A);
   }
}
void deopassupdate(char *A)
{
   design();
   char *id,*old,*new1;
   setcolor(RED);
   gotoxy(30,11);
   cout<<"Deo password update";
   gotoxy(28,13);
   cout<<"Enter the new password";
   gotoxy(28,16);
   cout<<"Enter the confirm password";
   rectangle(280,295,330,315);
   setcolor(YELLOW);
   outtextxy(295,292,"OK");
   gotoxy(28,14);
   gets(old);
   gotoxy(28,17);
   gets(new1);
   if(stricmp(old,new1)==0)
   {
   ifstream infile;
   ofstream outfile;
   outfile.open("login.txt",fstream::app);
   infile.open("deologin.txt",fstream::app);
   while (!infile.eof())
   {
   infile >> id;
   if(stricmp(id,A)==0)
   {
   outfile << id << endl;
   infile >> id;
   id=old;
   outfile << id << endl;
   }
   else
   {
   outfile << id << endl;
   infile >> id;
   outfile << id << endl;
   }
   }
   outfile.close();
   infile.close();
   remove("deologin.txt");
   rename("login.txt","deologin.txt");
   setcolor(LIGHTGRAY);
   outtextxy(230,410,"Password Changed");
   getch();
   deoscreen(A);
   }
   else
   {
   setcolor(LIGHTGRAY);
   outtextxy(105,410,"New and confirm password does not match");
   getch();
   deoscreen(A);
   }
}
void viewrem(char *A)
{
   design();
   int j=0;
   char a[30],b[30];
   ifstream infile;
   setcolor(MAGENTA);
   int flag=0;
   outtextxy(150,130,"Reminder To Be set");
   infile.open("remaind.txt");
   while (1)
   {
   if(!infile)
   break;
   setcolor(LIGHTGRAY);
   infile >> b;
   if(!infile)
   break;
   outtextxy(170,160+j,"Event :");
    setcolor(3);
   outtextxy(250,160+j,b);
   infile >> a;
    setcolor(7);
   outtextxy(170,180+j,"Email :");
    setcolor(3);
   outtextxy(250,180+j,a);
   j=j+50;
   flag=1;

   }
   if(flag==0)
   {
   setcolor(GREEN);
   outtextxy(210,410,"No Reminder to be shown");
   }
   getch();
   adminscreen(A);
}

