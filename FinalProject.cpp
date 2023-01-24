/*
	
	project: Student Prerequisite Subject Management System

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

/*
	CNode class for courses nodes
*/
class CNode{
	public:
	string course_code;
	string course_name;
	string course_prerequisite;
	char course_grade;
	bool course_clear;
	bool course_selection;
	CNode* next;
};

/*
	SNode class for student Nodes
*/
class SNode{
	public:
	int student_id;
	string name;
	string password;
	SNode* next;
	CNode* courseLink;
};

/*
	LinkedList class for creating the who link lists data structure
*/

class LinkedList{
	private:
	SNode* head=NULL;
	
	public:
		LinkedList(){
			head==NULL;
		}
		~LinkedList();
		void addStudent(string, int, string);				//function to add student nodes
		void addCourse(int, string , string, string);		//function to add courses to a specific student account/node
		void updateCourseData(int, string, char, bool);		//function to update course data by changing grade or clearance status
		void checkClearedCourse(int);						//function to display a list of cleared courses
		void checkPrerequisite(int, string);				//function to check prerequisite course of any course 
		void coursesAvailable(int);							//function to display list of courses available for registration
		void registerCourse(int, string);					//function to register any course change course selection value to true
		void registeredCourses(int);						//function to display list of registered course by a student
		void dropCourse(int, string);						//function to drop any registered course
		
		void displayCourse(int);							//function to display list of courses of any student either clear or not
		void displayList();									//function to display list of all students and their data
		
		bool findNode(int);									//function to check if a noode is avaible in linked list or not and return true/false value
		bool checkPassword(int, string);					//function that checks password of student and return true/false value
		bool isEmpty();										//function to check if linked list is empty or not
		
		SNode* getHead(){									//function that return a head of the linked list
			return head;
		}
};


////////////////////////////////////////////////
////////////////////////////////////////////////////

