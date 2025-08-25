#include <iostream>
#include "cow.h"

using namespace std;

int main() {
  Cow cow1;
  cow1.set_name("betsy");
  cow1.set_weight(400.0);
  cow1.set_color(black);

  cow1.Moo();
  cow1.Properties();
}