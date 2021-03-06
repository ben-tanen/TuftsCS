/*
 * Abilities.cpp
 *
 *  Created on: Oct 17, 2014
 *      Author: Chris Gregg
 */

#include "Abilities.h"

using namespace std;

Abilities::Abilities() {
	// start with only your hand
	head = new AbilityNode();
	head->ability.strength = 1;
	head->ability.weapon = "hand";
	head->next = NULL;
}

// copy constructor
Abilities::Abilities(const Abilities &source) {
	// TODO: Students write code here
	head = new AbilityNode;
	head->ability = source.head->ability;
	
	AbilityNode *src_temp = source.head;
	AbilityNode *new_temp = head;
	
	while (src_temp != NULL){;
	      new_temp->next = new AbilityNode;
	      new_temp = new_temp->next;
	      src_temp = src_temp->next;
	      if (src_temp != NULL)
		new_temp->ability = src_temp->ability;
	}
}


// assignment (=) overload
Abilities &Abilities::operator=(const Abilities &source) {
	// TODO: Students write code here
	cout << "got to overload" << endl;
	
	if (this != &source) {
	    deleteList();
	    
	    head = new AbilityNode;
	    head->ability = source.head->ability;
	    
	    AbilityNode *src_temp = source.head;
	    AbilityNode *new_temp = head;
	    
	    while (src_temp != NULL){
		  
		  new_temp->next = new AbilityNode;
		  new_temp = new_temp->next;
		  src_temp = src_temp->next;
		  if (src_temp != NULL) {
		    new_temp->ability = src_temp->ability;
		    cout << "here2" << endl;
		  }
	    }
	}
	return *this;
	
	
	
}

Abilities::~Abilities() {
	deleteList();
}

void Abilities::deleteList() {
	// TODO: Students write code here
	cout << "got to deleteList" << endl;
	int num_nodes = abilityCount();
	
	AbilityNode *temp1 = head;
	AbilityNode *temp2 = head;
	
	for (int i=0;i<num_nodes;i++){
	    temp1 = temp1->next;
	    delete temp2;
	    temp2 = temp1;
	}
}

void Abilities::updateAbility(std::string name, int amount) {
	AbilityNode *curr = head;
	AbilityNode *prev = NULL;

	while (curr != NULL) {
		if (curr->ability.weapon == name) {
			// found the node to update
			curr->ability.strength = amount;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	// not found, create new node to populate
	curr = new AbilityNode();
	curr->ability.weapon = name;
	curr->ability.strength = amount;
	curr->next = NULL;

	if (prev==NULL) {
		// at head
		head = curr;
	}
	else {
		prev->next = curr;
	}
}

int Abilities::getStrength(std::string name) {
	// returns -1 if the name does not exist in the list
	AbilityNode *curr = head;
	while (curr != NULL) {
		if (curr->ability.weapon == name) {
			return curr->ability.strength;
		}
		curr = curr->next;
	}
	return -1;
}

int Abilities::abilityCount() {
	AbilityNode *curr = head;
	int count=0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

Ability &Abilities::abilityByIndex(int index) {
	// does not do error checking on index!
	AbilityNode *curr = head;
	for (int i=0;i<index;i++) {
		curr = curr->next;
	}
	return curr->ability;
}

void Abilities::printAbilities() {
	// walk the list and print all weapons and abilities
	AbilityNode *curr = head;
	while (curr != NULL) {
		cout << "\t" << curr->ability.weapon << " : "
				<< curr->ability.strength << "\n";
		curr = curr->next;
	}
}

int Abilities::totalStrength() {
	int totalStrength = 0;

	// walk the list and calculate total strength
	AbilityNode *curr = head;
	while (curr != NULL) {
		totalStrength += curr->ability.strength;
		curr = curr->next;
	}
	return totalStrength;
}
