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
    int lineNum = 0;
    double num;
    double ave = 0;
    double high = 0;
    double low = 100;
    double median = 0;

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
    if(fin.is_open()) {
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
        ave = ave/lineNum;
        fin.close();
    }
    cout << "Ther are " << lineNum << " readings in the file" << endl;
    cout << "The average rading is " << fixed << setprecision(3) << ave << endl;
    cout << "The highest reading is " << fixed << setprecision(3) << high << endl;
    cout << "The lowest reaindg is " << fixed << setprecision(3) << low << endl;
    cout << "The median reading is " << fixed << setprecision(3) << median << endl;

    return 0;
}