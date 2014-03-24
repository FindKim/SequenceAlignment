/*

	Created by Kim Ngo 14/3/23
	
	CodonFrequency.cpp
	
	Calculates frequency for each codon in the gene
	Create library of codon frequencies
	
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <utility> // pair

using namespace std;

CodonFrequency::CodonFrequency(string) {

	public:
		CodonFrequency(string);
		int getCodonCount;
	
	private:
		vector< pair<string, int> > codon;
			// Stores codon and # of occurances
		vector <float> codonFreqSeq;
			// Vector of codon frequencies that correspond with the seq using codon vector
		int codonCount; 	
			// Total number of codons in sequence used to calculate frequency

}
