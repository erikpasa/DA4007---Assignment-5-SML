#include "writer.h"
#include <stdexcept>

using namespace std;
//Constructor
writer::writer(const reader& reader_ref, double pseudocount,
               std::size_t lengthoutput, std::size_t sizekgram)
    : engine(random_device{}()), alpha(pseudocount),
      r(reader_ref),
      length(lengthoutput),
      sizekgram(sizekgram) {
    //check if given alpha is valid
    if(alpha < 0){
        throw invalid_argument("Alpha cannot be negative");
    }
    //check if sizekgram has valid size
    if(lengthoutput<sizekgram) {
        throw invalid_argument("Output length must be at least the k-gram size");
    }
    
    const set<char>& letters = r.get_alphabet();
    
    //create alphabet vector
    for(char c : letters) {
        alphabetvector.push_back(c);
    }

};

void writer::createweights(const std::string& kgram) {

}

std::string writer::writeoutput() {
    
    for(int i = 0; i<length;++i) {

    }
}

