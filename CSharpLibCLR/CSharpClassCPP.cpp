#include "Stdafx.h"

#include "CSharpClassCPP.h"
#include "CSharpClassCLR.h"

CSharpClassCPP* CSharpClassCPP::CreateInstance(ICSharpClassCPPCallback* cb)
{
	return new CSharpClassCLR(cb);
}