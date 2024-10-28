#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<windows.h>
using namespace std;

void menu();
void cpascode();


class hospital {
public:
    virtual void get() = 0;
    virtual void show() = 0;
};

class info : public hospital {
public:
    char name[50], time[50];
    int num, age;

    void get() {
        system("cls");
        cin.sync();
        cout << "\n Enter the patient name =";
        cin.getline(name, 50);
        cout << "\n Enter the appointment time =";
        cin.getline(time, 50);
        cout << "\n Enter age =";
        cin >> age;
        cout << "\n Enter appointment no =";
        cin >> num;
    }

    void show() {
        cout << "\n Name =" << name;
        cout << "\n Age =" << age;
        cout << "\n No =" << num;
        cout << "\n Time =" << time;
    }
};

class staff : public info {
public:
    info a1;

    void get() {
        system("cls");
        ofstream out("Staff.txt", ios::app | ios::binary);
        a1.get();
        out.write((char*)&a1, sizeof(info));
        out.close();
        cout << "Your entry has been saved";
        getch();
        menu();
    }

    void show() {
        ifstream in("Staff.txt");
        if (!in) {
            cout << "No data in the file";
            cout << "\n Press any key to continue :";
            getch();
            menu();
        }
        else {
            while (!in.eof()) {
                in.read((char*)&a1, sizeof(info));
                a1.show();
            }
            in.close();
            cout << "Press enter to continue ";
            getch();
            menu();
        }
    }
};

class Dr_one : public info {
public:
    info a1;

    void get() {
        system("cls");
        ofstream out("Dr_one.txt", ios::app | ios::binary);
        a1.get();
        out.write((char*)&a1, sizeof(info));
        out.close();
        cout << "Your entry has been saved";
        getch();
        menu();
    }

    void show() {
        ifstream in("Dr_one.txt");
        if (!in) {
            cout << "No data in the file";
            cout << "\n Press any key to continue :";
            getch();
            menu();
        }
        else {
            while (!in.eof()) {
                in.read((char*)&a1, sizeof(info));
                a1.show();
            }
            in.close();
            cout << "Press enter to continue ";
            getch();
            menu();
        }
    }
};

class Dr_two : public info {
public:
    info a1;

    void get() {
        system("cls");
        ofstream out("Dr_two.txt", ios::app | ios::binary);
        a1.get();
        out.write((char*)&a1, sizeof(info));
        out.close();
        cout << "Your entry has been saved";
        getch();
        menu();
    }

    void show() {
        ifstream in("Dr_two.txt");
        if (!in) {
            cout << "No data in the file";
            cout << "\n Press any key to continue :";
            getch();
            menu();
        }
        else {
            while (!in.eof()) {
                in.read((char*)&a1, sizeof(info));
                a1.show();
            }
            in.close();
            cout << "Press enter to continue ";
            getch();
            menu();
        }
    }
};

class management : public Dr_one {
public:
    char all[1000];
    char name[100], age[30], sal[30], pos[25];

    void get() {
        ofstream out("management.txt", ios::app);
        system("cls");
        cin.sync();
        cout << "\n Enter name :";
        cin.getline(name, 100);
        cout << "\n Enter age :";
        cin.getline(age, 30);
        cout << "\n Enter salary :";
        cin.getline(sal, 30);
        cout << "\n Enter working position :";
        cin.getline(pos, 25);

        out << "\nName=" << name << "\nage=" << age << "\nsalary=" << sal << "\nWorking position=" << pos;
        out.close();
        cout << "\nYour information has been saved :\n\t Press any key to continue";
        getch();
        menu();
    }

    void show() {
        ifstream in("management.txt");
        if (!in) {
            cout << "File open error";
        }
        while (!in.eof()) {
            in.getline(all, 1000);
            cout << all << "\n";
        }
        in.close();
        cout << "\n\t Press any key to continue : ";
        getch();
        menu();
    }
};
void menu() {
    int choice;
    system("cls");
    cout << "\n\t\t---Hospital Management System---";
    cout << "\n\n\t\t1. Add Staff";
    cout << "\n\t\t2. Add Doctor (Dr. One)";
    cout << "\n\t\t3. Add Doctor (Dr. Two)";
    cout << "\n\t\t4. Add Management";
    cout << "\n\t\t5. Display Staff";
    cout << "\n\t\t6. Display Doctor (Dr. One)";
    cout << "\n\t\t7. Display Doctor (Dr. Two)";
    cout << "\n\t\t8. Display Management";
    cout << "\n\t\t9. Exit";
    cout << "\n\n\t\tEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        {
            staff s;
            s.get();
            break;
        }
    case 2:
        {
            Dr_one d1;
            d1.get();
            break;
        }
    case 3:
        {
            Dr_two d2;
            d2.get();
            break;
        }
    case 4:
        {
            management m;
            m.get();
            break;
        }
    case 5:
        {
            staff s;
            s.show();
            break;
        }
    case 6:
        {
            Dr_one d1;
            d1.show();
            break;
        }
    case 7:
        {
            Dr_two d2;
            d2.show();
            break;
        }
    case 8:
        {
            management m;
            m.show();
            break;
        }
    case 9:
        exit(0);
    default:
        cout << "\nInvalid Choice! Please try again.";
    }
}

int main()
 {
    menu();
    return 0;
}