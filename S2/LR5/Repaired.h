#pragma once
#include "TNotCopyable.h"
class Repaired
{
private:
	TNotCopyable *tnotcopyable;
public:
	Repaired()
	{
		tnotcopyable = new TNotCopyable();
	}

	~Repaired()
	{
		tnotcopyable->Close();
		delete tnotcopyable;
	}
};