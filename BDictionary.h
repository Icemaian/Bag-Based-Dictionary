/*
* File:   BDictionary.h
* CSIS 215-<D01>
* Author Isaac Craig & Prof Sipantzi
*/

#ifndef BDICTIONARY_H
#define	BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
public:
	// constructors/destructor
	BDictionary() : Dictionary() {};
	BDictionary(const size_t size) : Dictionary() {
		dictionary = new ABag<KVpair<Key, E>>(size);
	};
	~BDictionary() {};
	// methods: clear, insert, remove, removeAny, find, size, etc.

	void clear() { //clears dictionary by destructing it and re-constructing it
		dictionary->emptyBag();
	}; //********************************************************************

	bool insert(const Key& k, const E& e) { // inserts record, key & value
		KVpair<Key, E> KV(k, e);
		if (dictionary->addItem(KV)) {
			return true;
		}
		else {
			return false;
		}
	} //********************************************************************

	bool remove(const Key& k, E& rtnVal) { // removes the specific record 
		KVpair<Key, E> KV(k, rtnVal);
		if (dictionary->remove(KV)) {
			rtnVal = KV.value();
			return true;
		}
		else {
			return false;
		}
	} //********************************************************************

	bool removeAny(E& returnValue) { //removes an arbituary record
		KVpair<Key, E> KV;
		if (dictionary->removeTop(KV)) {
			returnValue = KV.value();
			return true;
		}
		else {
			return false;
		}
	} //********************************************************************

	bool find(const Key& k, E& returnValue) const { //finds and update return Value
		KVpair<Key, E> KV(k, returnValue);
		if (dictionary->find(KV)) {
			returnValue = KV.value();
			return true;
		}
		else {
			return false;
		} 
	} //********************************************************************

	int size() { //returns the current number of records in the dictionary
		return dictionary->size();
	} //********************************************************************

private:
	//Pointer to a ABag object.  You'll need to instantiate the bag in your constructor:
	// dictionary = new ABag<KVpair<Key, E>>(size) or something similar depending on how
	// you've implemented your ABag constructor(s).
	//This pointer gives you access to the bag which stores your data and provides the 
	//functions you need to build your dictionary.
	ABag<KVpair<Key, E>>* dictionary;
};


#endif	/* BDICTIONARY_H */

