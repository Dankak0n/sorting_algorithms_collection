//It is assumed that first <= last
#include<iterator>
template <class Compare, class ForwardIterator>
void
bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) { //[first, last)
	if (first == last) //zero elements
		return;
	for (bool swapped = true; swapped; ) {
		swapped = false;
		ForwardIterator iter = first, prev_iter = first;
		for (++iter; iter != last; ++prev_iter, ++iter)
			if (!comp(*prev_iter, *iter) && *prev_iter != *iter) {
				std::iter_swap(prev_iter, iter);
				swapped = true;
			}
	}
}
