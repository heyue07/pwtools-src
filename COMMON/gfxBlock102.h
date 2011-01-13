#pragma once

#include "gfxBlock.h"

#pragma once

public ref class gfxBLOCK102 : gfxBLOCK
{
	public: gfxBLOCK102(void)
	{
	}
	protected: ~gfxBLOCK102()
	{
	}

	public: virtual bool Fix(Options^ options) override
	{
		if(options->gfxDowngrade)
		{
			FixBasicParameters();
			FixControlTypes();

			String^ line;

			for(int i=0; i<Parameters->Count; i++)
			{
				line = (String^)Parameters[i];

				if(line->StartsWith("SurfaceUseParentDir:"))
				{
					Parameters->RemoveAt(i);
					i--;
				}
				if(line->StartsWith("YawEffect:"))
				{
					Parameters->RemoveAt(i);
					i--;
				}
			}
		}
		return true;
	}
};