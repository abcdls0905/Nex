#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __ANDROID__
#include <android/log.h>
#define  LOG_TAG    "fm"
#endif

#ifdef FX_SYSTEM_WINDOWS
#include "../Runtime/system/win_encoding.h"
#include "../Runtime/system/win_string.h"
#endif // FX_SYSTEM_WINDOWS

#ifdef FX_SYSTEM_LINUX
#include "../Runtime/system/linux_encoding.h"
#include "../Runtime/system/linux_string.h"
#endif // FX_SYSTEM_LINUX

#ifdef FX_SYSTEM_IOS
#include "../Runtime/system/ios_encoding.h"
#include "../Runtime/system/ios_string.h"
#endif // FX_SYSTEM_IOS


#include "app.h"
#include "../Runtime/public/i_var_list.h"

ASSERTION_FAIL_DEFINED;

#define UI_WIDTH 1024
#define UI_HEIGHT 768

static void show_fatal_error(const char* info)
{
#ifdef _WIN32
	MessageBoxA(NULL, info, "fatal error", MB_OK | MB_ICONERROR);
#endif
}

#ifndef _WIN32
	#ifdef __ANDROID__
		bool _custom_trace(void* context, const char* info)
		{
			#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
			LOGI(info, "%s", info);
			return true;
		}
	#else
		bool _custom_trace(void* context, const char* info)
		{
			::printf(info);
			::printf("\n");
			return true;
		}
	#endif
#endif

void App::Init(const char* workpath, const IVarList& args, int screen_width, int screen_height, float scale)
{
	if(m_initok)
		return ;
	m_width = screen_width;
	m_height = screen_height;
}

#ifndef _WIN32
extern void hideKeyboard();
void App::OnInput(const char* utf8)
{
    int result;
    wchar_t wtext[256];
    Port_UTF8ToWideStr(utf8, wtext, sizeof(wtext));
    for(int i = 0; wtext[i]!=0; i++)
    {
        if(wtext[i] == '\n' && wtext[i+1] == 0)
        {
            hideKeyboard();
            return;
        }
        OnMsg(WM_CHAR, wtext[i], 0, result);
    }
}
#endif

void App::OnFrame()
{
	
}

void App::OnRender()
{
}

bool App::OnMsg(unsigned int msg, size_t param1, size_t param2, int& result)
{
	return false;
}

void App::Shutdown()
{
}

void App::OnShowKeyboard(int height)
{
}

void App::OnHideKeyboard()
{
}

const char* App::GetFocusText(char* buf, size_t size)
{
	return nullptr;
}