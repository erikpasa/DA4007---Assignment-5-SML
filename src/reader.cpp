#include "reader.h";
#include <iostream>
#include <stdexcept>
#include <fstream>;
#include <sstream>


using namespace std;

//Constructor
reader::reader(const std::string& Filename,const std::size_t kgramsize) {
    alphabet.clear();
    text = readfile(Filename);

}

//Reading file sequence
std::string reader::readfile(const std::string& filename) {
    //opening file 
    fstream file;
    file.open(filename);
    if(!file.is_open()){
        throw("Could not open text file");
    }

    //reading file and creating alphabet
    // Faster than reading char by char with get(): the file is transferred in 
    //bulk via its stream buffer, avoiding per-character stream call overhead.
    ostringstream ss; 
    ss << file.rdbuf();
    text = ss.str();
    //set automatically removes duplicate chars
    alphabet.insert(text.begin(), text.end());
    return text;
}