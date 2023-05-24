#include "functions.h++"
#include "constants.h++"
#include "internalfunctions.h++"
//#include "classes.h++"

#include "C:/Users/gogop/AppData/Local/node-gyp/Cache/18.13.0/include/node/node.h"
#include <windows.h>


void Initialize(v8::Local<v8::Object> exports) {
    v8::Isolate *isolate = v8::Isolate::GetCurrent();
    NODE_SET_METHOD(exports, "createWindow", CreateWindowAddon);
	NODE_SET_METHOD(exports, "showWindow", ShowWindowAddon);
	NODE_SET_METHOD(exports, "hideWindow", HideWindowAddon);
    NODE_SET_METHOD(exports, "runMessageLoop", RunMessageLoopAddon);
    NODE_SET_METHOD(exports, "registerClass", RegisterClassNODE);
	NODE_SET_METHOD(exports, "getErr", GetLastErrorErr);
	NODE_SET_METHOD(exports, "msgBox", MSGBOX);
    InPlaceMerge(exports,GetConstants());
}

NODE_MODULE(addon, Initialize)