#ifndef SRC_KX003_REGISTER_H_
#define SRC_KX003_REGISTER_H_


#define XOUT_L			0x06
#define XOUT_H			0x07
#define YOUT_L			0x08
#define YOUT_H			0x09
#define ZOUT_L			0x0A
#define ZOUT_H			0x0B


#define DCST_RESP		0x0C


#define WHO_AM_I		0x0F


#define INT_SRC1		0x16
#define DRDY_MASK		1<<4
#define WUFS_MASK		1<<1


#define INT_SRC2		0x17
#define XNWU_BIT		5
#define XPWU_BIT		4
#define YNWU_BIT		3
#define YPWU_BIT		2
#define ZNWU_BIT		1
#define ZPWU_BIT		0

#define XNWU_MASK		1<<5
#define XPWU_MASK		1<<4
#define YNWU_MASK		1<<3
#define YPWU_MASK		1<<2
#define ZNWU_MASK		1<<1
#define ZPWU_MASK		1<<0


#define STATUS_REG		0x19
#define INT_BIT			4
#define INT_MASK		1<<4


#define INT_REL			0x1A


#define CTRL_REG1		0x1B
#define PC1_BIT			7
#define RES_BIT			6
#define DRDYE_BIT		5
#define GSEL1_BIT		4
#define GSEL0_BIT		3
#define EN16G_BIT		2
#define WUFE_BIT		1

#define PC1_MASK		1<<7
#define RES_MASK		1<<6
#define DRDYE_MASK		1<<5
#define GSEL1_MASK		1<<4
#define GSEL0_MASK		1<<3
#define EN16G_MASK		1<<2
#define WUFE_MASK		1<<1


#define CTRL_REG2		0x1D
#define SRST_BIT		7
#define DCST_BIT		4
#define OWUFA_BIT		2
#define OWUFB_BIT		1
#define OWUFC_BIT		0

#define SRST_MASK		1<<7
#define DCST_MASK		1<<4
#define OWUFA_MASK		1<<2
#define OWUFB_MASK		1<<1
#define OWUFC_MASK		1<<0


#define INT_CTRL_REG1	0x1E
#define IEN_BIT			5
#define IEA_BIT			4
#define IEL_BIT			3
#define STPOL_BIT		1

#define IEN_MASK		1<<5
#define IEA_MASK		1<<4
#define IEL_MASK		1<<3
#define STPOL_MASK		1<<1


#define INT_CTRL_REG2	0x1F
#define ULMODE_BIT		7
#define XNWUE_BIT		5
#define XPWUE_BIT		4
#define YNWUE_BIT		3
#define YPWUE_BIT		2
#define ZNWUE_BIT		1
#define XPWUE_BIT		0

#define ULMODE_MASK		1<<7
#define XNWUE_MASK		1<<5
#define XPWUE_MASK		1<<4
#define YNWUE_MASK		1<<3
#define YPWUE_MASK		1<<2
#define ZNWUE_MASK		1<<1
#define XPWUE_MASK		1<<0


#define DATA_CTRL_REG	0x21
#define OSAA_BIT		1<<3
#define OSAB_BIT		1<<2
#define OSAC_BIT		1<<1
#define OSAD_BIT		1<<0

#define OSAA_MASK		1<<3
#define OSAB_MASK		1<<2
#define OSAC_MASK		1<<1
#define OSAD_MASK		1<<0


#define WAKEUP_COUNTER	0x29


#define NA_COUNTER		0x2A


#define SELF_TEST		0x3A


#define WAKEUP_THRESHOLD_H	0x6A


#define WAKEUP_THRESHOLD_L	0x6B

#endif
