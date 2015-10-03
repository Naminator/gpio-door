#pragma once

#ifndef PATH_MAX
#define PATH_MAX MAX_PATH
#endif

#ifdef _UNICODE
    typedef std::wstring tstring;
    typedef wchar_t tchar;
#define TEXT(s) L##s
#else
    typedef std::string tstring;
    typedef char tchar;
#define TEXT(s) s
#endif

#define DAEMON_NAME "garagedoord"
