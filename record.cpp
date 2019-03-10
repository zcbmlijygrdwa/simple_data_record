#include <iostream>
#include <fstream>

#include <chrono>
#include <ctime> 

using namespace std;

int main () {
    ofstream myfile;
    float data = 0 ;

    cout<<"Please enter data:"<<endl;
    cin>>data;
    if(int(data)==0)
    {
        cout<<"invalid input, try again.."<<endl;
        return -1;
    }
    auto time_now = std::chrono::system_clock::now();
    std::time_t time_data = std::chrono::system_clock::to_time_t(time_now);

    char buffer [80];
    struct tm * timeinfo = localtime (&time_data);

    //http://www.cplusplus.com/reference/ctime/strftime/
    strftime(buffer,80,"%m-%d-%Y %T",timeinfo);

    std::cout << "Data: "<<data<<" recorded at " << buffer<<endl;

    myfile.open ("data.txt",ios::app);
    myfile << data<<" "<< buffer<<endl;
    myfile.close();
    return 0;
}
