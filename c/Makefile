SEARCH=searching_algorithms
SORT=sorting_algorithms
SEARCH_DIRS=binary-search
SORT_DIRS=insertion-sort mergesort quicksort selection-sort


all:
	# build all searching
	set -e; for d in $(SEARCH); do \
		for s in $(SEARCH_DIRS); do $(MAKE) all -C "$$d/$$s"; done \
		done
	# build all sorting
	set -e; for d in $(SORT); do \
		for s in $(SORT_DIRS); do $(MAKE) all -C "$$d/$$s"; done \
		done

test:
	# test all searching
	set -e; for d in $(SEARCH); do \
		for s in $(SEARCH_DIRS); do $(MAKE) test -C "$$d/$$s"; done \
		done
	# test all sorting
	set -e; for d in $(SORT); do \
		for s in $(SORT_DIRS); do $(MAKE) test -C "$$d/$$s"; done \
		done

clean: 
	# clean all searching
	set -e; for d in $(SEARCH); do \
		for s in $(SEARCH_DIRS); do $(MAKE) clean -C "$$d/$$s"; done \
		done
	# clean all sorting
	set -e; for d in $(SORT); do \
		for s in $(SORT_DIRS); do $(MAKE) clean -C "$$d/$$s"; done \
		done

.PHONY: all clean test

