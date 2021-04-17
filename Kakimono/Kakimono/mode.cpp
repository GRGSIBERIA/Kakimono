#include "mode.h"
#include <fstream>
#include <iostream>

void includeConfigureIntoDatabase(const std::string& confpath, Database* database)
{
	std::ifstream fs(confpath);

	bool is_open = fs.is_open();
	fs.close();

	if (!is_open)	// İ’èƒtƒ@ƒCƒ‹‚ª‘¶İ‚µ‚È‚¢
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

	std::cout << std::endl;
	std::cout << "Enter the command in ()" << std::endl;
	std::cout << "- (register) a subject" << std::endl;
	std::cout << "- (insert) an journal" << std::endl;
	std::cout << "- (query) summaries" << std::endl;
	std::cout << "- (update) an journal" << std::endl;
	std::cout << "- (delete) an journal" << std::endl;
	std::cout << "- (exit)" << std::endl;
	std::cout << "command ? >>> ";

	while (state != State::EXIT)
	{

	}
}

Mode::~Mode()
{
	delete database;
}
