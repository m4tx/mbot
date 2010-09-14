#include "AnalyzeMessage.hpp"

std::vector<std::string> Words2;
std::vector<std::string> Words;
std::vector<std::string> PreviousWords;

int TwondQuestionIteration = 0; // Zmienna pomocnicza. Po przypisaniu do niej wartoœci 2 zmienna IsQuestion jest przestawiana na false.
int TwondBotQuestionIteration = 0; // Zmienna pomocnicza. Po przypisaniu do niej wartoœci 3 zmienna BotQuestion jest przestawiana na 0.

bool IsWelcome = false; // Czy u¿ytkownik siê ju¿ przywita³.
bool IsWassUp = false; // Czy bot siê ju¿ pyta³ "Co u Ciebie?"
bool IsUserWassUp = false; // Czy u¿ytkownik siê ju¿ pyta³ "Co u Ciebie?"

bool IsQuestion = false; // Czy bot siê zapyta³ o coœ.
bool IsInterrogativeSentence = false; // Zdanie pytaj¹ce

std::string AnalyzeAndYou (std::vector<std::string> Words);

// Zmienna przechowuj¹ca aktualn¹ wypowiedŸ, które zada³ bot. Zmienna jest u¿ywana do odpowiadania na pytanie "A Ty?", choæ nie tylko.
// 0 - pytanie niestandardowe lub brak pytania.; 1 - zarezerwowane.; 2 - Co u Ciebie?; 3 - Przegl¹da³em Twój dysk twardy;
short int BotQuestion = 0;

