#include <windows.h>

int main(int argc, char *argv[])
{
   int x;
   unsigned char cmdline[32768];
  
   STARTUPINFO si;
   PROCESS_INFORMATION pi;
   ZeroMemory(&si, sizeof(si));
   si.cb = sizeof(si);
   si.dwFlags = STARTF_USESHOWWINDOW;
   si.wShowWindow = SW_NORMAL;
   ZeroMemory(&pi, sizeof(pi));
   ZeroMemory(&cmdline, 32768);
  
   lstrcpy(cmdline, "_ACM.exe");
  
   for(x=1;x<argc;x++)
   {
      lstrcat(cmdline, " ");
      lstrcat(cmdline, argv[x]);
   }
  
   if(!CreateProcess(0, cmdline, 0, 0, FALSE, 0, NULL, NULL, &si, &pi))
   {
   		MessageBox(NULL, "Can't launch _ACM.exe", "Error", MB_ICONERROR | MB_OK);
   		return 0;
   }
		
   WaitForSingleObject(pi.hProcess, INFINITE);
   CloseHandle(pi.hProcess);
   CloseHandle(pi.hThread);
   return 0;
}
