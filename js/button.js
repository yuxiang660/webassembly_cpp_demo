var a = 0;
async function button() {
   a++;
   console.log(Module._ShowMeTheAnswer());
   console.log(Module._Add(0, a));
   console.log(Module._Sub(0, a));
   console.log(Module._Multiply(1, a));
   var ptr = Module._GetString();
   var str = UTF8ToString(ptr);
   console.log(typeof(str));
   console.log(str);
}
