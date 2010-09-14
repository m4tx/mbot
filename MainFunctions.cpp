#include "MainFunctions.hpp"

//==================================================================================================


//==================================================================================================

std::string GetWndText (HWND hwnd)
{
    DWORD size = GetWindowTextLength (hwnd);
    LPSTR Buffer = (LPSTR) GlobalAlloc (GPTR, size + 1);
    GetWindowText (hwnd, Buffer, size + 1);

    return std::string(Buffer);
}

//==================================================================================================

std::string StrToLower (std::string src)
{
    for (unsigned int i = 0; i <= src.length(); i++)
    {
        switch (src[i])
        {
            case 'A': src[i] = 'a'; break;
            case '�': src[i] = '�'; break;
            case 'B': src[i] = 'b'; break;
            case 'C': src[i] = 'c'; break;
            case '�': src[i] = '�'; break;
            case 'D': src[i] = 'd'; break;
            case 'E': src[i] = 'e'; break;
            case '�': src[i] = '�'; break;
            case 'F': src[i] = 'f'; break;
            case 'G': src[i] = 'g'; break;
            case 'H': src[i] = 'h'; break;
            case 'I': src[i] = 'i'; break;
            case 'J': src[i] = 'j'; break;
            case 'K': src[i] = 'k'; break;
            case 'L': src[i] = 'l'; break;
            case 'M': src[i] = 'm'; break;
            case 'N': src[i] = 'n'; break;
            case '�': src[i] = '�'; break;
            case 'O': src[i] = 'o'; break;
            case '�': src[i] = '�'; break;
            case 'P': src[i] = 'p'; break;
            case 'Q': src[i] = 'q'; break;
            case 'R': src[i] = 'r'; break;
            case 'S': src[i] = 's'; break;
            case '�': src[i] = '�'; break;
            case 'T': src[i] = 't'; break;
            case 'U': src[i] = 'u'; break;
            case 'V': src[i] = 'v'; break;
            case 'W': src[i] = 'w'; break;
            case 'X': src[i] = 'x'; break;
            case 'Y': src[i] = 'y'; break;
            case 'Z': src[i] = 'z'; break;
            case '�': src[i] = '�'; break;
            case '�': src[i] = '�'; break;
            default: break;
        }
    }

    return src;
}

//==================================================================================================

void trim (std::string& str)
{
    std::string::size_type pos = str.find_last_not_of( ' ' );
    if (pos != std::string::npos)
    {
        str.erase( pos + 1 );
        pos = str.find_first_not_of( ' ' );
        if ( pos != std::string::npos )
            str.erase( 0, pos );
    }
    else
        str.erase( str.begin(), str.end() );
}

std::string trimstr (std::string str)
{
    std::string temp = str;
    trim (temp);
    return temp;
}

//==================================================================================================

void DeleteSpecialChars( std::string& src )
{
    for (unsigned int i = 0; i < src.length(); i++)
            if (!(src[i] >= 97 && src[i] <= 122) && // Pomi�dzy a a z
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '?') &&
                !(src[i] == ' '))
            {
                src = src.erase(i, 1);
                i--;
            }
}

void DeleteSpecialChars2 (std::string& src)
{
    for (unsigned int i = 0; i < src.length(); i++)
            if (!(src[i] >= 65 && src[i] <= 90) && // Pomi�dzy A a Z
                !(src[i] >= 97 && src[i] <= 122) && // Pomi�dzy a a z
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '�') &&
                !(src[i] == '?') &&
                !(src[i] == ' '))
            {
                src = src.erase(i, 1);
                i--;
            }

}

void DeleteQuestionMark (std::string &src)
{
    loop:
    for (unsigned int i = 0; i < src.length(); i++)
        if (src[i] == 63)
            src.erase (i, 1);
    for (unsigned int i = 0; i < src.length(); i++)
        if (src[i] == 63)
            goto loop;
}

void DeleteQuestionMark (std::vector<std::string> &src)
{
    for (unsigned int i = 0; i < src.size(); i++)
    {
        trim (src[i]);

        for (unsigned int i2 = 0; i2 < src[i].length(); i2++)
            if (src[i][i2] == 63)
            {
                src[i].erase (i2, 1);
                i2--;
            }
    }
}

//==================================================================================================

std::string DeletePolishChars (std::string src)
{
    for (unsigned int i = 0; i <= src.length(); i++)
    {
        switch (src[i])
        {
            case '�': src[i] = 'a'; break;
            case '�': src[i] = 'c'; break;
            case '�': src[i] = 'e'; break;
            case '�': src[i] = 'l'; break;
            case '�': src[i] = 'n'; break;
            case '�': src[i] = 'o'; break;
            case '�': src[i] = 's'; break;
            case '�': src[i] = 'z'; break;
            case '�': src[i] = 'z'; break;
            default: break;
        }
    }

    return src;
}

//==================================================================================================

