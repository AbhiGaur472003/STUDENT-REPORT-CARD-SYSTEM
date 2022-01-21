#include<iostream>
#include<fstream>
using namespace std;

class Student{
    public:
    int roll_no;
    int m_mark,e_mark,s_mark,h_mark,ss_mark;
    string name;
    float avg;
    char grad;

    void Calculate(){
        avg=(m_mark+e_mark+s_mark+h_mark+ss_mark)/5;
        if(avg >=85){
            grad='A';
        }else if(avg <85 && avg >=75){
            grad='B';
        }else if(avg < 75 && avg >=65){
            grad='C';
        }else if(avg < 65 && avg >=55){
            grad='D';
        }else if(avg < 55 && avg >=45){
            grad='E';
        }else{
            grad='F';
        }
    }
    void getdata(){
        cin.ignore();
        cout<<"\n\nEnter Name of Student:: ";
        getline(cin,name);
        cout<<"\n\nEnter Roll Number of Student:: ";
        cin>>roll_no;
        cout<<"\n\nEnter marks out of 100\n\n";
        cout<<"Enter Math marks:: ";
        cin>>m_mark;
         cout<<"\nEnter English marks:: ";
        cin>>e_mark;
        cout<<"\nEnter Science marks:: ";
        cin>>s_mark;
        cout<<"\nEnter Hindi marks:: ";
        cin>>h_mark;
        cout<<"\nEnter Social Science:: ";
        cin>>ss_mark;
        Calculate();
    }
    void PrintData(){
        cout<<"\n\nName of Student:: "<<name<<endl;
        cout<<"\nRoll Number is :: "<<roll_no<<endl;
        cout<<"\nMath marks:: "<<m_mark<<endl;
        cout<<"\nEnglish marks:: "<<e_mark<<endl;
        cout<<"\nScience marks:: "<<s_mark<<endl;
        cout<<"\nHindi marks:: "<<h_mark<<endl;
        cout<<"\nSocial Science:: "<<ss_mark<<endl;
        cout<<"\nAverage of marks:: "<<avg<<endl;
        cout<<"\nGrade of Student:: "<<grad<<endl;
    }
};

void createStudent(){
    Student s;
    ofstream StudentFile;
    StudentFile.open("student.txt",ios::binary|ios::app);
    s.getdata();
    StudentFile.write(reinterpret_cast<char *>(&s), sizeof(Student));
    StudentFile.close();
    cout << "\n\nStudent record Has Been recorded ";
    cin.ignore();
    cin.get();
}
void PrintAllData(){
    Student s;
    ifstream StudentFile;
    StudentFile.open("student.txt",ios::binary);
    if (!StudentFile){
        cout<<"File error!! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\t\tDISPLAYING ALL RECORDS\n\n";
    while (StudentFile.read(reinterpret_cast<char *>(&s), sizeof(Student))){
        cout<<"\n\n====================================\n";
        s.PrintData();
        cout<<"\n\n====================================\n";
    }
    StudentFile.close();
    cin.ignore();
    cin.get();
}
void PrintParticular(int a){
    Student s;
    ifstream StudentFile;
    StudentFile.open("student.txt",ios::binary);
    if(!StudentFile){
        cout<<"File error!! Press any key to exit";
        cin.ignore();
        cin.get();
        return ;
    }
    bool p=false;
    while (StudentFile.read(reinterpret_cast<char *>(&s), sizeof(Student))){
        if(s.roll_no==a){
            p=true;
            cout<<"\n\n\tDISPLAYING RECORD OF ROLL_NO -->   "<<a;
            cout<<"\n\n====================================\n";
            s.PrintData();
            cout<<"\n\n====================================\n";
        }
    }
    StudentFile.close();
    if(p==false){
        cout<<"\n\nRecord Not Found!!\n\n";
    }
    cin.ignore();
    cin.get();
}
int main(){
    
    while(1){
        system("cls");
        cout<<"\n\n\n\t\tStudents Information\n\n\n";
        cout<<"\t\t1.Create Student\n\n";
        cout<<"\t\t2.All Students details\n\n";
        cout<<"\t\t3.Particular Student details\n\n";
        cout<<"\t\t4.Exit\n\n";
        cout<<"\n\n\nEnter your choice:: ";
        int a;
        cin>>a;
        system("cls");
        switch(a){
            case 1: createStudent();
                    break;
            case 2: PrintAllData();
                    break;
            case 3: cout<<"\nEnter the particular roll no:: ";
                    int b;
                    cin>>b;
                    PrintParticular(b);
                    break;

            case 4: exit(0);
        }
    }


}