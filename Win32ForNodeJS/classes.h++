#pragma once

#include "C:/Users/gogop/AppData/Local/node-gyp/Cache/18.13.0/include/node/node.h"
#include <windows.h>
#include <locale>
#include <codecvt>
#include "constants.h++"
#include "internalfunctions.h++"
#include "functions.h++"

#pragma endregion

class Window {
public:
    static void Constructor(const v8::FunctionCallbackInfo<v8::Value>& args) {
        v8::Isolate* isolate = args.GetIsolate();

        if (args.IsConstructCall()) {
            // Extract the argument from the constructor
            if (args.Length() >= 1 && args[0]->IsNumber()) {
                int id = args[0]->Int32Value(isolate->GetCurrentContext()).ToChecked();

                // Create a new instance of the class
                Window* window = new Window(id);
                window->Wrap(args.This());
                args.GetReturnValue().Set(args.This());
            } else {
                // Invalid arguments
                isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Invalid arguments").ToLocalChecked()));
            }
        } else {
            // Invoked without new keyword
            isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Must use 'new' with constructor").ToLocalChecked()));
        }
    }

    static void GetMethod(const v8::FunctionCallbackInfo<v8::Value>& args) {
        v8::Isolate* isolate = args.GetIsolate();
        Window* window = ObjectWrap::Unwrap<Window>(args.Holder());

        // Return the id property
        args.GetReturnValue().Set(v8::Number::New(isolate, window->id_));
    }

    static void SomeMethod(const v8::FunctionCallbackInfo<v8::Value>& args) {
        // Perform some actions
        std::cout << "Methoding" << std::endl;
    }

private:
    explicit Window(int id) : id_(id) {}

    int id_;
};
//
//void InitializeWindowClass(const v8::Local<v8::Object>& exports, const v8::Local<v8::Context>& context) {
//    v8::Isolate* isolate = exports->GetIsolate();
//    v8::HandleScope scope(isolate);
//
//    // Create a new class template
//    v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, Window::Constructor);
//    tpl->SetClassName(v8::String::NewFromUtf8(isolate, "Window"));
//
//    // Add method properties to the prototype
//    tpl->PrototypeTemplate()->Set(isolate, "get", v8::FunctionTemplate::New(isolate, Window::GetMethod));
//    tpl->PrototypeTemplate()->Set(isolate, "somemethod", v8::FunctionTemplate::New(isolate, Window::SomeMethod));
//
//    // Assign the class template to the exports object
//    exports->Set(context, v8::String::NewFromUtf8(isolate, "Window"), tpl->GetFunction(context).ToLocalChecked()).FromJust();
//}
//
//NODE_MODULE_INIT(/* exports, module, context */) {
//v8::Local<v8::Object> exports = info.Env().GetInstanceData<v8::Object>();
//v8::Local<v8::Context> context = info.Context();
//InitializeWindowClass(exports, context);
//NODE_MODULE_CONTEXT_AWARE_BUILTIN_END
//}
