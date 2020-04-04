/* ********************************************************************************** */
/* This program is developed and handled by  AYUSH CHOUDHARY                          */
/* Also this program has been compiled and executed successfully on TURBOC3 compiler  */
/* ********************************************************************************** */

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define  cls    system("cls")

struct  log_d{
    char id[20];
    char pwd[10];
}ld[20];

struct name{
   char first[15];
   char middle[15];
   char last[15];
};

struct mobile{
    char number[10];
};
struct dates{
   int month;
   int date;
   int year;
};

struct details{
   int roll;
   struct name ns;
   struct name nm;
   struct name nf;
   struct mobile n1;
   struct mobile n2;
   struct dates birth;
   struct dates addm;
   char email[30];
   char id[15];
}stdt[20];

/*########### FUNCTIONS DECLARATIONS ##########*/

void welcome();
void infinity();
int login();
int space(int,int);
int search(char [], char []);
void wait(int );
int admin_select(char [],char []);
int user_select(char [],char []);
int reading_file();
int change_pwd(char [29][15]);
int line_count(char []);
int word_count(char []);
int modify_student();
int del_line(char []);
int search_student(char []);
void input();
void output();
int add_account();
int delete_account(char []);
void about();
int num_student();

FILE *fp;

int main(){
   int gd=DETECT,gm,t=50;
   double tempx,tempy,i;
   char s[5];
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   welcome();
  /* for(i=30;i<=300;i++){
   tempx=getmaxx()/2+150*cos(t*3.14/180);
   tempy=getmaxy()/2-50*sin(t*3.14/180);

//putpixel(tempx,tempy,WHITE);
//sprintf(s,"%lf,%lf",tempx,tempy);
//outtextxy(10,10,s);
   setfillstyle(2,GREEN);
   circle(tempx,tempy,i/5);
   floodfill(tempx-1,tempy-1,WHITE);
   t++;
   delay(1);
   cleardevice();
   }*/
   infinity();
   setcolor(YELLOW);
   settextstyle(11,0,20);
   outtextxy(180,240,"Welcome to our Management System.");
   outtextxy(180,250,"Press any key to continue...");
   getch();
   closegraph();

   login();

   getch();
   return 0;
}

int login(){
  char ch;
  int i,j;
  //clrscr();
 system("cls");
  space(8,10);
  printf("USER_ID :");
  scanf("%s",ld[1].id);
  printf("\tPassword:");
  for(i=0;i<8;i++){
    ld[1].pwd[i]=getch();
    printf("*");
  }
  ld[1].pwd[8]='\0';
  search(ld[1].id,ld[1].pwd);

 return 0;
}


int space(int x,int y){
   int i,j;
   for(i=0;i<y;i++)
      printf("\n");
   for(j=0;j<x;j++)
      printf(" ");
  return 0;
}

int search(char id[],char pwd[]){

  FILE *fp;
  int i=1,j,words;
  char buffer[40][15],ch;
  char f_name[]="test.txt";
  //char id[12],pwd[10],ch;
  //clrscr();
  fflush(stdin);
  words=word_count(f_name);
  //lines=line_count(f_name);
  fp=fopen(f_name,"r");
  for(i=1;i<=words;i++){
    fscanf(fp,"%s",buffer[i]);
  }

  for(i=1;i<words;i+=2){
    if((strncmp(buffer[i],id,strlen(id))==0) && (strncmp(buffer[i+1],pwd,strlen(pwd))==0)){
      //printf("\nFound\n");//complete condition over here..
      //break;
      //else if over here..
       if((strncmp(id,"kiet",4)==0)||strncmp(id,"KIET",4)==0){
		     printf("\n\t>>ADMIN:Login Successfull\n");
		  do{
		admin_select(id,pwd);
		printf("\n\nDo you want the menu again(Y/y)");
		ch=getch();
		  }
		  while(ch=='Y'||ch=='y');
		  exit (EXIT_SUCCESS);
		  break;
	      }
       else{
		printf("\n\t>>USER:Login Successfull\n");

		  do{
			user_select(id,pwd);
			printf("Do you want the menu again(Y/y)");
			ch=getch();
		  }
		  while(ch=='Y'||ch=='y');
		    exit (EXIT_SUCCESS);
		    break;
	      }
	 }//external if closed..

    }

   if((i==words) || (i==words-1)|| (i==words+1)){
	       printf("\n\n\tLogin Failed..\n");
	       printf("\tDo you want to login again(Y/y)");
	       ch=getch();
	    if(ch=='Y'||ch=='y')
	       login();
	    else
	       exit (1);
   }
  printf("\n");
/*  for(j=1;j<words;j+=2){
    printf("%-15s%-10s\n",buffer[j],buffer[j+1]);
  }*/

  fclose(fp);
  getch();
  exit(EXIT_SUCCESS);
  return 1;
}

