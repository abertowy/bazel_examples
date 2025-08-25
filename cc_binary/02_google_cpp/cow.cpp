#include <iostream>
#include "cow.h"

using namespace std;

Cow::Cow() {}

Cow::~Cow() {}

void Cow::Moo() {
  cout << name() << " says MOO." << endl;
}

void Cow::Properties() {
  cout << name() << " weighs " << weight() << ", is "
       << color() << " and says MOO." << endl;
}