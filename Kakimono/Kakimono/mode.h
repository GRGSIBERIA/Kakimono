#pragma once
#include <string>

#include "database.h"

class Mode
{
	const std::string confpath = "./kaikei.conf";

	enum class State
	{
		COMMAND, // コマンド待機モード
		INSERT,	// 挿入モード
		QUERY,	// 閲覧モード
		UPDATE,	// 更新モード
		DELETE	// 削除モード
	} state = State::COMMAND;

	Database* database;

public:
	

	Mode();

	virtual ~Mode();
};