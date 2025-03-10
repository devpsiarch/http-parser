#pragma once
#include "../include/header.h"
class response {
public:
    response(Version,Response_code,const std::vector<header>&,const std::string&) noexcept;
    std::string construct() const noexcept;
    static response deconstruct(const std::string&);
    std::string getVersion() const noexcept {return version_to_string(version);}
    std::string getStatus() const noexcept {return code_to_string(status_code);}
    std::string getBody() const noexcept {return body;}
    void setStatusCode(const Response_code)  noexcept;
    void setHeaders(const std::vector<header>&) noexcept;
    void setBody(const std::string&) noexcept;
private:
    Version version;
    Response_code status_code;
    std::vector<header> headers;
    std::string body;
};