int main(){
	
	LinkedList student;
	
	int admin=21303;
	string adminpassword="admin303";
	
	
	int mainChoice=0, adminChoice=0, adminId=0, studentChoice=0, studentId=0;
	
	char adminSubChoice='\0', studentSubChoice='\0', courseGrade='\0';
	
	bool courseClear=false;
	
	string adminPassword="\0", studentName="\0", studentPassword="\0", courseCode="\0", courseName="\0", coursePrerequisite="\0";

	cout<<"\n======================================================"<< endl;
	cout<<"\nWelcome to Student Prerequisite management system"<< endl;
	cout<<"\n======================================================"<< endl;
	
	while(mainChoice!=3){
		cout<<"\n======================================================"<< endl;
		cout<<"\nEnter 1 for Admin"<< endl;
		cout<<"Enter 2 for Student"<< endl;
		cout<<"Enter 3 to  Quit"<< endl;
		cout<<"Enter choice: ";
		cin>>mainChoice;
		cout<<"\n======================================================"<< endl;
		switch(mainChoice){
			case 1:
				cout<<"\nEnter Admin Id: ";
				cin>>adminId;
				if(adminId==admin){
					cout<<"Enter Password: ";
					cin>>adminPassword;
					if(adminPassword==adminpassword){
						
						while(adminChoice!=7){
							cout<<"\n======================================================"<< endl;
							cout<<"\nEnter 1 to Add Student Account"<< endl;
							cout<<"Enter 2 to Add courses"<< endl;
							cout<<"Enter 3 to Update Student course data"<< endl;
							cout<<"Enter 4 to check Student Cleared Courses"<< endl;
							cout<<"Enter 5 to check Student Current Registered Courses"<< endl;
							cout<<"Enter 6 to Display All Student Data"<< endl;
							cout<<"Enter 7 to Exit"<< endl;
							cout<<"Enter Choice: ";
							cin>>adminChoice;
							switch(adminChoice){
								case 1:
									do{
										cout<<"\n======================================================"<< endl;
										cout<<"\nEnter Student ID: ";
										cin>>studentId;
										cout<<"Enter Student Name: ";
										cin.ignore();
										getline(cin, studentName);
										cout<<"Enter Student Password: ";
										getline(cin, studentPassword); 
										student.addStudent(studentName, studentId, studentPassword);
										cout<<"\nAdd another account? y/n ";
										cin>>adminSubChoice;
									}
									while(adminSubChoice=='y' || adminSubChoice =='Y');
									break;
								case 2:
									cout<<"\n======================================================"<< endl;
									cout<<"\nEnter Student ID: ";
									cin>>studentId;
									do{
										cout<<"Enter Course Code:";
										cin.ignore();
										getline(cin,courseCode);
										cout<<"Enter Course Name:";
										getline(cin,courseName);
										cout<<"Enter Course Prerequiste (if any else enter --): ";
										getline(cin,coursePrerequisite);
										student.addCourse(studentId, courseCode, courseName, coursePrerequisite);
										cout<<"\nAdd another Course? y/n ";
										cin>>adminSubChoice;
										cout<<endl;
									}
									while(adminSubChoice=='y' || adminSubChoice =='Y');
									break;
								case 3:
									cout<<"\n======================================================"<< endl;
									cout<<"\nEnter Student ID: ";
									cin>>studentId;
									do{
										cout<<"\n======================================================"<< endl;
										cout<<"\nCourse whose data is not updated: "<< endl;
										student.coursesAvailable(studentId);
										cout<<"\n======================================================"<< endl;
										cout<<"\nEnter Course Code: ";
										cin.ignore();
										getline(cin,courseCode);
										cout<<"Enter Course Grade: ";
										cin>>courseGrade;
										cout<<"Enter Course Clearance: (1/0) ";
										cin>>courseClear;
										student.updateCourseData(studentId, courseCode, courseGrade, courseClear);
										cout<<"\nUpdate another Course Data? y/n ";
										cin>>adminSubChoice;
										cout<<endl;
									}
									while(adminSubChoice=='y' || adminSubChoice =='Y');
									break;
								case 4:
									cout<<"\n======================================================"<< endl;
									do{
										cout<<"\nEnter Student ID: ";
										cin>>studentId;
										cout<<"\n======================================================"<< endl;
										student.checkClearedCourse(studentId);
										cout<<"\n======================================================"<< endl;
										cout<<"\nCheck Another Student Cleared Course? y/n : ";
										cin>>adminSubChoice;
										cout<<endl;
									}
									while(adminSubChoice=='y' || adminSubChoice=='Y');
									break;
								case 5:
									cout<<"\n======================================================"<< endl;
									do{
										cout<<"\nEnter Student ID: ";
										cin>>studentId;
										cout<<"\n======================================================"<< endl;
										student.registeredCourses(studentId);
										cout<<"\n======================================================"<< endl;
										cout<<"\nCheck Another Student Course? y/n : ";
										cin>>adminSubChoice;
										cout<<endl;
									}
									while(adminSubChoice=='y' || adminSubChoice=='Y');
									break;
								case 6:
									cout<<"\n======================================================"<< endl;
									cout<<endl;
									student.displayList();
									cout<<"\n======================================================"<< endl;
									break;
								case 7:
									cout<<"\n======================================================"<< endl;
									break;
								default:
									
									cout<<"\nInvalid Input"<< endl;
										
							}
						}
						
					}
					else{
						cout<<"\nincorrect password"<< endl;
					}
				}
				break;
			case 2:
				cout<<"\nEnter Student ID: ";
				cin>>studentId;
				if(student.findNode(studentId)){
					cout<<"Enter Password: ";
					cin>>studentPassword;
					cout<<"\n======================================================"<< endl;
					if(student.checkPassword(studentId, studentPassword)){
						while(studentChoice!=6){
							cout<<"\nEnter 1 to Check Cleared courses "<< endl;
							cout<<"Enter 2 to Register for courses "<< endl;
							cout<<"Enter 3 to Check Prerequisite of course"<< endl;
							cout<<"Enter 4 to Check Registered Courses"<< endl;
							cout<<"Enter 5 to to Drop course"<< endl;
							cout<<"Enter 6 to Exit "<< endl;
							cout<<"Enter Choice: ";
							cin>>studentChoice;
							cout<<"\n======================================================"<< endl;
							switch(studentChoice){
								case 1:
									cout<<"\nCourse Cleared: "<< endl;
									student.checkClearedCourse(studentId);
									cout<<"\n======================================================"<< endl;
									break;
								case 2:
									
									do{
										cout<<"\n======================================================"<< endl;
										cout<<"\nCourse Available To register."<< endl;
										student.coursesAvailable(studentId);
										cout<<"\nEnter Course Code: ";
										cin.ignore();
										getline(cin, courseCode);
										student.registerCourse(studentId, courseCode);
										cout<<"Register another course: y/n ";
										cin>>studentSubChoice; 
									}
									while(studentSubChoice=='y' || studentSubChoice=='Y');
									cout<<"\n======================================================"<< endl;
									break;
								case 3:
									do{
										cout<<"\nEnter Course Code: ";
										cin.ignore();
										getline(cin, courseCode);
										student.checkPrerequisite(studentId, courseCode);
										cout<<"Check Another Course Prerequiste? y/n ";
										cin>>studentSubChoice; 
										cout<<"\n======================================================"<< endl;
									}
									while(studentSubChoice=='y' || studentSubChoice=='Y');
									break;
								case 4:
									cout<<endl;
									student.registeredCourses(studentId);
									cout<<"\n======================================================"<< endl;
									break;
								case 5:
									do{
										cout<<"\nCourses you have registered for: "<< endl;
										student.registeredCourses(studentId);
										cout<<"Enter Course Code (Enter 1 if no courses registered)";
										cin>>courseCode;
										if(courseCode=="1"){
											cout<<"\n======================================================"<< endl;
											break;
										}
										student.dropCourse(studentId, courseCode);
										cout<<"\nDrop another Course? y/n : ";
										cin>>studentSubChoice;
										cout<<"\n======================================================"<< endl;
										
									}
									while(studentSubChoice=='y' || studentSubChoice=='Y');
									break;
								case 6:
									break;
								default:
									cout<<"\nINVALID INPUT!"<< endl;
									break;
							}
						}
					}
					else{
						cout<<"\nWrongPassword!"<< endl;
					}					
				}
				else{
					cout<<"\nStudent Account doesn't Exist!"<< endl;
				}
				break;
			case 3:
				cout<<"\n!!GOOD BYE!!"<< endl;
				cout<<"\n======================================================"<< endl;
				break;
			default:
				cout<<"\nINVALID INPUT"<< endl;
				break;
		}
	}
	return 0;
}


