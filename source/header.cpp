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
// Here is the imlimentation for the header class.
header::header(const std::string& key_wanted,const std::string& value_needed){
    this->key = key_wanted;
    this->value = value_needed;
}
// This methode will make the header line that will be added to the http request later on.
std::string header::construct() const{
    std::string header_line = key;
    header_line += ": ";
    header_line += value;
    return header_line;
}
