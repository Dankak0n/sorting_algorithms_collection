//It is assumed that first <= last
//Multiply and surrender paradigm
#include<iterator>
template <class Compare, class RandomAccessIterator>
void
slow_sort(RandomAccessIterator first, RandomAccessIterator last, const Compare &comp) { //[first, last)

	typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
	difference_type len = std::distance(first, last);

	if (len < 2)
		return;

	RandomAccessIterator middle = first + len / 2;

	slow_sort(first, middle, comp);
	slow_sort(middle, last, comp);

	--last;
	--middle;
	if (comp(*last, *middle))
		std::iter_swap(middle, last);

	slow_sort(first, last, comp);
}
