#include<iostream>
#include<string>

using namespace std;

bool IsInt(string str);
bool IsSci(string str);
bool IsDec(string str);
bool IsHex(string str);
bool IsId(string str);
bool IsKeyword(string str);
bool IsPhoneNumber(string str);

int main() {
  string input;
  int num;
  cin >> num;
  cout << num << endl;
  for (int i = 1; i <= num; i++) {
    cin >> input;
    cout << i << ": ";
    if (IsKeyword(input)) {
      cout << "Keyword." << endl;
    } else if (IsSci(input)) {
      cout << "Scientific." << endl;
    } else if (IsDec(input)) {
      cout << "Decimal." << endl;
    } else if (IsHex(input)) {
      cout << "Hexadecimal." << endl;
    } else if (IsInt(input)) {
      cout << "Integer." << endl;
    } else if (IsPhoneNumber(input)) {
      cout << "Phone." << endl;
    } else if (IsId(input)) {
      cout << "Identifier." << endl;
    } else {
      cout << "INVALID!" << endl;
    }
  }
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
     if (k == int('H')) {
      if (state == 1) {
        state = 2;
      } else {
        return false;
      }
    } else if (k < 58 && k >= 48 || k < 71 && k >= 65) {
      if (state == 0 || state == 1) {
        state = 1;
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
  return str == "while" || str == "if" || str == "else" || str == "print";
}

bool IsPhoneNumber(string str) {
  int state = 0;
  int k;
  for (int i = 0; i < str.length(); i++) {
    k = int(str[i]);
    if (k < 58 && k >= 48) {
      if (state >= 1 && state <= 3
      || state >= 4 && state <= 7
      || state >= 9 && state <= 12
      || state >= 14 && state <= 15
      || state >= 17 && state <= 19) {
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
      if (state == 4) {
        state = 5;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  return state == 13;
}