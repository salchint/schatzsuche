#pragma once

#include <iostream>
#include <string>
#include <vector>

class Screen
{
private:
  size_t width;
  size_t hight;
  size_t padding;

  std::string& umlaute(std::string text)
  {
    using namespace std;
    vector<size_t> positions;
    string::iterator it = text.begin()
    positions.push_back( text.find('ü'
    //string tmp = text.replace(

  }

public:
  Screen() : width(110), hight(55)
    , padding(6)
  {
  }

  virtual ~Screen()
  {
  }

  void print(std::string text)
  {
    using namespace std;
    cout << text << endl;
  }
};
