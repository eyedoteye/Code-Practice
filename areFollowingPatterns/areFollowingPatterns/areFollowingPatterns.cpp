#include "stdafx.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>


bool areFollowingPatterns(
  std::vector<std::string> const &strings,
  std::vector<std::string> const &patterns)
{
  if(strings.size() != patterns.size())
    return false;


  std::unordered_map<
    std::string,
    std::string> patternToStringPairs;
  std::unordered_map <
    std::string,
    std::string> stringToPatternPairs;

  for(std::vector<std::string>::size_type i = 0;
      i < patterns.size();
      ++i)
  {
    std::string *string = &patternToStringPairs[patterns[i]];
    if(*string == "")
      *string = strings[i];
    else if(*string != strings[i])
      return false;

    std::string *pattern = &stringToPatternPairs[strings[i]];
    if(*pattern == "")
      *pattern = patterns[i];
    else if(*pattern != patterns[i])
      return false;
  }

  return true;
}

int main()
{
  std::vector<std::string> strings;
  strings.push_back("cat");
  strings.push_back("dog");
  strings.push_back("doggy");

  std::vector<std::string> patterns;
  patterns.push_back("a");
  patterns.push_back("b");
  patterns.push_back("b");

  if(areFollowingPatterns(strings, patterns))
    printf("goodjob");
  else
    printf("bad job");

  return 0;
}
