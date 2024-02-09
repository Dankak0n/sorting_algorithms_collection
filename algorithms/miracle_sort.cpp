//It is assumed that first <= last
template <class Compare, class ForwardIterator>
void
miracle_sort(ForwardIterator first, ForwardIterator last, Compare comp) { //[first, last)
	if (first == last) //zero elements
		return;
	bool sorted = false;
	do {
		sorted = true;
		ForwardIterator iter = first, prev_iter = first;
		for (++iter; iter != last; ++iter, ++prev_iter)
			if (!comp(*prev_iter, *iter))
				sorted = false;
	} while (!sorted);
}
