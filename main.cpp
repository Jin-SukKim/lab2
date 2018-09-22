#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;
bool comp(double a, double b) {
    return a < b;
}

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
    double ascNum[numList];

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
        int count = 0;
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
            ascNum[count] = num;
            count++;
        }
        ave = ave/lineNum;
        fin.close();
    }

    std::sort(ascNum, ascNum+numList, comp);
    if(numList%2==0) {
        median = (ascNum[numList/2] + ascNum[numList/2+1]) / 2;
    } else {
        median = ascNum[numList/2];
    }

    cout << "There are " << lineNum+1 << " readings in the file" << endl;
    cout << "The average reading is " << fixed << setprecision(3) << ave << endl;
    cout << "The highest reading is " << fixed << setprecision(3) << high << endl;
    cout << "The lowest reading is " << fixed << setprecision(3) << low << endl;
    cout << "The median reading is " << fixed << setprecision(3) << median << endl;
    
    return 0;
}