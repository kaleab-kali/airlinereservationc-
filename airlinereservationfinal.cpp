#include <iostream>
using namespace std;

void welcome();
int choice_opt();
bool check_Eco();
bool check_first();
void reserve_seat(int choice);
void print_ticket(int choice,int seat);
void next_flight();

int seat[100];

int main()
{
    int seat_choice,eco_avalabile,first_avalabile;
    char ch;
    for(int i=0;i<=100;i++){

        system("cls");
        welcome();
        seat_choice = choice_opt();   //it accepts the returned value from choice_opt function
        eco_avalabile = check_Eco();  //it accepts the returned value from check_eco function
        first_avalabile = check_first(); //it accepts the returned value from check_firest function

        switch(seat_choice){
        case 1:{
            if(eco_avalabile == 1){
                reserve_seat(1);}
            else if (eco_avalabile == 0) //it checks the other section is available
                    {
                        if(first_avalabile == 1){
                            int Y,N;
                            cout << "there is available place in the first class: \n";
                            cout << "would you like to book in the first class: ([y]es,[N]o) \n";
                            cin >> ch;
                            if(ch == 'Y' || ch == 'y'){
                                reserve_seat(2);}
                            else
                                next_flight();
                        }
                        else
                            next_flight();
                    }}
            break;
        case 2:{
            if(first_avalabile == 1){
                reserve_seat(2);}
            else if(first_avalabile == 0){    // it checks the other section is avalabile
                    if(eco_avalabile == 1){
                        int Y,N;
                        cout << "there is available place in the economy class: \n";
                        cout << "would you like to book in the economy class: ([y]es,[N]o) \n";
                        cin >> ch;
                        if(ch == 'Y' || ch == 'y'){
                            reserve_seat(1);}
                        else
                            next_flight();
                    }
                    else
                        next_flight();
            }
            }
            break;
        case 3:
            exit(0);
    } }
    return 0;
}
// to welcomes the user
void welcome(){
    cout<<"*********************************************** WELCOME TO AASTU AIRLINE**************************************************\n\n";
    cout<<("                                                            |                                                             ")<<endl;
    cout<<R"(                                                      --====|====--                                                       )"<<endl;
    cout<<R"(                                                            |                                                             )"<<endl;
    cout<<R"(                                                                                                                          )"<<endl;
    cout<<R"(                                                        .-"""""-.                                                         )"<<endl;
    cout<<R"(                                                      .'_________'.                                                       )"<<endl;
    cout<<R"(                                                     /_/_|__|__|_\_\                                                      )"<<endl;
    cout<<R"(                                                    ;'-._       _.-';                                                     )"<<endl;
    cout<<R"(                               ,--------------------|    `-. .-'    |--------------------,                                )"<<endl;
    cout<<R"(                                ``""--..__    ___   ;       '       ;   ___    __..--""``                                 )"<<endl;
    cout<<R"(                                          `"-// \\.._\             /_..// \\-"`                                           )"<<endl;
    cout<<R"(                                             \\_//    '._       _.'    \\_//                                              )"<<endl;
    cout<<R"(                                              `"`        ``---``        `"`                                               )"<<endl;
    cout<<R"(            _         _______  _        _          _      _____                                       _    _               )"<<endl;
    cout<<R"(     /\    (_)       |__   __|(_)      | |        | |     |  __ \                                    | |  (_)              )"<<endl;
    cout<<R"(    /  \    _  _ __     | |    _   ___ | | __ ___ | |_    | |__) | ___  ___   ___  _ __ __   __ __ _ | |_  _   ___   _ __  )"<<endl;
    cout<<R"(   / /\ \  | || '__|    | |   | | / __|| |/ // _ \| __|   |  _  / / _ \/ __| / _ \| '__|\ \ / // _` || __|| | / _ \ | '_ \ )"<<endl;
    cout<<R"(  / ____ \ | || |       | |   | || (__ |   <|  __/| |_    | | \ \|  __/\__ \|  __/| |    \ V /| (_| || |_ | || (_) || | | |)"<<endl;
    cout<<R"( /_/    \_\|_||_|       |_|   |_| \___||_|\_\\___| \__|   |_|  \_\\___||___/ \___||_|     \_/  \__,_| \__||_| \___/ |_| |_|)"<<endl;
    cout<<endl;
    cout<<R"(---------------------------------------------------------------------------------------------------------------------------)"<<endl;
    cout<<R"(---------------------------------------------------------------------------------------------------------------------------)"<<endl;
}
//choice for the section a person wants in a plane
int choice_opt(){
    int class_choice;
    label:
    cout << "\t\t\t" <<"please enter 1 for economy class \n";
    cout << "\t\t\t" <<"please enter 2 for business class \n";
    cout << "\t\t\t" <<"please enter 3 to exit \n";
    cin >> class_choice;
    if(class_choice != 1 && class_choice !=2 && class_choice!=3){
        cout << "you entered a wrong choice! \n";
        goto label;
    }
    return class_choice;
}
//check availability on the economy class
bool check_Eco()
{
    int count_eco = 0;
    for(int i = 0;i<30;i++){
        if(seat[i] == 0){count_eco++;}}
    if (count_eco > 0){
        return 1;}
    else
        return 0;
}
//check availability on the first class
bool check_first()
{
    int count_first=0;
    for(int i = 30;i<100;i++){
        if(seat[i] == 0){ count_first++;}}
    if(count_first >0)
        return 1;
    else
        return 0;
}
//reserve a seat based on the preference of the person need
void reserve_seat(int choice)
{
    int seat_number=0;
    //reserve a seat for economy section
    if(choice == 1){
        for(int i=0; i<30;i++){
            if(seat[i] == 0){
                seat[i] = 1;
                seat_number = i+1;}
            if(seat_number != 0) //it breaks the loop when a seat is reserved
                break;}
        if(seat_number != 0)
            print_ticket(choice,seat_number);
    }
    //reserve a seat for first section
    else
    {   if(choice == 2){
            for(int j= 30; j<100;j++){
                if(seat[j] == 0){
                    seat[j] = 1;
                    seat_number = j+1;
                }
                if(seat_number != 0)
                    break;}
            if(seat_number != 0)
                print_ticket(choice,seat_number);
        }}
}
//print out boarding pass for individuals
void print_ticket(int choice,int seat_number)
{
    int age,pass_number;
    string first_name,middle_name,last_name,section_type;
    char gender,verify_age;
    label:
    cout << "what is your first name: "<<endl;
    cin >> first_name;
    cout << "what is your middle name: "<<endl;
    cin >> middle_name;
    cout << "what is your last name: "<<endl;
    cin >> last_name;
    cout << "what is your age: "<<endl;
    age1:
    cin >> age;
    if(age < 0 || age > 150){
        cout << "Error!!please enter your age again: ";goto age1;
    }
    else if(age < 18){
        cout << "you are underage! you arenot allowed to travel alone! \n";
        cout << "are you travling with your family? ([Y]es,[N]o) \n";
        cin >> verify_age;
        if(verify_age == 'N' || verify_age == 'n'){
            cout << "sorry you are not allowed to travel alone!"<<endl;
            system("pause");
            goto label;}
    }
    cout << "what is your gender: ([M]ale,[F]emale) "<<endl;
    gen_back:
    cin >> gender;
    if(gender == 'm')
         goto gen_front;
    else if(gender == 'M')
         goto gen_front;
    else if(gender == 'F')
         goto gen_front;
    else if(gender == 'f')
         goto gen_front;
    else
        cout << "please enter a proper character!";goto gen_back;
    gen_front:
    cout << "what is your passport number: "<<endl;
    cin >> pass_number;
    cout << "***********************************************************************\n";
    cout << "********************Boarding pass**************************************\n";
    cout << "\t\t"<<"  first name: "<<first_name<<endl;
    cout << "\t\t"<<"  middel name: "<<middle_name<<endl;
    cout << "\t\t"<<"  Last name: "<<last_name<<endl;
    cout << "\t\t"<<"  age: "<<age<<endl;
    cout << "\t\t"<<"  gender: "<<gender<<endl;
    cout << "\t\t"<<"  passport number: "<<pass_number<<endl;
    cout << "\t\t"<<"  seat number: "<<seat_number<<endl;
    cout << "\t\t"<<"  section: "<<((choice == 1)?"economy class":"first class")<<endl; // based on the selected section prints out which section is reserved
    cout << "\t\t"<<"  Gate: 404"<<endl;
    cout << "\t\t"<<"  Date of departure: June 29, 2021"<<endl;
    cout << "******************Thank you for choose our Airline!!*******************"<<endl;
    cout << "************************Have a nice Flight*****************************"<<endl;
    system("pause");
}
void next_flight()
{
    cout << "we are sorry for the inconvenience!"<<endl;
    cout << "the next flight leaves in 3 hours!"<<endl;
    system("pause");
}


