/*
* File:   ABag.h
* CSIS 215-<D01>
* Author Isaac Craig & Prof Sipantzi
*/

#ifndef ABAG_H
#define	ABAG_H

#include "book.h"
#include "bagADT.h"

template <typename E>
class ABag : public Bag<E> {
public:
	// constructors/destructor
	ABag() : Bag() { //size not specified
		setCapacity(10);
	};

	ABag(const size_t size) : Bag() {//size specified
		setCapacity(size);
	};
	~ABag() {};
	
	// bag methods: addItem, remove, operator+=, size, etc.

	bool addItem(const E& item) { //adds item to the top as you would in a bag
		if (used < capacity)
		{
			data[used] = item;
			used++;
			return true;
		}
		else {
			return false;
		}
	}; //*****************************************************************
	
	bool remove(E& item) { //removes specific item in bag 
		if (used > 0) {
			for (int i{ 0 }; i < used; i++) {
				if (data[i] == item) { //finds item
					item = data[i];
					used--;
					for (int j{ i }; j < used; j++) { // shift bag to fill emptied slot
						data[j] = data[j++];
					}
					return true;
				}
			}
		}
		return false;
	}; //*****************************************************************

	bool removeTop(E& returnValue) { //removes top bag item
		if (used > 0) {
			used--;
			returnValue = data[used];
			return true;
		}
		return false;
	}; //*****************************************************************

	bool find(E& returnValue) const { //returns true if item exists in array
		for (int i{ 0 }; i < used; i++) {
			if (data[i] == returnValue) {
				returnValue = data[i];
				return true;
			}
		} 
		return false;
	}; //*****************************************************************

	bool inspectTop(E& item) const { //checks bag for contents, if true updates item with data array
		if (used > 0) {
			for (int i{ 0 }; i < used; i++) {
				item = data[i];
			}
			return true;
		}
		else {
			return false;
		}
	}; //*****************************************************************

	int size() const { //current number of items in the bag
		return used;
	}; //*****************************************************************

	void emptyBag() { //empties bag
		used = 0;
	}; //*****************************************************************

	int bagCapacity() const { //total bag capacity
		return capacity;
	}; //*****************************************************************

	bool operator+=(const E& addend) { //adds item to bag
		if (addItem(addend)) {
			return true;
		} 
		else {
			return false;
		}
	}; //*****************************************************************

private:
	E data[20];		 // an array of items
	int used{ 0 }; 	 // number of items the data array currently holds
	int capacity;    // the number of items the bag can hold (size of array)

	void setCapacity(const size_t cap) {
		capacity = cap;
	};
};

#endif	/* ABAG_H */


