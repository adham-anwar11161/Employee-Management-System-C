#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

typedef struct{
int day;
int month;
int year;
}date;
typedef struct {
int id;
char name [30];
float salary;
date birth_date;
char address[40];
char mobile[16];
date enrollment_date;
char email[25];
}employee;
employee company[100];
int employee_count=0;
COORD coord= {0,0};
void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void drawbox (){
    int i,x;
gotoxy(39,10);
printf("%c",201);
for(i=1;i<30;i++)
    printf("%c",205);
 printf("%c",187);
 for (x=11;x<20;x++){
    gotoxy(39,x);
    printf("%c",186);
    for(i=1;i<30;i++)
        printf("%c",32);
    printf("%c",186);
}
gotoxy(39,20);
printf("%c",200);
for(i=1;i<30;i++)
    printf("%c",205);
 printf("%c",188);
}
void sort_emp() {

    int i, j;
    employee temp;
for (i = 0; i < employee_count - 1; i++) {
        for (j = 0; j < employee_count - i - 1; j++) {
            if (strcmp(company[j].name, company[j + 1].name) > 0) {
                temp = company[j];
                company[j] = company[j + 1];
                company[j + 1] = temp;
            }
        }
    }
}

int vali_mob(char mob[]){
if (strlen(mob)!=11)return 0;
for(int i=0;mob[i]!='\0';i++){
    if(mob[i]<'0' || mob[i]>'9')return 0;
}
return 1;
}
int vali_email(char email[]) {
    int i;
    int at_pos = -1;
    int dot_pos = -1;
    int at_count = 0;

    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_count++;
            at_pos = i;
        }
        if (email[i] == '.') {
            dot_pos = i;
        }
    }

    if ((at_count == 1 && at_pos > 0 )&& (dot_pos > at_pos + 1 )&& email[dot_pos + 1] != '\0') {
        return 1;
    }
return 0;
}
void add_emp(){
system("cls");
    int i,id,repeated_id;

    do {
        repeated_id = 0;
        printf("enter ur ID: ");
        scanf("%d", &id);

        for (i = 0; i < employee_count; i++) {
            if (company[i].id == id) {
                repeated_id = 1;
                printf("Errorrrr This ID already exists\n",id);
                break;
            }
        }
    } while (repeated_id == 1);

    company[employee_count].id = id;

    printf("Enter ur Full Name: ");
    getchar();
    gets(company[employee_count].name);
printf("Enter Salary: ");
scanf("%f", &company[employee_count].salary);
printf("Enter Birth Date :\n ");
printf("day: ");
scanf("%d", &company[employee_count].birth_date.day);
printf("month: ");
 scanf("%d",&company[employee_count].birth_date.month);
 printf("year: ");
scanf("%d",&company[employee_count].birth_date.year);

    printf("Enter Address: ");
   getchar();
    gets(company[employee_count].address);
        printf("Enter Mobile Number: ");
 gets(company[employee_count].mobile);
do{

  if(vali_mob(company[employee_count].mobile)==0){
   printf("incorrect plz enter  11 digit\n");
  printf("Enter a correct Mobile Number: ");
 gets(company[employee_count].mobile);}
 else
    break;
}while(3);


    printf("Enter Email: ");
    gets(company[employee_count].email);
    do{

  if(vali_email(company[employee_count].email)==0){
   printf("incorrect plz enter corr email\n");
  printf("Enter a correct email : ");
 gets(company[employee_count].email);}
 else
    break;
}while(3);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    company[employee_count].enrollment_date.day = tm.tm_mday;
    company[employee_count].enrollment_date.month = tm.tm_mon + 1;
    company[employee_count].enrollment_date.year = tm.tm_year + 1900;


    printf("Enrollment Date set to: %d-%d-%d\n",
            company[employee_count].enrollment_date.day,
            company[employee_count].enrollment_date.month,
            company[employee_count].enrollment_date.year);
    printf("\n successfully added \n");
    employee_count++;


}
void print_emp(){
    system("cls");
sort_emp();
    if (employee_count == 0) {
        printf("No employees found in the system.\n");
        return;
        }

    printf("-+--+--+- Employees -+--+--+-\n");
    int i;
    for (i = 0; i < employee_count; i++) {

        printf("ID: %d\n", company[i].id);
        printf("name: %s\n", company[i].name);
        printf("salary: %.2f\n", company[i].salary);
        printf("birth Date: %d-%d-%d\n", company[i].birth_date.day, company[i].birth_date.month, company[i].birth_date.year);
        printf("address: %s\n", company[i].address);
        printf("Mobile: %s\n", company[i].mobile);
        printf("Enrollment Date: %d-%d-%d\n", company[i].enrollment_date.day, company[i].enrollment_date.month, company[i].enrollment_date.year);
        printf("Email: %s\n", company[i].email);
         printf("= = = = = = = = = = = = = \n");
    }
    printf("Total Employees: %d\n", employee_count);



}
void query_emp() {
    system("cls");

    if (employee_count == 0) {
        printf("No employees in the system to search for.\n");
        return;
    }

    char search[30];
    int i, found = 0;

    printf("Enter anyy part of employee name: ");

    gets(search);
printf("\n--- afterr Searching  ---\n");
    for (i = 0; i < employee_count; i++) {
        if (strstr(company[i].name, search) != NULL) {
            found = 1;
            printf("------------------<>-----------------\n");
            printf("ID: %d\n", company[i].id);
            printf("Name: %s\n", company[i].name);
            printf("Salary: %.2f\n", company[i].salary);
            printf("Birth Date: %d-%d-%d\n", company[i].birth_date.day, company[i].birth_date.month, company[i].birth_date.year);
            printf("Address: %s\n", company[i].address);
            printf("Mobile: %s\n", company[i].mobile);
            printf("Enrollment Date: %02d-%02d-%04d\n", company[i].enrollment_date.day, company[i].enrollment_date.month, company[i].enrollment_date.year);
            printf("Email: %s\n", company[i].email);
        }
    }

    if (found == 0) {
        printf("No employees found\n");

    }}
