
#ifndef CONNECTION_H
#define CONNECTION_H

#include "date.h"
#include "fstream"
class Connection{
	// Its always OK to discuss your private issues with good friends, at least in C++!
	friend class Network;

private:
	string f_name;
	string l_name;
	Date *birthdate;
	Connection* next;
	Connection* prev;

public:
	Connection();
	Connection(string filename);
	Connection(string f_name, string l_name, string bdate);
	void print_connection();
	void set_connection();
	void set_connection(string filename);
	bool operator==(Connection& rhs);
	bool operator!=(Connection& rhs);
	~Connection(){delete birthdate;}
	string getf_name(){return f_name;}
	string getl_name(){return l_name;}
	Date* get_birthdate(){return birthdate;};
};


#endif
