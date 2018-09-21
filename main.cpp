#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <random>

using namespace std;

int main() {
    ofstream fout;
    int numList = (rand() % 513) + 512;
    double ranNum;
    int lineNum;
    double num;
    double ave = 0;
    double high = 0;
    double low = 100;
    double median;

    fout.open("Reading.txt");
    if(fout.is_open()){
        for(int i=0;i<numList;i++) {
            ranNum = (rand() /(double)RAND_MAX)* 40 + 50;
            fout << i << " " << fixed << setprecision(3) << ranNum << endl;
        }
        fout.close();
    }
    ifstream fin;
    fin.open("Reading.txt");
    if(fin.is_opend()) {
        istringstream strLine;
        string line;

        while (getline(fin, line)) {
            strLine.clear();
            strLine.str(line);
            strLine >> lineNum;
            strLine >> num;
            ave += num;
            if (num > high) {
                high = num;
            }
            if (num < low) {
                low = num;
            }
            if (lineNum == (numList / 2)) {
                median = num;
            }
        }
        fin.close();
    }

    return 0;
}