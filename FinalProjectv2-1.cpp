#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<Windows.h>
using namespace std;

void Menu();//global function
void Logo();//global function
int choice;//global variable
int id;
int n;
//able to access all over the project
class Intro{
    public:
    void Front(){
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t*  "<<"*  "<<"*    "<<"*****  "<<"*        "<<"*****   "<<" ****  "<<"    ***     "<<"****\n";
        Sleep(400);
        cout << "\t\t\t\t\t*  "<<"*  "<<"*    "<<"*  "<<"    *       "<<"*        "<<"*    *   "<<"*  *  *   "<<"*\n";
        Sleep(400);
        cout << "\t\t\t\t\t*  "<<"*  "<<"*    "<<"*****  "<<"*       "<<"*        "<<"*    *   "<<"*  *  *   "<<"****\n";
        Sleep(400);
        cout << "\t\t\t\t\t*  "<<"*  "<<"*    "<<"*  "<<"    *       "<<"*        "<<"*    *   "<<"*  *  *   "<<"*\n";
        Sleep(400);
        cout << "\t\t\t\t\t  ***      "<<"*****   "<<"*****   "<<"*****    "<<"****   " <<      " *  *  *   "<<"****\n\n";
        Sleep(400);
        cout << "\t\t\t\t                           * * * * *      ****\n";
        Sleep(400);
        cout << "\t\t\t\t                               *         *    *\n";
        Sleep(400);
        cout << "\t\t\t\t                               *         *    *\n";
        Sleep(400);
        cout << "\t\t\t\t                               *         *    *\n";
        Sleep(400);
        cout << "\t\t\t\t                               *          ****\n\n";
        Sleep(400);
        cout << "\t\t\t\t\t============================================================\n";
        cout << "\t\t\t\t\t+    H O T E L  M A N A G E M E N T  S Y S T E M  Vr.1.1\n";
        cout << "\t\t\t\t\t============================================================\n ";
        system("pause");
        Members();
    }
    void Members(){
        system("cls");
        cout << "\n\n\n\n\t\t\t+======================================================================Ver#2.0.1+\n\n";
        Sleep(400);
        cout << "\t\tGROUP MEMBERS (DEVELOPERS)\n";
        cout << "\t\t+--------------------------------------+\n\n";
        Sleep(400);
        cout << "\t\t-> NAME " << "\t\t\tROLL NUMBER" << "\t\t\tBATCH" << endl << endl;
        Sleep(400);
        cout << "\t\t-> 1. Muhammad Zeeshan" << "\t\t20021519-075" << "\t\t\tBS-CS20-B" << endl << endl;
        Sleep(400);
        cout << "\t\t-> 2. Kamran Ahsan" << "\t\t20021519-152" << "\t\t\tBS-CS20-B" << endl << endl;
        Sleep(400);
        cout << "\t\t-> 3. Sarosh Baqir" << "\t\t20021519-089" << "\t\t\tBS-CS20-B" << endl << endl;
        Sleep(400);
        cout << "\t\t-> 4. Ashel Eman" << "\t\t20021519-102" << "\t\t\tBS-CS20-B" << endl;
        Sleep(400);
        cout << "\t\t+---------------------------------------------------------------------------+\n\n";
        Sleep(400);
        cout << "\t\tSUBMITTED TO : " << "  MS. Ayesha Rashid       Last Due-date: 18th March 2022" << endl << endl;
     system("pause");
    }
};
struct Node1{
    string food;
    Node1 *next1;
};
struct Node{
    int Room_No;
    int no_of_rooms;
    string phone;
    int no_of_days;
    int pass;
    int bill;
    int total;
    string name;
    string room_type;
    string LowClass = "LOWER";
    string MediumClass = "Medium";
    string VIPClass = "VIP";
    string food;
    string cnic;
    Node* next;
    public:
        Node(){
            next = NULL;
        }
};
class ZKAS{
    public:
        friend void Bookrooms(int choice);
        friend void Booking_Portal();
        friend void show(Node* newhead);
        friend Node* readlinklist();
        friend void SearchRecords(Node* start);
        friend Node* Checkout(Node* start);
        friend Node* EditRecords(Node* start);
};
Node* start = NULL, *current = NULL;
Node1* front = NULL;
Node1* rear = NULL;
Node1* temp;
int lowclass = 15;
int vipclass = 15;
int mediumclass = 20;
int total=50;
// ---------------------------------Insertion of customer-------------------------------------
int checkerr(){
    a:
    cout << "\n\t\t\t=> Enter Your Choice: ";
    cin >> choice;
    bool valid =false;
    while (!valid)
    {
        if (cin.good())
        {
             valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(123, '\n');
            cout << "\n\tERROR: Enter Valid Integer!" << endl;
            goto a;
        }
    }
    return choice;
}
int checkerDays(){
    a:
    int days;
    cout << "\n\t => How many Days do you want to stay? : ";
    cin >> days;
    bool valid =false;
    while (!valid)
    {
        if (cin.good())
        {
             valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(123, '\n');
            cout << "\n\tERROR: Enter Valid Integer!, strings are not allowed" << endl;
            goto a;
        }
    }
    return days;
}
Node* checkExisted(Node* room){
    int flag = 0;
    a:
    cout << "\n\t => Enter Room_NO: ";
    cin >> room->Room_No;
    try{
        ifstream file("Record.txt");
        while (file.good()){
            int cust_room;
            if (!file.eof()){
                file >> cust_room;
                if (cust_room == room->Room_No){
                    throw cust_room;
                    flag = 1;
                }
            }
        }
        file.close();
    }catch (int cust_room){
        if (flag == 1){
            cout << "\n\tThis ROOM-NO is already existed, please try again!" << endl;
            goto a;
        }
    }
    return room;
}
void Bookrooms(int choice){
    system("cls");
    system("COLOR 00");
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\tLoading, Please Wait ";
    char load = 219;
    for(int i = 0; i < 40; i++){
        cout << load;
        if(i < 10){
            Sleep(50);
        }
        if(i >= 10 && i < 20){
            Sleep(10);
        }
        if(i >= 10){
            Sleep(15);
        }
    }
    system("cls");
    cout << "\n\t\t\t\t\t============================================================\n";
    cout << "\t\t\t\t\t+         B O O K I N G  R O O M S  S Y S T E M            +\n";
    cout << "\t\t\t\t\t============================================================\n\n";
    current = new Node;
    int flag = 0, total;
    int cust_id;
    cin.ignore();
    ofstream file("Record.txt", ios::in | ios::app);
    cout << "\n\t => Enter customer name: ";
    getline(cin, current->name);
    cout << "\n\t => Enter Cnic No(34202-): ";
    getline(cin, current->cnic);
    cout << "\n\t => Enter Phone No: ";
    cin >> current->phone;
    current->no_of_days = checkerDays();
    if (choice == 3)
    {
    cout << "\n\t #LOW Class(Available-rooms = " << lowclass << ")" << endl;
        r:
        current = checkExisted(current);
        if(current->Room_No<=50 && current->Room_No>30){
            lowclass--;
            cout << "\n\t #Note: Remaining left low class rooms are = " << lowclass << endl;
            total = 2000 * current->no_of_days ;
            current->bill = total;
            cout << "\n\t => Your Total bill is RS : " << current->bill << "/-"<< endl;
            current->room_type = current->LowClass;
            cout << "\n\t => Customer ROOM TYPE is : " << current->room_type << endl;
        }
        else{
            cout<<"\n\tInvalid Room No :"<<endl;
            goto r;
        }
    }
    else if (choice == 2)
    {
    cout << "\n\t #Medium Class(Available-rooms = " << mediumclass << ")" << endl;
        r1:
        current = checkExisted(current);
        if(current->Room_No<=30 && current->Room_No>15){
            mediumclass--;
        cout << "\n\t #Note: Remaining left Medium Class rooms are = " << mediumclass << endl;
        total = 4000 * current->no_of_days;
        current->bill = total;
        cout << "\n\t => Your Total bill is RS : " << current->bill << "/-"<< endl;
        current->room_type = current->MediumClass;
        cout << "\n\t => Customer ROOM TYPE is : " << current->room_type << endl;
        }
        else{
            cout<<"\n\tInvalid Room No :"<<endl;
            goto r1;
        }
    }
    else if (choice == 1)
    {
    cout << "\n\t #VIP Class(Available-rooms = " << vipclass << ")" << endl;
        r2:
        current = checkExisted(current);
        if(current->Room_No<=15 && current->Room_No>0){
            vipclass--;
        cout << "\n\t #NoteRemaining left VIP rooms are = " << vipclass << endl;
        total = 8000 * current->no_of_days;
        current->bill = total;
        cout << "\n\t => Your Total bill is RS : " << current->bill << "/-"<< endl;
        current->room_type = current->VIPClass;
        cout << "\n\t => Customer ROOM TYPE is : " << current->room_type << endl;
        }
        else{
            cout<<"\n\tInvalid Room No :"<<endl;
            goto r2;
        }
    }
    srand(time(NULL));
    int c = rand()%10000;
    current->pass = c;
    cout << "\n\tTo Check your Details use this User-ID for login = " << current->name << endl;
    cout << "\n\tPassword: " << current->pass << endl;
    cout << "\n\tNote: Don't lose your password" << endl;
    current->next = start;
    start = current;
    cout << "\n\t\t\t -> User Registered and Room has been booked!." << endl;
    file << start->name << endl;
    file << start->cnic << endl;
    file << start->phone << endl;
    file << start->no_of_days << endl;
    file << start->bill << endl;
    file << start->pass << endl;
    file << start->Room_No << endl;
    file << start->room_type << endl;
    cout<<"----------------------------------"<<endl;
    file.close();
}
void Booking_Portal(){
    system("cls");
    Logo();
    cout << "\n\t\t\t==> Available Rooms" << endl;
    cout << "\n\t\t\t=> [ 1 ] Book VIP Rooms(1_15)"<< endl;
    cout << "\n\t\t\t=> [ 2 ] Book Medium Class Rooms(16_30)"<< endl;
    cout << "\n\t\t\t=> [ 3 ] Book Low Class Rooms(31_50)"<< endl;
    cout << "\n\t\t\t=> [ 4 ] Back to Menu"<< endl;
    choice=checkerr();
    switch(choice){
        case 1:
        Bookrooms(choice);
        system("pause");
        Booking_Portal();
        break;
       case 2:
        Bookrooms(choice);
        system("pause");
        Booking_Portal();
        break;
        case 3:
        Bookrooms(choice);
        system("pause");
        Booking_Portal();
        case 4:
        Menu();
        break;
    }
}
Node* readlinklist(Node* start){
    int count = 0;
        Node* newNode, *last;
        ifstream file("Record.txt");
        if(file.is_open())
        {
            while(file.good()){
                string blank_line;
                newNode = new Node();
                getline(file, newNode->name, '\n');
                getline(file, newNode->cnic, '\n');
                getline(file, newNode->phone, '\n');
                file >> newNode->no_of_days;
                file >> newNode->bill;
                file >> newNode->pass;
                file >> newNode->Room_No;
                file >> newNode->room_type;
                getline(file, blank_line, '\n');
                newNode->next = NULL;
                if(start == NULL){
                    start = newNode;
                    last = newNode;
                }
                else{
                    last->next = newNode;
                    last = newNode;
                }
            }
            file.close();
        }
        else
        {
            r:
            system("cls");
            cout << "\n\t\t [==] Hotel is empty!" << endl;
            cout << "\n\t\t [==] Press 1 for main manu\n"<< endl;
            cout << "\t\t [==] Press 2 for exit\n"<< endl;
            choice=checkerr();
            if (choice == 1){
                Menu();
            }
            else if(choice==2){
                exit(0);
            }
            else{
                goto r;
            }
        }
        // Sorting
        int swap;
        current=start;
        Node *temp=new Node;
        while(current->next!=NULL){
            temp=current->next;
            while(temp->next !=NULL){
                if(current->Room_No > temp->Room_No){
                    swap=current->Room_No;
                    current->Room_No = temp->Room_No;
                    temp->Room_No=swap;
                     string name = current->name;
                    current->name = temp->name;
                    temp->name = name;
                    //cnic
                    string cnic = current->cnic;
                    current->cnic = temp->cnic;
                    temp->cnic = cnic;
                    //phone
                    string phone = current->cnic;
                    current->cnic = temp->cnic;
                    temp->cnic = cnic;
                    //no of days
                    int no_of_days = current->no_of_days;
                    current->no_of_days = temp->no_of_days;
                    temp->no_of_days = no_of_days;
                    //bill
                    int bill = current->bill;
                    current->bill = temp->bill;
                    temp->bill = bill;
                    //pass
                    int pass = current->pass;
                    current->pass = temp->pass;
                    temp->pass = pass;
                }
                temp=temp->next;
            }
            current=current->next;
        }
        return start;
}
void show(Node* start){
    bool flag = false;
    system("cls");
    cout << "\n\t\t\t============================================================\n";
    cout << "\t\t\t+         C U S T O M E R  R E C O R D S                   +\n";
    cout << "\t\t\t============================================================\n\n";
    current = readlinklist(start);
    cout << "\n\t\t\tList OF Customers" << endl;
    cout << "\n\t\t\t------------------------------\n";
        while(current->next != NULL){
            cout << "\n\t\t\t Room No              : " << current->Room_No << endl;
            cout << "\t\t\t Customer name        : " << current->name << endl;
            cout << "\t\t\t CNIC                 : " << current->cnic << endl;
            cout << "\t\t\t Telephone            : " << current->phone << endl;
            cout << "\t\t\t No.of Days           : " << current->no_of_days << endl;
            cout << "\t\t\t Total Paid bill      : " << current->bill << endl;
            cout << "\t\t\t USERNAME             : " << current->name << endl;
            cout << "\t\t\t PASSWORD             : " << current->pass << endl;
            cout << "\t\t\t Your Room type       : " << current->room_type<< endl;
            cout << "\n\t\t\t------------------------------\n";
            current = current->next;
            flag = true;
        }
        if(flag == false){
            cout << "\n\n\n\t\t\t ====? Note: No Record Found!!  ====?" << endl;
        }
    getch();
    Menu();
}
void SearchRecords(Node* start){
    system("CLS");
    cout << "\n\t\t\t\t\t============================================================\n";
    cout << "\t\t\t\t\t+            S E A R C H  R E C O R D S                    +\n";
    cout << "\t\t\t\t\t============================================================\n\n";
    int found = 0;
    Node* search = readlinklist(start);
    cout << "\n\tEnter Room no to search data: ";
    cin >> id;
    while(search->next != NULL){
        if(search->Room_No == id){
            cout << "\n\t\t\t------------------------------\n";
            cout << "\n\t\t\t Room No              : " << search->Room_No << endl;
            cout << "\t\t\t Customer name        : " << search->name << endl;
            cout << "\t\t\t CNIC                 : " << search->cnic << endl;
            cout << "\t\t\t Telephone            : " << search->phone << endl;
            cout << "\t\t\t No.of Days           : " << search->no_of_days << endl;
            cout << "\t\t\t Total Paid bill      : RS " << search->bill << "/-" << endl;
            cout << "\t\t\t USERNAME             : " << search->name << endl;
            cout << "\t\t\t PASSWORD             : " << search->pass << endl;
            cout << "\t\t\t Your Room type       : " << search->room_type<< endl;
            cout << "\t\t\t------------------------------\n";
            found++;
        }
        search = search->next;
    }
    if(found == 0){
        cout << "\n\tNo Records Found, !" << endl;
    }
    getch();
    Menu();
}
Node* EditRecords(Node* start){
    int flag = 0;
    current = readlinklist(start);
    Node* nodeNew = new Node;
    int found = 0;
    Node* last;
    ifstream file("Record.txt", ios::in);
    ofstream newFile("Temp.txt", ios::out|ios::app);
    cout << "\n\tEnter Room no to Update RECORD: ";
    cin >> id;

    if(file.is_open()){
    while(!file.eof()){
        while(current->next != NULL){
            if(current->Room_No != id){
                newFile << current->name << endl;
                newFile << current->cnic << endl;
                newFile << current->phone << endl;
                newFile << current->no_of_days << endl;
                newFile << current->bill << endl;
                newFile << current->pass << endl;
                newFile << current->Room_No << endl;
                newFile << current->room_type << endl;
            }
            else{
                cout << "\n\t\t\t------------------------------\n";
                cout << "\n\t\t\t Room No              : " << current->Room_No << endl;
                cout << "\t\t\t Customer name        : " << current->name << endl;
                cout << "\t\t\t CNIC                 : " << current->cnic << endl;
                cout << "\t\t\t Telephone            : " << current->phone << endl;
                cout << "\t\t\t No.of Days           : " << current->no_of_days << endl;
                cout << "\t\t\t Total Paid bill      : RS " << current->bill << "/-" << endl;
                cout << "\t\t\t USERNAME             : " << current->name << endl;
                cout << "\t\t\t PASSWORD             : " << current->pass << endl;
                cout << "\t\t\t Your Room type       : " << current->room_type<< endl;
                cout << "\n\t\t\t------------------------------\n";
                found++;
                char ch;
                cout << "\n\tDo you want to update customer record? -> (y/n): ";
                cin >> ch;
                if(ch == 'y'){
                int choice;
                cout << "\n\tWhat to do you want to update? ";
                cout << "\n\tNote: our system only update these records!" << endl;
                cout << "\n\t1. Phone Number of customer." << endl;
                cout << "\n\t2. Changing in customer name?. " << endl;
                cout << "\n\t3. Changing in Customer Login-password. " << endl;
                cout << "\n\tChoose any of above: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cin.ignore();
                    cout << "\n\tEnter newPhone No: ";
                    getline(cin, current->phone);
                    cout << "\n\tPhone number updated" << endl;
                    break;
                case 2:
                    cin.ignore();
                    a:
                    cout << "\n\tEnter newName: ";
                    getline(cin, current->name);
                    cout << "\n\tName of customer has been changed" << endl;
                    break;
                case 3:
                    cout << "\n\tAssign new Password to user: ";
                    cin >> current->pass;
                    cout << "\n\tLogin password has been changed" << endl;
                    break;
                default:
                    cout << "\n\tNo more changes were made!." << endl;
                    }
                }
                else{
                    cout << "\n\tNo more further changes were made!" << endl;
                }
                newFile << current->name << endl;
                newFile << current->cnic << endl;
                newFile << current->phone << endl;
                newFile << current->no_of_days << endl;
                newFile << current->bill << endl;
                newFile << current->pass << endl;
                newFile << current->Room_No << endl;
                newFile << current->room_type << endl;
            }
            string blank_line;
            getline(file, nodeNew->name, '\n');
            getline(file, nodeNew->cnic, '\n');
            getline(file, nodeNew->phone, '\n');
            file >> nodeNew->no_of_days;
            file >> nodeNew->bill;
            file >> nodeNew->pass;
            file >> nodeNew->Room_No;
            file >> nodeNew->room_type;
            nodeNew->next = NULL;
            current = current->next;
            if(start == NULL){
                start = nodeNew;
                last = nodeNew;
            }
            else{
                last->next = nodeNew;
                last = nodeNew;
            }
            }
        if(found == 0){
            cout << "\n\t Enter Valid Room No !!. " << endl;
            getch();
            Menu();
        }
            // }
        file.close();
        newFile.close();
        remove("Record.txt");
        rename("Temp.txt", "Record.txt");
        // cout << "File rename successfully" << endl;
        break;
        }
    }
    else{
        cout << "\n\t\tUnable to open file!!" << endl;
    }
    getch();
    Menu();
    return start;
}
void Menu(){
        string name;
    int choice;
    Node* start = NULL;
           system("cls");
           cout << endl << endl;
            cout << "\t\t\t\t\t============================================================\n";
            cout << "\t\t\t\t\t+    H O T E L  M A N A G E M E N T  S Y S T E M  Vr.2.1   +\n";
            cout << "\t\t\t\t\t============================================================\n ";
            cout << "\n\t\t\t\t\t _________________________\t _________________________\n";
            cout << "\t\t\t\t\t|\t\t\t  |\t|\t\t\t  |"<< endl; 
            cout << "\t\t\t\t\t| [ 1 ] Visit Hotel First |\t| [ 2 ] Display Records\t  |" << endl;
            cout << "\t\t\t\t\t|_________________________|\t|_________________________|" << endl;
            cout << "\n\t\t\t\t\t _________________________\t _________________________\n";
            cout << "\t\t\t\t\t|\t\t\t  |\t|\t\t\t  |"<< endl; 
            cout << "\t\t\t\t\t| [ 3 ] Search Records\t  |\t| [ 4 ] Update Records\t  |" << endl;
            cout << "\t\t\t\t\t|_________________________|\t|_________________________|" << endl;
            cout << "\n\t\t\t\t\t _________________________\t\n";
            cout << "\t\t\t\t\t|\t\t\t  |\t"<< endl; 
            cout << "\t\t\t\t\t| [ 5 ] Exit the Program  |" << endl;
            cout << "\t\t\t\t\t|_________________________|" << endl;
            cout << "\n\n\t\t\t\t\t============================================================\n";
            cout << "\t\t\t\t\t+\t       M A N A G E D  B Y  Z . K . A . S\t   +\n";
            cout << "\t\t\t\t\t============================================================\n ";
            choice=checkerr();
        switch (choice)
        {
           case 1:
               Booking_Portal();
               break;
           case 2:
               show(start);
               break;
           case 3:
               SearchRecords(start);
               break;
           case 4:
               EditRecords(start);
               break;
           case 5:
                system("COLOR 00");
                cout << "\n\n\n";
                cout << "Thanks for using this software 🥰!";
                cout << "\n\n\n";
                cout << "\t\t\t\t\tshutting down, Please Wait ";
                char load = 219;
                for(int i = 0; i < 40; i++){
                    cout << load;
                    if(i < 10){
                        Sleep(40);
                    }
                    if(i >= 10 && i < 20){
                        Sleep(20);
                    }
                    if(i >= 10){
                        Sleep(15);
                    }
                }
               exit(0);
               break;
           default:
               Menu();
        }
};

