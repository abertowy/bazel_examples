#ifndef COW_H
#define COW_H

using namespace std;

typedef enum Color {black, brown, beige, blackandwhite, nocolor};

class Cow {
 public:
  Cow();
  ~Cow();

  // accessors
  double weight() { return weight_; };
  string name() { return name_; };
  Color color() { return color_; };

  // mutators
  void set_name(string inName) { name_ = inName; };
  void set_color(Color inColor) { color_ = inColor; };
  void set_weight(double inWeight) {weight_ = inWeight; };

  void Moo();
  void Properties();

 private:
  Color color_;
  double weight_;
  string name_;
};

#endif