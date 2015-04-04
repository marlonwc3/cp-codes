struct Comp {
  bool operator () (const S& a, const S& b) const {
     return a.attr < b.attr;
  }
};








