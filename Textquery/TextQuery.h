#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "QueryResult.h"
using namespace std;

class TextQuery
{
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>>					file;	// ÊäÈëÎÄ¼ş
	map<string, shared_ptr<set<size_t>>>		wm;
};

