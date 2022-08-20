#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<custom.h>
#include<windows.h>
#define up 72
#define down 80
#define left 75
#define right 77
#define Cancel 2
#define Ok 1
#define TryAgain 10
#define Continue 11
#define Ignore 5
#define Retry 4
#define Abort 3
#define Yes 6
#define No 7

struct user_accounts
{
    char account_type;  //no encryption
    char first_name[60];
    char last_name[60];
    char username[60];
    char guest_admin[60];
    char guest_username[60];
    char password[60];
    char Backup_key[60];
    char Data_key[60];
    char library_name[60];
    char mobile[60];
    char email[60];
    char bookpath[200];
    char stdpath[200];
    char issuepath[200];
    char categoriepath[200];
    char invoice_path[200];
    char main_folderPath[200];  //no encryption
    //Permission's
    int add_new_books;       //no encryption
    int Delete_books;       //no encryption
    int Change_book_name;       //no encryption
    int Change_category;       //no encryption
    int Change_writer_name;       //no encryption
    int Change_rent_rate;       //no encryption
    int Change_extra_charge;       //no encryption
    int Change_book_qty;       //no encryption
    int Change_book_price;       //no encryption
    int Change_rack_number;      //no encryption
    int View_all_book;
    int export_all_books;
    int issue_book_permission;
    int submit_books;
    int view_issued_books;
    int view_invoices;
    int view_all_invoices;
    int export_issued_book;
    int Export_all_invoice;
    int add_new_students;
    int remove_students;
    int search_students;
    int change_student_name;
    int chnage_father_name;
    int change_mobile_number;
    int chnage_roll_number;
    int view_all_students;
    int Export_student_data;
    int add_new_categoryes;
    int remove_categoryes;
    int search_categoryes;
    int view_all_categoryes;
}guser,chacking;

struct last_login
{
    char Name_1[60];
    char Name_2[60];
    char Name_3[60];
    char Name_4[60];
    char Name_5[60];
}glogs;

struct Invoice
{
    char invoive_no[15];
    char std_id[15];
    char std_class[15];
    char std_roll_no[15];
    char mobile[15];
    char book_id[15];
    char book_name[60];
    char std_name[60];
    char book_category[60];
    char rent_charge[60];
    char extra_charge[60];
    char total_amount[60];
    char day_of_submit[5];
    char month_of_submit[5];
    char year_of_submit[7];
    char issue_day[5];
    char issue_month[5];
    char issue_year[7];
    char submit_day[5];
    char submit_month[5];
    char submit_year[7];
}ginvoice;

struct issue_books
{
    char std_id[15];
    int book_id;
    char book_name[60];
    char std_name[60];
    char std_mobile[15];
    int issue_day;
    int issue_month;
    int issue_year;
    int submit_day;
    int submit_month;
    int submit_year;
}gissuedata;

struct books
{
    int id;
    char book_name[60];
    char writer[60];
    char categorie[60];
    int qty;
    int book_price;
    int rent_price;
    int extra_charge;
    int rack_no;
}gbookdata;

struct categorie
{
    char categorie_id[60];
    char categorie[60];
}gcategorie;

struct students
{
    char id[15];
    char name[60];
    char father_name[60];
    char std_class[15];
    char roll_no[15];
    char year[6];
    char mobile[15];
    int joine_day;
    int joine_month;
    int joine_year;
}gstudent;
struct settings
{
    int auto_gernate_backupkey;
    int auto_gernate_datakey;
    int auto_detect_date;
    int set_permission_while_creating_acoount;
    int password_masking;
    int warnings;
    int auto_open_invoice;
    int auto_gernate_invoice_no;
}gsetting;
//Define Path for File
    char userpath[300];
    char fix_mainfolder[]="BRIGHTGOAL\\FixFolder.dat";
    char tempfile[]="BRIGHTGOAL\\tempfile.dat";
    char main_path[]="BRIGHTGOAL";
    char setting_path[]="BRIGHTGOAL\\Setting.ini";
    char Last_logins[]="BRIGHTGOAL\\Last_logs.dat";
    char Exported_data[]="BRIGHTGOAL\\EXPORTED DATA";
    char Export_fix[]="BRIGHTGOAL\\EXPORTED DATA\\FixFolder.dat";
    int login_status;
