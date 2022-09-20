#pragma once

#define XLEN 32
#define RVMODEL_CLEAR_MSW_INT
#define RVMODEL_CLEAR_MTIMER_INT
#define RVMODEL_CLEAR_MEXT_INT
#define RVMODEL_SET_MSW_INT

#define TEST_CASE_1

#define RVMODEL_BOOT

#define SW(reg,addr);\
    .option push;\
    .option norvc;\
    sw reg,0(addr);\
    .option pop;

#define RVMODEL_HALT \
    LI(x1, 0xf0000000) \
    LI(x2, 0xfffffff0) \
    SW(x2, x1) \
1:  j 1b

#define RVMODEL_DATA_BEGIN .data

#define RVMODEL_DATA_END

#define RVMODEL_IO_ASSERT_GPR_EQ(_SP, _R, _I) \
    LI(_SP, _I) \
    beq _SP, _R, 1f \
    LI(x1, 0xf0000000) \
    LI(x2, 0xfffffff1) \
    SW(x2, x1) \
1:

#define RVMODEL_IO_WRITE_STR(reg, str)
