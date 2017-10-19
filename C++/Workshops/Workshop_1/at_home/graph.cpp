/*
Name: Wahab Zafar
Email: wzafar1@myseneca.ca
Student # : 106-939-168
*/


#include "tools.h"
#include "graph.h"
#include <iostream>

using namespace std;


namespace sict {
	void printGraph(int samples[], int noOfSamples) {
		int max = findMax(samples, noOfSamples);
		cout << "Graph:" << endl;
		for (int i = 0; i < noOfSamples; i++) {
			printBar(samples[i], max);
		}
	}
	// prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max) {
		int i;
		for (i = 0; i < 70 * val / max; i++) {
			cout << "*";
		}
		cout << " " << val << endl;
	}

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples) {
		int i;
		for (i = 0; i < noOfSamples; i++) {
			cout << (i + 1) << "/" << noOfSamples << ": ";
			samples[i] = getInt(1, 1000000);
		}
	}
	int findMax(int samples[], int noOfSamples) {
		int max = samples[0];
		int i;
		for (i = 1; i < noOfSamples; i++) {
			if (max < samples[i]) max = samples[i];
		}
		return max < 70 ? 70 : max;
	}
}