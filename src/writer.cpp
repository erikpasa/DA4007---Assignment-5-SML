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
    weights.clear();
    const map<string,map<char,int>>& transitions = r.get_charactertransition();
    
    const map<char,int>& lettercount = transitions.at(kgram);
    for(const auto& i : alphabetvector){
        auto it = lettercount.find(i);
        if(it != lettercount.end()) {
            weights.push_back(it->second+alpha);
        }
        else{
            weights.push_back(0.0+alpha);
        }
    }
}

std::string writer::writeoutput() {
    string output;
    //initial weights
    {
    vector<string> kgrams;
    vector<double> startweights;
    const std::map<std::string,int>& kgramscount = r.get_kgramcount();
    for(const auto& i : kgramscount) {
        kgrams.push_back(i.first);
        startweights.push_back(i.second);
    }
    //initial distribution
    discrete_distribution<int> dist(startweights.begin(),startweights.end());
    output+=kgrams.at(dist(engine));
    }
    discrete_distribution<int> dist;
    std::map<std::string,std::map<char,int>> charactertransition;
    const map<string,map<char,int>>& transitions = r.get_charactertransition();
    for(int i = 0; i<length;++i) {
        string currentkgram = output.substr(output.size() - sizekgram);
        createweights(currentkgram);
        for(const auto& i : transitions.at()) {
        output+=alphabetvector.at(dist(engine));
    }
}
}

