#pragma once
#include "TNotCopyable.h"
class Repaired
{
private:
	TNotCopyable *tnotcopyable;
public:
	Repaired() 
	{ }

	Repaired(TNotCopyable *pointer)
	{
		tnotcopyable = pointer;
	}

	~Repaired()
	{
		if(tnotcopyable != nullptr)
			tnotcopyable->Close();	
	}
};
