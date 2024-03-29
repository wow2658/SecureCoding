#include <stdio.h>
#include <conio.h>


__declspec(naked) void TestFunc(int nParam)
{
	__asm // Function Prologue
	{
		push		ebp			// (Extended) Base Pointer를
		mov			ebp, esp	// (Extended) Stack Pointer 높이까지 올리고
		sub			esp, 10h	// esp를 10h(16진수로16바이트) 빼서 올린다. 
	}
	int nData;
	nData = 10;
	printf("TestFunc(%d)\n", nParam);
	__asm // Function Epilogue
	{
		mov			esp, ebp	// 올렸던 esp를 다시 제자리로 되돌리고
		pop			ebp			// 자동변수 반환하듯 ebp 빼버린다.
		ret
	}
}

int main(void)
{
	TestFunc(5);
	__asm
	{
		push	5				// 인수로 5
		call	TestFunc		// 함수 부르고
		add		esp, 4h			// 인수로 int 5를 줘서 4바이트 만큼 내려준듯 하다. (스택이 감소했다는 소리)
	}
	return 0;
}