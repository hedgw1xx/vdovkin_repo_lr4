#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool UserInput(string input) {
  if (input.empty())
    return false;
  try {
    int number = stoi(input);
  } catch (...) {
    return false;
  }
  return true;
}

function<void()> EnterNumber(int &varLink, string label) {
  return [&varLink, label]() {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    while (!UserInput(raw_input)) {
      cout << label;
      getline(cin, raw_input);
    }
    varLink = stoi(raw_input);
  };
}

void enterA() {
  int a;
  EnterNumber(a, "Enter number A: ");
  cout << "Number A: " << a << endl;
}

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
      {1, {"Enter number A", enterA}},    {2, {"Enter number B", enterB}},
      {3, {"Enter number C", enterC}},    {4, {"Remainder", remainder}},
      {5, {"Integer part", integerPart}},
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
