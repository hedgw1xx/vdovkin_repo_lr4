#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int side1, side2;

function<void()> EnterNumber(int &varlink, string label) {}

void enterA() {}

void enterB() {}

void enterC() {}

void remainder() {}

void integerPart() {}

struct MenuItem {
  string title;
  function<void()> action;
};

int main() {
  map<int, MenuItem> menu = {
      {1, {"Enter side 1", EnterNumber(side1, "side 1")}},
      {2, {"Enter side 2", EnterNumber(side2, "side 2")}},
      {3, {"Calculate area", CalcArea}},
      {4, {"Calculate perimeter", CalcPerim}},
  };

  int choice = 0;

  while (true) {
    cout << "Menu:" << endl;
    for (const auto &item : menu) {
      cout << "Task " << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 0) {
      cout << "© 2025 Evgeniy Vdovkin" << endl;
      break;
    }
    cout << endl;
    if (menu.find(choice) != menu.end()) {
      menu[choice].action();
    } else {
      cout << "Invalid choice" << endl;
    }
    cout << endl;
  }
  return 0;
}