class Login :public ZKAS{
    private:
        int choice;
        int tryy=3, tryy1=3;
        string userName, pass;
        char ps = ' ';
        int password;
    public:
        void loginAsAdmin(){
            cout<<"\n\t\t\t => Enter User-Name: ";
            cin>>userName;
            cout<<"\n\t\t\t => Enter Password: ";
            while(ps != 13){
                ps = getch();
                if(ps == 13)
                    break;

                if (ps == 8){
                    if(pass.size() != 0){
                        cout << "\b \b";
                        pass.erase(pass.size()-1);
                    }
                }
                if((ps >47 && ps < 56)|| (ps >64 && ps < 91) || (ps > 96 && ps < 123)){
                    pass+= ps;
                    cout << "*";
                }
            }
            if(userName=="zkas" && pass=="zkas123"){
                system("COLOR 00");
                cout << "\n\n\n";
                cout << "\t\t\t\t\tLogging, Please Wait ";
                char load = 219;
                for(int i = 0; i < 40; i++){
                    cout << load;
                    if(i < 10){
                        Sleep(50);
                    }
                    if(i >= 10 && i < 20){
                        Sleep(30);
                    }
                    if(i >= 10){
                        Sleep(15);
                    }
                }
                system("cls");
                Menu();
            }
            else{
				if(tryy==0){
                    system("COLOR 00");
                    cout << "\n\n\n\t\t\tOOPS!! You Loss All Your Trys. Wait For A Mint...";
                    char load = 219;
                    for (int i = 0; i < 40; i++)
                    {
                        cout << load;
                        if (i < 10){
                        Sleep(50);
                        }
                        if (i >= 10 && i < 20){
                            Sleep(40);
                        }
                            if (i >= 10){
                            Sleep(15);
                        }
                    }
                    system("cls");
                    login();
                }
                else{
                    cout<<"\n\t\t\t\t\t => Enter Valid Login Details!!!"<<endl;
                    Sleep(800);
                    system("CLS");
                    cout << "\n\n\t\t\t\t\t============================================================\n";
                    cout << "\t\t\t\t\t+    H O T E L  M A N A G E M E N T  S Y S T E M  Vr.2.1   +\n";
                    cout << "\t\t\t\t\t============================================================\n\n";
                    cout<<"\n\t\t\t\t\t --> You Have trys "<<tryy<<" Left"<<endl;
                    tryy--;
                    loginAsAdmin();
                }
            }
        }
    public:

