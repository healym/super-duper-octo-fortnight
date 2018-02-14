#include<iostream>
#include<string>

using namespace std;

int main() {
    return 0;
}

bool IsInt(string str) {
  int k;
  int state = 0;
  for (int i = 0; i < str.length(); i++) {
    k = int(str[i]);
    if (k == int('+') || k == int('-')) {
        if (state == 0) {
          state = 1;
        } else {
          return false;
        }
    } else if (k < 58 && k >= 48) {
        state = 2;
    } else {
        return false;
    }
  }
  return state == 2;
}

bool IsDec(string str) {
  int k;
  int state = 0;
  for (int i = 0; i < str.length(); i++) {
    k = int(str[i]);
    if (k == int('+') || k == int('-')) {
        if (state == 0) {
          state = 1;
        } else {
          return false;
        }
    } else if (k < 58 && k >= 48) {
        if (state == 0 || state == 1) {
          state = 2;
        } else if (state == 2) {
          state = 2;
        } else if (state == 3 || state == 4) {
          state = 4;
        }
    } else if (k == int('.')) {
        if (state == 2) {
          state = 3;
        } else {
          return false;
        }
    } else {
        return false;
    }
  }
  return state == 4;
}

bool IsSci(string str) {
  int state = 0;
  int k;
  for(int i = 0; i < str.length(); i++) {
    k = int(str[i]);
    if (k == int('+') || k == int('-')) {
      if (state == 0) {
        state = 1;
      } else if (state == 4) {
        state = 5;
      } else {
        return false;
      }
    } else if (k < 58 && k >= 48) {
        if (state == 0 || state == 1) {
          state = 2;
        } else if (state == 2) {
          state = 2;
        } else if (state == 3) {
          state = 3;
        } else if (state == 4 || state == 5 || state == 6) {
          state = 6;
        } else {
          return false;
        }
    } else if (k == int('.')) {
        if (state == 2) {
          state = 3;
        } else {
          return false;
        }
    } else if (k == int('E') || k == int('e')) {
        if (state == 3) {
          state = 4;
        } else {
          return false;
        }
    } else {
      return false;
    }
  }
  return state == 6;
}

bool IsHex(string str) {
  int state = 0;
  int k;
  for (int i = 0; i < str.length(); i++) {
    k = int(str[i]);
    if (k < 58 && k >= 48 || k < 91 && k > 65) {
      if (state == 0 || state == 1) {
        state = 1;
      } else {
        return false;
      }
    } else if (k == int('H')) {
      if (state == 1) {
        state = 2;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  return state == 2;
}

bool IsId(string str) {
  int state = 0;
  int k;
  for (int i = 0; i < str.length(); i++) {
    k = int(str[i]);
    if (k < 91 && k >=65 || k < 123 && k >= 97){
      if (state == 0) {
        state = 1;
      } else if (state == 1) {
        state = 1;
      }
    } else if (k<58 && k>=48) {
      if (state == 1) {
        state = 1;
      } else {
        return false;
      }
    } else if (k == int('_')) {
      if (state = 1) {
        state = 1;
      } else {
        return false;
      }
    }
  }
  return state == 1;
}

bool IsKeyword(string str) {
  return str == "WHILE" || str == "IF" || str == "ELSE" || str == "PRINT";
}

bool IsPhoneNumber(string str) {
  int state = 0;
  int k;
  for (int i = 0; i < str.length(); i++) {
    k = int(str[i]);
    if (k < 58 && k >= 48) {
      if (state > 0 && state < 3
      || state > 4 && state < 8
      || state > 8 && state < 13
      || state > 13 && state < 16
      || state > 17 && state < 20) {
        state++;
      } else if (state == 0) {
        state = 14;
      } else {
        return false;
      }
    } else if (k == int('.')) {
      if (state == 16) {
        state = 17;
      } else if (state == 20) {
        state = 9;
      } else {
        return false;
      }
    } else if (k == int('-')) {
      if (state == 8) {
        state = 9;
      } else if (state == 16) {
        state = 5;
      } else {
        return false;
      }
    } else if (k == int('(')) {
      if (state == 0) {
        state = 1;
      } else {
        return false;
      }
    } else if (k == int(')')) {
      if (state == 5) {
        state = 6;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  return state == 13;
}