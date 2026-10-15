#include "reader.h"
#include <stdexcept>
#include <fstream>
#include <cstddef>
#include <sstream>


using namespace std;

//Constructor
reader::reader(const string& Filename,const size_t kgramsize) {
    filename = Filename;
    if(kgramsize == 0) {
        throw invalid_argument("The kgram cannot have zero length");
    }
    string text = readfile(Filename,kgramsize);
    alphabet.insert(text.begin(), text.end());
    counter(text,kgramsize);
}

//Reading file sequence
string reader::readfile(const string& Filename, const size_t kgramsize) {
    //opening file 
    ifstream file;
    file.open(Filename);
    if(!file.is_open()){
        throw runtime_error("cannot open file '" + Filename + "'");
    }

    // Faster than reading char by char with get(): the file is transferred in 
    //bulk via its stream buffer, avoiding per-character stream call overhead.
    ostringstream ss; 
    ss << file.rdbuf();
    string text = ss.str();
    if(text.size()<=kgramsize){
        throw runtime_error("text file is too short compared to chosen kgrams");
    }
    return text;
}

void reader::counter(const string& text, size_t ksize) {
    for (size_t i = 0; i + ksize <= text.size(); i++) {
        kgramcount[text.substr(i, ksize)]++;
    }

 
    for (size_t i = 0; i + ksize < text.size(); i++) {
        charactertransition[text.substr(i, ksize)][text[i + ksize]]++;
    }
}

const set<char>&  reader::get_alphabet() const {
    return alphabet;
}

const map<string,int>& reader::get_kgramcount() const {
    return kgramcount;
}


const map<string,map<char,int>>& reader::get_charactertransition() const {
    return charactertransition;
}