//This Program Is Created By PatelDharam23CE092.
//Purpose :- Update the CHARUSAT employee system (practical 8) as per given class diagram.
//concept :- Function overriding.
#include<iostream>
#include<stdlib.h>
using namespace std;
class employee
{
private :
    int employeid;
    string name;
    string qualification;
    float exp;
    long long int contact_number;
    static float exp_sum;
    static float avg_exp;
protected :
    void getdata()
    {
        back :
        cout<<"Enter an Employee ID :";
        cin>>employeid;
        if(employeid>9999 || employeid<1000){
            cout<<endl<<"Please Enter Valid Employee ID"<<endl;
            goto back;
        }
        fflush(stdin);
        cout<<endl;
        cout<<"Employee Name   : ";
        getline(cin,name);
        fflush(stdin);
        cout<<"Qualification   : ";
        getline(cin,qualification);
        fflush(stdin);
        cout<<"Experience      : ";
        cin>>exp;
        exp_sum=exp_sum+exp;
        fflush(stdin);
        cout<<"Contact Number  : ";
        cin>>contact_number;
        fflush(stdin);
    }
    void putdata() {
        cout << "Employee ID     : " << employeid << endl;
        cout << "Employee Name   : " << name << endl;
        cout << "Qualification   : " << qualification << endl;
        cout << "Experience      : " << exp << " Years" << endl;
        cout << "Contact Number  : " << contact_number << endl;
    }

    int searchid(int id)
    {
        if(id==employeid)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
public :
    static void display_average_exp(int x,int y){
        avg_exp=exp_sum/(x+y);
        cout<<"The Average Of employee Experience is : "<<avg_exp;
    }
};
float employee :: exp_sum=0;
float employee :: avg_exp=0;


class teaching_employee : public employee
{
private :
    string designation;
    string specialization;
    string pay_scale;
public :
    void getdata(){

        employee::getdata();
        cout<<"Designation     : ";
        getline(cin, designation);
        cout<<"Specialization  : ";
        getline(cin,specialization);
        cout<<"Pay Scale       :";
        getline(cin,pay_scale);

    }
    void putdata(){
        cout<<"Designation     : "<<designation<<endl;
        cout<<"Specialization  : "<<specialization<<endl;
        cout<<"Pay Scale       :"<<pay_scale<<endl;
    }
    int searchid(int id){
    if(employee::searchid(id)){
        employee::putdata();
        cout<<"Designation     : "<<designation<<endl;
        cout<<"Specialization  : "<<specialization<<endl;
        cout<<"Pay Scale       :"<<pay_scale<<endl;
        return 0;
        }
    else{
        return 1;
    }
    }
};
class nonteching_employee : public employee
{
private :
    int salary;
public :
    void getdata() {
//by default on calling of non_teaching's employee data first it call get data of employee
        employee::getdata();
        cout<<"Salary         : ";
        cin>>salary;
    }
    void putdata(){
        cout<<"Salary          : "<<salary;
    }
    int searchid(int id){
        if(employee::searchid(id)){
//by default on calling of non_teaching's employee data first it call get data of employee
            employee::putdata();
            cout<<"Salary     : "<<salary;
            return 0;
        }
       else {
        return 1;
       }
    }
};
int main()
{
    teaching_employee a[500];
    nonteching_employee b[500];
    char ch='y';
    int i=0;
    int rv;
    int id;
    int op;
    int no_of_teaching_employee;
    int no_of_non_teaching_employee;
    int choice;
    cout<<"Enter Number Of Teaching Employee : ";
    cin>>no_of_teaching_employee;
    cout<<"Enter Number Of Non Teaching Employee : ";
    cin>>no_of_non_teaching_employee;
    cout<<endl;
    while(i<no_of_teaching_employee)
    {

        a[i].getdata();
        i++;
        cout<<endl;
    }
    i=0;
    if(no_of_non_teaching_employee>0){
    cout<<"Enter The Data For Non Teaching Employee"<<endl;
    }
    while(i<no_of_non_teaching_employee)
    {

        b[i].getdata();
        i++;
        cout<<endl;
    }
    ch='Y';
    system("CLS");
    main_menu :
    cout<<"Enter Your Choice"<<endl;
    cout<<"1.To Get Employee Details "<<endl;
    cout<<"2.To Get Average Employee Expirence "<<endl;
    vapas :
    cout<<endl<<"Enter Your Choice : ";
    cin>>choice;
    switch(choice){
case 1:
    cout<<"Enter Employee ID to Get Employee Details :-"<<endl<<endl;
    while(ch!='n' && ch!='N')
    {
        cout<<"Enter Employee ID : ";
        cin>>id;
        cout<<endl;
        for(int j=0; j<no_of_teaching_employee; j++)
        {

            rv=a[j].searchid(id);
            if(rv==0){
                    break;}

        }
        for(int j=0; j<no_of_non_teaching_employee; j++)
        {

            rv=b[j].searchid(id);
            if(rv==0){
                    break;}

        }
        if(rv)
        {
            cout<<endl<<"Entered Employee ID is Invalid , Please Enter Valid Employee ID"<<endl;
        }
        cout<<endl<<"Press 'Y' to Get More Employee Details or Enter 'N' to Exit : ";
        cin>>ch;
    }
    cout<<"Enter \"1\" to go back to main menu or press any key to exit"<<endl;
    cin>>op;
    if(op==1){
        goto main_menu;
    }
    else{
    break;
    }
case 2:
    employee :: display_average_exp(no_of_teaching_employee,no_of_non_teaching_employee);
    cout<<endl<<"Enter \"1\" to go back to main menu or press any key to exit"<<endl;
    cin>>op;
    if(op==1){
        goto main_menu;
    }
    else{
    break;
    }
default :
    cout<<"Enter Valid Choice";
    goto vapas;
        }
    return 0;
}

