#pragma once

#include "../Runtime/public/i_var_list.h"
#include "../Runtime/public/var_list.h"

class App
{
	// ¼ÆÊ±Æ÷
	int m_width;
	int m_height;
	bool m_initok;
public:
	App()
	{ 
		m_initok = false;
	}
	void Init(const char* workpath, const IVarList& args, int screen_width, int screen_height, float scale);

	void OnFrame();
    
    void OnRender();

	void Shutdown();

	bool OnMsg(unsigned int msg, size_t param1, size_t param2, int& result);

    void OnInput(const char* utf8);

	void OnShowKeyboard(int height = 400.0f);

	void OnHideKeyboard();
    
	static App& Inst()
	{
		static App s_app;
		return s_app;
	}

	const char* GetFocusText(char* buf, size_t size);

};