#ifndef _AYEER_H
#define _AYEER_H 1
#pragma once
#include <Windows.h>
#include <WinUser.h>
#include "Gbk2Utf8.h"
#include "cJSON.h"


extern CGbk2Utf8 iconv;//编码转换;

/****************************************************/


POINT mouse_pos();  /** 获取鼠标坐标 */
void mouse_move(int x, int y); /** 移动鼠标 */

void mouse_down();  /** 左鼠标按下 */
void mouse_up();  /** 左鼠标弹起 */
void rmouse_down();  /** 右鼠标按下 */
void rmouse_up();  /** 右鼠标弹起 */
void click();  /** 左单击鼠标 */
void rclick();  /** 模拟鼠标右击 */

/************************************************************/
void key_event(char* key); /** 键盘操作 */


/************************************************************/


/************************************************************/
/*窗口操作*/
HWND get_hWnd_cursor_pos(); //通过鼠标坐标获取窗口
void message_box(char * msg);
HWND find_window(char * name, int mode);// mode 1:接classname 查找
                                        // mode 2:接title 查找
										// mode 3:接classname 模糊查找
										// mode 4:接title 模糊查找

void select_window(HWND hWnd);//选择窗口 将窗口离到最上层
void get_all_window();//获到所有桌面窗口
/************************************************************/

void show_window_rect(int left, int top, int right, int bottom, int lineWidth); /** 显示矩形 */
void sleep(int milli_second);
/************************************************************/



/************************************************************/
BOOL save_jpg_file(HWND hWnd, int x, int y, int nWidht, int nHeight, LPCTSTR lpszPath);//保存为图片



/************************************************************/
//执行程序
void shell_execute(char *cmd);

/************************************************************/
//utils

#endif
