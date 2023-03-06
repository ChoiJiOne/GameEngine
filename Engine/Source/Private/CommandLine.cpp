#include "CommandLine.h"
#include "TextHelper.hpp"

std::string CommandLine::ExecutePath_;
std::unordered_map<std::string, std::string> CommandLine::ArgumentValues_;

void CommandLine::ParseFromArgV(int32_t ArgC, char* ArgV[])
{
	ExecutePath_ = ArgV[0];

	for (int32_t Index = 1; Index < ArgC; ++Index)
	{
		std::string Argument = ArgV[Index];
		std::vector<std::string> ArgumentElements = TextHelper::Split(Argument, "=");

		if (ArgumentElements.size() == 2)
		{
			ArgumentValues_.insert({ ArgumentElements.front(), ArgumentElements.back() });
		}
	}
}

bool CommandLine::IsValid(const std::string& Key)
{
	return (ArgumentValues_.find(Key) != ArgumentValues_.end());
}

std::string CommandLine::GetValue(const std::string& Key)
{
	CHECK(IsValid(Key), "not valid key value");
	return ArgumentValues_.at(Key);
}