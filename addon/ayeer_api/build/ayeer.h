#ifndef _AYEER_H
#define _AYEER_H 1
#pragma once
#include <Windows.h>
#include <WinUser.h>
#include "Gbk2Utf8.h"
#include "cJSON.h"


extern CGbk2Utf8 iconv;//����ת��;

/****************************************************/


POINT mouse_pos();  /** ��ȡ������� */
void mouse_move(int x, int y); /** �ƶ���� */

void mouse_down();  /** ����갴�� */
void mouse_up();  /** ����굯�� */
void rmouse_down();  /** ����갴�� */
void rmouse_up();  /** ����굯�� */
void click();  /** �󵥻���� */
void rclick();  /** ģ������һ� */

/************************************************************/
void key_event(char* key); /** ���̲��� */


/************************************************************/


/************************************************************/
/*���ڲ���*/
HWND get_hWnd_cursor_pos(); //ͨ����������ȡ����
void message_box(char * msg);
HWND find_window(char * name, int mode);// mode 1:��classname ����
                                        // mode 2:��title ����
										// mode 3:��classname ģ������
										// mode 4:��title ģ������

void select_window(HWND hWnd);//ѡ�񴰿� �������뵽���ϲ�
void get_all_window();//���������洰��
/************************************************************/

void show_window_rect(int left, int top, int right, int bottom, int lineWidth); /** ��ʾ���� */
void sleep(int milli_second);
/************************************************************/



/************************************************************/
BOOL save_jpg_file(HWND hWnd, int x, int y, int nWidht, int nHeight, LPCTSTR lpszPath);//����ΪͼƬ



/************************************************************/
//ִ�г���
void shell_execute(char *cmd);

/************************************************************/
//utils

#endif
