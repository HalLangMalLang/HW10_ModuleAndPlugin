#include "Temporary.h"

void FTemporaryModule::StartupModule()
{
    // 플러그인이 로드될 때 로그를 남기거나 초기화하는 코드를 여기에 적습니다.
}

void FTemporaryModule::ShutdownModule()
{
    // 플러그인이 꺼질 때 메모리를 해제하는 코드를 여기에 적습니다.
}

IMPLEMENT_MODULE(FTemporaryModule, Temporary);