int main_menu()
{
    char ch;
    char a_type;
    int re,i;
    int x,y,x1,y1,point,pointx;
    restart_complete_mainmenu:
    system("cls");
    system("COLOR bC");
    console_title("Harvindar Singh - 9140417112, www.brightgoal.in");
    Hide_cursor();
    buffer_size(116,45);
    adjustWindowSize(0,0,111,42);
    Bk_color(28,1);
    back_freame(0,111,0,2);
    Bk_color(28,15);
    MSGinM("BRIGHTGOAL LIBRARY MANAGEMENT NSYSTEM POWERED BY HARVINDAR SINGH",1);
    Bk_color(180,17);
    drowlineH(0,110,42,220);
    Bk_color(117,17);
    drowlineV(3,42,0,219);
    drowlineV(3,42,111,219);
    ind_back_freame(1,110,40,42,28,180,1);
    buffer_size(112,43);
    adjustWindowSize(0,0,112,43);
    restart_menu:
    Bk_color(180,7);
    //window(2,38,6,41);
    //window(40,109,6,41);
    main_menu_background();
    working_area_background();
    ind_back_freame(2,38,3,5,117,180,12);
    ind_back_freame(40,109,3,5,117,180,12);
    notification();
    Bk_color(28,15);
    gotoxy(2,41);
    printf("%c STATUS BAR",14);
    Bk_color(197,15);
    gotoxy(17,4);
    printf("MAIN MENU");
    x=3;
    x1=38;
    y=6;
    pointx=6;
    reset:
        y1=y+2;
        point=y+1;
        Bk_color(117,1);
        if(x==3)
        {
            gotoxy(12,7);
            printf("Login");
            gotoxy(12,9);
            printf("Create New Account");
            gotoxy(12,11);
            printf("Manage Accounts");
            gotoxy(12,13);
            printf("Setting");
            gotoxy(12,15);
            printf("Rules & Instructions");
            gotoxy(12,17);
            printf("About");
            gotoxy(12,19);
            printf("Exit");
            /*gotoxy(12,23);
            printf("Intructions");
            gotoxy(12,25);
            printf("About");
            gotoxy(12,27);
            printf("Close Application");
            gotoxy(12,29);
            printf("Option 13");
            gotoxy(12,31);
            printf("Option 14");
            gotoxy(12,33);
            printf("Option 15");
            gotoxy(12,35);
            printf("Option 16");
            gotoxy(12,37);
            printf("Option 17");*/
            setcolor(14);
            menu_option(x,x1,y,y1);
            Bk_color(225,9);
            if(y+1==7 && x==3)
            {
                gotoxy(12,7);
                printf("Login");
            }
            if(y+1==9 && x==3)
            {
                gotoxy(12,9);
                printf("Create New Account");
            }
            if(y+1==11 && x==3)
            {
                gotoxy(12,11);
                printf("Manage Accounts");
            }
            if(y+1==13 && x==3)
            {
                gotoxy(12,13);
                printf("Setting");
            }
            if(y+1==15 && x==3)
            {
                gotoxy(12,15);
                printf("Rules & Instructions");
            }
            if(y+1==17 && x==3)
            {
                gotoxy(12,17);
                printf("About");
            }
            if(y+1==19 && x==3)
            {
                gotoxy(12,19);
                printf("Exit");
            }
            /*if(y+1==21 && x==3)
            {
                gotoxy(12,21);
                printf("Exit");
            }
            if(y+1==23 && x==3)
            {
                gotoxy(12,23);
                printf("Intructions");
            }
            if(y+1==25 && x==3)
            {
                gotoxy(12,25);
                printf("About");
            }
            if(y+1==27 && x==3)
            {
                gotoxy(12,27);
                printf("Close Application");
            }
            if(y+1==29 && x==3)
            {
                gotoxy(12,29);
                //printf("Option 13");
            }
            if(y+1==31 && x==3)
            {
                gotoxy(12,31);
                //printf("Option 14");
            }
            if(y+1==33 && x==3)
            {
                gotoxy(12,33);
                //printf("Option 15");
            }
            if(y+1==35 && x==3)
            {
                gotoxy(12,35);
                //printf("Option 16");
            }
            if(y+1==37 && x==3)
            {
                gotoxy(12,37);
                //printf("Option 17");
            }*/
        }
        gotoxy(pointx,point);
        printf("%c",249);
        Bk_color(117,14);
        rechoise:
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        Bk_color(117,14);
        gotoxy(56,4);
        ch=getch();
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>6 && y<=18)
                    {
                        gotoxy(pointx,point);
                        printf("%c",256);
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y-2;
                        goto reset;
                    }
                    goto rechoise;
                case down:
                    if(y>=6 && y<18)
                    {
                        gotoxy(pointx,point);
                        printf("%c",256);
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y+2;
                        goto reset;
                    }
                    goto rechoise;
                }
            }
            else
            {
                goto reset;
            }
        }
        else if(ch==13)
        {
            switch(y+1)
            {
            case 7:
                re=Login(0);
                if(re==202)
                {
                    notification();
                    Hide_cursor();
                    goto reset;
                }
                Hide_cursor();
                Bk_color(28,1);
                strip_of_title_bar(1,1);
                Bk_color(28,15);
                Copy_string_to_other_in_uupercase(guser.library_name,guser.library_name);
                MSGinM(guser.library_name,1);
                if(guser.account_type=='a')
                {
                    Bk_color(28,15);
                    gotoxy(2,41);
                    printf("LOGIN BY : ");
                    for(i=0;i<15;i++)
                    {
                        if(guser.first_name[i]=='\0')
                            break;
                        if(guser.first_name[i]>='a' && guser.first_name[i]<='z')
                            printf("%c",guser.first_name[i]-32);
                        else
                            printf("%c",guser.first_name[i]);
                    }
                    if(i==15)
                        printf("...");
                    gotoxy(34,41);
                    printf("TYPE : ADMINISTRATOR");
                }
                if(guser.account_type=='g')
                {
                    Bk_color(28,15);
                    gotoxy(2,41);
                    printf("LOGIN BY : ");
                    for(i=0;i<15;i++)
                    {
                        if(guser.first_name[i]=='\0')
                            break;
                        if(guser.first_name[i]>='a' && guser.first_name[i]<='z')
                            printf("%c",guser.first_name[i]-32);
                        else
                            printf("%c",guser.first_name[i]);
                    }
                    if(i==15)
                        printf("...");
                    gotoxy(34,41);
                    printf("TYPE : GUEST");
                }
                login_status=1;
                update_logs(guser.first_name);
                library_main_menu();
                login_status=0;
                Bk_color(28,1);
                update_status_bar(1,41);
                strip_of_title_bar(1,1);
                Bk_color(28,15);
                gotoxy(2,41);
                printf("%c STATUS BAR",14);
                MSGinM("BRIGHTGOAL LIBRARY MANAGEMENT NSYSTEM POWERED BY HARVINDAR SINGH",1);
                Bk_color(117,15);
                Hide_cursor();
                notification();
                Clear_buffer();
                goto restart_menu;
                break;
            case 9:
                re=choose_account_type(&a_type);
                if(re==103)
                {
                    re=Login(a_type);
                    Hide_cursor();
                    Clear_buffer();
                    if(re==202)
                    {
                        Hide_cursor();
                        Bk_color(117,15);
                        notification();
                        goto reset;
                    }
                    re=chack_total_guest_account(guser.username);
                    if(re>=10)
                    {
                        Bk_color(28,15);
                        //re=MessageBoxA(NULL,"  You can create only 10 guest\n  account of the administrator account"," ERROR",16);
                        rec_MSGinM("YOU CAN CREATE ONLY 10 GUEST",40,109,35);
                        rec_MSGinM("ACCOUNT OF THE ADMINISTRATOR ACCOUNT",40,109,37);
                        print_date_time(74,95,41,61,20);
                        Clear_buffer();
                        Bk_color(117,15);
                        notification();
                        Hide_cursor();
                        goto reset;
                    }
                }
                if(re==202)
                {
                    Hide_cursor();
                    Bk_color(117,15);
                    notification();
                    goto reset;
                }
                create_account(a_type);
                Clear_buffer();
                Hide_cursor();
                Bk_color(117,15);
                notification();
                goto reset;
                break;
            case 11:
                manage_accounts();
                Hide_cursor();
                notification();
                goto restart_menu;
                break;
            case 13:
                setting();
                notification();
                goto reset;
                break;
            case 15:
                Hide_cursor();
                rules_of_software();
                Clear_buffer();
                notification();
                goto reset;
                break;
            case 17:
                about();
                Clear_buffer();
                notification();
                goto reset;
                break;
            case 19:
                exit(0);
                break;
            case 21:
                view_all_account();
                Clear_buffer();
                goto reset;
                break;
            case 23:
                exit(0);
                break;
            case 25:
                break;
            case 27:
                break;
            case 29:
                break;
            case 31:
                break;
            case 33:
                break;
            case 35:
                break;
            case 37:
                break;
            case 39:
                break;
            }
        }
        else
        {
            goto reset;
        }
    getch();
}
int print_login_status()
{
    int i;
    if(guser.account_type=='a')
    {
        Bk_color(28,15);
        gotoxy(2,41);
        printf("LOGIN BY : ");
        for(i=0;i<15;i++)
        {
            if(guser.first_name[i]=='\0')
                break;
            if(guser.first_name[i]>='a' && guser.first_name[i]<='z')
                printf("%c",guser.first_name[i]-32);
            else
                printf("%c",guser.first_name[i]);
        }
        if(i==15)
            printf("...");
        gotoxy(34,41);
        printf("TYPE : ADMINISTRATOR");
    }
    if(guser.account_type=='g')
    {
        Bk_color(28,15);
        gotoxy(2,41);
        printf("LOGIN BY : ");
        for(i=0;i<15;i++)
        {
            if(guser.first_name[i]=='\0')
                break;
            if(guser.first_name[i]>='a' && guser.first_name[i]<='z')
                printf("%c",guser.first_name[i]-32);
            else
                printf("%c",guser.first_name[i]);
        }
        if(i==15)
            printf("...");
        gotoxy(34,41);
        printf("TYPE : GUEST");
    }
}
int library_main_menu()
{
    char ch;
    int x,x1,y,y1;
    Clear_buffer();
    restart_library_menu:
    Bk_color(180,7);
    main_menu_background();
    ind_back_freame(2,38,3,5,117,180,12);
    Bk_color(197,15);
    rec_MSGinM("LIBRARY MENU",2,38,4);
    notification();
    x=3;
    x1=38;
    y=6;
    reset:
        y1=y+2;
        Bk_color(117,1);
        if(x==3)
        {
            gotoxy(12,7);
            printf("Book Management");
            gotoxy(12,9);
            printf("Book Transaction");
            gotoxy(12,11);
            printf("Students Management");
            gotoxy(12,13);
            printf("Categories Management");
            gotoxy(12,15);
            printf("Logout");
            /*gotoxy(12,17);
            printf("Logout");
            /*gotoxy(12,19);
            printf("About");
            gotoxy(12,21);
            printf("Exit");
            gotoxy(12,23);
            printf("Intructions");
            gotoxy(12,25);
            printf("About");
            gotoxy(12,27);
            printf("Close Application");
            gotoxy(12,29);
            printf("Option 13");
            gotoxy(12,31);
            printf("Option 14");
            gotoxy(12,33);
            printf("Option 15");
            gotoxy(12,35);
            printf("Option 16");
            gotoxy(12,37);
            printf("Option 17");*/
            setcolor(14);
            menu_option(x,x1,y,y1);
            Bk_color(225,9);
            if(y+1==7 && x==3)
            {
                gotoxy(12,7);
                printf("Book Management");
            }
            if(y+1==9 && x==3)
            {
                gotoxy(12,9);
                printf("Book Transaction");
            }
            if(y+1==11 && x==3)
            {
                gotoxy(12,11);
                printf("Students Management");
            }
            if(y+1==13 && x==3)
            {
                gotoxy(12,13);
                printf("Categories Management");
            }
            if(y+1==15 && x==3)
            {
                gotoxy(12,15);
                printf("Logout");
            }
            /*if(y+1==17 && x==3)
            {
                gotoxy(12,17);
                printf("Logout");
            }
            /*if(y+1==19 && x==3)
            {
                gotoxy(12,19);
                printf("About");
            }
            if(y+1==21 && x==3)
            {
                gotoxy(12,21);
                printf("Exit");
            }
            if(y+1==23 && x==3)
            {
                gotoxy(12,23);
                printf("Intructions");
            }
            if(y+1==25 && x==3)
            {
                gotoxy(12,25);
                printf("About");
            }
            if(y+1==27 && x==3)
            {
                gotoxy(12,27);
                printf("Close Application");
            }
            if(y+1==29 && x==3)
            {
                gotoxy(12,29);
                //printf("Option 13");
            }
            if(y+1==31 && x==3)
            {
                gotoxy(12,31);
                //printf("Option 14");
            }
            if(y+1==33 && x==3)
            {
                gotoxy(12,33);
                //printf("Option 15");
            }
            if(y+1==35 && x==3)
            {
                gotoxy(12,35);
                //printf("Option 16");
            }
            if(y+1==37 && x==3)
            {
                gotoxy(12,37);
                //printf("Option 17");
            }*/
        }
        Bk_color(117,14);
        rechoise:
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        Bk_color(117,14);
        gotoxy(56,4);
        ch=getch();
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>6 && y<=14)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y-2;
                        goto reset;
                    }
                    goto rechoise;
                case down:
                    if(y>=6 && y<14)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y+2;
                        goto reset;
                    }
                    goto rechoise;
                }
            }
            else
            {
                goto reset;
            }
        }
        else if(ch==13)
        {
            switch(y+1)
            {
            case 7:
                Book_management();
                goto restart_library_menu;
                break;
            case 9:
                book_transaction();
                goto restart_library_menu;
                break;
            case 11:
                student_management();
                goto restart_library_menu;
                break;
            case 13:
                category_management();
                goto restart_library_menu;
                break;
            case 15:
                return 1;
                break;
            }
        }
        else
        {
            goto reset;
        }
}
int Book_management()
{
    char ch;
    int x,x1,y,y1;
    Clear_buffer();
    restat_book_menu:
    Bk_color(180,7);
    main_menu_background();
    ind_back_freame(2,38,3,5,117,180,12);
    Bk_color(197,15);
    rec_MSGinM("BOOK MANAGEMENT",2,38,4);
    notification();
    x=3;
    x1=38;
    y=6;
    reset:
        y1=y+2;
        Bk_color(117,1);
        if(x==3)
        {
            gotoxy(10,7);
            printf("Add New Book");
            gotoxy(10,9);
            printf("Delete Book");
            gotoxy(10,11);
            printf("Search Book");
            gotoxy(10,13);
            printf("Change Book Name");
            gotoxy(10,15);
            printf("Change Category");
            gotoxy(10,17);
            printf("Change Writer Name");
            gotoxy(10,19);
            printf("Chnage Rent Rate");
            gotoxy(10,21);
            printf("Change Extra Charge");
            gotoxy(10,23);
            printf("Change Book Quantity");
            gotoxy(10,25);
            printf("Change Book Price");
            gotoxy(10,27);
            printf("Change Rack Number");
            gotoxy(10,29);
            printf("View All Book");
            gotoxy(10,31);
            printf("Export All Book's In Excel");
            /*gotoxy(12,33);
            printf("Option 15");
            gotoxy(12,35);
            printf("Option 16");
            gotoxy(12,37);
            printf("Option 17");*/
            setcolor(14);
            menu_option(x,x1,y,y1);
            Bk_color(225,9);
            if(y+1==7 && x==3)
            {
                gotoxy(10,7);
                printf("Add New Book");
            }
            if(y+1==9 && x==3)
            {
                gotoxy(10,9);
                printf("Delete Book");
            }
            if(y+1==11 && x==3)
            {
                gotoxy(10,11);
                printf("Search Book");
            }
            if(y+1==13 && x==3)
            {
                gotoxy(10,13);
                printf("Change Book Name");
            }
            if(y+1==15 && x==3)
            {
                gotoxy(10,15);
                printf("Change Category");
            }
            if(y+1==17 && x==3)
            {
                gotoxy(10,17);
                printf("Change Writer Name");
            }
            if(y+1==19 && x==3)
            {
                gotoxy(10,19);
                printf("Chnage Rent Rate");
            }
            if(y+1==21 && x==3)
            {
                gotoxy(10,21);
                printf("Change Extra Charge");
            }
            if(y+1==23 && x==3)
            {
                gotoxy(10,23);
                printf("Change Book Quantity");
            }
            if(y+1==25 && x==3)
            {
                gotoxy(10,25);
                printf("Change Book Price");
            }
            if(y+1==27 && x==3)
            {
                gotoxy(10,27);
                printf("Change Rack Number");
            }
            if(y+1==29 && x==3)
            {
                gotoxy(10,29);
                printf("View All Book");
            }
            if(y+1==31 && x==3)
            {
                gotoxy(10,31);
                printf("Export All Book's In Excel");
            }
            /*if(y+1==33 && x==3)
            {
                gotoxy(12,33);
                //printf("Option 15");
            }
            if(y+1==35 && x==3)
            {
                gotoxy(12,35);
                //printf("Option 16");
            }
            if(y+1==37 && x==3)
            {
                gotoxy(12,37);
                //printf("Option 17");
            }*/
        }
        Bk_color(117,14);
        rechoise:
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        Bk_color(117,14);
        gotoxy(56,4);
        ch=getch();
        if(ch==27)
        {
            return 202;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>6 && y<=30)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y-2;
                        goto reset;
                    }
                    goto rechoise;
                case down:
                    if(y>=6 && y<30)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y+2;
                        goto reset;
                    }
                    goto rechoise;
                }
            }
            else
            {
                goto reset;
            }
        }
        else if(ch==13)
        {
            switch(y+1)
            {
            case 7:
                if(guser.add_new_books)
                {
                    add_new_book();
                    Hide_cursor();
                    notification();
                    Clear_buffer();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto restat_book_menu;
                break;
            case 9:
                if(guser.Delete_books)
                {
                    delete_book();
                    notification();
                    Hide_cursor();
                    Clear_buffer();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 11:
                search_book();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 13:
                if(guser.Change_book_name)
                {
                    modify_book_data(1);
                    Hide_cursor();
                    notification();
                    Clear_buffer();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 15:
                if(guser.Change_category)
                {
                    modify_book_data(2);
                    notification();
                    Clear_buffer();
                    Hide_cursor();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 17:
                if(guser.Change_writer_name)
                {
                    modify_book_data(3);
                    notification();
                    Clear_buffer();
                    Hide_cursor();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 19:
                if(guser.Change_rent_rate)
                {
                    modify_book_data(4);
                    notification();
                    Clear_buffer();
                    Hide_cursor();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 21:
                if(guser.Change_extra_charge)
                {
                    modify_book_data(5);
                    notification();
                    Clear_buffer();
                    Hide_cursor();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 23:
                if(guser.Change_book_qty)
                {
                    modify_book_data(6);
                    notification();
                    Clear_buffer();
                    Hide_cursor();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 25:
                if(guser.Change_book_price)
                {
                    modify_book_data(7);
                    notification();
                    Clear_buffer();
                    Hide_cursor();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 27:
                if(guser.Change_rack_number)
                {
                    modify_book_data(8);
                    notification();
                    Clear_buffer();
                    Hide_cursor();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 29:
                if(guser.View_all_book)
                {
                    system("cls");
                    view_all_books();
                    system("cls");
                    system("COLOR bc");
                    main_frame(180,guser.library_name);
                    Bk_color(180,7);
                    main_menu_background();
                    ind_back_freame(2,38,3,5,117,180,12);
                    Bk_color(197,15);
                    rec_MSGinM("BOOK MANAGEMENT",2,38,4);
                    print_login_status();
                    notification();
                    Hide_cursor();
                    Clear_buffer();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
                break;
            case 31:
                if(guser.export_all_books)
                {
                    export_all_books_to_excel();
                    notification();
                    Hide_cursor();
                    Clear_buffer();
                }
                else
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                goto reset;
            }
        }
        else
        {
            goto reset;
        }
}
int export_all_books_to_excel()
{
    int re;
    char temp[15];
    char newline[]="\n";
    char next_column[]=",";
    FILE *fp,*fp1;
    char filename[60];
    char file_path[250];
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("EXPORT BOOK'S TO EXCEL SHEET");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("FILE NAME");
    Bk_color(28,15);
    field_of_mainmenu(60,20);
    mkdir(Exported_data);
    reinput_file_name:
        Show_cursor(7);
        strcpy(file_path,Exported_data);
        Bk_color(252,0);
        re=input_string_undermainmenu(filename,46,61,20);
        if(re==202)
        {
            return 202;
        }
        Hide_cursor();
        strcat(filename,".csv");
        strcat(file_path,"\\");
        strcat(file_path,filename);
        if(chack_file_name(file_path)==1)
        {
            MessageBoxA(NULL," File name already exist, Please Enter another name of the file."," Error",16);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            goto reinput_file_name;
        }
        fp=fopen(file_path,"w");
        fp1=fopen(guser.bookpath,"rb");
        if(fp==NULL || fp1==NULL)
        {
            MessageBoxA(NULL,"  An Error! book list could not exported to excel sheet, please try again."," Error",16);
            Clear_buffer();
            return 0;
        }
        fputs("Book Id,Book Name,Writer,Category,Quantity,Book Price,Rack Number,Rent Rate,Extra Charge\n",fp);
        while(fread(&gbookdata,sizeof(struct books),1,fp1)>0)
        {
            decryption(gbookdata.book_name);
            decryption(gbookdata.writer);
            decryption(gbookdata.categorie);
            convert_number_to_string(gbookdata.id,temp);
            fputs(temp,fp);
            fputs(next_column,fp);
            fputs(gbookdata.book_name,fp);
            fputs(next_column,fp);
            fputs(gbookdata.writer,fp);
            fputs(next_column,fp);
            fputs(gbookdata.categorie,fp);
            fputs(next_column,fp);
            convert_number_to_string(gbookdata.qty,temp);
            fputs(temp,fp);
            fputs(next_column,fp);
            convert_number_to_string(gbookdata.book_price,temp);
            fputs(temp,fp);
            fputs(next_column,fp);
            convert_number_to_string(gbookdata.rack_no,temp);
            fputs(temp,fp);
            fputs(next_column,fp);
            convert_number_to_string(gbookdata.rent_price,temp);
            fputs(temp,fp);
            fputs(next_column,fp);
            convert_number_to_string(gbookdata.extra_charge,temp);
            fputs(temp,fp);
            fputs(newline,fp);
        }
        fclose(fp);
        fclose(fp1);
        MessageBoxA(NULL," All Book's Successfully Exported.\nFind File on this Path : brightgoal->exported data"," Book's Exported",64);
        Clear_buffer();
        return 1;

}
int delete_book()
{
    int re,bookid;
    FILE *fp,*fp1;
    Bk_color(180,11);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("DELETE BOOK");
    Bk_color(28,15);
    gotoxy(42,23);
    printf("BOOK ID");
    delete_more_book:
    Bk_color(28,15);
    field_of_mainmenu(60,23);
    Show_cursor(7);
    reinput_bookid:
    re=input_numbers_undermainmenu(&bookid,9,61,23);
    if(re==202)
    {
        return 202;
    }
    if(chack_book_id(bookid)!=1)
    {
        MessageBoxA(NULL," Incorrect Book ID please enter valid book id."," Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(28,0);
        goto reinput_bookid;
    }
    if(chack_book_id_in_issuelist(bookid,&re)==1)
    {
        MessageBoxA(NULL," You can not delete this book. because this book issued to a student."," Invalid Action",48);
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(252,0);
        Clear_buffer();
        goto reinput_bookid;
    }
    re=MessageBoxA(NULL," Are you sure you want to delete book Permanently."," Confirm Message",36);
    if(re!=Yes)
    {
        return 0;
    }
    fp=fopen(guser.bookpath,"rb");
    fp1=fopen(tempfile,"wb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not delete the book."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gbookdata,sizeof(struct books),1,fp)>0)
    {
        if(bookid!=gbookdata.id)
        {
            fwrite(&gbookdata,sizeof(struct books),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen(guser.bookpath,"wb");
    fp1=fopen(tempfile,"rb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not delete the book."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gbookdata,sizeof(struct books),1,fp1)>0)
    {
        fwrite(&gbookdata,sizeof(struct books),1,fp);
    }
    fclose(fp);
    fclose(fp1);
    remove(tempfile);
    re=MessageBoxA(NULL," Book Successfully deleted, you want to delete one more book."," Book Deleted",68);
    Clear_buffer();
    if(re==Yes)
    {
        goto delete_more_book;
    }
    return 1;
}
int get_available_qty_ofbook(int book_id)
{
    int total_book_qty,issude_book_qty,available_book_qty;
    if(get_qty_of_book(book_id,&total_book_qty)==1)
    {
        if(chack_book_id_in_issuelist(book_id,&issude_book_qty)==1)
        {
            available_book_qty=total_book_qty-issude_book_qty;
            return available_book_qty;
        }
        else
        {
            return total_book_qty;
        }
    }
    else
    {
        return 0;
    }
}
int get_qty_of_book(int book_id,int *qty_of_book)
{
    FILE *fp;
    fp=fopen(guser.bookpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&gbookdata,sizeof(struct books),1,fp)>0)
    {
        if(book_id==gbookdata.id)
        {
            fclose(fp);
            *qty_of_book=gbookdata.qty;
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int modify_book_data(int type)
{
    int re,bookid,issued_book;
    FILE *fp,*fp1;
    char msgbox[140],issuedbooks[15];
    struct books modify_data;
    Bk_color(180,11);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("MODIFY BOOK DATA");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("BOOK ID");
    gotoxy(42,23);
    if(type==1)
    {
        printf("NEW BOOK NAME");
    }
    else if(type==2)
    {
        printf("NEW CATEGORY");
    }
    else if(type==3)
    {
        printf("NEW WRITER NAME");
    }
    else if(type==4)
    {
        printf("NEW RENT RATE");
    }
    else if(type==5)
    {
        printf("NEW EXTRA CHARGE");
    }
    else if(type==6)
    {
        printf("NEW QUANTITY");
    }
    else if(type==7)
    {
        printf("NEW BOOK PRICE");
    }
    else if(type==8)
    {
        printf("NEW RACK NUMBER");
    }
    modify_more_book:
    Bk_color(28,15);
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    Show_cursor(7);
    reinput_bookid:
    re=input_numbers_undermainmenu(&bookid,9,61,20);
    if(re==202)
    {
        return 202;
    }
    if(chack_book_id(bookid)!=1)
    {
        MessageBoxA(NULL," Incorrect Book ID please enter valid book id."," Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,20);
        Bk_color(28,0);
        goto reinput_bookid;
    }
    if(type!=6)
    {
        if(type!=8)
        {
            if(chack_book_id_in_issuelist(bookid,&issued_book)==1)
            {
                 MessageBoxA(NULL," At present you can not modify the data of this book because this book issued to a student."," Invalid Action",48);
                 Clear_buffer();
                 Bk_color(28,15);
                 field_of_mainmenu(60,20);
                 Bk_color(252,0);
                 goto reinput_bookid;
            }
        }
    }
    strcpy(modify_data.book_name,gbookdata.book_name);
    strcpy(modify_data.categorie,gbookdata.categorie);
    strcpy(modify_data.writer,gbookdata.writer);
    modify_data.id=gbookdata.id;
    modify_data.book_price=gbookdata.book_price;
    modify_data.extra_charge=gbookdata.extra_charge;
    modify_data.qty=gbookdata.qty;
    modify_data.rack_no=gbookdata.rack_no;
    modify_data.rent_price=gbookdata.rent_price;
    if(type==1)
    {
        reinput_bookname:
        re=input_Number_char_undermainmenu(modify_data.book_name,46,61,23);
        if(re==202)
        {
            return 202;
        }
        if(chack_book(modify_data.book_name)==1)
        {
            if(gbookdata.id==modify_data.id)
                MessageBoxA(NULL," You can not input old name of this book, please enter new name."," Invalid Input",48);
            else
                MessageBoxA(NULL," Book name already exist. Please enter other name."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,23);
            Bk_color(252,0);
            goto reinput_bookname;
        }
        encryption(modify_data.book_name);
    }
    else if(type==2)
    {
        reinput_category:
        re=input_Number_char_undermainmenu(modify_data.categorie,46,61,23);
        if(re==202)
        {
            return 202;
        }
        if(chack_categorie(modify_data.categorie)!=1)
        {
            MessageBoxA(NULL," Incorrect category or category id \n Please input valid category or id"," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,23);
            Bk_color(252,0);
            goto reinput_category;
        }
        encryption(modify_data.categorie);
    }
    else if(type==3)
    {
        re=input_string_undermainmenu(modify_data.writer,46,61,23);
        if(re==202)
        {
            return 202;
        }
        encryption(modify_data.writer);
    }
    else if(type==4)
    {
        re=input_numbers_undermainmenu(&modify_data.rent_price,9,61,23);
        if(re==202)
        {
            return 202;
        }
    }
    else if(type==5)
    {
        re=input_numbers_undermainmenu(&modify_data.extra_charge,9,61,23);
        if(re==202)
        {
            return 202;
        }
    }
    else if(type==6)
    {
        reinput_book_qty:
        msgbox[0]='\0';
        issued_book=0;
        re=input_numbers_undermainmenu(&modify_data.qty,9,61,23);
        if(re==202)
        {
            return 202;
        }
        if(chack_book_id_in_issuelist(bookid,&issued_book)==1)
        {
            if(modify_data.qty<issued_book)
            {
                convert_number_to_string(issued_book,issuedbooks);
                strcat(msgbox,"You can not enter book quantity lass then ");
                strcat(msgbox,issuedbooks);
                strcat(msgbox,",\n because ");
                strcat(msgbox,issuedbooks);
                strcat(msgbox," books have been issued to the students.");
                MessageBoxA(NULL,msgbox,"Invalid action",48);
                Clear_buffer();
                Bk_color(28,15);
                field_of_mainmenu(60,23);
                Bk_color(252,0);
                goto reinput_book_qty;
            }
        }
    }
    else if(type==7)
    {
        re=input_numbers_undermainmenu(&modify_data.book_price,9,61,23);
        if(re==202)
        {
            return 202;
        }
    }
    else if(type==8)
    {
        re=input_numbers_undermainmenu(&modify_data.rack_no,9,61,23);
        if(re==202)
        {
            return 202;
        }
    }
    Hide_cursor();
    fp=fopen(guser.bookpath,"rb");
    fp1=fopen(tempfile,"wb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not modify the book data."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gbookdata,sizeof(struct books),1,fp)>0)
    {
        if(bookid!=gbookdata.id)
        {
            fwrite(&gbookdata,sizeof(struct books),1,fp1);
        }
        else
        {
            fwrite(&modify_data,sizeof(struct books),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen(guser.bookpath,"wb");
    fp1=fopen(tempfile,"rb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not modify the book data."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gbookdata,sizeof(struct books),1,fp1)>0)
    {
        fwrite(&gbookdata,sizeof(struct books),1,fp);
    }
    fclose(fp);
    fclose(fp1);
    remove(tempfile);
    re=MessageBoxA(NULL," Book data successfully modified, you want to modify one more book."," Book Data Modified",68);
    Clear_buffer();
    if(re==Yes)
    {
        goto modify_more_book;
    }
    return 1;
}
void test()
{
    FILE *fp;
    int x,y,flag=0,flag2=0,flag3=0;
    char ch;
    struct user_accounts viewguestac;
    Hide_cursor();
    system("COLOR 7C");
    adjustWindowSize(0,0,112,42);
    buffer_size(308,42);
    Bk_color(28,1);
    back_freame(0,307,0,2);
    Bk_color(28,15);
    rec_MSGinM("STUDENT NAME",0,46,1);
    rec_MSGinM("BOOK NAME",48,95,1);
    rec_MSGinM("INVO. NO.",97,108,1);
    rec_MSGinM("STD. ID",110,121,1);
    rec_MSGinM("STD CLASS",123,134,1);
    rec_MSGinM("ROLL NO.",136,147,1);
    rec_MSGinM("BOOK ID",149,160,1);
    rec_MSGinM("BOOK CATEGORY",160,212,1);
    rec_MSGinM("ISSUE DATE",210,227,1);
    rec_MSGinM("SUBMIT DATE",225,241,1);
    rec_MSGinM("DATE OF SUB.",241,255,1);
    rec_MSGinM("RENT CHARGE",253,269,1);
    rec_MSGinM("EXTRA CHARGE",268,282,1);
    rec_MSGinM("TOTAL AMT",280,294,1);
    rec_MSGinM("MOBILE",291,310,1);
    line_V(0,2,48,'n','n',0);
    line_V(0,2,97,'n','n',0);
    line_V(0,2,110,'n','n',0);
    line_V(0,2,123,'n','n',0);
    line_V(0,2,136,'n','n',0);
    line_V(0,2,149,'n','n',0);
    line_V(0,2,162,'n','n',0);
    line_V(0,2,212,'n','n',0);
    line_V(0,2,227,'n','n',0);
    line_V(0,2,241,'n','n',0);
    line_V(0,2,255,'n','n',0);
    line_V(0,2,269,'n','n',0);
    line_V(0,2,282,'n','n',0);
    line_V(0,2,295,'n','n',0);
    Bk_color(117,1);
    line_V(3,41,48,'n','n',0);
    line_V(3,41,97,'n','n',0);
    line_V(3,41,110,'n','n',0);
    line_V(3,41,123,'n','n',0);
    line_V(3,41,136,'n','n',0);
    line_V(3,41,149,'n','n',0);
    line_V(3,41,162,'n','n',0);
    line_V(3,41,212,'n','n',0);
    line_V(3,41,227,'n','n',0);
    line_V(3,41,241,'n','n',0);
    line_V(3,41,255,'n','n',0);
    line_V(3,41,269,'n','n',0);
    line_V(3,41,282,'n','n',0);
    line_V(3,41,295,'n','n',0);
    gotoxy(1,4);
    printf("HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
    gotoxy(50,4);
    printf("HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
    gotoxy(99,4);
    printf("HHHHHHHHHH");
    gotoxy(112,4);
    printf("HHHHHHHHHH");
    gotoxy(125,4);
    printf("HHHHHHHHHH");
    gotoxy(138,4);
    printf("HHHHHHHHHH");
    gotoxy(151,4);
    printf("01/01/2018");
    gotoxy(164,4);
    printf("HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
    gotoxy(214,4);
    printf("01/01/2018");
    gotoxy(229,4);
    printf("01/01/2018");
    gotoxy(243,4);
    printf("HHHHHHHHHH");
    gotoxy(257,4);
    printf("HHHHHHHHHH");
    gotoxy(271,4);
    printf("HHHHHHHHHH");
    gotoxy(284,4);
    printf("HHHHHHHHHH");
    gotoxy(297,4);
    printf("9695806109");
}
int view_all_issued_book()
{
    FILE *fp;
    int x,y,flag=0,flag2=0,flag3=0;
    char ch;
    Hide_cursor();
    system("COLOR 7C");
    adjustWindowSize(0,0,112,42);
    buffer_size(163,42);
    Bk_color(28,1);
    back_freame(0,162,0,2);
    //column_strip_of_view_book(0,1);
    Bk_color(28,15);
    rec_MSGinM("STUDENT NAME",0,46,1);
    rec_MSGinM("BOOK NAME",48,95,1);
    rec_MSGinM("STD. ID",97,108,1);
    rec_MSGinM("BOOK ID",110,121,1);
    rec_MSGinM("IUUSE DT.",123,134,1);
    rec_MSGinM("SUBMIT DT.",136,147,1);
    rec_MSGinM("MOBILE",149,160,1);
    line_V(0,2,48,'n','n',0);
    line_V(0,2,97,'n','n',0);
    line_V(0,2,110,'n','n',0);
    line_V(0,2,123,'n','n',0);
    line_V(0,2,136,'n','n',0);
    line_V(0,2,149,'n','n',0);
    Bk_color(117,1);
    line_V(3,41,48,'n','n',0);
    line_V(3,41,97,'n','n',0);
    line_V(3,41,110,'n','n',0);
    line_V(3,41,123,'n','n',0);
    line_V(3,41,136,'n','n',0);
    line_V(3,41,149,'n','n',0);
    fp=fopen(guser.issuepath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        MessageBoxA(NULL," There is no issue books in issue list."," List Empty",64);
        Clear_buffer();
        return 404;
    }
    y=4;
    flag3=0;
    Bk_color(117,1);
    gotoxy(48,3);
    printf("%c",179);
    gotoxy(97,3);
    printf("%c",179);
    gotoxy(110,3);
    printf("%c",179);
    gotoxy(123,3);
    printf("%c",179);
    gotoxy(136,3);
    printf("%c",179);
    gotoxy(149,3);
    printf("%c",179);
    while(fread(&gissuedata,sizeof(struct issue_books),1,fp)>0)
    {
        if((y+1)>41)
        {
            if(flag3==0)
            {
                adjustWindowSize(0,0,111,42);
                flag3=1;
            }
            buffer_size(163,y+2);
        }
        Bk_color(117,1);
        gotoxy(48,y);
        printf("%c",179);
        gotoxy(97,y);
        printf("%c",179);
        gotoxy(110,y);
        printf("%c",179);
        gotoxy(123,y);
        printf("%c",179);
        gotoxy(136,y);
        printf("%c",179);
        gotoxy(149,y);
        printf("%c",179);
        gotoxy(48,y+1);
        printf("%c",179);
        gotoxy(97,y+1);
        printf("%c",179);
        gotoxy(110,y+1);
        printf("%c",179);
        gotoxy(123,y+1);
        printf("%c",179);
        gotoxy(136,y+1);
        printf("%c",179);
        gotoxy(149,y+1);
        printf("%c",179);
        if(flag==0)
        {
            Bk_color(117,1);
            flag=1;
        }
        else
        {
            Bk_color(117,15);
            flag=0;
        }
        gotoxy(1,y);
        printf("%s",gissuedata.std_name);
        gotoxy(50,y);
        printf("%s",gissuedata.book_name);
        gotoxy(99,y);
        printf("%s",gissuedata.std_id);
        gotoxy(112,y);
        printf("%d",gissuedata.book_id);
        gotoxy(125,y);
        printf("%02d/%02d/%04d",gissuedata.issue_day,gissuedata.issue_month,gissuedata.issue_year);
        gotoxy(138,y);
        printf("%02d/%02d/%04d",gissuedata.submit_day,gissuedata.submit_month,gissuedata.submit_year);
        gotoxy(151,y);
        printf("%s",gissuedata.std_mobile);
        y=y+2;
        flag2=1;
    }
    fclose(fp);
    if(flag2==0)
    {
        MessageBoxA(NULL," There is no issue books in issue list."," List Empty",64);
        Clear_buffer();
        return 0;
    }
    x=0;
    Bk_color(28,15);
    rescroll:
        gotoxy(x,y);
        ch=getch();
        if(ch==-32)
        {
            ch=getch();
            if(ch==left || ch==right)
            {
                switch(ch)
                {
                case 75:
                    if(flag3==1)
                    {
                        x=x-111;
                        flag3=0;
                    }
                    if(x>0 && x<=163)
                    {
                        x--;
                    }
                    goto rescroll;
                case right:
                    if(flag3==0)
                    {
                        x=x+111;
                        flag3=1;
                    }
                    if(x>=0 && x<163)
                    {
                        x++;
                    }
                    goto rescroll;
                }
            }
            else
            {
                goto rescroll;
            }
        }
        else if(ch==13)
        {

        }
        else
        {
            goto rescroll;
        }
}
int view_all_student()
{
    FILE *fp;
    int x,y,flag=0,flag2=0,flag3=0;
    char ch;
    //struct user_accounts viewguestac;
    Hide_cursor();
    system("COLOR 7C");
    adjustWindowSize(0,0,112,42);
    buffer_size(170,42);
    Bk_color(28,1);
    back_freame(0,169,0,2);
    //column_strip_of_view_book(0,1);
    Bk_color(28,15);
    rec_MSGinM("STUDENT NAME",0,46,1);
    rec_MSGinM("FATHER NAME",48,95,1);
    rec_MSGinM("STD. ID",97,108,1);
    rec_MSGinM("CLASS",110,121,1);
    rec_MSGinM("ROLL NO",123,134,1);
    rec_MSGinM("MOBILE",136,147,1);
    rec_MSGinM("JOIN DATE",149,159,1);
    rec_MSGinM("YEAR",162,168,1);
    line_V(0,2,48,'n','n',0);
    line_V(0,2,97,'n','n',0);
    line_V(0,2,110,'n','n',0);
    line_V(0,2,123,'n','n',0);
    line_V(0,2,136,'n','n',0);
    line_V(0,2,149,'n','n',0);
    line_V(0,2,162,'n','n',0);
    Bk_color(117,1);
    line_V(3,41,48,'n','n',0);
    line_V(3,41,97,'n','n',0);
    line_V(3,41,110,'n','n',0);
    line_V(3,41,123,'n','n',0);
    line_V(3,41,136,'n','n',0);
    line_V(3,41,149,'n','n',0);
    line_V(3,41,162,'n','n',0);
    fp=fopen(guser.stdpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        MessageBoxA(NULL," There is no Student in library."," List Empty",64);
        Clear_buffer();
        return 404;
    }
    y=4;
    flag3=0;
    Bk_color(117,1);
    gotoxy(48,3);
    printf("%c",179);
    gotoxy(97,3);
    printf("%c",179);
    gotoxy(110,3);
    printf("%c",179);
    gotoxy(123,3);
    printf("%c",179);
    gotoxy(136,3);
    printf("%c",179);
    gotoxy(149,3);
    printf("%c",179);
    gotoxy(162,3);
    printf("%c",179);
    while(fread(&gstudent,sizeof(struct students),1,fp)>0)
    {
        if((y+1)>41)
        {
            if(flag3==0)
            {
                adjustWindowSize(0,0,111,42);
                flag3=1;
            }
            buffer_size(170,y+2);
        }
        Bk_color(117,1);
        gotoxy(48,y);
        printf("%c",179);
        gotoxy(97,y);
        printf("%c",179);
        gotoxy(110,y);
        printf("%c",179);
        gotoxy(123,y);
        printf("%c",179);
        gotoxy(136,y);
        printf("%c",179);
        gotoxy(149,y);
        printf("%c",179);
        gotoxy(162,y);
        printf("%c",179);
        gotoxy(48,y+1);
        printf("%c",179);
        gotoxy(97,y+1);
        printf("%c",179);
        gotoxy(110,y+1);
        printf("%c",179);
        gotoxy(123,y+1);
        printf("%c",179);
        gotoxy(136,y+1);
        printf("%c",179);
        gotoxy(149,y+1);
        printf("%c",179);
        gotoxy(162,y+1);
        printf("%c",179);
        if(flag==0)
        {
            Bk_color(117,1);
            flag=1;
        }
        else
        {
            Bk_color(117,15);
            flag=0;
        }
        gotoxy(1,y);
        printf("%s",gstudent.name);
        gotoxy(50,y);
        printf("%s",gstudent.father_name);
        gotoxy(99,y);
        printf("%s",gstudent.id);
        gotoxy(112,y);
        printf("%s",gstudent.std_class);
        gotoxy(125,y);
        printf("%s",gstudent.roll_no);
        gotoxy(138,y);
        printf("%s",gstudent.mobile);
        gotoxy(151,y);
        printf("%02d/%02d/%04d",gstudent.joine_day,gstudent.joine_month,gstudent.joine_year);
        gotoxy(164,y);
        printf("%s",gstudent.year);
        y=y+2;
        flag2=1;
    }
    fclose(fp);
    if(flag2==0)
    {
        MessageBoxA(NULL," There is no Student in library."," List Empty",64);
        Clear_buffer();
        return 0;
    }
    x=0;
    Bk_color(28,15);
    rescroll:
        gotoxy(x,y);
        ch=getch();
        if(ch==-32)
        {
            ch=getch();
            if(ch==left || ch==right)
            {
                switch(ch)
                {
                case 75:
                    if(flag3==1)
                    {
                        x=x-111;
                        flag3=0;
                    }
                    if(x>0 && x<=221)
                    {
                        x--;
                    }
                    goto rescroll;
                case right:
                    if(flag3==0)
                    {
                        x=x+111;
                        flag3=1;
                    }
                    if(x>=0 && x<221)
                    {
                        x++;
                    }
                    goto rescroll;
                }
            }
            else
            {
                goto rescroll;
            }
        }
        else if(ch==13)
        {

        }
        else
        {
            goto rescroll;
        }
}
int view_all_books()
{
    FILE *fp;
    int x,y,flag=0,flag2=0,flag3=0;
    char ch;
    struct user_accounts viewguestac;
    Hide_cursor();
    system("COLOR 7C");
    adjustWindowSize(0,0,112,42);
    buffer_size(221,42);
    Bk_color(28,1);
    column_strip_of_view_book(0,1);
    Bk_color(28,15);
    rec_MSGinM("BOOK NAME",0,46,1);
    rec_MSGinM("WRITER NAME",48,95,1);
    rec_MSGinM("CATEGORY",97,143,1);
    rec_MSGinM("BOOK ID",145,156,1);
    rec_MSGinM("RACK NO",157,169,1);
    rec_MSGinM("RENT RT.",171,182,1);
    rec_MSGinM("EX. CH.",183,195,1);
    rec_MSGinM("BOOK PR.",197,208,1);
    rec_MSGinM("QTY",206,221,1);
    line_V(0,2,48,'n','n',0);
    line_V(0,2,97,'n','n',0);
    line_V(0,2,145,'n','n',0);
    line_V(0,2,158,'n','n',0);
    line_V(0,2,171,'n','n',0);
    line_V(0,2,184,'n','n',0);
    line_V(0,2,197,'n','n',0);
    line_V(0,2,209,'n','n',0);
    Bk_color(117,1);
    line_V(3,41,48,'n','n',0);
    line_V(3,41,97,'n','n',0);
    line_V(3,41,145,'n','n',0);
    line_V(3,41,158,'n','n',0);
    line_V(3,41,171,'n','n',0);
    line_V(3,41,184,'n','n',0);
    line_V(3,41,197,'n','n',0);
    line_V(3,41,209,'n','n',0);
    fp=fopen(guser.bookpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        MessageBoxA(NULL," There is no book in library."," List Empty",64);
        Clear_buffer();
        return 404;
    }
    y=4;
    flag3=0;
    Bk_color(117,1);
    gotoxy(48,3);
    printf("%c",179);
    gotoxy(97,3);
    printf("%c",179);
    gotoxy(145,3);
    printf("%c",179);
    gotoxy(158,3);
    printf("%c",179);
    gotoxy(171,3);
    printf("%c",179);
    gotoxy(184,3);
    printf("%c",179);
    gotoxy(197,3);
    printf("%c",179);
    gotoxy(209,3);
    printf("%c",179);
    while(fread(&gbookdata,sizeof(struct books),1,fp)>0)
    {
        decryption(gbookdata.book_name);
        decryption(gbookdata.writer);
        decryption(gbookdata.categorie);
        if((y+1)>41)
        {
            if(flag3==0)
            {
                adjustWindowSize(0,0,111,42);
                flag3=1;
            }
            buffer_size(221,y+2);
        }
        Bk_color(117,1);
        gotoxy(48,y);
        printf("%c",179);
        gotoxy(97,y);
        printf("%c",179);
        gotoxy(145,y);
        printf("%c",179);
        gotoxy(158,y);
        printf("%c",179);
        gotoxy(171,y);
        printf("%c",179);
        gotoxy(184,y);
        printf("%c",179);
        gotoxy(197,y);
        printf("%c",179);
        gotoxy(209,y);
        printf("%c",179);
        gotoxy(48,y+1);
        printf("%c",179);
        gotoxy(97,y+1);
        printf("%c",179);
        gotoxy(145,y+1);
        printf("%c",179);
        gotoxy(158,y+1);
        printf("%c",179);
        gotoxy(171,y+1);
        printf("%c",179);
        gotoxy(184,y+1);
        printf("%c",179);
        gotoxy(197,y+1);
        printf("%c",179);
        gotoxy(209,y+1);
        printf("%c",179);
        if(flag==0)
        {
            Bk_color(117,1);
            flag=1;
        }
        else
        {
            Bk_color(117,15);
            flag=0;
        }
        gotoxy(1,y);
        printf("%s",gbookdata.book_name);
        gotoxy(50,y);
        printf("%s",gbookdata.writer);
        gotoxy(99,y);
        if(gbookdata.categorie[0]>='0' && gbookdata.categorie[0]<='9')
        {
            chack_categorie(gbookdata.categorie);
            printf("%s",gcategorie.categorie);
        }
        else
        {
            printf("%s",gbookdata.categorie);
        }
        gotoxy(147,y);
        printf("%d",gbookdata.id);
        gotoxy(160,y);
        printf("%d",gbookdata.rack_no);
        gotoxy(173,y);
        printf("%d",gbookdata.rent_price);
        gotoxy(186,y);
        printf("%d",gbookdata.extra_charge);
        gotoxy(199,y);
        printf("%d",gbookdata.book_price);
        gotoxy(211,y);
        printf("%d",gbookdata.qty);
        y=y+2;
        flag2=1;
    }
    fclose(fp);
    if(flag2==0)
    {
        MessageBoxA(NULL," There is no book in library."," List Empty",64);
        Clear_buffer();
        return 0;
    }
    x=0;
    Bk_color(28,15);
    rescroll:
        gotoxy(x,y);
        ch=getch();
        if(ch==-32)
        {
            ch=getch();
            if(ch==left || ch==right)
            {
                switch(ch)
                {
                case 75:
                    if(flag3==1)
                    {
                        x=x-111;
                        flag3=0;
                    }
                    if(x>0 && x<=221)
                    {
                        x--;
                    }
                    goto rescroll;
                case right:
                    if(flag3==0)
                    {
                        x=x+111;
                        flag3=1;
                    }
                    if(x>=0 && x<221)
                    {
                        x++;
                    }
                    goto rescroll;
                }
            }
            else
            {
                goto rescroll;
            }
        }
        else if(ch==13)
        {

        }
        else
        {
            goto rescroll;
        }
}
int add_new_book()
{
    int re;
    FILE *fp;
    struct books newbook;
    Bk_color(180,11);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("ADD NEW BOOK");
    add_more_book:
    Clear_buffer();
    Bk_color(28,15);
    gotoxy(42,8);
    printf("BOOK NAME");
    gotoxy(42,11);
    printf("WRITER NAME");
    gotoxy(42,14);
    printf("CATEGORIE");
    gotoxy(42,17);
    printf("BOOK ID");
    gotoxy(42,20);
    printf("RACK NUMBER");
    gotoxy(42,23);
    printf("RENT RATE");
    gotoxy(42,26);
    printf("EXTRA CHARGE");
    gotoxy(42,29);
    printf("BOOK PRICE");
    gotoxy(42,32);
    printf("BOOK QUANTITY");
    field_of_mainmenu(60,8);
    field_of_mainmenu(60,11);
    field_of_mainmenu(60,14);
    field_of_mainmenu(60,17);
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    field_of_mainmenu(60,26);
    field_of_mainmenu(60,29);
    field_of_mainmenu(60,32);
    Show_cursor(8);
    reinput_bookname:
    re=input_Number_char_undermainmenu(newbook.book_name,46,61,8);
    if(re==202)
    {
        return 202;
    }
    if(chack_book(newbook.book_name)==1)
    {
        MessageBoxA(NULL," Book name Already exist."," Warning",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,8);
        Bk_color(252,0);
        goto reinput_bookname;
    }
    re=input_string_undermainmenu(newbook.writer,46,61,11);
    if(re==202)
    {
        return 202;
    }
    reinput_categorie:
    re=input_Number_char_undermainmenu(newbook.categorie,46,61,14);
    if(re==202)
    {
        return 202;
    }
    if(chack_categorie(newbook.categorie)!=1)
    {
        MessageBoxA(NULL," Incorrect book Category or Category ID, Please reinput."," Incorrect Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,14);
        Bk_color(252,0);
        goto reinput_categorie;
    }
    if(newbook.categorie[0]>='0' && newbook.categorie[0]<='9')
    {
        strcpy(newbook.categorie,gcategorie.categorie);
        Bk_color(28,15);
        field_of_mainmenu(60,14);
        Bk_color(252,0);
        gotoxy(61,14);
        printf("%s",newbook.categorie);
    }
    reinput_bookid:
    re=input_numbers_undermainmenu(&newbook.id,9,61,17);
    if(re==202)
    {
        return 202;
    }
    if(chack_book_id(newbook.id)==1)
    {
        MessageBoxA(NULL," Book Id already exist.","Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,17);
        Bk_color(252,0);
        goto reinput_bookid;
    }
    re=input_numbers_undermainmenu(&newbook.rack_no,9,61,20);
    if(re==202)
    {
        return 202;
    }
    re=input_numbers_undermainmenu(&newbook.rent_price,9,61,23);
    if(re==202)
    {
        return 202;
    }
    re=input_numbers_undermainmenu(&newbook.extra_charge,9,61,26);
    if(re==202)
    {
        return 202;
    }
    re=input_numbers_undermainmenu(&newbook.book_price,9,61,29);
    if(re==202)
    {
        return 202;
    }
    re=input_numbers_undermainmenu(&newbook.qty,9,61,32);
    if(re==202)
    {
        return 202;
    }
    encryption(newbook.book_name);
    encryption(newbook.categorie);
    encryption(newbook.writer);
    fp=fopen(guser.bookpath,"ab");
    fwrite(&newbook,sizeof(struct books),1,fp);
    fclose(fp);
    re=MessageBoxA(NULL," Book successfully added, you want to add one more new Book"," Book Added",68);
    if(re==Yes)
    {
        goto add_more_book;
    }
    return 1;
}
int search_book()
{
    int re,bookid,flag=0;
    FILE *fp;
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("DELETE BOOK");
    Bk_color(28,15);
    gotoxy(42,23);
    printf("BOOK ID");
    delete_more_book:
    Bk_color(28,15);
    field_of_mainmenu(60,23);
    Show_cursor(7);
    reinput_bookid:
    re=input_numbers_undermainmenu(&bookid,9,61,23);
    if(re==202)
    {
        return 202;
    }
    if(chack_book_id(bookid)!=1)
    {
        re=MessageBoxA(NULL," Incrroct Book ID, plese enter valid book id."," Invalid Input",53);
        Clear_buffer();
        if(re==No)
        {
            return 0;
        }
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(252,0);
        goto reinput_bookid;
    }
    else
    {
        decryption(gbookdata.book_name);
        decryption(gbookdata.writer);
        decryption(gbookdata.categorie);
        if(gbookdata.categorie[0]>='0' && gbookdata.categorie[0]<='9')
        {
            chack_categorie(gbookdata.categorie);
            decryption(gcategorie.categorie);
            flag=1;
        }
    }
    Hide_cursor();
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("BOOK RECORD");
    Clear_buffer();
    Bk_color(28,15);
    gotoxy(42,8);
    printf("BOOK NAME");
    gotoxy(42,11);
    printf("WRITER NAME");
    gotoxy(42,14);
    printf("CATEGORIE");
    gotoxy(42,17);
    printf("BOOK ID");
    gotoxy(42,20);
    printf("RACK NUMBER");
    gotoxy(42,23);
    printf("RENT RATE");
    gotoxy(42,26);
    printf("EXTRA CHARGE");
    gotoxy(42,29);
    printf("BOOK PRICE");
    gotoxy(42,32);
    printf("BOOK QUANTITY");
    field_of_mainmenu(60,8);
    field_of_mainmenu(60,11);
    field_of_mainmenu(60,14);
    field_of_mainmenu(60,17);
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    field_of_mainmenu(60,26);
    field_of_mainmenu(60,29);
    field_of_mainmenu(60,32);
    Bk_color(252,0);
    gotoxy(61,8);
    printf("%s",gbookdata.book_name);
    gotoxy(61,11);
    printf("%s",gbookdata.writer);
    gotoxy(61,14);
    printf("%s",gbookdata.categorie);
    gotoxy(61,17);
    printf("%d",gbookdata.id);
    gotoxy(61,20);
    printf("%d",gbookdata.rack_no);
    gotoxy(61,23);
    printf("%d Rs.",gbookdata.rent_price);
    gotoxy(61,26);
    printf("%d Rs.",gbookdata.extra_charge);
    gotoxy(61,29);
    printf("%d Rs.",gbookdata.book_price);
    gotoxy(61,32);
    printf("%d",gbookdata.qty);
    Bk_color(28,15);
    print_date_time(74,95,41,39,41);
}
int add_new_category()
{
    int re;
    FILE *fp;
    struct categorie newcatg;
    Bk_color(180,11);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("ADD NEW CATEGORY");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("CATEGORY ID");
    gotoxy(42,23);
    printf("CATEGORY");
    Show_cursor(7);
    add_more_category:
        Bk_color(28,15);
        field_of_mainmenu(60,20);
        field_of_mainmenu(60,23);
    reinput_category_id:
        re=input_charnumbers_undermainmenu(newcatg.categorie_id,46,5,61,20);
        if(re==202)
        {
            return 202;
        }
        if(chack_categorie(newcatg.categorie_id)==1)
        {
            MessageBoxA(NULL," Category ID already exist."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            Bk_color(252,0);
            goto reinput_category_id;
        }
    reinput_category:
        re=input_string_undermainmenu(newcatg.categorie,46,61,23);
        if(re==202)
        {
            return 202;
        }
        if(chack_categorie(newcatg.categorie)==1)
        {
            MessageBoxA(NULL," Category already exist."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,23);
            Bk_color(252,0);
            goto reinput_category;
        }
        encryption(newcatg.categorie);
        encryption(newcatg.categorie_id);
        fp=fopen(guser.categoriepath,"ab");
        if(fp==NULL)
        {
            fclose(fp);
            re=MessageBoxA(NULL,"An error occurred, Category can not be added."," Error",21);
            Clear_buffer();
            if(re==Retry)
            {
                goto add_more_category;
            }
            else
            {
                return 404;
            }
        }
        fwrite(&newcatg,sizeof(struct categorie),1,fp);
        fclose(fp);
        re=MessageBoxA(NULL," Category successfully added, you want to add one more new Category"," Category Added",68);
        Clear_buffer();
        if(re==Yes)
        {
            goto add_more_category;
        }
        return 1;
}
int search_category()
{
    int re;
    char category[60];
    FILE *fp,*fp1;
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("SEARCH CATEGORY");
    Bk_color(28,15);
    gotoxy(42,23);
    printf("CATEGORY OR ID");
    delete_more_catrgory:
    Bk_color(28,15);
    field_of_mainmenu(60,23);
    reinput_category:
    Show_cursor(7);
    re=input_Number_char_undermainmenu(category,46,61,23);
    if(re==202)
    {
        return 202;
    }
    if(chack_categorie(category)!=1)
    {
        MessageBoxA(NULL," Incorrect category or category id please enter valid category or id."," Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(28,0);
        goto reinput_category;
    }
    Hide_cursor();
    Bk_color(180,1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("CATEGORY RECORD");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("CATEGORY ID");
    gotoxy(42,23);
    printf("CATEGORY");
    Bk_color(28,15);
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    Bk_color(252,0);
    gotoxy(61,20);
    printf("%s",gcategorie.categorie_id);
    gotoxy(61,23);
    printf("%s",gcategorie.categorie);
    Bk_color(28,15);
    print_date_time(74,95,41,39,41);
}
int chack_categorie(char *categ)
{
    FILE *fp;
    fp=fopen(guser.categoriepath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&gcategorie,sizeof(struct categorie),1,fp)>0)
    {
        decryption(gcategorie.categorie);
        decryption(gcategorie.categorie_id);
        if(match_two_string(categ,gcategorie.categorie_id)==1)
        {
            fclose(fp);
            return 1;
        }
        else if(match_two_string(categ,gcategorie.categorie)==1)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int view_all_category()
{
    FILE *fp;
    int x,y,flag=0,flag2=0,flag3=0;
    char ch;
    struct user_accounts viewguestac;
    Hide_cursor();
    system("cls");
    system("COLOR 7C");
    adjustWindowSize(0,0,112,43);
    buffer_size(112,43);
    Bk_color(28,1);
    back_freame(0,111,0,2);
    Bk_color(28,15);
    rec_MSGinM("CATEGORY ID",0,56,1);;
    rec_MSGinM("CATEGORY",56,111,1);
    line_V(0,2,56,'n','n',0);
    Bk_color(128,1);
    fp=fopen(guser.categoriepath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        MessageBoxA(NULL," An Error occurred, You Cannot View Accounts","Error",16);
        Clear_buffer();
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        return 404;
    }
    Bk_color(117,1);
    gotoxy(56,3);
    printf("%c",179);
    y=4;
    while(fread(&gcategorie,sizeof(struct categorie),1,fp)>0)
    {
       decryption(gcategorie.categorie);
       decryption(gcategorie.categorie_id);
       if((y+1)>41)
       {
           buffer_size(112,y+2);
       }
       Bk_color(117,1);
       gotoxy(56,y);
       printf("%c",179);
       gotoxy(56,y+1);
       printf("%c",179);
        if(flag==0)
        {
            Bk_color(117,1);
            flag=1;
        }
        else
        {
            Bk_color(117,15);
            flag=0;
        }
        gotoxy(1,y);
        printf("%s",gcategorie.categorie_id);
        gotoxy(58,y);
        printf("%s",gcategorie.categorie);
        y=y+2;
        flag2=1;
    }
    fclose(fp);
    if(flag2==0)
    {
        MessageBoxA(NULL," No Category, Please Add new Category"," Warning",32);
        Clear_buffer();
        return 0;
    }
    else
    {
        Clear_buffer();
        getch();
        return 1;
    }
}
int chack_book(char *bookname)
{
    FILE *fp;
    fp=fopen(guser.bookpath,"rb");
    if(fp==NULL)
    {
        return 0;
    }
    while(fread(&gbookdata,sizeof(struct books),1,fp)>0)
    {
        decryption(gbookdata.book_name);
        if(match_two_string(bookname,gbookdata.book_name)==1)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int chack_book_id(int id)
{
    FILE *fp;
    fp=fopen(guser.bookpath,"rb");
    if(fp==NULL)
    {
        return 0;
    }
    while(fread(&gbookdata,sizeof(struct books),1,fp)>0)
    {
        if(gbookdata.id==id)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int student_management()
{
    char ch;
    int x,x1,y,y1;
    Clear_buffer();
    restat_library_menu:
    Bk_color(180,7);
    main_menu_background();
    ind_back_freame(2,38,3,5,117,180,12);
    Bk_color(197,15);
    rec_MSGinM("STUDENT MANAGEMENT",2,38,4);
    notification();
    x=3;
    x1=38;
    y=6;
    reset:
        y1=y+2;
        Bk_color(117,1);
        if(x==3)
        {
            gotoxy(10,7);
            printf("Add New Student");
            gotoxy(10,9);
            printf("Remove Student");
            gotoxy(10,11);
            printf("Search Student");
            gotoxy(10,13);
            printf("Change Student name");
            gotoxy(10,15);
            printf("Change Father Name");
            gotoxy(10,17);
            printf("Change Mobile number");
            gotoxy(10,19);
            printf("Change Roll Number");
            gotoxy(10,21);
            printf("View All Students");
            gotoxy(10,23);
            printf("Export All Student in Excel");
            /*gotoxy(12,25);
            printf("View All Students");
            gotoxy(12,27);
            printf("Close Application");
            gotoxy(12,29);
            printf("Option 13");
            gotoxy(12,31);
            printf("Option 14");
            gotoxy(12,33);
            printf("Option 15");
            gotoxy(12,35);
            printf("Option 16");
            gotoxy(12,37);
            printf("Option 17");*/
            setcolor(14);
            menu_option(x,x1,y,y1);
            Bk_color(225,9);
            if(y+1==7 && x==3)
            {
                gotoxy(10,7);
                printf("Add New Student");
            }
            if(y+1==9 && x==3)
            {
                gotoxy(10,9);
                printf("Remove Student");
            }
            if(y+1==11 && x==3)
            {
                gotoxy(10,11);
                printf("Search Student");
            }
            if(y+1==13 && x==3)
            {
                gotoxy(10,13);
                printf("Change Student name");
            }
            if(y+1==15 && x==3)
            {
                gotoxy(10,15);
                printf("Change Father Name");
            }
            if(y+1==17 && x==3)
            {
                gotoxy(10,17);
                printf("Change Mobile number");
            }
            if(y+1==19 && x==3)
            {
                gotoxy(10,19);
                printf("Change Roll Number");
            }
            if(y+1==21 && x==3)
            {
                gotoxy(10,21);
                printf("View All Students");
            }
            if(y+1==23 && x==3)
            {
                gotoxy(10,23);
                printf("Export All Student in Excel");
            }
            /*if(y+1==25 && x==3)
            {
                gotoxy(12,25);
                printf("View All Students");
            }
            /*if(y+1==27 && x==3)
            {
                gotoxy(12,27);
                printf("Close Application");
            }
            if(y+1==29 && x==3)
            {
                gotoxy(12,29);
                //printf("Option 13");
            }
            if(y+1==31 && x==3)
            {
                gotoxy(12,31);
                //printf("Option 14");
            }
            if(y+1==33 && x==3)
            {
                gotoxy(12,33);
                //printf("Option 15");
            }
            if(y+1==35 && x==3)
            {
                gotoxy(12,35);
                //printf("Option 16");
            }
            if(y+1==37 && x==3)
            {
                gotoxy(12,37);
                //printf("Option 17");
            }*/
        }
        Bk_color(117,14);
        rechoise:
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        Bk_color(117,14);
        gotoxy(56,4);
        ch=getch();
        if(ch==27)
        {
            return 202;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>6 && y<=22)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y-2;
                        goto reset;
                    }
                    goto rechoise;
                case down:
                    if(y>=6 && y<22)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y+2;
                        goto reset;
                    }
                    goto rechoise;
                }
            }
            else
            {
                goto reset;
            }
        }
        else if(ch==13)
        {
            switch(y+1)
            {
            case 7:
                if(guser.add_new_students==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                add_new_student();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 9:
                if(guser.remove_students==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                remove_student();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 11:
                if(guser.search_students==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                search_student();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 13:
                if(guser.change_student_name==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                modify_student(1);
                Hide_cursor();
                notification();
                Clear_buffer();
                goto reset;
                break;
            case 15:
                if(guser.chnage_father_name==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                modify_student(2);
                Hide_cursor();
                notification();
                Clear_buffer();
                goto reset;
                break;
            case 17:
                if(guser.change_mobile_number==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                modify_student(3);
                Hide_cursor();
                notification();
                Clear_buffer();
                goto reset;
                break;
            case 19:
                if(guser.chnage_roll_number==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                modify_student(4);
                Hide_cursor();
                notification();
                Clear_buffer();
                goto reset;
                break;
            case 21:
                if(guser.view_all_students==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                system("cls");
                view_all_student();
                system("cls");
                system("COLOR bc");
                main_frame(180,guser.library_name);
                Bk_color(180,7);
                main_menu_background();
                ind_back_freame(2,38,3,5,117,180,12);
                Bk_color(197,15);
                rec_MSGinM("STUDENT MANAGEMENT",2,38,4);
                print_login_status();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 23:
                if(guser.Export_student_data==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                export_all_students_to_excel();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
            }
        }
        else
        {
            goto reset;
        }
}
int export_all_students_to_excel()
{
    int re;
    char temp[15];
    char newline[]="\n";
    char next_column[]=",";
    FILE *fp,*fp1;
    char filename[60];
    char file_path[250];
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("EXPORT STUDENT'S TO EXCEL SHEET");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("FILE NAME");
    Bk_color(28,15);
    field_of_mainmenu(60,20);
    mkdir(Exported_data);
    reinput_file_name:
        Show_cursor(7);
        strcpy(file_path,Exported_data);
        Bk_color(252,0);
        re=input_string_undermainmenu(filename,46,61,20);
        if(re==202)
        {
            return 202;
        }
        Hide_cursor();
        strcat(filename,".csv");
        strcat(file_path,"\\");
        strcat(file_path,filename);
        if(chack_file_name(file_path)==1)
        {
            MessageBoxA(NULL," File name already exist, Please Enter another name of the file."," Error",16);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            goto reinput_file_name;
        }
        fp=fopen(file_path,"w");
        fp1=fopen(guser.stdpath,"rb");
        if(fp==NULL || fp1==NULL)
        {
            MessageBoxA(NULL,"  An Error! Student list could not exported to excel sheet, please try again."," Error",16);
            Clear_buffer();
            return 0;
        }
        fputs("Student Id,Student Name,Father Name,Class,Roll Number,Year,Mobile Number,Joining Date\n",fp);
        while(fread(&gstudent,sizeof(struct students),1,fp1)>0)
        {
            fputs(gstudent.id,fp);
            fputs(next_column,fp);
            fputs(gstudent.name,fp);
            fputs(next_column,fp);
            fputs(gstudent.father_name,fp);
            fputs(next_column,fp);
            fputs(gstudent.std_class,fp);
            fputs(next_column,fp);
            fputs(gstudent.roll_no,fp);
            fputs(next_column,fp);
            fputs(gstudent.year,fp);
            fputs(next_column,fp);
            fputs(gstudent.mobile,fp);
            fputs(next_column,fp);
            store_date_in_string(temp,gstudent.joine_day,gstudent.joine_month,gstudent.joine_year);
            fputs(temp,fp);
            fputs(newline,fp);
        }
        fclose(fp);
        fclose(fp1);
        MessageBoxA(NULL," All Student's Successfully Exported.\nFind File on this Path : brightgoal->exported data"," Book's Exported",64);
        Clear_buffer();
        return 1;

}
int modify_student(int type)
{
    int re;
    char std_id[15];
    char message[456];
    FILE *fp,*fp1;
    struct students modify_data;
    Bk_color(180,11);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("MODIFY STUDENT DATA");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("STUDENT ID");
    gotoxy(42,23);
    if(type==1)
    {
        printf("STUDENT NAME");
    }
    else if(type==2)
    {
        printf("FATHER NAME");
    }
    else if(type==3)
    {
        printf("NEW MOBILE NO.");
    }
    else if(type==4)
    {
        printf("NEW ROLL NUMBER");
    }
    modify_more_student:
    Bk_color(28,15);
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    Show_cursor(7);
    reinput_std_id:
    re=input_charnumbers_undermainmenu(std_id,9,2,61,20);
    if(re==202)
    {
        return 202;
    }
    convert_string_to_int(&re,std_id);
    if(re<=0)
    {
        MessageBoxA(NULL," Invaid student id, Please enter valid id."," Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,20);
        Bk_color(252,0);
        goto reinput_std_id;
    }
    if(chack_student_id(std_id)!=1)
    {
        MessageBoxA(NULL,"Incorrect Student Id, Please enter valid student id"," Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(252,0);
        goto reinput_std_id;
    }
    if(chack_student_id_in_issuelist(std_id)==1)
    {
        MessageBoxA(NULL," At present you can not modify the data of this student because it has been issued a book."," Invalid Action",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,20);
        Bk_color(252,0);
        goto reinput_std_id;
    }
    strcpy(modify_data.id,gstudent.id);
    strcpy(modify_data.name,gstudent.name);
    strcpy(modify_data.father_name,gstudent.father_name);
    strcpy(modify_data.mobile,gstudent.mobile);
    strcpy(modify_data.roll_no,gstudent.roll_no);
    strcpy(modify_data.std_class,gstudent.std_class);
    strcpy(modify_data.year,gstudent.year);
    modify_data.joine_day=gstudent.joine_day;
    modify_data.joine_month=gstudent.joine_month;
    modify_data.joine_year=gstudent.joine_year;
    if(type==1)
    {
        re=input_string_undermainmenu(modify_data.name,46,61,23);
        if(re==202)
        {
            return 202;
        }
    }
    else if(type==2)
    {
        re=input_string_undermainmenu(modify_data.father_name,46,61,23);
        if(re==202)
        {
            return 202;
        }
    }
    else if(type==3)
    {
        reinput_mobile:
        re=input_mobile_undermainmenu(modify_data.mobile,10,61,23);
        if(re==202)
        {
            return 202;
        }
        if(gsetting.warnings==1)
        {
            if(chack_std_mobile(modify_data.mobile)==1)
            {
                if(match_two_string(modify_data.mobile,gstudent.mobile)!=1)
                {
                    strcpy(message," Mobile number Already exist.\n");
                    strcat(message,"\n Student id    : ");
                    strcat(message,gstudent.id);
                    strcat(message,"\n Student name  : ");
                    strcat(message,gstudent.name);
                    strcat(message,"\n Father name   : ");
                    strcat(message,gstudent.father_name);
                    strcat(message,"\n Class         : ");
                    strcat(message,gstudent.std_class);
                    strcat(message,"\n Roll number   : ");
                    strcat(message,gstudent.roll_no);
                    strcat(message,"\n Mobile Number : ");
                    strcat(message,gstudent.mobile);
                    strcat(message,"\n Year          : ");
                    strcat(message,gstudent.year);
                    re=MessageBoxA(NULL,message," Confirmation message",54);
                    Clear_buffer();
                    if(re==TryAgain)
                    {
                        Bk_color(28,15);
                        field_of_mainmenu(60,23);
                        Bk_color(252,0);
                        goto reinput_mobile;
                    }
                }
            }

        }
    }
    else if(type==4)
    {
        reinput_roll_number:
        re=input_num_and_char_undermainmenu(modify_data.roll_no,10,1,61,23);
        if(re==202)
        {
            return 202;
        }
        if(chack_roll_number_of_class(modify_data.roll_no,modify_data.std_class)==1)
        {
            if(match_two_string(std_id,gstudent.id)!=1)
            {
                strcpy(message," This role number already allocated to another student\n in the class.\n");
                strcat(message,"\n Student id    : ");
                strcat(message,gstudent.id);
                strcat(message,"\n Student name  : ");
                strcat(message,gstudent.name);
                strcat(message,"\n Father name   : ");
                strcat(message,gstudent.father_name);
                strcat(message,"\n Class         : ");
                strcat(message,gstudent.std_class);
                strcat(message,"\n Roll number   : ");
                strcat(message,gstudent.roll_no);
                strcat(message,"\n Mobile Number : ");
                strcat(message,gstudent.mobile);
                strcat(message,"\n Year          : ");
                strcat(message,gstudent.year);
                MessageBoxA(NULL,message," Invalid Input",48);
                Clear_buffer();
                Bk_color(28,15);
                field_of_mainmenu(60,23);
                Bk_color(252,0);
                goto reinput_roll_number;
            }
        }
    }
    Hide_cursor();
    fp=fopen(guser.stdpath,"rb");
    fp1=fopen(tempfile,"wb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not modify the Student data."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gstudent,sizeof(struct students),1,fp)>0)
    {
        if(match_two_string(std_id,gstudent.id)!=1)
        {
            fwrite(&gstudent,sizeof(struct students),1,fp1);
        }
        else
        {
            fwrite(&modify_data,sizeof(struct students),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen(guser.stdpath,"wb");
    fp1=fopen(tempfile,"rb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not modify the Student data."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gstudent,sizeof(struct students),1,fp1)>0)
    {
        fwrite(&gstudent,sizeof(struct students),1,fp);
    }
    fclose(fp);
    fclose(fp1);
    remove(tempfile);
    re=MessageBoxA(NULL," Student data successfully modified, you want to modify one more Student."," Student Data Modified",68);
    Clear_buffer();
    if(re==Yes)
    {
        goto modify_more_student;
    }
    return 1;
}
int search_student()
{
    int re;
    char student_id[15];
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("SEARCH STUDENT");
    Bk_color(28,15);
    gotoxy(42,23);
    printf("STUDENT ID");
    remove_more_students:
    Bk_color(28,15);
    field_of_mainmenu(60,23);
    Show_cursor(7);
    reinput_std_id:
    re=input_charnumbers_undermainmenu(student_id,9,2,61,23);
    if(re==202)
    {
        return 202;
    }
    if(chack_student_id(student_id)!=1)
    {
        MessageBoxA(NULL," Incorrect student ID please enter valid student id."," Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(28,0);
        goto reinput_std_id;
    }
    Hide_cursor();
    Bk_color(180,1);
    working_area_background();
    Bk_color(28,15);
    gotoxy(42,8);
    printf("STUDENT ID");
    gotoxy(42,11);
    printf("NAME");
    gotoxy(42,14);
    printf("FATHER NAME");
    gotoxy(42,17);
    printf("CLASS");
    gotoxy(42,20);
    printf("ROLL NUMBER");
    gotoxy(42,23);
    printf("YEAR");
    gotoxy(42,26);
    printf("MOBILE NUMBER");
    gotoxy(42,29);
    printf("JOINING DATE");
    Bk_color(28,15);
    Clear_buffer();
    field_of_mainmenu(60,8);
    field_of_mainmenu(60,11);
    field_of_mainmenu(60,14);
    field_of_mainmenu(60,17);
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    field_of_mainmenu(60,26);
    field_of_mainmenu(60,29);
    Bk_color(252,0);
    gotoxy(61,8);
    printf("%s",gstudent.id);
    gotoxy(61,11);
    printf("%s",gstudent.name);
    gotoxy(61,14);
    printf("%s",gstudent.father_name);
    gotoxy(61,17);
    printf("%s",gstudent.std_class);
    gotoxy(61,20);
    printf("%s",gstudent.roll_no);
    gotoxy(61,23);
    printf("%s",gstudent.year);
    gotoxy(61,26);
    printf("%s",gstudent.mobile);
    gotoxy(61,29);
    printf("%02d/%02d/%04d",gstudent.joine_day,gstudent.joine_month,gstudent.joine_year);
    Bk_color(28,15);
    print_date_time(74,95,41,39,41);
    Clear_buffer();
}
int add_new_student()
{
    int re,i;
    FILE *fp;
    char message[456];
    struct students newstudent;
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("ADD NEW STUDENT");
    Bk_color(28,15);
    gotoxy(42,8);
    printf("STUDENT ID");
    gotoxy(42,11);
    printf("NAME");
    gotoxy(42,14);
    printf("FATHER NAME");
    gotoxy(42,17);
    printf("CLASS");
    gotoxy(42,20);
    printf("ROLL NUMBER");
    gotoxy(42,23);
    printf("YEAR");
    gotoxy(42,26);
    printf("MOBILE NUMBER");
    gotoxy(42,29);
    printf("JOINING DATE");
    add_more_student:
        Bk_color(28,15);
        Clear_buffer();
        field_of_mainmenu(60,8);
        field_of_mainmenu(60,11);
        field_of_mainmenu(60,14);
        field_of_mainmenu(60,17);
        field_of_mainmenu(60,20);
        field_of_mainmenu(60,23);
        field_of_mainmenu(60,26);
        field_of_mainmenu(60,29);
        Show_cursor(7);
        reinput_std_id:
        re=input_charnumbers_undermainmenu(newstudent.id,9,2,61,8);
        if(re==202)
        {
            return 202;
        }
        convert_string_to_int(&re,newstudent.id);
        if(re<=0)
        {
            MessageBoxA(NULL," Invaid student id, Please enter valid id."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,8);
            Bk_color(252,0);
            goto reinput_std_id;
        }
        if(chack_student_id(newstudent.id)==1)
        {
            strcpy(message," Student id already exist. Please enter another id.\n");
            strcat(message,"\n Student id    : ");
            strcat(message,gstudent.id);
            strcat(message,"\n Student name  : ");
            strcat(message,gstudent.name);
            strcat(message,"\n Father name   : ");
            strcat(message,gstudent.father_name);
            strcat(message,"\n Class         : ");
            strcat(message,gstudent.std_class);
            strcat(message,"\n Roll number   : ");
            strcat(message,gstudent.roll_no);
            strcat(message,"\n Mobile Number : ");
            strcat(message,gstudent.mobile);
            strcat(message,"\n Year          : ");
            strcat(message,gstudent.year);
            MessageBoxA(NULL,message," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,8);
            Bk_color(252,0);
            goto reinput_std_id;
        }
        re=input_string_undermainmenu(newstudent.name,46,61,11);
        if(re==202)
        {
            return 202;
        }
        re=input_string_undermainmenu(newstudent.father_name,46,61,14);
        if(re==202)
        {
            return 202;
        }
        re=input_num_and_char_undermainmenu(newstudent.std_class,10,1,61,17);
        if(re==202)
        {
            return 202;
        }
        reinput_roll_number:
        re=input_num_and_char_undermainmenu(newstudent.roll_no,10,1,61,20);
        if(re==202)
        {
            return 202;
        }
        if(chack_roll_number_of_class(newstudent.roll_no,newstudent.std_class)==1)
        {
            strcpy(message," This role number already allocated to another student\n in the class.\n");
            strcat(message,"\n Student id    : ");
            strcat(message,gstudent.id);
            strcat(message,"\n Student name  : ");
            strcat(message,gstudent.name);
            strcat(message,"\n Father name   : ");
            strcat(message,gstudent.father_name);
            strcat(message,"\n Class         : ");
            strcat(message,gstudent.std_class);
            strcat(message,"\n Roll number   : ");
            strcat(message,gstudent.roll_no);
            strcat(message,"\n Mobile Number : ");
            strcat(message,gstudent.mobile);
            strcat(message,"\n Year          : ");
            strcat(message,gstudent.year);
            MessageBoxA(NULL,message," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            Bk_color(252,0);
            goto reinput_roll_number;
        }
        reinput_year:
        re=input_charnumbers_undermainmenu(newstudent.year,4,4,61,23);
        if(re==202)
        {
            return 202;
        }
        i=0;
        convert_string_to_int(&i,newstudent.year);
        if(i<2018 || i>9999)
        {
            MessageBoxA(NULL," Invalid year, please input valid year."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,23);
            Bk_color(252,0);
            goto reinput_year;
        }
        reinput_mobile:
        re=input_mobile_undermainmenu(newstudent.mobile,10,61,26);
        if(re==202)
        {
            return 202;
        }
        if(gsetting.warnings==1)
        {
            if(chack_std_mobile(newstudent.mobile)==1)
            {
                strcpy(message," Mobile number Already exist.\n");
                strcat(message,"\n Student id    : ");
                strcat(message,gstudent.id);
                strcat(message,"\n Student name  : ");
                strcat(message,gstudent.name);
                strcat(message,"\n Father name   : ");
                strcat(message,gstudent.father_name);
                strcat(message,"\n Class         : ");
                strcat(message,gstudent.std_class);
                strcat(message,"\n Roll number   : ");
                strcat(message,gstudent.roll_no);
                strcat(message,"\n Mobile Number : ");
                strcat(message,gstudent.mobile);
                strcat(message,"\n Year          : ");
                strcat(message,gstudent.year);
                re=MessageBoxA(NULL,message," Confirmation message",54);
                Clear_buffer();
                if(re==TryAgain)
                {
                    Bk_color(28,15);
                    field_of_mainmenu(60,26);
                    Bk_color(252,0);
                    goto reinput_mobile;
                }
            }
        }
        if(gsetting.auto_detect_date==1)
        {
            get_system_date(&newstudent.joine_day,&newstudent.joine_month,&newstudent.joine_year);
            Bk_color(252,0);
            gotoxy(61,29);
            printf("%02d/%02d/%04d",newstudent.joine_day,newstudent.joine_month,newstudent.joine_year);
        }
        else
        {
            re=input_date_undermainmenu(&newstudent.joine_day,&newstudent.joine_month,&newstudent.joine_year,61,29,75,32,0,252,28,15);
        }
        Hide_cursor();
        fp=fopen(guser.stdpath,"ab");
        if(fp==NULL)
        {
            fclose(fp);
            MessageBoxA(NULL," An error occurred, the student could not be added."," Error",16);
            Clear_buffer();
            return 404;
        }
        fwrite(&newstudent,sizeof(struct students),1,fp);
        fclose(fp);
        re=MessageBoxA(NULL," Student successfully added. do you want one more student."," Student added",68);
        if(re==Yes)
        {
            goto add_more_student;
        }
        return 1;
}
int remove_student()
{
    int re;
    char student_id[15],message[456];
    FILE *fp,*fp1;
    Bk_color(180,11);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("REMOVE STUDENT");
    Bk_color(28,15);
    gotoxy(42,23);
    printf("STUDENT ID");
    remove_more_students:
    Bk_color(28,15);
    field_of_mainmenu(60,23);
    Show_cursor(7);
    reinput_std_id:
    re=input_charnumbers_undermainmenu(student_id,9,2,61,23);
    if(re==202)
    {
        return 202;
    }
    if(chack_student_id(student_id)!=1)
    {
        MessageBoxA(NULL," Incorrect student ID please enter valid student id."," Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(28,0);
        goto reinput_std_id;
    }
    if(chack_student_id_in_issuelist(student_id)==1)
    {
        MessageBoxA(NULL," At present you can not delete this student because it has been issued a book."," Invalid Action",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(252,0);
        goto reinput_std_id;
    }
    strcpy(message," Are you sure you want to remove student Permanently.\n");
    strcat(message,"\n Student id    : ");
    strcat(message,gstudent.id);
    strcat(message,"\n Student name  : ");
    strcat(message,gstudent.name);
    strcat(message,"\n Father name   : ");
    strcat(message,gstudent.father_name);
    strcat(message,"\n Class         : ");
    strcat(message,gstudent.std_class);
    strcat(message,"\n Roll number   : ");
    strcat(message,gstudent.roll_no);
    strcat(message,"\n Mobile Number : ");
    strcat(message,gstudent.mobile);
    strcat(message,"\n Year          : ");
    strcat(message,gstudent.year);
    re=MessageBoxA(NULL,message," Confirm Message",36);
    if(re!=Yes)
    {
        return 0;
    }
    fp=fopen(guser.stdpath,"rb");
    fp1=fopen(tempfile,"wb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not remove the student."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gstudent,sizeof(struct students),1,fp)>0)
    {
        if(match_two_string(student_id,gstudent.id)!=1)
        {
            fwrite(&gstudent,sizeof(struct students),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen(guser.stdpath,"wb");
    fp1=fopen(tempfile,"rb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not remove the student."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gstudent,sizeof(struct students),1,fp1)>0)
    {
        fwrite(&gstudent,sizeof(struct students),1,fp);
    }
    fclose(fp);
    fclose(fp1);
    remove(tempfile);
    re=MessageBoxA(NULL," Student Successfully removed, you want to remove one more student."," Student removed",68);
    Clear_buffer();
    if(re==Yes)
    {
        goto remove_more_students;
    }
    return 1;
}
int chack_std_mobile(char *mobile)
{
    FILE *fp;
    fp=fopen(guser.stdpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&gstudent,sizeof(struct students),1,fp)>0)
    {
        if(match_two_string(mobile,gstudent.mobile)==1)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int chack_roll_number_of_class(char *rollno,char *stdclass)
{
    FILE *fp;
    fp=fopen(guser.stdpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&gstudent,sizeof(struct students),1,fp)>0)
    {
        if(match_two_string(stdclass,gstudent.std_class)==1)
        {
            if(match_two_string(rollno,gstudent.roll_no)==1)
            {
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}
int chack_student_id(char *id)
{
    FILE *fp;
    fp=fopen(guser.stdpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&gstudent,sizeof(struct students),1,fp)>0)
    {
        if(match_two_string(id,gstudent.id)==1)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int category_management()
{
    char ch;
    int x,x1,y,y1;
    Clear_buffer();
    restat_library_menu:
    Bk_color(180,7);
    main_menu_background();
    ind_back_freame(2,38,3,5,117,180,12);
    Bk_color(197,15);
    rec_MSGinM("CATEGORY MANAGEMENT",2,38,4);
    notification();
    x=3;
    x1=38;
    y=6;
    reset:
        y1=y+2;
        Bk_color(117,1);
        if(x==3)
        {
            gotoxy(12,7);
            printf("Add New Category");
            gotoxy(12,9);
            printf("Remove Category");
            gotoxy(12,11);
            printf("Search Category");
            gotoxy(12,13);
            printf("View All Category");
            /*gotoxy(12,15);
            printf("Change Father Name");
            gotoxy(12,17);
            printf("Change Roll Number");
            gotoxy(12,19);
            printf("Chnage Mobile Number");
            gotoxy(12,21);
            printf("Change Student Class");
            gotoxy(12,23);
            printf("Change Year");
            gotoxy(12,25);
            printf("View All Students");
            gotoxy(12,27);
            printf("Close Application");
            gotoxy(12,29);
            printf("Option 13");
            gotoxy(12,31);
            printf("Option 14");
            gotoxy(12,33);
            printf("Option 15");
            gotoxy(12,35);
            printf("Option 16");
            gotoxy(12,37);
            printf("Option 17");*/
            setcolor(14);
            menu_option(x,x1,y,y1);
            Bk_color(225,9);
            if(y+1==7 && x==3)
            {
                gotoxy(12,7);
                printf("Add New Category");
            }
            if(y+1==9 && x==3)
            {
                gotoxy(12,9);
                printf("Remove Category");
            }
            if(y+1==11 && x==3)
            {
                gotoxy(12,11);
                printf("Search Category");
            }
            if(y+1==13 && x==3)
            {
                gotoxy(12,13);
                printf("View All Category");
            }
            /*if(y+1==15 && x==3)
            {
                gotoxy(12,15);
                printf("Change Father Name");
            }
            if(y+1==17 && x==3)
            {
                gotoxy(12,17);
                printf("Change Roll Number");
            }
            if(y+1==19 && x==3)
            {
                gotoxy(12,19);
                printf("Chnage Mobile Number");
            }
            if(y+1==21 && x==3)
            {
                gotoxy(12,21);
                printf("Change Student Class");
            }
            if(y+1==23 && x==3)
            {
                gotoxy(12,23);
                printf("Change Year");
            }
            if(y+1==25 && x==3)
            {
                gotoxy(12,25);
                printf("View All Students");
            }
            if(y+1==27 && x==3)
            {
                gotoxy(12,27);
                printf("Close Application");
            }
            if(y+1==29 && x==3)
            {
                gotoxy(12,29);
                //printf("Option 13");
            }
            if(y+1==31 && x==3)
            {
                gotoxy(12,31);
                //printf("Option 14");
            }
            if(y+1==33 && x==3)
            {
                gotoxy(12,33);
                //printf("Option 15");
            }
            if(y+1==35 && x==3)
            {
                gotoxy(12,35);
                //printf("Option 16");
            }
            if(y+1==37 && x==3)
            {
                gotoxy(12,37);
                //printf("Option 17");
            }*/
        }
        Bk_color(117,14);
        rechoise:
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        Bk_color(117,14);
        gotoxy(56,4);
        ch=getch();
        if(ch==27)
        {
            return 202;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>6 && y<=12)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y-2;
                        goto reset;
                    }
                    goto rechoise;
                case down:
                    if(y>=6 && y<12)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y+2;
                        goto reset;
                    }
                    goto rechoise;
                }
            }
            else
            {
                goto reset;
            }
        }
        else if(ch==13)
        {
            switch(y+1)
            {
            case 7:
                if(guser.add_new_categoryes==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                add_new_category();
                Hide_cursor();
                notification();
                Clear_buffer();
                goto reset;
                break;
            case 9:
                if(guser.remove_categoryes==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                remove_category();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 11:
                if(guser.search_categoryes==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                search_category();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 13:
                if(guser.view_all_categoryes==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                view_all_category();
                system("cls");
                system("COLOR bc");
                main_frame(180,guser.library_name);
                Bk_color(180,7);
                main_menu_background();
                ind_back_freame(2,38,3,5,117,180,12);
                Bk_color(197,15);
                rec_MSGinM("CATEGORY MANAGEMENT",2,38,4);
                print_login_status();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            }
        }
        else
        {
            goto reset;
        }
}
int remove_category()
{
    int re,flag=0;
    char category[60];
    FILE *fp,*fp1;
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("REMOVE CATEGORY");
    Bk_color(28,15);
    gotoxy(42,23);
    printf("CATEGORY OR ID");
    delete_more_catrgory:
    Bk_color(28,15);
    field_of_mainmenu(60,23);
    reinput_category:
    Show_cursor(7);
    re=input_Number_char_undermainmenu(category,46,61,23);
    if(re==202)
    {
        return 202;
    }
    if(chack_categorie(category)!=1)
    {
        MessageBoxA(NULL," Incorrect category or category id please enter valid category or id."," Invalid Input",48);
        Clear_buffer();
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        Bk_color(28,0);
        goto reinput_category;
    }
    Hide_cursor();
    if(category[0]>='0' && category[0]<='9')
    {
        flag=1;
    }
    else
    {
        flag=0;
    }
    re=MessageBoxA(NULL," Are you sure you want to remove category Permanently."," Confirm Message",36);
    if(re!=Yes)
    {
        return 0;
    }
    fp=fopen(guser.categoriepath,"rb");
    fp1=fopen(tempfile,"wb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not remove the category."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gcategorie,sizeof(struct categorie),1,fp)>0)
    {
        if(flag==1)
        {
            decryption(gcategorie.categorie_id);
            if(match_two_string(category,gcategorie.categorie_id)!=1)
            {
                encryption(gcategorie.categorie_id);
                fwrite(&gcategorie,sizeof(struct categorie),1,fp1);
            }
        }
        if(flag==0)
        {
            decryption(gcategorie.categorie);
            if(match_two_string(category,gcategorie.categorie)!=1)
            {
                encryption(gcategorie.categorie);
                fwrite(&gcategorie,sizeof(struct categorie),1,fp1);
            }
        }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen(guser.categoriepath,"wb");
    fp1=fopen(tempfile,"rb");
    if(fp==NULL || fp1==NULL)
    {
        MessageBoxA(NULL," An error occurred, Could not remove the category."," Error",16);
        Clear_buffer();
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gcategorie,sizeof(struct categorie),1,fp1)>0)
    {
        fwrite(&gcategorie,sizeof(struct categorie),1,fp);
    }
    fclose(fp);
    fclose(fp1);
    remove(tempfile);
    re=MessageBoxA(NULL," Category Successfully Removed, you want to remove one more category."," Category Removed",68);
    Clear_buffer();
    if(re==Yes)
    {
        goto delete_more_catrgory;
    }
    return 1;
}
int book_transaction()
{
    char ch;
    int x,x1,y,y1;
    Clear_buffer();
    restat_library_menu:
    Bk_color(180,7);
    main_menu_background();
    ind_back_freame(2,38,3,5,117,180,12);
    Bk_color(197,15);
    rec_MSGinM("BOOK TRANSACTION",2,38,4);
    notification();
    x=3;
    x1=38;
    y=6;
    reset:
        y1=y+2;
        Bk_color(117,1);
        if(x==3)
        {
            gotoxy(10,7);
            printf("Issue Book");
            gotoxy(10,9);
            printf("Submit Book");
            gotoxy(10,11);
            printf("View Issued Book");
            gotoxy(10,13);
            printf("Search Issued Book");
            gotoxy(10,15);
            printf("View Invoice");
            gotoxy(10,17);
            printf("View All Invoice");
            gotoxy(10,19);
            printf("Export Issed Book in Excel");
            gotoxy(10,21);
            printf("Export All Invoice in Excel");
            /*gotoxy(12,23);
            printf("Intructions");
            gotoxy(12,25);
            printf("About");
            gotoxy(12,27);
            printf("Close Application");
            gotoxy(12,29);
            printf("Option 13");
            gotoxy(12,31);
            printf("Option 14");
            gotoxy(12,33);
            printf("Option 15");
            gotoxy(12,35);
            printf("Option 16");
            gotoxy(12,37);
            printf("Option 17");*/
            setcolor(14);
            menu_option(x,x1,y,y1);
            Bk_color(225,9);
            if(y+1==7 && x==3)
            {
                gotoxy(10,7);
                printf("Issue Book");
            }
            if(y+1==9 && x==3)
            {
                gotoxy(10,9);
                printf("Submit Book");
            }
            if(y+1==11 && x==3)
            {
                gotoxy(10,11);
                printf("View Issued Book");
            }
            if(y+1==13 && x==3)
            {
                gotoxy(10,13);
                printf("Search Issued Book");
            }
            if(y+1==15 && x==3)
            {
                gotoxy(10,15);
                printf("View Invoice");
            }
            if(y+1==17 && x==3)
            {
                gotoxy(10,17);
                printf("View All Invoice");
            }
            if(y+1==19 && x==3)
            {
                gotoxy(10,19);
                printf("Export Issed Book in Excel");
            }
            if(y+1==21 && x==3)
            {
                gotoxy(10,21);
                printf("Export All Invoice in Excel");
            }
            /*if(y+1==23 && x==3)
            {
                gotoxy(12,23);
                printf("Intructions");
            }
            if(y+1==25 && x==3)
            {
                gotoxy(12,25);
                printf("About");
            }
            if(y+1==27 && x==3)
            {
                gotoxy(12,27);
                printf("Close Application");
            }
            if(y+1==29 && x==3)
            {
                gotoxy(12,29);
                //printf("Option 13");
            }
            if(y+1==31 && x==3)
            {
                gotoxy(12,31);
                //printf("Option 14");
            }
            if(y+1==33 && x==3)
            {
                gotoxy(12,33);
                //printf("Option 15");
            }
            if(y+1==35 && x==3)
            {
                gotoxy(12,35);
                //printf("Option 16");
            }
            if(y+1==37 && x==3)
            {
                gotoxy(12,37);
                //printf("Option 17");
            }*/
        }
        Bk_color(117,14);
        rechoise:
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        Bk_color(117,14);
        gotoxy(56,4);
        ch=getch();
        if(ch==27)
        {
            return 202;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>6 && y<=20)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y-2;
                        goto reset;
                    }
                    goto rechoise;
                case down:
                    if(y>=6 && y<20)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y+2;
                        goto reset;
                    }
                    goto rechoise;
                }
            }
            else
            {
                goto reset;
            }
        }
        else if(ch==13)
        {
            switch(y+1)
            {
            case 7:
                if(guser.issue_book_permission==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                issue_book();
                Clear_buffer();
                Hide_cursor();
                notification();
                goto reset;
                break;
            case 9:
                if(guser.submit_books==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                submit_book();
                Clear_buffer();
                Hide_cursor();
                notification();
                goto reset;
                break;
            case 11:
                if(guser.view_issued_books==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                system("cls");
                view_all_issued_book();
                system("cls");
                system("COLOR bc");
                main_frame(180,guser.library_name);
                Bk_color(180,7);
                main_menu_background();
                ind_back_freame(2,38,3,5,117,180,12);
                Bk_color(197,15);
                rec_MSGinM("BOOK TRANSACTION",2,38,4);
                print_login_status();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 13:
                search_issue_book();
                notification();
                Clear_buffer();
                Hide_cursor();
                goto reset;
                break;
            case 15:
                if(guser.view_invoices==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                ShowCursor(7);
                view_invoice();
                notification();
                Clear_buffer();
                Hide_cursor();
                goto reset;
            case 17:
                if(guser.view_all_invoices==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                system("cls");
                view_all_Invoice();
                system("cls");
                system("COLOR bc");
                main_frame(180,guser.library_name);
                Bk_color(180,7);
                main_menu_background();
                ind_back_freame(2,38,3,5,117,180,12);
                Bk_color(197,15);
                rec_MSGinM("BOOK TRANSACTION",2,38,4);
                print_login_status();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
            case 19:
                if(guser.export_issued_book==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                export_all_issued_book_to_excel();
                notification();
                Clear_buffer();
                Hide_cursor();
                goto reset;
            case 21:
                if(guser.Export_all_invoice==0)
                {
                    MessageBoxA(NULL," You need permission to perform this action.\n\n You require permission from administrator to perform this action"," Access Denied",48);
                    Clear_buffer();
                    goto rechoise;
                }
                Export_all_invoice_to_excel();
                notification();
                Clear_buffer();
                Hide_cursor();
                goto reset;
            }
        }
        else
        {
            goto reset;
        }
}
int view_all_Invoice()
{
    FILE *fp;
    int x,y,flag=0,flag2=0,flag3=0;
    char ch;
    Hide_cursor();
    system("COLOR 7C");
    adjustWindowSize(0,0,112,42);
    buffer_size(308,42);
    Bk_color(28,1);
    back_freame(0,307,0,2);
    Bk_color(28,15);
    rec_MSGinM("STUDENT NAME",0,46,1);
    rec_MSGinM("BOOK NAME",48,95,1);
    rec_MSGinM("INVO. NO.",97,108,1);
    rec_MSGinM("STD. ID",110,121,1);
    rec_MSGinM("STD CLASS",123,134,1);
    rec_MSGinM("ROLL NO.",136,147,1);
    rec_MSGinM("BOOK ID",149,160,1);
    rec_MSGinM("BOOK CATEGORY",160,212,1);
    rec_MSGinM("ISSUE DATE",210,227,1);
    rec_MSGinM("SUBMIT DATE",225,241,1);
    rec_MSGinM("DATE OF SUB.",241,255,1);
    rec_MSGinM("RENT CHARGE",253,269,1);
    rec_MSGinM("EXTRA CHARGE",268,282,1);
    rec_MSGinM("TOTAL AMT",280,294,1);
    rec_MSGinM("MOBILE",291,310,1);
    line_V(0,2,48,'n','n',0);
    line_V(0,2,97,'n','n',0);
    line_V(0,2,110,'n','n',0);
    line_V(0,2,123,'n','n',0);
    line_V(0,2,136,'n','n',0);
    line_V(0,2,149,'n','n',0);
    line_V(0,2,162,'n','n',0);
    line_V(0,2,212,'n','n',0);
    line_V(0,2,227,'n','n',0);
    line_V(0,2,241,'n','n',0);
    line_V(0,2,255,'n','n',0);
    line_V(0,2,269,'n','n',0);
    line_V(0,2,282,'n','n',0);
    line_V(0,2,295,'n','n',0);
    Bk_color(117,1);
    line_V(3,41,48,'n','n',0);
    line_V(3,41,97,'n','n',0);
    line_V(3,41,110,'n','n',0);
    line_V(3,41,123,'n','n',0);
    line_V(3,41,136,'n','n',0);
    line_V(3,41,149,'n','n',0);
    line_V(3,41,162,'n','n',0);
    line_V(3,41,212,'n','n',0);
    line_V(3,41,227,'n','n',0);
    line_V(3,41,241,'n','n',0);
    line_V(3,41,255,'n','n',0);
    line_V(3,41,269,'n','n',0);
    line_V(3,41,282,'n','n',0);
    line_V(3,41,295,'n','n',0);
    fp=fopen(guser.invoice_path,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        MessageBoxA(NULL," There is no invoice in invoice list."," List Empty",64);
        Clear_buffer();
        return 404;
    }
    y=4;
    flag3=0;
    while(fread(&ginvoice,sizeof(struct Invoice),1,fp)>0)
    {
        if((y+1)>41)
        {
            if(flag3==0)
            {
                adjustWindowSize(0,0,111,42);
                flag3=1;
            }
            buffer_size(308,y+2);
        }
        Bk_color(117,1);
        gotoxy(48,y);
        printf("%c",179);
        gotoxy(97,y);
        printf("%c",179);
        gotoxy(110,y);
        printf("%c",179);
        gotoxy(123,y);
        printf("%c",179);
        gotoxy(136,y);
        printf("%c",179);
        gotoxy(149,y);
        printf("%c",179);
        gotoxy(162,y);
        printf("%c",179);
        gotoxy(212,y);
        printf("%c",179);
        gotoxy(227,y);
        printf("%c",179);
        gotoxy(241,y);
        printf("%c",179);
        gotoxy(255,y);
        printf("%c",179);
        gotoxy(269,y);
        printf("%c",179);
        gotoxy(282,y);
        printf("%c",179);
        gotoxy(295,y);
        printf("%c",179);
        gotoxy(48,y+1);
        printf("%c",179);
        gotoxy(97,y+1);
        printf("%c",179);
        gotoxy(110,y+1);
        printf("%c",179);
        gotoxy(123,y+1);
        printf("%c",179);
        gotoxy(136,y+1);
        printf("%c",179);
        gotoxy(149,y+1);
        printf("%c",179);
        gotoxy(162,y+1);
        printf("%c",179);
        gotoxy(212,y+1);
        printf("%c",179);
        gotoxy(227,y+1);
        printf("%c",179);
        gotoxy(241,y+1);
        printf("%c",179);
        gotoxy(255,y+1);
        printf("%c",179);
        gotoxy(269,y+1);
        printf("%c",179);
        gotoxy(282,y+1);
        printf("%c",179);
        gotoxy(295,y+1);
        printf("%c",179);
        if(flag==0)
        {
            Bk_color(117,1);
            flag=1;
        }
        else
        {
            Bk_color(117,15);
            flag=0;
        }
        gotoxy(1,y);
        printf("%s",ginvoice.std_name);
        gotoxy(50,y);
        printf("%s",ginvoice.book_name);
        gotoxy(99,y);
        printf("%s",ginvoice.invoive_no);
        gotoxy(112,y);
        printf("%s",ginvoice.std_id);
        gotoxy(125,y);
        printf("%s",ginvoice.std_class);
        gotoxy(138,y);
        printf("%s",ginvoice.std_roll_no);
        gotoxy(151,y);
        printf("%s",ginvoice.book_id);
        gotoxy(164,y);
        printf("%s",ginvoice.book_category);
        gotoxy(214,y);
        printf("%s/%s/%s",ginvoice.issue_day,ginvoice.issue_month,ginvoice.issue_year);
        gotoxy(229,y);
        printf("%s/%s/%s",ginvoice.submit_day,ginvoice.submit_month,ginvoice.submit_year);
        gotoxy(243,y);
        printf("%s/%s/%s",ginvoice.day_of_submit,ginvoice.month_of_submit,ginvoice.year_of_submit);
        gotoxy(257,y);
        printf("%s",ginvoice.rent_charge);
        gotoxy(271,y);
        printf("%s",ginvoice.extra_charge);
        gotoxy(284,y);
        printf("%s",ginvoice.total_amount);
        gotoxy(297,y);
        printf("%s",ginvoice.mobile);
        y=y+2;
        flag2=1;
    }
    fclose(fp);
    if(flag2==0)
    {
        MessageBoxA(NULL," There is no invoice in invoice list."," List Empty",64);
        Clear_buffer();
        return 0;
    }
    x=0;
    Bk_color(28,15);
    rescroll:
        gotoxy(x,y);
        ch=getch();
        if(ch==-32)
        {
            ch=getch();
            if(ch==left || ch==right)
            {
                switch(ch)
                {
                case 75:
                    if(flag3==1)
                    {
                        x=x-111;
                        flag3=0;
                    }
                    if(x>0 && x<=308)
                    {
                        x--;
                    }
                    goto rescroll;
                case right:
                    if(flag3==0)
                    {
                        x=x+111;
                        flag3=1;
                    }
                    if(x>=0 && x<308)
                    {
                        x++;
                    }
                    goto rescroll;
                }
            }
            else
            {
                goto rescroll;
            }
        }
        else if(ch==13)
        {

        }
        else
        {
            goto rescroll;
        }
}
int export_all_issued_book_to_excel()
{
    int re;
    char Book_id[15],Tr_date[15];
    char newline[]="\n";
    char next_column[]=",";
    FILE *fp,*fp1;
    char filename[60];
    char file_path[250];
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("EXPORT ISSUED BOOK TO EXCEL SHEET");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("FILE NAME");
    Bk_color(28,15);
    field_of_mainmenu(60,20);
    mkdir(Exported_data);
    reinput_file_name:
        Show_cursor(7);
        strcpy(file_path,Exported_data);
        Bk_color(252,0);
        re=input_string_undermainmenu(filename,46,61,20);
        if(re==202)
        {
            return 202;
        }
        Hide_cursor();
        strcat(filename,".csv");
        strcat(file_path,"\\");
        strcat(file_path,filename);
        if(chack_file_name(file_path)==1)
        {
            MessageBoxA(NULL," File name already exist, Please Enter another name of the file."," Error",16);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            goto reinput_file_name;
        }
        fp=fopen(file_path,"w");
        fp1=fopen(guser.issuepath,"rb");
        if(fp==NULL || fp1==NULL)
        {
            MessageBoxA(NULL,"  An Error! Issued book could not exported to excel sheet, please try again."," Error",16);
            Clear_buffer();
            return 0;
        }
        fputs("Student ID,Student Name,Mobile Number,Book Id,Book Name,Issue Date,Submit Date\n",fp);
        while(fread(&gissuedata,sizeof(struct issue_books),1,fp1)>0)
        {
            fputs(gissuedata.std_id,fp);
            fputs(next_column,fp);
            fputs(gissuedata.std_name,fp);
            fputs(next_column,fp);
            fputs(gissuedata.std_mobile,fp);
            fputs(next_column,fp);
            convert_number_to_string(gissuedata.book_id,Book_id);
            fputs(Book_id,fp);
            fputs(next_column,fp);
            fputs(gissuedata.book_name,fp);
            fputs(next_column,fp);
            store_date_in_string(Tr_date,gissuedata.issue_day,gissuedata.issue_month,gissuedata.issue_year);
            fputs(Tr_date,fp);
            fputs(next_column,fp);
            store_date_in_string(Tr_date,gissuedata.submit_day,gissuedata.submit_month,gissuedata.submit_year);
            fputs(Tr_date,fp);
            fputs(newline,fp);
        }
        fclose(fp);
        fclose(fp1);
        MessageBoxA(NULL," All Issued Book Successfully Exported.\nFind File on this Path : brightgoal->exported data"," Invoice Exported",64);
        Clear_buffer();
        return 1;

}
int store_date_in_string(char *str,int day,int month,int year)
{
    int temp[6];
    convert_number_to_string(day,str);
    strcat(str,"/");
    convert_number_to_string(month,temp);
    strcat(str,temp);
    convert_number_to_string(year,temp);
    strcat(str,"/");
    strcat(str,temp);
    return 1;
}
int Export_all_invoice_to_excel()
{
    int re;
    char newline[]="\n";
    char next_column[]=",";
    int count=1;
    FILE *fp,*fp1;
    char filename[60];
    char file_path[250];
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("EXPORT INVOICE TO EXCEL SHEET");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("FILE NAME");
    Bk_color(28,15);
    field_of_mainmenu(60,20);
    mkdir(Exported_data);
    reinput_file_name:
        Show_cursor(7);
        strcpy(file_path,Exported_data);
        Bk_color(252,0);
        re=input_string_undermainmenu(filename,46,61,20);
        if(re==202)
        {
            return 202;
        }
        Hide_cursor();
        strcat(filename,".csv");
        strcat(file_path,"\\");
        strcat(file_path,filename);
        if(chack_file_name(file_path)==1)
        {
            MessageBoxA(NULL," File name already exist, Please Enter another name of the file."," Error",16);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            goto reinput_file_name;
        }
        fp=fopen(file_path,"w");
        fp1=fopen(guser.invoice_path,"rb");
        if(fp==NULL || fp1==NULL)
        {
            MessageBoxA(NULL,"  An Error! Bill invoice could not exported to excel sheet, please try again."," Error",16);
            Clear_buffer();
            return 0;
        }
        fputs("Invoice Number,Student ID,Student Name,Student Class,Student Roll No.,Book ID,Book Name,Book Category,Student Mobile,Issue Date,Submit Date,Date Of Submit,Rent Charge,Extra Charge,Total Amount\n",fp);
        while(fread(&ginvoice,sizeof(struct Invoice),1,fp1)>0)
        {
            fputs(ginvoice.invoive_no,fp);
            fputs(next_column,fp);
            fputs(ginvoice.std_id,fp);
            fputs(next_column,fp);
            fputs(ginvoice.std_name,fp);
            fputs(next_column,fp);
            fputs(ginvoice.std_class,fp);
            fputs(next_column,fp);
            fputs(ginvoice.std_roll_no,fp);
            fputs(next_column,fp);
            fputs(ginvoice.book_id,fp);
            fputs(next_column,fp);
            fputs(ginvoice.book_name,fp);
            fputs(next_column,fp);
            fputs(ginvoice.book_category,fp);
            fputs(next_column,fp);
            fputs(ginvoice.mobile,fp);
            fputs(next_column,fp);
            fputs(ginvoice.issue_day,fp);
            fputs("/",fp);
            fputs(ginvoice.issue_month,fp);
            fputs("/",fp);
            fputs(ginvoice.issue_year,fp);
            fputs(next_column,fp);
            fputs(ginvoice.submit_day,fp);
            fputs("/",fp);
            fputs(ginvoice.submit_month,fp);
            fputs("/",fp);
            fputs(ginvoice.submit_year,fp);
            fputs(next_column,fp);
            fputs(ginvoice.day_of_submit,fp);
            fputs("/",fp);
            fputs(ginvoice.month_of_submit,fp);
            fputs("/",fp);
            fputs(ginvoice.year_of_submit,fp);
            fputs(next_column,fp);
            fputs(ginvoice.rent_charge,fp);
            fputs(next_column,fp);
            fputs(ginvoice.extra_charge,fp);
            fputs(next_column,fp);
            fputs(ginvoice.total_amount,fp);
            fputs(newline,fp);
            count++;
        }
        fputs(",,,,,,,,,,,Total,",fp);
        create_sum_formula(filename,2,count,"m");
        fputs(filename,fp);
        fputs(next_column,fp);
        create_sum_formula(filename,2,count,"n");
        fputs(filename,fp);
        fputs(next_column,fp);
        create_sum_formula(filename,2,count,"o");
        fputs(filename,fp);
        fclose(fp);
        fclose(fp1);
        MessageBoxA(NULL," All Bill Invoice Successfully Exported.\nFind File on this Path :  brightgoal->exported data"," Invoice Exported",64);
        Clear_buffer();
        return 1;
}
int create_sum_formula(char *formula,int from,int to,char *column)
{
    char temp[15];
    formula[0]='\0';
    strcat(formula,"=sum(");
    strcat(formula,column);
    convert_number_to_string(from,temp);
    strcat(formula,temp);
    strcat(formula,":");
    strcat(formula,column);
    convert_number_to_string(to,temp);
    strcat(formula,temp);
    strcat(formula,")");
}
int chack_file_name(char *file_name)
{
    FILE *fp;
    fp=fopen(file_name,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 0;
    }
    else
    {
        fclose(fp);
        return 1;
    }
}
int view_invoice()
{
    int re;
    char invoice_number[15];
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("VIEW INVOICE");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("INVOICE NUMBER");
    Bk_color(28,15);
    field_of_mainmenu(60,20);
    reinput_invoice_number:
        re=input_charnumbers_undermainmenu(invoice_number,9,1,61,20);
        if(re==202)
        {
            return 202;
        }
        if(chack_invoice_number(invoice_number)!=1)
        {
            MessageBoxA(NULL," Incrroct Invoice Number."," Invalid Invoice Number",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            Bk_color(252,0);
            goto reinput_invoice_number;
        }
        Hide_cursor();
        print_invoice(invoice_number);
        Clear_buffer();
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        return 1;
}
int search_issue_book()
{
    char std_id[15];
    int book_id,re;
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("SEARCH ISSUED BOOK");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("STUDENT ID");
    gotoxy(42,23);
    printf("BOOK ID");
    Bk_color(28,15);
    field_of_mainmenu(60,23);
    field_of_mainmenu(60,20);
    Show_cursor(7);
    reinput_std_id:
        Bk_color(252,0);
        re=input_charnumbers_undermainmenu(std_id,9,2,61,20);
        if(re==202)
        {
            return 202;
        }
        if(chack_student_id(std_id)!=1)
        {
            MessageBoxA(NULL," Incorrect student id."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            goto reinput_std_id;
        }
        if(chack_student_id_in_issuelist(std_id)!=1)
        {
            MessageBoxA(NULL," No Book has been issued to this student."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            goto reinput_std_id;
        }
    reinput_book_id:
        Bk_color(252,0);
        re=input_numbers_undermainmenu(&book_id,9,61,23);
        if(chack_book_id(book_id)!=1)
        {
            MessageBoxA(NULL," Incorrect Book id."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,23);
            goto reinput_std_id;
        }
        if(book_already_issue_to(std_id,book_id)!=1)
        {
            MessageBoxA(NULL," This book has not been issued to this student"," Invalid Action",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,23);
            goto reinput_std_id;
        }
        Hide_cursor();
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("ISSUE BOOK RECORD");
    Bk_color(28,15);
    gotoxy(42,8);
    printf("STUDENT ID");
    gotoxy(42,11);
    printf("STUDENT NAME");
    gotoxy(42,14);
    printf("BOOK ID");
    gotoxy(42,17);
    printf("BOOK NAME");
    gotoxy(42,20);
    printf("BOOK CATEGORY");
    gotoxy(42,23);
    printf("WRITER NAME");
    gotoxy(42,26);
    printf("ISSUE DATE");
    gotoxy(42,29);
    printf("SUBMIT DATE");
    Bk_color(28,15);
    Clear_buffer();
    field_of_mainmenu(60,8);
    field_of_mainmenu(60,11);
    field_of_mainmenu(60,14);
    field_of_mainmenu(60,17);
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    field_of_mainmenu(60,26);
    field_of_mainmenu(60,29);
    Bk_color(252,0);
    gotoxy(61,8);
    printf("%s",gissuedata.std_id);
    gotoxy(61,11);
    printf("%s",gissuedata.std_name);
    gotoxy(61,14);
    printf("%d",gissuedata.book_id);
    gotoxy(61,17);
    printf("%s",gissuedata.book_name);
    if(chack_book_id(book_id)==1)
    {
        decryption(gbookdata.writer);
        decryption(gbookdata.categorie);
        gotoxy(61,20);
        printf("%s",gbookdata.categorie);
        gotoxy(61,23);
        printf("%s",gbookdata.writer);
    }
    gotoxy(61,26);
    printf("%02d/%02d/%04d",gissuedata.issue_day,gissuedata.issue_month,gissuedata.issue_year);
    gotoxy(61,29);
    printf("%02d/%02d/%04d",gissuedata.submit_day,gissuedata.submit_month,gissuedata.submit_year);
    Bk_color(28,15);
    print_date_time(74,95,41,39,41);
    Clear_buffer();

}
int issue_book()
{
    int re;
    FILE *fp;
    char message[456];
    struct issue_books issuebook;
    struct students newstudent;
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("ISSUE BOOK TO STUDENT");
    Bk_color(28,15);
    gotoxy(42,8);
    printf("STUDENT ID");
    gotoxy(42,11);
    printf("STUDENT NAME");
    gotoxy(42,14);
    printf("BOOK ID");
    gotoxy(42,17);
    printf("BOOK NAME");
    gotoxy(42,20);
    printf("BOOK CATEGORY");
    gotoxy(42,23);
    printf("WRITER NAME");
    gotoxy(42,26);
    printf("ISSUE DATE");
    gotoxy(42,29);
    printf("SUBMIT DATE");
    Show_cursor(7);
    issue_more_book:
        Bk_color(28,15);
        Clear_buffer();
        field_of_mainmenu(60,8);
        field_of_mainmenu(60,11);
        field_of_mainmenu(60,14);
        field_of_mainmenu(60,17);
        field_of_mainmenu(60,20);
        field_of_mainmenu(60,23);
        field_of_mainmenu(60,26);
        field_of_mainmenu(60,29);
        reinput_std_id:
        re=input_charnumbers_undermainmenu(issuebook.std_id,10,2,61,8);
        if(re==202)
        {
            return 202;
        }
        if(chack_student_id(issuebook.std_id)!=1)
        {
            MessageBoxA(NULL," Invalid student id. Please enter valid student id."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,8);
            Bk_color(252,0);
            goto reinput_std_id;
        }
        strcpy(issuebook.std_name,gstudent.name);
        strcpy(issuebook.std_mobile,gstudent.mobile);
        gotoxy(61,11);
        printf("%s",gstudent.name);
        reinput_book_id:
        re=input_numbers_undermainmenu(&issuebook.book_id,9,61,14);
        if(re==202)
        {
            return 202;
        }
        if(chack_book_id(issuebook.book_id)!=1)
        {
            MessageBoxA(NULL," Invalid Book Id. enter valid book id"," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,14);
            Bk_color(252,0);
            goto reinput_book_id;
        }
        if(get_available_qty_ofbook(issuebook.book_id)==0)
        {
            MessageBoxA(NULL," No more book's available in library."," Invalid action",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,14);
            Bk_color(252,0);
            goto reinput_book_id;

        }
        if(book_already_issue_to(issuebook.std_id,issuebook.book_id)==1)
        {
            MessageBoxA(NULL," This book has already been issued to this student."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,14);
            Bk_color(252,0);
            goto reinput_book_id;
        }
        decryption(gbookdata.book_name);
        decryption(gbookdata.categorie);
        decryption(gbookdata.writer);
        strcpy(issuebook.book_name,gbookdata.book_name);
        gotoxy(61,17);
        printf("%s",gbookdata.book_name);
        gotoxy(61,20);
        printf("%s",gbookdata.categorie);
        gotoxy(61,23);
        printf("%s",gbookdata.writer);
        if(gsetting.auto_detect_date==1)
        {
            get_system_date(&issuebook.issue_day,&issuebook.issue_month,&issuebook.issue_year);
            gotoxy(61,26);
            printf("%02d/%02d/%04d",issuebook.issue_day,issuebook.issue_month,issuebook.issue_year);
        }
        else
        {
            re=input_date_undermainmenu(&issuebook.issue_day,&issuebook.issue_month,&issuebook.issue_year,61,26,32,65,0,252,28,15);
            if(re==202)
            {
                return 202;
            }
        }
        reinput_submit_date:
        re=input_date_undermainmenu(&issuebook.submit_day,&issuebook.submit_month,&issuebook.submit_year,61,29,32,65,0,252,28,15);
        if(re==202)
        {
            return 202;
        }
        if(issuebook.issue_day==issuebook.submit_day && issuebook.issue_month==issuebook.submit_month && issuebook.issue_year==issuebook.submit_year)
        {
            MessageBoxA(NULL," You can not enter same date of the date of issue and the date of submit"," Invalid input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,29);
            Bk_color(252,0);
            goto reinput_submit_date;
        }
        if(issuebook.submit_year<issuebook.issue_year)
        {
            MessageBoxA(NULL," You can not enter previous date of the issue date."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,29);
            Bk_color(252,0);
            goto reinput_submit_date;
        }
        else if((issuebook.submit_year==issuebook.issue_year) && (issuebook.submit_month<issuebook.issue_month))
        {
            MessageBoxA(NULL," You can not enter previous date of the issue date."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,29);
            Bk_color(252,0);
            goto reinput_submit_date;
        }
        else if((issuebook.submit_year==issuebook.issue_year) && (issuebook.submit_month==issuebook.issue_month) && (issuebook.submit_day<issuebook.issue_day))
        {
            MessageBoxA(NULL," You can not enter previous date of the issue date."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,29);
            Bk_color(252,0);
            goto reinput_submit_date;
        }
        fp=fopen(guser.issuepath,"ab");
        if(fp==NULL)
        {
            fclose(fp);
            MessageBoxA(NULL," An error occurred, book could not issued."," Error",16);
            Clear_buffer();
            return 404;
        }
        fwrite(&issuebook,sizeof(struct issue_books),1,fp);
        fclose(fp);
        re=MessageBoxA(NULL,"  Book Successfully Issued, you want to issue one more book."," Book issued",68);
        Clear_buffer();
        if(re==Yes)
        {
            goto issue_more_book;
        }
}
int submit_book()
{
    int re,day_of_submit,month_of_submit,year_of_submit;
    int rent_day,total_day,extra_day,extra_charge,rent_charge,total_amount;
    FILE *fp;
    char message[456];
    struct issue_books issuebook;
    struct Invoice newinvoice;
    submit_more_book:
    Bk_color(180,11);
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("ISSUE BOOK TO STUDENT");
    Bk_color(28,15);
    gotoxy(42,8);
    printf("STUDENT ID");
    gotoxy(42,11);
    printf("STUDENT NAME");
    gotoxy(42,14);
    printf("BOOK ID");
    gotoxy(42,17);
    printf("BOOK NAME");
    gotoxy(42,20);
    printf("BOOK CATEGORY");
    gotoxy(42,23);
    printf("WRITER NAME");
    gotoxy(42,26);
    printf("ISSUE DATE");
    gotoxy(42,29);
    printf("SUBMIT DATE");
    gotoxy(42,32);
    printf("DATE OF TODAY");
    gotoxy(42,35);
    printf("INVOICE NUMBER");
    Show_cursor(7);
        Bk_color(28,15);
        Clear_buffer();
        field_of_mainmenu(60,8);
        field_of_mainmenu(60,11);
        field_of_mainmenu(60,14);
        field_of_mainmenu(60,17);
        field_of_mainmenu(60,20);
        field_of_mainmenu(60,23);
        field_of_mainmenu(60,26);
        field_of_mainmenu(60,29);
        field_of_mainmenu(60,32);
        field_of_mainmenu(60,35);
        reinput_std_id:
        re=input_charnumbers_undermainmenu(issuebook.std_id,10,2,61,8);
        if(re==202)
        {
            return 202;
        }
        if(chack_student_id(issuebook.std_id)!=1)
        {
            MessageBoxA(NULL," Invalid student id. Please enter valid student id."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,8);
            Bk_color(252,0);
            goto reinput_std_id;
        }
        if(chack_student_id_in_issuelist(issuebook.std_id)!=1)
        {
            MessageBoxA(NULL," This book has not been issued to this student."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,8);
            Bk_color(252,0);
            goto reinput_std_id;
        }
        strcpy(newinvoice.std_id,issuebook.std_id); //For gernating invoice
        strcpy(newinvoice.std_name,gstudent.name);  //For gernating invoice
        strcpy(newinvoice.std_class,gstudent.std_class);     //For gernating invoice
        strcpy(newinvoice.std_roll_no,gstudent.roll_no);     //For gernating invoice
        strcpy(newinvoice.mobile,gstudent.mobile);       //For gernating invoice
        gotoxy(61,11);
        printf("%s",gstudent.name);
        reinput_book_id:
        re=input_numbers_undermainmenu(&issuebook.book_id,9,61,14);
        if(re==202)
        {
            return 202;
        }
        if(chack_book_id(issuebook.book_id)!=1)
        {
            MessageBoxA(NULL," Invalid Book Id. enter valid book id"," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,14);
            Bk_color(252,0);
            goto reinput_book_id;
        }
        if(book_already_issue_to(issuebook.std_id,issuebook.book_id)!=1)
        {
            MessageBoxA(NULL," This book are not issued to this student."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,14);
            Bk_color(252,0);
            goto reinput_book_id;

        }
        decryption(gbookdata.book_name);
        decryption(gbookdata.categorie);
        decryption(gbookdata.writer);
        convert_number_to_string(issuebook.book_id,newinvoice.book_id); //For gernating invoice
        strcpy(newinvoice.book_name,gbookdata.book_name);               //For gernating invoice
        strcpy(newinvoice.book_category,gbookdata.categorie);           //For gernating invoice
        convert_number_to_string(gissuedata.issue_day,newinvoice.issue_day);    //For gernating invoice
        convert_number_to_string(gissuedata.issue_month,newinvoice.issue_month);    //For gernating invoice
        convert_number_to_string(gissuedata.issue_year,newinvoice.issue_year);  //For gernating invoice
        convert_number_to_string(gissuedata.submit_day,newinvoice.submit_day);  //For gernating invoice
        convert_number_to_string(gissuedata.submit_month,newinvoice.submit_month);  //For gernating invoice
        convert_number_to_string(gissuedata.submit_year,newinvoice.submit_year);    //For gernating invoice
        gotoxy(61,17);
        printf("%s",gbookdata.book_name);
        gotoxy(61,20);
        printf("%s",gbookdata.categorie);
        gotoxy(61,23);
        printf("%s",gbookdata.writer);
        gotoxy(61,26);
        printf("%02d/%02d/%04d",gissuedata.issue_day,gissuedata.issue_month,gissuedata.issue_year);
        gotoxy(61,29);
        printf("%02d/%02d/%04d",gissuedata.submit_day,gissuedata.submit_month,gissuedata.submit_year);
        issuebook.submit_day=gissuedata.submit_day;
        issuebook.submit_month=gissuedata.submit_month;
        issuebook.submit_year=gissuedata.submit_year;
        issuebook.issue_day=gissuedata.issue_day;
        issuebook.issue_month=gissuedata.issue_month;
        issuebook.issue_year=gissuedata.issue_year;
        reinput_submit_date:
        if(gsetting.auto_detect_date==1)
        {
            get_system_date(&day_of_submit,&month_of_submit,&year_of_submit);
            gotoxy(61,32);
            printf("%02d/%02d/%04d",day_of_submit,month_of_submit,year_of_submit);
        }
        else
        {
            re=input_date_undermainmenu(&day_of_submit,&month_of_submit,&year_of_submit,61,32,65,32,0,252,28,15);
            if(re==202)
            {
                return 202;
            }
        }
        if(year_of_submit<issuebook.submit_year)
        {
            MessageBoxA(NULL," You can not enter previous date of the submit date."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,32);
            Bk_color(252,0);
            goto reinput_submit_date;
        }
        else if((issuebook.submit_year==year_of_submit) && (month_of_submit<issuebook.submit_month))
        {
            MessageBoxA(NULL," You can not enter previous date of the submit date."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,32);
            Bk_color(252,0);
            goto reinput_submit_date;
        }
        else if((issuebook.submit_year==year_of_submit) && (issuebook.submit_month==month_of_submit) && (day_of_submit<issuebook.submit_day))
        {
            MessageBoxA(NULL," You can not enter previous date of the submit date."," Invalid Input",48);
            Clear_buffer();
            Bk_color(28,15);
            field_of_mainmenu(60,32);
            Bk_color(252,0);
            goto reinput_submit_date;
        }
        convert_number_to_string(day_of_submit,newinvoice.day_of_submit);   //For gernating invoice
        convert_number_to_string(month_of_submit,newinvoice.month_of_submit);   //For gernating invoice
        convert_number_to_string(year_of_submit,newinvoice.year_of_submit);     //For gernating invoice
        total_day=diffrent_between_in_dates(issuebook.issue_day,issuebook.issue_month,issuebook.issue_year,day_of_submit,month_of_submit,year_of_submit);
        rent_day=diffrent_between_in_dates(issuebook.issue_day,issuebook.issue_month,issuebook.issue_year,issuebook.submit_day,issuebook.submit_month,issuebook.submit_year);
        extra_day=total_day-rent_day;
        rent_charge=rent_day*gbookdata.rent_price;
        extra_charge=extra_day*gbookdata.extra_charge;
        total_amount=rent_charge+extra_charge;
        convert_number_to_string(rent_charge,newinvoice.rent_charge);   //For gernating invoice
        convert_number_to_string(extra_charge,newinvoice.extra_charge); //For gernating invoice
        convert_number_to_string(total_amount,newinvoice.total_amount); //For gernating invoice
        if(extra_charge==0)
        {
            strcpy(newinvoice.extra_charge,"00");
        }
        if(gsetting.auto_gernate_invoice_no==1)     //For gernating invoice
        {
            get_invoice_number(newinvoice.invoive_no);
            gotoxy(61,35);
            printf("%s",newinvoice.invoive_no);
        }
        else
        {
            reinput_invoice_number:
                Bk_color(252,0);
                re=input_charnumbers_undermainmenu(newinvoice.invoive_no,9,1,61,35);
                if(re==202)
                {
                    return 202;
                }
                if(chack_invoice_number(newinvoice.invoive_no)==1)
                {
                    MessageBoxA(NULL," Invoice number already exist. please enter another invoice number."," Invalid Input",48);
                    Clear_buffer();
                    Bk_color(28,15);
                    field_of_mainmenu(60,35);
                    Bk_color(252,0);
                    goto reinput_invoice_number;
                }
        }
        if(remove_book_issue_list(issuebook.std_id,issuebook.book_id)!=1)
        {
            MessageBoxA(NULL,"An error occurred, the book could not be submitted."," Error",16);
            Clear_buffer();
            return 0;
        }
        else
        {
            fp=fopen(guser.invoice_path,"ab");
            if(fp==NULL)
            {
                MessageBoxA(NULL," An error, the invoice could not be saved"," Error",16);
                Clear_buffer();
            }
            else
            {
                fwrite(&newinvoice,sizeof(struct Invoice),1,fp);
                fclose(fp);
                if(gsetting.auto_open_invoice==1)
                {
                    re=print_invoice(newinvoice.invoive_no);
                    Clear_buffer();
                    if(re==1)
                    {
                        Bk_color(28,15);
                        print_date_time(74,95,41,39,41);
                    }
                }
                else
                {
                    re=MessageBoxA(NULL,"Do you want see bill invoice.","Book Submited",36);
                    if(re==6)
                    {
                        re=print_invoice(newinvoice.invoive_no);
                        Clear_buffer();
                        if(re==1)
                        {
                            Bk_color(28,15);
                            print_date_time(74,95,41,39,41);
                        }
                    }
                }
            }
        }
        re=MessageBoxA(NULL,"Book successfully submited, you want to submit one more book."," Confirm Message",36);
        Clear_buffer();
        if(re==Yes)
        {
            goto submit_more_book;
        }
}
int print_invoice(char *invoice_num)
{
    if(chack_invoice_number(invoice_num)!=1)
    {
        return 0;
    }
    Bk_color(180,7);
    working_area_background();
    ind_back_freame(40,109,3,5,117,180,12);
    Bk_color(197,15);
    rec_MSGinM("BILL INVOICE",40,109,4);
    Bk_color(117,0);
    gotoxy(42,7);
    printf("[ BRIGHTGOAL ]");
    gotoxy(42,9);
    printf("PORTAL : BRIGHTGOAL.IN");
    gotoxy(42,11);
    printf("POWERED BY : HARVINDAR SINGH");
    gotoxy(42,13);
    printf("CONTACT : 9695806109");
    Bk_color(117,8);
    ind_back_freame(82,107,6,8,225,117,8);
    Bk_color(128,14);
    ind_back_freame(82,107,8,10,128,128,14);
    Bk_color(225,8);
    ind_back_freame(82,107,10,12,225,225,8);
    Bk_color(128,14);
    ind_back_freame(82,107,12,14,117,128,14);
    Bk_color(128,15);
    gotoxy(95,7);
    printf("|");
    gotoxy(95,11);
    printf("|");
    Bk_color(225,0);
    gotoxy(95,9);
    printf("|");
    gotoxy(95,13);
    printf("|");
    Bk_color(128,15);
    gotoxy(85,7);
    printf("INVOICE");
    gotoxy(100,7);
    printf("DATE");
    gotoxy(86,11);
    printf("STD ID");
    gotoxy(99,11);
    printf("BOOK ID");
    Bk_color(225,0);
    gotoxy(83,9);
    printf("%s",ginvoice.invoive_no);
    gotoxy(97,9);
    printf("%s/%s/%s",ginvoice.day_of_submit,ginvoice.month_of_submit,ginvoice.year_of_submit);
    gotoxy(83,13);
    printf("%s",ginvoice.std_id);
    gotoxy(97,13);
    printf("%s",ginvoice.book_id);
    Bk_color(117,8);
    back_freame(42,107,15,17);
    Bk_color(128,15);
    gotoxy(43,16);
    printf("BILL TO");
    Bk_color(117,9);
    gotoxy(43,18);
    printf("STD NAME : %s",ginvoice.std_name);
    gotoxy(43,20);
    printf("CLASS : %s",ginvoice.std_class);
    gotoxy(43,22);
    printf("ROLL NUMBER : %s",ginvoice.std_roll_no);
    gotoxy(43,24);
    printf("MOBILE NUMBER : %s",ginvoice.mobile);
    Bk_color(117,8);
    ind_back_freame(42,107,26,28,128,128,8);
    //Bk_color(117,7);
    //line_V(28,38,53,'n','n',0);
    //line_V(28,38,64,'n','n',0);
    //line_V(28,38,75,'n','n',0);
    //line_V(28,38,86,'n','n',0);
    //line_V(28,38,97,'n','n',0);
    Bk_color(128,7);
    line_V(26,28,53,'n','n',0);
    line_V(26,28,64,'n','n',0);
    line_V(26,28,75,'n','n',0);
    line_V(26,28,86,'n','n',0);
    line_V(26,28,97,'n','n',0);
    Bk_color(128,15);
    gotoxy(43,27);
    printf("ISSUE DATE");
    gotoxy(54,27);
    printf("SUB. DATE");
    gotoxy(65,27);
    printf("CURRENT DT");
    gotoxy(77,27);
    printf("RENT CH.");
    gotoxy(88,27);
    printf("EXTRA CH.");
    gotoxy(98,27);
    printf("TOTAL AMT");
    Bk_color(117,9);
    gotoxy(43,30);
    printf("%s/%s/%s",ginvoice.issue_day,ginvoice.issue_month,ginvoice.issue_year);
    gotoxy(54,30);
    printf("%s/%s/%s",ginvoice.submit_day,ginvoice.submit_month,ginvoice.submit_year);
    gotoxy(65,30);
    printf("%s/%s/%s",ginvoice.day_of_submit,ginvoice.month_of_submit,ginvoice.year_of_submit);
    gotoxy(76,30);
    printf("%s",ginvoice.rent_charge);
    gotoxy(87,30);
    printf("%s",ginvoice.extra_charge);
    gotoxy(98,30);
    printf("%s",ginvoice.total_amount);
    Bk_color(117,8);
    ind_back_freame(42,107,36,38,128,128,8);
    Bk_color(128,14);
    gotoxy(43,37);
    printf("TOTAL AMOUNT OF THE BILL");
    gotoxy(94,37);
    printf("RS. %s",ginvoice.total_amount);
    return 1;
}
int remove_book_issue_list(char *std_id,int book_id)
{
    FILE *fp,*fp1;
    int flag=0;
    fp=fopen(guser.issuepath,"rb");
    fp1=fopen(tempfile,"wb");
    if(fp==NULL || fp1==NULL)
    {
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gissuedata,sizeof(struct issue_books),1,fp)>0)
    {
        if(match_two_string(std_id,gissuedata.std_id)==1)
        {
            if(gissuedata.book_id==book_id)
            {
                flag=1;
            }
            else
            {
                fwrite(&gissuedata,sizeof(struct issue_books),1,fp1);
            }
        }
        else
        {
            fwrite(&gissuedata,sizeof(struct issue_books),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen(guser.issuepath,"wb");
    fp1=fopen(tempfile,"rb");
    if(fp==NULL || fp1==NULL)
    {
        fclose(fp);
        fclose(fp1);
        return 404;
    }
    while(fread(&gissuedata,sizeof(struct issue_books),1,fp1)>0)
    {
        fwrite(&gissuedata,sizeof(struct issue_books),1,fp);
    }
    fclose(fp);
    fclose(fp1);
    remove(tempfile);
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int chack_invoice_number(char *num)
{
    FILE *fp;
    fp=fopen(guser.invoice_path,"rb");
    if(fp==NULL)
    {
        return 404;
    }
    while(fread(&ginvoice,sizeof(struct Invoice),1,fp)>0)
    {
        if(match_two_string(num,ginvoice.invoive_no)==1)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int get_invoice_number(char *num)
{
    char invoice_number;
    regernate_invoice_number:
        gernate_key_char(invoice_number,9);
        if(chack_invoice_number(invoice_number)==1)
        {
            goto regernate_invoice_number;
        }
        else
        {
            strcpy(num,invoice_number);
            return 1;
        }
}
int chack_book_id_in_issuelist(int book_id,int *total_issued_book)
{
    int flag=0;
    FILE *fp;
    fp=fopen(guser.issuepath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&gissuedata,sizeof(struct issue_books),1,fp)>0)
    {
        if(book_id==gissuedata.book_id)
        {
            flag++;
        }
    }
    *total_issued_book=flag;
    fclose(fp);
    if(flag==0)
        return 0;
    else
        return 1;
}
int chack_student_id_in_issuelist(char *std_id)
{
    FILE *fp;
    fp=fopen(guser.issuepath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&gissuedata,sizeof(struct issue_books),1,fp)>0)
    {
        if(match_two_string(std_id,gissuedata.std_id)==1)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int book_already_issue_to(char *std_id,int book_id)
{
    FILE *fp;
    fp=fopen(guser.issuepath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&gissuedata,sizeof(struct issue_books),1,fp)>0)
    {
        if(match_two_string(std_id,gissuedata.std_id)==1)
        {
            if(book_id==gissuedata.book_id)
            {
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}
void about()
{
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("About",40,109,4);
    Bk_color(28,15);
    make_frame(42,108,8,21);
    gotoxy(44,8);
    printf(" Brightgoal lms  v1.0.0 ");
    make_frame(43,43+25,7,9);
    gotoxy(43,8);
    printf("%c",180);
    gotoxy(43+25,8);
    printf("%c",195);
    gotoxy(46,11);
    printf("Author Name : Harvindar Singh");
    gotoxy(46,13);
    printf("Contact No : 9140417112");
    gotoxy(46,15);
    printf("Home Page : www.brightgoal.in");
    gotoxy(46,17);
    printf("Operating System : Windows xp, 7, 8, 8.1, 10 (64 or 32 Bit)");
    gotoxy(46,19);
    printf("Build Time : 01:20:33 AM - 10 Dec 2018");
    gotoxy(46,23);
    printf("This Software is Build in C language by Harvindar Singh.");
    gotoxy(46,25);
    printf("This Software is Designed to Manage Library Data Such as Books");
    gotoxy(46,27);
    printf("Student, Category etc.");
    Bk_color(28,15);
    print_date_time(74,95,41,39,41);
    getch();

}
int setting()
{
    char ch;
    FILE *fp;
    int y,x;
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("Setting",40,109,4);
    y=7;
    x=102;
    chack_setting();
    reset_setting:
        Bk_color(28,15);
        gotoxy(43,7);
        printf("Auto Gernate Backup Key");
        gotoxy(43,9);
        printf("Auto Gernate Data Key");
        gotoxy(43,11);
        printf("Auto Date Detection");
        gotoxy(43,13);
        printf("Password Masking");
        gotoxy(43,15);
        printf("Set Guset Account Permission While Creating A/c");
        gotoxy(43,17);
        printf("Warning Message's");
        gotoxy(43,19);
        printf("Open bill invoice automatically after submit the book.");
        gotoxy(43,21);
        printf("Generate invoice number automatically.");
        setting_strip(42,y,28,14,11);
        Bk_color(225,1);
        if(y==7)
        {
            gotoxy(43,7);
            printf("Auto Gernate Backup Key");
        }
        if(y==9)
        {
            gotoxy(43,9);
            printf("Auto Gernate Data Key");
        }
        if(y==11)
        {
            gotoxy(43,11);
            printf("Auto Date Detection");
        }
        if(y==13)
        {
            gotoxy(43,13);
            printf("Password Masking");
        }
        if(y==15)
        {
            gotoxy(43,15);
            printf("Set Guset Account Permission While Creating A/c");
        }
        if(y==17)
        {
            gotoxy(43,17);
            printf("Warning Message's");
        }
        if(y==19)
        {
            gotoxy(43,19);
            printf("Open bill invoice automatically after submit the book.");
        }
        if(y==21)
        {
            gotoxy(43,21);
            printf("Generate invoice number automatically.");
        }
        if(y==7)
            Bk_color(180,1);
        else
            Bk_color(28,15);
        if(gsetting.auto_gernate_backupkey)
        {
            gotoxy(x,7);
            printf("ON");
        }
        else
        {
            gotoxy(x,7);
            printf("OFF");
        }
        if(y==9)
            Bk_color(180,1);
        else
            Bk_color(28,15);
        if(gsetting.auto_gernate_datakey)
        {
            gotoxy(x,9);
            printf("ON");
        }
        else
        {
            gotoxy(x,9);
            printf("OFF");
        }
        if(y==11)
            Bk_color(180,1);
        else
            Bk_color(28,15);
        if(gsetting.auto_detect_date)
        {
            gotoxy(x,11);
            printf("ON");
        }
        else
        {
            gotoxy(x,11);
            printf("OFF");
        }
        if(y==13)
            Bk_color(180,1);
        else
            Bk_color(28,15);
        if(gsetting.password_masking)
        {
            gotoxy(x,13);
            printf("ON");
        }
        else
        {
            gotoxy(x,13);
            printf("OFF");
        }
        if(y==15)
            Bk_color(180,1);
        else
            Bk_color(28,15);
        if(gsetting.set_permission_while_creating_acoount)
        {
            gotoxy(x,15);
            printf("ON");
        }
        else
        {
            gotoxy(x,15);
            printf("OFF");
        }
        if(y==17)
            Bk_color(180,1);
        else
            Bk_color(28,15);
        if(gsetting.warnings)
        {
            gotoxy(x,17);
            printf("ON");
        }
        else
        {
            gotoxy(x,17);
            printf("OFF");
        }
        if(y==19)
            Bk_color(180,1);
        else
            Bk_color(28,15);
        if(gsetting.auto_open_invoice)
        {
            gotoxy(x,19);
            printf("ON");
        }
        else
        {
            gotoxy(x,19);
            printf("OFF");
        }
        if(y==21)
            Bk_color(180,1);
        else
            Bk_color(28,15);
        if(gsetting.auto_gernate_invoice_no)
        {
            gotoxy(x,21);
            printf("ON");
        }
        else
        {
            gotoxy(x,21);
            printf("OFF");
        }
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        reinput:
        ch=getch();
        if(ch==27)
        {
            return 0;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>7 && y<=21)
                    {
                        setting_strip(42,y,28,1,1);
                        y=y-2;
                    }
                    else
                    {
                        goto reinput;
                    }
                    goto reset_setting;
                case down:
                    if(y>=7 && y<21)
                    {
                        setting_strip(42,y,28,1,1);
                        y=y+2;
                    }
                    else
                    {
                        goto reinput;
                    }
                    goto reset_setting;
                }
            }
            else
            {
                if(ch==left)
                {
                    switch(y)
                    {
                    case 7:
                        gsetting.auto_gernate_backupkey=0;
                        break;
                    case 9:
                        gsetting.auto_gernate_datakey=0;
                        break;
                    case 11:
                        gsetting.auto_detect_date=0;
                        break;
                    case 13:
                        gsetting.password_masking=0;
                        break;
                    case 15:
                        gsetting.set_permission_while_creating_acoount=0;
                        break;
                    case 17:
                        gsetting.warnings=0;
                        break;
                    case 19:
                        gsetting.auto_open_invoice=0;
                        break;
                    case 21:
                        gsetting.auto_gernate_invoice_no=0;
                        break;
                    }
                    goto reset_setting;
                }
                if(ch==right)
                {
                    switch(y)
                    {
                    case 7:
                        gsetting.auto_gernate_backupkey=1;
                        break;
                    case 9:
                        gsetting.auto_gernate_datakey=1;
                        break;
                    case 11:
                        gsetting.auto_detect_date=1;
                        break;
                    case 13:
                        gsetting.password_masking=1;
                        break;
                    case 15:
                        gsetting.set_permission_while_creating_acoount=1;
                        break;
                    case 17:
                        gsetting.warnings=1;
                        break;
                    case 19:
                        gsetting.auto_open_invoice=1;
                        break;
                    case 21:
                        gsetting.auto_gernate_invoice_no=1;
                        break;
                    }
                    goto reset_setting;
                }
            }
        }
        else if(ch==13)
        {
            fp=fopen(setting_path,"wb");
            fwrite(&gsetting,sizeof(struct settings),1,fp);
            fclose(fp);
            return 1;
        }
        else if(ch==48 || ch==49)
        {
            if(ch==48)
                {
                    switch(y)
                    {
                    case 7:
                        gsetting.auto_gernate_backupkey=0;
                        break;
                    case 9:
                        gsetting.auto_gernate_datakey=0;
                        break;
                    case 11:
                        gsetting.auto_detect_date=0;
                        break;
                    case 13:
                        gsetting.password_masking=0;
                        break;
                    case 15:
                        gsetting.set_permission_while_creating_acoount=0;
                        break;
                    case 17:
                        gsetting.warnings=0;
                        break;
                    case 19:
                        gsetting.auto_open_invoice=0;
                        break;
                    case 21:
                        gsetting.auto_gernate_invoice_no=0;
                        break;
                    }
                    goto reset_setting;
                }
                if(ch==49)
                {
                    switch(y)
                    {
                    case 7:
                        gsetting.auto_gernate_backupkey=1;
                        break;
                    case 9:
                        gsetting.auto_gernate_datakey=1;
                        break;
                    case 11:
                        gsetting.auto_detect_date=1;
                        break;
                    case 13:
                        gsetting.password_masking=1;
                        break;
                    case 15:
                        gsetting.set_permission_while_creating_acoount=1;
                        break;
                    case 17:
                        gsetting.warnings=1;
                        break;
                    case 19:
                        gsetting.auto_open_invoice=1;
                        break;
                    case 21:
                        gsetting.auto_gernate_invoice_no=1;
                        break;
                    }
                    goto reset_setting;
                }
        }
        else
        {
            goto reset_setting;
        }
    getch();
}
int chack_setting()
{
    FILE *fp;
    int flag=0;
    fp=fopen(setting_path,"rb");
    if(fp==NULL)
    {
        gsetting.auto_gernate_backupkey=0;
        gsetting.auto_gernate_datakey=0;
        gsetting.auto_detect_date=1;
        gsetting.password_masking=1;
        gsetting.set_permission_while_creating_acoount=1;
        gsetting.warnings=1;
        gsetting.auto_open_invoice=1;
        gsetting.auto_gernate_invoice_no=0;
        return 404;
    }
    while(fread(&gsetting,sizeof(struct settings),1,fp)>0)
    {
        flag=1;
    }
    fclose(fp);
    if(!flag)
    {
        gsetting.auto_gernate_backupkey=0;
        gsetting.auto_gernate_datakey=0;
        gsetting.auto_detect_date=1;
        gsetting.password_masking=1;
        gsetting.set_permission_while_creating_acoount=1;
        gsetting.warnings=1;
        gsetting.auto_open_invoice=1;
        gsetting.auto_gernate_invoice_no=0;
        return 0;
    }
    else
    {
        return 1;
    }
}
void setting_strip(int x,int y,int bkcolor,int mstrip_color,int rstrip_color)
{
    Bk_color(bkcolor,mstrip_color);
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    Bk_color(bkcolor,rstrip_color);
    printf("%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220);
    Bk_color(bkcolor,mstrip_color);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    Bk_color(bkcolor,rstrip_color);
    printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);
    Bk_color(bkcolor,mstrip_color);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
    Bk_color(bkcolor,rstrip_color);
    printf("%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223);
}
int manage_accounts()
{
    int x,x1,y,y1,re;
    char ch;
    restat_account_management:
    Bk_color(180,7);
    main_menu_background();
    ind_back_freame(2,38,3,5,117,180,12);
    Bk_color(197,15);
    rec_MSGinM("MANAGE ACCOUNTS",2,38,4);
    x=3;
    x1=38;
    y=6;
    reset:
        y1=y+2;
        Bk_color(117,1);
        if(x==3)
        {
            gotoxy(9,7);
            printf("Find Your Account");
            gotoxy(9,9);
            printf("Change your Name");
            gotoxy(9,11);
            printf("Change Password");
            gotoxy(9,13);
            printf("Forget Password");
            gotoxy(9,15);
            printf("Set Guest A/c Permmissions");
            gotoxy(9,17);
            printf("Delete Account");
            gotoxy(9,19);
            printf("View All Guset Account");
            setcolor(14);
            menu_option(x,x1,y,y1);
            Bk_color(225,9);
            if(y+1==7 && x==3)
            {
                gotoxy(9,7);
                printf("Find Your Account");
            }
            if(y+1==9 && x==3)
            {
                gotoxy(9,9);
                printf("Change your Name");
            }
            if(y+1==11 && x==3)
            {
                gotoxy(9,11);
                printf("Change Password");
            }
            if(y+1==13 && x==3)
            {
                gotoxy(9,13);
                printf("Forget Password");
            }
            if(y+1==15 && x==3)
            {
                gotoxy(9,15);
                printf("Set Guest A/c Permmissions");
            }
            if(y+1==17 && x==3)
            {
                gotoxy(9,17);
                printf("Delete Account");
            }
            if(y+1==19 && x==3)
            {
                gotoxy(9,19);
                printf("View All Guset Account");
            }
        }
        Bk_color(117,14);
        rechoise:
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        Bk_color(117,14);
        gotoxy(56,4);
        ch=getch();
        if(ch==27)
        {
            return 202;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>6 && y<=18)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y-2;
                        goto reset;
                    }
                    goto rechoise;
                case down:
                    if(y>=6 && y<18)
                    {
                        setcolor(7);
                        menu_option(x,x1,y,y1);
                        y=y+2;
                        goto reset;
                    }
                    goto rechoise;
                }
            }
            else
            {
                goto reset;
            }
        }
        else if(ch==13)
        {
            switch(y+1)
            {
            case 7:
                Find_your_account();
                notification();
                Hide_cursor();
                goto reset;
                break;
            case 9:
                change_name();
                notification();
                Hide_cursor();
                goto reset;
                break;
            case 11:
                change_Password();
                notification();
                Hide_cursor();
                goto reset;
                break;
            case 13:
                Forget_Password();
                notification();
                Hide_cursor();
                goto reset;
                break;
            case 15:
                set_guest_account_permission();
                notification();
                Hide_cursor();
                Clear_buffer();
                goto reset;
                break;
            case 17:
                Delete_account();
                notification();
                Hide_cursor();
                goto reset;
                break;
            case 19:
                re=Login('g');
                if(re==202)
                {
                    Hide_cursor();
                    notification();
                    goto reset;
                }
                Hide_cursor();
                system("cls");
                Clear_buffer();
                view_all_guest_account(guser.username);
                system("cls");
                system("COLOR bC");
                main_frame(180,"BRIGHTGOAL SCHOOL MANAGEMENT NSYSTEM POWERED BY HARVINDAR SINGH");
                Clear_buffer();
                notification();
                goto restat_account_management;
                break;
            }
        }
        else
        {
            goto reset;
        }
}
int set_guest_account_permission()
{
    int re;
    char username[60];
    char password[60];
    char guest_username[60];
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("DELETE ACCOUNT",40,109,4);
    Bk_color(28,15);
    gotoxy(41,18);
    printf("USERNAME");
    gotoxy(41,21);
    printf("PASSWORD");
    gotoxy(41,24);
    printf("GUEST A/C USERNAME");
    gotoxy(42,27);
    //printf("DATA KEY");
    field_of_mainmenu(60,18);
    field_of_mainmenu(60,21);
    field_of_mainmenu(60,24);
    //field_of_mainmenu(60,27);
    reenter_username:
    Show_cursor(8);
    Bk_color(252,0);
    re=input_Number_char_undermainmenu(username,46,61,18);
    if(re==202)
    {
        return 202;
    }
    Hide_cursor();
    re=chack_username(username);
    if(re!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,18);
        rec_MSGinM("INVALID USERNAME",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,18);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_username;
    }
    if(chacking.account_type=='g')
    {
        Bk_color(28,15);
        field_of_mainmenu(60,18);
        rec_MSGinM("ONLY ADMIN ACCOUNTS WILL BE ACCEPTED",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,18);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_username;
    }
    reenter_password:
    Show_cursor(7);
    re=input_password_undermainmenu(password,46,61,21);
    Hide_cursor();
    if(re==202)
    {
        return 202;
    }
    if(strcmp(password,chacking.password)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,21);
        rec_MSGinM("INCORRECT PASSWORD",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_password;
    }
    reenter_guest_username:
    Show_cursor(7);
    re=input_Number_char_undermainmenu(guest_username,46,61,24);
    Hide_cursor();
    if(re==202)
    {
        return 202;
    }
    re=chack_username(guest_username);
    if(re!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,24);
        rec_MSGinM("INCORRECT GUEST ACCOUNT USERNAME",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,24);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_guest_username;
    }
    if(match_two_string(chacking.guest_admin,username)!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,24);
        rec_MSGinM("INCORRECT GUEST ACCOUNT USERNAME",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,24);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_guest_username;
    }
    if(chacking.account_type=='a')
    {
        Bk_color(28,15);
        field_of_mainmenu(60,24);
        rec_MSGinM("ONLY GUEST ACCOUNTS WILL BE ACCEPTED",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,24);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_guest_username;
    }
    repermission:
    Clear_buffer();
    re=get_permission_of_guest_account(&chacking);
    if(re==202)
    {
        return 202;
    }
    if(confirmation_msg("Are you Sure you want to Save Permissions of Guest Acoount.","Please Confirm","YES ","NO",'y','n'))
    {
        re=replace_permission_of_guest_account(&chacking,chacking.guest_username);
        if(re!=1)
        {
            Bk_color(28,15);
            rec_MSGinM("AN ERROR OCCURRED PERMISSIONS CAN NOT SAVED",40,109,33);
            Bk_color(28,15);
            print_date_time(74,95,41,61,21);
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        goto repermission;
    }

}
int replace_permission_of_guest_account(struct user_accounts *permission,char *username)
{
    int flag=1;
    struct user_accounts newname;
    FILE *fp,*temp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    temp=fopen(tempfile,"wb");
    if(temp==NULL)
    {
        fclose(fp);
        fclose(temp);
        return 404;
    }
    while(fread(&newname,sizeof(struct user_accounts),1,fp)>0)
    {
        if(flag)
        {
            decryption(newname.guest_username);
            if(match_two_string(username,newname.guest_username)==1)
            {
                flag=0;
                newname.add_new_books=permission->add_new_books;
                newname.Delete_books=permission->Delete_books;
                newname.Change_book_name=permission->Change_book_name;
                newname.Change_category=permission->Change_category;
                newname.Change_writer_name=permission->Change_writer_name;
                newname.Change_rent_rate=permission->Change_rent_rate;
                newname.Change_extra_charge=permission->Change_extra_charge;
                newname.Change_book_qty=permission->Change_book_qty;
                newname.Change_book_price=permission->Change_book_price;
                newname.Change_rack_number=permission->Change_rack_number;
                newname.View_all_book=permission->View_all_book;
                newname.export_all_books=permission->export_all_books;
                newname.issue_book_permission=permission->issue_book_permission;
                newname.submit_books=permission->submit_books;
                newname.view_issued_books=permission->view_issued_books;
                newname.view_invoices=permission->view_invoices;
                newname.view_all_invoices=permission->view_all_invoices;
                newname.export_issued_book=permission->export_issued_book;
                newname.Export_all_invoice=permission->Export_all_invoice;
                newname.add_new_students=permission->add_new_students;
                newname.remove_students=permission->remove_students;
                newname.search_students=permission->search_students;
                newname.change_student_name=permission->change_student_name;
                newname.chnage_father_name=permission->chnage_father_name;
                newname.change_mobile_number=permission->change_mobile_number;
                newname.chnage_roll_number=permission->chnage_roll_number;
                newname.view_all_students=permission->view_all_students;
                newname.Export_student_data=permission->Export_student_data;
                newname.add_new_categoryes=permission->add_new_categoryes;
                newname.remove_categoryes=permission->remove_categoryes;
                newname.search_categoryes=permission->search_categoryes;
                newname.view_all_categoryes=permission->view_all_categoryes;
            }
        }
        encryption(newname.guest_username);
        fwrite(&newname,sizeof(struct user_accounts),1,temp);
    }
    fclose(fp);
    fclose(temp);
    temp=fopen(tempfile,"rb");
    if(temp==NULL)
    {
        fclose(temp);
        return 404;
    }
    fp=fopen(userpath,"wb");
    if(fp==NULL)
    {
        fclose(fp);
        fclose(temp);
        return 404;
    }
    while(fread(&newname,sizeof(struct user_accounts),1,temp)>0)
    {
        fwrite(&newname,sizeof(struct user_accounts),1,fp);
    }
    fclose(fp);
    fclose(temp);
    remove(tempfile);
    if(flag==0)
        return 1;
    else
        return 0;
}
int Forget_Password()
{
    int re;
    char username[60];
    char backup_key[60];
    char new_pass[60];
    char confirm_pass[60];
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("CHANGE ACCOUNT PASSWORD",40,109,4);
    Bk_color(28,15);
    gotoxy(42,18);
    printf("USERNAME");
    gotoxy(42,21);
    printf("BACKUP KEY");
    gotoxy(42,24);
    printf("NEW PASSWORD");
    gotoxy(42,27);
    printf("CONFIRM PASSWORD");
    field_of_mainmenu(60,18);
    field_of_mainmenu(60,21);
    field_of_mainmenu(60,24);
    field_of_mainmenu(60,27);
    reenter_username:
    Show_cursor(8);
    Bk_color(252,0);
    re=input_Number_char_undermainmenu(username,46,61,18);
    if(re==202)
    {
        return 202;
    }
    re=chack_username(username);
    if(re!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,18);
        rec_MSGinM("INVALID USERNAME",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,18);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_username;
    }
    reenter_password:
    re=input_mobile_undermainmenu(backup_key,15,61,21);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(backup_key,chacking.Backup_key)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,21);
        rec_MSGinM("INCORRECT BACKUP KEY\a",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_password;
    }
    reinput_newpass:
    re=input_password_undermainmenu(new_pass,46,61,24);
    if(re==202)
    {
        return 202;
    }
    re=input_password_undermainmenu(confirm_pass,46,61,27);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(new_pass,confirm_pass)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,24);
        field_of_mainmenu(60,27);
        rec_MSGinM("BOTH PASSWORD ARE NOT MATCH\a",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,24);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reinput_newpass;
    }
    re=replace_Password_of_account(new_pass,username,chacking.account_type);
    Hide_cursor();
    if(re!=1)
    {
        Bk_color(28,15);
        rec_MSGinM("AN ERROR OCRECD PASSWORD DOESNOT CHANGED",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Clear_buffer();
        return 0;
    }
    else
    {
        Bk_color(28,15);
        rec_MSGinM("PASSWORD SUCCESSFULLY CHANGED",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Clear_buffer();
        return 1;
    }
}
int remove_account(char *username,int account_type)
{
    int flag=0;
    struct user_accounts newname;
    FILE *fp,*temp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    temp=fopen(tempfile,"wb");
    if(temp==NULL)
    {
        fclose(fp);
        fclose(temp);
        return 404;
    }
    flag=0;
    while(fread(&newname,sizeof(struct user_accounts),1,fp)>0)
    {
        if(account_type=='g')
        {

            if(flag==0)
            {
                decryption(newname.guest_username);
                if(match_two_string(newname.guest_username,username)==1)
                {
                    flag=1;
                }
                else
                {
                    encryption(newname.guest_username);
                    fwrite(&newname,sizeof(struct user_accounts),1,temp);
                }
            }
            else
            {
                fwrite(&newname,sizeof(struct user_accounts),1,temp);
            }
            continue;
        }
        if(account_type=='a')
        {
            decryption(newname.username);
            decryption(newname.guest_admin);
            if((match_two_string(newname.username,username)!=1) && (match_two_string(newname.guest_admin,username)!=1))
            {
                encryption(newname.username);
                encryption(newname.guest_admin);
                fwrite(&newname,sizeof(struct user_accounts),1,temp);
            }
            else
            {
                flag=1;
            }
        }
    }
    fclose(fp);
    fclose(temp);
    if(flag==1)
    {
        temp=fopen(tempfile,"rb");
        if(temp==NULL)
        {
            fclose(temp);
            return 404;
        }
        fp=fopen(userpath,"wb");
        if(fp==NULL)
        {
            fclose(fp);
            fclose(temp);
            return 404;
        }
        while(fread(&newname,sizeof(struct user_accounts),1,temp)>0)
        {
            fwrite(&newname,sizeof(struct user_accounts),1,fp);
        }
        fclose(fp);
        fclose(temp);
        remove(tempfile);
        return 1;
    }
    else
    {
        return 0;
    }
}
int Delete_account()
{
    int re;
    char username[60];
    char password[60];
    char data_key[60];
    char backup_key[60];
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("DELETE ACCOUNT",40,109,4);
    Bk_color(28,15);
    gotoxy(42,18);
    printf("USERNAME");
    gotoxy(42,21);
    printf("PASSWORD");
    gotoxy(42,24);
    printf("BACKUP KEY");
    gotoxy(42,27);
    //printf("DATA KEY");
    field_of_mainmenu(60,18);
    field_of_mainmenu(60,21);
    field_of_mainmenu(60,24);
    //field_of_mainmenu(60,27);
    reenter_username:
    Show_cursor(8);
    Bk_color(252,0);
    re=input_Number_char_undermainmenu(username,46,61,18);
    if(re==202)
    {
        return 202;
    }
    re=chack_username(username);
    if(re!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,18);
        rec_MSGinM("INVALID USERNAME",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,18);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_username;
    }
    reenter_password:
    re=input_password_undermainmenu(password,46,61,21);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(password,chacking.password)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,21);
        rec_MSGinM("INCORRECT PASSWORD",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_password;
    }
    reenter_backup_key:
    re=input_mobile_undermainmenu(backup_key,15,61,24);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(backup_key,chacking.Backup_key)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,24);
        rec_MSGinM("INVALID BACKUP KEY",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,24);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_backup_key;
    }
    /*reenter_data_key:
    re=input_mobile_undermainmenu(data_key,15,61,27);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(data_key,chacking.Data_key)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,27);
        rec_MSGinM("INVALID DATA KEY",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,27);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_data_key;
    }*/
    Hide_cursor();
    if(chacking.account_type=='a')
    {
        re=confirmation_msg("Are you sure you want to permanently delete your Account. If you delete your account then your all guest accounts and data will be automatically deleted.","Please confirm again","DELETE","CANCEL",'d','c');
        if(!re)
        {
            return 0;
        }
    }
    else
    {
        re=confirmation_msg("Are you sure you want to permanently delete your Account.","Please confirm again","DELETE","CANCEL",'d','c');
        if(!re)
        {
            return 0;
        }
    }
    if(chacking.account_type=='a')
    {
        create_bat_file(chacking.main_folderPath);
        mkdir(chacking.main_folderPath);
        system("long.bat");
        remove("long.bat");
    }
    re=remove_account(username,chacking.account_type);
    if(re!=1)
    {
        gotoxy(47,35);
        printf("Error : %d",re);
        Bk_color(28,15);
        rec_MSGinM("AN ERROR OCRECD ACCOUNT DOESNOT DELETE",40,109,33);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Clear_buffer();
        return 0;
    }
    else
    {
        Bk_color(28,15);
        rec_MSGinM("ACCOUNT SUCCESSFULLY DELETED",40,109,33);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Clear_buffer();
        return 1;
    }
}
void create_bat_file(char *ch)
{
    FILE *fp;
    mkdir(ch);
    fp=fopen("long.bat","w");
    fprintf(fp,"@echo off\nfor /d %c%cp in (%c",37,37,34);
    fprintf(fp,"%s",ch);
    fprintf(fp,"%c) do rmdir %c%c%cp%c /s /q\nexit",34,34,37,37,34);
    fclose(fp);
}
int change_name()
{
    int re;
    char username[60];
    char password[60];
    char last_name[60];
    char first_name[60];
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("CHANGE YOUR NAME",40,109,4);
    Bk_color(28,15);
    gotoxy(42,18);
    printf("USERNAME");
    gotoxy(42,21);
    printf("PASSWORD");
    gotoxy(42,24);
    printf("NEW FIRST NAME");
    gotoxy(42,27);
    printf("NEW LAST NAME");
    field_of_mainmenu(60,18);
    field_of_mainmenu(60,21);
    field_of_mainmenu(60,24);
    field_of_mainmenu(60,27);
    reenter_username:
    Show_cursor(8);
    Bk_color(252,0);
    re=input_Number_char_undermainmenu(username,46,61,18);
    if(re==202)
    {
        return 202;
    }
    re=chack_username(username);
    if(re!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,18);
        rec_MSGinM("INVALID USERNAME",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,18);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_username;
    }
    reenter_password:
    re=input_password_undermainmenu(password,46,61,21);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(password,chacking.password)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,21);
        rec_MSGinM("INCORRECT PASSWORD",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_password;
    }
    re=input_string_undermainmenu(first_name,46,61,24);
    if(re==202)
    {
        return 202;
    }
    re=input_string_undermainmenu(last_name,46,61,27);
    if(re==202)
    {
        return 202;
    }
    re=replace_name_of_account(first_name,last_name,username,chacking.account_type);
    Hide_cursor();
    if(re==1)
    {
        Bk_color(28,15);
        rec_MSGinM("NAME SUCCESSFULLY CHANGED",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Clear_buffer();
        return 1;
    }
    else
    {
        Bk_color(28,15);
        rec_MSGinM("AN ERROR OCRECD NAME DOESNOT CHANGED",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Clear_buffer();
        return 0;
    }
}
int change_Password()
{
    int re;
    char username[60];
    char password[60];
    char new_pass[60];
    char confirm_pass[60];
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("CHANGE ACCOUNT PASSWORD",40,109,4);
    Bk_color(28,15);
    gotoxy(42,18);
    printf("USERNAME");
    gotoxy(42,21);
    printf("PASSWORD");
    gotoxy(42,24);
    printf("NEW PASSWORD");
    gotoxy(42,27);
    printf("CONFIRM PASSWORD");
    field_of_mainmenu(60,18);
    field_of_mainmenu(60,21);
    field_of_mainmenu(60,24);
    field_of_mainmenu(60,27);
    reenter_username:
    Show_cursor(8);
    Bk_color(252,0);
    re=input_Number_char_undermainmenu(username,46,61,18);
    if(re==202)
    {
        return 202;
    }
    re=chack_username(username);
    if(re!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,18);
        rec_MSGinM("INVALID USERNAME",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,18);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_username;
    }
    reenter_password:
    re=input_password_undermainmenu(password,46,61,21);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(password,chacking.password)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,21);
        rec_MSGinM("INCORRECT PASSWORD",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reenter_password;
    }
    reinput_newpass:
    re=input_password_undermainmenu(new_pass,46,61,24);
    if(re==202)
    {
        return 202;
    }
    re=input_password_undermainmenu(confirm_pass,46,61,27);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(new_pass,confirm_pass)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,24);
        field_of_mainmenu(60,27);
        rec_MSGinM("BOTH PASSWORD ARE NOT MATCH\a",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,24);
        Bk_color(28,1);
        Strip_of_notificationbar(42,30);
        goto reinput_newpass;
    }
    re=replace_Password_of_account(new_pass,username,chacking.account_type);
    Hide_cursor();
    if(re!=1)
    {
        Bk_color(28,15);
        rec_MSGinM("AN ERROR OCRECD PASSWORD DOESNOT CHANGED",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Clear_buffer();
        return 0;
    }
    else
    {
        Bk_color(28,15);
        rec_MSGinM("PASSWORD SUCCESSFULLY CHANGED",40,109,30);
        Bk_color(28,15);
        print_date_time(74,95,41,61,21);
        Clear_buffer();
        return 1;
    }
}
int replace_Password_of_account(char *new_pass,char *username,int account_type)
{
    int flag=1;
    struct user_accounts newname;
    FILE *fp,*temp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    temp=fopen(tempfile,"wb");
    if(temp==NULL)
    {
        fclose(fp);
        fclose(temp);
        return 404;
    }
    while(fread(&newname,sizeof(struct user_accounts),1,fp)>0)
    {
        if(flag)
        {
            if(account_type=='a')
            {
                decryption(newname.username);
                if(match_two_string(username,newname.username)==1)
                {
                    flag=0;
                    strcpy(newname.password,new_pass);
                    encryption(newname.password);
                }
                encryption(newname.username);
            }
            else if(account_type=='g')
            {
                decryption(newname.guest_username);
                if(match_two_string(username,newname.guest_username)==1)
                {
                    flag=0;
                    strcpy(newname.password,new_pass);
                    encryption(newname.password);
                }
                encryption(newname.guest_username);
            }
        }
        fwrite(&newname,sizeof(struct user_accounts),1,temp);
    }
    fclose(fp);
    fclose(temp);
    temp=fopen(tempfile,"rb");
    if(temp==NULL)
    {
        fclose(temp);
        return 404;
    }
    fp=fopen(userpath,"wb");
    if(fp==NULL)
    {
        fclose(fp);
        fclose(temp);
        return 404;
    }
    while(fread(&newname,sizeof(struct user_accounts),1,temp)>0)
    {
        fwrite(&newname,sizeof(struct user_accounts),1,fp);
    }
    fclose(fp);
    fclose(temp);
    remove(tempfile);
    return 1;
}
int replace_name_of_account(char *first_name,char *last_name,char *username,int account_type)
{
    int flag=1;
    struct user_accounts newname;
    FILE *fp,*temp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    temp=fopen(tempfile,"wb");
    if(temp==NULL)
    {
        fclose(fp);
        fclose(temp);
        return 404;
    }
    while(fread(&newname,sizeof(struct user_accounts),1,fp)>0)
    {
        if(flag)
        {
            if(account_type=='a')
            {
                decryption(newname.username);
                if(match_two_string(username,newname.username)==1)
                {
                    flag=0;
                    strcpy(newname.first_name,first_name);
                    strcpy(newname.last_name,last_name);
                    encryption(newname.first_name);
                    encryption(newname.last_name);
                }
                encryption(newname.username);
            }
            else if(account_type=='g')
            {
                decryption(newname.guest_username);
                if(match_two_string(username,newname.guest_username)==1)
                {
                    flag=0;
                    strcpy(newname.first_name,first_name);
                    strcpy(newname.last_name,last_name);
                    encryption(newname.first_name);
                    encryption(newname.last_name);
                }
                encryption(newname.guest_username);
            }
        }
        fwrite(&newname,sizeof(struct user_accounts),1,temp);
    }
    fclose(fp);
    fclose(temp);
    if(flag==0)
    {
        temp=fopen(tempfile,"rb");
        if(temp==NULL)
        {
            fclose(temp);
            return 404;
        }
        fp=fopen(userpath,"wb");
        if(fp==NULL)
        {
            fclose(fp);
            fclose(temp);
            return 404;
        }
        while(fread(&newname,sizeof(struct user_accounts),1,temp)>0)
        {
            fwrite(&newname,sizeof(struct user_accounts),1,fp);
        }
        fclose(fp);
        fclose(temp);
        remove(tempfile);
        return 1;
    }
    else
    {
        return 0;
    }
}
int chack_username(char *username)
{
    FILE *fp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&chacking,sizeof(struct user_accounts),1,fp)>0)
    {
        decryption(chacking.username);
        decryption(chacking.guest_username);
        gotoxy(61,27);
        if(match_two_string(username,chacking.username)==1)
        {
            fclose(fp);
            decryption(chacking.username);
            decryption(chacking.password);
            decryption(chacking.library_name);
            decryption(chacking.first_name);
            decryption(chacking.last_name);
            decryption(chacking.Data_key);
            decryption(chacking.Backup_key);
            decryption(chacking.guest_admin);
            decryption(chacking.guest_username);
            return 1;
        }
        else if(match_two_string(chacking.guest_username,username)==1)
        {
            fclose(fp);
            decryption(chacking.username);
            decryption(chacking.password);
            decryption(chacking.library_name);
            decryption(chacking.first_name);
            decryption(chacking.last_name);
            decryption(chacking.Data_key);
            decryption(chacking.Backup_key);
            decryption(chacking.guest_admin);
            decryption(chacking.guest_username);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int Find_your_account()
{
    int re,y=16;
    char backup_key[60];
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("FIND YOUR ACCOUNT",40,109,4);
    Bk_color(28,15);
    gotoxy(42,23);
    printf("ENTER BACKUP KEY");
    field_of_mainmenu(60,23);
    reenter_backup_key:
    Show_cursor(8);
    Bk_color(252,0);
    re=input_Number_char_undermainmenu(backup_key,15,61,23);
    if(re==202)
    {
        return 202;
    }
    re=chack_back_id(backup_key);
    if(re!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        rec_MSGinM("INVALID BACKUP KEY",40,109,27);
        Bk_color(28,15);
        print_date_time(74,95,41,61,23);
        Bk_color(28,1);
        Strip_of_notificationbar(42,27);
        goto reenter_backup_key;
    }
    Hide_cursor();
    Bk_color(180,1);
    working_area_background();
    Bk_color(197,15);
    rec_MSGinM("YOUR ACCOUNT INFO",40,109,4);
    Bk_color(28,15);
    make_frame(41,108,y,y+12);
    line_H(41,108,y+2,'t','a');
    line_H(41,108,y+4,'t','a');
    line_H(41,108,y+6,'t','a');
    line_H(41,108,y+8,'t','a');
    line_H(41,108,y+10,'t','a');
    line_V(y,y+2,58,'t','a',y+2);
    line_V(y+2,y+4,58,'p','a',0);
    line_V(y+4,y+6,58,'p','a',0);
    line_V(y+6,y+8,58,'p','a',0);
    line_V(y+8,y+10,58,'p','a',0);
    line_V(y+10,y+12,58,'t','a',y+10);
    gotoxy(43,y+1);
    printf("FIRST NAME");
    gotoxy(43,y+3);
    printf("LAST NAME");
    gotoxy(43,y+5);
    printf("USERNAME NAME");
    gotoxy(43,y+7);
    printf("BACKUP KEY");
    gotoxy(43,y+9);
    printf("DATA KEY");
    gotoxy(43,y+11);
    printf("ACCOUNT TYPE");
    gotoxy(60,y+1);
    printf("%s",chacking.first_name);
    gotoxy(60,y+3);
    printf("%s",chacking.last_name);
    if(chacking.account_type=='a')
    {
        gotoxy(60,y+5);
        printf("%s",chacking.username);
        gotoxy(60,y+11);
        printf("ADMINISTRATOR ACCOUNT");
    }
    if(chacking.account_type=='g')
    {
        gotoxy(60,y+5);
        printf("%s",chacking.guest_username);
        gotoxy(60,y+11);
        printf("GUEST ACCOUNT");
    }
    gotoxy(60,y+7);
    printf("%s",chacking.Backup_key);
    gotoxy(60,y+9);
    printf("%s",chacking.Data_key);
    Bk_color(28,15);
    print_date_time(74,95,41,61,23);
    Clear_buffer();
}
int chack_back_id(char *backup_id)
{
    FILE *fp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&chacking,sizeof(struct user_accounts),1,fp)>0)
    {
        decryption(chacking.Backup_key);
        gotoxy(61,27);
        if(match_two_string(backup_id,chacking.Backup_key)==1)
        {

            fclose(fp);
            decryption(chacking.username);
            decryption(chacking.password);
            decryption(chacking.library_name);
            decryption(chacking.first_name);
            decryption(chacking.last_name);
            decryption(chacking.Data_key);
            decryption(chacking.Backup_key);
            decryption(chacking.guest_admin);
            decryption(chacking.guest_username);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int choose_account_type(char *type)
{
    char ch;
    int x,y;
    Hide_cursor();
    Bk_color(180,7);
    working_area_background();
    ind_back_freame(40,109,3,5,117,180,12);
    Bk_color(197,15);
    rec_MSGinM("CHOOSE ACCOUNT TYPE",40,109,4);
    y=20;
    x=42;
    re_choice:
        Bk_color(117,1);
        Strip_of_notificationbar(x,y);
        if(y==20)
            Bk_color(28,15);
        else
            Bk_color(117,1);
        rec_MSGinM("CREATE NEW ACCOUNT FOR LIBRARY",40,109,20);
        if(y==23)
            Bk_color(28,15);
        else
            Bk_color(117,1);
        rec_MSGinM("CREATE GUEST ACCOUNT OF MAIN ACCOUNT",40,109,23);
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        ch=getch();
        if(ch==27)
        {
            return 202;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y==23)
                    {
                        Bk_color(117,7);
                        Strip_of_notificationbar(x,y);
                        y=20;
                    }
                    goto re_choice;
                    break;
                case down:
                    if(y==20)
                    {
                        Bk_color(117,7);
                        Strip_of_notificationbar(x,y);
                        y=23;
                    }
                    goto re_choice;
                    break;
                }
            }
            else
            {
                goto re_choice;
            }
        }
        else if(ch==13)
        {
            switch(y)
            {
            case 20:
                *type='a';
                return 97;
                break;
            case 23:
                *type='g';
                return 103;
                break;
            }
        }
        else
        {
            goto re_choice;
        }
}
int chack_total_guest_account(char *admin_username)
{
    int total_guest_account=0;
    struct user_accounts chack;
    FILE *fp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&chack,sizeof(struct user_accounts),1,fp)>0)
    {
        if(chack.account_type=='g')
        {
            decryption(chack.guest_admin);
            if(match_two_string(admin_username,chack.guest_admin)==1)
            {
                total_guest_account++;
            }
        }
    }
    fclose(fp);
    return total_guest_account;
}
int create_account(int account_type)
{
    struct user_accounts newaccount;
    char confirm_pass[60];
    int re,i;
    FILE *fp;
    Bk_color(180,11);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(68,4);
    printf("CREATE NEW ACCOUNT");
    Bk_color(28,15);
    gotoxy(42,8);
    printf("FIRST NAME");
    gotoxy(42,11);
    printf("LAST NAME");
    gotoxy(42,14);
    printf("USER NAME");
    gotoxy(42,17);
    printf("PASSWORD");
    gotoxy(42,20);
    printf("CONFIRM PASSWORD");
    gotoxy(42,23);
    printf("MOBILE NUMBER");
    gotoxy(42,26);
    printf("EMAIL");
    gotoxy(42,29);
    printf("BACKUP KEY");
    gotoxy(78,29);
    printf(" DATA KEY ");
    gotoxy(42,32);
    printf("LIBRARY NAME");
    gotoxy(42,35);
    printf("ACCOUNT TYPE");
    field_of_mainmenu(60,8);
    field_of_mainmenu(60,11);
    field_of_mainmenu(60,14);
    field_of_mainmenu(60,17);
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    field_of_mainmenu(60,26);
    field_of_mainmenu(60,29);
    field_of_mainmenu(60,32);
    field_of_mainmenu(60,35);
    Bk_color(28,1);
    back_freame(78,88,28,30);
    Bk_color(28,15);
    gotoxy(78,29);
    printf("  DATA KEY");
    newaccount.account_type=account_type;
    Show_cursor(10);
    Bk_color(252,0);
    if(account_type=='a')
    {
        gotoxy(61,35);
        printf("ADMINISTRATOR ACCOUNT");
    }
    if(account_type=='g')
    {
        gotoxy(61,35);
        printf("GUEST ACCOUNT");
    }
    if(account_type=='g')
    {
        gotoxy(61,32);
        printf("%s",guser.library_name);
    }
    re=input_string_undermainmenu(newaccount.first_name,46,61,8);
    if(re==202)
    {
        return 0;
    }
    re=input_string_undermainmenu(newaccount.last_name,46,61,11);
    if(re==202)
    {
        return 0;
    }
    if(account_type=='g')
    {
        strcpy(newaccount.guest_admin,guser.username);
    }
    reenter_username:
    if(account_type=='a')
    {
        re=input_Number_char_undermainmenu(newaccount.username,46,61,14);
        if(re==202)
        {
            return 0;
        }
        if(chack_account(newaccount.username,'\0','\0','\0')==1)
        {
            Bk_color(28,15);
            field_of_mainmenu(60,14);
            rec_MSGinM("USERNAME ALREADY TAKEN",40,109,38);
            Bk_color(28,15);
            print_date_time(74,95,41,61,14);
            Bk_color(28,1);
            field_of_mainmenu(45,38);
            Bk_color(252,15);
            goto reenter_username;
        }
    }
    else
    {
        re=input_Number_char_undermainmenu(newaccount.guest_username,46,61,14);
        if(re==202)
        {
            return 0;
        }
        if(chack_account(newaccount.guest_username,'\0','\0','\0')==1)
        {
            Bk_color(28,15);
            field_of_mainmenu(60,14);
            rec_MSGinM("USERNAME ALREADY TAKEN",40,109,38);
            Bk_color(28,15);
            print_date_time(74,95,41,61,14);
            Bk_color(28,1);
            field_of_mainmenu(45,38);
            Bk_color(252,15);
            goto reenter_username;
        }
    }
    reenter_pass:
    re=input_password_undermainmenu(newaccount.password,46,61,17);
    if(re==202)
    {
        return 0;
    }
    re=input_password_undermainmenu(confirm_pass,46,61,20);
    if(re==202)
    {
        return 0;
    }
    if(strcmp(confirm_pass,newaccount.password)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,17);
        field_of_mainmenu(60,20);
        //gotoxy(65,37);
        rec_MSGinM("BOTH PASSWORD DO NOT MATCH",40,109,38);
        Bk_color(28,15);
        print_date_time(74,95,41,61,17);
        Bk_color(28,1);
        field_of_mainmenu(45,38);
        Bk_color(252,15);
        goto reenter_pass;
    }
    re=input_mobile(newaccount.mobile,10,61,23);
    if(re==202)
    {
        return 202;
    }
    re=input_email_undermainmenu(newaccount.email,46,61,26);
    if(re==202)
    {
        return 202;
    }
    if(gsetting.auto_gernate_backupkey)
    {
        regarnate_backup_key:
        get_new_backup_key(newaccount.Backup_key,15);
        if(verify_keys(newaccount.Backup_key,15)==0)
        {
            goto regarnate_backup_key;
        }
        gotoxy(61,29);
        printf("%s",newaccount.Backup_key);
    }
    else
    {
        reenter_backup_key:
        input_mobile(newaccount.Backup_key,15,61,29);
        if(chack_keys(newaccount.Backup_key,'b')==1)
        {
            Bk_color(28,15);
            field_of_mainmenu(60,29);
            Bk_color(28,1);
            back_freame(78,88,28,30);
            Bk_color(28,15);
            gotoxy(78,29);
            printf("  DATA KEY");
            rec_MSGinM("BACKUP KEY IS ALREADY TAKEN\a",40,109,38);
            Bk_color(28,15);
            print_date_time(74,95,41,61,29);
            Bk_color(28,1);
            field_of_mainmenu(45,38);
            Bk_color(252,0);
            goto reenter_backup_key;
        }

    }
    if(account_type=='a')
    {
        if(gsetting.auto_gernate_datakey)
        {
            regarnate_data_key:
            get_new_data_key(newaccount.Data_key,15);
            if(verify_keys(newaccount.Data_key,15)==0)
            {
                goto regarnate_data_key;
            }
            gotoxy(90,29);
            printf("%s",newaccount.Data_key);
        }
        else
        {
            reenter_data_key:
            input_mobile(newaccount.Data_key,15,90,29);
            if(chack_keys(newaccount.Data_key,'d')==1)
            {
                Bk_color(28,15);
                back_freame(89,107,28,30);
                rec_MSGinM("DATA KEY IS ALREADY TAKEN\a",40,109,38);
                Bk_color(28,15);
                print_date_time(74,95,41,90,29);
                Bk_color(28,1);
                field_of_mainmenu(45,38);
                Bk_color(252,0);
                goto reenter_data_key;
            }
        }

    }
    if(account_type=='g')
    {
        strcpy(newaccount.Data_key,guser.Data_key);
        gotoxy(90,29);
        printf("%s",newaccount.Data_key);
    }
    if(account_type=='a')   // input library name only in admin account
    {
        reinput_library_name:
        re=input_string_undermainmenu(newaccount.library_name,46,61,32);
        if(re==202)
        {
            return 0;
        }
        if(gsetting.warnings==1)
        {
            if(chack_library_name(newaccount.library_name)==1)
            {
                Bk_color(28,1);
                Strip_of_notificationbar(42,38);
                Bk_color(28,15);
                re=MessageBoxA(NULL," The account of this library is already created"," Warning",54);
                Clear_buffer();
                if(re==TryAgain)
                {
                    Bk_color(28,15);
                    field_of_mainmenu(60,32);
                    Bk_color(252,0);
                    goto reinput_library_name;
                }
                Bk_color(28,1);
                Strip_of_notificationbar(42,38);
            }
        }

        re=make_folder_under_path(main_path,newaccount.Data_key,newaccount.main_folderPath,1);
        if(re!=0)
        {
            Hide_cursor();
            Bk_color(28,15);
            rec_MSGinM("AN ERROR OCCURRED, THE ACCOUNT COULD NOT BE CREATED",40,109,38);
            Bk_color(28,15);
            print_date_time(74,95,41,61,17);
            Clear_buffer();
            return 0;
        }
        newaccount.add_new_books=1;
        newaccount.Delete_books=1;
        newaccount.Change_book_name=1;
        newaccount.Change_category=1;
        newaccount.Change_writer_name=1;
        newaccount.Change_rent_rate=1;
        newaccount.Change_extra_charge=1;
        newaccount.Change_book_qty=1;
        newaccount.Change_book_price=1;
        newaccount.Change_rack_number=1;
        newaccount.View_all_book=1;
        newaccount.export_all_books=1;
        newaccount.issue_book_permission=1;
        newaccount.submit_books=1;
        newaccount.view_issued_books=1;
        newaccount.view_invoices=1;
        newaccount.view_all_invoices=1;
        newaccount.export_issued_book=1;
        newaccount.Export_all_invoice=1;
        newaccount.add_new_students=1;
        newaccount.remove_students=1;
        newaccount.search_students=1;
        newaccount.change_student_name=1;
        newaccount.chnage_father_name=1;
        newaccount.change_mobile_number=1;
        newaccount.chnage_roll_number=1;
        newaccount.view_all_students=1;
        newaccount.Export_student_data=1;
        newaccount.add_new_categoryes=1;
        newaccount.remove_categoryes=1;
        newaccount.search_categoryes=1;
        newaccount.view_all_categoryes=1;
    }
    else
    {
        strcpy(newaccount.library_name,guser.library_name);
        strcpy(newaccount.main_folderPath,guser.main_folderPath);
        newaccount.add_new_books=0;
        newaccount.Delete_books=0;
        newaccount.Change_book_name=0;
        newaccount.Change_category=0;
        newaccount.Change_writer_name=0;
        newaccount.Change_rent_rate=0;
        newaccount.Change_extra_charge=0;
        newaccount.Change_book_qty=0;
        newaccount.Change_book_price=0;
        newaccount.Change_rack_number=0;
        newaccount.View_all_book=0;
        newaccount.export_all_books=0;
        newaccount.issue_book_permission=0;
        newaccount.submit_books=0;
        newaccount.view_issued_books=0;
        newaccount.view_invoices=0;
        newaccount.view_all_invoices=0;
        newaccount.export_issued_book=0;
        newaccount.Export_all_invoice=0;
        newaccount.add_new_students=0;
        newaccount.remove_students=0;
        newaccount.search_students=0;
        newaccount.change_student_name=0;
        newaccount.chnage_father_name=0;
        newaccount.change_mobile_number=0;
        newaccount.chnage_roll_number=0;
        newaccount.view_all_students=0;
        newaccount.Export_student_data=0;
        newaccount.add_new_categoryes=0;
        newaccount.remove_categoryes=0;
        newaccount.search_categoryes=0;
        newaccount.view_all_categoryes=0;
    }
    if(account_type=='a')
    {
        make_folder_under_path(newaccount.main_folderPath,"Brightgoal_Books.dat",newaccount.bookpath,0);
        make_folder_under_path(newaccount.main_folderPath,"Brightgoal_Students.dat",newaccount.stdpath,0);
        make_folder_under_path(newaccount.main_folderPath,"Brightgoal_IssueBooks.dat",newaccount.issuepath,0);
        make_folder_under_path(newaccount.main_folderPath,"Brightgoal_Categorie.dat",newaccount.categoriepath,0);
        make_folder_under_path(newaccount.main_folderPath,"Bill_Invoice.dat",newaccount.invoice_path,0);
        fp=fopen(newaccount.bookpath,"wb");
        if(fp==NULL)
        {
            MessageBoxA(NULL," An error occurred, the account could not be created"," ERROR",16);
            Clear_buffer();
            return 0;
        }
        else
        {
            fclose(fp);
        }
        fp=fopen(newaccount.stdpath,"wb");
        if(fp==NULL)
        {
            MessageBoxA(NULL," An error occurred, the account could not be created"," ERROR",16);
            Clear_buffer();
            return 0;
        }
        else
        {
            fclose(fp);
        }
        fp=fopen(newaccount.issuepath,"wb");
        if(fp==NULL)
        {
            MessageBoxA(NULL," An error occurred, the account could not be created"," ERROR",16);
            Clear_buffer();
            return 0;
        }
        else
        {
            fclose(fp);
        }
        fp=fopen(newaccount.categoriepath,"wb");
        if(fp==NULL)
        {
            MessageBoxA(NULL," An error occurred, the account could not be created"," ERROR",16);
            Clear_buffer();
            return 0;
        }
        else
        {
            fclose(fp);
        }
        fp=fopen(newaccount.invoice_path,"wb");
        if(fp==NULL)
        {
            MessageBoxA(NULL," An error occurred, the account could not be created"," ERROR",16);
            Clear_buffer();
            return 0;
        }
        else
        {
            fclose(fp);
        }
    }
    else
    {
        strcpy(newaccount.bookpath,guser.bookpath);
        strcpy(newaccount.stdpath,guser.stdpath);
        strcpy(newaccount.issuepath,guser.issuepath);
        strcpy(newaccount.categoriepath,guser.categoriepath);
        strcpy(newaccount.invoice_path,guser.invoice_path);
    }
    if(account_type=='a')
    {
        for(i=0;i<10;i++)
        {
            newaccount.guest_admin[i]='\0';
            newaccount.guest_username[i]='\0';
        }
    }
    if(account_type=='g')
    {
        for(i=0;i<10;i++)
        {
            newaccount.username[i]='\0';
        }
    }
    if(account_type=='g')
    {
        if(gsetting.set_permission_while_creating_acoount)
        {
            re=get_permission_of_guest_account(&newaccount);
            if(re==202)
            {
                return 0;
            }
        }
    }
    encryption(newaccount.username);
    encryption(newaccount.password);
    encryption(newaccount.library_name);
    encryption(newaccount.first_name);
    encryption(newaccount.last_name);
    encryption(newaccount.Data_key);
    encryption(newaccount.Backup_key);
    encryption(newaccount.guest_admin);
    encryption(newaccount.guest_username);
    mkdir(main_path);
    fp=fopen(userpath,"ab");
    if(fp==NULL)
    {
        Hide_cursor();
        Bk_color(28,15);
        if(account_type=='g')
        {
            if(gsetting.set_permission_while_creating_acoount)
                re=MessageBoxA(NULL," An error occurred, the account could not be created"," Error",16);
            else
                rec_MSGinM("AN ERROR OCCURRED, THE ACCOUNT COULD NOT BE CREATED",40,109,38);
        }
        else
            rec_MSGinM("AN ERROR OCCURRED, THE ACCOUNT COULD NOT BE CREATED",40,109,38);
        fclose(fp);
        Bk_color(28,15);
        print_date_time(74,95,41,61,17);
        Clear_buffer();
        return 0;
    }
    fwrite(&newaccount,sizeof(struct user_accounts),1,fp);
    fclose(fp);
    Hide_cursor();
    Bk_color(28,15);
    if(account_type=='g')
    {
        if(gsetting.set_permission_while_creating_acoount)
        {
            MessageBoxA(NULL," Account successfully created"," Notification",0);
            Clear_buffer();
        }
        else
        {
            rec_MSGinM("ACCOUNT SUCCESSFULLY CREATED",40,109,38);
            print_date_time(74,95,41,61,17);
            Clear_buffer();
        }

    }
    else
    {
        rec_MSGinM("ACCOUNT SUCCESSFULLY CREATED",40,109,38);
        print_date_time(74,95,41,61,17);
        Clear_buffer();
    }
    Bk_color(28,15);
}
int chack_library_name(char *library_name)
{
    struct user_accounts chack;
    FILE *fp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&chack,sizeof(struct user_accounts),1,fp)>0)
    {
        decryption(chack.library_name);
        if(match_two_string(chack.library_name,library_name)==1)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int gernate_key_int(int *key,int lenth)
{
    int i,temp,number;
    temp=0;
    for(i=1;i<=lenth;i++)
    {
        reset:
        number=(rand()%10);
        if(number==0 && i==1)
            goto reset;
        temp=((temp*10)+number);
    }
    *key=temp;
    return number;
}
int gernate_key_char(char *key,int lenth)
{
    int i,temp,number;
    for(i=0;i<lenth;i++)
    {
        temp=rand()%10;
        key[i]=int_to_char_int(temp);
    }
    key[i]='\0';
    return 1;
}
int verify_keys(char *key,int lenth)
{
    int i,count=0;
    for(i=0;i<lenth;i++)
    {
        if(key[i]>=48 && key[i]<=57)
        {
            count++;
        }
    }
    if(i==lenth && count==lenth && key[i]=='\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int make_folder_under_path(char *path,char *folder_name,char *recive_completePath,int f_creation)
{
    char c_path[300];
    int i;
    strcpy(c_path,path);
    i=strlen(c_path);
    c_path[i]=92;
    i++;
    c_path[i]=92;
    i++;
    c_path[i]='\0';
    strcat(c_path,folder_name);
    if(f_creation!=0)
        i=mkdir(c_path);
    if(recive_completePath!='\0')
    {
        strcpy(recive_completePath,c_path);
    }
    return i;
}
int chack_account(char *user_name,char *backup_key,char *data_key,char *library_name)
{
    FILE *fp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&chacking,sizeof(struct user_accounts),1,fp)>0)
    {

        if(user_name!='\0')
        {
            decryption(chacking.guest_username);
            decryption(chacking.username);
            if(match_two_string(chacking.username,user_name)==1)
            {
                fclose(fp);
                decryption(chacking.username);
                decryption(chacking.password);
                decryption(chacking.library_name);
                decryption(chacking.first_name);
                decryption(chacking.last_name);
                decryption(chacking.Data_key);
                decryption(chacking.Backup_key);
                decryption(chacking.guest_admin);
                decryption(chacking.guest_username);
                return 1;
            }
            else if(match_two_string(chacking.guest_username,user_name)==1)
            {
                fclose(fp);
                decryption(chacking.username);
                decryption(chacking.password);
                decryption(chacking.library_name);
                decryption(chacking.first_name);
                decryption(chacking.last_name);
                decryption(chacking.Data_key);
                decryption(chacking.Backup_key);
                decryption(chacking.guest_admin);
                decryption(chacking.guest_username);
                return 1;
            }
        }
        else if(data_key!='\0')
        {
            decryption(chacking.Data_key);
            if(match_two_string(chacking.Data_key,data_key)==1)
            {
                fclose(fp);
                decryption(chacking.username);
                decryption(chacking.password);
                decryption(chacking.library_name);
                decryption(chacking.first_name);
                decryption(chacking.last_name);
                decryption(chacking.Data_key);
                decryption(chacking.Backup_key);
                decryption(chacking.guest_admin);
                decryption(chacking.guest_username);
                return 1;
            }
        }
        else if(backup_key!='\0')
        {
            decryption(chacking.Backup_key);
            if(match_two_string(chacking.Backup_key,backup_key)==1)
            {
                fclose(fp);
                decryption(chacking.username);
                decryption(chacking.password);
                decryption(chacking.library_name);
                decryption(chacking.first_name);
                decryption(chacking.last_name);
                decryption(chacking.Data_key);
                decryption(chacking.Backup_key);
                decryption(chacking.guest_admin);
                decryption(chacking.guest_username);
                return 1;
            }
        }
        else if(library_name!='\0')
        {
            decryption(chacking.library_name);
            if(match_two_string(library_name,chacking.library_name)==1)
            {
                fclose(fp);
                decryption(chacking.username);
                decryption(chacking.password);
                decryption(chacking.library_name);
                decryption(chacking.first_name);
                decryption(chacking.last_name);
                decryption(chacking.Data_key);
                decryption(chacking.Backup_key);
                decryption(chacking.guest_admin);
                decryption(chacking.guest_username);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}
int chack_account_at_logintime(char *user)
{
    FILE *fp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&guser,sizeof(struct user_accounts),1,fp)>0)
    {
        decryption(guser.username);
        decryption(guser.guest_username);
        if(match_two_string(user,guser.username)==1)
        {
            fclose(fp);
            decryption(guser.username);
            decryption(guser.password);
            decryption(guser.library_name);
            decryption(guser.first_name);
            decryption(guser.last_name);
            decryption(guser.Data_key);
            decryption(guser.Backup_key);
            decryption(guser.guest_admin);
            decryption(guser.guest_username);
            return 1;
        }
        else if(match_two_string(user,guser.guest_username)==1)
        {
            fclose(fp);
            decryption(guser.username);
            decryption(guser.password);
            decryption(guser.library_name);
            decryption(guser.first_name);
            decryption(guser.last_name);
            decryption(guser.Data_key);
            decryption(guser.Backup_key);
            decryption(guser.guest_admin);
            decryption(guser.guest_username);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int get_new_backup_key(char *key,int lenth)
{
    FILE *fp;
    char temp[65];
    struct user_accounts chack;
    regernate:
        gernate_key_char(temp,lenth);
        fp=fopen(userpath,"rb");
        if(fp==NULL)
        {
            fclose(fp);
            strcpy(key,temp);
            return 404;
        }
        while(fread(&chack,sizeof(struct user_accounts),1,fp)>0)
        {
            decryption(chack.Backup_key);
            if(match_two_string(temp,chack.Backup_key)==1)
            {
                fclose(fp);
                goto regernate;
            }
        }
        strcpy(key,temp);
        return 1;
}
int get_new_data_key(char *key,int lenth)
{
    FILE *fp;
    char temp[65];
    struct user_accounts chack;
    regernate:
        gernate_key_char(temp,lenth);
        fp=fopen(userpath,"rb");
        if(fp==NULL)
        {
            fclose(fp);
            strcpy(key,temp);
            return 404;
        }
        while(fread(&chack,sizeof(struct user_accounts),1,fp)>0)
        {
            decryption(chack.Data_key);
            if(match_two_string(temp,chack.Data_key)==1)
            {
                fclose(fp);
                goto regernate;
            }
        }
        strcpy(key,temp);
        return 1;
}
int chack_keys(char *key,int type)
{
    FILE *fp;
    struct user_accounts chack;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    while(fread(&chack,sizeof(struct user_accounts),1,fp)>0)
    {
        if(type==68 || type==100)
        {
            decryption(chack.Data_key);
            if(match_two_string(chack.Data_key,key)==1)
            {
                fclose(fp);
                return 1;
            }
        }
        if(type==66 || type==98)
        {
            decryption(chack.Backup_key);
            if(match_two_string(key,chack.Backup_key)==1)
            {
                fclose(fp);
                return 1;
            }
        }
    }
    return 0;
}
int Login(int type)
{
    int re;
    char username[60];
    char password[60];
    Bk_color(180,11);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    setcolor(1);
    working_area_background();
    Bk_color(197,15);
    gotoxy(72,4);
    printf("LOGIN PANNEL");
    Bk_color(28,15);
    gotoxy(42,20);
    printf("ENTER USER NAME");
    gotoxy(42,23);
    printf("ENTER PASSWORD");
    field_of_mainmenu(60,20);
    field_of_mainmenu(60,23);
    back_freame(60,107,19,21);
    back_freame(60,107,22,24);
    Show_cursor(8);
    reenter_username:
    re=input_Number_char_undermainmenu(username,46,61,20);
    if(re==202)
    {
        return 202;
    }
    if(chack_account_at_logintime(username)!=1)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,20);
        rec_MSGinM("INVALID USERNAME",40,109,37);
        Bk_color(28,15);
        print_date_time(74,95,41,61,20);
        Bk_color(28,1);
        Strip_of_notificationbar(42,37);
        Bk_color(252,15);
        goto reenter_username;
    }
    if(type=='g')
    {
        if(guser.account_type=='g')
        {
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            rec_MSGinM("ACCEPT ONLY ADMINISTRATOR ACCOUNT",40,109,37);
            Bk_color(28,15);
            print_date_time(74,95,41,61,20);
            Bk_color(28,1);
            Strip_of_notificationbar(42,37);
            Bk_color(252,15);
            goto reenter_username;
        }
    }
    if(type=='a')
    {
        if(guser.account_type=='a')
        {
            Bk_color(28,15);
            field_of_mainmenu(60,20);
            rec_MSGinM("ACCEPT ONLY GUEST ACCOUNT",40,109,37);
            Bk_color(28,15);
            print_date_time(74,95,41,61,20);
            Bk_color(28,1);
            Strip_of_notificationbar(42,37);
            Bk_color(252,15);
            goto reenter_username;
        }
    }
    reenter_password:
    re=input_password_undermainmenu(password,46,61,23);
    if(re==202)
    {
        return 202;
    }
    if(strcmp(guser.password,password)!=0)
    {
        Bk_color(28,15);
        field_of_mainmenu(60,23);
        rec_MSGinM("INCORRECT PASSWORD",40,109,37);
        Bk_color(28,15);
        print_date_time(74,95,41,61,23);
        Bk_color(28,1);
        Strip_of_notificationbar(42,37);
        Bk_color(252,15);
        goto reenter_password;
    }
    else
    {
        Hide_cursor();
        Bk_color(28,15);
        rec_MSGinM("   LOGIN SUCCESSFULL",40,109,37);
        Bk_color(28,15);
        print_date_time(74,95,41,61,23);
        Bk_color(28,1);
        Strip_of_notificationbar(42,37);
        return 1;
    }
}
void notification()
{
    int admin_account,guest_account;
    int total_book,total_student,total_issue_book,total_category,total_invoice;
    ind_back_freame(40,109,3,5,117,180,12);
    Bk_color(197,15);
    gotoxy(70,4);
    printf("NOTIFICATIONS");
    Bk_color(180,7);
    working_area_background();
    Bk_color(117,1);
    if(login_status==0)
    {
        gotoxy(42,7);
        printf("Last five login by");
        notification_strip(42,8);
        if(chack_last_login()==1)
        {
            gotoxy(44,10);
            if(strlen(glogs.Name_1)>4)
            {
                printf("%c  %s",249,glogs.Name_1);
            }
            gotoxy(44,12);
            if(strlen(glogs.Name_2)>4)
            {
                printf("%c  %s",249,glogs.Name_2);
            }
            gotoxy(44,14);
            if(strlen(glogs.Name_3)>4)
            {
                printf("%c  %s",249,glogs.Name_3);
            }
            gotoxy(44,16);
            if(strlen(glogs.Name_4)>4)
            {
                printf("%c  %s",249,glogs.Name_4);
            }
            gotoxy(44,18);
            if(strlen(glogs.Name_5)>4)
            {
                printf("%c  %s",249,glogs.Name_5);
            }
        }
        else
        {
            gotoxy(44,10);
            printf("No Record");
        }
        total_account(&admin_account,&guest_account);
        gotoxy(42,24);
        printf("Account Information");
        notification_strip(42,25);
        gotoxy(44,27);
        printf("%c Total Administrator Acoount in Library : %d",249,admin_account);
        gotoxy(44,29);
        printf("%c Total Guest Acoount in Library : %d",249,guest_account);
    }
    else
    {
        total_book=total_books();
        total_student=total_students();
        total_issue_book=total_issued_books();
        total_category=total_categoryes();
        total_invoice=total_invoices();
        gotoxy(42,7);
        printf("Library Information");
        notification_strip(42,8);
        gotoxy(44,10);
        printf("%c Total Book's in library [ By Type ]        : %d",249,total_book);
        gotoxy(44,12);
        printf("%c Total Student in library                   : %d",249,total_student);
        gotoxy(44,14);
        printf("%c Total issued book's                        : %d",249,total_issue_book);
        gotoxy(44,16);
        printf("%c Total Number of book's category in library : %d",249,total_category);
        gotoxy(44,18);
        printf("%c Total Invoice                              : %d",249,total_invoice);
    }
}
int total_invoices()
{
    FILE *fp;
    int count=0;
    fp=fopen(guser.invoice_path,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 0;
    }
    while(fread(&ginvoice,sizeof(struct Invoice),1,fp)>0)
    {
        count++;
    }
    fclose(fp);
    return count;
}
int total_categoryes()
{
    FILE *fp;
    int count=0;
    fp=fopen(guser.categoriepath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 0;
    }
    while(fread(&gcategorie,sizeof(struct categorie),1,fp)>0)
    {
        count++;
    }
    fclose(fp);
    return count;
}
int total_issued_books()
{
    FILE *fp;
    int count=0;
    fp=fopen(guser.issuepath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 0;
    }
    while(fread(&gissuedata,sizeof(struct issue_books),1,fp)>0)
    {
        count++;
    }
    fclose(fp);
    return count;
}
int total_students()
{
    FILE *fp;
    int count=0;
    fp=fopen(guser.stdpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 0;
    }
    while(fread(&gstudent,sizeof(struct students),1,fp)>0)
    {
        count++;
    }
    fclose(fp);
    return count;
}
int total_books()
{
    FILE *fp;
    int count=0;
    fp=fopen(guser.bookpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 0;
    }
    while(fread(&gbookdata,sizeof(struct books),1,fp)>0)
    {
        count++;
    }
    fclose(fp);
    return count;
}
void notification_strip(int x,int y)
{
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
}
int total_account(int *admin,int *guest)
{
    struct user_accounts total_ac;
    int gues=0,adm=0;
    FILE *fp;
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        *admin=0;
        *guest=0;
        return 404;
    }
    while(fread(&total_ac,sizeof(struct user_accounts),1,fp)>0)
    {
        if(total_ac.account_type=='a')
        {
            adm++;
        }
        if(total_ac.account_type=='g')
        {
            gues++;
        }
    }
    *admin=adm;
    *guest=gues;
    return 1;
}
int update_logs(char *name)
{
    FILE *fp;
    fp=fopen(Last_logins,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        glogs.Name_1[0]='\0';
        glogs.Name_2[0]='\0';
        glogs.Name_3[0]='\0';
        glogs.Name_4[0]='\0';
        glogs.Name_5[0]='\0';
        strcpy(glogs.Name_1,name);
        fp=fopen(Last_logins,"wb");
        if(fp==NULL)
        {
            return 404;
        }
        fwrite(&glogs,sizeof(struct last_login),1,fp);
        fclose(fp);
        return 1;
    }
    if(fread(&glogs,sizeof(struct last_login),1,fp)>0)
    {
        fclose(fp);
        strcpy(glogs.Name_5,glogs.Name_4);
        strcpy(glogs.Name_4,glogs.Name_3);
        strcpy(glogs.Name_3,glogs.Name_2);
        strcpy(glogs.Name_2,glogs.Name_1);
        strcpy(glogs.Name_1,name);
        fp=fopen(Last_logins,"wb");
        if(fp==NULL)
        {
            return 404;
        }
        fwrite(&glogs,sizeof(struct last_login),1,fp);
        fclose(fp);
    }
    else
    {
        fclose(fp);
        glogs.Name_1[0]='\0';
        glogs.Name_2[0]='\0';
        glogs.Name_3[0]='\0';
        glogs.Name_4[0]='\0';
        glogs.Name_5[0]='\0';
        strcpy(glogs.Name_1,name);
        fp=fopen(Last_logins,"wb");
        if(fp==NULL)
        {
            return 404;
        }
        fwrite(&glogs,sizeof(struct last_login),1,fp);
        fclose(fp);
    }

}
int chack_last_login()
{
    FILE *fp;
    fp=fopen(Last_logins,"rb");
    if(fp==NULL)
    {
        return 404;
    }
    if(fread(&glogs,sizeof(struct last_login),1,fp)>0)
    {
        fclose(fp);
        return 1;
    }
    else
    {
        fclose(fp);
        return 0;
    }
}
int input_Number_char_undermainmenu(char *a,int lenth,int x,int y)
{
    int i=0,return_value;
    for(i=0;i<lenth;i++)
    {
        abc:
        Bk_color(28,15);
        print_date_time(74,95,41,x,y);
        Bk_color(252,0);
        gotoxy(x,y);
        a[i]=getche();
        if(a[i]==27)
        {
            a[i]='\0';
            return 202;
        }
        if(a[i]==-32)
        {
            a[i]=getche();
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]==8)
        {
            if(i==0)
            {
                goto abc;
            }
            else
            {
            i--;
            x--;
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
            }

        }
        if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
        {

        }
        else if(a[i]==32 && i!=0 && a[i-1]!=' ')
        {

        }
        else if(a[i]>=48 && a[i]<=57)
        {

        }
        else if(a[i]==13 && i>=5)
        {
            a[i]='\0';
            return 1;
        }
        else if(a[i]==13 && i<6)
        {
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Enter minimum 5 character's"," Warning",48);
                Clear_buffer();
            }
            goto abc;
        }
        else
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        x++;
    }
    a[i]='\0';
    return a;
}
int input_num_and_char_undermainmenu(char *a,int lenth,int minlenth,int x,int y)
{
    int i=0,return_value;
    for(i=0;i<lenth;i++)
    {
        abc:
        Bk_color(28,15);
        print_date_time(74,95,41,x,y);
        Bk_color(252,0);
        gotoxy(x,y);
        a[i]=getche();
        if(a[i]==27)
        {
            a[i]='\0';
            return 202;
        }
        if(a[i]==-32)
        {
            a[i]=getche();
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]==8)
        {
            if(i==0)
            {
                goto abc;
            }
            else
            {
            i--;
            x--;
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
            }

        }
        if(i==0 && a[i]=='0')
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
        {

        }
        else if(a[i]==32 && i!=0 && a[i-1]!=' ')
        {

        }
        else if(a[i]>=48 && a[i]<=57)
        {

        }
        else if(a[i]==13 && i>=minlenth)
        {
            a[i]='\0';
            return 1;
        }
        else if(a[i]==13 && i<minlenth)
        {
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Enter More character's Now"," Warning",48);
                Clear_buffer();
            }
            goto abc;
        }
        else
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        x++;
    }
    a[i]='\0';
    return a;
}
int input_string_undermainmenu(char *a,int lenth,int x,int y)
{
    int i=0,return_value;
    for(i=0;i<lenth;i++)
    {
        abc:
        Bk_color(28,15);
        print_date_time(74,95,41,x,y);
        Bk_color(252,0);
        gotoxy(x,y);
        a[i]=getche();
        if(a[i]==-32)
        {
            a[i]=getche();
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]==27)
        {
            a[i]='\0';
            return 202;
        }
        if(a[i]==8)
        {
            if(i==0)
            {
                goto abc;
            }
            else
            {
            i--;
            x--;
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
            }

        }
        if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
        {

        }
        else if(a[i]==32 && i!=0 && a[i-1]!=' ')
        {

        }
        else if(a[i]==13 && i>=5)
        {
            a[i]='\0';
            return 1;
        }
        else if(a[i]==13 && i<6)
        {
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Enter minimum 5 character's"," Warning",48);
                Clear_buffer();
            }
            goto abc;
        }
        else
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        x++;
    }
    a[i]='\0';
    return a;
}
int input_mobile_undermainmenu(char *a,int lenth,int x,int y)
{
    int i=0,return_value;
    for(i=0;i<lenth;i++)
    {
        abc:
        Bk_color(28,15);
        print_date_time(74,95,41,x,y);
        Bk_color(252,0);
        gotoxy(x,y);
        a[i]=getche();
        if(a[i]==-32)
        {
            a[i]=getche();
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]==27)
        {
            a[i]='\0';
            return 202;
        }
        if(a[i]==8)
        {
            if(i==0)
            {
                goto abc;
            }
            else
            {
            i--;
            x--;
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
            }

        }
        if(i==0 && a[i]=='0')
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if((a[i]>=48 && a[i]<=57))
        {

        }
        else if(a[i]==13 && i==10)
        {
            a[i]='\0';
            return 1;
        }
        else if(a[i]==13 && i<6)
        {
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Enter minimum 10 character's"," Warning",48);
                Clear_buffer();
            }
            goto abc;
        }
        else
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        x++;
    }
    a[i]='\0';
    return a;
}
int input_charnumbers_undermainmenu(char *a,int lenth,int minlenth,int x,int y)
{
    int i=0,return_value;
    for(i=0;i<lenth;i++)
    {
        abc:
        Bk_color(28,15);
        print_date_time(74,95,41,x,y);
        Bk_color(252,0);
        gotoxy(x,y);
        a[i]=getche();
        if(a[i]==-32)
        {
            a[i]=getche();
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]=='0' && i==0)
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]==27)
        {
            a[i]='\0';
            return 202;
        }
        if(a[i]==8)
        {
            if(i==0)
            {
                goto abc;
            }
            else
            {
            i--;
            x--;
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
            }

        }
        if((a[i]>=48 && a[i]<=57))
        {

        }
        else if(a[i]==13 && i>=minlenth)
        {
            a[i]='\0';
            return 1;
        }
        else if(a[i]==13 && i<minlenth)
        {
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Enter More character's Now"," Warning",48);
                Clear_buffer();
            }
            goto abc;
        }
        else
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        x++;
    }
    a[i]='\0';
    return a;
}
int input_email_undermainmenu(char *a,int lenth,int x,int y)
{
    int i=0,return_value;
    int count=0;
    int tempx,tempy;
    int dot=0,last_position=0,last_atrate=0;
    tempx=x;
    tempy=y;
    creset:
    for(i=0;i<lenth;i++)
    {
        abc:
        Bk_color(28,15);
        print_date_time(74,95,41,x,y);
        Bk_color(252,0);
        gotoxy(x,y);
        a[i]=getche();
        if(a[i]==27)
        {
            a[i]='\0';
            return 202;
        }
        if(a[i]==-32)
        {
            a[i]=getche();
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]==8)
        {
            if(i==0)
            {
                goto abc;
            }
            else
            {
            i--;
            x--;
            if(a[i]=='@')
            {
                count=0;
                last_atrate=0;
            }
            if(a[i]=='.')
                last_position=0;
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
            }

        }
        if((a[i]>='a' && a[i]<='z'))
        {

        }
        else if( a[i]=='.' && i!=0 && a[i-1]!='.' && a[i-1]!='@' && a[i-1]!='-')
        {
            dot++;
            last_position=i;
        }
        else if(a[i]=='@' && i!=0 && a[i-1]!='@' && a[i-1]!='.' && a[i-1]!='-' && count<1)
        {
            count++;
            last_atrate=i;
        }
        else if(a[i]>='0' && a[i]<='9')
        {

        }
        else if( a[i]=='-' && i!=0 && a[i-1]!='-' && a[i-1]!='@' && a[i-1]!='.')
        {

        }
        else if(a[i]==13 && i>=5 && dot!=0 && count!=0 && a[i-1]!='.' && a[i-1]!='@' && a[i-1]!='-' && last_position>last_atrate)
        {
            a[i]='\0';
            if((a[last_position+1]=='\0' || a[last_position+2]=='\0'))
            {
                gotoxy(x,y);
                printf("%c",256);
                if(gsetting.warnings)
                {
                    return_value=MessageBoxA(NULL,"  Invalid Email address"," Warning",48);
                    Clear_buffer();
                }
                goto abc;
            }
            return 1;
        }
        else
        {
            gotoxy(x,y);
            printf("%c",256);
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Invalid Email address"," Warning",48);
                Clear_buffer();
            }
            goto abc;
        }
        x++;
    }
    a[i]='\0';
    if( dot!=0 && count!=0 && a[i-1]!='.' && a[i-1]!='@' && a[i-1]!='-' && last_position>last_atrate)
    {
        if((a[last_position+1]!='\0' && a[last_position+2]!='\0'))
        {
            return a;
        }
        else
        {
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Invalid Email address"," Warning",48);
                Clear_buffer();
            }
            x=tempx;
            y=tempy;
            for(i=x;i<=x+lenth;i++)
            {
                gotoxy(i,y);
                printf("%c",256);
            }
            last_position=0;
            last_atrate=0;
            count=0;
            dot=0;
            goto creset;
        }
    }
    else
    {
        if(gsetting.warnings)
        {
            return_value=MessageBoxA(NULL,"  Invalid Email address"," Warning",48);
            Clear_buffer();
        }
        x=tempx;
        y=tempy;
        for(i=x;i<=x+lenth;i++)
        {
            gotoxy(i,y);
            printf("%c",256);
        }
        last_position=0;
        last_atrate=0;
        count=0;
        dot=0;
        goto creset;
    }
}
int input_date_undermainmenu(int *day1,int *month1,int *year1,int x,int y,int ex,int ey,int font_co,int bk_co,int error_bkco,int error_foco)
{
    int ch,return_value;
    int a,day=0,month=0,year=0,count=1,m,loop=0,i,j;
    m=x;
    Bk_color(255,7);
    gotoxy(x,y);
    printf("dd/mm/yyyy");
    restart:
    if(count==9)
    {
       *day1=day;
        *month1=month;
        *year1=year;
        return 1;
    }
    Bk_color(28,15);
    print_date_time(74,95,41,x,y);
    Bk_color(bk_co,font_co);
    gotoxy(x,y);
    ch=getche();
    systemback:
    if(ch==27)
    {
        *day1=0;
        *month1=0;
        *year1=0;
        return 202;
    }
    if(ch==-32)
    {
        ch=getche();
        gotoxy(x,y);
        printf("%c",256);
    }
    if(ch>=48 && ch<=57)
    {
        switch(ch)
        {
        case 48:
            a=0;
            break;
        case 49:
            a=1;
            break;
        case 50:
            a=2;
            break;
        case 51:
            a=3;
            break;
        case 52:
            a=4;
            break;
        case 53:
            a=5;
            break;
        case 54:
            a=6;
            break;
        case 55:
            a=7;
            break;
        case 56:
            a=8;
            break;
        case 57:
            a=9;
            break;
        }
        if(count<=2)
        {
            day=(day*10)+a;
            count++;
            x++;
            if(count==3)
            {
                printf("/");
                x++;
            }
            if(count==3)
            {

                    if(day>31 || day<1)
                    {
                                ch=8;
                                loop=1;
                                if(gsetting.warnings)
                                {
                                    return_value=MessageBoxA(NULL,"  Invalid Day"," Warning",48);
                                    Clear_buffer();
                                }
                                Bk_color(bk_co,font_co);
                                goto systemback;
                    }
            }
            goto restart;
        }
        else if(count<=4)
        {
            month=(month*10)+a;
            count++;
            x++;
            if(count==5)
            {
                x++;
                printf("/");
            }
            if(count==5)
            {
                if(month>12 || month<1)
                {
                            ch=8;
                            loop=1;
                            if(gsetting.warnings)
                            {
                                return_value=MessageBoxA(NULL,"  Invalid Month"," Warning",48);
                                Clear_buffer();
                            }
                            Bk_color(bk_co,font_co);
                            goto systemback;
                }
            }
            if(count==5)
            {
                if(day>28)
                {
                    if(month==2)
                    {
                            ch=8;
                            loop=1;
                            if(gsetting.warnings)
                            {
                                return_value=MessageBoxA(NULL,"  Invalid Month"," Warning",48);
                                Clear_buffer();
                            }
                            Bk_color(bk_co,font_co);
                            goto systemback;
                    }
                }
                if(day>30)
                {
                    if(month==4 || month==6 || month==9 || month==11)
                    {
                            ch=8;
                            loop=1;
                            if(gsetting.warnings)
                            {
                                return_value=MessageBoxA(NULL,"  Invalid Month"," Warning",48);
                                Clear_buffer();
                            }
                            Bk_color(bk_co,font_co);
                            goto systemback;
                    }
                }
            }
            goto restart;
        }
        else if(count<=8)
        {
            year=(year*10)+a;
            count++;
            x++;
            if(count==9)
            {
                if(year<1640)
                {
                            ch=8;
                            loop=3;
                            if(gsetting.warnings)
                            {
                                return_value=MessageBoxA(NULL,"  Invalid Year"," Warning",48);
                                Clear_buffer();
                            }
                            Bk_color(bk_co,font_co);
                            goto systemback;
                }
            }
            goto restart;
        }
        else
        {
            *day1=day;
            *month1=month;
            *year1=year;
            return 1;
        }
    }
    else if(ch==13)
    {
        if(day==0 || month==0 || year<1620)
        {
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Invalid Date"," Warning",48);
                Clear_buffer();
            }
            gotoxy(x,y);
            printf("%c",256);
            goto restart;
        }
        *day1=day;
        *month1=month;
        *year1=year;
        return 1;
    }
    else if(ch==8)
    {
        gotoxy(x,y);
        printf("%c",256);
        if(count>1)
        {
            count--;
        }
        if(count>=5 && count<=8)
        {
            year=year/10;
        }
        if(count>=3 && count<=4)
        {
            month=month/10;
        }
        if(count>=1 && count<=2)
        {
            day=day/10;
        }
        if(count==4)
        {
            gotoxy(x,y);
            printf("%c",256);
            x--;
            gotoxy(x,y);
            printf("%c",256);
        }
        if(count==2)
        {
            gotoxy(x,y);
            printf("%c",256);
            x--;
            gotoxy(x,y);
            printf("%c",256);
        }
        if(x>m)
        {
            x--;
            gotoxy(x,y);
            printf("%c",256);
        }
        if(loop==0)
        goto restart;
        else
        {
            while(loop)
            {
                loop--;
                goto systemback;
            }
        }
    }
    else
    {
        gotoxy(x,y);
        printf("%c",256);
        goto restart;
    }
}
int input_numbers_undermainmenu(int *num,int lenth,int x,int y)
{
    int temp=0,i,j,x1,y1;
    char ch;
    x1=x;
    y1=y;
    reset:
    x=x1;
    y=y1;
    for(i=1;i<=lenth;i++)
    {
        restart:
            Bk_color(28,15);
            print_date_time(74,95,41,x,y);
            Bk_color(252,0);
            gotoxy(x,y);
            ch=getche();
            if(ch=='0' && i==1)
            {
                gotoxy(x,y);
                printf("%c",256);
                goto restart;
            }
            if(ch==27)
            {
                return 202;
            }
            if(ch==-32)
            {
                ch=getche();
                gotoxy(x,y);
                printf("%c",256);
                goto restart;
            }
            if(ch>=48 && ch<=57)
            {
                x++;
                temp=temp*10+(ch-48);
            }
            else if(ch==13 && temp>0)
            {
                *num=temp;
                return;
            }
            else if(ch==8)
            {
                if(i>1)
                {
                    temp=temp/10;
                    x--;
                    i--;
                }
                    gotoxy(x,y);
                    printf("%c",256);
                goto restart;
            }
            else
            {
                gotoxy(x,y);
                printf("%c",256);
                goto restart;
            }
    }
    if(temp<1)
    {
        if(gsetting.warnings==1)
        {
            MessageBoxA(NULL," Invalid number"," Invalid Input",48);
            Clear_buffer();
        }
        Bk_color(252,15);
        for(j=x1;j<=x;j++)
        {
            gotoxy(j,y);
            printf("%c",256);
        }
        temp=0;
        goto reset;
    }
    *num=temp;
    return;
}
int input_password_undermainmenu(char *a,int lenth,int x,int y)
{
    int i=0,j,x1,y1,flag,return_value;
    char ch;
    x1=x;
    y1=y;
    if(gsetting.password_masking)
        flag=0;
    else
        flag=1;
    for(i=0;i<lenth;i++)
    {

        abc:
        Bk_color(28,15);
        print_date_time(74,95,41,x,y);
        Bk_color(252,0);
        gotoxy(x,y);
        a[i]=getche();
        if(a[i]==0)
        {
            if(kbhit())
            {
                ch=getch();
                if(ch==31)
                {
                    //if(i==0)
                       // goto abc;
                    a[i]='\0';
                    a[i+1]='\0';
                    gotoxy(x1,y1);
                    printf("%s",a);
                    flag=1;
                }
                else if(ch==35)
                {
                    //if(i==0)
                        //goto abc;
                    for(j=x1;j<x;j++)
                    {
                        gotoxy(j,y1);
                        printf("*");
                    }
                    gotoxy(x,y);
                    flag=0;
                }
            }
        }
        if(a[i]==-32)
        {
            a[i]=getche();
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]==27)
        {
            a[i]='\0';
            return 202;
        }
        if(a[i]!=8)
        {
            if(flag==0)
            {
                gotoxy(x,y);
                printf("*");
            }
            else
            {
                gotoxy(x,y);
                printf("%c",a[i]);
            }
        }
        if(a[i]==8)
        {
            if(i==0)
            {
                goto abc;
            }
            else
            {
            i--;
            x--;
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
            }
        }
        if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') || (a[i]>=48 && a[i]<=57))
        {

        }
        else if(a[i]==33 || a[i]==64 || a[i]==35 || a[i]==36 ||a[i]==37 || a[i]==94 ||a[i]==38 || a[i]==42)
        {

        }
        else if(a[i]==13 && i>=8)
        {
            a[i]='\0';
            return;
        }
        else if(a[i]==13 && i<9)
        {
            if(gsetting.warnings)
            {
                return_value=MessageBoxA(NULL,"  Enter minimum 8 character's"," Warning",48);
                Clear_buffer();
            }
        }
        else
        {

            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        x++;
    }
    a[i]='\0';
    return a;
}
/*void rec_MSGinM(char *string,int x,int x1,int y)
{
    int H_lenth,middile_p;
    H_lenth=(strlen(string))/2;
    middile_p=x1-((x1-x)/2);
    gotoxy(middile_p-H_lenth+1,y);
    printf("%s",string);
}*/
void main_menu_background()
{
    gotoxy(2,6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,21);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,23);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,25);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,27);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,29);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,30);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,31);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,32);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,33);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,34);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,35);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,36);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,37);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,38);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(2,39);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

}
void working_area_background()
{
    gotoxy(40,6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,21);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,23);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,25);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,27);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,29);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,30);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,31);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,32);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,33);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,34);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,35);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,36);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,37);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,38);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,39);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}
