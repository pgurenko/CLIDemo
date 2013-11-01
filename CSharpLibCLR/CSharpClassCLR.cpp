#include "Stdafx.h"

#include "CSharpClassCLR.h"

using namespace msclr::interop;

CSharpClassCLR::CSharpClassCLR(ICSharpClassCPPCallback* cb)
{
	Console::WriteLine("ManagedCLI: CSharpClassCLR::CSharpClassCLR");

	m_pCallback = cb;

	m_Instance = gcnew CSharpClass();
	
	m_Instance->MyEvent += MAKE_DELEGATE(EventHandler<MyEventArgs^>, OnMyEvent);
}

void CSharpClassCLR::OnMyEvent(Object^ sender, MyEventArgs^ e)
{
	Console::WriteLine("ManagedCLI: CSharpClassCLR::OnMyEvent");
	
	if(m_pCallback)
	{
		m_pCallback->OnMyEvent(marshal_as<wstring>(e->Str), CSharpClassMoodCPP(e->Enum));
	}
}

wstring CSharpClassCLR::myMethod(int arg)
{
	Console::WriteLine("ManagedCLI: CSharpClassCLR::myMethod");
	return marshal_as<wstring>(m_Instance->myMethod(arg));
}

void CSharpClassCLR::FireMyEvent()
{
	Console::WriteLine("ManagedCLI: CSharpClassCLR::FireMyEvent");
	m_Instance->FireMyEvent();
}