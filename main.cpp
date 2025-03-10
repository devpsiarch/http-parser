#include <iostream>
#include "include/header.h"
#include "include/request.h"
#include "include/response.h"
using namespace std;
int main(void){
    // testing the reponse class. 
    vector<header> headers2 = {
        {"host","exmaple.com"},
        {"goodboy","amazing"},
        {"miss","NO"},
    };
    response test6 = response(Version::HTTP_1_1,Response_code::OK,headers2,
                             "{book:the great wall,price:3.99}");
    test6.setBody("<html>  <head>    <title>Example Response</title>  </head>  <body>    <h1>Hello, World!</h1>    <p>This is an example HTTP response.</p>  </body></html>");
    std::string ex2 = test6.construct();
    std::cout << ex2 << "\n\n";

    test6 = response::deconstruct(ex2);
    std::cout << "Body = " << test6.getBody() << '\n';
    std::cout << "status = " << test6.getStatus() << '\n';
    std::cout << "Verion = " << test6.getVersion() << '\n';
    return 0;
    string test = "hello:beautifil:people of the earch";
    vector<string> res = split(test,":");
    for(string a:res){
        cout << a << '\n';
    }
    return 0;
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
        {"goodboy","amazing"},
        {"miss","NO"},
    };
    
    request test3 = request(Method::GET,"account",Version::HTTP_1_1,headers);
    std::string buffer = test3.construct(); 
    std::cout << '\n' << buffer;
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
