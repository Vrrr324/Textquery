#pragma once
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class QueryResult
{
public:
	friend ostream& print(ostream&, const QueryResult&);
	QueryResult(string s,
		shared_ptr<set<size_t>>p,
		shared_ptr<vector<string>>f) :
	sought(s),lines(p),file(f){}

private:
	string						sought;		// 查询单词
	shared_ptr<set<size_t>>		lines;		// 出现的行号
	shared_ptr<vector<string>>	file;		// 输入文件
};

