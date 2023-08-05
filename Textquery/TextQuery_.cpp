#include "TextQuery.h"

TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1; // 行号
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
			{
				// 注意:`.`和`->`
				lines.reset(new set<size_t>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& sought) const
{
	// 如果没有找到 返回一个空
	static shared_ptr<set<size_t>> nodata(new set<size_t>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
	{
		return QueryResult(sought, nodata, file);
	}
	else
	{
		return QueryResult(sought, loc->second, file);
	}
}
