namespace sviridenko
{
  template< typename Iter >
  void iterSwap(Iter first, Iter second)
  {
    auto tempValue = *first;
    *first = *second;
    *second = tempValue;
  }

  template < typename Iter >
  void insertSort(Iter begin, Iter end, bool cmp)
  {
    Iter iter = begin;
    iter++;
    while (iter != end) {
      Iter key = iter;
      Iter it = iter;
      it--;
      while ((*it > *key && cmp == 0) || (*it < *key && cmp == 1)) {
        iterSwap< Iter >(it, key);
        key--;
        if (it != begin)
        {
          it--;
        }
      }
      iter++;
    }
  }

  template < typename Iter >
  void shakerSort(Iter begin, Iter end, bool cmp)
  {
    Iter first = begin;
    Iter last = end;
    for (Iter i = first; i != last;)
    {
      bool swapped = true;
      while (first != last-- && swapped) {
        swapped = false;
        for (Iter i = first; i != last; ++i) {
          Iter next = i;
          next++;
          if (next == end)
          {
            break;
          }
          if ((*next < *i && cmp == 0) || (*next > *i && cmp == 1)) {
            iterSwap< Iter >(i, next);
            swapped = true;
          }
        }
        if (!swapped) {
          break;
        }
        swapped = false;
        Iter i = end;
        i--;
        for (; i != first; --i)
        {
          Iter prev = i;
          prev--;
          if ((*i < *prev && cmp == 0) || (*i > *prev && cmp == 1)) {
            iterSwap< Iter >(i, prev);
            swapped = true;
          }
        }
        ++first;
      }
    }
  }

  template < typename Iter >
  void oddEvenSort(Iter begin, Iter end, bool cmp)
  {
    bool sorted = false;
    while (!sorted)
    {
      sorted = true;
      Iter beginNext = begin;
      beginNext++;
      for (Iter i = beginNext; i != end; (i++)++)
      {
        Iter next = i;
        next++;
        if (next == end)
        {
          break;
        }
        if ((*i > *next && cmp == 0) || (*i < *next && cmp == 1))
        {
          iterSwap< Iter >(i, next);
          sorted = false;
        }
      }
      for (Iter i = begin; i != end; (i++)++)
      {
        Iter next = i;
        next++;
        if (next == end)
        {
          break;
        }
        if ((*i > *next && cmp == 0) || (*i < *next && cmp == 1))
        {
          iterSwap< Iter >(i, next);
          sorted = false;
        }
      }
    }
  }
}
