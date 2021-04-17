#pragma once
#include <string>

class Database
{
	const std::string dbpath;

public:
	Database(const std::string& dbpath);

	virtual ~Database();
};