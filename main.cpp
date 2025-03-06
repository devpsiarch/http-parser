#include <iostream>
#include "include/header.h"
#include "include/request.h"
using namespace std;
int main(void){
    /*string test = "hello:beautifil:people of the earch";
    vector<string> res = split(test,":");
    for(string a:res){
        cout << a << '\n';
    }
    // testing the header.
    header host = header::deconstruct("host: exmaple.com\r\n");
    std::cout << host.getKey() << '\n';
    std::cout << host.getVal() << '\n';
    std::string test2 = host.construct();
    cout << "contructed is : " << test2 << '\n';
    return 0;
    // testing the request.
    vector<header> headers = {
        {"host","exmaple.com"},
        {"nigger","amazing"},
        {"miss","NO"},
    };
    request test3 = request(Method::GET,"account",Version::HTTP_1_1,headers);
    std::string buffer = test3.construct(); 
    std::cout << '\n' << buffer;*/
    std::string test4 = "POST /users HTTP/1.1\r\nHost: example.com\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: 50\r\n"; 
    request test5 = request::deconstruct(test4);
    std::cout << test5.getVersion() << '\n';
    std::cout << test5.getMethod() << '\n';
    std::cout << test5.getResourse() << '\n';
    for(const header& H:test5.headers){
        cout << H.getKey() << "->" << H.getVal() << '\n';
    }
    cout << "hurray";
    return 0;
}
