#pragma once
// here we will define some constants for convicence also some utils.
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& expr,const std::string& delim);


namespace http {
    static std::string END_LINE = "\r\n";
    static std::string CONV_ERR = "NOT";
}
// they are wrapped by classes here to avoid conflicts in naming
enum class Version {
    HTTP_1_1,
    HTTP_2_0,
    HTTP_3_0,
    NONE
};
enum class Method {
    POST,
    GET,
    DELETE,
    PATCH,
    NONE
};
// these will most lickly be either friends functions or directly used in the class below
Version string_to_version(const std::string& str);
Method string_to_method(const std::string& str);

std::string version_to_string(Version ver);
std::string method_to_string(Method meth);
class header {
public:
    header(const std::string&,const std::string&) noexcept;
    std::string getKey() const {return key;}
    std::string getVal() const {return value;}
    void setKey(const std::string& new_key) {key = new_key;}
    void setVal(const std::string& new_value) {value = new_value;}
    std::string construct() const noexcept ;    // this will make a header format like : (key: value)
    static header deconstruct(const std::string&);
private:
    std::string key;
    std::string value;
};