        Node* Readlinklist(Node* start){
            Node* newNode, *last;
            ifstream file("Food.txt");
            if(file.is_open())
            {
                while(file.good()){
                    string blank_line;
                    newNode = new Node();
                    getline(file, newNode->food, '\n');
                    // getline(file, blank_line, '\n');
                    newNode->next = NULL;
                    if(start == NULL){
                        start = newNode;
                        last = newNode;
                    }
                    else{
                        last->next = newNode;
                        last = newNode;
                    }
                }
                file.close();
            }
            return start;
        }

        void qInsert() {
            string Food;
            cout<<"\n\n\tEnter Food Name : ";
            cin>>Food;
            if (rear == NULL) {
                rear =new Node1();
                rear->next1 = NULL;
                rear->food = Food;
                front = rear;
            } else {
                temp=new Node1();
                rear->next1 = temp;
                temp->food = Food;
                temp->next1 = NULL;
                rear = temp;
            }
            cout<<"\n\t\t 🤩 Your Order have been Submitted!!"<<endl;
        }
        void qDelete() {
            temp = front;
            if (front == NULL) {
                cout<<"\n\t\tNothing To Take"<<endl;
                return;
            }
            else
            if (temp->next1 != NULL) {
                temp = temp->next1;
                cout<<"\n\t\t +> Your Order have been deQueue : "<<front->food<<endl;
                free(front);
                front = temp;
            } else {
                cout<<"\n\t\t +> Your Order have been deQueue : "<<front->food<<endl;
                free(front);
                front = NULL;
                rear = NULL;
            }
        }
        void qDisplay() {
            temp = front;
            if ((front == NULL) && (rear == NULL)) {
                cout<<"\n\t\t :) No Order to display"<<endl;
                return;
            }
            cout<<"\n\t => Remaining Orders are: "<<endl;
            cout<<"\t________________________________________________________"<<endl<<endl;
            while (temp != NULL) {
                cout<<"\t"<<temp->food<<"\t";
                temp = temp->next1;
            }
            cout<<"\n\t________________________________________________________"<<endl;
        }

