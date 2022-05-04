#include "SkipList.h"
#include <iostream>

using namespace std;

SkipList::SkipList() : listHeads() {
    makeNewLevelList();
    makeNewLevelList();
}

// makes a new list on the top level of existing list.
// call only when top list is NULL or just the two sentinels. 
void SkipList::makeNewLevelList() {
    SkipList::Entry* minusInfinity = new Entry("!!", "");	// "!!" < any other string.
    SkipList::Entry* plusInfinity = new Entry("}}", "");	// "}}" > any other key.

    Quad* first = new Quad(minusInfinity);
    Quad* last = new Quad(plusInfinity);

    int numLists = listHeads.size();
    Quad* oldFirst = numLists == 0 ? NULL : listHeads[numLists - 1];
    Quad* oldLast  = numLists == 0 ? NULL : oldFirst->next;

    first->prev = NULL;
    first->next = last;
    first->above = NULL;
    first->below = oldFirst;

    last->prev = first;
    last->next = NULL;
    last->above = NULL;
    last->below = oldLast;

    if(oldFirst != NULL) {
        oldFirst->above = first;
        oldLast->above = last;
    }
    listHeads.push_back(first);
}

void SkipList::printOneList(int listNum) {
	Quad* bottomCurrent = listHeads[0];
	Quad* current = listHeads[listNum];

	while(bottomCurrent->next != NULL) {
		std::string toPrint;
		if(current->entry->getKey() == bottomCurrent->entry->getKey()) {
			toPrint = current->entry->getKey();
			current = current->next;
		}
		else {
			toPrint = "--";
		}
		cout << "--" << toPrint;
		bottomCurrent = bottomCurrent->next;
	}
	cout << "--" << bottomCurrent->entry->getKey() << "--" << endl;
}

void SkipList::print() {
	int numLists = listHeads.size();
	for(int i = numLists - 1; i >= 0; i--) {
		printOneList(i);
	}
} 

SkipList::Entry* SkipList::find(Key k) {
    int numLists = listHeads.size();
    Quad* current = listHeads[numLists - 1]; //LEFT UPMOST ELEMENT
    while (current->below != NULL) {
        current = current->below;			// drop down
        while(k >= current->next->entry->getKey()) {	// scan forward
            current = current->next;
        }
    } 
    if(current->entry->key == k) {
        return current->entry;
    }
    else {
        return NULL;
    }
}

// the "trail" is a vector of the last node visited on each list
// the last element of trail is on the lowest list; the first is on the highest.
std::vector<SkipList::Quad*>* SkipList::findWithTrail(Key k) {
    std::vector<SkipList::Quad*>* trail = new std::vector<Quad*>();

    int numLists = listHeads.size();
    Quad* current = listHeads[numLists - 1];

    while (current != NULL) {
        while(k >= current->next->entry->getKey()) {	// scan forward
            current = current->next;
        }
        trail->push_back(current);
        current = current->below;			// drop down
    } 
    return trail;
}
void SkipList::insert(Key k, Value v){
    Entry* answer1 = new Entry(k,v);//just create the entry
    std::vector<SkipList::Quad*>* trail = findWithTrail(k);
    if(trail->back()->entry->getKey() == k){
        return; //already in there
    }
    int height = 0;
    while(rand()%2 == 1){
        height++; //calculating the height with heads and tail
    }
  
    while(height >= listHeads.size()-1){ //height 0 the lowest height
        makeNewLevelList(); //list heads give the height since it has every leftmost element in each level
    }
    SkipList::Quad* below = NULL;
    for(int i = 0; i <= height; i++){ //for each level in height
        SkipList::Quad* before;
        if(trail->size() == 0){
            before = listHeads[i];//if trail is 0 it means its only the leftmost imaginary elements on the level and we need to add it after that 
        }
        else{
            before = trail->back(); //there is some element in each level which we are inserting after them
            //as we know trail does a search and return a list full of elements that we are inserting after them
            trail->pop_back(); //we need pop back and go to next one
        }
        SkipList::Quad* answer2 = new Quad(answer1); //insering above and after
        answer2->prev = before;
        answer2->next = before->next;
        before->next->prev = answer2;
        answer2->above = NULL;
        answer2->below = below;
        before->next = answer2;
        if(below != NULL){ //if below is NULL like the first iteration we would get segFault without this iteration
            below->above = answer2;
        }
        below = answer2;
    }
    delete trail;
}

// fill in the assigned functions here.


void SkipList::remove(Key k){
    std::vector<SkipList::Quad*>* trail = findWithTrail(k);
    SkipList::Quad* current = trail->back(); //the last element is the element lowest on the list, we are starting with lowest 
    //and traversing upwards
    while(current != NULL){
        SkipList::Quad* rem = current;
        current = current->above; //traversing upward
        rem->next->prev = rem->prev; //the one after has a prev link now to the one before
        rem->prev->next = rem->next;  // the one before links the the one after since we are removing rem
        if(current == NULL){
            delete rem->entry;
        }
        delete rem;
    }
    delete trail; //not needed anymore
    //the minumum number of levels is 2 size() it cant be less than two
    if(listHeads.size() == 2){ //even when removed we need two levels 
        return; //just end since there needs no change we cant make the level lesser
    }
    while(listHeads[listHeads.size()-2]->next->entry->getKey() == "}}"){ //if the level has the  only two imaginary node delete them
        listHeads.pop_back();
    }
    return;
}
SkipList::Entry* SkipList::ceilingEntry(Key k){
    SkipList::Quad* current = listHeads[0];
    while(current != NULL){
        if(current->entry->getKey() == k){
            return current->entry;
        }
        else if(current->entry->getKey() > k){//as soon as something bigger seen break 
            break;
        }
        current = current->next;
    }
    return current->entry;

}
SkipList::Entry* SkipList::floorEntry(Key k){
    SkipList::Quad* current = listHeads[0];
    while(current != NULL){
        if(current->entry->getKey() == k){
            return current->entry;
        }
        else if(current->entry->getKey() > k){//as soon as something bigger seen break 
            return current->prev->entry;
        }
        current = current->next;
    }
    return current->entry;
}

SkipList::Entry* SkipList::greaterEntry(Key k){
    SkipList::Quad* current = listHeads[0];
    while(current != NULL){
        if(current->entry->getKey() > k){//as soon as something bigger seen break 
            return current->entry;
        }
        current = current->next;
    }
    return current->entry;
}

SkipList::Entry* SkipList::lesserEntry(Key k){
    SkipList::Quad* current = listHeads[0];
    bool found = false;
    while(current != NULL){
        if(current->entry->getKey() == k){
            found = true;
        }
        if(current->entry->getKey() > k && found){//as soon as something bigger seen break 
            return current->prev->prev->entry;
        }
        else if(current->entry->getKey() > k && !found){//as soon as something bigger seen break 
            return current->prev->entry;
        }
        current = current->next;
    }
    return current->prev->entry;
}
SkipList::~SkipList(){
    while(!listHeads.empty()){ //go to list of head delete each level one by one
        Quad* current = listHeads.front();
        while(current != NULL){
            Quad* temp = current;
            current = current->next;
            delete temp;
            temp = NULL;
        }
        listHeads.erase(listHeads.begin());
    }
}