void welcome(){
int type=1,i,x,y;
x=getmaxx()/2;
y=getmaxy()/2;
switch(type++){
case 1: settextstyle(2,0,10);
	outtextxy(x,y,"W_");
	delay(200);
	cleardevice();

case 2: outtextxy(x-10,y,"WE_");
	delay(200);
	cleardevice();

case 3:outtextxy(x-30,y,"WEL_");
       delay(200);
       cleardevice();

case 4:outtextxy(x-50,y,"WELC_");
       delay(200);
       cleardevice();

case 5:outtextxy(x-70,y,"WELCO_");
       delay(200);
       cleardevice();

case 6:outtextxy(x-70,y,"WELCOM_");
       delay(200);
       cleardevice();

case 7:outtextxy(x-70,y,"WELCOME...");
       delay(1000);
       cleardevice();

 }
}
void infinity(){
  int gd=DETECT,gm,t=50,j;
   double tempx,tempy,i;
   char s[5];
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   for(t=0;t<360;t++){
   tempx=getmaxx()/2+(100*(1.414)*cos(t*3.14/180))/(pow(sin(t*3.14/180),2)+1);
   tempy=getmaxy()/2+(90*(1.414)*cos(t*3.14/180)*sin(t*3.14/180))/(pow(sin(t*3.14/180),2)+1);
  //printf("x==%ld\ny==%ld\n",tempx,tempy);
   putpixel(tempx,tempy,t%10);
   delay(10);
   }
   cleardevice();
}

/*void wait(int time){
  int i;
   for(i=0;i<time;i++){
   printf("\r-");delay(100);
   printf("\r/");delay(100);
   printf("\r|");delay(100);
   printf("\r\\");delay(100);
   printf("\r-");delay(100);
   printf("\r/");delay(100);
   printf("\r|");delay(100);
   printf("\r\\");delay(100);
   printf("\r-");
   }
   printf("\r\t>>Done\r");
}
*/

int admin_select(char id[],char pwd[]){
int choice,ch;
char _id[12];
printf("\nWhat do you want to do?\n");
printf("1:Modify Student Record.\n");
printf("2:Enter new student(s) record.\n");
printf("3:Search for student record.\n");
printf("4:Delete student Record.\n");
printf("5:Create new account.\n");
printf("6:Number of students.\n");
printf("7:Return to Login Page.\n");
printf("8:EXIT.\n");

scanf("%d",&choice);
switch(choice){
case 1:cls;
       modify_student();
       break;
case 2:cls;
       input();
       output();
       break;
case 3:cls;
       printf("Enter the student ID::");
       scanf("%s",_id);
       search_student(_id);
       break;
case 4:cls;
       printf("Enter the student ID::");
       scanf("%s",_id);
       del_line(_id);
       break;
case 5:cls;
       add_account();
       break;
case 6:cls;
       num_student();
       break;
case 7:cls;
       login();
       break;
case 8:exit(EXIT_SUCCESS);

default:printf("Enter appropriate choice.\n");
	printf("Do you want to go again(Y/y):");
	ch=getch();
	if(ch=='Y'||ch=='y')
	    admin_select(id ,pwd);
	else
	  exit(EXIT_SUCCESS);
}
return 0;
}


int user_select(char id[],char pwd[]){
int choice;
char ch;
printf("\nEnter your choice:\n");
printf("1:Change your login password.\n");
printf("2:Check your details.\n");
printf("3:ABOUT US.\n");
printf("4:Return to Login Page.\n");
printf("5:EXIT.\n");
scanf("%d",&choice);

switch(choice){
case 1:reading_file();        //cls; applied inside..
       break;
case 2:cls;
       search_student(id);
       break;
case 3:cls;
       about();
       break;
case 4:cls;
       login();
       break;
case 5:exit(EXIT_SUCCESS);
default:printf("Enter appropriate choice.\n");
	printf("Do you want to go again(Y/y):");
	ch=getch();
	if(ch=='Y'||ch=='y')
	    user_select(id,pwd);
	else
	  exit(1);
}
return 0;
}

