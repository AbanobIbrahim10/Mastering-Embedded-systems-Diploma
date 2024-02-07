

typedef unsigned long uint32_t ;
typedef unsigned char uint8_t ;
typedef unsigned short uint16_t ;

#define SET_BIT(REG, BIT)       REG |=  (1<< (BIT))
#define CLR_BIT(REG, BIT)       REG &= ~(1<< (BIT))
#define TOGGLE_BIT(REG, BIT)    REG ^=  (1<< (BIT))
#define GET_BIT(REG,BIT)		(((REG)&(1<<BIT))>>BIT)
