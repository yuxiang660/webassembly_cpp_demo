#ifndef EM_PORT_API
#   if defined(__EMSCRIPTEN__)
#      include <emscripten.h>
#      if defined(__cplusplus)
#         define EM_PORT_API(rettype) extern "C" rettype EMSCRIPTEN_KEEPALIVE
#      else
#         define EM_PORT_API(rettype) rettype EMSCRIPTEN_KEEPALIVE
#      endif
#   else
#      if defined(__cplusplus)
#         define EM_PORT_API(rettype) extern "C" rettype
#      else
#         define EM_PORT_API(rettype) rettype
#      endif
#   endif
#endif

#include "util.h"
#include "demo.h"

EM_PORT_API(int) ShowMeTheAnswer() {
   return DEMO::show_me_the_answer();
}

EM_PORT_API(float) Add(float a, float b) {
   return DEMO::add(a, b);
}

EM_PORT_API(int) Sub(int a, int b) {
   return DEMO::sub(a, b);
}

EM_PORT_API(int) Multiply(int a, int b) {
   return DEMO::multiply(a, b);
}

