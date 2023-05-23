#pragma once
#include "C:/Users/gogop/AppData/Local/node-gyp/Cache/18.13.0/include/node/node.h"
#include <windows.h>
#include <vector>
#include <iostream>
#include "constants.h++"
#pragma endregion

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd,message,wParam,lParam);
    }
}

v8::Local<v8::Object> Merge(v8::Local<v8::Object> object1,v8::Local<v8::Object> object2){
    v8::Isolate *isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Object> mergedObject = v8::Object::New(isolate);

    v8::Local<v8::Array> propertyNames1 = object1->GetPropertyNames(isolate->GetCurrentContext()).ToLocalChecked();

    // Iterate over the property names and copy them to the merged object
    for (uint32_t i = 0; i < propertyNames1->Length(); i++) {
        v8::Local<v8::Value> propertyName = propertyNames1->Get(isolate->GetCurrentContext(), i).ToLocalChecked();
        v8::Local<v8::Value> propertyValue = object1->Get(isolate->GetCurrentContext(), propertyName).ToLocalChecked();

        mergedObject->Set(isolate->GetCurrentContext(), propertyName, propertyValue).Check();
    }

    // Get the property names of the second object
    v8::Local<v8::Array> propertyNames2 = object2->GetPropertyNames(isolate->GetCurrentContext()).ToLocalChecked();

    // Iterate over the property names and copy them to the merged object
    for (uint32_t i = 0; i < propertyNames2->Length(); i++) {
        v8::Local<v8::Value> propertyName = propertyNames2->Get(isolate->GetCurrentContext(), i).ToLocalChecked();
        v8::Local<v8::Value> propertyValue = object2->Get(isolate->GetCurrentContext(), propertyName).ToLocalChecked();

        mergedObject->Set(isolate->GetCurrentContext(), propertyName, propertyValue).Check();
    }
    return mergedObject;
}
void InPlaceMerge(v8::Local<v8::Object> target, v8::Local<v8::Object> source) {
    v8::Local<v8::Array> propertyNames = source->GetPropertyNames(target->CreationContext()).ToLocalChecked();

    for (uint32_t i = 0; i < propertyNames->Length(); i++) {
        v8::Local<v8::Value> propertyName = propertyNames->Get(target->CreationContext(), i).ToLocalChecked();
        v8::Local<v8::Value> propertyValue = source->Get(target->CreationContext(), propertyName).ToLocalChecked();

        target->Set(target->CreationContext(), propertyName, propertyValue).Check();
    }
}
LPCWSTR UTFChanger(v8::Local<v8::String> str) {
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::String::Value unicodeValue(isolate, str);
    const uint16_t* utf16Buffer = reinterpret_cast<const uint16_t*>(*unicodeValue);
    size_t utf16Length = unicodeValue.length();
    std::wstring wideString(utf16Buffer, utf16Buffer + utf16Length);
    return wideString.c_str();
}

