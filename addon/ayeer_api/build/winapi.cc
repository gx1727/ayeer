#include "ayeer.h"
#include <atlimage.h>

/*******************************************************/
//������

/** ��ȡ������� */
POINT mouse_pos()
{
	POINT pnt;
	::GetCursorPos(&pnt);
	return pnt;
}

/** �ƶ���� */
void mouse_move(int x, int y)
{
	::SetCursorPos(x, y);
}

/** ����갴�� */
void mouse_down()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//�������
}

/** ����굯�� */
void mouse_up()
{
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//�ɿ����
}

/** ����갴�� */
void rmouse_down()
{
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);//�����Ҽ�
}

/** ����굯�� */
void rmouse_up()
{
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);//�ɿ��Ҽ�
}

/** �󵥻���� */
void click()
{
	mouse_down();//�������
	mouse_up();//�ɿ����
}

/** ģ������һ� */
void rclick(void)
{
	rmouse_down();//�����Ҽ�
	rmouse_up();//�ɿ��Ҽ�
}


/************************************************************/
/** ���̲��� */
void key_event(char* key)
{
	if (key == "ctrl+a") {
		keybd_event(VK_CONTROL, 0, 0, 0);
		keybd_event('A', 0, 0, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
		keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
	}
	else if (key == "ctrl+s") {
		keybd_event(VK_CONTROL, 0, 0, 0);
		keybd_event('S', 0, 0, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
		keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
	}
	else if (key == "ctrl+c") {
		keybd_event(VK_CONTROL, 0, 0, 0);
		keybd_event('C', 0, 0, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
		keybd_event('C', 0, KEYEVENTF_KEYUP, 0);
	}
	else if (key == "ctrl+v") {
		keybd_event(VK_CONTROL, 0, 0, 0);
		keybd_event('V', 0, 0, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
		keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
	}
	else if (key == "left") {
		keybd_event(VK_LEFT, 0, 0, 0);
		keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
	}
	else if (key == "up") {
		keybd_event(VK_UP, 0, 0, 0);
		keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
	}
	else if (key == "right") {
		keybd_event(VK_RIGHT, 0, 0, 0);
		keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
	}
	else if (key == "down") {
		keybd_event(VK_DOWN, 0, 0, 0);
		keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
	}
	else {

		int length = strlen(key);
		for (int i = 0; i < length; i++) {
			int ch = key[i];


			if (ch >= 'a' && ch <= 'z') {
				ch -= 32;
			}
			else if (ch >= 'A' && ch <= 'Z') {
				keybd_event(VK_CAPITAL, 0, 0, 0);
			}
			if (key[i] == '.') {
				ch = VK_DECIMAL;
			}
			if (key[i] == '-') {
				ch = VK_SUBTRACT;
			}
			keybd_event(ch, 0, 0, 0);
			keybd_event(ch, 0, KEYEVENTF_KEYUP, 0);

			if (key[i] >= 'A' && key[i] <= 'Z') {
				keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP, 0);
			}
		}
	}
}




/************************************************************/




/** ��ʾ���� */
void show_window_rect(int left, int top, int right, int bottom, int lineWidth)
{
	HWND DeskHwnd = ::GetDesktopWindow();    //ȡ��������   
	HDC DeskDC = ::GetWindowDC(DeskHwnd);     //ȡ�������豸����   
	int oldRop2 = SetROP2(DeskDC, R2_NOTXORPEN);


	left = left > 0 ? left : 0;
	top = top > 0 ? top : 0;

	HPEN newPen = ::CreatePen(0, lineWidth, RGB(255, 0, 0));    //�����»���,����DeskDC   
	HGDIOBJ oldPen = ::SelectObject(DeskDC, newPen);
	::Rectangle(DeskDC, left, top, right, bottom);  //��ָʾ������Χ��ʾ��˸����   

																		//::Beep(100,100);   
	Sleep(4000);    //������˸ʱ����   
	::Rectangle(DeskDC, left, top, right, bottom);

	::SetROP2(DeskDC, oldRop2);
	::SelectObject(DeskDC, oldPen);
	::DeleteObject(newPen);
	::ReleaseDC(DeskHwnd, DeskDC);
	DeskDC = NULL;
}


void sleep(int milli_second)
{
	Sleep(milli_second);
}

/** ͨ����������ȡ���� */
HWND get_hWnd_cursor_pos()
{
	HWND hWnd;
	POINT pnt;
	::GetCursorPos(&pnt);                //ȡ���������   
	HWND UnHwnd = ::WindowFromPoint(pnt);    //ȡ�����ָ�봦���ھ��   

	hWnd = UnHwnd;
	HWND grayHwnd = ::GetWindow(hWnd, GW_CHILD);
	RECT tempRc;
	BOOL bFind = FALSE;
	while (grayHwnd)
	{
		::GetWindowRect(grayHwnd, &tempRc);
		if (::PtInRect(&tempRc, pnt))
		{
			bFind = TRUE;
			break;
		}
		else
		{
			grayHwnd = ::GetWindow(grayHwnd, GW_HWNDNEXT);
		}

	}//while   
	if (bFind == TRUE)
	{
		bFind = FALSE;
		hWnd = grayHwnd;
	}
	return hWnd;
}



void message_box(char * msg)
{
	MessageBox(NULL, msg, "��ʾ", MB_OK);
}

// mode 0:��classname ����
// mode 1:��title ����
// mode 3:��classname ģ������
// mode 4:��title ģ������

HWND find_window(char * name, int mode)
{
	if (mode == 1) {
		return ::FindWindow(name, NULL);
	}
	else if (mode == 2) {
		return ::FindWindow(NULL, name);
	}
	else {
		if (mode == 3) {

		}
		else if (mode == 4) {

		}
	}
}

//ѡ�񴰿� �������뵽���ϲ�
void select_window(HWND hWnd)
{
	::SwitchToThisWindow(hWnd, TRUE);
}

//���������洰��
void get_all_window() 
{
}
/*******************************************************/

//����ΪͼƬ
BOOL save_jpg_file(HWND hWnd, int x, int y, int nWidht, int nHeight, LPCTSTR lpszPath)
{

	HWND hDesktop = ::GetDesktopWindow();
	if (!hDesktop) {
		return FALSE;
	}
	if (NULL == hWnd)
	{
		hWnd = hDesktop;
	}
	RECT rect;
	::GetWindowRect(hWnd, &rect);

	HDC hSrcDC = ::GetWindowDC(hWnd);
	if (!hSrcDC) {
		return FALSE;
	}

	HDC hMemDC = ::CreateCompatibleDC(hSrcDC);
	if (!hMemDC) {
		return FALSE;
	}

	HBITMAP hBitmap = ::CreateCompatibleBitmap(hSrcDC, nWidht, nHeight);
	if (!hBitmap) {
		return FALSE;
	}

	HBITMAP hOldBitmap = (HBITMAP)::SelectObject(hMemDC, hBitmap);
	::BitBlt(hMemDC, -x, -y, nWidht + x, nHeight + y, hSrcDC, 0, 0, SRCCOPY | CAPTUREBLT);

	CImage imgCreate;
	imgCreate.Attach(hBitmap);
	imgCreate.Save(lpszPath);
	imgCreate.Destroy();

	::SelectObject(hMemDC, hOldBitmap);
	::DeleteObject(hBitmap);
	::DeleteDC(hMemDC);
	::ReleaseDC(hWnd, hSrcDC);

	return TRUE;
}


/************************************************************/
//ִ�г���
void shell_execute(char *cmd)
{
	ShellExecute(NULL, _T("open"), cmd, _T(""), _T(""), SW_SHOW);
}