int reading_file(){
  int i,return_value;
  char ch,buffer[29][15];
  char id[12];
  FILE *fp;
  //strcpy(ld[1].id,"kiet@ayush");
  printf("Reading from the file.\n");
  fp=fopen("test.txt","r");
  if(fp==NULL){
    printf("!!File not found..");
  }
  /*while((ch=fgetc(fp))!=EOF){
       printf("%c",ch);
  }*/
  printf("\n");
  fseek(fp,0,SEEK_SET);
  for(i=1;i<29;i++){
  fscanf(fp,"%s",buffer[i]);
  //printf("%s, ",buffer[i]);
  }
  printf(">>Done! Reading");
  fclose(fp);

  return_value=change_pwd(buffer);
  /*fp=fopen("test.txt","r");
  if(fp==NULL){
    printf("!!File not found..");
  }
  while((ch=fgetc(fp))!=EOF){
    printf("%c",ch);
  }

  fclose(fp);*/
  printf("\nYour new password is::%s\n",buffer[return_value]);
return 0;
}

int change_pwd(char buffer[29][15]){
  FILE *fp;
  int i,j;
  char pwd[10];
  /*printf("\nEnter the id you want to modify:");
  scanf("%s",id);*/
  cls;
  for(i=1;i<29;i++){
    if(strcmp(buffer[i],ld[1].id)==0){
	printf("\n\n-->Found>>%d<<\n",i);
	printf("Corresponding ID       :%s\n",ld[1].id);
	printf("Enter your new password:");
	scanf("%s",pwd);
	strcpy(buffer[i+1],pwd);
	j=i+1;
	break;
    }
  }

  if(i==29)
    printf("\n\n!!!!Not found");

    fp=fopen("test.txt","w");
     for(i=1;i<29;i+=2){
	fprintf(fp,"%-15s%-10s \n",buffer[i],buffer[i+1]);
     }

     printf("Password Changed Successfully..\n\n");
     fclose(fp);

  return j;
}

