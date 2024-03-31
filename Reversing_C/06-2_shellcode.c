// main __asm { 시작지점에 브레이크 걸고 어셈블리에서 시작 주소를 본다
// 004115C0 ~ 004115FF인것을 확인 (임의주소확인 꺼야 가능)
// 영역을 복사하고 쓸대없는 것들 덜어내기
// 
// 
//0x004115C0  55 8b ec 83 ec 40 53  U����@S
//0x004115C7  56 57 55 8b ec 83 ec  VWU����
//0x004115CE  48 c6 45 f4 63 c6 45  H�E�c�E
//0x004115D5  f5 61 c6 45 f6 6c c6  �a�E�l�
//0x004115DC  45 f7 63 c6 45 f8 00  E�c�E�.
//0x004115E3  6a 01 8d 45 f4 50 a1  j.�E�P�
//0x004115EA  00 80 41 00 ff d0 6a.�A.��j
//0x004115F1  01 a1 fc 80 41 00 ff.���A.�
//0x004115F8  d0 5f 5e 5b 8b e5 5d  �_ ^ [��]
//0x004115FF 여기는 필요없음



//"\x55\x8b\xec\x83\xec\x40\x53"
//"\x56\x57\x55\x8b\xec\x83\xec"
//"\x48\xc6\x45\xf4\x63\xc6\x45"
//"\xf5\x61\xc6\x45\xf6\x6c\xc6"
//"\x45\xf7\x63\xc6\x45\xf8\x00"
//"\x6a\x01\x8d\x45\xf4\x50\xa1"
//"\x00\x80\x41\x00\xff\xd0\x6a" // a1 주목		winExec 00418000
//"\x01\xa1\xfc\x80\x41\x00\xff" //	리틀엔디안  exit    004180fc
//"\xd0\x5f\x5e\x5b\x8b\xe5\x5d"

#include <Windows.h>

void main(void)
{
	char shellcode[] =
	{
"\x55\x8b\xec\x83\xec\x40\x53"
"\x56\x57\x55\x8b\xec\x83\xec"
"\x48\xc6\x45\xf4\x63\xc6\x45"
"\xf5\x61\xc6\x45\xf6\x6c\xc6"
"\x45\xf7\x63\xc6\x45\xf8\x00"
"\x6a\x01\x8d\x45\xf4\x50\xa1"
"\x34\x80\x41\x00\xff\xd0\x6a"
"\x01\xa1\xf0\x80\x41\x00\xff"
"\xd0\x5f\x5e\x5b\x8b\xe5\x5d"

	};


	//WinExec("", 1); // 낚시용도. 이걸 한번 호출해서 주소를 딴다음 a1친구들 수정하자. 00418000-> 0418034h
	//exit(0);		// 알아냈으니 주석처리. 004180fc->04180F0h
	int* pshell = (int*)shellcode;
	__asm
	{
		jmp pshell
	}
}