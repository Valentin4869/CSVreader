#include <iostream>
#include <fstream>
#include <assert.h>
#include <sstream>
#include <vector>
#include <iterator>
#include <sstream>

vector<vector<double>> readCSV(char* path, bool print) {


	ifstream in;
	string line;
	string cline;
	vector< vector<double> > X;

	in.open(path);
	assert(in.is_open());

	int c = 0;
	while (getline(in, line)) {

		istringstream ss(line);
		istream_iterator<string> begin(ss), end;
		vector<string> lineTokens(begin, end);
		auto it = lineTokens.begin();


		cline = *it;
		if(print)
		cout << "Processing line:\n" << cline << endl;

		bool foundcomma = true;
		int lastoffset = 0;
		int lastcomma = 0;
		vector<double> row;
		while (foundcomma) {

			lastcomma = cline.find(',', lastoffset);


			if (lastcomma >= 0) {


				row.push_back(stod(cline.substr(lastoffset, lastcomma - lastoffset)));
				lastoffset = lastcomma + 1;
			
			}
			else {

				foundcomma = false;
				row.push_back(stod(cline.substr(lastoffset, cline.length() - lastoffset)));
				
			}

		}
		X.push_back(row);
	}

	in.close();


	//print
	if (print) {
		cout << "\n\nelements:"<<c<<"  " << X.size()<<"x"<<X.front().size() << endl;
		for (int i = 0; i < X.size(); i++)
			for (int j = 0; j < X.front().size(); j++)
				printf("%i,%i: %f\n", i, j, X[i][j]);
	}
	

	return X;
}