        void orderFood(Node *start){
            int i=1;
            current=Readlinklist(start);
            cout<<"\n\t\t+------------------------+------------------------------+-----------------------+"<<endl;
            while(current!=NULL){
                cout<<"\t\t "<<i++<<" : "<<current->food<<"  ";
                current=current->next;
            }
            cout<<"\n\t\t+------------------------+------------------------------+-----------------------+"<<endl;
            cout<<"\n\n\n\n\t\t\t=> Press 1 :: For Order"<<endl;
            cout<<"\n\t\t\t=> Press 2 :: For Take Order"<<endl;
            cout<<"\n\t\t\t=> Press 3 :: For Display Order"<<endl;
            choice=checkerr();
            if(choice==1){
                qInsert();
            }
            else if(choice==2){
                qDelete();
            }
            else if(choice==3){
                qDisplay();
            }
            else{
                system("CLS");
                orderFood(start);
            }
        }

        void loginAsUser(){
            string username;
            int password;
            int found = 0;
            cin.ignore();
            cout << "\n\t\t\t => Enter Username: ";
            getline(cin, username);
            a:
            cout << "\n\t\t\t => Enter Password: ";
            cin >> password;
            Node* user = new Node;
            user = readlinklist(start);
            bool valid = false;
            while(!valid){
                if(cin.good()){
                    valid = true;
                }
                else{
                    cin.clear();
                    cin.ignore(123, '\n');
                    cout << "Note: please enter an valid integer, string are not allowed!" << endl;
                    goto a;
                }
            }
            
            system("COLOR 00");
                    cout << "\n\n\n\t\t\t Signing in, Please Wait ";
                    char load = 219;
                    for (int i = 0; i < 40; i++)
                    {
                        cout << load;
                        if (i < 10){
                        Sleep(50);
                        }
                        if (i >= 10 && i < 20){
                            Sleep(40);
                        }
                            if (i >= 10){
                            Sleep(15);
                        }
                    }
            system("cls");
             while(user->next != NULL){
                if(user->name == username && user->pass == password){
                system("CLS");
                    d:
        	        cout << "\n\n\t\t\t\t\t============================================================\n";
                    cout << "\t\t\t\t\t+    H O T E L  M A N A G E M E N T  S Y S T E M  Vr.2.1   +\n";
                    cout << "\t\t\t\t\t============================================================\n ";
                    cout << "\n\t\t\t\t\t _________________________\t _________________________\n";
                    cout << "\t\t\t\t\t|\t\t\t  |\t|\t\t\t  |"<< endl; 
                    cout << "\t\t\t\t\t| [ 1 ] HOTEL DETAILS     |\t| [ 2 ] ORDER FOOD        |" << endl;
                    cout << "\t\t\t\t\t|_________________________|\t|_________________________|" << endl;
                    choice=checkerr();
                    if(choice==1){
                        cout<<"\n\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
                        cout<<"\n\t\t\t Total Availables Rooms: "<<total<<endl;
                        cout<<"\n\t\t\t 1) VIP Room           : "<<vipclass<<endl;
                        cout<<"\n\t\t\t 2) Low Class Rooms    : "<<lowclass<<endl;
                        cout<<"\n\t\t\t 3) Medium Class Rooms : "<<mediumclass<<endl;
                        cout<<"\n\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
                    b:
                        cout<<"\n\t\t\t => Would you want to LogOut(1) or OrderFood(2) :"<<endl;
                        choice=checkerr();
                        if(choice==1){
                            system("COLOR 00");
                            cout << "\n\n\t\t\t Logouting, Please Wait ";
                            char load = 219;
                            for (int i = 0; i < 40; i++)
                            {
                                cout << load;
                                if (i < 10){
                                    Sleep(50);
                                }
                                if (i >= 10 && i < 20){
                                    Sleep(40);
                                }
                                if (i >= 10){
                                    Sleep(15);
                                }
                            }
                            system("cls");
                            login();
                        }
                        else if(choice==2){
                            system("CLS");
                            orderFood(start);
                            goto b;
                        }
                        else{
                            system("CLS");
                            goto b;
                        }
                    }
                    else if(choice==2){
                        system("CLS");
                        orderFood(start);
                        goto b;
                    }
                    else{
                        system("CLS");
                        goto d;
                    }
                    found++;  
                }
                user = user->next;
            }
        if(found == 0){
            if(tryy==0){
                    cout<<"\n\t\t\t\t\t => OOPS!! You Loss All Your Trys. Wait For A Mint..."<<endl;
                    Sleep(2000);
                    login();
                }
                else{
                    cout<<"\n\t\t\t\t\t => Enter Valid Login Details!!!"<<endl;
                    Sleep(800);
                    system("CLS");
                    cout << "\n\n\t\t\t\t\t============================================================\n";
                    cout << "\t\t\t\t\t+    H O T E L  M A N A G E M E N T  S Y S T E M  Vr.2.1   +\n";
                    cout << "\t\t\t\t\t============================================================\n\n";
                    cout<<"\n\t\t\t\t\t --> You Have trys "<<tryy<<" Left"<<endl;
                    tryy--;
                    loginAsUser();
                }
        }
            else{
                cout << "User Logged-in Successfully, " << endl;
            }
        }
        void login(){

			system("CLS");
            p:
            Logo();
            cout << "\n\t\t\t\t _________________________\t _________________________\n";
            cout << "\t\t\t\t|\t\t\t  |\t|\t\t\t  |"<< endl; 
            cout << "\t\t\t\t| [ 1 ] LOGIN             |\t| [ 2 ] EXIT THE PROGRAM  |" << endl;
            cout << "\t\t\t\t|_________________________|\t|_________________________|" << endl;
            choice=checkerr();
            if(choice==1){
                system("CLS");
                z:
                cout << "\n\n\t\t\t\t\t============================================================\n";
                cout << "\t\t\t\t\t+    H O T E L  M A N A G E M E N T  S Y S T E M  Vr.2.1   +\n";
                cout << "\t\t\t\t\t============================================================\n ";
                cout << "\n\t\t\t\t\t _________________________\t _________________________\n";
                cout << "\t\t\t\t\t|\t\t\t  |\t|\t\t\t  |"<< endl; 
                cout << "\t\t\t\t\t| [ 1 ] LOGIN AS ADMIN    |\t| [ 2 ] LOGIN AS USER     |" << endl;
                cout << "\t\t\t\t\t|_________________________|\t|_________________________|" << endl;
                cout << "\n\t\t\t\t\t ______________________________\t\n";
                cout << "\t\t\t\t\t|\t\t\t       |"<< endl; 
                cout << "\t\t\t\t\t| [ 3 ] BACK TO LOGIN PANEL    |\t" << endl;
                cout << "\t\t\t\t\t|______________________________|\t" << endl << endl;
                cout << "\t\t\t\t\t============================================================\n ";
                choice=checkerr();
                if(choice==1){
                    loginAsAdmin();
                }
                else if(choice==2){
                    loginAsUser();
                }
                else if(choice==3){
                    system("cls");
                    system("COLOR 00");
                    cout << "\n\n\n\t\t\t Loading, Please Wait";
                    char load = 219;
                    for (int i = 0; i < 40; i++)
                    {
                        cout << load;
                        if (i < 10){
                            Sleep(100);
                        }
                        if (i >= 10 && i < 20){
                            Sleep(100);
                        }
                        if (i >= 10){
                            Sleep(15);
                        }
                    }
                    system("cls");
                    login();
                }
                else{
                    system("CLS");
                    goto z;
                }
            }
            else if(choice==2){
                exit(2);
            }
            else{
                login();
            }
        }
};


