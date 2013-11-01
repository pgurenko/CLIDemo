// CLIDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

#include "CSharpClassCPP.h"

class CSharpCallbackClass : public ICSharpClassCPPCallback
{
public:
	virtual void OnMyEvent(wstring str, CSharpClassMoodCPP mood)
	{
		wstring strMood;
		switch(mood)
		{
			case CSCM_Sad:
				strMood = L"Sad";
				break;
			case CSCM_Happy:
				strMood = L"Happy";
				break;
			default:
				strMood = L"Undefined";
				break;
		}
			
		printf("\n<< MyEvent received from managed code. Greeting: \"%ls\" Mood: %ls\n", str.c_str(), strMood.c_str());
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	printf("CLI demo: test of unmanaged wrapper for managed code\n");

	printf("\n>> Unmanaged: creating CSharpClassCPP...\n");

	CSharpCallbackClass* pCB = new CSharpCallbackClass();

	CSharpClassCPP* pCSClass = CSharpClassCPP::CreateInstance(pCB);

	printf("\n>> Unmanaged: invoking native myMethod...\n");

	wstring str = pCSClass->myMethod(1234);

	printf("Unmanaged: CSharpClassCPP myMethod returned \"%ls\"\n", str.c_str());

	printf("\n>> Unmanaged: firing event from unmanaged code...\n");

	pCSClass->FireMyEvent();

	printf("\nPress any key to continue...\n");

	_getch();

	delete pCB;

	return 0;
}