#include "PawException.h"
#include <sstream>


PawException::PawException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* PawException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* PawException::GetType() const noexcept
{
	return "Paw Exception";
}

int PawException::GetLine() const noexcept
{
	return line;
}

const std::string& PawException::GetFile() const noexcept
{
	return file;
}

std::string PawException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}