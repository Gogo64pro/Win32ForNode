const addon = require('./build/Release/addon.node');
// Create a window
const parent = 0; 
const x = 100;
const y = 100;
const width = 400;
const height = 300;
const title = 'Name';


addon.registerClass('classname');
const windowHandle = addon.createWindow(
    {
        parent,
        x,
        y,
        width,
        height,
        title,
        class: 'classname',
        style: addon.Styles.OverLappedWindow
    }
);
console.log('Window handle:', windowHandle);
const childWindowHandle = addon.createWindow({
    parent:windowHandle,
    x:10,
    y:10,
    width:200,
    height:150,
    title:'button',
    class: 'BUTTON',
    style: addon.Styles.ChildWindow|addon.Styles.Border
})
addon.showWindow(childWindowHandle)
console.log('Child Window handle:', childWindowHandle);

console.log(addon)

addon.showWindow(windowHandle);


addon.runMessageLoop();

