//File: A3_SheetPb1_20220314.cpp
//Purpose:Label Generator.
//Author: Mahmoud Gomaa Rabea
//Section:S17,18
//ID:20220314
//TA: Rana Abd-Elkader
//Date:9 Dec 2023

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class LabelGenerator {
protected:
    string label;
    int sequence;

public:
    LabelGenerator(string l, int s) : label(l), sequence(s) {}

    virtual void nextLabel() {
        cout << label << ' ' << sequence++ << endl;
    }
};

class FileLabelGenerator : public LabelGenerator {
private:
    string fileName;
    ifstream file;
    vector<string> lines;
    int idx;

public:
    FileLabelGenerator(string l, int s, string f) : LabelGenerator(l, s), fileName(f), idx(0) {
        file.open(fileName, ios::in);
        string line;
        if (file.is_open()) {
            while (getline(file, line))
                lines.push_back(line);
            file.close();
        } else {
            cerr << "Error: Could not open file " << fileName << endl;
        }
    }

    void nextLabel() override {
        ofstream outFile;
        if (!idx)
            outFile.open(fileName, ios::out);
        else
            outFile.open(fileName, ios::app);

        if (outFile.is_open()) {
            outFile << label << ' ' << sequence++ << ' ' << lines[idx++] << endl;
            outFile.close();
        } else {
            cerr << "Error: Could not open file " << fileName << endl;
        }
    }
};

int main() {
    LabelGenerator figureNumbers("Figure", 1);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        figureNumbers.nextLabel();
        cout << (i < 2 ? ", " : "\n");
    }

    FileLabelGenerator figureLabels("Figure", 1, "anyFile.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        figureLabels.nextLabel();
    }

    return 0;
}