int main(){
    // Intro i;
    // i.Front();
    Login obj;
    obj.login();
    // Menu();
    return 0;
}
void Logo()
{
	cout << "\n\n";
	for(int i = 0; i < 2; i++){
		cout << "\t\t*";
		for(int j = 0; j < 92 ; j++){
			cout << "*";
		}
			cout << endl;
	}
	for(int j = 0; j < 1; j++){
			cout << "\t\t+";
			for(int i = 0; i < 3; i++){
				cout << "+";
			}
			cout << "\t\t\t\t\t\t\t\t\t\t\t ";
			for(int i = 0; i <= 3; i++){
				cout << "+";
			}
			cout << endl;
		}
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
				cout << "+";
			}
		    cout << "\t\t\t$$$$$$$$$$   $$    $$   $$$$$$$$   $$$$$$$$          \t\t ";
			for(int i = 0; i <= 3; i++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t        $$   $$   $$    $$    $$   $$                \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t$$$$$$$$$$   $$$$$$     $$$$$$$$   $$$$$$$$          \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t$$           $$   $$    $$    $$         $$          \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t$$$$$$$$$$   $$    $$   $$    $$   $$$$$$$$          \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t                                                     \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t$$    $$  $$$$$$$$  $$$$$$$$$$  $$$$$$$$  $$         \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t$$    $$  $$    $$      $$      $$        $$         \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t$$$$$$$$  $$    $$      $$      $$$$$$$$  $$         \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t$$    $$  $$    $$      $$      $$        $$         \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << endl;
			cout << "\t\t";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
			cout << "\t\t\t$$    $$  $$$$$$$$      $$      $$$$$$$$  $$$$$$$$   \t\t ";
			for(int j = 0; j <= 3; j++){
			cout << "+";
			}
		cout << endl;
	for(int j = 0; j < 1; j++){
			cout << "\t\t+";
			for(int i = 0; i < 3; i++){
				cout << "+";
			}
			cout << "\t\t\t\t\t\t\t\t\t\t\t ";
			for(int i = 0; i <= 3; i++){
				cout << "+";
			}
			cout << endl;
	}
	for(int i = 0; i < 2; i++){
		cout << "\t\t*";
		for(int j = 0; j < 92 ; j++){
			cout << "*";
		}
			cout << endl;
	}
}