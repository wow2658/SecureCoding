#include <windows.h>

// x86
// 프로젝트 속성 \ 링커 \ 고급 \ 임의 기준 주소(아니요), DEP(아니요)
//				 \ C/C++ \ 코드생성 \ 보안 검사(보안 검사 사용 안 함 /GS-)
void main(void)
{
	__asm
	{
		push		 ebp
		mov			 ebp, esp
		sub		     esp, 48h
		mov          byte ptr[ebp-0Ch], 63h		 //c
		mov          byte ptr[ebp-0Bh], 61h		 //a
		mov          byte ptr[ebp-0Ah], 6Ch		 //l
		mov          byte ptr[ebp-9], 63h		 //c
		mov          byte ptr[ebp-8], 0			 //\0
		push         1
		lea          eax, [ebp-0Ch]
		push         eax
		mov          eax, WinExec
		call         eax
		push         1
		mov          eax, exit
		call         eax
	}
}

//_declspec(naked) void main(void)
//{
//	char szBuffer[5];
//	szBuffer[0] = 'c';
//	szBuffer[1] = 'a';
//	szBuffer[2] = 'l';
//	szBuffer[3] = 'c';
//	szBuffer[4] = '\0';
//	WinExec(szBuffer, 1);
//	exit(0);
//}