#include <string>
#include <Windows.h>
#include <tchar.h>

using std::wstring;

int _tmain(int argc, _TCHAR* argv[])
{
	wstring command(L"/K \"cd ");
	wstring currentDir(MAX_PATH, 0);

	GetCurrentDirectory(currentDir.size(), const_cast<LPWSTR>(currentDir.data()));
	currentDir.insert(0, L"\"");
	currentDir.append(L"\"");

	command.append(currentDir);
	currentDir.append(L"\"");

	ShellExecute(NULL,
		L"runas",
		L"cmd.exe",
		command.data(),
		currentDir.data(),
		SW_SHOW);

	return 0;
}

