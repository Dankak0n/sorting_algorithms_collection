//It is assumed that first <= last
#include<iterator>
template <class Compare, class BidirectionalIterator>
void
insertion_sort(BidirectionalIterator first, BidirectionalIterator last, Compare comp) { //[first, last)
	if (first == last) //zero elements
		return;
	BidirectionalIterator last_sorted = first; //actually the first element after last sorted
	for (++last_sorted; last_sorted != last; ++last_sorted) {
		BidirectionalIterator prev_iter = last_sorted;
		--prev_iter;
		for(BidirectionalIterator iter = last_sorted; iter != first && comp(*iter, *prev_iter); --prev_iter, --iter)
			std::iter_swap(iter, prev_iter);
	}
}
