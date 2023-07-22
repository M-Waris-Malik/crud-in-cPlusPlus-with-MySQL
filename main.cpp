#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PASSW = "your password";
const char* DB = "mydb";

int main() {
	
MYSQL* 	conn;
conn = mysql_init(NULL);

if(!mysql_real_connect(conn,HOST, USER, PASSW, DB,3306, NULL,0)){
cout<<mysql_error(conn);	
}

else{
	
	cout<<"Logged in..."<<endl<<endl;
	Sleep(2000);
}

bool exit= false;
while(!exit){
	system("cls");
	int val;
	cout<<"1. Insert Data: "<<endl;
	cout<<"2. Delete Data: "<<endl;
	cout<<"3. Update Data: "<<endl;
	cout<<"0. Exit"<<endl;
	cout<<"Enter value: ";
	cin>>val;
		
	if(val==1){
	string id, name, grade;	
	
		cout<<"Enter ID: ";
	cin>>id;
	
	cout<<"Enter Name: ";
	cin>>name;
	
	cout<<"Enter Grade ";
	cin>>grade;
	
	string query = "INSERT INTO boy (ID, Name, Grade) VALUES('"+id+"', '"+name+"', '"+grade+"')";
	if(mysql_query(conn,query.c_str())){
	cout<<mysql_error(conn)<<endl;
	}
	else{
		cout<<"Data inserted: "<<endl<<endl;
	}
	
	Sleep(2000);	
	}
	
	else if(val==2){
	string id;
	cout<<"Enter id for delete: ";
	cin>>id;
	
	string del = "DELETE FROM boy WHERE ID = '"+id+"'";
		if(mysql_query(conn, del.c_str())){
		cout<<mysql_error(conn)<<endl;
	}
		else{
		cout<<"Data Deleted:"<<endl;
	}
	Sleep(2000);
	}
	
	else if(val==3){
			string id, grade;
		cout<<"Enter id: ";
		cin>>id;
		cout<<"Enter New Grade: ";
		cin>>grade;		
	string upd= "UPDATE boy SET Grade = '"+grade+"' WHERE ID= '"+id+"'";
	if(mysql_query(conn, upd.c_str())){
		cout<<"Error: "<<mysql_error(conn)<<endl;
	}
	else{
		cout<<"Data updated: "<<endl;
	}
	Sleep(2000);		
	}
}	
mysql_close(conn);
    return 0;
}

