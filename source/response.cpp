#include "../include/response.h"
response::response(Version version,Response_code code,
        const std::vector<header>& headers,const std::string& body_text) noexcept 
        :version(version) , status_code(code) , body(body_text) {
    for(const header& H:headers){
        this->headers.push_back(H);
    }
}

std::string response::construct() const noexcept {
    std::string result;
    // adding the start line.
    result += version_to_string(version);
    result += " ";
    result += std::to_string(static_cast<int>(status_code));
    result += " ";
    result += code_to_string(status_code);
    result += http::END_LINE;
    // adding the headers.
    for(const header& H:this->headers){
        result += H.construct();
    }
    // adding the blanck line.
    result += http::END_LINE;
    // adding the body / content of the response.
    result += body;
    // am assuming here that at the end of the body section of the 
    // response , the body does not end with the end line "\r\n".
    return result;
}
// this will look a lot like the request one since no many differences.
response response::deconstruct(const std::string& message) {
    std::vector<std::string> lines = split(message,http::END_LINE);
    if(lines.size() < 1) {
        throw std::runtime_error("HTTP Response ('" + 
            std::string(message) + "') consisted of " 
            + std::to_string(lines.size()) + " lines, should be >= 1.");
    }
    std::vector<std::string> sections = split(lines[0]," ");
    if(sections.size() != 3){
        throw std::runtime_error("HTTP response startline ('" +
        lines[0] + "') consisted of " +
        std::to_string(sections.size()) + " segments, should be == 3.");
    }
    // extracting the startline.
    Version res_ver = string_to_version(sections[0]);
    Response_code res_code = string_to_code(sections[1]);
    std::string res_status = code_to_string(res_code);
    //extracting the headers.
    std::vector<header> res_headers;
    // here we skip the last 2 line (the black line and the body line)
    for(size_t i = 1 ; i < lines.size()-2 ; i ++){
        res_headers.push_back(header::deconstruct(lines[i]));
    }
    std::string body = lines[lines.size()-1];
    return response(res_ver,res_code,res_headers,body);
}
// I provided these because i think the object should allow for the user to 
// user only one object and modify it acordingly , not everything 
// since that defaits the whole point of using classes.
void response::setStatusCode(const Response_code new_code)  noexcept{
    if(new_code == status_code) return;
    status_code = new_code; 
}
void response::setHeaders(const std::vector<header>& new_headers) noexcept{
    // wop wop , the std::vector does not overload the == so no check
    headers = new_headers;
}
void response::setBody(const std::string& new_body) noexcept{
    body = new_body;
}