int modify_student(){
   FILE *fd;
   int words,lines,i,k=1;
   char buffer[1000][20],_id[12],ch;
   char f_name[]="DATABASE.txt";
   words=word_count(f_name);
   //printf("\n\nWords=%d\n",words);
   printf("\nEnter the student's ID to be modified::");
   scanf("%s",_id);
   fd=fopen(f_name,"r");
   if(fd==NULL)
      printf("Can't open file.");

   for(i=1;i<=words;i++){
     fscanf(fd,"%s",buffer[i]);
   }
   fclose(fd);   //reading file closed..

   for(i=1;i<words;i+=20){
      if(strcmp(buffer[i],_id)==0)
	       break;
      if(i==words-19){
	    if(strcmp(buffer[i],_id)!=0){
	        printf("\n!!!Not Found..");
            printf("\nYou have to login again::Press any key to continue..");
            getch();
            cls;
            login();
	     }
      }
   }

    printf("\n\n==========Student's Details Modify Module==========\n\n");
    printf("ID           ::");
      scanf("%s",stdt[1].id);
      strcpy(buffer[i],stdt[1].id);
    printf("Name         ::");
      scanf("%s%s%s",stdt[1].ns.first,stdt[1].ns.middle,stdt[1].ns.last);
      strcpy(buffer[i+1],stdt[1].ns.first);
      strcpy(buffer[i+2],stdt[1].ns.middle);
      strcpy(buffer[i+3],stdt[1].ns.last);
    printf("Roll no.     ::");
      scanf("%d",&stdt[1].roll);
      sprintf(buffer[i+4],"%d",stdt[1].roll);
    printf("Mother's Name::");
      scanf("%s%s%s",stdt[1].nm.first,stdt[1].nm.middle,stdt[1].nm.last);
      strcpy(buffer[i+5],stdt[1].nm.first);
      strcpy(buffer[i+6],stdt[1].nm.middle);
      strcpy(buffer[i+7],stdt[1].nm.last);
    printf("Father's Name::");
      scanf("%s%s%s",stdt[1].nf.first,stdt[1].nf.middle,stdt[1].nf.last);
      strcpy(buffer[i+8],stdt[1].nf.first);
      strcpy(buffer[i+9],stdt[1].nf.middle);
      strcpy(buffer[i+10],stdt[1].nf.last);
    printf("DOB          ::");
      scanf("%d%d%d",&stdt[1].birth.date,&stdt[1].birth.month,&stdt[1].birth.year);
      sprintf(buffer[i+11],"%d",stdt[1].birth.date);
      sprintf(buffer[i+12],"%d",stdt[1].birth.month);
      sprintf(buffer[i+13],"%d",stdt[1].birth.year);
    printf("Mobile       ::");
      scanf("%s",stdt[1].n1.number);
      strcpy(buffer[i+14],stdt[1].n1.number);
    printf("Father's mob ::");
      scanf("%s",stdt[1].n2.number);
      strcpy(buffer[i+15],stdt[1].n2.number);
    printf("DOA          ::");
      scanf("%d%d%d",&stdt[1].addm.date,&stdt[1].addm.month,&stdt[1].addm.year);
      sprintf(buffer[i+16],"%d",stdt[1].addm.date);
      sprintf(buffer[i+17],"%d",stdt[1].addm.month);
      sprintf(buffer[i+18],"%d",stdt[1].addm.year);
    printf("E-mail       ::");
      scanf("%s",stdt[1].email);
      strcpy(buffer[i+19],stdt[1].email);
    lines=line_count(f_name);
    fd=fopen(f_name,"w");

     for(i=1;i<lines;i++){
	fprintf(fd,"%-12s%-12s%-10s%-10s",buffer[k],buffer[k+1],buffer[k+2],buffer[k+3]);
	fprintf(fd,"%-5s%-10s%-10s%-10s",buffer[k+4],buffer[k+5],buffer[k+6],buffer[k+7]);
	fprintf(fd,"%-15s%-15s%-15s",buffer[k+8],buffer[k+9],buffer[k+10]);
	fprintf(fd,"%-4s%-4s%-6s",buffer[k+11],buffer[k+12],buffer[k+13]);
	fprintf(fd,"%-12s%-12s",buffer[k+14],buffer[k+15]);
	fprintf(fd,"%-4s%-4s%-6s",buffer[k+16],buffer[k+17],buffer[k+18]);
	fprintf(fd,"%-30s\t\n",buffer[k+19]);
	k+=20;
     }
     printf("\n\nDONE!!Your modifications has been implemented..");
     fclose(fd);
     fflush(stdin);
  return 0;
}

int word_count(char filename[]){
FILE *fp;
int i=0,inside_word=0;
char ch;
fp=fopen(filename,"r");
   while((ch=fgetc(fp))!=EOF){
	//printf("%c",ch);
	if((ch==' ')|| (ch == '\n') || (ch =='\t')){
	     inside_word=0;  //signifies that no word is here..
	}
	else if(inside_word==0) {
	     i++;
	     inside_word=1;   //signifies that word found..
       }
   }

fclose(fp);
return i;
}

int line_count(char filename[]){
FILE *fp;
int i=0;
char ch;
fp=fopen(filename,"r");
while((ch=fgetc(fp))!=EOF){
    if(ch=='\n')
	i++;
}
fclose(fp);
return (i+1);
}

