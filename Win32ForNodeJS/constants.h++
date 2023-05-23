


#pragma once

#include "C:/Users/gogop/AppData/Local/node-gyp/Cache/18.13.0/include/node/node.h"
#include <windows.h>

#pragma endregion

void
addConstant(v8::Local<v8::Object> &object, v8::Local<v8::Value> key, v8::Local<v8::Value> value, v8::Isolate *isolate) {
    object->Set(
            isolate->GetCurrentContext(),
            key,
            value
    );
}


v8::Local<v8::Object> GetConstants() {
    v8::Isolate *isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Object> constants = v8::Object::New(isolate);
    v8::Local<v8::Object> Styles = v8::Object::New(isolate);
    const std::pair<std::string, long long> StylePairs[] = {
            {"Overlapped",               WS_OVERLAPPED},
            {"Popup",                    WS_POPUP},
            {"Child",                    WS_CHILD},
            {"Minimized",                WS_MINIMIZE},
            {"Visible",                  WS_VISIBLE},
            {"Disables",                 WS_DISABLED},
            {"ClipSiblings",             WS_CLIPSIBLINGS},
            {"ClipChildren",             WS_CLIPCHILDREN},
            {"Maximized",                WS_MAXIMIZE},
            {"Caption",                  WS_CAPTION},
            {"Border",                   WS_BORDER},
            {"DlgFrame",                 WS_DLGFRAME},
            {"VScroll",                  WS_VSCROLL},
            {"HScroll",                  WS_HSCROLL},
            {"SysMenu",                  WS_SYSMENU},
            {"ThickFrame",               WS_THICKFRAME},
            {"Group",                    WS_GROUP},
            {"TabStop",                  WS_TABSTOP},
            {"MinimizeBox",              WS_MINIMIZEBOX},
            {"MaximizeBox",              WS_MAXIMIZEBOX},
            {"Tiled",                    WS_TILED},
            {"IconIC",                   WS_ICONIC},
            {"SizeBox",                  WS_SIZEBOX},
            {"TiledWindow",              WS_TILEDWINDOW},
            {"OverLappedWindow",         WS_OVERLAPPEDWINDOW},
            {"PopupChild",               WS_POPUPWINDOW},
            {"ChildWindow",              WS_CHILDWINDOW},
            {"ExtendedDLGModalFrame",    WS_EX_DLGMODALFRAME},
            {"ExtendedNoParentNotify",   WS_EX_NOPARENTNOTIFY},
            {"ExtendedTopMost",          WS_EX_TOPMOST},
            {"ExtendedAcceptFiles",      WS_EX_ACCEPTFILES},
            {"ExtendedTransparent",      WS_EX_TRANSPARENT},
            {"ExtendedMDIChild",         WS_EX_MDICHILD},
            {"ExtendedToolWindow",       WS_EX_TOOLWINDOW},
            {"ExtendedWindowEdge",       WS_EX_WINDOWEDGE},
            {"ExtendedClientEdge",       WS_EX_CLIENTEDGE},
            {"ExtendedContextHelp",      WS_EX_CONTEXTHELP},
            {"ExtendedRight",            WS_EX_RIGHT},
            {"ExtendedLeft",             WS_EX_LEFT},
            {"ExtendedRTLReading",       WS_EX_RTLREADING},
            {"ExtendedLTRReading",       WS_EX_LTRREADING},
            {"ExtendedLeftScrollBar",    WS_EX_LEFTSCROLLBAR},
            {"ExtendedRightScrollBar",   WS_EX_RIGHTSCROLLBAR},
            {"ExtendedControlParent",    WS_EX_CONTROLPARENT},
            {"ExtendedStaticEdge",       WS_EX_STATICEDGE},
            {"ExtendedAppWindow",        WS_EX_APPWINDOW},
            {"ExtendedLayered",          WS_EX_LAYERED},
            {"ExtendedNoInheritLayout",  WS_EX_NOINHERITLAYOUT},
            {"ExtendedLayoutRTL",        WS_EX_LAYOUTRTL},
            {"ExtendedComposited",       WS_EX_COMPOSITED},
            {"ExtendedNoActive",         WS_EX_NOACTIVATE},
            {"ExtendedOverLappedWindow", WS_EX_OVERLAPPEDWINDOW},
            {"ExtendedPaletteWindow",    WS_EX_PALETTEWINDOW}
    };
    for (const auto &x: StylePairs) {
        addConstant(Styles, v8::String::NewFromUtf8(isolate, x.first.c_str()).ToLocalChecked(),
                    v8::Integer::New(isolate, x.second), isolate);
    }
    addConstant(constants, v8::String::NewFromUtf8(isolate, "Styles").ToLocalChecked(), Styles, isolate);
    return constants;
}