void rules_background()
{
    gotoxy(40,6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,21);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,23);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,25);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,27);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,29);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,30);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,31);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,32);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,33);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,34);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,35);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,36);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,37);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,38);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(40,39);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}
void strip_of_title_bar(int x,int y)
{
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}
void field_of_mainmenu(int x,int y)
{
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
}
void Strip_of_notificationbar(int x,int y)
{
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
}
void menu_option(int x,int x1,int y,int y1)
{
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
}
void strip_of_set_permision(int x,int y,int stripcolor,int adcolor,int bkcolor)
{
    Bk_color(bkcolor,stripcolor);
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    Bk_color(bkcolor,adcolor);
    printf("%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220);
    Bk_color(bkcolor,stripcolor);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    Bk_color(bkcolor,adcolor);
    printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
    Bk_color(bkcolor,stripcolor);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
    Bk_color(bkcolor,adcolor);
    printf("%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223);
}
void back_freame(int x,int x1,int y, int y1)
{
    int i;
    for(i=x;i<=x1;i++)
    {
        gotoxy(i,y);
        printf("%c",220);
        gotoxy(i,y+1);
        printf("%c",219);
        gotoxy(i,y1);
        printf("%c",223);
    }
}
void ind_back_freame(int x,int x1,int y, int y1,int bottomLineshadow_color,int topLineShadow_color,int line_color)
{
    int i;
    for(i=x;i<=x1;i++)
    {
        Bk_color(topLineShadow_color,line_color);
        gotoxy(i,y);
        printf("%c",220);
        gotoxy(i,y+1);
        printf("%c",219);
        Bk_color(bottomLineshadow_color,line_color);
        gotoxy(i,y1);
        printf("%c",223);
    }
}
void menu_background()
{
    Bk_color(124,11);
    int i,j;
    for(j=3;j<=41;j++)
    {
        for(i=1;i<=110;i++)
        {
            gotoxy(i,j);
            printf("%c",219);
        }
    }
}
void update_status_bar(int x,int y)
{
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}
void window(int x,int x1,int y,int y1)
{
    int i,j;
    for(j=y;j<=y1;j++)
    {
        for(i=x;i<=x1;i++)
        {
            gotoxy(i,j);
            printf("%c",219);
        }
    }
}
void print_date_time(int dateX,int timeX,int y,int cursorx,int cursory) // Print date and time using this function
{
    time_t s,val=1;
    struct tm *current;
    int day,month,year;
    gotoxy(dateX,y);
    printf("Date : ");
    gotoxy(timeX,y);
    printf("Time : ");
    get_system_date(&day,&month,&year);
    gotoxy(dateX+7,y);
    printf("%02d/%02d/%04d",day,month,year);
    while(!kbhit())
    {
        s=time(NULL);
        current=localtime(&s);
        gotoxy(timeX+7,y);
        switch(current->tm_hour)
        {
        case 13:
            printf("%02d",1);
            break;
        case 14:
            printf("%02d",2);
            break;
        case 15:
            printf("%02d",3);
            break;
        case 16:
            printf("%02d",4);
            break;
        case 17:
            printf("%02d",5);
            break;
        case 18:
            printf("%02d",6);
            break;
        case 19:
            printf("%02d",7);
            break;
        case 20:
            printf("%02d",8);
            break;
        case 21:
            printf("%02d",9);
            break;
        case 22:
            printf("%02d",10);
            break;
        case 23:
            printf("%02d",11);
            break;
        case 00:
            printf("%02d",12);
            break;
        }
        if(current->tm_hour>=1 && current->tm_hour<=12)
            printf("%02d:%02d",current->tm_hour,current->tm_min);
        else
            printf(":%02d",current->tm_min);
        if(current->tm_hour>=12 && current->tm_hour<=23)
        {
            gotoxy(timeX+12,y);
            printf(" PM");
        }
        else
        {
            gotoxy(timeX+12,y);
            printf(" AM");
        }
        gotoxy(cursorx,cursory);
        delay(40);
    }
}
void print_date_time_AI(int dateX,int timeX,int y,int cursorx,int cursory) // Print date and time using this function
{
    time_t s,val=1;
    struct tm *current;
    int day,month,year;
    gotoxy(dateX,y);
    printf("Date : ");
    gotoxy(timeX,y);
    printf("Time : ");
    get_system_date(&day,&month,&year);
    gotoxy(dateX+7,y);
    printf("%02d/%02d/%04d",day,month,year);
    //while(!kbhit())
    //{
        s=time(NULL);
        current=localtime(&s);
        gotoxy(timeX+7,y);
        switch(current->tm_hour)
        {
        case 13:
            printf("%02d",1);
            break;
        case 14:
            printf("%02d",2);
            break;
        case 15:
            printf("%02d",3);
            break;
        case 16:
            printf("%02d",4);
            break;
        case 17:
            printf("%02d",5);
            break;
        case 18:
            printf("%02d",6);
            break;
        case 19:
            printf("%02d",7);
            break;
        case 20:
            printf("%02d",8);
            break;
        case 21:
            printf("%02d",9);
            break;
        case 22:
            printf("%02d",10);
            break;
        case 23:
            printf("%02d",11);
            break;
        case 00:
            printf("%02d",12);
            break;
        }
        if(current->tm_hour>=1 && current->tm_hour<=12)
            printf("%02d:%02d:%02d",current->tm_hour,current->tm_min,current->tm_sec);
        else
            printf(":%02d:%02d",current->tm_min,current->tm_sec);
        if(current->tm_hour>=12 && current->tm_hour<=23)
        {
            gotoxy(timeX+15,y);
            printf(" PM");
        }
        else
        {
            gotoxy(timeX+15,y);
            printf(" AM");
        }
        gotoxy(cursorx,cursory);
        //delay(40);
    //}
}
void welcome_screen_2()
{
    console_title("                                              BRIGHTGOAL SCHOOL FEES & STUDENT MANAGEMENT SYSTEM");
    system("COLOR bF");
    Hide_cursor();
    buffer_size(50,18);
    adjustWindowSize(339,207,50,18);
    remove_console_buttons();
    setcolor(12);
    drowlineH(0,49,17,219);
    drowlineH(0,49,0,219);
    buffer_size(50,17);
    adjustWindowSize(399,207,50,17);
    getch();
}
int confirmation_msg(char *your_msg,char *title,char *msg1,char *msg2,char *yes_by,char *no_by)
{
    int i,x,y,x1,y1;
    char ch;
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("CONFIRMATION MESSAGE",40,109,4);
    warning_background_under_main_menu(42,16,15,28,197,12);
    Bk_color(252,1);
    gotoxy(44,16);
    printf("%s",title);
    x=44;
    y=19;
    Bk_color(197,15);
    for(i=0;your_msg[i]!='\0';i++)
    {
        if(x==44)
            if(your_msg[i]==32)
                i++;
        gotoxy(x,y);
        printf("%c",your_msg[i]);
        if(x==104)
        {
            if(your_msg[i]!=32 && your_msg[i+1]!=32)
            {
                x++;
                gotoxy(x,y);
                printf("-");
            }
            x=44;
            y=y+2;;
        }
        else
        {
            x++;
        }

    }
    x1=73; //73-87 91-105
    y1=28;
    if(yes_by>='A' && yes_by<='Z')
    {
        yes_by=yes_by+32;
    }
    if(no_by>='A' && no_by<='Z')
    {
        no_by=no_by+32;
    }
    reset:
        Bk_color(197,15);
        strip_of_warning_msg(x1,y1);
        if(x1==91)
        {
            Bk_color(252,1);
            rec_MSGinM(msg2,91,105,28);
            Bk_color(197,15);
            rec_MSGinM(msg1,73,87,28);
        }
        else
        {
            Bk_color(197,15);
            rec_MSGinM(msg2,91,105,28);
            Bk_color(252,1);
            rec_MSGinM(msg1,73,87,28);
        }
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        ch=getch();
        if(ch==yes_by)
        {
            return 1;
        }
        if(ch==no_by)
        {
            return 0;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==left || ch==right)
            {
                switch(ch)
                {
                case left:
                    if(x1==91)
                    {
                        Bk_color(197,12);
                        strip_of_warning_msg(x1,y1);
                        x1=73;
                    }
                    goto reset;
                    break;
                case right:
                    if(x1==73)
                    {
                        Bk_color(197,12);
                        strip_of_warning_msg(x1,y1);
                        x1=91;
                    }
                    goto reset;
                    break;
                }
            }
            else
            {
                goto reset;
            }
        }
        else if(ch==13)
        {
            switch(x1)
            {
            case 73:
                return 1;
                break;
            case 91:
                return 0;
                break;
            }
        }
        else
        {
            goto reset;
        }
    getch();
}
void strip_of_warning_msg(int x,int y)
{
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
}
void warning_background_under_main_menu(int x,int y,int title_color,int t_topbkcolor,int t_bottombkcolor,int areacolor)
{
    Bk_color(t_topbkcolor,title_color);
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    Bk_color(t_bottombkcolor,title_color);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
    Bk_color(t_topbkcolor,areacolor);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

}
void view_all_account()
{
    system("cls");
    FILE *fp;
    fp=fopen(userpath,"rb");
    while(fread(&guser,sizeof(struct user_accounts),1,fp)>0)
    {
        decryption(guser.username);
        decryption(guser.password);
        decryption(guser.library_name);
        decryption(guser.first_name);
        decryption(guser.last_name);
        decryption(guser.Data_key);
        decryption(guser.Backup_key);
        decryption(guser.guest_admin);
        decryption(guser.guest_username);
        gotoxy(45,1);
        printf("Path : %s",guser.main_folderPath);
        gotoxy(45,3);
        printf("User Name : %s",guser.username);
        gotoxy(45,5);
        printf("Password : %s",guser.password);
        gotoxy(45,7);
        printf("Data Key : %s",guser.Data_key);
        gotoxy(45,9);
        printf("Backup key : %s",guser.Backup_key);
        gotoxy(45,11);
        printf("First Name : %s",guser.first_name);
        gotoxy(45,13);
        printf("Last Name : %s",guser.last_name);
        gotoxy(45,15);
        printf("School Name : %s",guser.library_name);
        gotoxy(45,17);
        printf("Mobile NUMBER : %s",guser.mobile);
        gotoxy(45,19);
        printf("Account type : %c",guser.account_type);
        gotoxy(45,21);
        printf("Email : %s",guser.email);
        gotoxy(45,23);
        printf("Guest User NAme : %s",guser.guest_username);
        gotoxy(45,25);
        printf("Guest Account Admin : %s",guser.guest_admin);
        gotoxy(45,27);
//        printf("Permission : %d",guser.permission_10);
        gotoxy(30,29);
        printf("Book Path : %s",guser.bookpath);
        gotoxy(30,31);
        printf("Issue Book Path %s",guser.issuepath);
        gotoxy(30,33);
        printf("Category Path : %s",guser.categoriepath);
        gotoxy(30,35);
        printf("Student Path : %s",guser.stdpath);
        if(getch()==27)
        {
            fclose(fp);
            return;
        }
        system("cls");
    }
    getch();
    fclose(fp);
}
int get_permission_of_guest_account(struct user_accounts *permission)
{
    int x,y,flag=1,flag2=1;
    char ch;
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("SET GUEST ACCOUNT PERMISSIONS",40,109,4);
    Bk_color(28,9);
    line_V(6,38,74,'n','n',0);
    x=41;
    y=7;
    Hide_cursor();
    reset_setting:
        Bk_color(28,15);
        if(x==41 || flag==1 || flag2==1)
        {
            gotoxy(42,7);
            printf("Add New Book");
            gotoxy(42,9);
            printf("Delete Book");
            gotoxy(42,11);
            printf("Change Book Name");
            gotoxy(42,13);
            printf("Change Category");
            gotoxy(42,15);
            printf("Change Writer Name");
            gotoxy(42,17);
            printf("Change Rent Rate");
            gotoxy(42,19);
            printf("Change Extra Charge");
            gotoxy(42,21);
            printf("Change Book Quantity");
            gotoxy(42,23);
            printf("Change Book Price");
            gotoxy(42,25);
            printf("Change Rack Number");
            gotoxy(42,27);
            printf("View All Book");
            gotoxy(42,29);
            printf("Export All  Book's");
            gotoxy(42,31);
            printf("Issue Book");
            gotoxy(42,33);
            printf("Submit Book");
            gotoxy(42,35);
            printf("View All Issued Book");
            gotoxy(42,37);
            printf("View Invoice");
        }
        if(x==76 || flag==1 || flag2==0)
        {
            gotoxy(77,7);
            printf("View All Invoice");
            gotoxy(77,9);
            printf("Export All Issued Books");
            gotoxy(77,11);
            printf("Export All Invoice");
            gotoxy(77,13);
            printf("Add New Student");
            gotoxy(77,15);
            printf("Remove Student");
            gotoxy(77,17);
            printf("Search Student");
            gotoxy(77,19);
            printf("Change Student Name");
            gotoxy(77,21);
            printf("Change Std. Father Name");
            gotoxy(77,23);
            printf("Change Std. Mobile No.");
            gotoxy(77,25);
            printf("Change Std. Roll Number");
            gotoxy(77,27);
            printf("View All Student's");
            gotoxy(77,29);
            printf("Export All Std. Data");
            gotoxy(77,31);
            printf("Add New Category");
            gotoxy(77,33);
            printf("Remove Category");
            gotoxy(77,35);
            printf("Search Category");
            gotoxy(77,37);
            printf("View All Category");
        }
        if(x==41 || flag==1 || flag2==1)
        {
            if(permission->add_new_books==1)
            {
                gotoxy(68,7);
                printf("Allow");
            }
            else
            {
                gotoxy(68,7);
                printf("Deny");
            }
            if(permission->Delete_books==1)
            {
                gotoxy(68,9);
                printf("Allow");
            }
            else
            {
                gotoxy(68,9);
                printf("Deny");
            }
            if(permission->Change_book_name==1)
            {
                gotoxy(68,11);
                printf("Allow");
            }
            else
            {
                gotoxy(68,11);
                printf("Deny");
            }
            if(permission->Change_category==1)
            {
                gotoxy(68,13);
                printf("Allow");
            }
            else
            {
                gotoxy(68,13);
                printf("Deny");
            }
            if(permission->Change_writer_name==1)
            {
                gotoxy(68,15);
                printf("Allow");
            }
            else
            {
                gotoxy(68,15);
                printf("Deny");
            }
            if(permission->Change_rent_rate==1)
            {
                gotoxy(68,17);
                printf("Allow");
            }
            else
            {
                gotoxy(68,17);
                printf("Deny");
            }
            if(permission->Change_extra_charge==1)
            {
                gotoxy(68,19);
                printf("Allow");
            }
            else
            {
                gotoxy(68,19);
                printf("Deny");
            }
            if(permission->Change_book_qty==1)
            {
                gotoxy(68,21);
                printf("Allow");
            }
            else
            {
                gotoxy(68,21);
                printf("Deny");
            }
            if(permission->Change_book_price==1)
            {
                gotoxy(68,23);
                printf("Allow");
            }
            else
            {
                gotoxy(68,23);
                printf("Deny");
            }
            if(permission->Change_rack_number==1)
            {
                gotoxy(68,25);
                printf("Allow");
            }
            else
            {
                gotoxy(68,25);
                printf("Deny");
            }
            if(permission->View_all_book==1)
            {
                gotoxy(68,27);
                printf("Allow");
            }
            else
            {
                gotoxy(68,27);
                printf("Deny");
            }
            if(permission->export_all_books==1)
            {
                gotoxy(68,29);
                printf("Allow");
            }
            else
            {
                gotoxy(68,29);
                printf("Deny");
            }
            if(permission->issue_book_permission==1)
            {
                gotoxy(68,31);
                printf("Allow");
            }
            else
            {
                gotoxy(68,31);
                printf("Deny");
            }
            if(permission->submit_books==1)
            {
                gotoxy(68,33);
                printf("Allow");
            }
            else
            {
                gotoxy(68,33);
                printf("Deny");
            }
            if(permission->view_issued_books==1)
            {
                gotoxy(68,35);
                printf("Allow");
            }
            else
            {
                gotoxy(68,35);
                printf("Deny");
            }
            if(permission->view_invoices==1)
            {
                gotoxy(68,37);
                printf("Allow");
            }
            else
            {
                gotoxy(68,37);
                printf("Deny");
            }

        }
        if(x==76 || flag==1 || flag2==0)
        {
            if(permission->view_all_invoices==1)
            {
                gotoxy(103,7);
                printf("Allow");
            }
            else
            {
                gotoxy(103,7);
                printf("Deny");
            }
            if(permission->export_issued_book==1)
            {
                gotoxy(103,9);
                printf("Allow");
            }
            else
            {
                gotoxy(103,9);
                printf("Deny");
            }
            if(permission->Export_all_invoice==1)
            {
                gotoxy(103,11);
                printf("Allow");
            }
            else
            {
                gotoxy(103,11);
                printf("Deny");
            }
            if(permission->add_new_students==1)
            {
                gotoxy(103,13);
                printf("Allow");
            }
            else
            {
                gotoxy(103,13);
                printf("Deny");
            }
            if(permission->remove_students==1)
            {
                gotoxy(103,15);
                printf("Allow");
            }
            else
            {
                gotoxy(103,15);
                printf("Deny");
            }
            if(permission->search_students==1)
            {
                gotoxy(103,17);
                printf("Allow");
            }
            else
            {
                gotoxy(103,17);
                printf("Deny");
            }
            if(permission->change_student_name==1)
            {
                gotoxy(103,19);
                printf("Allow");
            }
            else
            {
                gotoxy(103,19);
                printf("Deny");
            }
            if(permission->chnage_father_name==1)
            {
                gotoxy(103,21);
                printf("Allow");
            }
            else
            {
                gotoxy(103,21);
                printf("Deny");
            }
            if(permission->change_mobile_number==1)
            {
                gotoxy(103,23);
                printf("Allow");
            }
            else
            {
                gotoxy(103,23);
                printf("Deny");
            }
            if(permission->chnage_roll_number==1)
            {
                gotoxy(103,25);
                printf("Allow");
            }
            else
            {
                gotoxy(103,25);
                printf("Deny");
            }
            if(permission->view_all_students==1)
            {
                gotoxy(103,27);
                printf("Allow");
            }
            else
            {
                gotoxy(103,27);
                printf("Deny");
            }
            if(permission->Export_student_data==1)
            {
                gotoxy(103,29);
                printf("Allow");
            }
            else
            {
                gotoxy(103,29);
                printf("Deny");
            }
            if(permission->add_new_categoryes==1)
            {
                gotoxy(103,31);
                printf("Allow");
            }
            else
            {
                gotoxy(103,31);
                printf("Deny");
            }
            if(permission->remove_categoryes==1)
            {
                gotoxy(103,33);
                printf("Allow");
            }
            else
            {
                gotoxy(103,33);
                printf("Deny");
            }
            if(permission->search_categoryes==1)
            {
                gotoxy(103,35);
                printf("Allow");
            }
            else
            {
                gotoxy(103,35);
                printf("Deny");
            }
            if(permission->view_all_categoryes==1)
            {
                gotoxy(103,37);
                printf("Allow");
            }
            else
            {
                gotoxy(103,37);
                printf("Deny");
            }

        }
        flag=0;
        Bk_color(25,14);
        strip_of_set_permision(x,y,14,11,28);
        Bk_color(180,1);
        if(x==41 && y==7)
        {
            if(permission->add_new_books==1)
            {
                gotoxy(68,7);
                printf("Allow");
            }
            else
            {
                gotoxy(68,7);
                printf("Deny");
            }
        }
        if(x==41 && y==9)
        {
            if(permission->Delete_books==1)
            {
                gotoxy(68,9);
                printf("Allow");
            }
            else
            {
                gotoxy(68,9);
                printf("Deny");
            }
        }
        if(x==41 && y==11)
        {
            if(permission->Change_book_name==1)
            {
                gotoxy(68,11);
                printf("Allow");
            }
            else
            {
                gotoxy(68,11);
                printf("Deny");
            }
        }
        if(x==41 && y==13)
        {
            if(permission->Change_category==1)
            {
                gotoxy(68,13);
                printf("Allow");
            }
            else
            {
                gotoxy(68,13);
                printf("Deny");
            }
        }
        if(x==41 && y==15)
        {
            if(permission->Change_writer_name==1)
            {
                gotoxy(68,15);
                printf("Allow");
            }
            else
            {
                gotoxy(68,15);
                printf("Deny");
            }
        }
        if(x==41 && y==17)
        {
            if(permission->Change_rent_rate==1)
            {
                gotoxy(68,17);
                printf("Allow");
            }
            else
            {
                gotoxy(68,17);
                printf("Deny");
            }
        }
        if(x==41 && y==19)
        {
            if(permission->Change_extra_charge==1)
            {
                gotoxy(68,19);
                printf("Allow");
            }
            else
            {
                gotoxy(68,19);
                printf("Deny");
            }
        }
        if(x==41 && y==21)
        {
            if(permission->Change_book_qty==1)
            {
                gotoxy(68,21);
                printf("Allow");
            }
            else
            {
                gotoxy(68,21);
                printf("Deny");
            }
        }
        if(x==41 && y==23)
        {
            if(permission->Change_book_price==1)
            {
                gotoxy(68,23);
                printf("Allow");
            }
            else
            {
                gotoxy(68,23);
                printf("Deny");
            }
        }
        if(x==41 && y==25)
        {
            if(permission->Change_rack_number==1)
            {
                gotoxy(68,25);
                printf("Allow");
            }
            else
            {
                gotoxy(68,25);
                printf("Deny");
            }
        }
        if(x==41 && y==27)
        {
            if(permission->View_all_book==1)
            {
                gotoxy(68,27);
                printf("Allow");
            }
            else
            {
                gotoxy(68,27);
                printf("Deny");
            }
        }
        if(x==41 && y==29)
        {
            if(permission->export_all_books==1)
            {
                gotoxy(68,29);
                printf("Allow");
            }
            else
            {
                gotoxy(68,29);
                printf("Deny");
            }
        }
        if(x==41 && y==31)
        {
            if(permission->issue_book_permission==1)
            {
                gotoxy(68,31);
                printf("Allow");
            }
            else
            {
                gotoxy(68,31);
                printf("Deny");
            }
        }
        if(x==41 && y==33)
        {
            if(permission->submit_books==1)
            {
                gotoxy(68,33);
                printf("Allow");
            }
            else
            {
                gotoxy(68,33);
                printf("Deny");
            }
        }
        if(x==41 && y==35)
        {
            if(permission->view_issued_books==1)
            {
                gotoxy(68,35);
                printf("Allow");
            }
            else
            {
                gotoxy(68,35);
                printf("Deny");
            }
        }
        if(x==41 && y==37)
        {
            if(permission->view_invoices==1)
            {
                gotoxy(68,37);
                printf("Allow");
            }
            else
            {
                gotoxy(68,37);
                printf("Deny");
            }
        }
        if(x==76 && y==7)
        {
            if(permission->view_all_invoices==1)
            {
                gotoxy(103,7);
                printf("Allow");
            }
            else
            {
                gotoxy(103,7);
                printf("Deny");
            }
        }
        if(x==76 && y==9)
        {
            if(permission->export_issued_book==1)
            {
                gotoxy(103,9);
                printf("Allow");
            }
            else
            {
                gotoxy(103,9);
                printf("Deny");
            }
        }
        if(x==76 && y==11)
        {
            if(permission->Export_all_invoice==1)
            {
                gotoxy(103,11);
                printf("Allow");
            }
            else
            {
                gotoxy(103,11);
                printf("Deny");
            }
        }
        if(x==76 && y==13)
        {
            if(permission->add_new_students==1)
            {
                gotoxy(103,13);
                printf("Allow");
            }
            else
            {
                gotoxy(103,13);
                printf("Deny");
            }
        }
        if(x==76 && y==15)
        {
            if(permission->remove_students==1)
            {
                gotoxy(103,15);
                printf("Allow");
            }
            else
            {
                gotoxy(103,15);
                printf("Deny");
            }
        }
        if(x==76 && y==17)
        {
            if(permission->search_students==1)
            {
                gotoxy(103,17);
                printf("Allow");
            }
            else
            {
                gotoxy(103,17);
                printf("Deny");
            }
        }
        if(x==76 && y==19)
        {
            if(permission->change_student_name==1)
            {
                gotoxy(103,19);
                printf("Allow");
            }
            else
            {
                gotoxy(103,19);
                printf("Deny");
            }
        }
        if(x==76 && y==21)
        {
            if(permission->chnage_father_name==1)
            {
                gotoxy(103,21);
                printf("Allow");
            }
            else
            {
                gotoxy(103,21);
                printf("Deny");
            }
        }
        if(x==76 && y==23)
        {
            if(permission->change_mobile_number==1)
            {
                gotoxy(103,23);
                printf("Allow");
            }
            else
            {
                gotoxy(103,23);
                printf("Deny");
            }
        }
        if(x==76 && y==25)
        {
            if(permission->chnage_roll_number==1)
            {
                gotoxy(103,25);
                printf("Allow");
            }
            else
            {
                gotoxy(103,25);
                printf("Deny");
            }
        }
        if(x==76 && y==27)
        {
            if(permission->view_all_students==1)
            {
                gotoxy(103,27);
                printf("Allow");
            }
            else
            {
                gotoxy(103,27);
                printf("Deny");
            }
        }
        if(x==76 && y==29)
        {
            if(permission->Export_student_data==1)
            {
                gotoxy(103,29);
                printf("Allow");
            }
            else
            {
                gotoxy(103,29);
                printf("Deny");
            }
        }
        if(x==76 && y==31)
        {
            if(permission->add_new_categoryes==1)
            {
                gotoxy(103,31);
                printf("Allow");
            }
            else
            {
                gotoxy(103,31);
                printf("Deny");
            }
        }
        if(x==76 && y==33)
        {
            if(permission->remove_categoryes==1)
            {
                gotoxy(103,33);
                printf("Allow");
            }
            else
            {
                gotoxy(103,33);
                printf("Deny");
            }
        }
        if(x==76 && y==35)
        {
            if(permission->search_categoryes==1)
            {
                gotoxy(103,35);
                printf("Allow");
            }
            else
            {
                gotoxy(103,35);
                printf("Deny");
            }
        }
        if(x==76 && y==37)
        {
            if(permission->view_all_categoryes==1)
            {
                gotoxy(103,37);
                printf("Allow");
            }
            else
            {
                gotoxy(103,37);
                printf("Deny");
            }
        }
        Bk_color(225,1);
        if(x==41 && y==7)
        {
            gotoxy(42,7);
            printf("Add New Book");
        }
        if(x==41 && y==9)
        {
            gotoxy(42,9);
            printf("Delete Book");
        }
        if(x==41 && y==11)
        {
            gotoxy(42,11);
            printf("Change Book Name");
        }
        if(x==41 && y==13)
        {
            gotoxy(42,13);
            printf("Change Category");
        }
        if(x==41 && y==15)
        {
            gotoxy(42,15);
            printf("Change Writer Name");
        }
        if(x==41 && y==17)
        {
            gotoxy(42,17);
            printf("Change Rent Rate");
        }
        if(x==41 && y==19)
        {
            gotoxy(42,19);
            printf("Change Extra Charge");
        }
        if(x==41 && y==21)
        {
            gotoxy(42,21);
            printf("Change Book Quantity");
        }
        if(x==41 && y==23)
        {
            gotoxy(42,23);
            printf("Change Book Price");
        }
        if(x==41 && y==25)
        {
            gotoxy(42,25);
            printf("Change Rack Number");
        }
        if(x==41 && y==27)
        {
            gotoxy(42,27);
            printf("View All Book");
        }
        if(x==41 && y==29)
        {
            gotoxy(42,29);
            printf("Export All  Book's");
        }
        if(x==41 && y==31)
        {
            gotoxy(42,31);
            printf("Issue Book");
        }
        if(x==41 && y==33)
        {
            gotoxy(42,33);
            printf("Submit Book");
        }
        if(x==41 && y==35)
        {
            gotoxy(42,35);
            printf("View All Issued Book");
        }
        if(x==41 && y==37)
        {
            gotoxy(42,37);
            printf("View Invoice");
        }
        if(x==76 && y==7)
        {
            gotoxy(77,7);
            printf("View All Invoice");
        }
        if(x==76 && y==9)
        {
            gotoxy(77,9);
            printf("Export All Issued Books");
        }
        if(x==76 && y==11)
        {
            gotoxy(77,11);
            printf("Export All Invoice");
        }
        if(x==76 && y==13)
        {
            gotoxy(77,13);
            printf("Add New Student");
        }
        if(x==76 && y==15)
        {
            gotoxy(77,15);
            printf("Remove Student");
        }
        if(x==76 && y==17)
        {
            gotoxy(77,17);
            printf("Search Student");
        }
        if(x==76 && y==19)
        {
            gotoxy(77,19);
            printf("Change Student Name");
        }
        if(x==76 && y==21)
        {
            gotoxy(77,21);
            printf("Change Std. Father Name");
        }
        if(x==76 && y==23)
        {
            gotoxy(77,23);
            printf("Change Std. Mobile No.");
        }
        if(x==76 && y==25)
        {
            gotoxy(77,25);
            printf("Change Std. Roll Number");
        }
        if(x==76 && y==27)
        {
            gotoxy(77,27);
            printf("View All Student's");
        }
        if(x==76 && y==29)
        {
            gotoxy(77,29);
            printf("Export All Std. Data");
        }
        if(x==76 && y==31)
        {
            gotoxy(77,31);
            printf("Add New Category");
        }
        if(x==76 && y==33)
        {
            gotoxy(77,33);
            printf("Remove Category");
        }
        if(x==76 && y==35)
        {
            gotoxy(77,35);
            printf("Search Category");
        }
        if(x==76 && y==37)
        {
            gotoxy(77,37);
            printf("View All Category");
        }
        if(x==41)
        {
            flag2=1;
        }
        if(x==76)
        {
            flag2=0;
        }
        reenter_choice:
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        ch=getch();
        if(ch==27)
        {
            return 202;
        }
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y>7 && y<=37)
                    {
                        strip_of_set_permision(x,y,1,1,28);
                        y=y-2;
                    }
                    else
                    {
                        goto reenter_choice;
                    }
                    goto reset_setting;
                    break;
                case down:
                    if(y>=7 && y<37)
                    {
                        strip_of_set_permision(x,y,1,1,28);
                        y=y+2;
                    }
                    else
                    {
                       goto reenter_choice;
                    }
                    goto reset_setting;
                    break;
                }
            }
            else if(ch==left || ch==right)
            {
                switch(ch)
                {
                case left:
                    if(x==76)
                    {
                        strip_of_set_permision(x,y,1,1,28);
                        x=41;
                    }
                    else
                    {
                        goto reenter_choice;
                    }
                    goto reset_setting;
                    break;
                case right:
                    if(x==41)
                    {
                        strip_of_set_permision(x,y,1,1,28);
                        x=76;
                    }
                    else
                    {
                        goto reenter_choice;
                    }
                    goto reset_setting;
                    break;
                }
            }
        }
        else if(ch=='a' || ch=='d' || ch=='D' || ch=='A')
        {
            if(ch=='a' || ch=='A')
            {
                if(x==41)
                {
                    switch(y)
                    {
                    case 7:
                        permission->add_new_books=1;
                        break;
                    case 9:
                        permission->Delete_books=1;
                        break;
                    case 11:
                        permission->Change_book_name=1;
                        break;
                    case 13:
                        permission->Change_category=1;
                        break;
                    case 15:
                        permission->Change_writer_name=1;
                        break;
                    case 17:
                        permission->Change_rent_rate=1;
                        break;
                    case 19:
                        permission->Change_extra_charge=1;
                        break;
                    case 21:
                        permission->Change_book_qty=1;
                        break;
                    case 23:
                        permission->Change_book_price=1;
                        break;
                    case 25:
                        permission->Change_rack_number=1;
                        break;
                    case 27:
                        permission->View_all_book=1;
                        break;
                    case 29:
                        permission->export_all_books=1;
                        break;
                    case 31:
                        permission->issue_book_permission=1;
                        break;
                    case 33:
                        permission->submit_books=1;
                        break;
                    case 35:
                        permission->view_issued_books=1;
                        break;
                    case 37:
                        permission->view_invoices=1;
                        break;
                    }
                }
                if(x==76)
                {
                    switch(y)
                    {
                    case 7:
                        permission->view_all_invoices=1;
                        break;
                    case 9:
                        permission->export_issued_book=1;
                        break;
                    case 11:
                        permission->Export_all_invoice=1;
                        break;
                    case 13:
                        permission->add_new_students=1;
                        break;
                    case 15:
                        permission->remove_students=1;
                        break;
                    case 17:
                        permission->search_students=1;
                        break;
                    case 19:
                        permission->change_student_name=1;
                        break;
                    case 21:
                        permission->chnage_father_name=1;
                        break;
                    case 23:
                        permission->change_mobile_number=1;
                        break;
                    case 25:
                        permission->chnage_roll_number=1;
                        break;
                    case 27:
                        permission->view_all_students=1;
                        break;
                    case 29:
                        permission->Export_student_data=1;
                        break;
                    case 31:
                        permission->add_new_categoryes=1;
                        break;
                    case 33:
                        permission->remove_categoryes=1;
                        break;
                    case 35:
                        permission->search_categoryes=1;
                        break;
                    case 37:
                        permission->view_all_categoryes=1;
                        break;
                    }
                }
            }
            if(ch=='d' || ch=='D')
            {
                if(x==41)
                {
                    switch(y)
                    {
                    case 7:
                        permission->add_new_books=0;
                        break;
                    case 9:
                        permission->Delete_books=0;
                        break;
                    case 11:
                        permission->Change_book_name=0;
                        break;
                    case 13:
                        permission->Change_category=0;
                        break;
                    case 15:
                        permission->Change_writer_name=0;
                        break;
                    case 17:
                        permission->Change_rent_rate=0;
                        break;
                    case 19:
                        permission->Change_extra_charge=0;
                        break;
                    case 21:
                        permission->Change_book_qty=0;
                        break;
                    case 23:
                        permission->Change_book_price=0;
                        break;
                    case 25:
                        permission->Change_rack_number=0;
                        break;
                    case 27:
                        permission->View_all_book=0;
                        break;
                    case 29:
                        permission->export_all_books=0;
                        break;
                    case 31:
                        permission->issue_book_permission=0;
                        break;
                    case 33:
                        permission->submit_books=0;
                        break;
                    case 35:
                        permission->view_issued_books=0;
                        break;
                    case 37:
                        permission->view_invoices=0;
                        break;
                    }
                }
                if(x==76)
                {
                    switch(y)
                    {
                    case 7:
                        permission->view_all_invoices=0;
                        break;
                    case 9:
                        permission->export_issued_book=0;
                        break;
                    case 11:
                        permission->Export_all_invoice=0;
                        break;
                    case 13:
                        permission->add_new_students=0;
                        break;
                    case 15:
                        permission->remove_students=0;
                        break;
                    case 17:
                        permission->search_students=0;
                        break;
                    case 19:
                        permission->change_student_name=0;
                        break;
                    case 21:
                        permission->chnage_father_name=0;
                        break;
                    case 23:
                        permission->change_mobile_number=0;
                        break;
                    case 25:
                        permission->chnage_roll_number=0;
                        break;
                    case 27:
                        permission->view_all_students=0;
                        break;
                    case 29:
                        permission->Export_student_data=0;
                        break;
                    case 31:
                        permission->add_new_categoryes=0;
                        break;
                    case 33:
                        permission->remove_categoryes=0;
                        break;
                    case 35:
                        permission->search_categoryes=0;
                        break;
                    case 37:
                        permission->view_all_categoryes=0;
                        break;
                    }
                }
            }
            goto reset_setting;
        }
        else if(ch==13)
        {
            return 1;
        }
        else
        {
            goto reenter_choice;
        }

}
int view_all_guest_account(char *username)
{
    FILE *fp;
    int x,y,flag=0,flag2=0,flag3=0;
    char ch;
    struct user_accounts viewguestac;
    Hide_cursor();
    system("COLOR 7C");
    //buffer_size(116,45);
    //adjustWindowSize(0,0,111,42);

    //Bk_color(28,17);
    //drowlineH(0,111,42,220);
    //ind_back_freame(0,111,40,42,28,28,1);
    adjustWindowSize(0,0,112,42);
    buffer_size(213,42);
    Bk_color(28,1);
    //back_freame(0,212,0,2);
    column_strip_of_viewguest_account(0,1);
    Bk_color(28,15);
    rec_MSGinM("FIRST NAME",0,46,1);;
    rec_MSGinM("LAST NAME",48,95,1);
    rec_MSGinM("USERNAME",97,144,1);
    rec_MSGinM("PASSWORD",148,194,1);
    rec_MSGinM("BACKUP KEY",195,212,1);
    line_V(0,2,48,'n','n',0);
    line_V(0,2,97,'n','n',0);
    line_V(0,2,146,'n','n',0);
    line_V(0,2,195,'n','n',0);
    /*strip_of_viewguest_account(0,6,8,128,117,117);
    strip_of_viewguest_account(0,10,8,128,117,117);
    strip_of_viewguest_account(0,14,8,128,117,117);
    strip_of_viewguest_account(0,18,8,128,117,117);
    strip_of_viewguest_account(0,22,8,128,117,117);
    strip_of_viewguest_account(0,26,8,128,117,117);
    strip_of_viewguest_account(0,30,8,128,117,117);
    strip_of_viewguest_account(0,34,8,128,117,117);
    strip_of_viewguest_account(0,38,8,128,117,117);*/
    Bk_color(117,1);
    line_V(3,41,48,'n','n',0);
    line_V(3,41,97,'n','n',0);
    line_V(3,41,146,'n','n',0);
    line_V(3,41,195,'n','n',0);
    Bk_color(128,1);        //0  48  96
    fp=fopen(userpath,"rb");
    if(fp==NULL)
    {
        fclose(fp);
        Bk_color(28,15);
        gotoxy(2,41);
        printf("An Error occurred, You Cannot View Accounts\a");
        Bk_color(28,15);
        print_date_time(74,95,41,39,41);
        return 404;
    }
    y=4;
    while(fread(&viewguestac,sizeof(struct user_accounts),1,fp)>0)
    {
        decryption(viewguestac.guest_admin);
        if(match_two_string(viewguestac.guest_admin,username)==1)
        {
            decryption(viewguestac.guest_username);
            decryption(viewguestac.password);
            decryption(viewguestac.Backup_key);
            decryption(viewguestac.first_name);
            decryption(viewguestac.last_name);
            if(flag==0)
            {
                Bk_color(117,1);
                flag=1;
            }
            else
            {
                Bk_color(117,15);
                flag=0;
            }
            gotoxy(1,y);
            printf("%s",viewguestac.first_name);
            gotoxy(50,y);
            printf("%s",viewguestac.last_name);
            gotoxy(99,y);
            printf("%s",viewguestac.guest_username);
            gotoxy(148,y);
            printf("%s",viewguestac.password);
            gotoxy(197,y);
            printf("%s",viewguestac.Backup_key);
            y=y+2;
            flag2=1;
        }
    }
    y=y+2;
    Bk_color(117,12);
    gotoxy(1,y);
    printf("%s",guser.first_name);
    gotoxy(50,y);
    printf("%s",guser.last_name);
    gotoxy(99,y);
    printf("%s",guser.username);
    gotoxy(148,y);
    printf("%s",guser.password);
    gotoxy(197,y);
    printf("%s",guser.Backup_key);
    gotoxy(1,1);
    fclose(fp);
    if(flag2==0)
    {
        Bk_color(117,1);
        gotoxy(2,40);
        printf("No Guest Accounts\a");
    }
    x=0;
    Bk_color(28,15);
    rescroll:
        gotoxy(x,y);
        ch=getch();
        if(ch==-32)
        {
            ch=getch();
            if(ch==left || ch==right)
            {
                switch(ch)
                {
                case 75:
                    if(flag3==1)
                    {
                        x=x-111;
                        flag3=0;
                    }
                    if(x>0 && x<=212)
                    {
                        x--;
                    }
                    goto rescroll;
                case right:
                    if(flag3==0)
                    {
                        x=x+111;
                        flag3=1;
                    }
                    if(x>=0 && x<212)
                    {
                        x++;
                    }
                    goto rescroll;
                }
            }
            else
            {
                goto rescroll;
            }
        }
        else if(ch==13)
        {

        }
        else
        {
            goto rescroll;
        }
}
void column_strip_of_view_book(int x,int y)
{
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}
void column_strip_of_viewguest_account(int x,int y)
{
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}
void strip_of_viewguest_account(int x,int y,int color,int center,int top,int bottom)
{
    Bk_color(top,color);
    gotoxy(x,y-1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    Bk_color(center,color);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    Bk_color(bottom,color);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
}
void main_frame(int color_of_time_strip,char *massage)
{
    Hide_cursor();
    buffer_size(116,45);
    adjustWindowSize(0,0,111,42);
    Bk_color(28,1);
    back_freame(0,111,0,2);
    Bk_color(28,15);
    MSGinM(massage,1);
    Bk_color(180,17);
    drowlineH(0,110,42,220);
    Bk_color(117,17);
    drowlineV(3,42,0,219);
    drowlineV(3,42,111,219);
    ind_back_freame(1,110,40,42,28,color_of_time_strip,1);
    buffer_size(112,43);
    adjustWindowSize(0,0,112,43);
}
int rules_of_software()
{
    int y,y1,scr;
    char ch;
    float scroler,point,value;
    Bk_color(180,1);
    working_area_background();
    ind_back_freame(40,109,3,5,28,180,12);
    Bk_color(197,15);
    rec_MSGinM("RULES & INSTRUCTIONS",40,109,4);
    y=51;
    y1=7;
    scroler=(float)8;//29
    value=(float)(y+29)-38;
    point=(float)29/value;
    Bk_color(255,15);
    scroll_bar_strip_of_manageaccounts(108,8);
    Bk_color(197,15);
    gotoxy(108,7);
    printf("%c",30);
    gotoxy(108,38);
    printf("%c",31);
    reset_intruction:
        Bk_color(288,9);
        gotoxy(108,scroler);
        printf("%c",177);
        // massage area start
        if(y1>=7 && y1<=38)
        {
            Bk_color(28,14);
            gotoxy(42,y1);
            printf("Instructions");

        }
        if(y1+1>=7 && y1+1<=38)
        {
            Bk_color(28,14);
            line_H(42,42+12,y1+1,'n','n');
        }
        Bk_color(28,15);
        if(y1+3>=7 && y1+3<=38)
        {
            gotoxy(42,y1+3);
            printf("%c You can use Ctrl+Alt+s or Ctrl+Alt+h keys for Show and Hide",249);
        }
        if(y1+5>=7 && y1+5<=38)
        {
            gotoxy(44,y1+5);
            printf("Password. While Entering password.");
        }
        if(y1+7>=7 && y1+7<=38)
        {
            gotoxy(42,y1+7);
            printf("%c Use 'A' for Allow & 'D' for Deny while set Gutest A/c",249);
        }
        if(y1+9>=7 && y1+9<=38)
        {
            gotoxy(44,y1+9);
            printf("Permissions.");
        }
        if(y1+11>=7 && y1+11<=38)
        {
            gotoxy(42,y1+11);
            printf("%c You Can use the Setting Option to Customize the setting of",249);
        }
        if(y1+13>=7 && y1+13<=38)
        {
            gotoxy(44,y1+13);
            printf("This Software. Such as generate Backup or Data Key");
        }
        if(y1+15>=7 && y1+15<=38)
        {
            gotoxy(44,y1+15);
            printf("Automatically, Password Masking, Auto Detect Date etc.");
        }
        if(y1+17>=7 && y1+17<=38)
        {
            gotoxy(44,y1+17);
            printf("Use ( Right %c or Left %c ) Keys and ( 0 or 1 ) keys to ON or",27,26);
        }
        if(y1+19>=7 && y1+19<=38)
        {
            gotoxy(44,y1+19);
            printf("OFF Settings.");
        }
        if(y1+21>=7 && y1+21<=38)
        {
            gotoxy(42,y1+21);
            printf("%c You Can Find Your account Using Backup Key.",249);
        }
        if(y1+23>=7 && y1+23<=38)
        {
            gotoxy(42,y1+23);
            printf("%c Suppose you are forgotten your password, you can change your",249);
        }
        if(y1+25>=7 && y1+25<=38)
        {
            gotoxy(44,y1+25);
            printf("password using Backup key and Username.");
        }
        if(y1+27>=7 && y1+27<=38)
        {
            gotoxy(42,y1+27);
            printf("%c You can set guest A/c Access Permission of your Administrator",249);
        }
        if(y1+29>=7 && y1+29<=38)
        {
            gotoxy(44,y1+29);
            printf("Account Using Only Admin Account Username and Password");
        }
        if(y1+31>=7 && y1+31<=38)
        {
            gotoxy(42,y1+31);
            printf("%c You can delete your Account. using Username, Password, ",249);
        }
        if(y1+33>=7 && y1+33<=38)
        {
            gotoxy(44,y1+33);
            printf("Data Key. If the type of Account you to delete is ");
        }
        if(y1+35>=7 && y1+35<=38)
        {
            gotoxy(44,y1+35);
            printf("Administrator then your all guest accounts and data will be  ");
        }
        if(y1+37>=7 && y1+37<=38)
        {
            gotoxy(44,y1+37);
            printf("automatically deleted.");
        }
        if(y1+39>=7 && y1+39<=38)
        {
            gotoxy(42,y1+39);
            printf("%c You Can View all Guest Account Of Your Administrator Account",249);
        }
        if(y1+41>=7 && y1+41<=38)
        {
            gotoxy(44,y1+41);
            printf("Using Username & Password of Administrator Account.");
        }
        //--------------------------------------------
        if(y>=7 && y<=38)
        {
            Bk_color(28,14);
            gotoxy(42,y);
            printf("Rules of Software");
        }
        if(y+1>=7 && y+1<=38)
        {
            line_H(42,42+23,y+1,'n','n');
        }
        Bk_color(28,15);
        if(y+3>=7 && y+3<=38)
        {
            gotoxy(42,y+3);
            printf("%c You can only enter up to 46 Characters in the First Name",249);
        }
        if(y+5>=7 && y+5<=38)
        {
            gotoxy(44,y+5);
            printf("Last Name, Username, Password & Library Name.");
        }
        if(y+7>=7 && y+7<=38)
        {
            gotoxy(42,y+7);
            printf("%c You Can Create Only 10 Guest Account Of The Administrator ",249);
        }

        if(y+9>=7 && y+9<=38)
        {
            gotoxy(44,y+9);
            printf("Account.");
        }

        if(y+11>=7 && y+11<=38)
        {
            gotoxy(42,y+11);
            printf("%c You Can Only Create One Administrator account for an",249);
        }

        if(y+13>=7 && y+13<=38)
        {
            gotoxy(44,y+13);
            printf("Library.");
        }

        if(y+15>=7 && y+15<=38)
        {
            gotoxy(42,y+15);
            printf("%c You can not enter a password less than 8 Characters.",249);
        }

        if(y+17>=7 && y+17<=38)
        {
            gotoxy(42,y+17);
            printf("%c You can not enter First Name, Last Name, Username, Library Name",249);
        }

        if(y+19>=7 && y+19<=38)
        {
            gotoxy(44,y+19);
            printf("less than 5 Characters.");
        }
        if(y+21>=7 && y+21<=38)
        {
            gotoxy(42,y+21);
            printf("%c The Minimum and Maximum Length of the Backup Key and Data Key",249);
        }
        if(y+23>=7 && y+23<=38)
        {
            gotoxy(44,y+23);
            printf("is 15 Characters.");
        }
        if(y+25>=7 && y+25<=38)
        {
            gotoxy(42,y+25);
            printf("%c You Can not change Account Username After creating Account.",249);
        }
        if(y+27>=7 && y+27<=38)
        {
            gotoxy(42,y+27);
            printf("%c You Can not Change Library Name, Backup Key, Mobile Number,",249);
        }
        if(y+29>=7 && y+29<=38)
        {
            gotoxy(44,y+29);
            printf("Email, Data Key After Creating Account.");
        }

        //massage area end.
        reinput:
        Bk_color(28,15);
        print_date_time(74,95,41,61,18);
        ch=getch();
        if(ch==-32)
        {
            ch=getch();
            if(ch==up || ch==down)
            {
                switch(ch)
                {
                case up:
                    if(y1<7)
                    {
                        Bk_color(255,15);
                        gotoxy(108,scroler);
                        printf("%c",219);
                        scroler=(float)scroler-point;
                        scr=(int)scroler;
                        if(scr<8)
                        {
                            scroler=8;
                        }
                        Bk_color(28,1);
                        rules_background();
                        y++;
                        y1++;
                    }
                    else
                    {
                        Bk_color(255,15);
                        gotoxy(108,scroler);
                        printf("%c",219);
                        scroler=8;
                        Bk_color(288,9);
                        gotoxy(108,scroler);
                        printf("%c",177);
                        goto reinput;
                    }
                    goto reset_intruction;
                case down:
                    if(y+29>38)
                    {
                        Bk_color(255,15);
                        gotoxy(108,scroler);
                        printf("%c",219);
                        scroler=(float)scroler+point;
                        scr=(int)scroler;
                        if(scr>37)
                        {
                            scroler=37;
                        }
                        Bk_color(28,1);
                        rules_background();
                        y--;
                        y1--;
                    }
                    else
                    {
                        Bk_color(255,15);
                        gotoxy(108,scroler);
                        printf("%c",219);
                        scroler=37;
                        Bk_color(288,9);
                        gotoxy(108,scroler);
                        printf("%c",177);
                        goto reinput;
                    }
                    goto reset_intruction;
                }
            }
            else
            {
                goto reset_intruction;
            }
        }
        else if(ch==13 || ch==27)
        {
            return 1;
        }
        else
        {
            goto reset_intruction;
        }
}
void scroll_bar_strip_of_manageaccounts(register int x,register int y)
{
    gotoxy(x,y);
    printf("%c",219);
    gotoxy(x,y+1);
    printf("%c",219);
    gotoxy(x,y+2);
    printf("%c",219);
    gotoxy(x,y+3);
    printf("%c",219);
    gotoxy(x,y+4);
    printf("%c",219);
    gotoxy(x,y+5);
    printf("%c",219);
    gotoxy(x,y+6);
    printf("%c",219);
    gotoxy(x,y+7);
    printf("%c",219);
    gotoxy(x,y+8);
    printf("%c",219);
    gotoxy(x,y+9);
    printf("%c",219);
    gotoxy(x,y+10);
    printf("%c",219);
    gotoxy(x,y+11);
    printf("%c",219);
    gotoxy(x,y+12);
    printf("%c",219);
    gotoxy(x,y+13);
    printf("%c",219);
    gotoxy(x,y+14);
    printf("%c",219);
    gotoxy(x,y+15);
    printf("%c",219);
    gotoxy(x,y+16);
    printf("%c",219);
    gotoxy(x,y+17);
    printf("%c",219);
    gotoxy(x,y+18);
    printf("%c",219);
    gotoxy(x,y+19);
    printf("%c",219);
    gotoxy(x,y+20);
    printf("%c",219);
    gotoxy(x,y+21);
    printf("%c",219);
    gotoxy(x,y+22);
    printf("%c",219);
    gotoxy(x,y+23);
    printf("%c",219);
    gotoxy(x,y+24);
    printf("%c",219);
    gotoxy(x,y+25);
    printf("%c",219);
    gotoxy(x,y+26);
    printf("%c",219);
    gotoxy(x,y+27);
    printf("%c",219);
    gotoxy(x,y+28);
    printf("%c",219);
    gotoxy(x,y+29);
    printf("%c",219);
}
void loder_box(int x,int y)
{
    gotoxy(x,y);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);

}
void welcome_screen()
{
    int x,x1,y,y1,i;
    Bk_color(28,1);
    window(0,111,6,37);
    Bk_color(28,15);
    welcome_box(40,8);
    welcome_box(64,8);
    welcome_box(40,28);
    welcome_box(64,28);
    x=40;
    x1=64;
    y=8;
    y1=28;
    for(i=1;i<=5;i++)
    {
        Bk_color(28,1);
        welcome_box(x,y);
        welcome_box(x1,y);
        welcome_box(x,y1);
        welcome_box(x1,y1);
        x++;
        x1--;
        y++;
        y1--;
        Bk_color(28,15);
        welcome_box(x,y);
        welcome_box(x1,y);
        welcome_box(x,y1);
        welcome_box(x1,y1);
        delay(40);
    }
    delay(500);
    x=45;
    y=13;
    Bk_color(28,15);
    welcome_box(x+14,y);
    welcome_box(x,y);
    welcome_box(x+14,y+10);
    welcome_box(x,y+10);
    while(x!=2)
    {
        Bk_color(28,1);
        welcome_box(x+14,y);
        welcome_box(x,y);
        welcome_box(x+14,y+10);
        welcome_box(x,y+10);
        x--;
        Bk_color(28,15);
        welcome_box(x+14,y);
        welcome_box(x,y);
        welcome_box(x+14,y+10);
        welcome_box(x,y+10);
        delay(40);
    }
    Bk_color(28,15);
    gotoxy(32,14);
    printf("888888b.           d8b          888      888                               888");
    gotoxy(32,15);
    printf("888  %c88b          Y8P          888      888                               888",34);
    gotoxy(32,16);
    printf("888  .88P                       888      888                               888 ");
    gotoxy(32,17);
    printf("8888888K.  888d888 888  .d88b.  88888b.  888888  .d88b.   .d88b.   8888b.  888 ");
    gotoxy(32,18);
    printf("888  %cY88b 888P%c   888 d88P%c88b 888 %c88b 888    d88P%c88b d88%c%c88b     %c88b 888 ",34,34,34,34,34,34,34,34);
    gotoxy(32,19);
    printf("888    888 888     888 888  888 888  888 888    888  888 888  888 .d888888 888 ");
    gotoxy(32,20);
    printf("888   d88P 888     888 Y88b 888 888  888 Y88b.  Y88b 888 Y88..88P 888  888 888 ");
    gotoxy(32,21);
    printf("8888888P%c  888     888  %cY88888 888  888  %cY888  %cY88888  %cY88P%c  %cY888888 888 ",34,34,34,34,34,34,34);
    gotoxy(32,22);
    printf("                            888                      888                       ");
    gotoxy(32,23);
    printf("                       Y8b d88P                 Y8b d88P                       ");
    gotoxy(32,24);
    printf("                       %cY88P%c                   %cY88P%c                        ",34,34,34,34);
    gotoxy(97,24);
    printf("BRIGHTGOAL.IN");
    gotoxy(87,26);
    //printf("For Windows,Version 1.0");
    gotoxy(92,26);
    printf("BY HARVINDAR SINGH");
    gotoxy(80,30);
    //printf("www.Brightgol.in (2016 - 2019)");
    delay(100);
    Bk_color(28,1);
    welcome_box(x+14,y);
    welcome_box(x,y);
    welcome_box(x+14,y+10);
    welcome_box(x,y+10);
    delay(60);
    Bk_color(255,15);
    welcome_box(x+13,y);
    welcome_box(x,y);
    welcome_box(x+13,y+9);
    welcome_box(x,y+9);
    Bk_color(255,1);
    b_alpha(9,17);
    make_frame(2,27,13,30);
    delay(3000);
}
void welcome_box(int x,int y)
{
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);
}
void b_alpha(int x,int y)
{
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c",223,219,219,219,219,219,219,219,219,219,219,220);
    gotoxy(x,y+1);
    printf("  %c%c%c     %c%c%c",219,219,219,219,219,219);
    gotoxy(x,y+2);
    printf("  %c%c%c     %c%c%c",219,219,219,219,219,219);
    gotoxy(x,y+3);
    printf("  %c%c%c    %c%c%c",219,219,219,220,219,223);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,219,219,219,219,219,219,219);
    gotoxy(x,y+5);
    printf("  %c%c%c    %c%c%c",219,219,219,223,219,220);
    gotoxy(x,y+6);
    printf("  %c%c%c     %c%c%c",219,219,219,219,219,219);
    gotoxy(x,y+7);
    printf("  %c%c%c     %c%c%c",219,219,219,219,219,219);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,219,219,219,219,219,219,219,223);
    gotoxy(x,y+9);
    //printf("%c%c%c")
}
void main()
{
    FILE *FixMainFolder,*Fix_export_data_folder;
    mkdir(main_path);
    mkdir(Exported_data);
    FixMainFolder=fopen(fix_mainfolder,"wb");
    Fix_export_data_folder=fopen(Export_fix,"wb");
    rename_exefile("BRIGHTGOAL LMS.exe");
    make_folder_under_path(main_path,"User_accounts.dat",userpath,0);
    chack_setting();
    system("COLOR ec");
    buffer_size(112,43);
    adjustWindowSize(0,0,112,43);
    Hide_cursor();
    welcome_screen();
    login_status=0;
    main_menu();
    fclose(FixMainFolder);
    fclose(Fix_export_data_folder);
}
