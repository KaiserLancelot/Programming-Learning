//
// Created by kaiser on 18-12-21.
//

#ifndef CPP_PRIMER_EX_13_49_STRVEC_H
#define CPP_PRIMER_EX_13_49_STRVEC_H

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec {
  friend void swap(StrVec& lhs, StrVec& rhs);

 public:
  using SizeType = std::size_t;
  StrVec() = default;
  StrVec(std::initializer_list<std::string> il);
  StrVec(const StrVec& item);
  StrVec(StrVec&& item) noexcept;
  StrVec& operator=(StrVec item);
  ~StrVec();
  void PushBack(const std::string& s);
  SizeType Size() const;
  SizeType Capacity() const;
  std::string* begin() const;
  std::string* end() const;
  void Reserve(SizeType new_cap);
  void Resize(SizeType size);
  void Resize(SizeType size, const std::string& value);

 private:
  void CheckAlloc();
  std::pair<std::string*, std::string*> AllocCopy(const std::string* begin,
                                                  const std::string* end);
  void Free();
  void Reallocate(SizeType new_cap);

  std::string* begin_{};
  std::string* end_{};
  std::string* cap_{};

  inline static std::allocator<std::string> alloc_;
};

void swap(StrVec& lhs, StrVec& rhs);

#endif  // CPP_PRIMER_EX_13_49_STRVEC_H