void delete_emp() {
    system("cls");
    if (employee_count == 0) {
        printf("No employees to delete.\n");
        return;
    }

    int del;
    int i, j, found = -1;

    printf("Enter ID to delete: ");
    scanf("%d", &del);

    for (i = 0; i < employee_count; i++) {
        if (company[i].id ==del) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\ntrying to delete an employee that is not in the file\n");
    }

    else {
        for (j = found; j < employee_count - 1; j++) {
            company[j] = company[j + 1];
        }
        employee_count--;
        printf("\nEmployee  deleted successfully!\n");
    }

}
void save_emp() {
    system("cls");
    FILE *fp = fopen("emp.txt", "w");
    if (fp == NULL) {
        printf("Error opening file \n");
        return;
    }

    int i;
    for (i = 0; i < employee_count; i++) {
        fprintf(fp, "%d,%s,%.2f,%d-%d-%d,%s,%s,%d-%d-%d,%s\n",
                company[i].id,
                company[i].name,
                company[i].salary,
                company[i].birth_date.day,
                company[i].birth_date.month,
                company[i].birth_date.year,
                company[i].address,
                company[i].mobile,
                company[i].enrollment_date.day,
                company[i].enrollment_date.month,
                company[i].enrollment_date.year,
                company[i].email);
    }

    fclose(fp);
}
void load_emp() {
 system("cls");
    FILE *fp = fopen("emp.txt", "r");
    if (fp == NULL) {
            printf("u dont have a file");
        return;
    }
    char* token;
    int rec_no=0,field_no;
    char line[200];
employee_count = 0;

    while (fgets(line,sizeof(line),fp)!=NULL)
    { rec_no++;
    token =strtok(line,",");
    field_no=0;
 while(token!=NULL){
    field_no++;
    switch (field_no){
case 1:
    company[employee_count].id=atoi(token);
    break;
    case 2:
    strcpy(company[employee_count].name,token);
    break;
    case 3:
    company[employee_count].salary=atof(token);
    break;
    case 4:
    company[employee_count].birth_date.day=atoi(token);
    break;
    case 5:
    company[employee_count].birth_date.month=atoi(token);
    break;
    case 6:
    company[employee_count].birth_date.year=atoi(token);
    break;
    case 7:
    strcpy(company[employee_count].address,token);
    break;
    case 8:
    strcpy(company[employee_count].mobile,token);
    break;
    case 9:
    company[employee_count].enrollment_date.day=atoi(token);
    break;
    case 10:
    company[employee_count].enrollment_date.month=atoi(token);
    break;
    case 11:
    company[employee_count].enrollment_date.year=atoi(token);
    break;
    case 12:
    strcpy(company[employee_count].email,token);
    break;
    }
    token = strtok(NULL,",-\n");
    }


        employee_count++;
    }

    fclose(fp);
}
void modify_emp() {
    system("cls");
    char ch;
    if (employee_count == 0) {
        printf("No employees \n");
        return;
    }
    int id;
    int i, found = -1;
    int choice =1;

    printf("Enter ID to modify: ");
    scanf("%d", &id);

    for (i = 0; i < employee_count; i++) {
        if (company[i].id == id) {
            found = i;
            break;
        }
    }

    if (found== -1) {
        printf("\n not found\n");
        return;
    }

    printf("\nEmployee Found: %s\n", company[found].name);
    printf("What do you want to modify?\n");
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
while(1){
drawbox();
do{
SetConsoleTextAttribute(hConsole, 15);
gotoxy(40, 11); printf(" 1] name ");
gotoxy(40, 13); printf(" 2] salary ");
gotoxy(40, 15); printf(" 3] address  ");
gotoxy(40, 17); printf(" 4] mobile ");
gotoxy(40, 19); printf(" 5] email ");

 printf("\n");


switch(choice){
case 1:
SetConsoleTextAttribute(hConsole, 240);
gotoxy(40, 11); printf(" 1] name ");
break;
case 2:
    SetConsoleTextAttribute(hConsole, 240);
   gotoxy(40, 13); printf(" 2] salary ");
   break;
case 3:
    SetConsoleTextAttribute(hConsole, 240);
    gotoxy(40, 15); printf(" 3] address  ");
    break;
case 4:
    SetConsoleTextAttribute(hConsole, 240);
   gotoxy(40, 17); printf(" 4] mobile ");
    break;
case 5:
    SetConsoleTextAttribute(hConsole, 240);
    gotoxy(40, 19); printf(" 5] email ");
    break;

}
 ch=_getch();
if(ch==-32)ch=getch();
if(ch==72){
    choice--;
    if(choice==0)choice=5;
}
if(ch==80){
    choice++;
    if(choice==6)choice=1;
}

}while(ch!=13);
SetConsoleTextAttribute(hConsole, 2);

printf("\n");
    switch (choice) {
        case 1:
            printf(" New Name: ");
           getchar();
            gets(company[found].name);
            printf("\nName updated successfully!\n");
            return;
        case 2:
            printf(" New Salary: ");
            scanf("%f", &company[found].salary);
            printf("\nSalary updated successfully!\n");
           return;
        case 3:
            printf(" New Address: ");
            getchar();
            gets(company[found].address);
            printf("\nAddress updated successfully!\n");
            return;
        case 4:
            printf(" New Mobile: ");
            getchar();
            gets(company[found].mobile);
            do{

  if(vali_mob(company[found].mobile)==0){
   printf("incorrect plz enter digits min 11 digit\n");
  printf("Enter a correct Mobile Number: ");
 gets(company[found].mobile);}
 else
    break;
}while(3);
            printf("\nMobile updated successfully!\n");
            return;
        case 5:
            printf(" New Email: ");
           getchar();
            gets(company[found].email);
            do{

  if(vali_email(company[found].email)==0){
   printf("incorrect plz enter corr email\n");
  printf("Enter a correct email : ");
 gets(company[found].email);}
 else
    break;
}while(3);
            printf("\nEmail updated successfully!\n");
           return;

    }
}}
int main(){
    load_emp();
     int pos=1;
char ch,yn;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
while(1){
drawbox();
do{
SetConsoleTextAttribute(hConsole, 15);
gotoxy(40, 11); printf(" 1] Load ");
gotoxy(40, 12); printf(" 2] Query ");
gotoxy(40, 13); printf(" 3] Add  ");
gotoxy(40, 14); printf(" 4] delete ");
gotoxy(40, 15); printf(" 5] modify ");
gotoxy(40, 16); printf(" 6] print ");
gotoxy(40, 17); printf(" 7] save ");
gotoxy(40, 18); printf(" 8] quit ");
 printf("\n");


switch(pos){
case 1:
SetConsoleTextAttribute(hConsole, 240);
gotoxy(40, 11); printf(" 1] Load ");
break;
case 2:
    SetConsoleTextAttribute(hConsole, 240);
   gotoxy(40, 12); printf(" 2] Query ");
   break;
case 3:
    SetConsoleTextAttribute(hConsole, 240);
    gotoxy(40, 13); printf(" 3] Add  ");
    break;
case 4:
    SetConsoleTextAttribute(hConsole, 240);
   gotoxy(40, 14); printf(" 4] delete ");
    break;
case 5:
    SetConsoleTextAttribute(hConsole, 240);
    gotoxy(40, 15); printf(" 5] modify ");
    break;
case 6:
        SetConsoleTextAttribute(hConsole, 240);
    gotoxy(40, 16); printf(" 6] print ");
    break;
case 7:SetConsoleTextAttribute(hConsole, 240);
    gotoxy(40, 17); printf(" 7] save ");
    break;
case 8:SetConsoleTextAttribute(hConsole, 240);
    gotoxy(40, 18); printf(" 8] quit ");
    break;
}
            ch=_getch();
if(ch==-32)ch=getch();
if(ch==72){
    pos--;
    if(pos==0)pos=8;
}
if(ch==80){
    pos++;
    if(pos==9)pos=1;
}

}while(ch!=13);
SetConsoleTextAttribute(hConsole, 2);
gotoxy(0,0);
printf("\n");
switch(pos){
case 1:

    load_emp();
break;
case 2:
 printf(" Query \n");
 query_emp();
   break;
case 3:
printf("Add \n ");
add_emp();
    break;
case 4:
printf("  delete\n ");
delete_emp();
    break;
case 5:
 printf(" modify \n");
 modify_emp();
    break;
case 6:
printf(" print\n ");
print_emp();
    break;
case 7:
 printf(" save \n ");
 save_emp();
    break;
case 8:
     printf("  quit\n ");
     printf("are u sure u wanna to quit!!\n Y / N ");
    yn = _getch();
     if(yn=='y'|| yn=='Y' )
        exit(0);
     else
        break;
        }}

return 0;
}
