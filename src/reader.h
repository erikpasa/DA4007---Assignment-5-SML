#pragma once
#include <string>
#include <map>
#include <set>

class reader {
public:
    reader(const std::string& Filename,const std::size_t kgramsize);

    //We want encapsulation so we make variables private, but introduce getter functions
    const std::set<char>&  get_alphabet() const;
    const std::map<std::string,int>& get_kgramcount() const;
    const std::map<std::string,std::map<char,int>>& get_charactertransition() const;
    
private:
    //variables
    std::size_t ksize; //size of kgrams
    std::map<std::string,int> kgramcount; //kgrams in the file, and the count of them
    std::map<std::string,std::map<char,int>> charactertransition; //characters that are after the associated kgram, and the count for the letters
    std::set<char> alphabet; //alphabet for the textfile

    //functions
    std::string readfile(const std::string& filename); //reads file and returns a text
    void counter(const std::string& text);  //finds kgrams counts them and counts the neighbouring letter for them, and also creates the alphabet
};