void input(){
    int n,i;
    FILE *fd;

	      //------------------writing to database--------------------//
	       fd = fopen("DATABASE.txt","a");
	       printf("This is the student's Record Management System:\n");
	       printf("Enter 0 if you don't want to add any.\n");
	       printf("Enter the number of students:");
	       scanf("%d",&n);
	       for(i=0;i<n;i++){
		   printf("------Enter the record of student_%d-------\n",i+1);
		   printf("Enter student's ID                                     ::");
		   scanf("%s",stdt[i].id);
		   fprintf(fd,"%-12s",stdt[i].id);

		   printf("Enter the name of student:(first,middle,last)          ::");
		   scanf("%s%s%s",stdt[i].ns.first,stdt[i].ns.middle,stdt[i].ns.last);
		   fprintf(fd,"%-12s%-10s%-10s",stdt[i].ns.first,stdt[i].ns.middle,stdt[i].ns.last);

		   printf("Enter the roll no of student                           ::");
		   scanf("%d",&stdt[i].roll);
		   fprintf(fd,"%-5d",stdt[i].roll);

		   printf("Enter the name of student's mother:(first,middle,last) ::");
		   scanf("%s%s%s",stdt[i].nm.first,stdt[i].nm.middle,stdt[i].nm.last);
		   fprintf(fd,"%-10s%-10s%-10s",stdt[i].nm.first,stdt[i].nm.middle,stdt[i].nm.last);

		   printf("Enter the name of student's father:(first,middle,last) ::");
		   scanf("%s%s%s",stdt[i].nf.first,stdt[i].nf.middle,stdt[i].nf.last);
		   fprintf(fd,"%-15s%-15s%-15s",stdt[i].nf.first,stdt[i].nf.middle,stdt[i].nf.last);

		   printf("Enter student's date of birth(dd mm yyyy)              ::");
		   scanf("%d%d%d",&stdt[i].birth.date,&stdt[i].birth.month,&stdt[i].birth.year);
		   fprintf(fd,"%-4d%-4d%-6d",stdt[i].birth.date,stdt[i].birth.month,stdt[i].birth.year);

		   printf("Enter student's 10 digit mobile number                 ::");
		   scanf("%s",stdt[i].n1.number);
		   fprintf(fd,"%-12s",stdt[i].n1.number);

		   printf("Enter students's father 10 digit mobile number         ::");
		   scanf("%s",stdt[i].n2.number);
		   fprintf(fd,"%-12s",stdt[i].n2.number);

		   printf("Enter student's date of admission(dd mm yyyy)          ::");
		   scanf("%d%d%d",&stdt[i].addm.date,&stdt[i].addm.month,&stdt[i].addm.year);
		   fprintf(fd,"%-4d%-4d%-6d",stdt[i].addm.date,stdt[i].addm.month,stdt[i].addm.year);
		   printf("Enter student's email id                               ::");
		   scanf("%s",stdt[i].email);
		   fprintf(fd,"%-30s\t\n",stdt[i].email);

		   printf("\n");

		  if((i+1)==n)
		      printf("Done!!Thanks for your details.");
	      }
     fclose(fd);
     fflush(stdin);
}


void output(){
    int ch;
    FILE *fd;
    printf("\n\n==========Student's Details==========\n\n");
    printf("%-12s%-30s%-5s%-30s%-45s%-14s%-12s%-12s%-14s%-30s\n","ID","Student's name","R.N.","Mother's name","Father's name","DOB","Mobile","Father mob.","DOA","E-mail");
    printf("===========================================================================================================================================================================\n");
    fd=fopen("DATABASE.txt","r");
    while((ch=fgetc(fd))!=EOF){
	 printf("%c",ch);
    }

    fclose(fd);
}

int search_student(char id[]){
   FILE *fd;
   int words,i;
   char buffer[1000][20];
   char f_name[]="DATABASE.txt";
   words=word_count(f_name);
   //printf("\n\nWords=%d\n",words);
   fd=fopen("DATABASE.txt","r");
   if(fd==NULL)
      printf("\nCan't open file.");

   for(i=1;i<=words;i++){
     fscanf(fd,"%s",buffer[i]);
   }

   for(i=1;i<words;i+=20){
      if(strcmp(buffer[i],id)==0)
	     break;

      if(i==words-19){
	     if(strcmp(buffer[i],id)!=0){
	        printf("\n!!!Not Found..");
	        return ;
	     }
      }
   }

    printf("\n\n==========Student's Details==========\n\n");
    printf("ID             ::%s\n",buffer[i]);
    printf("Name           ::%s %s %s\n",buffer[i+1],buffer[i+2],buffer[i+3]);
    printf("Roll no.       ::%s\n",buffer[i+4]);
    printf("Mother's Name  ::%s %s %s\n",buffer[i+5],buffer[i+6],buffer[i+7]);
    printf("Father's Name  ::%s %s %s\n",buffer[i+8],buffer[i+9],buffer[i+10]);
    printf("DOB(dd/mm/yyyy)::%s %s %s\n",buffer[i+11],buffer[i+12],buffer[i+13]);
    printf("Mobile         ::%s\n",buffer[i+14]);
    printf("Father's mob   ::%s\n",buffer[i+15]);
    printf("DOA(dd/mm/yyyy)::%s %s %s\n",buffer[i+16],buffer[i+17],buffer[i+18]);
    printf("E-mail         ::%s \n",buffer[i+19]);

    fflush(stdin);
return 0;
}

