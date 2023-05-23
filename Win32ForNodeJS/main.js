const addon = require('./build/Release/addon.node');
// Create a window
const parent = 0; // Set the parent window handle to 0 for a top-level window
const x = 100;
const y = 100;
const width = 400;
const height = 300;
const title = 'My Doggy DOG';
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

addon.registerClass('HMMMMMMMMMMMMMMMM');
const windowHandle = addon.createWindow(
    {
        parent,
        x,
        y,
        width,
        height,
        title,
        class: 'HMMMMMMMMMMMMMMMM',
        style: addon.Styles.OverLappedWindow | addon.Styles.ExtendedStaticEdge
    }
);
console.log('Window handle:', windowHandle);
const childWindowHandle = addon.createWindow({
    parent:windowHandle,
    x:10,
    y:10,
    width:200,
    height:150,
    title:'deez',
    class: 'BUTTON',
    style: addon.Styles.ChildWindow|addon.Styles.Border
})
addon.showWindow(childWindowHandle)
console.log('Child Window handle:', childWindowHandle);

console.log(addon)
// Show the windowon)
addon.showWindow(windowHandle);

// // Run the message loop

addon.runMessageLoop();

class Window {
    constructor(id) {
        this.id = id;
    }

    get() {
        return id;
    }

    somemethod() {
        console.log('methoding')
    }
}
