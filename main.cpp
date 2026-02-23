#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<limits>
using namespace std;

class Student{

     private:
     string name,id,Major,Class;
     float gpa;

     public:

     Student(string n,string i,string m,string c,float g){
     name=n;
     id=i;
     Major=m;
     Class=c;
     gpa=g;}
    
    string Getname(){return name;}
    string Getid(){return id;}
    string GetMajor(){return Major;}
    string GetClass(){return Class;}
    float Getgpa(){return gpa;}

    void Setname(string nm){
        name=nm;
    }
    void Setid(string i){
       if(i.size()==9)
        id=i;
       else
       cout<<"!!INVALID ID!!"<<endl;
    }
    void Setgpa(float g){
        if(g>=0.0 && g<=5.0)
        gpa=g;
        else
        cout<<"!!invalid gpa!!"<<endl;
    }
    void SetClass(string cl){
        Class=cl;
    }
    void SetMajor(string mj){
        Major=mj;
    }
    void displayinfo(){
        cout<<"NAME: "<<Getname()<<endl;
        cout<<"ID: "<<Getid()<<endl;
        cout<<"MAJOR: "<<GetMajor()<<endl;
        cout<<"Class: "<<GetClass()<<endl;
        cout<<"GPA: "<<Getgpa()<<endl;
    }
};
void Loadfromfile(vector<Student>& Students){
 ifstream file("Students.txt");
 if(!file.is_open()) return;
 string name,id,Class,Major;
 float gpa;
 while(getline(file,name)){
    getline(file,id);
    getline(file,Major);
    getline(file,Class);
    file>>gpa;
    file.ignore();
    Students.push_back(Student(name,id,Major,Class,gpa));
 }
 file.close();    
}
void SaveToFile(vector<Student>& Students){
 ofstream file("Students.txt");
    for(int i=0;i<Students.size();i++){
      file<<Students[i].Getname()<<endl;
      file<<Students[i].Getid()<<endl;
      file<<Students[i].GetMajor()<<endl;
      file<<Students[i].GetClass()<<endl;
      file<<Students[i].Getgpa()<<endl;
    }
    file.close();
    cout<<"\n======SAVED======!\n";
}
void AddStudent(vector<Student>& Students){
    string name,id,Class,Major;
    float gpa;
  do{
    cout<<"Enter Name: "<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout<<"Enter ID(9 Characters): ";
    cin>>id;
    cout<<"Enter Major: ";
    cin>>Major;
    cout<<"Enter Class: ";
    cin>>Class;
    cout<<"Enter gpa (0.0-5.0): ";
    cin>>gpa;
    if(id.size()!=9||gpa<0.0||gpa>5.0)
    cout<<"invalid input! please try again !\n";
    }while(id.size()!=9|| gpa<0.0|| gpa>5.0);
    Students.push_back(Student(name,id,Major,Class,gpa));
    cout<<"\n=====STUDENT ADDED SUCCESSFULLY=====\n";
}
int SearchById(vector<Student>& Students,string target){
    for(int i=0;i<Students.size();i++)
      if(Students[i].Getid()==target){
        return i;
       }   
return -1;
}
void ShowAll(vector<Student>& Students) {
    cout<<"+====================+===============+=================+==========+======+\n";
    cout<<"|Name                |ID             |Major            |Class     |GPA   |\n";
    cout<<"+====================+===============+=================+==========+======+\n";
          for(int i=0;i<Students.size();i++){    
    cout<<"|"<<left<<setw(20)<<Students[i].Getname();
    cout<<"|"<<left<<setw(15)<<Students[i].Getid();
    cout<<"|"<<left<<setw(17)<<Students[i].GetMajor();
    cout<<"|"<<left<<setw(10)<<Students[i].GetClass();
    cout<<"|"<<left<<setw(5)<<Students[i].Getgpa()<<" |\n";
    cout<<"+------------------------------------------------------------------------+\n";
        }
}
void UpdateStudentinfo(vector<Student>& Students){

    string target;
    int choice1;
    int index;
    do{
    cout<<"ENTER STUDENT ID: ";
    cin>>target;
    index=SearchById(Students,target);
    if(index!=-1)
     break;
     if(index==-1)
     cout<<"STUDENT NOT FOUND!\n[1]:SEARCH OTHER STUDENT\n[2]:EXIT TO MAIN MENU\n";
     cin>>choice1;
     if(choice1==2){
        return;
     }
    }while(choice1==1);
    if(index==-1) return;
    while(true){
    int choice2;
    cout<<"==========================================================\n";
    cout<<"                  SELECT THE INFO TO UPDATE: \n";
    cout<<"[1]:UPDATE NAME\n";
    cout<<"[2]:UPDATE ID\n";
    cout<<"[3]:UPDATE MAJOR\n";
    cout<<"[4]:UPDATE CLASS\n";
    cout<<"[5]:UPDATE GPA\n";
    cout<<"[6]:EXIT\n";
    cout<<"===========================================================\n";
    cout<<"CHOICE=>";
    cin>>choice2;
    switch(choice2){
    case 1:{
    string name;
    cout<<"ENTER NEW NAME: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    Students[index].Setname(name);
    break;}

    case 2:{
    string id;
    cout<<"ENTER NEW ID: ";
    cin>>id;
    Students[index].Setid(id);
    break;}
    
    case 3:{
    string Major;
    cout<<"ENTER NEW MAJOR: ";
    cin>>Major;
    Students[index].SetMajor(Major);
    break;}

    case 4:{
    string Class;
    cout<<"ENTER NEW CLASS: ";
    cin>>Class;
    Students[index].SetClass(Class);
    break;}

    case 5:{
    float gpa;
    cout<<"ENTER NEW GPA: ";
    cin>>gpa;
    Students[index].Setgpa(gpa);
    break;}

    case 6:{
    return;
    }

    default:{
    cout<<"INVALID CHOICE!\n";
    continue;}
    }
    cout<<"\n==========INFO UPDATED SUCCESSFULLY==========\n\n";
}
}
void DeleteStudent(vector<Student>& Students){
       string target;
       cout<<"ENTER STUDENT ID TO DELETE: ";
       cin>>target;
       int index = SearchById(Students,target);
       if(index==-1)
        cout<<"STUDENT NOT FOUND!\n";
       else{
        Students.erase(Students.begin()+index);
        cout<<"STUDENT DELETED!\n";}
}
void ShowStats(vector<Student>& Students){
    if(Students.empty()){
    cout<<"No students available!\n";
    return;
    }

    float sumgpa=0;
    for(int i=0;i<Students.size();i++){
        sumgpa+=Students[i].Getgpa();}
    int MaxID=0;
    string maxname=Students[0].Getname();
    float maxgpa=Students[0].Getgpa();
    for(int i=0;i<Students.size();i++)
     if(maxgpa<Students[i].Getgpa()){
       maxgpa=Students[i].Getgpa();
       maxname=Students[i].Getname();
       MaxID=i;
       maxname=Students[MaxID].Getname();
    }
    string minname=Students[0].Getname();
    float mingpa=Students[0].Getgpa();
    for(int i=0;i<Students.size();i++)
     if(mingpa>Students[i].Getgpa()){
       mingpa=Students[i].Getgpa();
       minname=Students[i].Getname();}

    cout<<"+=========STATISTICS==========================+\n";
    cout<<" TOTAL STUDENTS: "<<Students.size()<<right<<setw(30)<<"\n";
    cout<<" HIGHEST GPA: "<<maxgpa<<"("<<maxname<<")"<<right<<setw(22)<<"\n";
    cout<<" LOWEST GPA: "<<mingpa<<"("<<minname<<")"<<right<<setw(27)<<"\n";
    cout<<" AVERAGE GPA: "<<sumgpa/Students.size()<<right<<setw(30)<<"\n";
    cout<<"+=============================================+\n";
}
int main(){
    vector<Student> Students;
    Loadfromfile(Students);
 while(true){ 
    int choice;
    cout<<"\n\n";
    cout<<"+=================================================+\n";
    cout<<"|============STUDENT MANAGEMENT SYSTEM============|\n";
    cout<<"|==================MAIN MENU======================|\n";
    cout<<"|==>[1] Add Student                               |\n";
    cout<<"|==>[2] Show All Students                         |\n";
    cout<<"|==>[3] Search Student By ID                      |\n";
    cout<<"|==>[4] Update Student INFO                       |\n";
    cout<<"|==>[5] Delete Student                            |\n";
    cout<<"|==>[6] Show Statistics                           |\n";
    cout<<"|==>[7] Save & Exit                               |\n";
    cout<<"+=================================================+\n";
    cout<<"Choice: ";
    cin>>choice;

    switch(choice){
        case 1:
        AddStudent(Students);
        break;
        case 2:
        ShowAll(Students);
        break;
        case 3:{
        cout<<"Enter student ID to search: ";
        string target;
          do{
          cin>>target;
          if(target.size()!=9)
          cout<<"INVALID ID!! PLEASE TRY AGAIN (9 Characters)\n";
          }while(target.size()!=9);
        int index = SearchById(Students,target);
       if(index==-1)
        cout<<"Not found!\n";
       else{
        cout<<"FOUND!\n"<<"STUDENT INFO: \n";
        Students[index].displayinfo();}
        break;}
        case 4:
        UpdateStudentinfo(Students);
        break;
        case 5:
        DeleteStudent(Students);
        break;
        case 6:
        ShowStats(Students);
        break;
        case 7:
        SaveToFile(Students);
        return 0;
        default:
        cout<<"Invalid choice. Please enter 1-7.\n";
    }
    cout<<"-----------------------------------------";
    cout<<"\nPRESS ENTER TO CONTINUE...";
    cin.ignore();
   cin.get();
 }
 return 0;
}