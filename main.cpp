#include <iostream>
#include "include/header.h"
using namespace std;
int main(void){
    string test = "hello:beautifil:people of the earch";
    vector<string> res = split(test,":");
    for(string a:res){
        cout << a << '\n';
    }
    // testing the header.
    header host = header("host","exmaple.com");
    cout << "the line: \n" << host.construct() << '\n';
    // testing the request.
    vector<header> headers = {{"host","exmaple.com"}};
    return 0;
}
