#include "SortedSet.h"

SortedSet::SortedSet(Relation r)
{
	this->size = 0;
	cmpRel = r;
}

SortedSetIterator SortedSet::iterator() const
{
	return SortedSetIterator(*this);
}
