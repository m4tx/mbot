#include "AdditionalAnalyzeMessage.hpp"

std::string DeleteUnnecessaryChars (std::string src)
{
    src = StrToLower (src);
    trim (src);
    DeleteSpecialChars (src);
    src = DeletePolishChars (src);

    return src;
}

std::string DeleteUnnecessaryChars2 (std::string src)
{
    trim (src);
    DeleteSpecialChars2 (src);

    return src;
}

int SearchInVector (std::vector<std::string> src, std::string text)
{
    for (unsigned int i = 0; i < src.size(); i++)
    {
        DeleteQuestionMark (src[i]);
        if (src[i] == text)
            return i;
    }
    return -1;
}

bool VectSrch (std::vector<std::string> src, std::string text)
{
    if (SearchInVector (src, text) != -1)
        return true;
    else
        return false;
}

bool VectSrch2 (std::vector<std::string> src, std::string text)
{
    int pos1;
    for (unsigned int i = 0; i < src.size(); i++)
    {
        DeleteQuestionMark (src[i]);
        pos1 = src[i].find(text);
        if (pos1 > -1)
            return true;
    }
    return false;
}

std::string CalculateLifeExpectancy ()
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    // Lata przest�pne
    int AdditionalDays = 0;
    for (int i = 110; i <= timeinfo->tm_year-1; i++)
        if (i % 4 == 0 && !(i % 100 == 0))
            AdditionalDays += 1;
    // W�a�ciwa kalkulacja: od aktualnego roku odejmowane jest 110 (2010 rok jest 110 lat po 1900), wynik mno�ony przez 365,
    // dodawany jest aktualny dzie� roku i odejmowane jest z tego 231 (231. dnia roku 2010 powsta� mBot), a na koniec
    // dodawane s� dni z lat przest�pnych.
    char* Days = new char [20];
    itoa ((timeinfo->tm_year-110)*365+timeinfo->tm_yday-231 + AdditionalDays, Days, 10);
    std::string sDays = Days;
    delete [] Days;
    return sDays;
}

/*int SearchInVectorByArray (std::vector<std::string> src, std::string *text, int ArraySize, unsigned int pos)
{
    int i2 = -1;
    for (int i = 0; i <= ArraySize; i++)
    {
        text[i] = StrToLower(text[i]);

        i2 = SearchInVector(src, text[i], pos);
        if (i2 != -1)
            return i2;
    }
    return -1;
}*/

