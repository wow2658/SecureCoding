// main __asm { 시작지점에 브레이크 걸고 어셈블리에서 시작 주소를 본다
// 004115C9 ~ 004115FF인것을 확인 (임의주소확인 꺼야 가능)
// 영역을 복사하고 쓸대없는 것들 덜어내기
// 
// 
//0x004115C9  55 8b ec 83 ec 48 c6 45 f4  U����H�E�
//0x004115D2  63 c6 45 f5 61 c6 45 f6 6c  c�E�a�E�l
//0x004115DB  c6 45 f7 63 c6 45 f8 00 6a  �E�c�E�.j
//0x004115E4  01 8d 45 f4 50 a1 00 80 41.�E�P�.�A
//0x004115ED  00 ff d0 6a 01 a1 fc 80 41.��j.���A
//0x004115F6  00 ff d0 5f 5e 5b 8b e5 5d.��_ ^ [��]
//0x004115FF  c3 cc cc cc cc cc cc cc cc (여기는 무시)


//55 8b ec 83 ec 48 c6 45 f4
//63 c6 45 f5 61 c6 45 f6 6c
//c6 45 f7 63 c6 45 f8 00 6a
//01 8d 45 f4 50 a1 00 80 41
//00 ff d0 6a 01 a1 fc 80 41
//00 ff d0 5f 5e 5b 8b e5 5d
// 
// a1부분이 중요하므로 따로 분류해두기

//55 8b ec 83 ec 48 c6 45 f4
//63 c6 45 f5 61 c6 45 f6 6c
//c6 45 f7 63 c6 45 f8 00 6a
//01 8d 45 f4 50 
// a1 00 80 41 00         (여기가 WinExec)
//ff d0 6a 01 
// a1 fc 80 41 00		  (여기가 exit)
//ff d0 5f 5e 5b 8b e5 5d

// 싹다 앞에 \x붙여주고 줄마다 ""으로 묶기

//"\x55 \x8b \xec \x83 \xec \x48 \xc6 \x45 \xf4"
//"\x63 \xc6 \x45 \xf5 \x61 \xc6 \x45 \xf6 \x6c"
//"\xc6 \x45 \xf7 \x63 \xc6 \x45 \xf8 \x00 \x6a"
//"\x01 \x8d \x45 \xf4 \x50"
//"\xa1 \x00 \x80 \x41 \x00"
//"\xff \xd0 \x6a \x01"
//"\xa1 \xfc \x80 \x41 \x00"
//"\xff \xd0 \x5f \x5e \x5b \x8b \xe5 \x5d"

#include <Windows.h>

void main(void)
{
	char shellcode[] = { "\x55 \x8b \xec \x83 \xec \x48 \xc6 \x45 \xf4"
"\x63 \xc6 \x45 \xf5 \x61 \xc6 \x45 \xf6 \x6c"
"\xc6 \x45 \xf7 \x63 \xc6 \x45 \xf8 \x00 \x6a"
"\x01 \x8d \x45 \xf4 \x50"
"\xa1 \x00 \x80 \x41 \x00"  //0 41 80 00h
"\xff \xd0 \x6a \x01"
"\xa1 \xfc \x80 \x41 \x00" // 0 41 80 FCh
"\xff \xd0 \x5f \x5e \x5b \x8b \xe5 \x5d" };

	
	//WinExec("", 1); // 낚시용도. 이걸 한번 호출해서 주소를 딴다음 a1친구들 수정하자. 0 41 80 00h
	//exit(0);		// 알아냈으니 주석처리. 0 41 80 FCh
	int *pshell = (int*)shellcode;
	__asm
	{
		jmp pshell
	}
}