#include<iostream>
#include<string.h>

using namespace std;

class employee{
public:
    employee();
    ~employee();
    virtual void pay() = 0;
    virtual void promate(int increment = 0);
    virtual void display() = 0;
protected:
    char* name;
    int individualnum;
    int grade;
    float accumpay;
    static int employeenum;
};

class technician: public employee{
public:
    technician();
    void pay();
    void promate(int);
    void display();
private:
    float hourlyrate;
    int workhour;
};

class salesman: virtual public employee{
public:
    salesman();
    void pay();
    void promate(int);
    void display();
protected:
    float commerate;
    float sales;
};

class manager: virtual public employee{
public:
    manager();
    void pay();
    void promate(int);
    void display();
protected:
    float monthlypay;
};

class salesmanager: public salesman, public manager{
public:
    salesmanager();
    void pay();
    void promate(int);
    void display();
};


int employee::employeenum = 1000;
employee::employee(){
    char namestr[20];
    cout<<"input next name:";
    cin>>namestr;
    name = new char[strlen(namestr)+1];
    strcpy(name, namestr);
    individualnum = employeenum++;
    grade = 1;
    accumpay = 0;
}
employee::~employee(){
    delete name;
}
void employee::promate(int increment){
    grade += increment;
}

technician::technician(){
    hourlyrate = 100;
}
void technician::pay(){
    cout<<"input working hours:";
    cin>>workhour;
    accumpay = hourlyrate * workhour;
    cout<<"technician:"<<name<<"\tindividualnum:"<<individualnum<<"\taccumpay:"<<accumpay<<endl;
}
void technician::promate(int){
    employee::promate(2);
}
void technician::display(){
    cout<<"technician:"<<name<<"\tgrade:"<<grade<<"\tindividualnum:"<<individualnum<<"\taccumpay:"<<accumpay<<endl;
}

salesman::salesman(){
    commerate = 0.04;
}
void salesman::pay(){
    cout<<"input sales:";
    cin>>sales;
    accumpay = commerate * sales;
    cout<<"salesman:"<<name<<"\tindividualnum:"<<individualnum<<"\taccumpay:"<<accumpay<<endl;
}
void salesman::promate(int){
    employee::promate(0);
}
void salesman::display(){
    cout<<"salseman:"<<name<<"\tgrade:"<<grade<<"\tindividualnum:"<<individualnum<<"\taccumpay:"<<accumpay<<endl;
}

manager::manager(){
    monthlypay = 8000;
}
void manager::pay(){
    accumpay = monthlypay;
    cout<<"manager:"<<name<<"\tindividualnum:"<<individualnum<<"\taccumpay:"<<accumpay<<endl;
}
void manager::promate(int){
    employee::promate(3);
}
void manager::display(){
    cout<<"manager:"<<name<<"\tgrade:"<<grade<<"\tindividualnum:"<<individualnum<<"\taccumpay:"<<accumpay<<endl;
}

salesmanager::salesmanager(){
    monthlypay = 5000;
    commerate = 0.05;
}
void salesmanager::pay(){
    cout<<"input sales:";
    cin>>sales;
    accumpay = monthlypay + (commerate * sales);
    cout<<"salesmanager:"<<name<<"\tindividualnum:"<<individualnum<<"\taccumpay:"<<accumpay<<endl;
}
void salesmanager::promate(int){
    employee::promate(3);
}
void salesmanager::display(){
    cout<<"salesmanager:"<<name<<"\tgrade:"<<grade<<"\tindividualnum:"<<individualnum<<"\taccumpay:"<<accumpay<<endl;
}

int main(){
    technician t1;
    salesman s1;
    manager m1;
    salesmanager sm1;
    employee *emp[4] = {&t1, &s1, &m1, &sm1};
    for(int i = 0; i < 4; i++){
        emp[i]->promate();
        emp[i]->pay();
        emp[i]->display();
    }
    return 0;
}
