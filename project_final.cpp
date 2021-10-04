#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Student //student class
{
    public:
    string name,coursename; //student name
    int ID; //student id
    int marks; //number of courses student is taking
   
};

vector <Student> s; //Student class vector
map<string,string> usernameToPassword;//map to set username and password
int main()
{
    int K; 
    int input;
    string value;
    string cname,pass,pass1;
    cout<<"Welcome to the class tracker!"<<endl; //Display welcome message
    int ch;
    
   do{
    string s1,s2;
    cout<<"set your username\n(NOTE : Your Username should contain only characters,also no special characters & no numbers):\n";
    cin>>s1;
    cout<<"set your password.\n(NOTE : Your Password should contain only characters,also no special characters & no numbers):\n";
    cin>>s2;
    usernameToPassword[s2] = s1;
    cout<<"do you want to continue to set more username and password for other teachers?\nIf yes enter any number and if no enter 0\n";
    cin>>ch;
   }
   while(ch!=0);

	string t,t1;
	bool isFound = false;
	cout<<"Enter username and password to access student tracking system \n";
	cin>>t>>t1;

	auto it=usernameToPassword.find(t);//map iterator to find username & password.
    it=usernameToPassword.find(t1);
    
	if(usernameToPassword.find(t)==usernameToPassword.end() && usernameToPassword.find(t1)==usernameToPassword.end())
    {
	   cout<<"Either username or password is invalid\n";
     }
    else{
		cout<<"Found\n";
	    isFound = true;
	}
while(isFound)
{
    while (true) //while input is true
    {
        //string cname;
        int userinput,testid;
        int input,marks=0,ID=0,n=0; //integer variables
        string name,cname,coursename; //string variables
        cout<<"Choose an option.\n"; //display option menu
        cout<<"1.ADD A STUDENT RECORD\n";
        cout<<"2.GENERATE MARKSHEET\n";
        cout<<"3.SEARCH STUDENT RECORD\n";
        cout<<"4.MODIFY STUDENT RECORD\n";
        cout<<"5.DELETE STUDENT RECORD\n";
        cout<<"6.CHANGE PASSWORD\n";
        cout<<"7. QUIT\n";
        cin>>input; //recieve user input
        cin.ignore(); //ignore white spaces
        if (input==1) //if user input is 1
        {
            Student a;//object of class student
            cout<<"Input the name of the student."<<endl; //ask for name of student
            getline(cin, a.name); //receive name
            cout<<"Input the ID/roll no of the student."<<endl; //asl for ID of Student
            cin>>a.ID; // recieve ID
            cout<<"Input the course name of the student.\nNOTE:it should be of only 1 word,not having spaces & numbers"<<endl; //ask for coursename of student
            cin>>a.coursename; //receive course name
            // getline(cin,a.coursename);
            cout<<"Input the marks of the student."<<endl; //ask for marks of Student
            cin>>a.marks; // recieve marks
            s.push_back(a);
        }
        if(input==2)//if user input is 2
        {
          cout<<"DISPLAY MARKSHEET: \n";
	      cout<<"Name      |  ID   | Course Name |  Marks"<<endl; //display guidline
          cout<<"_______________________________________________"<<endl; //border
          for (int i=0; i<s.size(); i++) //for the size of the student class vector
            {
             cout<<s.at(i).name<<"        "<<s.at(i).ID<<"        "<<s.at(i).coursename<<"        "<<s.at(i).marks<<"        "<<endl; //display user name and id
            }
        }
        if(input==3)//if user input is 3
		{
            bool found1=false;
            
            cout<<"Enter roll no/ID of student you want to search\n";
            cin>>testid;
            for (int i=0; i<s.size(); i++) //for the size of the student class vector
            {
                if(testid==s.at(i).ID)
                {
                    cout<<"ID Found\n";
                    cout<<"Name      |  ID   | Course Name |  Marks"<<endl; //display guidline
                    cout<<s.at(i).name<<"        "<<s.at(i).ID<<"        "<<s.at(i).coursename<<"        "<<s.at(i).marks<<"        "<<endl; //display user name and id
                    found1=true;
                    break;
                }
    
                // cout<<"Not Found\n";
            }
            if(!found1){
            cout<<"This Student ID Not Found !\n";
                
            }
        }
        if(input==4)//if user input is 4
		{
             bool found2=false;
            
            cout<<"Enter roll no/ID of student you want to search\n";
            cin>>testid;
            for (int i=0; i<s.size(); i++) //for the size of the student class vector
            {
                if(testid==s.at(i).ID)
                {
                    cout<<" found\n";
                    cout<<"Enter the new details."<<endl;
                    cout<<"enter roll no\n";
                    cin>>s.at(i).ID;
                    cout<<"enter name\nenter only 1st name"<<endl;
                    cin>>s.at(i).name;
                    cout<<"Enter Course Name\n";
                    cin>>s.at(i).coursename;
                    cout<<"Enter marks:\n";
                    cin>>s.at(i).marks;
                    //cout<<s.at(i).name<<"         "<<s.at(i).ID<<"        "<<endl;
                    cout<<"Name      |  ID   | Course Name |  Marks"<<endl; //display guidline
                    cout<<s.at(i).name<<"        "<<s.at(i).ID<<"        "<<s.at(i).coursename<<"        "<<s.at(i).marks<<"        "<<endl; //display user name and id
                    found2=true;
                    break;
                }
                
            }
                if(!found2){
                 cout<<"This Student ID Not Found !\n";
                    
                }
            }
        if(input==5)//if user input is 5
            {
               cout << "enter roll no/ID to remove" << endl;
               cin >> userinput;
               bool Found = false;
               vector <Student>::iterator it3;//creating iterator of vector
               for (it3 = s.begin(); it3 != s.end(); ++it3) {
                   if ( it3->ID == userinput ){    
                         it3=s.erase(it3);
                         --it3;
                         cout<<"ID DELETED\n";
                         Found= true;
                        break;
                     }
                     
                }
                
                if(!Found)
                {
                    cout<<"This Student ID Not Found !\n";
                }
            
            }
            
         if(input==6)//if user input is 6
		 {

            cout<<"enter your original username to modify\n(NOTE : Your Username should contain only characters,also no special characters & no numbers):\n";
            cin>>cname;
            cout<<"enter your original password to modify.\n(NOTE : Your Password should contain only characters,also no special characters & no numbers):\n";
            cin>>pass;

        	auto itr=usernameToPassword.find(cname);
             itr=usernameToPassword.find(pass);
            
            if(usernameToPassword.find(cname)==usernameToPassword.end() && usernameToPassword.find(pass)==usernameToPassword.end())
            {
	        cout<<"Either username or password is invalid\n";
            }
            else{
		    cout<<"found\n";
		    cout<<"enter new password\n(NOTE : Your Password should contain only characters,also no special characters & no numbers):\n";
	     	cin>>pass1;
            value = itr->second;
            usernameToPassword.erase(itr);
            usernameToPassword[pass1] = value;

            }
             
         }
        if(input==7) //if user inputs 7
        {
            cout<<"Thank you for using the class tracker"<<endl; //display goodbye message
            cout<<"Have a good day"<<endl; //display goodbye message
            break; //terminates out of loop
        }
       
    }
    break;//terminates out of loop
    }
    return 0;
}
    



