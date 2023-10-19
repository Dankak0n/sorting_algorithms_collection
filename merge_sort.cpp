//It is assumed that first <= last
#include<iterator>
template <class Compare, class RandomAccessIterator>
void
merge_sort(RandomAccessIterator first, RandomAccessIterator last, const Compare &comp) { //[first, last)

	typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
	typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

	difference_type len = std::distance(first, last);

	if (len < 2)
		return;

	RandomAccessIterator middle = first + len / 2;

	merge_sort(first, middle, comp);
	merge_sort(middle, last, comp);

	value_type *tmp_buff = new value_type[len];

	RandomAccessIterator first_half_iter = first, second_half_iter = middle;
	for (difference_type i = 0; i != len; ++i)
		if (second_half_iter == last ||
		   (first_half_iter != middle && comp(*first_half_iter, *second_half_iter))) {
					tmp_buff[i] = *first_half_iter;
					++first_half_iter;
		} else {
					tmp_buff[i] = *second_half_iter;
					++second_half_iter;
		}

	for (difference_type i = 0; first != last; ++first, ++i)
		*first = tmp_buff[i];

	delete[] tmp_buff;
}