/////////////////////////////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////////

void LinkedList::addStudent(string studentName, int studentId, string password){
	SNode* currNode=head;
	SNode* newNode=new SNode;
	newNode->name=studentName;
	newNode->student_id=studentId;
	newNode->password=password;
	newNode->courseLink=NULL;
	if(currNode==NULL){
		newNode->next=head;
		head=newNode;
		return;
	}
	while(currNode->next!=NULL){
		currNode=currNode->next;
	}
	newNode->next=currNode->next;
	currNode->next=newNode;
}

//////////////////////////////////////////////////////////////////

void LinkedList::addCourse(int studentId, string courseCode, string courseName, string prerequisite){
	SNode* currNode=head;
	while(currNode->student_id!=studentId){
		currNode=currNode->next;
	}
	if(currNode){
		CNode* currCNode=currNode->courseLink;
		CNode* newNode=new CNode;
		 newNode->course_code=courseCode;
		 newNode->course_name=courseName;
		 newNode->course_prerequisite=prerequisite;
		 newNode->next=NULL;
		 newNode->course_grade='\0';
		 newNode->course_selection=false;
		 newNode->course_clear=false;
		if(currNode->courseLink==NULL){
			newNode->next=currNode->courseLink;
			currNode->courseLink=newNode;
			return;
		}
		while(currCNode->next!=NULL){
			currCNode=currCNode->next;
		}
		newNode->next=currCNode->next;
		currCNode->next=newNode;
	}
}

/////////////////////////////////////////////////////////////////

void LinkedList::updateCourseData(int studentId, string courseCode, char grade, bool courseClear){
	SNode* currNode=head;
	while(currNode->student_id!=studentId){
		currNode=currNode->next;
	}
	if(currNode){
		CNode* currCNode=currNode->courseLink;
		while(currCNode->course_code!=courseCode){
			currCNode=currCNode->next;
		}
		if(currCNode){
			currCNode->course_grade=grade;
			currCNode->course_clear=courseClear;
			currCNode->course_selection=false;
		}
		else{
			cout<<"course not found!"<< endl;
		}
		return;
	}
	else{
		cout<<"student account doesn't exist!"<< endl;
	}
	
}

/////////////////////////////////////////////////////////////////

