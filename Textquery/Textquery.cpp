#include <fstream>
#include <iostream>
#include "TextQuery.h"
using namespace std;

ostream& print(ostream& os, const QueryResult& qr) {
    os << qr.sought << " occurs " << qr.lines->size()
        << " times" << endl;
    for (auto num : *qr.lines) {
        os << "\t(line<<" << num + 1 << ")"
            << *(qr.file->begin() + num) << endl;
    }
    return os;
}


// 通过先编写程序使用这个类 判断该类是否有需要的操作
void runQueries(ifstream& infile) {
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream inputfile;
    inputfile.open("TEST.txt");
    if (!inputfile.is_open()) {
        cout << "wrong" << endl;
        return 1;
    }
    runQueries(inputfile);
}
