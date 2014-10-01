//-------------------------------------------------------------------------------------------
// �������� �������� ��� DiE. C++ (by =TS=)
//-------------------------------------------------------------------------------------------
//[1] BOOL WINAPI DiePlugProc(HWND die_hwnd,const char* file_name,const char* die_name)
//   -�������� ������� (���������� ���������), ������� � ������ ������� ��� ������,
//    ����������� ������ ��������������.
//      1.1) HWND die_hwnd
//           -����� �������� ����� DiE.
//      1.2) const char* file_name
//           -���� � ��������� � ������ ������ ��� (�����, ���� ������ �� �������).
//      1.3) const char* die_name
//           -���� �� Detect it Easy.
//-------------------------------------------------------------------------------------------
//[2] const WINAPI char* DiePlugName()
//   -������� ������� � ��� ��� �������, ����������� ������ ��������������. 
//      2.1) const char* DiePlugName
//           -��� �������.
//-------------------------------------------------------------------------------------------
//[3] BOOL WINAPI DiePlugHwnd(HWND _info, HWND _work)
//   -������� ������� � ������ ������ ����.
//      3.1) HWND _info
//           -����� ���� "Plugin info".
//      3.2) HWND _work
//           -����� ���� "Plugin work".
//-------------------------------------------------------------------------------------------
//[4] BOOL WINAPI DiePlugPe(unsigned char *file_ptr, DWORD file_size, DWORD file_ofset)
//    -������� ������� � ������ ��������� �� ����, �������� � ������ ������, � ��� ������.
//      4.1) unsigned char *file_ptr
//           -��������� �� ������������� ���� (MapViewOfFile).
//      4.2) DWORD file_size
//           -������ ��������� �����.
//      4.3) DWORD file_offset
//	   -�������� ����� ����� � �����
//-------------------------------------------------------------------------------------------

//============================================================================
#include <windows.h>
#define WINAPI __stdcall
//============================================================================
  HWND  info, work;
  DWORD size,offs;
  unsigned char *ptr;
//============================================================================
const char* WINAPI DiePlugName()
{
    return "Example Plugin For DiE";
}
//============================================================================
BOOL WINAPI DiePlugProc(HWND die_hwnd,const char* file_name,const char* die_name) // ������� �������
{
const char *pszFilename;    
char empty[]="empty!";
char szInfo[64];
    SetWindowText(info," Example Plugin For DiE (PDK)");
    SetWindowText(work," only example =)");
    pszFilename=(*file_name)?file_name:empty;
    MessageBox(die_hwnd,pszFilename,":)",0);
    MessageBox(die_hwnd,die_name,":)",0);
    wsprintf(szInfo,"%#X | %#X",size,ptr);
    MessageBox(die_hwnd,szInfo,":)",0);
    return TRUE;
}
//============================================================================
BOOL WINAPI DiePlugHwnd(HWND _info, HWND _work) // �������� ������ ��� ������ ����������
{
  info=_info;
  work=_work;
  return TRUE;
}
//============================================================================
BOOL WINAPI DiePlugPe(unsigned char *file_ptr, DWORD file_size, DWORD file_offset)  // �������� ������ ��������� ����� 
                                         // � ���������, ������������ �������� MapViewOfFile
{
      ptr=file_ptr;
      size=file_size;
      offs=file_offset;
      return TRUE;
}
//============================================================================
BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
  return TRUE;
}
    //============================================================================