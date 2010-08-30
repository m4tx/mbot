#ifndef MainFunctions_hpp
#define MainFunctions_hpp

#include <windows.h>
#include <string>
#include <vector>

HWND CreateButton (HWND ParentHwnd, HINSTANCE hInstance, char* Text, int x, int y, int w, int h);
HWND CreateEditBox (HWND ParentHwnd, HINSTANCE hInstance, int x, int y, int w, int h, bool Multiline, bool Readonly);
std::string GetWndText (HWND hwnd);
std::string StrToLower (std::string src);
void trim( std::string& str );
void DeleteSpecialChars( std::string& str );
void DeleteSpecialChars2 (std::string& src);
void DeleteQuestionMark (std::string &src);
void DeleteQuestionMark (std::vector<std::string> &src);
std::string DeletePolishChars (std::string src);

#endif
