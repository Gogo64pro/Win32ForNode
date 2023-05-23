#pragma once

#include "C:/Users/gogop/AppData/Local/node-gyp/Cache/18.13.0/include/node/node.h"
#include <windows.h>
#include <locale>
#include <codecvt>
#include "constants.h++"
#include "internalfunctions.h++"
//#include "classes.h++"

#pragma endregion

void CreateWindowAddon(const v8::FunctionCallbackInfo<v8::Value> &args) {
	//CreateWindowAddon({
	//  parent: number|Window,
	//  x: number,
	//  y: number,
	//  width: number,
	//  height: number,
	//  ['class']: String,
	//  title: String,
	//
	// })
	// Ensure correct number of arguments
	if (args.Length() < 1) {
		v8::Isolate *isolate = args.GetIsolate();
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "No matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	v8::Isolate *isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	auto object = args[0].As<v8::Object>();

	if (!(object->Has(context, v8::String::NewFromUtf8(isolate, "parent").ToLocalChecked()).FromMaybe(false))) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Missing 'parent' key\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!(object->Has(context, v8::String::NewFromUtf8(isolate, "x").ToLocalChecked()).FromMaybe(false))) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Missing 'x' key\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!(object->Has(context, v8::String::NewFromUtf8(isolate, "y").ToLocalChecked()).FromMaybe(false))) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Missing 'y' key\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!(object->Has(context, v8::String::NewFromUtf8(isolate, "width").ToLocalChecked()).FromMaybe(false))) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Missing 'width' key\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!(object->Has(context, v8::String::NewFromUtf8(isolate, "height").ToLocalChecked()).FromMaybe(false))) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Missing 'height' key\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!(object->Has(context, v8::String::NewFromUtf8(isolate, "class").ToLocalChecked()).FromMaybe(false))) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Missing 'class' key\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!(object->Has(context, v8::String::NewFromUtf8(isolate, "title").ToLocalChecked()).FromMaybe(false))) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Missing 'title' key\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!(object->Has(context, v8::String::NewFromUtf8(isolate, "style").ToLocalChecked()).FromMaybe(false))) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Missing 'style' key\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	v8::Local<v8::Value> ValueParent = object->Get(context, v8::String::NewFromUtf8(isolate,
	                                                                                "parent").ToLocalChecked()).ToLocalChecked();
	v8::Local<v8::Value> ValueX = object->Get(context,
	                                          v8::String::NewFromUtf8(isolate, "x").ToLocalChecked()).ToLocalChecked();
	v8::Local<v8::Value> ValueY = object->Get(context,
	                                          v8::String::NewFromUtf8(isolate, "y").ToLocalChecked()).ToLocalChecked();
	v8::Local<v8::Value> ValueWidth = object->Get(context, v8::String::NewFromUtf8(isolate,
	                                                                               "width").ToLocalChecked()).ToLocalChecked();
	v8::Local<v8::Value> ValueHeight = object->Get(context, v8::String::NewFromUtf8(isolate,
	                                                                                "height").ToLocalChecked()).ToLocalChecked();
	v8::Local<v8::Value> ValueClass = object->Get(context, v8::String::NewFromUtf8(isolate,
	                                                                               "class").ToLocalChecked()).ToLocalChecked();
	v8::Local<v8::Value> ValueTitle = object->Get(context, v8::String::NewFromUtf8(isolate,
	                                                                               "title").ToLocalChecked()).ToLocalChecked();
	v8::Local<v8::Value> ValueStyle = object->Get(context, v8::String::NewFromUtf8(isolate,
	                                                                               "style").ToLocalChecked()).ToLocalChecked();

	if (!ValueParent->IsNumber()) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "'parent' key is not of type number\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!ValueX->IsNumber()) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "'x' key is not of type number\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!ValueY->IsNumber()) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "'y' key is not of type number\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!ValueWidth->IsNumber()) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "'width' key is not of type number\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!ValueHeight->IsNumber()) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "'height' key is not of type number\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!ValueClass->IsString()) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "'class' key is not of type string\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!ValueTitle->IsString()) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "'title' key is not of type string\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	if (!ValueStyle->IsNumber()) {
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "'style' key is not of type number or addon.style\nNo matching function call. A correct call : CreateWindow({\n  parent: number,\n  x: number,\n  y: number,\n  width: number,\n  height: number,\n  ['class']: String,\n  title: String,\n  style:number||addon.style})").ToLocalChecked()));
		return;
	}
	// Extract arguments from Node.js
	HWND parent = reinterpret_cast<HWND>(ValueParent.As<v8::Integer>()->Value());
	int x = ValueX.As<v8::Integer>()->Value();
	int y = ValueY.As<v8::Integer>()->Value();
	int width = ValueWidth.As<v8::Integer>()->Value();
	int height = ValueHeight.As<v8::Integer>()->Value();
	long style = ValueStyle.As<v8::Integer>()->Value();

	v8::String::Utf8Value titleValue(isolate, ValueTitle.As<v8::String>());
	std::string utf8Title = *titleValue;

	std::wstring_convert <std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring title = converter.from_bytes(utf8Title);

	v8::String::Utf8Value classValue(isolate, ValueClass.As<v8::String>());
	std::string utf8Class(*classValue);
	std::wstring classv = converter.from_bytes(utf8Class);


