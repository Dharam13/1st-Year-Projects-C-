//This Program Is Created By PatelDharam23CE092.
//Purpose :- Develop a C++ program for library management system.
//concept :- Virtual class,hybrid inheritance.
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>
using namespace std;

class literature {
private :
    long int uni_id;
    string title;
public :
    void getdata() {
        cout << "***** Add Book Data *****" << endl;
        cout << "ID : ";
        cin >> uni_id;
        fflush(stdin);
        cout << "Title : ";
        getline(cin, title);
    }
    void putdata() {
        cout << left << setw(15) << uni_id << left << setw(15) << title;
    }
};
//e_literature class is virtual publicly inherited from literature class;
class e_literature : virtual public literature {
private :
    string doi;
public :
    void getdata() {
        cout << "DOI : ";
        fflush(stdin);
        getline(cin, doi);
    }
    void putdata() {
        cout << doi;
    }
};
//Hard_bound class is virtual publicly inherited from literature class;
class hard_bound : virtual public literature {
private :
    int number_of_copies;
public :
    void getdata() {
        cout << "In stock copies : ";
        cin >> number_of_copies;
    }
    void putdata() {
        cout << number_of_copies;
    }
};
//booksclass is virtual publicly inherited from e_literature and Hard_bound class;
class books : virtual public hard_bound , virtual public e_literature {
private :
    int isbn;
    int book_type;
    char ch;
public :
    void getdata() {
        literature::getdata();
        cout << "ISBN : ";
        cin >> isbn;
        cout << "(E)copy or (H)ardbound : ";
        cin >> ch;
        if (ch == 'E' || ch == 'e') {
            book_type = 1;
            e_literature::getdata();
        }
        if (ch == 'H' || ch == 'h') {
            book_type = 2;
            hard_bound::getdata();
        }
    }
    void putdata() {
        literature::putdata();
        cout << left << setw(15) << isbn;
        if (book_type == 1) {
            e_literature::putdata();
        }
        if (book_type == 2) {
            hard_bound::putdata();
        }
    }
};
//magazines class is virtual publicly inherited from e_literature and Hard_bound class;
class magazines : virtual public hard_bound , virtual public e_literature {
private :
    int issn;
    char ch;
    int m_type;
public :
    void getdata() {
        literature::getdata();
        cout << "ISSN : ";
        cin >> issn;
        cout << "(E)copy or (H)ardbound : ";
        cin >> ch;
        if (ch == 'E' || ch == 'e') {
            m_type = 1;
            e_literature ::getdata();
        }
        else if (ch == 'H' || ch == 'h') {
            m_type = 2;
            hard_bound::getdata();
        }
    }
    void putdata() {
        literature::putdata();
        cout << left << setw(15) << issn;
        if (m_type == 1) {
            e_literature::putdata();
        }
        if (m_type == 2) {
            hard_bound::putdata();
        }
    }
};

char enterchoice() {
    char ch;
    cout << endl << "Enter M to go to main menu or press any key to exit : ";
    cin >> ch;
    cout << endl;
    return ch;
}

int main() {
    int choice;
    int book_count = 0, magazine_count = 0;

    books* ptr_b[500];
    magazines* ptr_m[500];

    char ch = 'm';

    while (ch == 'M' || ch == 'm') {
        cout << endl << "Enter 1 : Add Book Data" << endl;
        cout << "Enter 2 : Add Magazine Data" << endl;
        cout << "Enter 3 : List All Books" << endl;
        cout << "Enter 4 : List All Magazine" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                ptr_b[book_count] = new books();
                ptr_b[book_count]->getdata();
                book_count++;
                ch = enterchoice();
                break;

            case 2:
                ptr_m[magazine_count] = new magazines();
                ptr_m[magazine_count]->getdata();
                magazine_count++;
                ch = enterchoice();
                break;

            case 3:
                for (int i = 0; i < book_count; ++i) {
                    ptr_b[i]->putdata();
                    cout << endl;
                }
                ch = enterchoice();
                break;

            case 4:
                for (int i = 0; i < magazine_count; ++i) {
                    ptr_m[i]->putdata();
                    cout << endl;
                }
                ch = enterchoice();
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    for (int i = 0; i < book_count; ++i) {
        delete ptr_b[i];
    }

    for (int i = 0; i < magazine_count; ++i) {
        delete ptr_m[i];
    }

    return 0;
}

