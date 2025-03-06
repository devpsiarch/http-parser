#include "../include/request.h"
// i made it a vec of unique ptrs to handle memory automaticly.
request::request(const Method method,const std::string& resourse,const Version version,
                 const std::vector<header>&headers) noexcept :
                version(version) , method(method) , resourse(resourse){
    for(const header& H:headers){
        this->headers.push_back(H);
    }
}
// this methode will contruct a request to be send in a string format.
std::string request::construct() const noexcept {
    std::string complete_request;
    // making the Start Line (Methode HTTP_version\r\n). 
    complete_request += method_to_string(method);
    complete_request += " ";
    complete_request += this->resourse;
    complete_request += " ";
    complete_request += version_to_string(version);
    complete_request += http::END_LINE;
    // making Headers (header.key: header.value\r\n)
    for(const header& H:this->headers){
        complete_request += H.construct();
        complete_request += http::END_LINE; 
    }
    // Adding the Empty line (\r\n).
    complete_request += http::END_LINE;
    return complete_request;
}
// this methode will take a string methode instead and make a object for it.
request request::deconstruct(const std::string& message){
    // this will contain all the lines from the http request.
    // here we are spliting the content from the headers.
    std::vector<std::string> lines = split(message,http::END_LINE);
    if(lines.size() < 1){
        throw std::runtime_error("HTTP Request ('" + std::string(message) + "') consisted of " 
                                 + std::to_string(lines.size()) + " lines, should be >= 1.");
    }
    std::vector<std::string> start_line_secs = split(lines[0]," ");
    if(start_line_secs.size() != 3){
        throw std::runtime_error("HTTP Request startline ('" + lines[0] + "') consisted of " 
                                 + std::to_string(start_line_secs.size()) + " segments, should be += 3.");
    }
    // extracting the data we need for the startline.
    Method req_met = string_to_method(start_line_secs[0]);
    std::string req_resourse = start_line_secs[1];
    Version req_ver = string_to_version(start_line_secs[2]);
    // extracting the Headers
    std::vector<header> req_headers;
    for(size_t i = 1 ; i < lines.size() ; i ++){
        req_headers.push_back(header::deconstruct(lines[i]));
    }
    return request(req_met,req_resourse,req_ver,req_headers);
}
