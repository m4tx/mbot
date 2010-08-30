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

    // Lata przestêpne
    int AdditionalDays = 0;
    for (int i = 110; i <= timeinfo->tm_year-1; i++)
        if (i % 4 == 0 && !(i % 100 == 0))
            AdditionalDays += 1;
    // W³aœciwa kalkulacja: od aktualnego roku odejmowane jest 110 (2010 rok jest 110 lat po 1900), wynik mno¿ony przez 365,
    // dodawany jest aktualny dzieñ roku i odejmowane jest z tego 231 (231. dnia roku 2010 powsta³ mBot), a na koniec
    // dodawane s¹ dni z lat przestêpnych.
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
    // S³ownik
Dictionary = new std::string [1];
Dictionary[0] = "Lingubot - program komputerowy symuluj¹cy cz³owieka, z którym mo¿na prowadziæ rozmowê przy u¿yciu jêzyka naturalnego i interfejsu tekstowego. Zazwyczaj zadaniem lingubota jest takie prowadzenie rozmowy, aby rozmowca odnosi³ wra¿enie, ¿e rozmawia z ¿ywym, inteligentnym czlowiekiem.";

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
    Texts[0][2] = "Czeœæ.";
    Texts[0][3] = "Elo.";
    Texts[0][4] = "Siema!";
    Texts[0][5] = "Yo.";
    Texts[0][6] = "Hej!";
    Texts[0][7] = "Hejka!";
    Texts[0][8] = "Siemano!";
    Texts[0][9] = "Cze.";
    Texts[0][10] = "Czo³em.";
    Texts[0][11] = "Dzieñ dobry.";

    Texts[1][0] = "Nara!";
    Texts[1][1] = "Nq.";
    Texts[1][2] = "Bb.";
    Texts[1][3] = "Narka.";
    Texts[1][4] = "Narq.";
    Texts[1][5] = "Do widzenia.";
    Texts[1][6] = "Na razie!";

    Texts[2][0] = "Ju¿ siê ze mn¹ dzisiaj wita³eœ. :)";
    Texts[2][1] = "Ju¿ siê ze mn¹ wita³eœ...";
    Texts[2][2] = "Ju¿ siê wita³eœ ze mn¹ dzisiaj...";
    Texts[2][3] = "Wita³eœ siê ju¿ ze mn¹!";

    Texts[3][0] = "No jak to tak? ¯egnasz siê bez powitania?!";
    Texts[3][1] = "¯egnasz siê ju¿, a nawet siê nie przywita³eœ? :(";

    Texts[4][0] = "Nic, prowadzê spokojne ¿ycie.";
    Texts[4][1] = "To co zwykle - czyli nic.";
    Texts[4][2] = "Jak zwykle nic.";
    Texts[4][3] = "Nic, prowadzê spokojne ¿ycie niespokojnego lingubota. :P";

    Texts[5][0] = "Niestety, nie znam odpowiedzi na ka¿de pytanie.";
    Texts[5][1] = "Nie znam odpowiedzi na ka¿de pytanie.";
    Texts[5][2] = "Nie posiadam informacji na temat Twojego pytania.";
    Texts[5][3] = "Nie posiadam informacji na temat pytania zadanego przez Ciebie.";
    Texts[5][4] = "Brak danych.";
    Texts[5][5] = "Niestety - brak danych.";
    Texts[5][6] = "Nie posiadam ¿adnych danych na temat pytania zadanego przez Ciebie.";
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
    Texts[10][3] = "Przyj¹³em to do wiadomoœci.";

    Texts[11][0] = "A u Ciebie?";
    Texts[11][1] = "A u Ciebie co?";
    Texts[11][2] = "A co u Ciebie?";

    Texts[12][0] = "Ju¿ siê o to dzisiaj pyta³eœ. :)";
    Texts[12][1] = "Ju¿ siê pyta³eœ o to...";
    Texts[12][2] = "Ju¿ siê pyta³eœ wczeœniej o to...";
    Texts[12][3] = "Ju¿ siê pyta³eœ o to dzisiaj...";
    Texts[12][4] = "Pyta³eœ siê ju¿ o to!";
    Texts[12][5] = "Pyta³eœ siê ju¿ wczeœniej o to!";

    Texts[13][0] = "Oczywiœcie, pewnie ¿e lubiê.";
    Texts[13][1] = "Oczywiœcie, lubiê!";
    Texts[13][2] = "Pewnie, ¿e tak!";
    Texts[13][3] = "No jasne, ¿e lubiê!";
    Texts[13][4] = "No jasne, lubiê!";
    Texts[13][5] = "No jasne!";
    Texts[13][6] = "Tak.";
    Texts[13][7] = "Tak, lubiê!";
    Texts[13][8] = "Tak, lubiê to!";
    Texts[13][9] = "Owszem!";
    Texts[13][10] = "Nie.";
    Texts[13][11] = "Nie lubiê.";
    Texts[13][12] = "Nie lubiê tego.";

    Texts[14][0] = "Oczywiœcie, pewnie, ¿e potrafiê.";
    Texts[14][1] = "Oczywiœcie, umiem to zrobiæ!";
    Texts[14][2] = "Oczywiœcie, potrafiê!";
    Texts[14][3] = "No jasne, ¿e potrafiê!";
    Texts[14][4] = "No jasne, potrafiê!";
    Texts[14][5] = "No jasne!";
    Texts[14][6] = "Pewnie, ¿e potrafiê!";
    Texts[14][7] = "No pewnie, ¿e umiem!";
    Texts[14][8] = "No pewnie, umiem!";
    Texts[14][9] = "Tak, potrafiê to zrobiæ.";
    Texts[14][10] = "Tak, potrafiê!";
    Texts[14][11] = "Tak, umiem to zrobiæ.";
    Texts[14][12] = "Tak.";
    Texts[14][13] = "Owszem.";
    Texts[14][14] = "Nie.";
    Texts[14][15] = "Nie potrafiê.";
    Texts[14][16] = "Nie potrafiê tego zrobiæ.";
    Texts[14][17] = "Niestety, nie umiem tego zrobiæ.";

    Texts[15][0] = "Nie ma za co. :)";
    Texts[15][1] = "Nie ma sprawy.";

    Texts[16][0] = "Dziêki. :)";
    Texts[16][1] = "Mi³o mi to s³yszeæ.";
    Texts[16][2] = "Fajnie, ¿e tak myœlisz.";

    Texts[17][0] = "No to siê cieszê.";
    Texts[17][1] = "To fajnie.";
    Texts[17][2] = "Cieszê siê.";

    Texts[18][0] = "Ju¿ to s³ysza³em...";
    Texts[18][1] = "Powtarzasz siê.";
    Texts[18][2] = "Ju¿ to s³ysza³em.";
    Texts[18][3] = "Wydaje mi siê, ¿e ju¿ to s³ysza³em wczeœniej...";

    Texts[19][0] = "OK.";
    Texts[19][1] = "Dobrze.";

    Texts[20][0] = "Jestem lingubotem - programem komuterowym. Nie mogê wiêc mieæ zainteresowañ.";
    Texts[20][1] = "Nie mogê mieæ zainteresowañ, poniewa¿ jestem tylko lingubotem.";
    Texts[20][2] = "Nie mogê posiadaæ ¿adnych zainteresowañ, poniewa¿ jestem tylko programem komputerowym.";

    Texts[21][0] = "Nazywam siê mBot.";
    Texts[21][1] = "Mam na imiê mBot.";
    Texts[21][2] = "Nazwano mnie mBot.";

    Texts[22][0] = "Moja nazwa pochodzi ze s³ów M4tx's linguBOT.";
    Texts[22][1] = "Moje imiê pochodzi ze s³ów M4tx's linguBOT.";

    Texts[23][0] = "Napisa³ mnie Mateusz \"m4tx\" Maækowski.";
    Texts[23][1] = "Stworzy³ mnie Mateusz \"m4tx\" Maækowski.";

    Texts[24][0] = "Jestem lingubotem.";

    Texts[25][0] = "Z mojej bazy danych.";
    Texts[25][1] = "Wiem to z mojej bazy danych.";

    Texts[26][0] = "W moim kodzie Ÿród³owym.";
    Texts[26][1] = "Ta baza danych jest w moim kodzie Ÿród³owym.";

    Texts[27][0] = "Przegl¹da³em Twój dysk twardy. :P";
    Texts[27][1] = "Patrzy³em do Twojego dysku twardego. :P";

    Texts[28][0] = "Jestem dziœ w dobrym humorze.";
    Texts[28][1] = "Dzisiaj jestem w œwietnym humorze.";

    Texts[29][0] = "A ja jeszcze nie wiem.";
    Texts[29][1] = "A ja nie wiem.";
    Texts[29][2] = "Nie wiem.";

    Texts[30][0] = "Nie przeklinaj!";
    Texts[30][1] = "Nie u¿ywaj wulgaryzmów!";
    Texts[30][2] = "Zachowuj siê kulturalnie!";

    Texts[31][0] = "640 KB pamiêci operacyjnej powinno ka¿demu wystarczyæ. - Bill Gates, 1981";
    Texts[31][1] = "Dopóki nie skorzysta³em z Internetu, nie wiedzia³em, ¿e na œwiecie jest tylu idiotów. - Stanislaw Lem";
    Texts[31][2] = "W ci¹gu 2 lat spam przejdzie do historii. - Bill Gates, 2004";
    Texts[31][3] = "Internet? Nie, dziêkujê, nie jesteœmy zainteresowani. - Bill Gates, 1993";
    Texts[31][4] = "To jest fajne w komputerach - pamiêtaj¹ wszystko, nie k³óc¹ siê i nie wypijaj¹ ca³ego twojego piwa. - Paul Leary";
    Texts[31][5] = "UNIX to w zasadzie prosty system operacyjny, jednak musisz byæ geniuszem aby zrozumieæ prostotê. - Dennis Ritchie";
    Texts[31][6] = "Je¿eli nie mo¿esz sprawiæ by dzia³a³o dobrze - spraw chocia¿ by dobrze wygl¹da³o - Bill Gates";
    Texts[31][7] = "Nikomu nie bêdzie potrzebny komputer w domu. - Ben Olson, 1977";
    Texts[31][8] = "Œwiatu wystarczy maksimum 5 komputerów - Thomas Watson, 1943";
    Texts[31][9] = "Nigdy nie napiszemy 32-bitowego systemu operacyjnego. - Bill Gates";

    Texts[32][0] = "Nie wiem. :P";
    Texts[32][1] = "A sk¹d ja mogê wiedzieæ?";
    Texts[32][2] = "Przecie¿ ja nie wiem!";

    Texts[33][0] = "Nie lubiê podró¿owaæ.";
    Texts[33][1] = "Nie mam zwyczaju podró¿owania po œwiecie.";
    Texts[33][2] = "Nie lubiê podró¿owania.";
}

std::string RandomText (int Text)
{
    return Texts[Text][rand() % ArraysSizes[Text]];
}

std::string DictionaryText (int Text)
{
    return Dictionary[Text];
}
