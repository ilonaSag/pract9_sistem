#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
volatile int e;
bool run = true;
HANDLE hThread = NULL;
DWORD WINAPI Count(LPVOID num) {
	while (run) {
		e++;
		Sleep(300);
		cout << e << endl;
	}
	return 0;
}
PROCESS_INFORMATION CreateNewProcess(wchar_t lpszAppName[]) {
	STARTUPINFO si;
	PROCESS_INFORMATION piApp;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	if (!CreateProcess(NULL, lpszAppName, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp)) {
		std::cout << "sozdano\n";
		_getch();
	}

	return piApp;
}
int main()
{

	DWORD IDThread;
	setlocale(LC_ALL, "Rus");
	wchar_t name[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";
	STARTUPINFO word;
	PROCESS_INFORMATION wordApp;
	ZeroMemory(&word, sizeof(STARTUPINFO));
	word.cb = sizeof(STARTUPINFO);
	wchar_t excelName[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE";
	STARTUPINFO excel;
	PROCESS_INFORMATION excelApp;
	ZeroMemory(&excel, sizeof(STARTUPINFO));
	excel.cb = sizeof(STARTUPINFO);
	wchar_t paintName[] = L"C:\\Windows\\system32\\mspaint.exe";
	STARTUPINFO paint;
	PROCESS_INFORMATION paintApp;
	ZeroMemory(&paint, sizeof(STARTUPINFO));
	paint.cb = sizeof(STARTUPINFO);
	wchar_t noteName[] = L"C:\\Program Files\\Notepad++\\notepad++.exe";
	STARTUPINFO note;
	PROCESS_INFORMATION noteApp;
	ZeroMemory(&note, sizeof(STARTUPINFO));
	note.cb = sizeof(STARTUPINFO);
	int answer;
	bool flag = true;

	wchar_t newput[256] = L"C:\\Users\\st310-06\\Desktop\\sag\\pract9_sistem\\x64\\Debug\\pract9_2.exe ";
	wchar_t put[256] = L"";

	HANDLE hThread2;
	DWORD IDThread2;
	hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Count, NULL, 0, NULL);
	if (hThread2 == NULL) {
		return GetLastError();
	}
	if (!SetHandleInformation(hThread2, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT)) {
		return GetLastError();
	}
	//дескрипто в символьнуюб строку
	_itow_s((int)hThread2, put, 10);
	//создаем командную строку
	wcscat_s(newput, put);
	PROCESS_INFORMATION piCounter = CreateNewProcess(newput);
	while (flag) {
		cout << "Меню:" << endl;
		cout << "1. Открыть Word" << endl;
		cout << "2. Открыть Excel" << endl;
		cout << "3. Открыть Paint" << endl;
		cout << "4. Открыть Notepad" << endl;
		cout << "5. Закрыть Word" << endl;
		cout << "6. Закрыть Excel" << endl;
		cout << "7. Закрыть Paint" << endl;
		cout << "8. Закрыть Notepad" << endl;
		cin >> answer;
		switch (answer) {
		case 1: if (CreateProcess(name, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &word, &wordApp))
		{
		}
			  break;
		case 2: if (CreateProcess(excelName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &excel, &excelApp))
		{
		}
			  break;
		case 3: if (CreateProcess(paintName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &paint, &paintApp))
		{
		}
			  break;
		case 4: if (CreateProcess(noteName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &note, &noteApp))
		{
		}
			  break;
		case 5:
			TerminateProcess(wordApp.hProcess, 1);
			break;
		case 6:
			TerminateProcess(excelApp.hProcess, 1);
			break;
		case 7:
			TerminateProcess(paintApp.hProcess, 1);
			break;
		case 8:
			TerminateProcess(noteApp.hProcess, 1);
			break;
		case 9:

			ExitProcess(0);
			break;
		}
	}
	WaitForSingleObject(hThread2, INFINITE);
	return 0;
}
