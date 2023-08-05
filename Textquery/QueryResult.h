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
	string						sought;		// ��ѯ����
	shared_ptr<set<size_t>>		lines;		// ���ֵ��к�
	shared_ptr<vector<string>>	file;		// �����ļ�
};

