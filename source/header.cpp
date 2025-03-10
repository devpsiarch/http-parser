#include "../include/header.h"

std::vector<std::string> split(const std::string& expr,const std::string& delim){
    // strtok is still better ...
    std::vector<std::string> tokens = std::vector<std::string>();
    std::string strcpy = expr;
    std::string token;

    std::size_t pos = strcpy.find(delim);
    
    while(pos != std::string::npos){
        token = strcpy.substr(0,pos);
        strcpy.erase(0,pos+(size_t)delim.length());

        tokens.push_back(token);
        pos = strcpy.find(delim);
    }

    if(strcpy.length() > 0){
        tokens.push_back(strcpy);
    }
    return tokens;
}

Version string_to_version(const std::string& str){
    if(str == "HTTP/1.1"){
        return Version::HTTP_1_1;
    }
    else if(str == "HTTP/2.0"){
        return Version::HTTP_2_0;
    }
    else if(str == "HTTP/3.0"){
        return Version::HTTP_3_0;
    }
    return Version::NONE;
}
Method string_to_method(const std::string& str){
    if(str == "POST"){
        return Method::POST;
    }
    else if(str == "GET"){
        return Method::GET;
    }
    else if(str == "DELETE"){
        return Method::DELETE;
    }
    else if(str == "PATCH"){
        return Method::PATCH;
    }
    return Method::NONE;
}

Response_code string_to_code(const std::string& str){
    if(str == "OK"){
        return Response_code::OK;
    }
    else if(str == "Created"){
        return Response_code::Created;
    }
    else if(str == "Forbidden"){
        return Response_code::Forbidden;
    }
    else if(str == "Found"){
        return Response_code::Found;
    }
    else if(str == "Not_Found"){
        return Response_code::Not_Found;
    }
    else if(str == "Internal_Server_Error"){
        return Response_code::Internal_Server_Error;
    }
    return Response_code::NONE;   
}

std::string version_to_string(Version ver){
    // for every possible case of the enum given we will match it ... 
    // execuse me ... we will "switch" it.
    switch (ver){
        case Version::HTTP_1_1:
            return "HTTP/1.1";
        case Version::HTTP_2_0:
            return "HTTP/2.0";
        case Version::HTTP_3_0:
            return "HTTP/3.0";
    }
    return http::CONV_ERR;
}
std::string method_to_string(Method meth){
    // again we will match every enum with its correct string to be used by the other classes.
    switch(meth){
        case Method::POST:
            return "POST";
        case Method::DELETE:
            return "DELETE";
        case Method::PATCH:
            return "PATCH";
        case Method::GET:
            return "GET";
    }
    return http::CONV_ERR;
}
std::string code_to_string(Response_code code){
    // we match each code given here. 
    switch(code){
        case Response_code::OK:
            return "OK";
        case Response_code::Created:
            return "Created";
        case Response_code::Forbidden:
            return "Forbidden";
        case Response_code::Found:
            return "Found";
        case Response_code::Not_Found:
            return "Not_Found";
        case Response_code::Internal_Server_Error:
            return "Internal_Server_Error";
    }
    return http::CONV_ERR;
}

// Here is the imlimentation for the header class.
header::header(const std::string& key_wanted,const std::string& value_needed) noexcept
                :key(key_wanted) , value(value_needed){
}
// This methode will make the header line that will be added to the http request later on.
std::string header::construct() const noexcept {
    std::string header_line = key;
    header_line += ": ";
    header_line += value;
    header_line += http::END_LINE;
    return header_line;
}
 // this methode as the name dictates , will make a header object out of a string 
header header::deconstruct(const std::string& str){
    std::vector<std::string> pairs = split(str,": ");
    if(pairs.size() != 2){
        throw std::runtime_error("Header string ('" + str + "') consisted of " 
                         + std::to_string(pairs.size()) + " keys, should be == 2.");
    }
    // extracting the values (we miss the last two bytes because they are the http::END_LINE)
    return header(pairs[0],pairs[1]);
}
