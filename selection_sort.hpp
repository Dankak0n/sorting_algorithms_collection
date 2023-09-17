//It is assumed that first <= last
#include<iterator>
template <class Compare, class ForwardIterator>
void
selection_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (; first != last; ++first) {
		ForwardIterator iter_to_min = first, iter = first;
		for (++iter; iter != last; ++iter)
			if (comp(*iter, *iter_to_min))
				iter_to_min = iter;
		std::iter_swap(iter_to_min, first);
	}
}
