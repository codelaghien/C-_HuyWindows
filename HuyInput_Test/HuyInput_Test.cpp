// HuyInput_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <locale> 
#include <iostream> 
#include <string>    

#include "HuyInput.h"

using namespace std;

int main()
{
    cout << "Test HuyInput class ! \n";

	wstring str = L"Đây là chuỗi tiếng Việt có dấu";
	//wcout << str;
	//HuyInput::WriteString(str);

	//string str0 = "Đây là chuỗi tiếng Việt có dấu";
	//cout << str0;
	//HuyInput::WriteString(str0);

	/*wstring name = HuyInput::ReadString(L"\nBạn tên là gì: ");
	HuyInput::WriteString(L"Chào bạn *" + name + L"*");

	int age = HuyInput::ReadInt(L"\n\nBạn bao nhiêu tuổi: ");
	HuyInput::WriteString(L"Bạn đã *" + HuyInput::ToUnicode(age) + L"* tuổi");

	double salary = HuyInput::ReadDouble(L"\n\nBạn làm được bao nhiêu: ");
	HuyInput::WriteString(L"Bạn làm được *" + HuyInput::ToUnicode(salary) + L"*");*/

	/*HuyInput::WriteString(L"\n\nNhập vào tuổi và lương: ");
	int age = HuyInput::ReadInt();
	double salary = HuyInput::ReadDouble();
	HuyInput::WriteString(L"\nBạn đã *" + HuyInput::ToUnicode(age) + L"* tuổi");
	HuyInput::WriteString(L"\nBạn làm được *" + HuyInput::ToUnicode(salary) + L"*");*/

	cout << "\n\n\n\n";
	system("pause");
	return 0;
}
 