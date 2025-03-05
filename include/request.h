#pragma once
#include "header.h" 
#include <vector>
#include <memory>

class request {
public:
    request(const Version,const Method,const std::vector<header>&,const std::string&);
    std::string construct() const;
    static request deconstruct(const std::string&);
private:
    Method method;
    Version version;
    std::vector<header> headers;
    std::string content;
};
