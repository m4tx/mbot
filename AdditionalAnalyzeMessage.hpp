#ifndef AdditionalAnalyzeMessage_hpp
#define AdditionalAnalyzeMessage_hpp

#include <vector>
#include <stdio.h>
#include <time.h>
#include "MainFunctions.hpp"

std::string DeleteUnnecessaryChars (std::string src);
std::string DeleteUnnecessaryChars2 (std::string src);
int SearchInVector (std::vector<std::string> src, std::string text);
bool VectSrch (std::vector<std::string> src, std::string text);
bool VectSrch2 (std::vector<std::string> src, std::string text);
bool VectSrch2AtEnd (std::vector<std::string> src, std::string text);
std::string CalculateLifeExpectancy ();
void InitTextsArray ();
std::string RandomText (int Text);
std::string DictionaryText (int Text);

#endif
