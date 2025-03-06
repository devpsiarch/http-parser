#pragma once
#include "header.h" 
#include <vector>
#include <memory>
#include <stdexcept>
class request {
public:
    request(const Method,const std::string&,const Version,const std::vector<header>&) noexcept ;
    std::string construct() const noexcept;
    std::string getVersion() const noexcept {return version_to_string(version);}
    std::string getMethod() const noexcept {return method_to_string(method);}
    std::string getResourse() const noexcept {return resourse;}
    static request deconstruct(const std::string&);
private:
    Method method;
    Version version;
    std::string resourse;
public:
    std::vector<header> headers;
};
