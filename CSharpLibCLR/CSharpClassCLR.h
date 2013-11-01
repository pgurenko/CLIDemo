#pragma once

#include "CSharpClassCPP.h"

#include <msclr\event.h>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace CSharpLib;

class CSharpClassCLR : public CSharpClassCPP
{
private:

	ICSharpClassCPPCallback* m_pCallback;
	gcroot<CSharpClass^> m_Instance;

public:

	CSharpClassCLR(ICSharpClassCPPCallback* cb);

    virtual wstring myMethod(int arg);

    virtual void FireMyEvent();

public:
	
	BEGIN_DELEGATE_MAP(CSharpClassCLR)
		EVENT_DELEGATE_ENTRY(OnMyEvent, Object^, MyEventArgs^)
	END_DELEGATE_MAP()

	void OnMyEvent(Object^ sender, MyEventArgs^ e);
};