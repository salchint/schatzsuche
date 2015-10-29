#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

#ifdef WIN32
# include "windows.h"
#else
# include <unistd.h>
#endif

void sleepMs(unsigned int millisecs)
{
#ifdef WIN32
  Sleep(millisecs);
#else
  usleep(millisecs * 1000);
#endif
}

class Screen
{
private:
  size_t width;
  size_t hight;
  size_t padding;
  
  std::string& breakLines(const char* text)
  {
    using namespace std;
    string buffer (text);
    this->breakLines(buffer);
  }

  std::string& breakLines(std::string& text)
  {
    using namespace std;
    string::size_type offset = 0;

    if(text.length() + 2*this->padding < this->width)
    {
      text.insert(0, this->padding, ' ');
      return text;
    }

    for(;offset != string::npos;)
    {
      offset = text.rfind(' ', offset + this->width - 2*this->padding);
      if(string::npos != offset)
      {
        text.replace(offset, 1, "\n");
        text.insert(offset + 1, this->padding, ' ');
      }
      if(text.length() < offset + this->width - 2*this->padding)
      {
        break;
      }
    }

    text.insert(0, this->padding, ' ');
    return text;
  }

  void typeDelayed(std::string text)
  {
    using namespace std;

    for(string::iterator it=text.begin(); it!=text.end(); ++it)
    {
      sleepMs(100);
      cout << *it;
      cout.flush();
      if('.' == *it || '!' == *it || '?' == *it)
      {
        sleepMs(400);
      }
    }
  }

public:
  Screen() : width(110), hight(45)
    , padding(4)
  {
  }

  virtual ~Screen()
  {
  }

  void clear()
  {
    using namespace std;

    for(size_t i=0; i<this->hight; ++i) cout << endl;
  }

  void promptToContinue()
  {
    using namespace std;

    for(int i=0; i<0.3*this->hight; ++i) cout << endl;
    string spacing;
    spacing.insert(0, this->width - 15, ' ');
    cout << spacing;
    string text ("Druecke ENTER");
    this->typeDelayed(this->breakLines(text));
    
    getchar();
  }

  void print(std::string text)
  {
    using namespace std;

    this->clear();
    this->typeDelayed(this->breakLines(text));

    this->promptToContinue();
  }

  void printParagraph(std::string text)
  {
    using namespace std;

    for(int i=0; i<3; ++i) cout << endl;
    this->typeDelayed(this->breakLines(text));
  }
};
