//
// Created by kaiser on 19-3-3.
//

#ifndef CPP_PRIMER_EX_16_15_H
#define CPP_PRIMER_EX_16_15_H

#include <iostream>
#include <string>
#include <vector>

using Pos = std::string::size_type;

template <Pos ht, Pos wd>
class Screen {
  friend std::ostream &operator<<(std::ostream &os, const Screen<ht, wd> &item);
  friend std::istream &operator>>(std::istream &is, Screen<ht, wd> &item);

 public:
  Screen() = default;
  explicit Screen(char ch) : contents_(ht * wd, ch) {}

  char Get() const { return contents_[cursor_]; }
  char Get(Pos r, Pos c) const { return contents_[r * wd + c]; }

  Screen Set(char ch) {
    contents_[cursor_] = ch;
    return *this;
  }

  Screen Set(Pos r, Pos c, char ch) {
    contents_[r * wd + c] = ch;
    return *this;
  }

  Screen Move(Pos r, Pos c) {
    cursor_ = r * wd + c;
    return *this;
  }

  const Screen Display(std::ostream &os) const {
    DoDisplay(os);
    return *this;
  }

  Screen Display(std::ostream &os) {
    DoDisplay(os);
    return *this;
  }

 private:
  void DoDisplay(std::ostream &os) const { os << contents_; }

  Pos cursor_{};
  std::string contents_;
};

#endif  // CPP_PRIMER_EX_16_15_H
