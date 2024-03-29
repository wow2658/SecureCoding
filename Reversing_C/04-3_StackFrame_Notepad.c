#include <stdio.h>
#include <stdlib.h>

void RunNotepad(void)
{
	system("notepad.exe"); // 리턴어드레스를 조작해서 메모장을 띄우려고 했던 코드
}

void TestFunc(int nParam)
{
	int nData = 5;
	puts("TestFunc()");
	*(&nData + 2) = (int)RunNotepad;  // 프로젝트 속성 \ 구속 속성 \ C/C++ \ 고급 \ 특정 경고 사용 안 함 (4700;4789) 후 가능
	//*(&nData + 2) += 14;  // 리턴어드레스를 조작해서 puts("After") 를 스킵해버린다.
}

// return address의 중요성을 알아보는 취지의 코드인데 지금 환경에서는 작동이 안된다.
int main(void)
{
	puts("Begin");
	puts("Before");
	TestFunc(10);
	puts("After"); 
	puts("End");
	return 0;
}