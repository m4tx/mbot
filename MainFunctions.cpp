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
            case '¥': src[i] = '¹'; break;
            case 'B': src[i] = 'b'; break;
            case 'C': src[i] = 'c'; break;
            case 'Æ': src[i] = 'æ'; break;
            case 'D': src[i] = 'd'; break;
            case 'E': src[i] = 'e'; break;
            case 'Ê': src[i] = 'ê'; break;
            case 'F': src[i] = 'f'; break;
            case 'G': src[i] = 'g'; break;
            case 'H': src[i] = 'h'; break;
            case 'I': src[i] = 'i'; break;
            case 'J': src[i] = 'j'; break;
            case 'K': src[i] = 'k'; break;
            case 'L': src[i] = 'l'; break;
            case 'M': src[i] = 'm'; break;
            case 'N': src[i] = 'n'; break;
            case 'Ñ': src[i] = 'ñ'; break;
            case 'O': src[i] = 'o'; break;
            case 'Ó': src[i] = 'ó'; break;
            case 'P': src[i] = 'p'; break;
            case 'Q': src[i] = 'q'; break;
            case 'R': src[i] = 'r'; break;
            case 'S': src[i] = 's'; break;
            case 'Œ': src[i] = 'œ'; break;
            case 'T': src[i] = 't'; break;
            case 'U': src[i] = 'u'; break;
            case 'V': src[i] = 'v'; break;
            case 'W': src[i] = 'w'; break;
            case 'X': src[i] = 'x'; break;
            case 'Y': src[i] = 'y'; break;
            case 'Z': src[i] = 'z'; break;
            case '': src[i] = 'Ÿ'; break;
            case '¯': src[i] = '¿'; break;
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
            if (!(src[i] >= 97 && src[i] <= 122) && // Pomiêdzy a a z
                !(src[i] == '¹') &&
                !(src[i] == 'æ') &&
                !(src[i] == 'ê') &&
                !(src[i] == '³') &&
                !(src[i] == 'ñ') &&
                !(src[i] == 'ó') &&
                !(src[i] == 'œ') &&
                !(src[i] == 'Ÿ') &&
                !(src[i] == '¿') &&
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
            if (!(src[i] >= 65 && src[i] <= 90) && // Pomiêdzy A a Z
                !(src[i] >= 97 && src[i] <= 122) && // Pomiêdzy a a z
                !(src[i] == '¹') &&
                !(src[i] == 'æ') &&
                !(src[i] == 'ê') &&
                !(src[i] == '³') &&
                !(src[i] == 'ñ') &&
                !(src[i] == 'ó') &&
                !(src[i] == 'œ') &&
                !(src[i] == 'Ÿ') &&
                !(src[i] == '¿') &&
                !(src[i] == '¥') &&
                !(src[i] == 'Æ') &&
                !(src[i] == 'Ê') &&
                !(src[i] == '£') &&
                !(src[i] == 'Ñ') &&
                !(src[i] == 'Ó') &&
                !(src[i] == 'Œ') &&
                !(src[i] == '') &&
                !(src[i] == '¯') &&
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
            case '¹': src[i] = 'a'; break;
            case 'æ': src[i] = 'c'; break;
            case 'ê': src[i] = 'e'; break;
            case '³': src[i] = 'l'; break;
            case 'ñ': src[i] = 'n'; break;
            case 'ó': src[i] = 'o'; break;
            case 'œ': src[i] = 's'; break;
            case 'Ÿ': src[i] = 'z'; break;
            case '¿': src[i] = 'z'; break;
            default: break;
        }
    }

    return src;
}

//==================================================================================================

