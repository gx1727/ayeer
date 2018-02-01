// hello.cc
#include <node.h>
#include <string.h>

#include ".\build\ayeer.h"

CGbk2Utf8 iconv;//编码转换;

namespace ayeer {

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;


	void hello2Method(const FunctionCallbackInfo<Value>& args) {
		char buff[1024];

		mouse_move(130, 130);
		Sleep(10);
		click();
		key_event("hhhhhh");
		/*
		Sleep(500);
		mouse_down();
		Sleep(500);
		move_mouse(230, 230);
		mouse_up();*/
		HWND hWnd = get_hWnd_cursor_pos();
		memset(buff, '\0', 1024);

		char* utf8buff = iconv.GetBufUtf8();
		iconv.gbk2utf8("abc在有有`1234567%$@!~~!@%~!@#$%^&*(~！·#￥%……—", utf8buff);

		POINT pnt = mouse_pos();
		sprintf(buff, "%d x:%d y:%d str:%s", (int)hWnd, pnt.x, pnt.y, utf8buff);

		//show_window_rect(10, 10, 800, 800, 2);
		save_jpg_file(NULL, 10, 10, 800, 800, "test.jpg");

		Isolate* isolate = args.GetIsolate();
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, buff));
	}

	/** 主入口 */
	void main_do(const FunctionCallbackInfo<Value>& args) {
		char ret[10240];
		memset(ret, '\0', 10240);

		Isolate* isolate = args.GetIsolate();
		String::Utf8Value cmd(args[0]->ToString());
		String::Utf8Value param(args[1]->ToString());

		if (strcmp(*cmd, "mouse_move") == 0) {
			cJSON *json;

			json = cJSON_Parse(*param);
			if (json) {
				cJSON * pSub_x = NULL;
				cJSON * pSub_y = NULL;
				pSub_x = cJSON_GetObjectItem(json, "x");
				pSub_y = cJSON_GetObjectItem(json, "y");
				if (NULL != pSub_x && NULL != pSub_y) {
					int x = pSub_x->valueint;
					int y = pSub_y->valueint;

					mouse_move(x, y);
				}
				cJSON_Delete(json);
			}
		}
		else if (strcmp(*cmd, "shell_execute") == 0) {
			char param_bgk[1024];
			memset(param_bgk, '\0', 1024);
			iconv.utf82gbk(*param, param_bgk);
			shell_execute(param_bgk);
	
		}
		else if (strcmp(*cmd, "message_box") == 0) {
			char param_bgk[1024];
			memset(param_bgk, '\0', 1024);
			iconv.utf82gbk(*param, param_bgk);
			message_box(param_bgk);
		}
		else if (strcmp(*cmd, "sleep") == 0) {
			int milli_second = atoi(*param);
			sleep(milli_second);
		}
		else if (strcmp(*cmd, "find_window") == 0) {
			cJSON *json;

			json = cJSON_Parse(*param);
			if (json) {
				cJSON * pSub_name = NULL;
				cJSON * pSub_mode = NULL;
				pSub_name = cJSON_GetObjectItem(json, "name");
				pSub_mode = cJSON_GetObjectItem(json, "mode");
				if (NULL != pSub_name && NULL != pSub_mode) {
					char *name = pSub_name->valuestring;
					int mode = pSub_mode->valueint;

					char param_bgk[1024];
					memset(param_bgk, '\0', 1024);
					iconv.utf82gbk(name, param_bgk);

					HWND hWnd = find_window(param_bgk, mode);
					sprintf(ret, "%d", (int)hWnd);
				}
				cJSON_Delete(json);
			}
		}
		else if (strcmp(*cmd, "select_window") == 0) {
			int hWnd = atoi(*param);
			select_window((HWND)hWnd);
		}
		

		args.GetReturnValue().Set(String::NewFromUtf8(isolate, ret));
	}


	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "do", main_do);
		NODE_SET_METHOD(exports, "hello2", hello2Method);
	}

	NODE_MODULE(addon, init)

}  // namespace demo