/*all right reserved by A. S. M. Toha*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

///____set cursor point______\\\

void gotoxy(int x,int y);

///_____ UTC time and date______\\\

void time_date(void);

///____helping part of whole function____\\\

void back_menu(void);
char call_option(void);
char select_choice(void);

///___payment method funcion____\\\

void choose_payment_method(void);
void bkash(void);
void rocket(void);
void nogod(void);

///_____entrance function_____\\\

void entry_process(void);

///_____logo making function_____\\\

void daraz_logo(void);

///_____welcoming front entrance______\\\

void welcome_daraz(void);

///_____user guideline to create account_____\\\

void guideline_to_create_account(void);

///_____email formating checking function_____\\\

int check_email_formation(void);

///______register account function_____\\\

void register_account(void);

///____login to account function______\\\

void login_account(void);

///_____main menu part of daraz____\\\

void main_menu_of_daraz(void);

///_____user activity function______\\\

void user_activity(void);

///____personal information (sub part of user activity)____\\\

void personal_information(void);

///____purchase history (sub part of user activity)____\\\

void purchase_history(void);

///_______about daraz (sub part of daraz main menu)______\\\

void about(void);

///______ daraz selling function (sub part of daraz main menu)_____\\\

void sell_with_us(void);

///_____ shop with us function (sub part of daraz main menu)____\\\

void shop_with_us(void);

///_____daraz global collection (sub part of shop with us)___\\\

void daraz_global_collection(void);

///___electronic & devices (sub part of global collection)___\\\

void global_electronic_devices(void);

///___electronic & accessories (sub part of global collection)___\\\

void global_electronic_accessories(void);

///____tv & home appliance (sub part of global collection)___\\\

void global_tv_home_appliences(void);

///____health & beauty (sub part of global collection)___\\\

void global_health_beauty(void);

///_____baby & toys (sub part of global collection)____\\\

void global_baby_toys(void);

///_____daraz mall (sub part of shop with us function)_____\\\

void daraz_mall(void);

///_____daraz discount (sub part of shop with us function)_____\\\

void  daraz_discount(void);

///_____daraz digital sheba (sub part of shop with us function)_____\\\

void daraz_digital_sheba(void);

///_____mobile top up (sub part of digital sheba_____\\\

void daraz_mobile_topup(void);

///____grameen phone topup (sub part of mobile top up)____\\\

void mobile_topup_gp(void);

///____robi topup (sub part of mobile top up)____\\\

void mobile_topup_rb(void);

///____banglalink topup (sub part of mobile top up)____\\\

void mobile_topup_bl(void);

///____teletalk topup (sub part of mobile top up)____\\\

void mobile_topup_tl(void);

///____mobile game & gift card (sub part of digital sheba)____\\\

void daraz_mobile_game_gift_cards(void);

///____entertainment & vouchers (sub part of digital sheba)____\\\

void daraz_entertainment_vouchers(void);

///____daraz shopping gift card (sub part of digital sheba)____\\\

void daraz_gift_cards(void);

///____ work with us function (sub part of dara main menu function)____\\\

void work_with_us(void);

///____sub part of work with us function______\\\

void product_distributer(void);
void product_delivery_man(void);
void graphics_designer(void);
void financial_officer(void);

///___helper part for work with us___\\\

int select_choice_in_work_with_us(void);

///_____account setting part____\\\

void account_settings(void);

///____sub parts of account setting____\\\

void edit_first_name(void);
void edit_last_name(void);
int user_edit_check_email_formation(void);
void change_email(void);
void change_password(void);
void change_phone_number(void);
void change_country(void);
void change_city(void);

///____log out from daraz menu____\\\

void log_out(void);

///____global variables___\\\

char choice;
char line[100];

int balance=10000000;

int amount;
int shopping_payment;
int mobile_recharge_amount;

///____ for making voucher_______\\\

int total_paid_amount=0;
int total_shopping_payment=0;
int global_collection_payment=0;
int electronic_devices_payment=0;
int electronic_accessories_payment=0;
int tv_home_appliences_payment=0;
int health_beauty_payment=0;
int baby_toys_payment=0;
int daraz_mall_payment=0;
int daraz_discount_payment=0;
int digital_sheba_payment=0;
int total_mobile_recharge_amount=0;
int mobile_game_gift_cards_payment=0;
int entertainment_vouchers_payment=0;
int gift_cards_payment=0;

///___ taking pin for method section____\\\

char bkash_pin_number[10];
char rocket_pin_number[10];
char nogod_pin_number[10];

char confirm_bkash_pin_number[10];
char confirm_rocket_pin_number[10];
char confirm_nogod_pin_number[10];

///____set cursor point______\\\

COORD coord = {0,0};
void gotoxy(int x,int y){
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

///_____ UTC time and date______\\\

void time_date(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE*FOREGROUND_RED*FOREGROUND_INTENSITY);
	time_t T=time(NULL);
	struct tm tm=*localtime(&T);
	gotoxy(0,0);printf("Time: %02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);
	gotoxy(0,1);printf("Date: %02d/%02d/%04d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);

}

///____helping part of whole function____\\\

void back_menu(){
    gotoxy(45,26);
    printf("Do you want to back main menu!");
    switch(select_choice()){
    case 'y':
        main_menu_of_daraz();
        break;
    case 'n':
        about();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Key!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            about();
        }
        else{
            main_menu_of_daraz();
        }
    }
}
char call_option(){
    gotoxy(50,25);
    printf("Press option number: ");
    return choice=getch();
}
char select_choice(){
    gotoxy(50,27);
    printf("Press [y/n]: ");
    return choice=getch();
}

///___payment method funcion____\\\

void choose_payment_method(){
    system("cls");
    daraz_logo();
    gotoxy(45,4);
    printf("Sir, please select payment method");
    gotoxy(50,6);
    printf("1. Bkash");
    gotoxy(50,8);
    printf("2. Rocket");
    gotoxy(50,10);
    printf("3. Nogod");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        bkash();
        break;
    case '2':
        rocket();
        break;
    case '3':
        nogod();
        break;
    case '0':
        main_menu_of_daraz();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            choose_payment_method();
        }
        else{
            main_menu_of_daraz();
        }
    }
}

///_____bkash (sub part of payment method)____\\\

void bkash(){
    system("cls");
    daraz_logo();
    gotoxy(50,6);
    fflush(stdin);
    printf("Enter Bkash pin number: ");
    gets(bkash_pin_number);
    gotoxy(50,8);
    fflush(stdin);
    printf("Enter amount in BDT: ");
    scanf("%d",&amount);
    if(amount>balance || total_paid_amount>balance){
        MessageBoxA(0,"You don't have enough balance!","Try Again!",5);
        main_menu_of_daraz();
    }
    gotoxy(50,10);
    fflush(stdin);
    printf("Enter Bkash in again: ");
    gets(confirm_bkash_pin_number);
    if(strcmp(bkash_pin_number,confirm_bkash_pin_number)!=0){
        MessageBoxA(0,"Wrong pin number!","Bkash!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            bkash();
        }
        else{
            main_menu_of_daraz();
        }
    }
}
///____rocket (sub part of payment method)_____\\\

void rocket(){
    system("cls");
    daraz_logo();
    gotoxy(50,6);
    fflush(stdin);
    printf("Enter Rocket pin number: ");
    gets(rocket_pin_number);
    gotoxy(50,8);
    fflush(stdin);
    printf("Enter amount in BDT: ");
    scanf("%d",&amount);
    if(amount>balance || total_paid_amount>balance){
        MessageBoxA(0,"You don't have enough balance!","Try Again!",5);
        main_menu_of_daraz();
    }
    gotoxy(50,10);
    fflush(stdin);
    printf("Enter Rocket in again: ");
    gets(confirm_rocket_pin_number);
    if(strcmp(rocket_pin_number,confirm_rocket_pin_number)!=0){
        MessageBoxA(0,"Wrong pin number!","Rocket!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            rocket();
        }
        else{
            main_menu_of_daraz();
        }
    }
}

///_____nogod (sub part of payment method)_____\\\

void nogod(void){
    system("cls");
    daraz_logo();
    gotoxy(50,6);
    fflush(stdin);
    printf("Enter Nogod pin number: ");
    gets(nogod_pin_number);
    gotoxy(50,8);
    fflush(stdin);
    printf("Enter amount in BDT: ");
    scanf("%d",&amount);
    if(amount>balance || total_paid_amount>balance){
        MessageBoxA(0,"You don't have enough balance!","Try Again!",5);
        main_menu_of_daraz();
    }
    gotoxy(50,10);
    fflush(stdin);
    printf("Enter Nogod in again: ");
    gets(confirm_nogod_pin_number);
    if(strcmp(nogod_pin_number,confirm_nogod_pin_number)!=0){
        MessageBoxA(0,"Wrong pin number!","Nogod!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            nogod();
        }
        else{
            main_menu_of_daraz();
        }
    }
}

///_____main function (starting point)_____\\\

int main(){
    system("cls");
    entry_process();
    return 0;
}

///_____entrance function_____\\\

void entry_process(){
    daraz_logo();
    int i;
    gotoxy(50,10);
    printf("LOADING ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED/FOREGROUND_BLUE);
    for(i=0;i<20;i++){
        printf("%c",177);
        Sleep(100);
    }
    welcome_daraz();
}

///_____logo making function_____\\\

void daraz_logo(){
    system("cls");
    time_date();
    gotoxy(56,0);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN*FOREGROUND_RED*FOREGROUND_INTENSITY);
    printf("Daraz.com");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);

}

///_____welcoming front entrance______\\\

void welcome_daraz(){

    system("cls");
    daraz_logo();
    gotoxy(40,5);
    printf("Welcome to daraz. In one place get everything!");
    gotoxy(40,6);
    printf("Big place for everything! Thanks for visiting us!");
    gotoxy(40,7);
    printf("You can buy products from here!");
    gotoxy(40,8);
    printf("You can sell products from here!");
    gotoxy(40,9);
    printf("You can get job in here!");
    gotoxy(40,10);
    printf("You can get digital sheba from here!");
    gotoxy(40,11);
    printf("Don't be late. Join with us guys!");
    gotoxy(58,12);
    getch();
    system("cls");
    daraz_logo();
    gotoxy(50,5);
    printf("1. Create an account");
    gotoxy(50,7);
    printf("2. Log in");
    gotoxy(50,9);
    printf("3. Exit");
    switch(call_option()){
    case '1':
            register_account();
        break;
    case '2':
        login_account();
        break;
    case '3':
        exit(0);
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Key!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            welcome_daraz();
        }
        else{
            exit(0);
        }
    }
}



///____register form information structure_____\\\

typedef struct{
    char first_name[20];
    char last_name[20];
    char register_email[70];
    char register_password[8];
    char login_email[70];
    char login_password[8];
    char country[20];
    char city[20];
    char phone_number[11];
}information;
information user;

///_____user information editor form  structure______\\\

typedef struct{
    char first_name[20];
    char last_name[20];
    char login_email[70];
    char login_password[8];
    char country[20];
    char city[20];
    char phone_number[11];
}edit_information;
edit_information user_edit_pannel;

///_____user guideline to create account_____\\\

void guideline_to_create_account(){
    FILE *fp_guideline_to_create_accouny;
    char *read_me="guideline_to_create_account.txt";
    fp_guideline_to_create_accouny=fopen(read_me, "r");
    while(fgets(line,sizeof(line),fp_guideline_to_create_accouny)){
        printf("%s",line);
    }
    fclose(fp_guideline_to_create_accouny);
}

///_____email formating checking function_____\\\

int check_email_formation(){
    if(strstr(user.register_email,"@gmail.com") || strstr(user.register_email,"@hotmail.com") || strstr(user.register_email,"@yahoo.com") || strstr(user.register_email,"@outlook.com")){
            return 2;
    }
    else{
        return 1;
    }
}

///______register account function_____\\\

void register_account(){
    system("cls");
    daraz_logo();
    guideline_to_create_account();
    gotoxy(58,18);
    getch();
    system("cls");
    daraz_logo();
    gotoxy(40,5);
    printf("First name      : ");
    gets(user.first_name);
    gotoxy(40,6);
    printf("Last name       : ");
    gets(user.last_name);
    gotoxy(40,7);
    printf("Email           : ");
    gets(user.register_email);
    gotoxy(40,8);
    printf("Password        : ");
    gets(user.register_password);
    gotoxy(40,9);
    printf("Phone number    : ");
    gets(user.phone_number);
    gotoxy(40,10);
    printf("Country name    : ");
    gets(user.country);
    gotoxy(40,11);
    printf("City name       : ");
    gets(user.city);
    if(strlen(user.first_name)<3 || strlen(user.first_name)>20){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, first name has to be minimum 3 character and maximum 20 character!","First Name!",5);
        register_account();
    }
    else if(strlen(user.last_name)<3 || strlen(user.last_name)>20){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, first name has to be minimum 3 character and maximum 20 character!","Last Name!",5);
        register_account();
    }

    else if(strlen(user.register_email)<12 || check_email_formation()==1){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, email formation doesn't correct!","Email!",5);
        register_account();
    }
    else if(strlen(user.register_password)<4 || strlen(user.register_password)>8){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, password has to be minimum 4 character and maximum 8 character!","Password!",5);
        register_account();
    }
    else if(strlen(user.phone_number)<9 || strlen(user.phone_number)>13){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, phone number has to be minimum 9 number and maximum 13 number!","Phone number!",5);
        register_account();
    }
    else if(strlen(user.country)<4 || strlen(user.country)>20){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, country name has to be minimum 4 character and maximum 20 character!","Country!",5);
        register_account();
    }
    else if(strlen(user.city)<1 || strlen(user.city)>20){
        system("cls");
        daraz_logo();
         MessageBoxA(0,"Sir, city name has to be minimum 1 character and maximum 20 character!","City!",5);
        register_account();
    }
    else{
        system("cls");
        daraz_logo();
        gotoxy(35,8);
        printf("Thanks for being with us! Your account have been created successfully!\n");
        gotoxy(58,12);
        getch();
        welcome_daraz();
    }
}

///____login to account function______\\\

void login_account(){
    system("cls");
    daraz_logo();
    gotoxy(40,4);
    printf("Please, login with your email and password!");
    gotoxy(40,6);
    printf("Email        : ");
    gets(user.login_email);
    gotoxy(40,7);
    printf("Password     : ");
    gets(user.login_password);
    if(strcmp(user.register_email,user.login_email)!=0){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Email doesn't match!Try again!","Invalid Email!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            login_account();
        }
        else{
            welcome_daraz();
        }
    }
    else if(strcmp(user.register_password,user.login_password)!=0){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Password doesn't match!Try again!","Invalid Password!",5);
        gotoxy(45,26);
        printf("Do You want to continue!");
        if(select_choice()=='y'){
            login_account();
        }
        else{
            welcome_daraz();
        }
    }
    else {
        system("cls");
        daraz_logo();
        int i;
		gotoxy(50,10);
		printf("LOGIN SUCCESSFULLY!");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED/FOREGROUND_BLUE);
        for(i=0;i<20;i++){
            printf("%c",177);
            Sleep(100);
        }
        main_menu_of_daraz();
    }

}

///_____main menu part of daraz____\\\

void main_menu_of_daraz(){
    system("cls");
    daraz_logo();
    gotoxy(50,4);
    printf("Menu:");
    gotoxy(50,6);
    printf("1. User activity");
    gotoxy(50,8);
    printf("2. About");
    gotoxy(50,10);
    printf("3. Sell With us");
    gotoxy(50,12);
    printf("4. Shop with us");
    gotoxy(50,14);
    printf("5. Work with us");
    gotoxy(50,16);
    printf("6. Account settings");
    gotoxy(50,18);
    printf("7. Log out");

    switch(call_option()){
    case '1':
        user_activity();
        break;
    case '2':
        about();
        break;
    case '3':
        sell_with_us();
        break;
    case '4':
        shop_with_us();
        break;
    case '5':
        work_with_us();
        break;
    case '6':
        account_settings();
        break;
    case '7':
        log_out();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Key!",5);
        gotoxy(45,25);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            main_menu_of_daraz();
        }
        else{
            log_out();
        }
    }
}

///_____user activity function______\\\

void user_activity(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Account information");
    gotoxy(50,6);
    printf("1. Personal information");
    gotoxy(50,8);
    printf("2. Purchase history");
    gotoxy(50,10);
    printf("0. Back");
    switch(call_option()){
    case '1':
        personal_information();
        break;
    case '2':
        purchase_history();
        break;
    case '0':
        main_menu_of_daraz();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Key!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            user_activity();
        }
        else{
            main_menu_of_daraz();
        }
    }
}

///____Personal information (sub part of user activity____\\\

void personal_information(){
    system("cls");
    daraz_logo();
    char choice;
    gotoxy(53,3);
    printf("Personal Information");
    gotoxy(40,6);
    printf("Name            :   %s %s",user.first_name,user.last_name);
    gotoxy(40,7);
    printf("Location:       :   %s,%s",user.city,user.country);
    gotoxy(40,8);
    printf("Phone Number    :   %s",user.phone_number);
    gotoxy(40,9);
    printf("Email           :   %s",user.login_email);
    gotoxy(40,10);
    printf("Password        :   %s",user.login_password);
    gotoxy(45,26);
    printf("Do you want to back main menu!");
    switch(select_choice()){
    case 'y':
        user_activity();
        break;
    case 'n':
        personal_information();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Key!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            personal_information();
        }
        else{
            user_activity();
        }
    }
}

///____purchase history (sub part of user activity)___\\\

void purchase_history(){
    system("cls");
    daraz_logo();
    int i,j;
    global_collection_payment=global_collection_payment+electronic_devices_payment+electronic_accessories_payment+tv_home_appliences_payment+health_beauty_payment+baby_toys_payment;
    digital_sheba_payment=digital_sheba_payment+total_mobile_recharge_amount+mobile_game_gift_cards_payment+entertainment_vouchers_payment+gift_cards_payment;
    total_paid_amount=total_paid_amount+global_collection_payment+digital_sheba_payment+daraz_mall_payment+daraz_discount_payment;
    gotoxy(53,3);
    printf("Purchase History");
    for(i=0,j=20;i<85;i++,j++){
        gotoxy(j,4);
        printf("%c",196);
    }
    gotoxy(35,8);
    printf("You card balance was                                            :%d BDT",balance);
    gotoxy(35,9);
    printf("Total purchase amount                                           :%d BDT",total_paid_amount);
    gotoxy(35,10);
    printf("Total purchase amount for only shopping                         :%d BDT",total_shopping_payment);
    gotoxy(35,11);
    printf("Total mobile recharge amount                                    :%d BDT",total_mobile_recharge_amount);
    gotoxy(35,12);
    printf("Total purchase amount from global collection category           :%d BDT",global_collection_payment);
    gotoxy(35,13);
    printf("Total purchase amount from daraz mall category                  :%d BDT",daraz_mall_payment);
    gotoxy(35,14);
    printf("Total purchase amount from daraz discount category              :%d BDT",daraz_discount_payment);
    gotoxy(35,15);
    printf("Total purchase amount from digital sheba category               :%d BDT",daraz_discount_payment);
    gotoxy(35,15);
    printf("Total purchase amount from electronic & devices section         :%d BDT",electronic_devices_payment);
    gotoxy(35,16);
    printf("Total purchase amount from electronic & accessories section     :%d BDT",electronic_accessories_payment);
    gotoxy(35,17);
    printf("Total purchase amount from tv & home appliance section          :%d BDT",tv_home_appliences_payment);
    gotoxy(35,18);
    printf("Total purchase amount from health & beauty section              :%d BDT",health_beauty_payment);
    gotoxy(35,19);
    printf("Total purchase amount from baby & toys section                  :%d BDT",baby_toys_payment);
    gotoxy(35,20);
    printf("Total purchase amount from game & gifts card section            :%d BDT",mobile_game_gift_cards_payment);
    gotoxy(35,21);
    printf("Total purchase amount from entertainment & vouchers section     :%d BDT",entertainment_vouchers_payment);
    gotoxy(35,22);
    printf("Total purchase amount from daraz gift card section              :%d BDT",gift_cards_payment);
    gotoxy(35,23);
    printf("Your current balance                                            :%d BDT",balance-total_paid_amount);
    gotoxy(50,26);
    printf("Do you want to back main menu!");
    switch(select_choice()){
    case 'y':
        user_activity();
        break;
    case 'n':
        purchase_history();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Key!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            purchase_history();
        }
        else{
            user_activity();
        }
    }

}
///_______about daraz______\\\

void about(){

    system("cls");
    daraz_logo();
    FILE *fp_about;
    char *read_me="about_daraz.txt";
    fp_about=fopen(read_me, "r");
    while(fgets(line,sizeof(line),fp_about)){
        printf("%s",line);
    }
    fclose(fp_about);
    back_menu();
}

///______ daraz selling function_____\\\

void sell_with_us(){
    struct seller{
        char product_name[50];
        int product_price;
        char seller_contact[20];
        char seller_location[50];
    };
    struct seller formation;

    FILE *product_file, *temp_file;
    char another, choice;

    char product_name[50];
    long int form_size;

    product_file=fopen("Product_list.txt","r+");
    if(product_file==NULL){
        product_file=fopen("Product_list.txt","w+");
        if(product_file==NULL){
            MessageBoxA(0,"Can not open file","Empty File!",5);
            main_menu_of_daraz();
        }
    }
    form_size = sizeof(formation);
    while(1){
        system("cls");
        daraz_logo();
        gotoxy(50,3);
        printf("Sell Your Product!");
        gotoxy(50,6);
        printf("1. Advertise your products here");
        gotoxy(50,8);
        printf("2. See your advertising products list");
        gotoxy(50,10);
        printf("3. Edit your advertising product name");
        gotoxy(50,12);
        printf("4. Delete your product from advertising");
        gotoxy(50,14);
        printf("0. Back");
        gotoxy(50,25);
        printf("Press option number: ");
        fflush(stdin);
        choice = getche();
        switch(choice){
        case '1':
            system("cls");
            daraz_logo();
            fseek(product_file,0,SEEK_END);
            another = 'y';
            while(another == 'y'){
                system("cls");
                daraz_logo();
                gotoxy(40,5);
                printf("Enter product name            : ");
                gets(formation.product_name);
                gotoxy(40,7);
                printf("Enter product price in BDT    : ");
                scanf("%d",&formation.product_price);
                gotoxy(40,9);
                fflush(stdin);
                printf("Enter seller contact          : ");
                gets(formation.seller_contact);
                gotoxy(40,11);
                printf("Enter seller location         : ");
                gets(formation.seller_location);

                fwrite(&formation,form_size,1,product_file);
                gotoxy(40,15);
                printf("Do you want to add another product[y/n]: ");
                fflush(stdin);
                another=getche();
            }
            break;
        case '2':
            system("cls");
            daraz_logo();
            rewind(product_file);
            int i=8;
            while(fread(&formation,form_size,1,product_file)==1){
                gotoxy(30,i);
                printf("Product Name:%s     Price:%d    Contract:%s     Location:%s",formation.product_name,formation.product_price,formation.seller_contact,formation.seller_location);
                i=i+2;
            }
            gotoxy(55,25);
            getch();
            break;

        case '3':
            system("cls");
            daraz_logo();
            another ='y';
            while(another=='y'){
                system("cls");
                daraz_logo();
                gotoxy(40,5);
                printf("Enter exact product name to modify: ");
                scanf("%s",product_name);
                rewind(product_file);
                while(fread(&formation,form_size,1,product_file)==1){
                    if(strcmp(formation.product_name,product_name)==0){
                        system("cls");
                        daraz_logo();
                        gotoxy(40,5);
                        fflush(stdin);
                        printf("Enter product name            : ");
                        gets(formation.product_name);
                        gotoxy(40,7);
                        printf("Enter product price in BDT    : ");
                        scanf("%d",&formation.product_price);
                        gotoxy(40,9);
                        fflush(stdin);
                        printf("Enter seller contact          : ");
                        gets(formation.seller_contact);
                        gotoxy(40,11);
                        printf("Enter seller location         : ");
                        gets(formation.seller_location);
                        fseek(product_file,-form_size,SEEK_CUR);
                        fwrite(&formation,form_size,1,product_file);
                        break;
                    }
                }
                gotoxy(35,15);
                printf("Do you want to modify another product[y/n]: ");
                fflush(stdin);
                another=getche();
            }
            break;
        case '4':
            system("cls");
            daraz_logo();
            another='y';
            while(another=='y'){
                system("cls");
                daraz_logo();
                gotoxy(40,5);
                printf("Enter exact product name to delete: ");
                scanf("%s",product_name);
                temp_file = fopen("Temp.txt","w");
                rewind(product_file);
                while(fread(&formation,form_size,1,product_file) == 1){
                    if(strcmp(formation.product_name,product_name) != 0){
                        fwrite(&formation,form_size,1,temp_file);
                    }
                }
                fclose(product_file);
                fclose(temp_file);
                remove("Product_list.txt");
                rename("Temp.txt","Product_list.txt");
                product_file=fopen("Product_list.txt", "r+");
                gotoxy(35,15);
                printf("Do you want to delete another record[y/n]: ");
                fflush(stdin);
                another=getche();
            }
            break;
        case '0':
            fclose(product_file);
            main_menu_of_daraz();
            break;
        default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Key!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
            if(select_choice()=='y'){
                fclose(product_file);
                sell_with_us();
            }
            else{
                fclose(product_file);
                main_menu_of_daraz();
            }
        }
    }
}

///_____ shop with us function____\\\

void shop_with_us(){
    system("cls");
    daraz_logo();
    gotoxy(35,3);
    printf("Welcome sir! Big marketplace in your hand, buy what you want!\n\n");
    gotoxy(50,5);
    printf("Menu:");
    gotoxy(50,8);
    printf("1. Global Collection");
    gotoxy(50,10);
    printf("2. DarazMall");
    gotoxy(50,12);
    printf("3. Discount");
    gotoxy(50,14);
    printf("4. Digital Sheba");
    gotoxy(50,16);
    printf("0. Back");
    switch(call_option()){
    case '1':
        daraz_global_collection();
        break;
    case '2':
        daraz_mall();
        break;
    case '3':
        daraz_discount();
        break;
    case '4':
        daraz_digital_sheba();
        break;
    case '0':
        main_menu_of_daraz();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Key!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            shop_with_us();
        }
        else{
            main_menu_of_daraz();
        }
    }
}

///_____daraz global collection (sub part of shop with us function)_____\\\

void daraz_global_collection(){
    system("cls");
    daraz_logo();
    gotoxy(50,4);
    printf("Categories");
    gotoxy(50,6);
    printf("1.  Electronic Devices");
    gotoxy(50,7);
    printf("2.  Electronic accessories");
    gotoxy(50,8);
    printf("3.  TV & Home Appliances");
    gotoxy(50,9);
    printf("4.  Health & Beauty");
    gotoxy(50,10);
    printf("5.  Babies & Toys");
    gotoxy(50,11);
    printf("0.  Back");
    switch(call_option()){
    case '1':
        global_electronic_devices();
        break;
    case '2':
        global_electronic_accessories();
        break;
    case '3':
        global_tv_home_appliences();
        break;
    case '4':
        global_health_beauty();
        break;
    case '5':
        global_baby_toys();
        break;
    case '0':
        shop_with_us();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            daraz_global_collection();
        }
        else{
            shop_with_us();
        }
    }
}

///____electronic & devices (sub part of global collection___\\\

void global_electronic_devices(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Global electronic devices");
    gotoxy(50,6);
    printf("1. Realmi 7 pro ");
    gotoxy(95,6);
    printf("Price: 15000 BDT");
    gotoxy(50,7);
    printf("2. Realmi c7");
    gotoxy(95,7);
    printf("Price: 25000 BDT");
    gotoxy(50,8);
    printf("3. Vivo y50");
    gotoxy(95,8);
    printf("Price: 30000 BDT");
    gotoxy(50,9);
    printf("4. Asus VivoBook");
    gotoxy(95,9);
    printf("Price: 60000 BDT");
    gotoxy(50,10);
    printf("5. Sony PS4 slim");
    gotoxy(95,10);
    printf("Price: 42000 BDT");
    gotoxy(50,11);
    printf("6. Nikon D5300 with lens");
    gotoxy(95,11);
    printf("Price: 50000 BDT");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment== 15000){
            system("cls");
            daraz_logo();
            electronic_devices_payment=electronic_devices_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_devices();
        }
        else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 15000 BDT!","Try Again!",5);
            global_electronic_devices();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==25000){
            electronic_devices_payment=electronic_devices_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_devices();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 25000 BDT!","Try Again!",5);
            global_electronic_devices();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==30000){
            electronic_devices_payment=electronic_devices_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_devices();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 15000 BDT!","Try Again!",5);
            global_electronic_devices();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==60000){
            electronic_devices_payment=electronic_devices_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_devices();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 60000 BDT!","Try Again!",5);
            global_electronic_devices();
        }
        break;
    case '5':
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==42000){
            electronic_devices_payment=electronic_devices_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_devices();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 42000 BDT!","Try Again!",5);
            global_electronic_devices();
        }
        break;
    case '6':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==50000){
            electronic_devices_payment=electronic_devices_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_devices();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 50000 BDT!","Try Again!",5);
            global_electronic_devices();
        }
        break;
    case '0':
        daraz_global_collection();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            global_electronic_devices();
        }
        else{
            daraz_global_collection();
        }
    }

}

///____electronic & accessories (sub part of global collection)____\\\

void global_electronic_accessories(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Global electronic accessories");
    gotoxy(50,6);
    printf("1. Vivo y50 Hard temper glass protector");
    gotoxy(95,6);
    printf("Price: 189 BDT");
    gotoxy(50,7);
    printf("2. i-phone 12 pro armor case");
    gotoxy(95,7);
    printf("Price: 500 BDT");
    gotoxy(50,8);
    printf("3. Samsung 20000mph portable power bank");
    gotoxy(95,8);
    printf("Price: 2000 BDT");
    gotoxy(50,9);
    printf("4. Xioumi 30000mph portable power bank");
    gotoxy(95,9);
    printf("Price: 3000 BDT");
    gotoxy(50,10);
    printf("5. Mi-3 charging adapter");
    gotoxy(95,10);
    printf("Price: 500 BDT");
    gotoxy(50,11);
    printf("6. Type-C fast charger adapter");
    gotoxy(95,11);
    printf("Price: 300 BDT");
    gotoxy(95,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==189){
            electronic_accessories_payment=electronic_accessories_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_accessories();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 189 BDT!","Try Again!",5);
            global_electronic_accessories();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==500){
            electronic_accessories_payment=electronic_accessories_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_accessories();
        }
        else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 500 BDT!","Try Again!",5);
            global_electronic_accessories();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==2000){
            electronic_accessories_payment=electronic_accessories_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_accessories();
        }
        else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 2000 BDT!","Try Again!",5);
            global_electronic_accessories();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==3000){
            electronic_accessories_payment=electronic_accessories_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_accessories();
        }
        else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 3000 BDT!","Try Again!",5);
            global_electronic_accessories();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==500){
            electronic_accessories_payment=electronic_accessories_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_accessories();
        }
        else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 500 BDT!","Try Again!",5);
            global_electronic_accessories();
        }
        break;
    case '6':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==300){
            electronic_accessories_payment=electronic_accessories_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_electronic_accessories();
        }
        else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 300 BDT!","Try Again!",5);
            global_electronic_accessories();
        }
        break;
    case '0':
        daraz_global_collection();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            global_electronic_accessories();
        }
        else{
            daraz_global_collection();
        }
    }
}

///____tv & home appliance (sub part of global collection)____\\\

void global_tv_home_appliences(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Global Tv & Home appliances");
    gotoxy(50,6);
    printf("1. 32inch Sony Plus Smart Tv");
    gotoxy(95,6);
    printf("Price: 12300 BDT");
    gotoxy(50,7);
    printf("2. Mi Xiaomi 43inch 4k HD smart Tv");
    gotoxy(95,7);
    printf("Price: 38920 BDT");
    gotoxy(50,8);
    printf("3. V-Guard Room Heater");
    gotoxy(95,8);
    printf("Price: 3200 BDT");
    gotoxy(50,9);
    printf("4. Vigo(RFL) Powerful Room Heater");
    gotoxy(95,9);
    printf("Price: 1230 BDT");
    gotoxy(50,10);
    printf("5. Vision Electronic Iron");
    gotoxy(95,10);
    printf("Price: 670 BDT");
    gotoxy(50,11);
    printf("6. Sharp rice cooker");
    gotoxy(95,11);
    printf("Price: 2500 BDT");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==12300){
            tv_home_appliences_payment=tv_home_appliences_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_tv_home_appliences();
        }
        else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 12300 BDT!","Try Again!",5);
            global_tv_home_appliences();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==38920){
            tv_home_appliences_payment=tv_home_appliences_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_tv_home_appliences();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 38920 BDT!","Try Again!",5);
            global_tv_home_appliences();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==3200){
            tv_home_appliences_payment=tv_home_appliences_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_tv_home_appliences();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 3200 BDT!","Try Again!",5);
            global_tv_home_appliences();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1230){
            tv_home_appliences_payment=tv_home_appliences_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_tv_home_appliences();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1230 BDT!","Try Again!",5);
            global_tv_home_appliences();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==670){
            tv_home_appliences_payment=tv_home_appliences_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_tv_home_appliences();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 670 BDT!","Try Again!",5);
            global_tv_home_appliences();
        }
        break;
    case '6':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==2500){
            tv_home_appliences_payment=tv_home_appliences_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_tv_home_appliences();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 2500 BDT!","Try Again!",5);
            global_tv_home_appliences();
        }
        break;
    case '0':
        daraz_global_collection();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            global_tv_home_appliences();
        }
        else{
            daraz_global_collection();
        }
    }
}

///___health & beauty (sub part of global collection)____\\\

void global_health_beauty(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Health & Beauty\n");
    gotoxy(50,6);
    printf("1. Olive Oil");
    gotoxy(95,6);
    printf("Price: 315 BDT");
    gotoxy(50,7);
    printf("2. Lavender Essential Oil-10ml");
    gotoxy(95,7);
    printf("Price: 360 BDT");
    gotoxy(50,8);
    printf("3. FASMC Bath Salts Body Massage");
    gotoxy(95,8);
    printf("Price: 275 BDT");
    gotoxy(50,9);
    printf("4. YESNOW Essence Natural Fruit Bath");
    gotoxy(95,9);
    printf("Price: 250 BDT");
    gotoxy(50,10);
    printf("5. Original Frozen");
    gotoxy(95,10);
    printf("Price: 669 BDT");
    gotoxy(50,11);
    printf("6. 4k plus cream");
    gotoxy(95,11);
    printf("Price: 160 BDT");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==315){
            health_beauty_payment=health_beauty_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_health_beauty();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 315 BDT!","Try Again!",5);
            global_health_beauty();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==360){
            health_beauty_payment=health_beauty_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_health_beauty();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 360 BDT!","Try Again!",5);
            global_health_beauty();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==275){
            health_beauty_payment=health_beauty_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_health_beauty();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 275 BDT!","Try Again!",5);
            global_health_beauty();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==250){
            health_beauty_payment=health_beauty_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_health_beauty();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 250 BDT!","Try Again!",5);
            global_health_beauty();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==669){
            health_beauty_payment=health_beauty_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_health_beauty();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 669 BDT!","Try Again!",5);
            global_health_beauty();
        }
        break;
    case '6':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==160){
            health_beauty_payment=health_beauty_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_health_beauty();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 160 BDT!","Try Again!",5);
            global_health_beauty();
        }
        break;
    case '0':
        daraz_global_collection();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            global_health_beauty();
        }
        else{
            daraz_global_collection();
        }
    }
}

///____baby & toys (sub part of global collection)___\\\

void global_baby_toys(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Global Baby Toys");
    gotoxy(50,6);
    printf("1. Baby Bath Toy Set");
    gotoxy(95,6);
    printf("Price: 120 BDT");
    gotoxy(50,7);
    printf("2. Emoji Squeeze");
    gotoxy(95,7);
    printf("Price: 90 BDT");
    gotoxy(50,8);
    printf("3. Exclusive Toys for Baby");
    gotoxy(95,8);
    printf("Price: 250 BDT");
    gotoxy(50,9);
    printf("4. Toy Kitchen");
    gotoxy(95,9);
    printf("Price: 220 BDT");
    gotoxy(50,10);
    printf("5. Baby Ring");
    gotoxy(95,10);
    printf("Price: 500 BDT");
    gotoxy(50,11);
    printf("6. Baby Car");
    gotoxy(95,11);
    printf("Price: 1090 BDT");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==120){
            baby_toys_payment=baby_toys_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_baby_toys();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 120 BDT!","Try Again!",5);
            global_baby_toys();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==90){
            baby_toys_payment=baby_toys_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_baby_toys();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 90 BDT!","Try Again!",5);
            global_baby_toys();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==250){
            baby_toys_payment=baby_toys_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_baby_toys();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 250 BDT!","Try Again!",5);
            global_baby_toys();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==220){
            baby_toys_payment=baby_toys_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_baby_toys();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 220 BDT!","Try Again!",5);
            global_baby_toys();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==500){
            baby_toys_payment=baby_toys_payment+shopping_payment;
            baby_toys_payment=baby_toys_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_baby_toys();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 500 BDT!","Try Again!",5);
            global_baby_toys();
        }
        break;
    case '6':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1090){
            baby_toys_payment=baby_toys_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            global_baby_toys();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1090 BDT!","Try Again!",5);
            global_baby_toys();
        }
        break;
    case '0':
        daraz_global_collection();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            global_baby_toys();
        }
        else{
            daraz_global_collection();
        }
    }
}
///_____daraz mall (sub part of shop with us function)_____\\\

void daraz_mall(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Top International Brand");
    gotoxy(50,6);
    printf("1. Fossil-Hybrid Smart watch Black");
    gotoxy(95,6);
    printf("Price:  15000 BDT");
    gotoxy(50,7);
    printf("2. Titan-Raga watch For Woman");
    gotoxy(95,7);
    printf("Price:  9000 BDT");
    gotoxy(50,8);
    printf("3. Diesel-Jeans For Man");
    gotoxy(95,8);
    printf("Price:  5000 BDT");
    gotoxy(50,9);
    printf("4. Daniel Klein-Watch DK 11");
    gotoxy(95,9);
    printf("Price:  2500 BDT");
    gotoxy(50,10);
    printf("5. Fastrack-Sunglass Black");
    gotoxy(95,10);
    printf("Price:  3000 BDT");
    gotoxy(50,11);
    printf("6. Casio-Scientific Calculator");
    gotoxy(95,11);
    printf("Price:  1500 BDT");
    gotoxy(50,13);
    printf("0.Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==15000){
            daraz_mall_payment=daraz_mall_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mall();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 15000 BDT!","Try Again!",5);
            daraz_mall();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==9000){
            daraz_mall_payment=daraz_mall_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mall();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 9000 BDT!","Try Again!",5);
            daraz_mall();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==5000){
            daraz_mall_payment=daraz_mall_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mall();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 5000 BDT!","Try Again!",5);
            daraz_mall();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==2500){
            daraz_mall_payment=daraz_mall_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mall();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 2500 BDT!","Try Again!",5);
            daraz_mall();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==3000){
            daraz_mall_payment=daraz_mall_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mall();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 3000 BDT!","Try Again!",5);
            daraz_mall();
        }
        break;
    case '6':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1500){
            daraz_mall_payment=daraz_mall_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mall();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1500 BDT!","Try Again!",5);
            daraz_mall();
        }
        break;
    case '0':
        shop_with_us();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            daraz_mall();
        }
        else{
            shop_with_us();
        }
    }
}

///_____daraz discount (sub part of shop with us function)_____\\\

void  daraz_discount(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Daraz Discount Offer");
    gotoxy(40,6);
    printf("1. Bed cover + Chair");
    gotoxy(80,6);
    printf("Price:  2000 BDT    Now: 1500 BDT");
    gotoxy(40,7);
    printf("2. 2 Soap + Olive oil");
    gotoxy(80,7);
    printf("Price:  1000 BDT    Now: 700 BDT ");
    gotoxy(40,8);
    printf("3. Apache 4v");
    gotoxy(80,8);
    printf("Price:  250000 BDT    Now: 230000 BDT");
    gotoxy(40,9);
    printf("4. Yellow T-Shirt + Jeans");
    gotoxy(80,9);
    printf("Price:  5000 BDT    Now: 4000 BDT");
    gotoxy(40,10);
    printf("5. Armani Jeans + Denim T-Shirt");
    gotoxy(80,10);
    printf("Price:  7000 BDT    Now: 5500 BDT");
    gotoxy(40,11);
    printf("6. Baby car + Baby Hoodie");
    gotoxy(80,11);
    printf("Price:  1500 BDT    Now: 1100 BDT");
    gotoxy(50,13);
    printf("0.Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1500){
            daraz_discount_payment=daraz_discount_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_discount();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1500 BDT!","Try Again!",5);
            daraz_discount();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==700){
            daraz_discount_payment=daraz_discount_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_discount();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 700 BDT!","Try Again!",5);
            daraz_discount();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==230000){
            daraz_discount_payment=daraz_discount_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_discount();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 230000 BDT!","Try Again!",5);
            daraz_discount();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==4000){
            daraz_discount_payment=daraz_discount_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_discount();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 4000 BDT!","Try Again!",5);
            daraz_discount();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==5500){
            daraz_discount_payment=daraz_discount_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_discount();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 5500 BDT!","Try Again!",5);
            daraz_discount();
        }
        break;
    case '6':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1100){
            daraz_discount_payment=daraz_discount_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_discount();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1100 BDT!","Try Again!",5);
            daraz_discount();
        }
        break;
    case '0':
        shop_with_us();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            daraz_discount();
        }
        else{
            shop_with_us();
        }
    }

}

///_____daraz digital sheba (sub part of shop with us function)_____\\\

void daraz_digital_sheba(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Categories");
    gotoxy(50,6);
    printf("1. Mobile Top-Up");
    gotoxy(50,7);
    printf("2. Games & Gift Card");
    gotoxy(50,8);
    printf("3. Entertainment Vouchers");
    gotoxy(50,9);
    printf("4. Daraz Gift Cards");
    gotoxy(50,10);
    printf("0. Back");
    switch(call_option()){
    case '1':
        daraz_mobile_topup();
        break;
    case '2':
        daraz_mobile_game_gift_cards();

        break;
    case '3':
        daraz_entertainment_vouchers();
        break;
    case '4':
        daraz_gift_cards();
        break;
    case '0':
        shop_with_us();
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            daraz_digital_sheba();
        }
        else{
            shop_with_us();
        }
    }
}

///____structure for mobile top up_____\\\

typedef struct{
    char gp_operator_name[20];
    char rb_operator_name[20];
    char bl_operator_name[20];
    char tl_operator_name[20];
    char gp_number[20];
    char rb_number[20];
    char bl_number[20];
    char tl_number[20];
}topup_information;
topup_information recharge;



///_____mobile top up (sub part of digital sheba_____\\\

void daraz_mobile_topup(){
    system("cls");
    daraz_logo();
    for(int i=0;i<10;i++){
        bkash_pin_number[i]='\0';
        rocket_pin_number[i]='\0';
        nogod_pin_number[i]='\0';
    }
    gotoxy(50,4);
    printf("Mobile Top-Up");
    gotoxy(50,7);
    printf("1. Grameen Phone");
    gotoxy(50,9);
    printf("2. Robi");
    gotoxy(50,11);
    printf("3. Banglalink");
    gotoxy(50,13);
    printf("4. Teletalk");
    gotoxy(50,15);
    printf("0. Back");
    switch(call_option()){
    case '1':
        mobile_topup_gp();
        break;
    case '2':
        mobile_topup_rb();
        break;
    case '3':
        mobile_topup_bl();
        break;
    case '4':
        mobile_topup_tl();
        break;
    case '0':
        daraz_digital_sheba();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do You want to continue!");
        if(select_choice()=='y'){
        daraz_mobile_topup();
        }
        else{
            daraz_digital_sheba();
        }
    }
}

///____grameen phone topup (sub part of mobile top up)____\\\

void mobile_topup_gp(){
    system("cls");
    daraz_logo();
    int signal=0;
    gotoxy(32,4);
    printf("Reminder! Give exactly operator name which you want to recharge!");
    gotoxy(35,6);
    printf("Grameen Phone | Robi-Airtel | Banglalink | Teletalk");
    gotoxy(40,8);
    fflush(stdin);
    printf("Enter sim operator name: ");
    gets(recharge.gp_operator_name);
    gotoxy(40,10);
    fflush(stdin);
    printf("Enter phone number:");
    gets(recharge.gp_number);

    if(strcmp(recharge.gp_operator_name,"Grameen Phone")!=0){
        MessageBoxA(0,"Operator name doesn't match!","Check Operator!",5);
        daraz_mobile_topup();
    }
    else if(recharge.gp_number[0]=='0' && recharge.gp_number[1]=='1' && recharge.gp_number[2]=='7'){
        int i;
		for( i=3;i<11;i++){
            if(recharge.gp_number[i]=='0'||recharge.gp_number[i]=='1'||recharge.gp_number[i]=='2'||recharge.gp_number[i]=='3'||recharge.gp_number[i]=='4'||recharge.gp_number[i]=='5'||recharge.gp_number[i]=='6'||recharge.gp_number[i]=='7'||recharge.gp_number[i]=='8'||recharge.gp_number[i]=='9'){
                signal++;
            }
        }
        if(signal==8){
            choose_payment_method();
            if(strcmp(bkash_pin_number,confirm_bkash_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge successfully by baksh!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else if(strcmp(rocket_pin_number,confirm_rocket_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge successfully by rocket!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else if(strcmp(nogod_pin_number,confirm_nogod_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge successfully by nogod!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else{
                system("cls");
                daraz_logo();
                MessageBoxA(0,"Sir, pin number doesn't match!","Warning!",5);
                gotoxy(45,26);
                printf("Do you want to continue!");
                if(select_choice()=='y'){
                    choose_payment_method();
                }
                else{
                    daraz_mobile_topup();
                }
            }
        }
        else{
            MessageBoxA(0,"Sim number doesn't correct!","Warning!",5);
            daraz_mobile_topup();
        }
    }
    else{
        MessageBoxA(0,"Sim number doesn't correct!","Waring!",5);
        daraz_mobile_topup();
    }
}

///____robi topup (sub part of mobile top up)____\\\

void mobile_topup_rb(){
    system("cls");
    daraz_logo();
    int signal=0;
    gotoxy(32,4);
    printf("Reminder! Give exactly operator name which you want to recharge!\n");
    gotoxy(35,6);
    printf("Grameen Phone | Robi-Airtel | Banglalink | Teletalk\n");
    fflush(stdin);
    gotoxy(40,8);
    printf("Enter sim operator name: ");
    gets(recharge.rb_operator_name);
    gotoxy(40,10);
    fflush(stdin);
    printf("Enter phone number:");
    gets(recharge.rb_number);

    if(strcmp(recharge.rb_operator_name,"Robi-Airtel")!=0){
        MessageBoxA(0,"Operator name doesn't match!","Check Operator!",5);
        daraz_mobile_topup();
    }
    else if(recharge.rb_number[0]=='0' && recharge.rb_number[1]=='1' && recharge.rb_number[2]=='8'){
        int i;
		for(i=3;i<11;i++){
            if(recharge.rb_number[i]=='0'||recharge.rb_number[i]=='1'||recharge.rb_number[i]=='2'||recharge.rb_number[i]=='3'||recharge.rb_number[i]=='4'||recharge.rb_number[i]=='5'||recharge.rb_number[i]=='6'||recharge.rb_number[i]=='7'||recharge.rb_number[i]=='8'||recharge.rb_number[i]=='9'){
                signal++;
            }
        }
        if(signal==8){
            choose_payment_method();
            if(strcmp(bkash_pin_number,confirm_bkash_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge BDT successfully by baksh!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else if(strcmp(rocket_pin_number,confirm_rocket_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge BDT successfully by rocket!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else if(strcmp(nogod_pin_number,confirm_nogod_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge BDT successfully by nogod!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else{
                system("cls");
                daraz_logo();
                MessageBoxA(0,"Sir, pin number doesn't match!","Warning!",5);
                gotoxy(45,26);
                printf("Do you want to continue!");
                if(select_choice()=='y'){
                    choose_payment_method();
                }
                else{
                    daraz_mobile_topup();
                }
            }
        }
        else{
            MessageBoxA(0,"Sim number doesn't correct","Warning!",5);
            daraz_mobile_topup();
        }
    }
    else{
        MessageBoxA(0,"Sim number doesn't correct","Warning!",5);
        daraz_mobile_topup();
    }

}

///____banglalink topup (sub part of mobile top up)____\\\

void mobile_topup_bl(){
    system("cls");
    daraz_logo();
    int signal=0;
    gotoxy(32,4);
    printf("Reminder! Give exactly operator name which you want to recharge!");
    gotoxy(35,6);
    printf("Grameen Phone | Robi-Airtel | Banglalink | Teletalk");
    gotoxy(40,8);
    fflush(stdin);
    printf("Enter sim operator name: ");
    gets(recharge.bl_operator_name);
    gotoxy(40,10);
    fflush(stdin);
    printf("Enter phone number:");
    gets(recharge.bl_number);
    if(strcmp(recharge.bl_operator_name,"Banglalink")!=0){
        MessageBoxA(0,"Operator name doesn't match","Check Operator!",5);
        daraz_mobile_topup();
    }
    else if(recharge.bl_number[0]=='0'&&recharge.bl_number[1]=='1'&&recharge.bl_number[2]=='9'){
        int i;
		for( i=3;i<11;i++){
            if(recharge.bl_number[i]=='0'||recharge.bl_number[i]=='1'||recharge.bl_number[i]=='2'||recharge.bl_number[i]=='3'||recharge.bl_number[i]=='4'||recharge.bl_number[i]=='5'||recharge.bl_number[i]=='6'||recharge.bl_number[i]=='7'||recharge.bl_number[i]=='8'||recharge.bl_number[i]=='9'){
                signal++;
            }
        }
        if(signal==8){
            choose_payment_method();
            if(strcmp(bkash_pin_number,confirm_bkash_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge BDT successfully by bkash!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else if(strcmp(rocket_pin_number,confirm_rocket_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
               MessageBoxA(0,"Recharge BDT successfully by rocket!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else if(strcmp(nogod_pin_number,confirm_nogod_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge BDT successfully by nogod!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else{
                system("cls");
                daraz_logo();
                MessageBoxA(0,"Sir, pin number doesn't match!","Warning!",5);
                gotoxy(45,26);
                printf("Do you want to continue!");
                if(select_choice()=='y'){
                    choose_payment_method();
                }
                else{
                    daraz_mobile_topup();
                }
            }
        }
        else{
            MessageBoxA(0,"Sim number doesn't correct!","Warning!",5);
            daraz_mobile_topup();
        }

    }
    else{
        MessageBoxA(0,"Sim number doesn't correct","Warning!",5);
        daraz_mobile_topup();
    }
}

///____teletalk topup (sub part of mobile top up)____\\\

void mobile_topup_tl(){
    system("cls");
    daraz_logo();
    int signal=0;
    gotoxy(32,4);
    printf("Reminder! Give exactly operator name which you want to recharge!");
    gotoxy(35,6);
    printf("Grameen Phone | Robi-Airtel | Banglalink | Teletalk");
    gotoxy(40,8);
    fflush(stdin);
    printf("Enter sim operator name: ");
    gets(recharge.tl_operator_name);
    gotoxy(40,10);
    fflush(stdin);
    printf("Enter phone number:");
    gets(recharge.tl_number);
    if(strcmp(recharge.tl_operator_name,"Teletalk")!=0){
        MessageBoxA(0,"Operator name doesn't match","Check Operator!",5);
        daraz_mobile_topup();
    }
    else if(recharge.tl_number[0]=='0'&&recharge.tl_number[1]=='1'&&recharge.tl_number[2]=='5'){
        int i;
		for( i=3;i<11;i++){
            if(recharge.tl_number[i]=='0'||recharge.tl_number[i]=='1'||recharge.tl_number[i]=='2'||recharge.tl_number[i]=='3'||recharge.tl_number[i]=='4'||recharge.tl_number[i]=='5'||recharge.tl_number[i]=='6'||recharge.tl_number[i]=='7'||recharge.tl_number[i]=='8'||recharge.tl_number[i]=='9'){
                signal++;
            }
        }
        if(signal==8){
            choose_payment_method();
            if(strcmp(bkash_pin_number,confirm_bkash_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge BDT successfully by bkash!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else if(strcmp(rocket_pin_number,confirm_rocket_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge BDT successfully by rocket!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else if(strcmp(nogod_pin_number,confirm_nogod_pin_number)==0){
                system("cls");
                daraz_logo();
                mobile_recharge_amount=amount;
                MessageBoxA(0,"Recharge BDT successfully by nogod!","Successful Recharged!",0);
                total_mobile_recharge_amount=total_mobile_recharge_amount+mobile_recharge_amount;
                daraz_mobile_topup();
            }
            else{
                system("cls");
                daraz_logo();
                MessageBoxA(0,"Sir, pin number doesn't match!","Warning!",5);
                gotoxy(45,26);
                printf("Do you want to continue!");
                if(select_choice()=='y'){
                    choose_payment_method();
                }
                else{
                    daraz_mobile_topup();
                }
            }
        }
        else{
            MessageBoxA(0,"Sim number doesn't correct!","Warning!",5);
            daraz_mobile_topup();
        }
    }
    else{
        MessageBoxA(0,"Sim number doesn't correct","Warning!",5);
        daraz_mobile_topup();
    }
}

///____mobile game & gift card (sub part of digital sheba)____\\\

void daraz_mobile_game_gift_cards(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Mobile Game and Gift Cards");
    gotoxy(50,6);
    printf("1. Pubg Royal Pass");
    gotoxy(95,6);
    printf("BDT 700 tk only");
    gotoxy(50,7);
    printf("2. Free Fire Royal Pass");
    gotoxy(95,7);
    printf("BDT 500 tk only");
    gotoxy(50,8);
    printf("3. Cyberprank Royal Pass");
    gotoxy(95,8);
    printf("BDT 1500 tk only");
    gotoxy(50,9);
    printf("4. Call Off Duty Full Game");
    gotoxy(95,9);
    printf("BDT 1200 tk only");
    gotoxy(50,10);
    printf("5. Speed Monster Gold Coin");
    gotoxy(95,10);
    printf("BDT 200 tk only");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==700){
            mobile_game_gift_cards_payment=mobile_game_gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mobile_game_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 700 BDT!","Try Again!",5);
            daraz_mobile_game_gift_cards();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==500){
            mobile_game_gift_cards_payment=mobile_game_gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mobile_game_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 500 BDT!","Try Again!",5);
            daraz_mobile_game_gift_cards();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1500){
            mobile_game_gift_cards_payment=mobile_game_gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mobile_game_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1500 BDT!","Try Again!",5);
            daraz_mobile_game_gift_cards();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1200){
            mobile_game_gift_cards_payment=mobile_game_gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mobile_game_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1200 BDT!","Try Again!",5);
            daraz_mobile_game_gift_cards();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==200){
            mobile_game_gift_cards_payment=mobile_game_gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_mobile_game_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 200 BDT!","Try Again!",5);
            daraz_mobile_game_gift_cards();
        }
        break;
    case '0':
        daraz_digital_sheba();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            daraz_mobile_game_gift_cards();
        }
        else{
            shop_with_us();
        }
    }
}

///____entertainment & vouchers (sub part of digital sheba)____\\\

void daraz_entertainment_vouchers(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Entertainment Vouchers");
    gotoxy(50,6);
    printf("1. SPOTIFY PREMIUM ACCOUNT");
    gotoxy(95,6);
    printf("BDT 500 tk only");
    gotoxy(50,7);
    printf("2. Spotify 1 Year");
    gotoxy(95,7);
    printf("BDT 1200 tk only");
    gotoxy(50,8);
    printf("3. Spotify Premium Subscription 1 Month");
    gotoxy(95,8);
    printf("BDT 99 tk only");
    gotoxy(50,9);
    printf("4. Netflix Gift Card");
    gotoxy(95,9);
    printf("BDT 1450 tk only");
    gotoxy(50,10);
    printf("5. iTunes Gift Card");
    gotoxy(95,10);
    printf("BDT 1700 tk only");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==500){
            entertainment_vouchers_payment=entertainment_vouchers_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_entertainment_vouchers();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 500 BDT!","Try Again!",5);
            daraz_entertainment_vouchers();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1200){
            entertainment_vouchers_payment=entertainment_vouchers_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_entertainment_vouchers();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1200 BDT!","Try Again!",5);
            daraz_entertainment_vouchers();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==99){
            entertainment_vouchers_payment=entertainment_vouchers_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_entertainment_vouchers();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 99 BDT!","Try Again!",5);
            daraz_entertainment_vouchers();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1450){
            entertainment_vouchers_payment=entertainment_vouchers_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_entertainment_vouchers();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1450 BDT!","Try Again!",5);
            daraz_entertainment_vouchers();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==1700){
            entertainment_vouchers_payment=entertainment_vouchers_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_entertainment_vouchers();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 1700 BDT!","Try Again!",5);
            daraz_entertainment_vouchers();
        }
        break;
    case '0':
        daraz_digital_sheba();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            daraz_entertainment_vouchers();
        }
        else{
            shop_with_us();
        }
    }

}

///____daraz shopping gift card (sub part of digital sheba)____\\\

void daraz_gift_cards(){
    system("cls");
    daraz_logo();
    gotoxy(50,3);
    printf("Daraz Gifts Card");
    gotoxy(50,6);
    printf("1. Daraz Gift Card");
    gotoxy(95,6);
    printf("BDT 100 tk only");
    gotoxy(50,7);
    printf("2. Daraz Gift Card");
    gotoxy(95,7);
    printf("BDT 200 tk only");
    gotoxy(50,8);
    printf("3. Daraz Gift Card");
    gotoxy(95,8);
    printf("BDT 2000 tk only");
    gotoxy(50,9);
    printf("4. Daraz Gift Card");
    gotoxy(95,9);
    printf("BDT 5000 tk only");
    gotoxy(50,10);
    printf("5. Daraz Gift Card");
    gotoxy(95,10);
    printf("BDT 20000 tk only");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==100){
            gift_cards_payment=gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 100 BDT!","Try Again!",5);
            daraz_gift_cards();
        }
        break;
    case '2':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==200){
            gift_cards_payment=gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 200 BDT!","Try Again!",5);
            daraz_gift_cards();
        }
        break;
    case '3':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==2000){
            gift_cards_payment=gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 2000 BDT!","Try Again!",5);
            daraz_gift_cards();
        }
        break;
    case '4':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==5000){
            gift_cards_payment=gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 5000 BDT!","Try Again!",5);
            daraz_gift_cards();
        }
        break;
    case '5':
        system("cls");
        daraz_logo();
        choose_payment_method();
        shopping_payment=amount;
        if(shopping_payment==20000){
            gift_cards_payment=gift_cards_payment+shopping_payment;
            total_shopping_payment=total_shopping_payment+shopping_payment;
            MessageBoxA(0,"Done!","Happy Shopping!",0);
            daraz_gift_cards();
        }
         else{
            system("cls");
            daraz_logo();
            MessageBoxA(0,"You have to pay 20000 BDT!","Try Again!",5);
            daraz_gift_cards();
        }
        break;
    case '0':
        daraz_digital_sheba();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            daraz_gift_cards();
        }
        else{
            shop_with_us();
        }
    }
}

///____ work with us function____\\\

void work_with_us(){
    system("cls");
    daraz_logo();
    gotoxy(40,4);
    printf("Welcome sir! Become a member in our family!");
    gotoxy(40,5);
    printf("Here is our job list. Chose any one based on your skill! Best off luck.");
    gotoxy(50,7);
    printf("1. Products Distributer");
    gotoxy(50,8);
    printf("2. Products Deliveryman");
    gotoxy(50,9);
    printf("3. Graphics Designer");
    gotoxy(50,10);
    printf("4. Finance Officer");
    gotoxy(50,12);
    printf("0. Back");
    switch(call_option()){
    case '1':
        product_distributer();
        break;
    case '2':
        product_delivery_man();
        break;
    case '3':
        graphics_designer();
        break;
    case '4':
        financial_officer();
        break;
    case '0':
        main_menu_of_daraz();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            work_with_us();
        }
        else{
            exit(0);
        }
    }
}

///____part of work with us function______\\\

void product_distributer(){
    system("cls");
    daraz_logo();
    FILE *fp_product_distributer;
    char *read_me="products_distributer.txt";
    fp_product_distributer=fopen(read_me, "r");
    while(fgets(line,sizeof(line),fp_product_distributer)){
        printf("%s",line);
    }
    fclose(fp_product_distributer);
    select_choice_in_work_with_us();
}
void product_delivery_man(){
    system("cls");
    daraz_logo();
    FILE *fp_product_delivery_man;
    char *read_me="products_deliveryman.txt";
    fp_product_delivery_man=fopen(read_me, "r");
    while(fgets(line,sizeof(line),fp_product_delivery_man)){
        printf("%s",line);
    }
    fclose(fp_product_delivery_man);
    select_choice_in_work_with_us();
}

void graphics_designer(){
    system("cls");
    daraz_logo();
    FILE *fp_graphics_designer;
    char *read_me="graphics_designer.txt";
    fp_graphics_designer=fopen(read_me, "r");
    while(fgets(line,sizeof(line),fp_graphics_designer)){
        printf("%s",line);
    }
    fclose(fp_graphics_designer);
    select_choice_in_work_with_us();
}
void financial_officer(){
    system("cls");
    daraz_logo();
    FILE *fp_financial_officer;
    char *read_me="finance_officer.txt";
    fp_financial_officer=fopen(read_me, "r");
    while(fgets(line,sizeof(line),fp_financial_officer)){
        printf("%s",line);
    }
    fclose(fp_financial_officer);
    gotoxy(50,20);
    select_choice_in_work_with_us();
}

///___helper part for work with use___\\\

int select_choice_in_work_with_us(){
    gotoxy(45,26);
    printf("Do you want see other job circular! ");
    switch(select_choice()){
    case 'y':
        work_with_us();
        break;
    case 'n':
        main_menu_of_daraz();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            work_with_us();
        }
        else{
            main_menu_of_daraz();
        }
    }
}

///_____account setting part____\\\

void account_settings(){
    system("cls");
    daraz_logo();
    gotoxy(30,4);
    printf("First name     : %s",user.first_name);
    gotoxy(70,4);
    printf("1. Edit first name");
    gotoxy(30,6);
    printf("Last name      : %s",user.last_name);
    gotoxy(70,6);
    printf("2. Edit last name");
    gotoxy(30,8);
    printf("Email          : %s",user.login_email);
    gotoxy(70,8);
    printf("3. Change email");
    gotoxy(30,10);
    printf("Password       : %s",user.login_password);
    gotoxy(70,10);
    printf("4. Change password");
    gotoxy(30,12);
    printf("Phone number   : %s",user.phone_number);
    gotoxy(70,12);
    printf("5. Change phone number");
    gotoxy(30,14);
    printf("Country name   : %s",user.country);
    gotoxy(70,14);
    printf("6. Change country");
    gotoxy(30,16);
    printf("City name      : %s",user.city);
    gotoxy(70,16);
    printf("7. Change city");
    gotoxy(50,18);
    printf("0. Back");
    switch(call_option()){
    case '1':
        edit_first_name();
        break;
    case '2':
        edit_last_name();
        break;
    case '3':
        change_email();
        break;
    case '4':
        change_password();
        break;
    case '5':
        change_phone_number();
        break;
    case '6':
        change_country();
        break;
    case '7':
        change_city();
        break;
    case '0':
        main_menu_of_daraz();
        break;
    default:
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir,you press wrong keyword!","Invalid Keyword!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");

        if(select_choice()=='y'){
            account_settings();
        }
        else{
            main_menu_of_daraz();
        }
    }
}

///____sub parts of account setting____\\\

void edit_first_name(){
    system("cls");
    daraz_logo();
    gotoxy(40,8);
    printf("First name: ");
    gets(user_edit_pannel.first_name);
    if(strlen(user_edit_pannel.first_name)<3 || strlen(user_edit_pannel.first_name)>20){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, first name has to be minimum 3 character and maximum 20 character!","Edit First Name Properly!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            edit_first_name();
        }
        else{
            account_settings();
        }
    }
    else{
        strcpy(user.first_name,user_edit_pannel.first_name);
        MessageBoxA(0,"First name changed successfully!","First Name Edited Successfully!",0);
        account_settings();
    }
}

void edit_last_name(){
    system("cls");
    daraz_logo();
    gotoxy(40,8);
    printf("Last name: ");
    gets(user_edit_pannel.last_name);
    if(strlen(user_edit_pannel.last_name)<3 || strlen(user_edit_pannel.last_name)>20){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, last name has to be minimum 3 character and maximum 20 character!","Edit Last Name Properly!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            edit_last_name();
        }
        else{
            account_settings();
        }
    }
    else{
        strcpy(user.last_name,user_edit_pannel.last_name);
        MessageBoxA(0,"Last name changed successfully!","Last Name Edited Successfully!",0);
        account_settings();
    }
}

int user_edit_check_email_formation(){
    if(strstr(user_edit_pannel.login_email,"@gmail.com") || strstr(user_edit_pannel.login_email,"@hotmail.com") || strstr(user_edit_pannel.login_email,"@yahoo.com") || strstr(user_edit_pannel.login_email,"@outlook.com")){
        return 2;
    }
    else{
        return 1;
    }
}

void change_email(){
    system("cls");
    daraz_logo();
    gotoxy(40,8);
    printf("Email: ");
    gets(user_edit_pannel.login_email);
    if(strlen(user_edit_pannel.login_email)<12 || user_edit_check_email_formation()==1){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, email formation doesn't correct!","Edit Email Properly!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            change_email();
        }
        else{
            account_settings();
        }
    }
    else{
        strcpy(user.login_email,user_edit_pannel.login_email);
        strcpy(user.register_email,user.login_email);
        MessageBoxA(0,"Email changed successfully!","Email Edited Successfully!",0);
        account_settings();
    }

}

void change_password(){
    system("cls");
    daraz_logo();
    gotoxy(40,8);
    printf("Password: ");
    gets(user_edit_pannel.login_password);
    if(strlen(user_edit_pannel.login_password)<4 || strlen(user_edit_pannel.login_password)>8){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, password has to be minimum 4 character and maximum 8 character!","Edit Password Properly!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            change_password();
        }
        else{
            account_settings();
        }
    }
    else{
        strcpy(user.login_password,user_edit_pannel.login_password);
        strcpy(user.register_password,user.login_password);
        MessageBoxA(0,"Password changed successfully!","Password Edited Successfully!",0);
        account_settings();
    }
}

void change_phone_number(){
    system("cls");
    daraz_logo();
    gotoxy(40,8);
    printf("Phone number: ");
    gets(user_edit_pannel.phone_number);
    if(strlen(user_edit_pannel.phone_number)<9 || strlen(user_edit_pannel.phone_number)>13){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, phone number has to be minimum 9 number and maximum 13 number!","Edit Phone Number Properly!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            change_phone_number();
        }
        else{
            account_settings();
        }
    }
    else{
        strcpy(user.phone_number,user_edit_pannel.phone_number);
        MessageBoxA(0,"Phone number changed successfully!","Edited Phone Number Successfully!",0);
        account_settings();
    }
}

void change_country(){
    system("cls");
    daraz_logo();
    gotoxy(40,8);
    printf("Country: ");
    gets(user_edit_pannel.country);
    if(strlen(user_edit_pannel.country)<4 || strlen(user_edit_pannel.country)>20){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, country name has to be minimum 4 character and maximum 20 character!","Edit Country Name Properly!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            change_country();
        }
        else{
            account_settings();
        }
    }
    else{
        strcpy(user.country,user_edit_pannel.country);
        MessageBoxA(0,"Country name changed successfully!","Edited Country Name Successfully!",0);
        account_settings();
    }
}

void change_city(){
    system("cls");
    daraz_logo();
    gotoxy(40,8);
    printf("City: ");
    gets(user_edit_pannel.city);
    if(strlen(user_edit_pannel.city)<1 || strlen(user_edit_pannel.city)>20){
        system("cls");
        daraz_logo();
        MessageBoxA(0,"Sir, city name has to be minimum 1 character and maximum 20 character!","Edit City Name Properly!",5);
        gotoxy(45,26);
        printf("Do you want to continue!");
        if(select_choice()=='y'){
            change_city();
        }
        else{
            account_settings();
        }
    }
    else{
        strcpy(user.city,user_edit_pannel.city);
        MessageBoxA(0,"City name changed successfully!","Edited City Name Properly!",0);
        account_settings();
    }
}

///____log out from daraz menu____\\\

void log_out(){
    system("cls");
    daraz_logo();
    MessageBoxA(0,"Thanks for Being With Us!","Daraz.Com!",0);
    gotoxy(45,26);
    printf("Do you want to logout!");
    if(select_choice()=='y'){
        welcome_daraz();
    }
    else{
        main_menu_of_daraz();
    }
}
