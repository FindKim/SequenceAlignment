//
//  ExtractSequence.cpp
//  
//
//  Created by Xuanyi Li on 14-3-18.
//
//

#include "ExtractSequence.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

ExtractSequence :: ExtractSequence(char *filename){
    ifstream file;
    file.open(filename);
    string sequence;
    string line;
    int i=0;
    getline(file,line);
    getHeader(line);
    while (!file.eof()) {
        getline(file,line);
        if (line[0]=='>') {
            Sequence seq (headers[0],headers[1],sequence);
            Sequences.push_back(seq);
            sequence.clear();
            headers.clear();
            getHeader(line);
        }
        else{
            sequence += line;
        }
    }
    Sequence seq (headers[0],headers[1],sequence);
    Sequences.push_back(seq);
}
void ExtractSequence :: printSequences(){
    for (int i = 0; i<Sequences.size(); i++) {
        Sequences[i].print();
        Sequences[i].printSeq();
        cout << "-----------------------" << endl;
    }
    cout << "Number of sequences: " << Sequences.size() << endl;
}
void ExtractSequence :: getHeader(string line){
    int i=0;
    int fasta = 0; // if it is a fasta like header -> 0
    string token;
    istringstream ss(line);
    while (getline(ss,token,'|')) {
        if (i==0) {
            if (token == ">gi") {  // if header start with ">gi": than it's a fasta style header, continue.
                i++;
                fasta = 1;
            }
            else{
                headers.push_back(token);
            }
        }
        if (i==1){
            if (fasta != 1) {  // continute b/c it's fasta header
                headers.push_back(token);
            }
        }
        if (i == 4) headers.push_back(token);				// 3rd token is ref number
        if (i == 5) headers.push_back(token);	// 4th token is seq description
        i++;
    }
}