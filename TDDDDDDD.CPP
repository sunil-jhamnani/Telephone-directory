#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
/**************************************************************************
CLASS NAME - stud
DETAILS - It contains functions to implement changes in contacts
**************************************************************************/

class stud
{
   char firstn[20],lastn[20],city[20],state[20],colony[30],m_l;
   unsigned long int ph_no;
   int age,street_no,plot_no,code;

public:

/**************************************************************************
FUNCTION NAME - get()
DETAILS - It takes information of new contact by user and initialise them
	  in respective data members
**************************************************************************/

   void get()
   {
	cout<<"\n\tEnter the first name : ";
	gets(firstn);
	cout<<"\n\tEnter the last name : ";
	gets(lastn);
	cin.get();
	cout<<"\n\tEnter your age : ";
	cin>>age;
	cout<<"\n\tEnter your state : ";
	gets(state);
	cout<<"\n\tEnter your city : ";
	gets(city);
	cout<<"\n\tEnter your colony name or sector number : ";
	gets(colony);
	cin.get();
	cout<<"\n\tEnter your street number (else press 0) : ";
	cin>>street_no;
	cout<<"\n\tEnter your plot number : ";
	cin>>plot_no;
	cout<<"\n\tEnter the type of connection you want(m for mobile,l for landline) : ";
	cin>>m_l;
	if(toupper(m_l)=='M')
	{
	  ph_no=1829084000+plot_no;
	  cout<<"\n\n\tYou are alloted the number : "<<ph_no;
	  getch();
	}
	else
	 if(toupper(m_l)=='L')
	  {
	    cout<<"\n\tEnter your 4 digit city code : ";
	    cin>>code;
	    ph_no=(2740000+code+plot_no);
	    cout<<"\n\n\tYou are alloted the number : "<<ph_no;
	    getch();
	  }
   }

/**************************************************************************
FUNCTION NAME - show()
DETAILS - It displays information of person using phone number, address
	  and name of th person
**************************************************************************/

   void show()
   {
	cout<<"\n\tNAME         : "<<firstn<<' '<<lastn;
	cout<<"\n\tAGE          : "<<age;
	cout<<"\n\tADDRESS     ==> ";
	cout<<"\n\t                  STATE : " <<state;
	cout<<"\n\t		  CITY  : "<<city;
	cout<<"\n\t		  COLONY NAME OR SECTOR NUMBER : "<<colony;
	cout<<"\n\t		  STREET NUMBER : "<<street_no;
	cout<<"\n\t		  PLOT NUMBER   : "<<plot_no;
	cout<<"\n\tTYPE OF CONNECTION : ";
	if(m_l=='M')
	{
	   cout<<"MOBILE";
	   cout<<"\n\tPHONE NUMBER : "<<ph_no;
	}
	cout<<"LANDLINE";
	cout<<"\n\tPhone number : "<<ph_no;
   }

/**************************************************************************
FUNCTION NAME - modify()
DETAILS - It modifies anyexisting contact and allocate a ner phone number
	  according to the modification
**************************************************************************/

   void modify()
   {
	cout<<"\n\tCurrent name    :"<<firstn<<' '<<lastn;
	cout<<"\n\tCurrent age     :"<<age;
	cout<<"\n\tCurrent address ==>";
	cout<<"\n\n\t                 STATE :" <<state;
	cout<<"\n\t                 CITY  : "<<city;
	cout<<"\n\t                 COLONY NAME OR SECTOR NUMBER : "<<colony;
	if(street_no!=0)
	cout<<"\n\t                 STREET NUMBER : "<<street_no;
	cout<<"\n\t                 PLOT NUMBER   : "<<plot_no;
	cout<<"\n\tCurrent phone number :"<<ph_no;
	cout<<"\n\tEnter new details ==>\n";
	char first[20],last[20],cit[20],stat[20],colny[30],ml;
	unsigned long int ph;
	int ag,str,plot,cod;
	cout<<"\n\tNew name (enter '.' for old one in each) : ";
	cout<<"\n\t       First name : ";
	gets(first);
	cout<<"\n\t       Last name : ";
	gets(last);
	cout<<"\n\tNew age (enter '-1' for old one) : ";
	cin>>ag;
	cout<<"\n\tNew address (enter '1' for old one in each) : ";
	cout<<"\n\t          State : ";
	gets(stat);
	cout<<"\n\t          City  : ";
	gets(cit);
	cout<<"\n\t          Colony name or sector number : ";
	gets(colny);
	cout<<"\n\t          Street number (else press 0) : ";
	cin>>str;
	cout<<"\n\t          Plot number : ";
	cin>>plot;
	if(toupper(m_l)=='L')
	{
	   cout<<"\n\tEnter your new 4 digit city code (enter '0' for old one in each) : ";
	   cin>>cod;
	   ph_no=(2740000+code+plot_no);
	   cout<<"\n\n\tYou are alloted the number : "<<ph_no;
	}
	else
	   if(toupper(m_l)=='M')
	   {
	      ph_no=1829084000+plot_no;
	      cout<<"\n\n\tYou are alloted the number : "<<ph_no;
	   }
	if(strcmpi(first,".") != 0)
	   strcpy(firstn,first);
	if(strcmpi(last,".") != 0)
	   strcpy(lastn,last);
	if(strcmpi(stat,"1") != 0)
	   strcpy(state,stat);
	if(strcmpi(cit,"1") != 0)
	   strcpy(city,cit);
	if(strcmpi(colny,"1") != 0)
	   strcpy(colony,colny);
	if(str!=0)
	 if(str!=1)
	   street_no=str;
	if(plot!=1)
	   plot_no=plot;
	if(ag!=-1)
	   age=ag;
   }
/**************************************************************************
ACCESSOR FUNCTIONS - These functions are used to get the values
		     of the required data member.
**************************************************************************/
   char *get_first()
   {
	return(firstn);
   }