// Create a window
	HWND hWnd = CreateWindowW(
			classv.c_str(),        // Window class
			title.c_str(),         // Window title
			(DWORD)style,                 // Window style
			x,                     // X position
			y,                     // Y position
			width,                 // Width
			height,                // Height
			parent,                // Parent window
			NULL,                  // Menu handle
			NULL,                  // Instance handle
			NULL                   // Additional application data
	);



	// Return the window handle to Node.js
	args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), reinterpret_cast<intptr_t>(hWnd)));
}

// Function to show a window
void ShowWindowAddon(const v8::FunctionCallbackInfo<v8::Value> &args) {
	// Ensure correct number of arguments
	if (args.Length() < 1) {
		// Throw an exception with an error message
		v8::Isolate *isolate = args.GetIsolate();
		isolate->ThrowException(
				v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Insufficient arguments").ToLocalChecked()));
		return;
	}

	// Check argument type
	if (!args[0]->IsInt32()) {
		// Throw an exception with an error message
		v8::Isolate *isolate = args.GetIsolate();
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Invalid argument: window handle must be an integer").ToLocalChecked()));
		return;
	}

	// Extract the window handle from Node.js
	HWND hWnd = (HWND)(args[0].As<v8::Integer>()->Value());

	// Show the window
	ShowWindow(hWnd, SW_SHOW);

	// Return nothing to Node.js
}
void HideWindowAddon(const v8::FunctionCallbackInfo<v8::Value> &args) {
	// Ensure correct number of arguments
	if (args.Length() < 1) {
		// Throw an exception with an error message
		v8::Isolate *isolate = args.GetIsolate();
		isolate->ThrowException(
				v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Insufficient arguments").ToLocalChecked()));
		return;
	}

	// Check argument type
	if (!args[0]->IsInt32()) {
		// Throw an exception with an error message
		v8::Isolate *isolate = args.GetIsolate();
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate,
		                                                                         "Invalid argument: window handle must be an integer").ToLocalChecked()));
		return;
	}

	// Extract the window handle from Node.js
	HWND hWnd = (HWND)(args[0].As<v8::Integer>()->Value());

	// Show the window
	ShowWindow(hWnd, SW_HIDE);

	// Return nothing to Node.js
}

// Function to run the message loop
void RunMessageLoopAddon(const v8::FunctionCallbackInfo<v8::Value> &args) {
	// Run the message loop
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Return nothing to Node.js
}

void GetLastErrorErr(const v8::FunctionCallbackInfo<v8::Value> &args) {
	args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), GetLastError()));
}

void RegisterClassNODE(const v8::FunctionCallbackInfo<v8::Value> &args) {
	HINSTANCE hModule = GetModuleHandle(NULL);
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hModule;  // Use the module handle
	wc.lpszClassName = *v8::String::Utf8Value(args.GetIsolate(), args[0].As<v8::String>());
	if (!RegisterClass(&wc)) {
		// Registration failed
		args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), GetLastError()));
	}

}