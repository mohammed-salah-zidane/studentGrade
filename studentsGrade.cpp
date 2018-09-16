#include<iostream>
#include<string>
using namespace std ;
struct student
{  
	string fname;
    string lname;
	double deg;
	char grade ;
};
char Gradefun(double x) //to determine he grade
{ char z;
   if(x<=100 && x>81)
	   z='A';
   else if (x<=80 && x>71)
	      z='B';
       else if (x<=70 && x>61)
		       z='C';
	        else if (x<=60 && x>50) 
				    z='D';
			     else
					 z='E';
			return z;}
 
void search ( student std[] , int length ) //function to seach about name
{  
	string stnum1 , stnum2 ;
	cout<<" please enter the name of the student which you want \n " ;
	cin>>stnum1>>stnum2; 
	for(int i=0; i<length ;i++)
	{  
		if(std[i].fname==stnum1 && std[i].lname==stnum2)
		{ 
			cout<<" his degree is : "<<std[i].deg<<"\n";
			cout<<" his grade is : "<<std[i].grade<<"\n";
		}
	}
}

void Display_sort( student stud[], int l)//sort degree of student ascending
{ 
	student fun;
	for(int n=0 ; n<l-1; n++)
      for( int k=n+1 ;k<l; k++)
{    
	if(stud[n].deg> stud[k].deg)
	{ 
		fun.fname=stud[n].fname;
		fun.lname=stud[n].lname;
		fun.deg=stud[n].deg;
		fun.grade=stud[n].grade;

		stud[n].fname=stud[k].fname;
		stud[n].lname=stud[k].lname;
		stud[n].deg=stud[k].deg;
		stud[n].grade=stud[k].grade;
		 
		stud[k].fname=fun.fname;
		stud[k].lname=fun.lname;
		stud[k].deg=fun.deg;
		stud[k].grade=fun.grade;

	}
}
	  for(int p=0 ;p<l;p++)
	  {
		  cout<<"the student number "<<p+1<<" :- \n ";
		  cout<<" his name is : " <<stud[p].fname<<" "<<stud[p].lname<<"\n";
		  cout<<" his degree is : "<<stud[p].deg<<"\n";
		  cout<<" his grade is : " <<stud[p].grade<<"\n";
		  cout<<"--------------------------------"<<endl;
	  }
	
		

}

int main ()                                                     //the main function of the program
	{
		int studnumber;
	cout<<" please enter student number :  \n";
	cin>>studnumber;

	student * information=new student[studnumber ];

	 cout<<"please enter information of every student : \n";

	 for (int m=0 ; m<studnumber ; m++)
	 {
		 cout<<" the student number : " <<m+1<<" please enter his first and last name and his degree . \n";
		 cin>>information[m].fname>>information[m].lname>>information[m].deg;
		 information[m].grade=Gradefun(information[m].deg);
	 }
		 
	 char op , selection;
do	 
	{
		cout << "please choose one of this selections :\n"
			<< "1- Display all student's names.\n"
			<< "2- Display all student's degree.\n"
			<< "3- Display all student's grade.\n"
			<< "4- Search for student's grade and degree using student name.\n"
			<< "5- Sort students based on their degrees.\n"
			<< "6- finish this program." << endl;

		cin >> selection;
		switch (selection)
		{ 
		case '1':
			for (int i = 0; i < studnumber; i++)
			{
				cout << i + 1 << "-" << information[i].fname << " " << information[i].lname << "\n";
				cout<<"--------------------------------"<<endl;
			}
			break;
         case '2':
			for (int i = 0; i < studnumber; i++)
			cout<<i+1<<":-"<<information[i].deg<<endl;
			break;
			case '3':
			for (int i = 0; i < studnumber; i++)
				cout << i + 1 << "-"<<information[i].grade << endl;
			break;
				case '4':
			search(information, studnumber);
			
			break;
		case '5':
			Display_sort(information, studnumber);
			break;
		default:
			cout << "Thanks for your coopreting" << endl;
			
		}

		cout << "if you want to do it again press { y } and to finish press { n }" << endl;
		cin >> op;
		
	} while (op!='n');
	
	return 0;
	system("pause");
}













































