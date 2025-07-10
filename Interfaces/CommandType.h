#pragma once
#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H
namespace Interfaces
{
	//represents possible input command types
	enum class CommandType
	{
		PAUSE_UNPAUSE = 3,
		QUIT = 2,
		ACTION = 1,
		EMPTY = 0,
	};
}
#endif