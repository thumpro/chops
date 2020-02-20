#pragma once
#include <string_view>

#define CAT_(a, b) a ## b
#define CAT(a, b) CAT_(a, b)

#define name_1(x) std::string_view{#x}
#define name_2(x,x2) std::string_view{#x} , std::string_view{#x2}
#define name_3(x,x2,x3) std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}
#define name_4(x,x2,x3,x4) std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, std::string_view{#x4}
#define name_5(x,x2,x3,x4,x5) std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
                              std::string_view{#x4}, std::string_view{#x5} 
#define name_6(x,x2,x3,x4,x5,x6) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}   
#define name_7(x,x2,x3,x4,x5,x6,x7) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}
#define name_8(x,x2,x3,x4,x5,x6,x7,x8) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}
#define name_9(x,x2,x3,x4,x5,x6,x7,x8,x9) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}
#define name_10(x,x2,x3,x4,x5,x6,x7,x8,x9,x10) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}
#define name_11(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}
#define name_12(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}
#define name_13(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}
#define name_14(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}
#define name_15(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}
#define name_16(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}
#define name_17(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}
#define name_18(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}
#define name_19(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}
#define name_20(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}
#define name_21(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}
#define name_22(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}
#define name_23(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}
#define name_24(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}

#define name_25(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}
#define name_26(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}
#define name_27(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}
#define name_28(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}
#define name_29(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}
#define name_30(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}
#define name_31(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}
#define name_32(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}
#define name_33(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}
#define name_34(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}
#define name_35(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}
#define name_36(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}
#define name_37(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}
#define name_38(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}, std::string_view{#x38}
#define name_39(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38, \
                x39) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}, std::string_view{#x38}, std::string_view{#x39}
#define name_40(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38, \
                x39,x40) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}, std::string_view{#x38}, std::string_view{#x39}, \
        std::string_view{#x40}
#define name_41(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38, \
                x39,x40,x41) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}, std::string_view{#x38}, std::string_view{#x39}, \
        std::string_view{#x40}, std::string_view{#x41}
#define name_42(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38, \
                x39,x40,x41,x42) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}, std::string_view{#x38}, std::string_view{#x39}, \
        std::string_view{#x40}, std::string_view{#x41}, std::string_view{#x42}
#define name_43(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38, \
                x39,x40,x41,x42,x43) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}, std::string_view{#x38}, std::string_view{#x39}, \
        std::string_view{#x40}, std::string_view{#x41}, std::string_view{#x42}, \
        std::string_view{#x43}
#define name_44(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38, \
                x39,x40,x41,x42,x43,x44) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}, std::string_view{#x38}, std::string_view{#x39}, \
        std::string_view{#x40}, std::string_view{#x41}, std::string_view{#x42}, \
        std::string_view{#x43}, std::string_view{#x44}
#define name_45(x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20, \
                x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38, \
                x39,x40,x41,x42,x43,x44,x45) \
        std::string_view{#x} , std::string_view{#x2}, std::string_view{#x3}, \
        std::string_view{#x4}, std::string_view{#x5}, std::string_view{#x6}, \
        std::string_view{#x7}, std::string_view{#x8}, std::string_view{#x9}, \
        std::string_view{#x10}, std::string_view{#x11}, std::string_view{#x12}, \
        std::string_view{#x13}, std::string_view{#x14}, std::string_view{#x15}, \
        std::string_view{#x16}, std::string_view{#x17}, std::string_view{#x18}, \
        std::string_view{#x19}, std::string_view{#x20}, std::string_view{#x21}, \
        std::string_view{#x22}, std::string_view{#x23}, std::string_view{#x24}, \
        std::string_view{#x25}, std::string_view{#x26}, std::string_view{#x27}, \
        std::string_view{#x28}, std::string_view{#x29}, std::string_view{#x30}, \
        std::string_view{#x31}, std::string_view{#x32}, std::string_view{#x33}, \
        std::string_view{#x34}, std::string_view{#x35}, std::string_view{#x36}, \
        std::string_view{#x37}, std::string_view{#x38}, std::string_view{#x39}, \
        std::string_view{#x40}, std::string_view{#x41}, std::string_view{#x42}, \
        std::string_view{#x43}, std::string_view{#x44}, std::string_view{#x45}

#ifdef _MSC_VER // Microsoft compilers

#define STRINGFY_EXPAND_HELPER( x ) x
#define STRINGIFY_VA_PRIVATE(...) STRINGFY_EXPAND_HELPER(CAT(name_, VA_NARGS(__VA_ARGS__))(__VA_ARGS__))
#define STRINGIFY_VA(...) STRINGFY_EXPAND_HELPER( STRINGIFY_VA_PRIVATE(__VA_ARGS__) )

#else

#define STRINGIFY_VA(...) CAT(name_, VA_NARGS(__VA_ARGS__))(__VA_ARGS__)

#endif