//Michael 22011942
#include <iostream>
#include <string>
using namespace std;

string input, temp;
string sentence[100];
int i, j, last, temp2, length, first, counter;
float spacecount;
int spaceamount(int inputlength);
int finalwordfind();

int main() {
  cout << "Enter a line of text: ";
  getline(cin, input);
  cout << endl << endl;
  if (input.length() > 40) {
    cout << endl;
    cout << "Error line of text exceeds 40 characters" << endl;
    exit(10);
  }
  cout << "1234567890123456789012345678901234567890" << endl;
  spaceamount(input.length());
}

int spaceamount(int inputlength) {
  int indx, intvalue, a, remainder, number;
  float floatvalue, difference;
  spacecount = 0;
  difference = 40 - inputlength;
  indx = 0;
  for (indx = 0; indx < inputlength; indx++) {
    if (input[indx] == ' ') {
      spacecount++;
      last = indx;
    }
  }
  for (indx = 0; input[indx] != ' '; indx ++) {
    first = indx;
  }
  if (difference < spacecount) {
    indx = 0;
    i = 0;
    j = 0;
    length = 0;
    while (difference > 0) {
      if (input[indx] == ' ') {
        temp = "";
        while (input[i] != ' ') {
          temp = temp + input[i];
          i++;
        }
        length = length + temp.length();
        temp = temp + "  ";
        sentence[j] = temp;
        j++;
        difference--;
        i++;
      }
      indx++;
    }
    finalwordfind();
    for (j = 0; j < spacecount + 1; j++) {
      cout << sentence[j];
    }
    cout << endl;

  } else if (difference > spacecount) {
    indx = 0;
    i = 0;
    j = 0;
    length = 0;
    floatvalue = difference / spacecount;
    intvalue = floatvalue * 100;
    if (intvalue % 100 == 0) {
      while (difference > 0) {
        if (input[indx] == ' ') {
          temp = "";
          while (input[i] != ' ') {
            temp = temp + input[i];
            i++;
          }
          length = length + temp.length();
          temp = temp + " ";
          for (a = 0; a < floatvalue; a++) {
            temp = temp + " ";
          }
          sentence[j] = temp;
          j++;
          difference = difference - floatvalue;
          i++;
        }
        indx++;
      }
      finalwordfind();
      for (j = 0; j < spacecount + 1; j++) {
        cout << sentence[j];
      }
      cout << endl;
    } else if (intvalue % 100 != 0) {
      remainder = intvalue % 100;
      if (remainder >= 50) {
        intvalue = floatvalue + 1;
        number = difference - (intvalue * (spacecount - 1));
        while (difference > 0) {
          if (input[indx] == ' ') {
            temp = "";
            while (input[i] != ' ') {
              temp = temp + input[i];
              i++;
            }
            length = length + temp.length();
            if (i < last) {
              temp = temp + " ";
              for (a = 0; a < intvalue; a++) {
                temp = temp + " ";
              }
            } else {
              temp = temp + " ";
              for (a = 0; a < number; a++) {
                temp = temp + " ";
              }
            }
            sentence[j] = temp;
            j++;
            difference = difference - intvalue;
            i++;
          }
          indx++;
        }
        finalwordfind();
        for (j = 0; j < spacecount + 1; j++) {
          cout << sentence[j];
        }
        cout << endl;
      } else {
        indx = 0;
        i = 0;
        j = 0;
        length = 0;
        intvalue = floatvalue;
        number = difference - (intvalue * spacecount);
        while (counter != spacecount) {
          if (input[indx] == ' ') {
            temp = "";
            while (input[i] != ' ') {
              temp = temp + input[i];
              i++;
            }
            length = length + temp.length();
            if (i > first + 1) {
              temp = temp + " ";
              for (a = 0; a < intvalue; a++) {
                temp = temp + " ";
              }
            } else {
              temp = temp + " ";
              for (a = 0; a < intvalue; a++) {
                temp = temp + " ";
              }
              for (a = 0; a < number; a++) {
                temp = temp + " ";
              }
            }
            sentence[j] = temp;
            j++;
            counter++;
            i++;
          }
          indx++;
        }
        finalwordfind();
        for (j = 0; j < spacecount + 1; j++) {
          cout << sentence[j];
        }
        cout << endl;
      }
    }
  }
}

int finalwordfind(){
  int indx, inputlength;
  inputlength = input.length();
  while (j < spacecount + 1) {
      temp = "";
      if (i < last + 1) {
      while (input[i] != ' ') {
        temp = temp + input[i];
        i++;
      }
      sentence[j] = temp + " ";
      j++;
      i++;
      length++;
  } else if (i == last + 1) {
    temp2 = i;
    for (indx = 0; indx < inputlength - temp2; indx++) {
      temp = temp + input[i];
      i++;
  }
  sentence[j] = temp;
  j++;
  }
}
}
