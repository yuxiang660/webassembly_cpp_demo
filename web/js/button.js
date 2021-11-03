var a = 1;
async function button() {
   console.log(Module._ShowMeTheAnswer());
   console.log(Module._Add(0, a));
   console.log(Module._Sub(0, a));
   console.log(Module._Multiply(1, a));
   a++;
}