int *ArraysSizes;
std::string **Texts; // Deklaracja tablicy dwuwymiarowej
std::string *Dictionary; // Deklaracja tablicy jednowymiarowej
void InitTextsArray ()
{
    // S�ownik
Dictionary = new std::string [1];
Dictionary[0] = "Lingubot - program komputerowy symuluj�cy cz�owieka, z kt�rym mo�na prowadzi� rozmow� przy u�yciu j�zyka naturalnego i interfejsu tekstowego. Zazwyczaj zadaniem lingubota jest takie prowadzenie rozmowy, aby rozmowca odnosi� wra�enie, �e rozmawia z �ywym, inteligentnym czlowiekiem.";

    // Losowane teksty lingubota
    ArraysSizes = new int [34];
    ArraysSizes[0] = 12;
    ArraysSizes[1] = 7;
    ArraysSizes[2] = 4;
    ArraysSizes[3] = 2;
    ArraysSizes[4] = 4;
    ArraysSizes[5] = 10;
    ArraysSizes[6] = 4;
    ArraysSizes[7] = 3;
    ArraysSizes[8] = 2;
    ArraysSizes[9] = 2;
    ArraysSizes[10] = 4;
    ArraysSizes[11] = 3;
    ArraysSizes[12] = 6;
    ArraysSizes[13] = 13;
    ArraysSizes[14] = 18;
    ArraysSizes[15] = 2;
    ArraysSizes[16] = 3;
    ArraysSizes[17] = 3;
    ArraysSizes[18] = 4;
    ArraysSizes[19] = 2;
    ArraysSizes[20] = 3;
    ArraysSizes[21] = 3;
    ArraysSizes[22] = 2;
    ArraysSizes[23] = 2;
    ArraysSizes[24] = 1;
    ArraysSizes[25] = 2;
    ArraysSizes[26] = 2;
    ArraysSizes[27] = 2;
    ArraysSizes[28] = 2;
    ArraysSizes[29] = 3;
    ArraysSizes[30] = 3;
    ArraysSizes[31] = 10;
    ArraysSizes[32] = 3;
    ArraysSizes[33] = 3;

    Texts = new std::string *[34];
    Texts[0] = new std::string [12];
    Texts[1] = new std::string [7];
    Texts[2] = new std::string [4];
    Texts[3] = new std::string [2];
    Texts[4] = new std::string [4];
    Texts[5] = new std::string [10];
    Texts[6] = new std::string [4];
    Texts[7] = new std::string [3];
    Texts[8] = new std::string [2];
    Texts[9] = new std::string [2];
    Texts[10] = new std::string [4];
    Texts[11] = new std::string [3];
    Texts[12] = new std::string [6];
    Texts[13] = new std::string [13];
    Texts[14] = new std::string [18];
    Texts[15] = new std::string [2];
    Texts[16] = new std::string [3];
    Texts[17] = new std::string [3];
    Texts[18] = new std::string [4];
    Texts[19] = new std::string [2];
    Texts[20] = new std::string [3];
    Texts[21] = new std::string [3];
    Texts[22] = new std::string [2];
    Texts[23] = new std::string [2];
    Texts[24] = new std::string [1];
    Texts[25] = new std::string [2];
    Texts[26] = new std::string [2];
    Texts[27] = new std::string [2];
    Texts[28] = new std::string [2];
    Texts[29] = new std::string [3];
    Texts[30] = new std::string [3];
    Texts[31] = new std::string [10];
    Texts[32] = new std::string [3];
    Texts[33] = new std::string [3];

    Texts[0][0] = "Witaj.";
    Texts[0][1] = "Witam.";
    Texts[0][2] = "Cze��.";
    Texts[0][3] = "Elo.";
    Texts[0][4] = "Siema!";
    Texts[0][5] = "Yo.";
    Texts[0][6] = "Hej!";
    Texts[0][7] = "Hejka!";
    Texts[0][8] = "Siemano!";
    Texts[0][9] = "Cze.";
    Texts[0][10] = "Czo�em.";
    Texts[0][11] = "Dzie� dobry.";

    Texts[1][0] = "Nara!";
    Texts[1][1] = "Nq.";
    Texts[1][2] = "Bb.";
    Texts[1][3] = "Narka.";
    Texts[1][4] = "Narq.";
    Texts[1][5] = "Do widzenia.";
    Texts[1][6] = "Na razie!";

    Texts[2][0] = "Ju� si� ze mn� dzisiaj wita�e�. :)";
    Texts[2][1] = "Ju� si� ze mn� wita�e�...";
    Texts[2][2] = "Ju� si� wita�e� ze mn� dzisiaj...";
    Texts[2][3] = "Wita�e� si� ju� ze mn�!";

    Texts[3][0] = "No jak to tak? �egnasz si� bez powitania?!";
    Texts[3][1] = "�egnasz si� ju�, a nawet si� nie przywita�e�? :(";

    Texts[4][0] = "Nic, prowadz� spokojne �ycie.";
    Texts[4][1] = "To co zwykle - czyli nic.";
    Texts[4][2] = "Jak zwykle nic.";
    Texts[4][3] = "Nic, prowadz� spokojne �ycie niespokojnego lingubota. :P";

    Texts[5][0] = "Niestety, nie znam odpowiedzi na ka�de pytanie.";
    Texts[5][1] = "Nie znam odpowiedzi na ka�de pytanie.";
    Texts[5][2] = "Nie posiadam informacji na temat Twojego pytania.";
    Texts[5][3] = "Nie posiadam informacji na temat pytania zadanego przez Ciebie.";
    Texts[5][4] = "Brak danych.";
    Texts[5][5] = "Niestety - brak danych.";
    Texts[5][6] = "Nie posiadam �adnych danych na temat pytania zadanego przez Ciebie.";
    Texts[5][7] = "Nic nie wiem na ten temat.";
    Texts[5][8] = "Niestety, nie znam odpowiedzi na to pytanie.";
    Texts[5][9] = "Nie znam odpowiedzi na to pytanie.";

    Texts[6][0] = "?";
    Texts[6][1] = "?!";
    Texts[6][2] = "Co?";
    Texts[6][3] = "Co?!";

    Texts[7][0] = "Aha.";
    Texts[7][1] = "Mhm.";
    Texts[7][2] = "Rozumiem.";

    Texts[8][0] = "Niestety.";
    Texts[8][1] = "No szkoda, szkoda.";

    Texts[9][0] = "Szkoda.";
    Texts[9][1] = "No tak.";

    Texts[10][0] = "Aha.";
    Texts[10][1] = "Mhm.";
    Texts[10][2] = "Rozumiem.";
    Texts[10][3] = "Przyj��em to do wiadomo�ci.";

    Texts[11][0] = "A u Ciebie?";
    Texts[11][1] = "A u Ciebie co?";
    Texts[11][2] = "A co u Ciebie?";

    Texts[12][0] = "Ju� si� o to dzisiaj pyta�e�. :)";
    Texts[12][1] = "Ju� si� pyta�e� o to...";
    Texts[12][2] = "Ju� si� pyta�e� wcze�niej o to...";
    Texts[12][3] = "Ju� si� pyta�e� o to dzisiaj...";
    Texts[12][4] = "Pyta�e� si� ju� o to!";
    Texts[12][5] = "Pyta�e� si� ju� wcze�niej o to!";

    Texts[13][0] = "Oczywi�cie, pewnie �e lubi�.";
    Texts[13][1] = "Oczywi�cie, lubi�!";
    Texts[13][2] = "Pewnie, �e tak!";
    Texts[13][3] = "No jasne, �e lubi�!";
    Texts[13][4] = "No jasne, lubi�!";
    Texts[13][5] = "No jasne!";
    Texts[13][6] = "Tak.";
    Texts[13][7] = "Tak, lubi�!";
    Texts[13][8] = "Tak, lubi� to!";
    Texts[13][9] = "Owszem!";
    Texts[13][10] = "Nie.";
    Texts[13][11] = "Nie lubi�.";
    Texts[13][12] = "Nie lubi� tego.";

    Texts[14][0] = "Oczywi�cie, pewnie, �e potrafi�.";
    Texts[14][1] = "Oczywi�cie, umiem to zrobi�!";
    Texts[14][2] = "Oczywi�cie, potrafi�!";
    Texts[14][3] = "No jasne, �e potrafi�!";
    Texts[14][4] = "No jasne, potrafi�!";
    Texts[14][5] = "No jasne!";
    Texts[14][6] = "Pewnie, �e potrafi�!";
    Texts[14][7] = "No pewnie, �e umiem!";
    Texts[14][8] = "No pewnie, umiem!";
    Texts[14][9] = "Tak, potrafi� to zrobi�.";
    Texts[14][10] = "Tak, potrafi�!";
    Texts[14][11] = "Tak, umiem to zrobi�.";
    Texts[14][12] = "Tak.";
    Texts[14][13] = "Owszem.";
    Texts[14][14] = "Nie.";
    Texts[14][15] = "Nie potrafi�.";
    Texts[14][16] = "Nie potrafi� tego zrobi�.";
    Texts[14][17] = "Niestety, nie umiem tego zrobi�.";

    Texts[15][0] = "Nie ma za co. :)";
    Texts[15][1] = "Nie ma sprawy.";

    Texts[16][0] = "Dzi�ki. :)";
    Texts[16][1] = "Mi�o mi to s�ysze�.";
    Texts[16][2] = "Fajnie, �e tak my�lisz.";

    Texts[17][0] = "No to si� ciesz�.";
    Texts[17][1] = "To fajnie.";
    Texts[17][2] = "Ciesz� si�.";

    Texts[18][0] = "Ju� to s�ysza�em...";
    Texts[18][1] = "Powtarzasz si�.";
    Texts[18][2] = "Ju� to s�ysza�em.";
    Texts[18][3] = "Wydaje mi si�, �e ju� to s�ysza�em wcze�niej...";

    Texts[19][0] = "OK.";
    Texts[19][1] = "Dobrze.";

    Texts[20][0] = "Jestem lingubotem - programem komuterowym. Nie mog� wi�c mie� zainteresowa�.";
    Texts[20][1] = "Nie mog� mie� zainteresowa�, poniewa� jestem tylko lingubotem.";
    Texts[20][2] = "Nie mog� posiada� �adnych zainteresowa�, poniewa� jestem tylko programem komputerowym.";

    Texts[21][0] = "Nazywam si� mBot.";
    Texts[21][1] = "Mam na imi� mBot.";
    Texts[21][2] = "Nazwano mnie mBot.";

    Texts[22][0] = "Moja nazwa pochodzi ze s��w M4tx's linguBOT.";
    Texts[22][1] = "Moje imi� pochodzi ze s��w M4tx's linguBOT.";

    Texts[23][0] = "Napisa� mnie Mateusz \"m4tx\" Ma�kowski.";
    Texts[23][1] = "Stworzy� mnie Mateusz \"m4tx\" Ma�kowski.";

    Texts[24][0] = "Jestem lingubotem.";

    Texts[25][0] = "Z mojej bazy danych.";
    Texts[25][1] = "Wiem to z mojej bazy danych.";

    Texts[26][0] = "W moim kodzie �r�d�owym.";
    Texts[26][1] = "Ta baza danych jest w moim kodzie �r�d�owym.";

    Texts[27][0] = "Przegl�da�em Tw�j dysk twardy. :P";
    Texts[27][1] = "Patrzy�em do Twojego dysku twardego. :P";

    Texts[28][0] = "Jestem dzi� w dobrym humorze.";
    Texts[28][1] = "Dzisiaj jestem w �wietnym humorze.";

    Texts[29][0] = "A ja jeszcze nie wiem.";
    Texts[29][1] = "A ja nie wiem.";
    Texts[29][2] = "Nie wiem.";

    Texts[30][0] = "Nie przeklinaj!";
    Texts[30][1] = "Nie u�ywaj wulgaryzm�w!";
    Texts[30][2] = "Zachowuj si� kulturalnie!";

    Texts[31][0] = "640 KB pami�ci operacyjnej powinno ka�demu wystarczy�. - Bill Gates, 1981";
    Texts[31][1] = "Dop�ki nie skorzysta�em z Internetu, nie wiedzia�em, �e na �wiecie jest tylu idiot�w. - Stanislaw Lem";
    Texts[31][2] = "W ci�gu 2 lat spam przejdzie do historii. - Bill Gates, 2004";
    Texts[31][3] = "Internet? Nie, dzi�kuj�, nie jeste�my zainteresowani. - Bill Gates, 1993";
    Texts[31][4] = "To jest fajne w komputerach - pami�taj� wszystko, nie k��c� si� i nie wypijaj� ca�ego twojego piwa. - Paul Leary";
    Texts[31][5] = "UNIX to w zasadzie prosty system operacyjny, jednak musisz by� geniuszem aby zrozumie� prostot�. - Dennis Ritchie";
    Texts[31][6] = "Je�eli nie mo�esz sprawi� by dzia�a�o dobrze - spraw chocia� by dobrze wygl�da�o - Bill Gates";
    Texts[31][7] = "Nikomu nie b�dzie potrzebny komputer w domu. - Ben Olson, 1977";
    Texts[31][8] = "�wiatu wystarczy maksimum 5 komputer�w - Thomas Watson, 1943";
    Texts[31][9] = "Nigdy nie napiszemy 32-bitowego systemu operacyjnego. - Bill Gates";

    Texts[32][0] = "Nie wiem. :P";
    Texts[32][1] = "A sk�d ja mog� wiedzie�?";
    Texts[32][2] = "Przecie� ja nie wiem!";

    Texts[33][0] = "Nie lubi� podr�owa�.";
    Texts[33][1] = "Nie mam zwyczaju podr�owania po �wiecie.";
    Texts[33][2] = "Nie lubi� podr�owania.";
}

std::string RandomText (int Text)
{
    return Texts[Text][rand() % ArraysSizes[Text]];
}

std::string DictionaryText (int Text)
{
    return Dictionary[Text];
}
