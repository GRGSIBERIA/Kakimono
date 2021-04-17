#include "mode.h"
#include <fstream>
#include <iostream>

void includeConfigureIntoDatabase(const std::string& confpath, Database* database)
{
	std::ifstream fs(confpath);

	bool is_open = fs.is_open();
	fs.close();

	if (!is_open)	// �ݒ�t�@�C�������݂��Ȃ�
	{
		std::ofstream ofs(confpath);
		ofs << "./kaikei.db";
		ofs.close();
	}

	std::ifstream ifs(confpath);
	if (ifs.fail()) std::cerr << "failed to open kaikei.db." << std::endl;

	std::string dbpath;
	std::getline(ifs, dbpath);
	database = new Database(dbpath);
}

Mode::Mode()
{
	includeConfigureIntoDatabase(confpath, database);	// new Database
}

Mode::~Mode()
{
	delete database;
}
