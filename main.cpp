#include <iostream>
#include "include/header.h"
using namespace std;
int main(void){
    string test = "hello:beautifil:people of the earch";
    vector<string> res = split(test,":");
    for(string a:res){
        cout << a << '\n';
    }
    return 0;
}