std::string AnalyzeMessage (std::string src)
{
    // Usuniêcie zawartoœci vectorów z wypowiedziami u¿ytkownika.
    Words.clear();
    Words2.clear();

    // Przypisanie zmiennej IsQuestion wartoœci false, jêzeli tak ma byæ.
    if (IsQuestion)
    {
        TwondQuestionIteration += 1;
        if (TwondQuestionIteration == 2)
            IsQuestion = false;
    }

    // Przypisanie zmiennej BotQuestion wartoœci false, jêzeli tak ma byæ.
    if (BotQuestion)
    {
        TwondBotQuestionIteration += 1;
        if (TwondBotQuestionIteration == 3)
            BotQuestion = false;
    }

    // Usuniêcie z wypowiedzi u¿ytkownika niepotrzebnych znaków.
    std::string src2 = DeleteUnnecessaryChars2 (src);

    // Przerobienie wypowiedzi u¿ytkownika w std::string na std::vector.
    unsigned int previous_i = 0;
    for (unsigned int i = 0; i <= src2.length(); i++)
    {
        if (src2[i] == ' ')
        {
            Words2.push_back (src2.substr(previous_i, i-previous_i));
            previous_i = i + 1;
        }
        if (i == src2.length())
        {
            Words2.push_back (src2.substr(previous_i, i-previous_i));
            previous_i = i + 1;
        }
    }

    // Usuniêcie z wypowiedzi u¿ytkownika niepotrzebnych znaków.
    src = DeleteUnnecessaryChars (src);
    if (src[0] == '\0')
        return "";

    // Przerobienie wypowiedzi u¿ytkownika w std::string na std::vector.
    previous_i = 0;
    for (unsigned int i = 0; i <= src.length(); i++)
    {
        if (src[i] == ' ')
        {
            Words.push_back (src.substr(previous_i, i-previous_i));
            previous_i = i + 1;
        }
        if (i == src.length())
        {
            Words.push_back (src.substr(previous_i, i-previous_i));
            previous_i = i + 1;
        }
    }

    if ((!VectSrch2(Words, "dowcip") && VectSrch2(Words, "cip")) ||
        VectSrch2(Words, "kurw") || VectSrch2(Words, "huj") || VectSrch2(Words, "pizd") || VectSrch2(Words, "pind") ||
        VectSrch2(Words, "pierdo") || VectSrch2(Words, "pierdzie") || VectSrch2(Words, "jeb") || VectSrch2(Words, "rucha") ||
        VectSrch2(Words, "fiut") || VectSrch2(Words, "dup") || VectSrch2(Words, "pieprzy") || VectSrch2(Words, "pieprzen") ||
        VectSrch2(Words, "zarabis")  || VectSrch2(Words, "sukinsyn"))
        return RandomText(30);

    // Sprawdzenie, czy zdanie jest pytaniem.
    if (src[src.length()-1] == '?' || Words[0] == "czy")
        IsInterrogativeSentence = true;
    else
        IsInterrogativeSentence = false;
    DeleteQuestionMark(Words);

    // Sprawdzenie, czy u¿ytkownik siê nie powtarza.
    if (PreviousWords.size() == Words.size())
    {
        bool IsRepetition = false;
        for (unsigned int i = 0; i < PreviousWords.size(); i++)
            //if (VectSrch(Words, PreviousWords[i]))
            if (PreviousWords[i] == Words[i])
                IsRepetition = true;
            else
            {
                IsRepetition = false;
                goto IsRep;
            }
        IsRep: if (IsRepetition)
            return RandomText(18);
    }

    if (VectSrch(Words, "a") && (VectSrch(Words, "ty") || VectSrch(Words, "ciebie")))
    {
        if (Words.size() == 2)
        {
            DeleteQuestionMark(PreviousWords);
            return AnalyzeAndYou (PreviousWords);
        }
        else
        {

            return AnalyzeAndYou (Words);
        }
    }

    // Oczyszczenie zmiennej przechowuj¹cej poprzedni¹ wypowiedŸ u¿ytkownika i przypisanie
    // do niej zawartoœci zmiennej, która przechowuje aktualn¹ wypowiedŸ.
    PreviousWords.clear();
    for (unsigned int i = 0; i < Words.size(); i++)
        PreviousWords.push_back (Words[i]);

    // W³aœciwa analiza wiadomoœci.
    if (VectSrch(Words, "witaj") || VectSrch(Words, "czesc") || VectSrch(Words, "elo") ||
             VectSrch(Words, "siema") || VectSrch(Words, "yo") || VectSrch(Words, "hej") ||
             VectSrch(Words, "hejka") || VectSrch(Words, "siemano") || VectSrch(Words, "cze") ||
             VectSrch(Words, "czolem") || VectSrch(Words, "witam") || VectSrch(Words, "jol") ||
             (VectSrch(Words, "dzien") && VectSrch(Words, "dobry")))
    {
        if (!IsWelcome)
        {
            IsWelcome = true;
            if (rand() % 3 == 0)
                return RandomText(0);
            else
            {
                IsQuestion = true;
                IsWassUp = true;
                BotQuestion = 2;
                return RandomText(0) + "\nCo u Ciebie?";
            }
        }
        else
            return RandomText(2);
    }
    else if (VectSrch(Words, "nara") || VectSrch(Words, "nq") || VectSrch(Words, "bb") ||
             VectSrch(Words, "narka") || VectSrch(Words, "narq") || (Words.size() > 1 && ((VectSrch(Words, "do") &&
             VectSrch(Words, "widzenia")) || (VectSrch(Words, "na") && VectSrch(Words, "razie")))))
                if (IsWelcome)
                    return RandomText(1);
                else
                    return RandomText(3);
    else if (VectSrch(Words, "co") && (VectSrch(Words, "ciebie") || VectSrch(Words, "cb") ||
             VectSrch(Words, "slychac")))
            if (!IsUserWassUp)
            {
                IsUserWassUp = true;
                if (rand() % 3 == 0)
                    return RandomText(4);
                else
                {
                    if (!IsWassUp)
                    {
                        IsQuestion = true;
                        IsWassUp = true;
                        BotQuestion = 2;
                        return RandomText(4) + "\n" + RandomText(11);
                    }
                    else
                        return RandomText(4);
                }
            }
            else
                return RandomText (12);
    else if (((VectSrch(Words, "piekna") || VectSrch(Words, "ladna") || VectSrch(Words, "fajna") || VectSrch(Words, "super")) &&
             VectSrch(Words, "pogoda")) || (VectSrch(Words, "slonce") && VectSrch(Words, "swieci")))
        return RandomText(42);
    else if (((VectSrch(Words, "brzydka") || VectSrch(Words, "lipna") || VectSrch(Words, "beznadziejna") || VectSrch(Words, "straszna")) &&
             VectSrch(Words, "pogoda")) || ((VectSrch(Words, "ciemne") || VectSrch(Words, "czarne") || VectSrch(Words, "granatowe")) &&
             VectSrch(Words, "chmury")))
        return RandomText(43);
    else if ((VectSrch(Words, "mam") && (VectSrch(Words, "pytan") || VectSrch(Words, "pytanie") || VectSrch(Words, "pytania"))) ||
             ((VectSrch(Words, "odpowiedzial") || VectSrch(Words, "odpowiedziec") || VectSrch(Words, "odpowiedz")) &&
              (VectSrch(Words, "pytan") || VectSrch(Words, "pytanie") || VectSrch(Words, "pytania"))))
        return RandomText(19);
    else if ((VectSrch(Words, "jakie") && VectSrch(Words, "masz") && VectSrch(Words, "zainteresowania")) ||
             (VectSrch(Words, "czym") && VectSrch(Words, "sie") && VectSrch(Words, "interesujesz")))
        return RandomText(20);
    else if ((VectSrch(Words, "jak") && ((VectSrch(Words, "sie") && VectSrch(Words, "nazywasz")) ||
             (VectSrch(Words, "masz") && VectSrch(Words, "na") && VectSrch(Words, "imie")))) ||
             ((VectSrch(Words, "jakie") || VectSrch(Words, "jakies")) &&
             VectSrch(Words, "masz") && SearchInVector(Words, "na") != SearchInVector(Words, "masz")+1 &&
             (VectSrch(Words, "imie") || VectSrch(Words, "imienia"))))
        return RandomText(21);
    else if ((VectSrch(Words, "dlaczego") || VectSrch(Words, "czemu")) && (VectSrch(Words, "nazywasz") || VectSrch(Words, "tak") || VectSrch(Words, "masz") ||
             VectSrch(Words, "nazwano")) && (VectSrch(Words, "cie") || VectSrch(Words, "nazwano") || VectSrch(Words, "na") || VectSrch(Words, "sie")) &&
             (VectSrch(Words, "imie") || VectSrch(Words, "mbot") || VectSrch(Words, "nazywasz") || VectSrch(Words, "nazwano")))
        return RandomText(22);
    else if (VectSrch(Words, "co") && (VectSrch(Words, "robisz") || VectSrch(Words, "robiles")))
    {
        BotQuestion = 3;
        return RandomText(27);
    }
    else if (VectSrch(Words, "co") && (VectSrch(Words, "zobaczyles") || VectSrch(Words, "widziales")) && BotQuestion == 3)
        return RandomText(37);
    else if ((VectSrch(Words, "jestem") && VectSrch(Words, "w") && (VectSrch(Words, "wysmienitym") ||  VectSrch(Words, "swietnym") ||
             VectSrch(Words, "dobrym") || VectSrch(Words, "wspanialym")) && VectSrch(Words, "humorze")) ||
             ((VectSrch(Words, "mam") || VectSrch(Words, "miewam")) && (VectSrch(Words, "wysmienity") || VectSrch(Words, "swietny") ||
             VectSrch(Words, "dobry")) && VectSrch(Words, "humor")))
        return RandomText(17);
    else if (VectSrch(Words, "lubisz"))
        return RandomText(13);
    else if (VectSrch(Words, "umiesz") || VectSrch(Words, "potrafisz"))
        return RandomText(14);
    else if (VectSrch(Words, "kto") && VectSrch(Words, "cie") &&
             (VectSrch(Words, "stworzyl") || VectSrch(Words, "napisal")))
        return RandomText(23);
    else if ((VectSrch(Words, "kim") || VectSrch(Words, "czym")) && VectSrch(Words, "jestes"))
        return RandomText(24);
    else if (VectSrch(Words, "znasz"))
        return RandomText(40);
    else if (VectSrch(Words, "mbot") && VectSrch(Words, "to") && (VectSrch(Words, "imie") || VectSrch(Words, "nazwisko")))
        return RandomText(41);
    else if ((VectSrch(Words, "co") || VectSrch(Words, "czym") || VectSrch(Words, "kim")) &&
             (VectSrch(Words, "jest") || VectSrch(Words, "to") || VectSrch(Words, "znaczy")))
    {
        if (VectSrch(Words, "lingubot"))
            return DictionaryText(0);
        else
            return RandomText(32);
    }
    else if (VectSrch(Words, "skad") && VectSrch(Words, "wiesz"))
        return RandomText(25);
    else if (VectSrch(Words, "gdzie") && VectSrch(Words, "masz") && VectSrch(Words, "baze"))
        return RandomText(26);
    else if (VectSrch(Words, "jestes"))
    {
        if (VectSrch(Words, "fajny") || VectSrch(Words, "smieszny") || VectSrch(Words, "fajoski") ||
            VectSrch(Words, "fajorski") || VectSrch(Words, "fajnym") || VectSrch(Words, "smiesznym") ||
            VectSrch(Words, "fajoskim") || VectSrch(Words, "fajorskim"))
            return RandomText(16);
        else
        {
            std::string dst = "";
            int Pos = VectSrch (Words, "jestes");

            Words2.erase (Words2.begin() + Pos);

            for (unsigned int i = 0; i < Words2.size(); i++)
                dst += " " + Words2[i];

            if (dst[0] != '\0')
                return std::string("Dlaczego uwa¿asz, ¿e jestem") + dst + std::string("?");
            else
                return RandomText(6);
        }
    }
    else if (VectSrch(Words, "umiesz") || VectSrch(Words, "potrafisz") ||
             VectSrch(Words, "umialbys") || VectSrch(Words, "potrafilbys"))
        return RandomText(14);
    else if (VectSrch(Words, "palisz"))
        return RandomText(34);
    else if (VectSrch(Words, "pijesz"))
        return RandomText(35);
    else if (VectSrch(Words, "cpasz"))
        return RandomText(36);
    else if (((VectSrch(Words, "byles") || VectSrch(Words, "przebywales") || VectSrch(Words, "bywales")) &&
              VectSrch(Words, "w")) || ((VectSrch(Words, "wyjezdzales") || VectSrch(Words, "jezdziles")) &&
              VectSrch(Words, "do")) || ((VectSrch(Words, "czys") || VectSrch(Words, "czy")) &&
              VectSrch(Words, "byl") && VectSrch(Words, "w")))
        return RandomText(33);
    else if (VectSrch(Words, "masz") && VectSrch(Words, "cos") && VectSrch(Words, "wspolnego"))
        return RandomText(38);
    else if (VectSrch(Words, "szkoda"))
        return RandomText(8);
    else if (VectSrch(Words, "niestety"))
        return RandomText(9);
    else if (VectSrch(Words, "dzieki"))
        return RandomText(15);
    else if (VectSrch(Words, "rozumiem") || VectSrch(Words, "aha") || VectSrch(Words, "mhm") ||
             (Words.size() > 1 && ((VectSrch(Words, "takie") && VectSrch(Words, "buty")))))
        return "";
    else if ((VectSrch(Words, "zapodaj") || VectSrch(Words, "daj") || VectSrch(Words, "opowiedz") || VectSrch(Words, "napisz")) &&
             (VectSrch(Words, "cytat") || VectSrch(Words, "cytata") || VectSrch(Words, "cytatka")))
        return RandomText(31);
    else if (((VectSrch(Words, "jak") && VectSrch(Words, "dlugo")) || VectSrch(Words, "ile") || VectSrch(Words, "dlugo")) &&
              (VectSrch(Words, "zyjesz") || VectSrch(Words, "istniejesz")))
        return "Moje pierwsze uruchomienie nast¹pi³o 20 sierpnia 2010 roku, co oznacza, ¿e istniejê ju¿ " + CalculateLifeExpectancy() + " dni.";
    else if (IsQuestion)
        return RandomText(7);
    else if (VectSrch(Words, "nic") || VectSrch(Words, "hm") || VectSrch(Words, "hmm") || VectSrch(Words, "hmmm") ||
             VectSrch(Words, "xp") || VectSrch(Words, "xd") || (VectSrch(Words, "a") && VectSrch(Words, "ten")) ||
             (VectSrch(Words, "ciesze") && VectSrch(Words, "sie")))
        return "";
    else if (VectSrch2AtEnd(Words, "sz"))
    {
        for (unsigned int i = 0; i < Words.size(); i++)
            if (Words[i] == "czy" || Words[i] == "ty" || Words[i] == "mi" || Words[i] == "to")
            {
                Words.erase (Words.begin() + i);
                i--;
            }

        if (Words.size() < 3 && Words.size() > 0)
            return "Nie.";
        else if (IsInterrogativeSentence)
            return RandomText(5);
        else
            return "";
    }
    else if (IsInterrogativeSentence)
        return RandomText(5);
    else if (!IsInterrogativeSentence)
        return RandomText(10);
    else
        return RandomText(6);
}