int add_account(){
  int i,n;
  char ch,chr,buffer[30];
  cls;
  fp=fopen("test.txt","a");
  printf("Enter the number of enteries:");
  scanf("%d",&n);
  if(n!=0)
    printf("ID\t\tpassword\n");
  for(i=1;i<=n;i++){
  scanf("%s",ld[i].id);
  scanf("%s",ld[i].pwd);
  fprintf(fp,"%-15s%-12s\n",ld[i].id,ld[i].pwd);
  }
  printf("\n\nDONE!! with %d enteries.\n",n);
  fclose(fp);

  printf("Do you want to check the details(Y/y)");
  ch=getch();
   if(ch=='Y'|| ch=='y')
   {
     cls;
     printf("\n########## Reading ##########\n");
     fp=fopen("test.txt","r");
     while((ch=fgetc(fp))!=EOF){
	    printf("%c",ch);
     }
   }
   else
     exit (EXIT_SUCCESS);
    printf("\nDONE!!");
   printf("Do you want to add student's details(Y/y).");
   chr=getch();
   cls;
   if(chr=='Y'||chr=='y'){
      input();
   }
   else
    admin_select("kiet@ayush","ayush123");
  return 0;
}

int del_line(char id[]){
  FILE *fo,*ft;
  int words,i,line=1,k=1,temp=1;
  char ch;
  char buffer[1000][20];
  char f_name[]="DATABASE.txt";
  fo=fopen(f_name,"r");
  words=word_count(f_name);
   //printf("\n\nWords=%d\n",words);
   fclose(fo);
   fo=fopen(f_name,"r");
   if(fo==NULL)
      printf("\nCan't open file.");

   for(i=1;i<=words;i++){
     if(i==(k*20)){
	     line++;
	     k++;
     }
     fscanf(fo,"%s",buffer[i]);
     if(strcmp(buffer[i],id)==0)
	    break;
   }
   if(i>words+1)
    printf("ERROR!!Not Found!!");
   //printf("\n\nline::%d\n\n",line);
   rewind(fo);
   ft=fopen("temp_f.txt","w");
   while((ch=fgetc(fo))!=EOF){
    if(ch=='\n')
	 temp++;
    if(temp!=line)
	   putc(ch,ft);
   }
   fclose(fo);
   fclose(ft);

   fo=fopen(f_name,"w");
   ft=fopen("temp_f.txt","r");
   while((ch=fgetc(ft))!=EOF){
       putc(ch,fo);
       //printf("%c",ch);
   }
fclose(fo);
fclose(ft);
remove("temp_f.txt");
fflush(stdin);
delete_account(id);
if(i!=words+1)
  printf("\n\nDONE!!The data of id:\"%s\" has been successfully removed..",id);

return 0;
}

int delete_account(char ID[]){
int i,words,lines,j;
FILE *fd;
char buff[50][15];
char f_name[]="test.txt";
words=word_count(f_name);
lines=line_count(f_name);
fd=fopen(f_name,"r");
for(i=1;i<=words;i++){
    fscanf(fd,"%s",buff[i]);
}
fclose(fd);
/*for(j=1;j<=words;j+=2){
    printf("%-15s%-12s\n",buff[j],buff[j+1]);
}*/

j=1;
  fd=fopen(f_name,"w");
  for(i=1;i<lines;i++){
    if(strncmp(buff[j],ID,10)!=0)
	    fprintf(fd,"%-15s%-12s\n",buff[j],buff[j+1]);
    j=j+2;
}
fclose(fd);
fflush(stdin);
return 0;
}

void about(){
  FILE *ab;
  char gc;
  ab=fopen("about.txt","r");
  while((gc=fgetc(ab))!=EOF){
    printf("%c",gc);
  }
  fclose(ab);
 }

int num_student(){
   int num_count;
   char f_name[]="DATABASE.txt";
   FILE *fp;
   cls;
   fp=fopen(f_name,"r");

   num_count=line_count(f_name);

   printf("The number of students are :%d",num_count-1);
   fclose(fp);
   return 0;
}
