/*
**    Kupa Qt utils - main.cpp
**
**    simple main file used to test the classes that will be used by the Kupa Qt apps    
**
**    by StephaneAG - 2013
*/

#include <iostream>
#include <string>
#include <vector> 

using namespace std;


// ---- class KupaSettings / a class holding the settings present in the 'node_settings.kupa' file, used by the 'Kupa.node' program

class KupaSettings
{
    std::string os, kupy_method;
  public:
    // setters
    void set_os(std::string); // set the OS in use
    void set_kupy_method(std::string); // set the Kupy method
    void global_setup(std::string, std::string); // set both at the same time 
    // getters
    std::string current_OS() { return os; }
    std::string current_kupy_method() { return kupy_method; }
};

void KupaSettings::set_os(std::string the_os)
{
    os = the_os;
}

void KupaSettings::set_kupy_method(std::string the_kupy_method)
{   
    kupy_method = the_kupy_method;
}

void KupaSettings::global_setup(std::string the_os, std::string the_kupy_method)
{
    os = the_os;
    kupy_method = the_kupy_method;
}






// ---- class KupaClient / a class representing any client present in the 'settings.kupa' file, used by the 'Kupa_<os>.sh' program
class KupaClient
{
    std::string name, ip_address, kupa_directory_path; // the name of the Kupa client node, its IP address & the path to the ( remote ) Kupa directory
    int port; // the port number to use for the ssh & scp calls ( inside Kupa_<os>.sh )
  public:
    // setters
    void set_name(std::string); // set the client's name
    void set_ip_address(std::string); // set the client's IP address
    void set_port(int); // set the client's port number
    void set_kupa_directory_path(std::string); // set the client's path to the Kupa directory
    // getters
    std::string get_name() { return name; }
    std::string get_ip_address() { return ip_address; }
    int get_port_number() { return port; }
    std::string get_kupa_directory_path() { return kupa_directory_path; }
};

void KupaClient::set_name(std::string the_name)
{
    name = the_name;
}

void KupaClient::set_ip_address(std::string the_ip_address)
{
	    ip_address = the_ip_address;
}

void KupaClient::set_port(int the_port_number)
{
	    port = the_port_number;
}

void KupaClient::set_kupa_directory_path(std::string the_kupa_directory_path)
{
	    kupa_directory_path = the_kupa_directory_path;
}






// ---- class KupaClientsList / a class hodling all the clients present in the 'settings.kupa' file, used by the 'Kupa_<os>.sh' program
class KupaClientsList
{
    //KupaClient clientsArray[]; // an array holding all the clients present in the 'Kupa clients list'
    std::vector<KupaClient> kclientsv; // same as above ut usin a vector instead of an array
  public:
    //void setup_array(); // stuff that will be done in a near future in a constructor ...
    void add_client(KupaClient&); // add a client to the array held
    void remove_client(KupaClient&); // remove a client from the array held
    void empty_clients_list(); // empty the clients list from woever client was in it
    void list_clients(); // list all the clients currently held by the array
    KupaClient get_client_from_name(std::string); // get a client from his name
    KupaClient get_client_from_ip_address(std::string); // get a client from his IP address
};

//KupaClientsList::setup_array()
//{
//    //clientsArray = NULL; // init to null ( at least ? )
//}

void KupaClientsList::add_client(KupaClient& the_client)
{
    kclientsv.push_back(the_client); 
}

void KupaClientsList::remove_client(KupaClient& the_client)
{
    //kclientsv.
}

void KupaClientsList::empty_clients_list()
{
    //kclientsv.
}

void KupaClientsList::list_clients()
{
    //kclientsv.
}


KupaClient KupaClientsList::get_client_from_name(std::string the_client_name)
{
    //kclientsv.
}

KupaClient KupaClientsList::get_client_from_ip_address(std::string the_client_ip_address)
{
    //kclientsv.
}

// ---- main

int main ()
{
    /*  test-implm of the 'KupaSettings' class */
    	
    KupaSettings kupaSetup; // create an instance of the KupaSettings class

    // setup independently the kupa settings properties
    kupaSetup.set_os("Mac"); // 1 stands for Linux, 2 for Mac, and maybe one day 3 for Windaube ..
    kupaSetup.set_kupy_method("direct"); // 1 stands for 'direct', 2 for 'twosteps'

    // getting the current settings
    cout << "Current Kupa.node settings:" << "\tOS: " << kupaSetup.current_OS() << "\tKupy method: " << kupaSetup.current_kupy_method() << endl;

    // modfying both at the same time
    kupaSetup.global_setup( "Linux", "twosteps"); // Linux - twosteps kupy 
    
    // getting the current settings
    cout << "Current Kupa.node settings:" << "\tOS: " << kupaSetup.current_OS() << "\tKupy method: " << kupaSetup.current_kupy_method() << endl;



    /* test-implm of the 'KupaCLient' class */
    KupaClient kclient; // create an instance of the KupaCLient class ( ~ a client that will be added to the 'Kupa shared klipboard' )
    // adjust its properties ( will be done in a constructor in a near future (...)
    kclient.set_name("StephaneAG_macbookpro"); // set the name of the client
    kclient.set_ip_address("192.168.1.7"); // set the IP address of the client
    kclient.set_port(22); // set the port number to use when connectiong to the above IP address
    kclient.set_kupa_directory_path("/Applications/Kupa"); // set the Kupa directory path (the 'remote' directory path pointing to the client's 'Kupa.node' location )

    // getting infos on a specifi client
    cout << "Client name: " << kclient.get_name() << endl;
    cout << "Client IP address: " << kclient.get_ip_address() << endl;
    cout << "Client port number: " << kclient.get_port_number() << endl;
    cout << "Client Kupa directory path: " << kclient.get_kupa_directory_path() << endl;


    return 0;
}
