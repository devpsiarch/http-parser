#pragma once
#include "header.h" 
#include <vector>
#include <memory>
#include <stdexcept>
class request {
public:
    request(const Method,const std::string&,const Version,const std::vector<header>&) noexcept ;
    std::string construct() const noexcept;
    static request deconstruct(const std::string&);
private:
    Method method;
    Version version;
    std::string resourse;
    std::vector<header> headers;
};
