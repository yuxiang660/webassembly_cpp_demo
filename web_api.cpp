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

EM_PORT_API(int) show_me_the_answer_c() {
   return DEMO::show_me_the_answer();
}

EM_PORT_API(float) add_c(float a, float b) {
   return DEMO::add(a, b);
}