void LinkedList::checkClearedCourse(int studentId){
	SNode* currNode=head;
	while(currNode->student_id!=studentId){
		
		currNode=currNode->next;
		if(currNode==NULL)
		break;
	}
	if(currNode){
		if(currNode->courseLink){
			CNode* currCNode=currNode->courseLink;
			cout<<"\nName: "<<currNode->name<<endl;
			cout<<left<<setw(7)<<"Code "<<left<<setw(65)<<"Course "<<left<<setw(6)<<"Grade"<<left<<setw(15)<<"Prerequiste Course\n"<< endl;
			while(currCNode){
				
				if(currCNode->course_clear==true){
					
					cout<<left<<setw(7)<< currCNode->course_code;
					cout<<left<<setw(65)<< currCNode->course_name;
					cout<<left<<setw(6)<< currCNode->course_grade;
					cout<<left<<setw(15)<< currCNode->course_prerequisite<<setw(25);
					cout<<endl;
				}
				currCNode=currCNode->next;
			}
		}
		else{
			cout<<"no courses are availble"<< endl;
		}
	}
	else{
		cout<<"student account doesn't exist"<< endl;
	}
	
}

////////////////////////////////////////////////////////////////

void LinkedList::registerCourse(int studentId, string courseId){
	SNode* currNode=head;
	while(currNode->student_id!=studentId){
		currNode=currNode->next;
	}
	CNode* currCNode=currNode->courseLink;
	while(currCNode->course_code!=courseId){
		currCNode=currCNode->next;
		if(currCNode==NULL){
			cout<<"\nwrong Course Code or Course not available!"<< endl;
			break;
		}
	}
	if(currCNode){
		if(currCNode->course_prerequisite=="--"){
			currCNode->course_selection=true;
		}
		else{
			CNode* tempCNode=currNode->courseLink;
			while(tempCNode->course_code!=currCNode->course_prerequisite){
				tempCNode=tempCNode->next;
				if(tempCNode==NULL)
				break;
			}
			if(tempCNode){
				if(tempCNode->course_clear==true){
					currCNode->course_selection=true;
				}
				else{
					cout<<"\nYou can not take this course. Please clear the following prerequiste course :"<< endl;
					cout<<"\nCourse: "<<tempCNode->course_name<<"\nCourse Code: "<< tempCNode->course_code<< "\nPrerequisite Course: "<< tempCNode->course_prerequisite<< endl;
				}
			}
			else{
				cout<<"\nPrerequiste not avaible and not clear. please contact admin" <<endl;
			}
		}
	}
}

///////////////////////////////////////////////////////////////

void LinkedList::registeredCourses(int stuId){
	SNode* currNode=head;
	while(currNode->student_id!=stuId){
		currNode=currNode->next;
		if(currNode==NULL)
		break;
	}
	if(currNode){
		if(currNode->courseLink){
			CNode* currCNode=currNode->courseLink;
			cout<<left<<setw(15)<<"Course Code "<<left<<setw(60)<<"Course Name "<<left<<setw(12)<<"Course Prerequiste\n"<< endl;
			while(currCNode){
				if(currCNode->course_clear==false && currCNode->course_selection==true){
					cout<<left<<setw(15)<<currCNode->course_code;
					cout<<left<<setw(60)<<currCNode->course_name;
					cout<<left<<setw(12)<<currCNode->course_prerequisite;
					cout<<endl;
				}
				currCNode=currCNode->next;
			}
		}
		else{
			cout<<"\nNo Courses Avaiable!"<< endl;
		}
	}
	else{
		cout<<"\nStudent Account Doesn't exists!"<< endl;
	}
}

///////////////////////////////////////////////////////////////

void LinkedList::dropCourse(int stuId, string courseCode){
	SNode* currNode=head;
	while(currNode->student_id!=stuId){
		currNode=currNode->next;
	}
	if(currNode){
		CNode* currCNode=currNode->courseLink;
		while(currCNode->course_code!=courseCode){
			currCNode=currCNode->next;
			if(currCNode==NULL){
				break;
			}
		}
		if(currCNode){
			currCNode->course_selection=false;
		}
		else{
			cout<<"\nWrong Course Code or Course not avaible"<< endl;
		}
	}
	
}

////////////////////////////////////////////////////////////////

void LinkedList::checkPrerequisite(int stuId, string course_code){
	SNode* currNode=head;
	while(currNode->student_id!=stuId){
		currNode=currNode->next;
	}
	CNode* currCNode=currNode->courseLink;
	CNode* tempNode=currNode->courseLink;
	while(currCNode->course_code!=course_code){
		currCNode=currCNode->next;
		if(currCNode==NULL){
			break;
		}
	}
	if(currCNode){
		if(currCNode->course_prerequisite!="--"){
			while(tempNode->course_code!=currCNode->course_prerequisite){
				tempNode=tempNode->next;
			}
			if(tempNode){
				cout<<endl;
				cout<<currCNode->course_code<< " Prerequisite Course is \n"<< endl;
				cout<<left<<setw(25)<<"Course Code: "<< tempNode->course_code<< endl;
				cout<<left<<setw(25)<<"Course Name: "<< tempNode->course_name<< endl;
				cout<<left<<setw(25)<<"Course Prerequisite: "<< tempNode->course_prerequisite<< endl;
				cout<<left<<setw(25)<<"Course clearance:  "<< tempNode->course_clear<< endl;
			}
			else{
				cout<<"Prerequisite course data not availble!"<< endl;
			}
		}
		else{
			cout<<"Course doesn't prerequisite course"<< endl;
		}
	}
	else
	cout<<"Course not avaible. Enter correct Course Code."<< endl;
}

