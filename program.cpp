//Application :  Student Automation system 

#include<iostream>

using namespace std;

/*typedef struct Student{
	int rollNo;
	char name[20];
	int marks;
	char address[50];
	struct Student *Next;
}NODE, *PNODE; */
     //OR//
struct Student{
	int rollNo;
	string name; 
	float percentage;
	string address;
	struct Student *Next;
};
typedef struct Student NODE;
typedef struct Student * PNODE;

class StudentDetails{
	private:
	    PNODE Head;
		int iSize;
	public:
	    StudentDetails(){
			Head=NULL;
			iSize=0;
		}		
		void InsertStudent(int,string,float,string);
		void SearchStudent(int);
		void UpdateStudent(int);
		void DeleteStudent(int);
		void DisplayAllStudents();
		int CountStudents();
};

void StudentDetails::InsertStudent(int rollNo, string name, float percentage, string address){
	PNODE newStud=NULL;
	newStud = new NODE; //allocation
	newStud->rollNo=rollNo;
	newStud->name=name;
	newStud->percentage=percentage;
	newStud->address=address;
    newStud->Next=NULL;
    if(Head==NULL){ // LL is empty
		Head=newStud; 
	}
	else{
		newStud->Next=Head;
		Head=newStud;
	}
	iSize++;
	   
}
void StudentDetails::SearchStudent(int rollNo){
	PNODE Temp=Head;
	cout<<"Roll No\t\tName\t\tPercentage\t\tAddress\n\n";
	while(Temp!=NULL){
		if(Temp->rollNo==rollNo){
			cout<<Temp->rollNo<<"\t\t";
			cout<<Temp->name<<"\t\t";
			cout<<Temp->percentage<<"\t\t\t";
			cout<<Temp->address<<"\t\t";
			cout<<"\n";
	    }
		Temp=Temp->Next;
	}
	cout<<"Roll number not found!!\n";
		
}
void StudentDetails::UpdateStudent(int rollNo){
    PNODE Temp=Head;
	while(Temp!=NULL){
		if(Temp->rollNo==rollNo){
			cout<<"update details of roll number:"<<Temp->rollNo<<"\n";
			cout<<"Enter name:\n";
			cin>>Temp->name;
			cout<<"Enter percentage:\n";
			cin>>Temp->percentage;
			cout<<"Enter address:\n";
			cin>>Temp->address;
			
			cout<<"Record Updated Succesffully!!";
		}
		Temp=Temp->Next;
	}
}
void StudentDetails::DeleteStudent(int rollNo){
    PNODE Temp1=Head;
	PNODE Temp2=Head;
	while(Temp1!=NULL){
		if(Temp1->rollNo==rollNo){
			if(Temp1==Temp2){
				Head=Head->Next;
				delete Temp1;
			}
			else{
				Temp2->Next=Temp1->Next;
				delete Temp1;
			}
		}
		cout<<"Record Deleted Succesffully!!";
		Temp2=Temp1;
		Temp1=Temp1->Next;
	}	
	iSize--;
}
void StudentDetails::DisplayAllStudents(){
	PNODE Temp=Head;
	if(Temp==NULL){
		cout<<"Records not available";
	}
	else{
		cout<<"Roll No\t\tName\t\tPercentage\t\tAddress\n\n";
	    while(Temp!=NULL){
			
			cout<<Temp->rollNo<<"\t\t";
			cout<<Temp->name<<"\t\t";
			cout<<Temp->percentage<<"\t\t\t";
			cout<<Temp->address<<"\t\t";
			cout<<"\n";
			Temp=Temp->Next;
	    }
		cout<<"\n";	
	}
}
int StudentDetails::CountStudents(){
	return iSize;
}

int main(){
	int iChoice=1,iNo=0,rollNo=0,iRet=0;
	float percentage;
	string name, address;
	StudentDetails stud;
	
	while(iChoice!=0){
		cout<<"Enter your choice:\n";
	    cout<<"1:Enter students details:\n";
        cout<<"2:Search Student:\n";
		cout<<"3:Update student inforamtion:\n";
		cout<<"4:Remove Student:\n";
		cout<<"5:Display details of all student:\n";
		cout<<"6:Number of students:\n";
		cout<<"0:presss 0 to exit\n";
		
		cin>>iChoice;
		
		switch(iChoice){
			case 1:
			    cout<<"Enter Roll Number\n";
				cin>>rollNo;
				cout<<"Enter Name:\n";
				cin>>name;
				cout<<"Enter Percentage:\n";
				cin>>percentage;
				cout<<"Enter Address:\n";
				cin>>address;
				stud.InsertStudent(rollNo,name,percentage,address);
			    break;
			case 2:
			    cout<<"Enter Roll number:\n";
				cin>>rollNo;
				stud.SearchStudent(rollNo);
			    break;
			case 3:
			    cout<<"Enter Roll number:\n";
				cin>>rollNo;
				stud.UpdateStudent(rollNo);
			    break;
			case 4:
				cout<<"Enter Roll number:\n";
				cin>>rollNo;
				stud.DeleteStudent(rollNo);
			    break;
			case 5:
			    stud.DisplayAllStudents();
			    break;
			case 6:
			    iRet=stud.CountStudents();
				cout<<"number ofstudents are:"<<iRet<<"\n";
				break;
			case 0:
			    cout<<"THANK YOU!!!";
			    break;
			default:
			    cout<<"Enter valid choice\n";
		}// end of switch
	} // end of while
	return 0;
}// end of main
