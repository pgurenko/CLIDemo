#pragma once

#include "Stdafx.h"

#include <string>

using namespace std;

enum CSharpClassMoodCPP
{ 
    CSCM_Undefined,
    CSCM_Sad,
    CSCM_Happy
};

class DLLAPI ICSharpClassCPPCallback
{
public:
	virtual void OnMyEvent(wstring str, CSharpClassMoodCPP mood) {}
};

class DLLAPI CSharpClassCPP
{
public:
	
	static CSharpClassCPP* CreateInstance(ICSharpClassCPPCallback* cb);

    virtual wstring myMethod(int arg) = 0;

    virtual void FireMyEvent() = 0;
};