///////////////////////////////////////////////////////////////

void LinkedList::coursesAvailable(int stuId){
	SNode* currNode=head;
	while(currNode->student_id!=stuId){
		currNode=currNode->next;
	}
	if(currNode->courseLink){
		CNode* currCNode=currNode->courseLink;
		cout<<endl;
		cout<<left<<setw(15)<<"Course Code "<<left<<setw(35)<<"Course Name "<<left<<setw(12)<<"Course Prerequiste\n"<< endl;
		while(currCNode){
			
			if(currCNode->course_clear==false && currCNode->course_selection==false){
				cout<<left<<setw(15)<<currCNode->course_code;
				cout<<left<<setw(35)<< currCNode->course_name;
				cout<<left<<setw(12)<< currCNode->course_prerequisite;
				cout<<endl;
			}
			currCNode=currCNode->next;
		}
	}
	else{
		cout<<"No Courses Avaible!"<< endl;
	}
}

//////////////////////////////////////////////////////////////

void LinkedList::displayList(){
	SNode* currNode=head;
	cout<<left<<setw(30)<<"Name"<<left<<setw(10)<<"ID"<< left<<setw(16)<<"Password\n"<< endl;
	while(currNode!=NULL){
		cout<<left<<setw(30)<<currNode->name;
		cout<<left<<setw(10)<<currNode->student_id;
		cout<<left<<setw(16)<<currNode->password;
		cout<<endl;
		currNode=currNode->next;
	}
	cout<<endl;
}

///////////////////////////////////////////////////////////////

void LinkedList::displayCourse(int studentId){
	SNode* currNode=head;
	while(currNode->student_id!=studentId){
		currNode=currNode->next;
	}
	if(currNode){
		if(currNode->courseLink){
			CNode* currCNode=currNode->courseLink;
			cout<<endl;
			cout<<left<<setw(7)<<"Code "<<left<<setw(65)<<"Course "<<left<<setw(6)<<"Grade"<<left<<setw(15)<<"Prerequiste Course\n"<< endl;
			while(currCNode){
				cout<<left<<setw(7)<<currCNode->course_code;
				cout<<left<<setw(65)<< currCNode->course_name;
				cout<<left<<setw(6)<< currCNode->course_grade;
				cout<<left<<setw(15)<< currCNode->course_prerequisite; 
				cout<<endl; 
				currCNode=currCNode->next;
			}
		}
	}
}

///////////////////////////////////////////////////////////////

bool LinkedList::isEmpty(){
	if(head!=NULL)
	return true;
	else
	return false;
}

//////////////////////////////////////////////////////////////

bool LinkedList::findNode(int stuId){
	if(!isEmpty()){
		return false;
	}
	SNode* currNode=head;
	while(currNode->student_id!=stuId){
		currNode=currNode->next;
		if(currNode==NULL){
			break;
		}
	}
	if(currNode){
		return true;
	}
	else{
		return false;
	}
}
//////////////////////////////////////////////////////////////

bool LinkedList::checkPassword(int stuId, string password){
	SNode* currNode=head;
	while(currNode->student_id!=stuId){
		currNode=currNode->next;
	}
	if(currNode->password==password){
		return true;
	}
	else{
		return false;
	}
}

///////////////////////////////////////////////////////////////

LinkedList::~LinkedList(){
	SNode* currNode=head;
	SNode* tempNode=NULL;
	while(currNode){
		if(currNode->courseLink){
			CNode* currCNode=currNode->courseLink;
			CNode* tempCNode=NULL;
			while(currCNode){
				tempCNode=currCNode->next;
				delete currCNode;
				currCNode=tempCNode;
			}
		}
		tempNode=currNode->next;
		delete currNode;
		currNode=tempNode;
	}
}

////////////////////////////////////////////////////////////////
