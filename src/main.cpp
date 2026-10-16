#include "reader.h"
#include "writer.h"
#include <stdexcept>
#include <cstddef>
#include <string>
#include <iostream>


using namespace std;

int main(int argc, char *argv[]) {
    //parameters
try{
size_t kgramsize;
string Filename;
size_t lengthoutput;
double alpha;
size_t pos;   
if(argc < 4) {
throw invalid_argument("There is a minimum of three arguments");
        }
    //pseudocount handling
if(argv[1][0]=='-'){

if(string(argv[1]) !="-a") {
throw invalid_argument("anything other than -a is not a option");
    }
else{
if(argc != 6) {
throw invalid_argument("There are 5 arguments for this setting");
    }
alpha = stod(argv[2], &pos);                                 
if(pos != string(argv[2]).size()) {                           
throw invalid_argument("-a must be followed by a number");
        }
kgramsize = stoul(argv[3], &pos);                              
if(argv[3][0]=='-' || pos != string(argv[3]).size()) {         
throw invalid_argument("k must be a positive integer");
        }
Filename = argv[4];
lengthoutput = stoul(argv[5], &pos);                           
if(argv[5][0]=='-' || pos != string(argv[5]).size()) {         
throw invalid_argument("output length must be a positive integer");
        }
    }}
else{
if(argc != 4) {
throw invalid_argument("There are three arguments for this setting");
    }
alpha = 0.0;
kgramsize = stoul(argv[1], &pos);                             
if(pos != string(argv[1]).size()) {                            
throw invalid_argument("k must be a positive integer");
        }
Filename =  argv[2];
lengthoutput = stoul(argv[3], &pos);                         
if(argv[3][0]=='-' || pos != string(argv[3]).size()) {      
throw invalid_argument("output length must be a positive integer");
        }
    }
    reader  input_reader(Filename,kgramsize);
    writer output_writer(input_reader,alpha,lengthoutput,kgramsize);
    cout << output_writer.writeoutput() << '\n';
    }
catch(const exception& e) {
cerr << "slm: " << e.what() << '\n';
return 1;
    }
return 0;
}