Win32ForNode
------------

Bringing Win32 for NodeJS

**_This is in early development_**

Why?
----

Because everything that can be built with JavaScript will be built with JavaScript

How?
----

This is acheived using NodeJS C++ Addons

Use
===

**Register a Window Class**  
addon.registerClass({  
name : String  
//Aditional functionality will be added soon  
})  
  
**Create a window**  
addon.createWindow({  
parent: number,              //Parent window handle (0 for no parent)  
x: number,                   //X positon  
y: number,                   //Y positon  
width: number,               //Window Width  
height: number,              //Window Height  
class: String,               //Window class  
title: String,               //Window title - text  
style: number || addon.style //Window style (Generated by using addon.Style numbers. Combinations with the | operator)  
}) : Number // Window handle  
  
**Show/Hide windows**  
addon.showWindow(handle:number)  
addon.hideWindow(handle:number)  
  
**MessageBox**  
addon.msgBox(text:String,title:String,parentHandle:Number)  
// **This still has no support for Wide characters**  
// This can only produce OK style message boxes for now  
  
**Get Last Error**  
addon.getErr() // Returns the last error in Number format - https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes  
  
**Run message loop**  
addon.runMessageLoop()  
//Runs the Win32 message loop. Program crashes if you try to interact with a window without running message loop  
//The program locks up after this command, soon you will be able to do action while running message loop. Make sure not to have async functions running in the background
