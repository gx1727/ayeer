#pragma once

class CGbk2Utf8
{
public:
	CGbk2Utf8();
	~CGbk2Utf8();
	int zzUnicode2gbkbase[65535]; //65535
	int zzGbk2utf8base[65535];

	char g_iconv_tmp_utf8[1024];//±àÂë×ª»»temp  1048576
	char g_iconv_tmp_gbk[1024];//±àÂë×ª»»temp

public:
	int utf82unicode(char *utf8char, int* unicode, int *len, int leaveLen);
	int utf82gbk(char *strutf8, char *strgbk);
	int gbk2utf8(char *strgbk, char *strutf8);

	int u2g(const char *strutf8, char *strgbk, int gLen);
	int g2u(const char *strgbk, char *strutf8, int uLen);

	char * GetBufUtf8();
	char * GetBufGbk();
};

