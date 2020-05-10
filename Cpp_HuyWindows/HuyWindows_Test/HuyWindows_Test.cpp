// HuyWindows_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h> 
#include <string>
#include <algorithm>
#include <windows.h> 
#include <locale>
#include <codecvt>
#include <cstdlib>
#include <cstdio>  
#include <fstream>      
#include <stdio.h>       
#include <stdlib.h>      
#include <time.h>       
#include <vector>

#include "HuySize.h";     
#include "HuyCurrentConsole.h";  
#include "HuyWindows.h";  
#include "HuyColors.h";   

void TruyenKieu(int parentWidth, int parentHeight);

int main()
{
	srand(time(NULL));

	HuySize consoleSize = HuyCurrentConsole::getSize();
	HuyWindows win(0, 0, consoleSize.width, consoleSize.height, 1, HuyColors::BLUE, HuyColors::WHITE);
	win.showConsoleCursor(false);
	win.saveScreenRect();
	win.animateFrame();
	win.clearConsole();
	win.drawFrame();

	wstring message = L"Cửa sổ chính"; 
	win.write(message, (win.getWidth() - (int)message.size()) / 2, (win.getHeight() / 2) - 1, HuyColors::BLUE, HuyColors::WHITE);

	int minWidth = 15;
	int minHeight = 4;
	int totalWindows = 10;
	HuyWindows windows[100];
	for (int i = 0; i < totalWindows; i++) {
		int x = rand() % (win.getWidth() - minWidth - 2) + 1;
		int y = rand() % (win.getHeight() - minHeight - 2) + 1;
		int w = rand() % (win.getWidth() - x - 1 - minWidth) + minWidth;
		int h = rand() % (win.getHeight() - y - 1 - minHeight) + minHeight;
		int background = HuyColors::getRandom();
		int color = HuyColors::getRandom();
		while (color == background) {
			color = HuyColors::getRandom();
		}

		windows[i] = HuyWindows(x, y, w, h, 1, background, color);
		windows[i].saveScreenRect();
		windows[i].animateFrame();
		windows[i].clearConsole();
		windows[i].drawFrame();

		message = L"Cửa sổ số " + HuyWindows::toWString(i + 1);
		windows[i].write(message, (windows[i].getWidth() - message.size()) / 2, 0, background, color);
		windows[i].write(message, (windows[i].getWidth() - message.size()) / 2, windows[i].getHeight() / 2, background, color);

		Sleep(10);
	}
	 
	TruyenKieu(win.getWidth(), win.getHeight());

	char c0 = _getch();
	for (int i = totalWindows - 1; i >= 0; i--) {
		windows[i].restoreScreenRect(); 
		Sleep(10);
	}

	char c = _getch();
	return 0;
}

void TruyenKieu(int parentWidth, int parentHeight) {
	vector<wstring> lines;
	lines.push_back(L" Truyện Kiều ");
	lines.push_back(L"Trăm năm trong cõi người ta");
	lines.push_back(L"Chữ tài chữ mệnh khéo là ghét nhau");
	lines.push_back(L"");
	lines.push_back(L"Trải qua một cuộc bể dâu");
	lines.push_back(L"Những điều trông thấy mà đau đớn lòng");
	lines.push_back(L"");
	lines.push_back(L"Lạ gì bỉ sắc tư phong");
	lines.push_back(L"Trời xanh quen thói má hồng đánh ghen");
	lines.push_back(L"");
	lines.push_back(L"Cảo thơm lần giở trước đèn");
	lines.push_back(L"Phong tình có lục còn truyền sử xanh");

	int w = parentWidth / 1.5;
	if (w > 50) w = 50;
	int x = (parentWidth - w) / 2;
	int h = lines.size() + 4;
	int y = (parentHeight - h) / 2;

	HuyWindows win(x, y, w, h, 1, HuyColors::LIGHTMAGENTA, HuyColors::WHITE);
	win.showConsoleCursor(false);
	win.saveScreenRect();
	win.animateFrame();
	win.clearConsole();
	win.drawFrame();

	win.write(lines[0], (win.getWidth() - (int)lines[0].size()) / 2, 0, HuyColors::GREEN, HuyColors::WHITE);
	for (int i = 1; i < lines.size(); i++) {
		win.write(lines[i], (win.getWidth() - (int)lines[i].size()) / 2, i + 1);
	}
	wstring author = L" Nguyễn Du ";
	win.write(author, (win.getWidth() - author.size() - 2), win.getHeight() - 1, HuyColors::BROWN, HuyColors::WHITE);

	char c = _getch();
	win.restoreScreenRect();
}
