#pragma once
#include "TNotCopyable.h"
class Repaired
{
private:
	TNotCopyable *tnotcopyable;
public:
	Repaired(TNotCopyable *pointer)
	{
		tnotcopyable = pointer;
	}

	~Repaired()
	{
		tnotcopyable->Close();
		tnotcopyable = nullptr;
	}
};