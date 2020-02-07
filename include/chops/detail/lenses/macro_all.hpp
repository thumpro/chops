#include <chops/detail/lenses/macro_main.hpp>
#include <chops/detail/narg_macro.hpp>
                                    
#define FULLY_EXPANDED(type, count, ...) \
    INTERNAL_EXPAND(REGISTER_LENSES_(type, __VA_ARGS__)) \
    INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH ## count (type, __VA_ARGS__))
#define SEMI_EXPANDED(type, count, ...) INTERNAL_EXPAND(FULLY_EXPANDED(type, count, __VA_ARGS__))
#define MAKE_LENSE(type, ...) INTERNAL_EXPAND(SEMI_EXPANDED(type, VA_NARGS(__VA_ARGS__), __VA_ARGS__))

#define ACTUAL_MACRO(type, field) MAKE_LENSE_(type, field)

#define LENS_MACRO_EXPAND_EACH1(type,a) \
        INTERNAL_EXPAND(ACTUAL_MACRO(type,a))
#define LENS_MACRO_EXPAND_EACH2(type,a,b) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH1(type,a) ACTUAL_MACRO(type,b))
#define LENS_MACRO_EXPAND_EACH3(type,a,b,c) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH2(type,a,b) ACTUAL_MACRO(type,c))
#define LENS_MACRO_EXPAND_EACH4(type,a,b,c,d) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH3(type,a,b,c) ACTUAL_MACRO(type,d))
#define LENS_MACRO_EXPAND_EACH5(type,a,b,c,d,e) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH4(type,a,b,c,d) ACTUAL_MACRO(type,e))
#define LENS_MACRO_EXPAND_EACH6(type,a,b,c,d,e,f) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH5(type,a,b,c,d,e) ACTUAL_MACRO(type,f))
#define LENS_MACRO_EXPAND_EACH7(type,a,b,c,d,e,f,g) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH6(type,a,b,c,d,e,f) ACTUAL_MACRO(type,g))
#define LENS_MACRO_EXPAND_EACH8(type,a,b,c,d,e,f,g,h) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH7(type,a,b,c,d,e,f,g) ACTUAL_MACRO(type,h))
#define LENS_MACRO_EXPAND_EACH9(type,a,b,c,d,e,f,g,h,i) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH8(type,a,b,c,d,e,f,g,h) ACTUAL_MACRO(type,i))
#define LENS_MACRO_EXPAND_EACH10(type,a,b,c,d,e,f,g,h,i,j) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH9(type,a,b,c,d,e,f,g,h,i) ACTUAL_MACRO(type,j))
#define LENS_MACRO_EXPAND_EACH11(type,a,b,c,d,e,f,g,h,i,j,k) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH10(type,a,b,c,d,e,f,g,h,i,j) ACTUAL_MACRO(type,k))
#define LENS_MACRO_EXPAND_EACH12(type,a,b,c,d,e,f,g,h,i,j,k,l) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH11(type,a,b,c,d,e,f,g,h,i,j,k) ACTUAL_MACRO(type,l))
#define LENS_MACRO_EXPAND_EACH13(type,a,b,c,d,e,f,g,h,i,j,k,l,m) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH12(type,a,b,c,d,e,f,g,h,i,j,k,l) ACTUAL_MACRO(type,m))
#define LENS_MACRO_EXPAND_EACH14(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH13(type,a,b,c,d,e,f,g,h,i,j,k,l,m) ACTUAL_MACRO(type,n))
#define LENS_MACRO_EXPAND_EACH15(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH14(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n) ACTUAL_MACRO(type,o))