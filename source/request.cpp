#include "../include/request.h"
// i made it a vec of unique ptrs to handle memory automaticly.
request::request(const Version Version,const Method method,const std::vector<header>& tokens,
                 const std::string& content){
    this->version = version;
    this->method = method;
    for(const header& H:tokens){
        this->headers.push_back(H);
    }
    this->content = content;
}
// this methode will contruct a request to be send in a string format.
std::string request::construct() const{
    std::string complete_request;
    // making the Start Line (Methode HTTP_version\r\n). 
    complete_request += method_to_string(method);
    complete_request += version_to_string(version);
    complete_request += "\r\n";
    // making Headers (header.key: header.value\r\n)
    for(const header& H:this->headers){
        complete_request += H.construct();
        complete_request += "\r\n"; 
    }
    // Adding the Empty line (\r\n).
    complete_request += "\r\n";
    // Adding the content whatever it is.
    complete_request += content;
    return complete_request;
}
// this methode will take a string methode instead and make a object for it.
request request::deconstruct(const std::string&){
    
}
