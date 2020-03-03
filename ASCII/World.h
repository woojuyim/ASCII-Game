#pragma once
#include "Character.h"

class World {

public:
	

	World() {
	}

	Character getuser() {
		for (i = 0; i < usercount; i++) {
			return userlist[i];
		}
	}


private:
	Character userlist[5];
	int usercount = 0;
	int i;

};
	
	
