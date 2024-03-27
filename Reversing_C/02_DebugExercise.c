// 프로젝트 속성 \ 구성 속성 \ C/C++ \ 일반 \ SDL검사(아니요) : 이렇게하면 학습을 위해 strcpy의 보안위험경고를 꺼버릴 수 있다.
#include <stdio.h>
#include <Windows.h>
#include <process.h>

//	포지션 브레이크말고 데이터 브레이크를 걸어보자
// 13줄 {에 포지션 브레이크 걸고 디버그 모드 실행
// Alt+F9로 중단점 창 열기
// 중단점 창의 새로 만들기 \ 데이터 중단점 \ &g_nSize (4바이트) 입력
// 일부러 A대문자 폭격해서 크래시 (낸다음 g_nSize 조사식으로 놓기)
// 데이터 중단점 적중 확인 : 4바이트에 벗어났다는 것을 감지해준것이다. 
// 이때 gets함수에서 죽었다고 띄워주는데 이거 말고 호출스택을 보자. 
// 문제가 된 gets함수를 43줄에서 호출했다는 정보를 알 수 있다.
char g_szData[12] = { "Empty" };
int g_nSize = 12;

void ThreadFunction(void* pParam)
{
	char szBuffer[12];
	while (1)
	{
		Sleep(1000);
		strcpy(szBuffer, g_szData);
		printf("스레드에서 출력하는 메세지 : %s\n", szBuffer);
		putchar(szBuffer[g_nSize]);
		putchar('\n');

		if (strcmp(szBuffer, "exit") == 0)
		{
			break;
		}
	}
	puts("스레드 종료");
}

int main(void)
{
	_beginthread(ThreadFunction, 0, NULL);

	while (strcmp(g_szData, "exit") != 0)
	{
		printf("문자열을 입력하세요 : ");
		gets(g_szData);
	}
	Sleep(1200);
	puts("응용 프로그램 종료");
	return 0;
}
