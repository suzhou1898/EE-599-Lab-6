
#include "connection.h"

Connection::Connection(){
    set_connection();
}


Connection::Connection(string f_name, string l_name, string bdate){
    this->f_name = f_name;
    this->l_name = l_name;
    this->birthdate = new Date(bdate);
}


Connection::Connection(string filename){
    // TODO: Complete this method!

    set_connection(filename);
}

void Connection::set_connection(){
    // prompts for the information of the user
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    string temp;

    cout << "First Name: ";
    // TODO: pay attention to how we read first name, as it can have spaces!
    std::getline (std::cin,f_name);

    cout << "Last Name: ";
    std::getline (std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline (std::cin,temp);
    // TODO: pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp);
}


void Connection::set_connection(string filename){
    // TODO: Complete this method!

    // Open the file <filename>
    // Look at connection_template.txt
    // Line #1: first name (can have spaces!)
    // Line #2: last name (can have spaces!)
    // Line #3: date of birth in string format

    string bdate;
    ifstream infile;
    infile.open(filename,ios::in);
    getline(infile, f_name);
    getline(infile, l_name);
    getline(infile, bdate);
    birthdate=new Date(bdate);
    infile.close();
}



bool Connection::operator==(Connection& rhs) {
    // TODO: Complete this method!
    // Hint: Look at how we overloaded equality in Date
    // Two connection are equal only if they have the same first name, last name and date of birth!

    if(this->f_name==rhs.getf_name() && this->l_name==rhs.getl_name() && *(this->birthdate)==*(rhs.get_birthdate())){
        return true;
    }
    else{
        return false;
    }
}

bool Connection::operator!=(Connection& rhs){
    // TODO: Complete this method!
    // Hint: again, look at how we did this for Date
    return !(*this==rhs);
}

void Connection::print_connection(){
    cout << l_name <<", " << f_name << endl;
    birthdate->print_date("Month D, YYYY");
}

