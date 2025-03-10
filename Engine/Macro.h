#pragma once

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=nullptr; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=nullptr; } }

#if defined( DEBUG ) || defined( _DEBUG )
#define ERROR_BOX(ERR_MSG) \
    do { \
        wchar_t buffer[256]; \
        swprintf_s(buffer, L"%s\n\nLocation: %s\nLine: %d", ERR_MSG, __FILEW__, __LINE__); \
        MessageBoxW(nullptr, buffer, L"Error", MB_OK | MB_ICONERROR); \
    } while(0)
// ���� �˻� �� void ��ȯ �� �޽��� ��� ��ũ��
#define CHECK_ERROR_VOID(CON, ERR_MSG) if((CON)) {ErrorBox(ERR_MSG); return;}
// ���� �˻� �� nullptr ��ȯ �� �޽��� ��� ��ũ��
#define CHECK_ERROR_NULL(CON, ERR_MSG) if((CON)) {ErrorBox(ERR_MSG); return nullptr; }
#define DEBUGPRINT		printf
#define DEBUGPRINTW		wprintf
#else
#define Assert(b)
#define ErrorBox(ERR_MSG)
// ���� �˻� �� void ��ȯ ��ũ��
#define CHECK_ERROR_VOID(CON, ERR_MSG) if((CON)) return;
// ���� �˻� �� nullptr ��ȯ ��ũ��
#define CHECK_ERROR_NULL(CON, ERR_MSG) if((CON)) return nullptr;
#define DEBUGPRINT		__noop
#define DEBUGPRINTW		__noop
#endif //DEBUG || _DEBUG
