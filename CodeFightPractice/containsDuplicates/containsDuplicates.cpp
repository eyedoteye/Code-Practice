#include "stdafx.h"
#include <unordered_set>
#include <vector>
#include <iostream>

bool containsDuplicates(std::vector<int> a)
{
  std::unordered_set<int> uniqueValues;

  for(std::vector<int>::size_type i = 0;
      i < a.size();
      ++i)
  {
    if(uniqueValues.find(a[i]) != uniqueValues.end())
      return true;

    uniqueValues.insert(a[i]);
  }

  return false;
}

void printTest(int testNumber, std::vector<int> input, bool expectedOutput, bool actualOutput)
{
  bool result = expectedOutput == actualOutput;
  std::cout << "Test #" << testNumber << " ";
  if(result)
    std::cout << "Passed.\n";
  else
    std::cout << "Failed.\n";

  std::cout << "  [" << input[0];
  for(std::vector<int>::size_type i = 1; i < input.size() - 1; ++i)
  {
    std::cout << ", " << input[i];
  }
  std::cout << "]" << std::endl;
  std::cout << "  Expected:\t" << (expectedOutput ? "true" : "false") << "\n";
  std::cout << "  Actual:\t" << (actualOutput ? "true" : "false") << std::endl;
}

int main()
{
  if(1) // First Test
  {
    std::vector<int> input{1, 2, 3, 1};
    bool expectedOutput = true;

    bool output = containsDuplicates(input);

    printTest(1, input, expectedOutput, output);
  }

  if(1) // Second Test
  {
    std::vector<int> input{3, 1};
    bool expectedOutput = false;

    bool output = containsDuplicates(input);

    printTest(2, input, expectedOutput, output);
  }

  if(1) // Third Test
  {
    std::vector<int> input{0, 4, 5, 0, 2, 6};
    bool expectedOutput = true;

    bool output = containsDuplicates(input);

    printTest(3, input, expectedOutput, output);
  }

  return 0;
}

