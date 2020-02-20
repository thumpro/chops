#pragma once

#include <chops/detail/lenses/macro_main.hpp>
#include <chops/detail/narg_macro.hpp>
#include <chops/detail/stringfy_macro.hpp>
                                    
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
#define LENS_MACRO_EXPAND_EACH16(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH15(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) ACTUAL_MACRO(type,p))
#define LENS_MACRO_EXPAND_EACH17(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH16(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) \
        ACTUAL_MACRO(type,r))
#define LENS_MACRO_EXPAND_EACH18(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH17(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r) \
        ACTUAL_MACRO(type,s))
#define LENS_MACRO_EXPAND_EACH19(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH18(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r) \
        ACTUAL_MACRO(type,s))
#define LENS_MACRO_EXPAND_EACH20(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH19(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s) \
        ACTUAL_MACRO(type,q))
#define LENS_MACRO_EXPAND_EACH21(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH20(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q) \
        ACTUAL_MACRO(type,t))
#define LENS_MACRO_EXPAND_EACH22(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH21(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t) \
        ACTUAL_MACRO(type,u))
#define LENS_MACRO_EXPAND_EACH23(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH22(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u) \
        ACTUAL_MACRO(type,v))
#define LENS_MACRO_EXPAND_EACH24(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH23(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v) \
        ACTUAL_MACRO(type,x))
#define LENS_MACRO_EXPAND_EACH25(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH24(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x) \
        ACTUAL_MACRO(type,y))
#define LENS_MACRO_EXPAND_EACH26(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH24(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y) \
        ACTUAL_MACRO(type,z))
#define LENS_MACRO_EXPAND_EACH27(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH26(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z) \
        ACTUAL_MACRO(type,aa))
#define LENS_MACRO_EXPAND_EACH28(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH27(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa) \
        ACTUAL_MACRO(type,ab))
#define LENS_MACRO_EXPAND_EACH29(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH28(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab) \
        ACTUAL_MACRO(type,ac))
#define LENS_MACRO_EXPAND_EACH30(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH29(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac) \
        ACTUAL_MACRO(type,ad))
#define LENS_MACRO_EXPAND_EACH31(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH30(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad) \
        ACTUAL_MACRO(type,ae))
#define LENS_MACRO_EXPAND_EACH32(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH31(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae) \
        ACTUAL_MACRO(type,af))
#define LENS_MACRO_EXPAND_EACH33(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH32(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af) \
        ACTUAL_MACRO(type,ag))
#define LENS_MACRO_EXPAND_EACH34(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH33(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag) \
        ACTUAL_MACRO(type,ah))
#define LENS_MACRO_EXPAND_EACH35(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH34(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah) \
        ACTUAL_MACRO(type,ai))
#define LENS_MACRO_EXPAND_EACH36(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH35(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai) \
        ACTUAL_MACRO(type,aj))
#define LENS_MACRO_EXPAND_EACH37(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH36(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj) \
        ACTUAL_MACRO(type,ak))
#define LENS_MACRO_EXPAND_EACH38(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak,al) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH37(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj,ak) \
        ACTUAL_MACRO(type,al))
#define LENS_MACRO_EXPAND_EACH39(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak,al,am) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH38(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj,ak,al) \
        ACTUAL_MACRO(type,am))
#define LENS_MACRO_EXPAND_EACH40(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak,al,am,an) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH39(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj,ak,al,am) \
        ACTUAL_MACRO(type,an))
#define LENS_MACRO_EXPAND_EACH41(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak,al,am,an,ao) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH40(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj,ak,al,am,an) \
        ACTUAL_MACRO(type,ao))
#define LENS_MACRO_EXPAND_EACH42(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak,al,am,an,ao,ap) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH41(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj,ak,al,am,an,ao) \
        ACTUAL_MACRO(type,ap))
#define LENS_MACRO_EXPAND_EACH43(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak,al,am,an,ao,ap,ar) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH42(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj,ak,al,am,an,ao,ap) \
        ACTUAL_MACRO(type,ar))
#define LENS_MACRO_EXPAND_EACH44(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak,al,am,an,ao,ap,ar,as) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH43(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj,ak,al,am,an,ao,ap,ar) \
        ACTUAL_MACRO(type,as))
#define LENS_MACRO_EXPAND_EACH45(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad,ae, \
                                 af,ag,ah,ai,aj,ak,al,am,an,ao,ap,ar,as,aq) \
        INTERNAL_EXPAND(LENS_MACRO_EXPAND_EACH44(type,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,q,t,u,v,x,y,z,aa,ab,ac,ad, \
                                                 ae,af,ag,ah,ai,aj,ak,al,am,an,ao,ap,ar,as) \
        ACTUAL_MACRO(type,aq))
