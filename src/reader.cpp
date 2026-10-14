#include "reader.h";
#include <iostream>
#include <stdexcept>
#include <fstream>;
#include <sstream>


using namespace std;

//Constructor
reader::reader(const std::string& Filename,const std::size_t kgramsize) {
    filename = Filename;
    alphabet.clear();
    text = readfile();
    counter();
}

//Reading file sequence
std::string reader::readfile() {
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

void reader::counter() {
    for (size_t i = 0; i + 3 < text.size(); i++) {
        std::string currentkgram = text.substr(i, 3);
        char current_neighborletter = text.at(i + 3);

        kgramcount[currentkgram]++;
        charactertransition[currentkgram][current_neighborletter]++;
    }
}

const std::set<char>&  reader::get_alphabet() const {
    return alphabet;
}

const std::map<std::string,int>& reader::get_kgramcount() const {
    return kgramcount;
}


const std::map<std::string,std::map<char,int>>& reader::get_charactertransition() const {
    return charactertransition;
}


