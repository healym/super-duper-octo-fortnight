#include<iostream>
#include<string>

using namespace std;

int main()
{
    return 0;
}

bool is_int(string str)
{
  char c;
  int state = 0;
  for(int i=0; i<str.length(); i++)
  {
    c = str[i];
    switch(c)
    {
      case '+':
      case '-':
      if(state == 0)
      {
        state = 1;
      }
      else
      {
        return false;
      }
        break;
      case '9':
      case '8':
      case '7':
      case '6':
      case '5':
      case '4':
      case '3':
      case '2':
      case '1':
      case '0':
        state = 2;
        break;
      default:
        return false;
    }
  }
  if(state == 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}