   char *get_last()
   {
	return(lastn);
   }
   char *get_state()
   {
	return(state);
   }
   char *get_city()
   {
	return(city);
   }
   char *get_col()
   {
	return(colony);
   }
   int get_street()
   {
	return(street_no);
   }
   int get_plot()
   {
	return(plot_no);
   }
   unsigned long int get_ph()
   {
	return(ph_no);
   }
};

/**************************************************************************
FUNCTION NAME - main()
DETAILS - It calls all the functions
**************************************************************************/

void main()
{
    int gdriver = DETECT, gmode, errorcode;
    int midx,midy;

    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, "");

    /* read result of initialization */
    errorcode = graphresult();
    if (errorcode != grOk)          /* an error occurred */
    {
       printf("Graphics error: %s\n", grapherrormsg(errorcode));
       printf("Press any key to halt:");
       getch();
       exit(1); /* terminate with an error code */
       closegraph();
    }
    y:

    setcolor(BLACK);
    textbackground(0) ;
    for(int i=1;i<=250;i++)
    {
	 setcolor(i);
	 cleardevice();
	 settextstyle(7, HORIZ_DIR, 5);
	 outtextxy(i+70,80,"WELCOME");
	 outtextxy(i,200,"TO THE PROJECT");
	 delay(20);
    }
    setcolor(BLACK);
    textbackground(BLUE);
    for(int j=1;j<=250;j++)
    {
	 setcolor(j);
	 cleardevice();
	 settextstyle(7, HORIZ_DIR, 5);
	 outtextxy(100,j-50,"TELEPHONE SERVICE");
	 outtextxy(230,j+100,"CENTRE");
	 delay(20);
    }
     outtextxy(70,250,"\n\nTELEPHONE DIRECTORY");
     settextstyle(7,0,1);
     for(i=1;i<=250;i++)
    {
	 setcolor(9+i);
	 cleardevice();
	 outtextxy(i,200,"Designed by :-");
	 outtextxy(400-i,270,"SHUBHAM KEDIA");
	 sound(500+i);
    }
	 nosound();
	 int a=320;
	 int b=250;
	 for(i=0;i<=3000;i++)
    {
	 putpixel(rand()%(a+=1),rand()%(b+=1),i);
	 delay(2);
    }
	 delay(1000);
    clearviewport();
    int ch,stt,pl,ph;
    char st[20],c[30],ft[30],l[30],o[30],ans;
    stud s;
    z:

    clearviewport();
    setbkcolor(6);
    setcolor(WHITE);
    cout<<"\n\n\n\n\n\n\n\n\n";
    rectangle(60,10,600,400);
    settextstyle(2,0,6);
    outtextxy(200,30," HELP -> PRESS ANY KEY 1 TO 6 " );
    outtextxy(220,50,"\n\n\n1. ADD NEW CONTACT " );
    outtextxy(220,100,"\n\n2. SHOW CONTACT" );
    outtextxy(220,150,"\n\n3. SEARCH CONTACT" );
    outtextxy(220,200,"\n\n4. MODIFY CONTACT" );
    outtextxy(220,250,"\n\n5. DELETE ANY CONTACT" );
    outtextxy(220,300,"\n\n6. EXIT " );
    outtextxy(220,350," Enter the choice ==>");
    gotoxy(55,23);
    cin>>ch;
    switch(ch)
    {
	case  1:  //responsible for addition of record
	{
	  do
	   {
	       clearviewport();
	       fstream f;
	       f.open("rec.txt",ios::in|ios::out|ios::ate|ios::app|ios::binary);
	       gotoxy(1,1);
	       s.get();
	       f.write((char *)&s,sizeof(s));
	       clearviewport();
	       outtextxy(250,360, "   Do you want to add more (y/n) ==> ");
	       ans=getch();
	       clearviewport();
	       f.close();
	   }while(toupper(ans)=='Y');
	  break;
	}
	case 2:  // will show all the contents of the file
	do{
	 clearviewport();
	 gotoxy(1,1);
	 cout<<"\n\n";
	 fstream f;
	 f.open("rec.txt",ios::in|ios::out|ios::ate|ios::app|ios::binary);
	 f.seekg(0);
	 int ctr=0;
	 while(f.read((char *)&s,sizeof(s)))
	 {
	    ctr=ctr+1;
	    if(ctr==20)
	    {
	       getchar();
	       clearviewport();
	       ctr=0;
	    }
	    s.show();
	    getch();
	    clearviewport();
	    gotoxy(1,1);
	    cout<<endl;
	    if(f.eof()==1)
	       break;
	 }
	 f.close();
	 outtextxy(240,350, "        Do you want to see more(y/n) ==>");
	 ans=getche();
	 }while(ans=='y' || ans=='Y');
	 goto z;


	case 3:  // will search contacts
	{
	  do
	   {
	       int flag=0;
	       clearviewport();
	       gotoxy(1,1);
	       cout<<"\n\n";
	       fstream f;
	       outtextxy(100,30,"OPTIONS ==>" );
	       outtextxy(120,50,"\n\n1. SEARCH USING NAME" );
	       outtextxy(120,100,"\n\n2. SEARCH USING ADDRESS" );
	       outtextxy(120,150,"\n\n3. SEARCH USING PHONE NUMBER" );
	       outtextxy(120,200,"\n\nEnter the choice (1-3) ->" );
	       gotoxy(47,14);
	       cin>>ch;
	       clearviewport();
	       f.open("rec.txt",ios::in|ios::out|ios::ate|ios::app|ios::binary);
	       f.seekg(0);
		 switch(ch)
		 {
		   case 1 :

		   gotoxy(1,1);
		   cout<<"\n\tEnter first name (if not known press n) : ";
		   gets(ft);
		   cout<<"\n\tEnter last name (if not known press n) : ";
		   gets(l);
		   while(f.read((char *)&s,sizeof(s)))
		   {
		     if(strcmpi(ft,s.get_first()) == 0||strcmpi(l,s.get_last()) == 0)
		     {
		       flag=1;
		       s.show();
		       getch();
		       clearviewport();
		       if(f.eof()==1)
			 break;
		     }
		   }
		   break;
		   case 2 :

		   gotoxy(1,1);
		   int p;
		   cout<<"\n\tEnter the state : ";
		   gets(st);
		   cout<<"\n\tEnter the city : ";
		   gets(c);
		   cout<<"\n\t1. Search contacts of a colony or sector";
		   cout<<"\n\t2. Search contacts using street number";
		   cout<<"\n\t3. Search contacts using plot number";
		   cout<<"\n\tEnter your choice (1-3) ==>";
		   gotoxy(37,9);
		   cin>>p;
		   if(p==1)
		   {
		     cout<<"\n\tEnter the colony or sector no. : ";
		     gets(o);
		     while(f.read((char *)&s,sizeof(s)))
		     {
		       if(strcmpi(st,s.get_state()) == 0&&strcmpi(c,s.get_city()) == 0)
			 if(strcmpi(o,s.get_col()) == 0)
			 {
			   flag=1;
			   s.show();
			   getch();
			   clearviewport();
			   if(f.eof()==1)
			     break;
			 }
		     }
		   }
		   else
		   if(p==2)
		   {
		     cout<<"\n\tEnter the street no. : ";
		     cin>>stt;
		     while(f.read((char *)&s,sizeof(s)))
		     {
		       if(strcmpi(st,s.get_state()) == 0&&strcmpi(c,s.get_city()) == 0)
			 if(stt==s.get_street())
		       {
			 flag=1;
			 s.show();
			 getch();
			 clearviewport();
			 if(f.eof()==1)
			   break;
		       }
		     }
		   }
		   else
		   {
		     cout<<"\n\tEnter the plot no. : ";
		     cin>>pl;
		     while(f.read((char *)&s,sizeof(s)))
		     {
		       if(strcmpi(st,s.get_state()) == 0&&strcmpi(c,s.get_city()) == 0)
		       if(pl==s.get_plot())
		       {
			 flag=1;
			 s.show();
			 getch();
			 clearviewport();
			 if(f.eof()==1)
			   break;
		       }
		      }
		   }
		   break;
		   case 3 :

		   gotoxy(1,1);
		   cout<<"\n\tEnter the phone no.(if landline include the city code) : ";
		   cin>>ph;
		   while(f.read((char *)&s,sizeof(s)))
		   {
		   if(ph==s.get_ph());
		   {
		     flag=1;
		     s.show();
		     getch();
		     clearviewport();
		     if(f.eof()==1)
		       break;
		   }
		   }
		   break;
		 }

	       f.close();
	       if(flag==0)
		 cout<<"\n\tRecord not found!!!!!";
	       outtextxy(240,350, "Do you want to search more(y/n) ==>");
	       ans=getche();
	   }while(toupper(ans)=='Y');
	   break;
	   }
	case 4:  //for the modification
	{
	  do
	   {
	       clearviewport();
	       gotoxy(1,1);
	       fstream f; stud s;
	       f.open("rec.txt",ios::in|ios::binary);
	       cout<<"\n\tEnter the details of person whose contact is to be modefied ==>";
	       cout<<"\n\tEnter first name :";
	       gets(ft);
	       cout<<"\n\tEnter last name  :";
	       gets(l);
	       cout<<"\n\tEnter state      :";
	       gets(st);
	       cout<<"\n\tEnter city       :";
	       gets(c);
	       clearviewport();
	       do
	       {
		  f.read((char *)&s,sizeof(s));
		  if(f.eof()==1)
		    break;
		  if(strcmpi(ft,s.get_first())==0&&strcmpi(l,s.get_last())==0&&strcmpi(st,s.get_state())==0&&strcmpi(c,s.get_city())==0)
		    break;
	       }while(f);
	       if(f.eof()!=0)
		 cout<<"\n\tRecord not found!!!!!";
	       else
	       {
		 gotoxy(1,1);
		 s.modify();
		 int l=f.tellg();
		 f.close();
		 f.open("rec.txt",ios::out|ios::binary|ios::ate);
		 f.seekg(l-sizeof(s));
		 f.write((char *)&s,sizeof(s));
	       }
	       f.close();
	       clearviewport();
	       outtextxy(270,360,"Do you want to modify more records(y/n) :-");
	       ans=getche();
	   }while(toupper(ans)=='Y');
	   break;
	  }
	case 5:  //responsible for the deletion of the record
	{
	  do{
	   clearviewport();
	   gotoxy(1,1);
	   int flag=0;
	   stud s;
	   ifstream fin;
	   fstream fout;
	   fin.open("rec.txt",ios::in|ios::binary);
	   fout.open("temp.txt",ios::app|ios::binary);
	   int i;
	   cout<<"\n\tEnter the details of person whose contact is to be deleted ==>";
	   cout<<"\n\tEnter first name :";
	   gets(ft);
	   cout<<"\n\tEnter last name  :" ;
	   gets(l);
	   cout<<"\n\tEnter state      :" ;
	   gets(st);
	   cout<<"\n\tEnter city       :" ;
	   gets(c);
	   while(fin.eof()==0)
	   {
	     fin.read((char *)&s,sizeof (s));
	     if(strcmpi(ft,s.get_first())==0&&strcmpi(l,s.get_last())==0&&strcmpi(st,s.get_state())==0&&strcmpi(c,s.get_city())==0)
	     { flag=1;
	     }
	     else
	      if(fin.eof()==1)
		  break;
	      else
	       {
		  fout.write((char*)&s,sizeof(s));
	       }

	    }
	   if(flag==0)
	   {
	     cout<<"\n\n\t\tRecord not found!!!!!!";
	     getch();
	     goto data;
	   }
	   fin.close();
	   fout.close();
	   remove("rec.txt");
	   rename("temp.txt","rec.txt");
	   cout<<"\n\t\tRecord get Deleted";
	   getchar();

	   data :
	   outtextxy(240,340, "Do you want to delete more(y/n):- ");
	   ans=getche();
	  }while(ans=='y' || ans=='Y');
	  break;
	}
	case 6:
	{
	 /*   clearviewport();
	    outtextxy(150,360,"****** THE END OF THE PROJECT ******");
	    outtextxy(200,390,"\n \n\n\n\n   PLEASE PRESS ENTER");
	    getchar();
	    clearviewport();
	    setbkcolor(0);
	    for (int i=0 ; i<2000; ++i )	    //Put Stars
	    {
	      putpixel(random(720), random(560), random( 16-1 )+1);
	      delay(1);
	    }
	    delay(1000);
	    setcolor(3);
	    settextstyle(1,0,7);
	    outtextxy(150,100,"THANK YOU");
	    outtextxy(150,250,"VISIT AGAIN");
	    delay(2000); */
	    closegraph();
	    exit(1);
	}
	default:

	    goto z;
    }
    goto z;

}



