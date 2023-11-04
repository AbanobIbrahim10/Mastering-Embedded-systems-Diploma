

typedef unsigned long uint32 ;
typedef unsigned char uint8 ;

#define SET_BIT(REG, BIT)       REG |=  (1<< (BIT))
#define CLR_BIT(REG, BIT)       REG &= ~(1<< (BIT))
#define TOGGLE_BIT(REG, BIT)    REG ^=  (1<< (BIT))