std::string AnalyzeAndYou (std::vector<std::string> Words)
{
    if (VectSrch(Words, "nazywam") && VectSrch(Words, "sie"))
        return RandomText(21);
    else if (VectSrch(Words, "interesuje") && VectSrch(Words, "sie"))
        return RandomText(20);
    else if ((VectSrch(Words, "nazywam") || VectSrch(Words, "sie")) || (VectSrch(Words, "mam") && VectSrch(Words, "imie")))
        return RandomText(21);
    else if (((VectSrch(Words, "nazywam") || VectSrch(Words, "sie")) || (VectSrch(Words, "mam") && VectSrch(Words, "imie"))) &&
             (VectSrch(Words, "bo") || VectSrch(Words, "poniewaz") || VectSrch(Words, "gdyz") || VectSrch(Words, "iz")))
        return RandomText(22);
    else if ((VectSrch(Words, "nazywam") || VectSrch(Words, "mam")) && (VectSrch(Words, "sie") || VectSrch(Words, "imie")) &&
        (VectSrch(Words, "poniewaz") || VectSrch(Words, "bo")))
        return RandomText(22);
    else if (VectSrch(Words, "robie") && VectSrch(Words, "robilem"))
        return RandomText(27);
    else if ((VectSrch(Words, "jestem") || VectSrch(Words, "mam") || VectSrch(Words, "miewam")) && (VectSrch(Words, "wysmienity") || VectSrch(Words, "wysmienitym") ||
        VectSrch(Words, "swietny") || VectSrch(Words, "swietnym") || VectSrch(Words, "dobry") || VectSrch(Words, "dobrym")) &&
        (VectSrch(Words, "humor") || VectSrch(Words, "humorze")))
        return RandomText(28);
    else if (VectSrch(Words, "lubie"))
        return RandomText(13);
    else if (VectSrch(Words, "umiem") || VectSrch(Words, "potrafie"))
        return RandomText(14);
    else if (VectSrch(Words, "stworzyl") && VectSrch(Words, "mnie"))
        return RandomText(23);
    else if (VectSrch(Words, "jestem") && VectSrch(Words, "czlowiekiem"))
        return RandomText(24);
    else if (VectSrch(Words, "umiem") || VectSrch(Words, "potrafie"))
        return RandomText(14);
    else if ((VectSrch(Words, "jestem") && VectSrch(Words, "w") && (VectSrch(Words, "wysmienitym") ||  VectSrch(Words, "swietnym") ||
             VectSrch(Words, "dobrym") || VectSrch(Words, "wspanialym")) && VectSrch(Words, "humorze")) ||
             ((VectSrch(Words, "mam") || VectSrch(Words, "miewam")) && (VectSrch(Words, "wysmienity") || VectSrch(Words, "swietny") ||
             VectSrch(Words, "dobry")) && VectSrch(Words, "humor")))
        return RandomText(39);
    else if (VectSrch(Words, "znam"))
        return RandomText(40);
    else if (VectSrch(Words, "wiem") && VectSrch(Words, "to") && VectSrch(Words, "z"))
        return RandomText(25);
    else if (VectSrch(Words, "mam") && VectSrch(Words, "baze") && (VectSrch(Words, "w") || VectSrch(Words, "na")))
        return RandomText(26);
    else if (VectSrch(Words, "pale"))
        return RandomText(34);
    else if (VectSrch(Words, "pije"))
        return RandomText(35);
    else if (VectSrch(Words, "cpam"))
        return RandomText(36);
    else if (((VectSrch(Words, "bylem") || VectSrch(Words, "przebywalem") || VectSrch(Words, "bywalem")) &&
              VectSrch(Words, "w")) || ((VectSrch(Words, "wyjezdzalem") || VectSrch(Words, "jezdzilem")) &&
              VectSrch(Words, "do")))
        return RandomText(33);
    else if (VectSrch(Words, "mam") && VectSrch(Words, "cos") && VectSrch(Words, "wspolnego"))
        return RandomText(38);
    else if ((VectSrch(Words, "zapodam") || VectSrch(Words, "dam") || VectSrch(Words, "opowiem") || VectSrch(Words, "napisze")) &&
             (VectSrch(Words, "cytat") || VectSrch(Words, "cytata") || VectSrch(Words, "cytatka")))
        return RandomText(31);
    else if (VectSrch(Words, "zyje") || VectSrch(Words, "istnieje"))
        return "Moje pierwsze uruchomienie nast¹pi³o 20 sierpnia 2010 roku, co oznacza, ¿e istniejê ju¿ " + CalculateLifeExpectancy() + " dni.";
    else if (BotQuestion == 2)
        return RandomText(4);
    else
        return RandomText(29);
}
