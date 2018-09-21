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
    fout.open("Reading.txt");
    if(fout.is_open()){
        for(int i=0;i<numList;i++) {
            ranNum = (rand() /(double)RAND_MAX)* 40 + 50;
            fout << i << " " << fixed << setprecision(3) << ranNum << endl;
        }
    }
    if(fout.is_open()) {
        fout.close();
    }
    return 0;
}