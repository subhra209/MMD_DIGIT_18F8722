#ifndef __BOARD__
#define __BOARD__

/*
*------------------------------------------------------------------------------
* device.h
*
* Include file for port pin assignments
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* File				: device.h
*------------------------------------------------------------------------------
*

*------------------------------------------------------------------------------
*/

/* 
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/

#include <p18f8722.h>
#include <delays.h>
#include <timers.h>
#include "typedefs.h"
#include "config.h"


/*
*------------------------------------------------------------------------------
* Hardware Port Allocation
*------------------------------------------------------------------------------
*/



// Heart Beat




// Rs485 / RS232 Serial commnunicaton port
#define		TX2_EN					PORTGbits.RG4			// TX control for RS485 communication
#define		TX2_EN_DIR				TRISGbits.TRISG4

#define 	SER2_TX					PORTGbits.RG1 		// serial transmit
#define		SER2_TX_DIR				TRISGbits.TRISG1
#define 	SER2_RX					PORTGbits.RG2			// serial receive
#define		SER2_RX_DIR				TRISGbits.TRISG2



// HeartBeat
#define		HEART_BEAT				PORTGbits.RG0			// high - OFF, Low - ON
#define		HEART_BEAT_DIR			TRISGbits.TRISG0

// MMD PORTS
#define 	MMD_DISPLAY_CONTROL				PORTGbits.RG3
#define 	MMD_DISPLAY_CONTROL_DIRECTION	TRISGbits.TRISG3

#define		MMD_DATA_PORT				PORTF	//LATF	 				// dot matrix display data (DB0-DB7)
#define 	MMD_DATA_PORT_DIR			TRISF
#define		MMD_DIGIT_PORT				PORTE	//LATE	 				// digit drivers(upto 128 digits)
#define		MMD_DIGIT_PORT_DIR			TRISE	//LATE	 				// digit drivers(upto 128 digits)

#define		ROW_SEL_A				PORTDbits.RD0			// decoder digit sel A
#define		ROW_SEL_A_DIR			TRISDbits.TRISD0
#define		ROW_SEL_B				PORTDbits.RD1		// decoder digit sel B
#define		ROW_SEL_B_DIR			TRISDbits.TRISD1
#define		ROW_SEL_C				PORTDbits.RD2		// decoder digit sel C
#define		ROW_SEL_C_DIR			TRISDbits.TRISD2
#define		ROW_SEL_D				PORTDbits.RD3		// decoder digit sel D
#define		ROW_SEL_D_DIR			TRISDbits.TRISD3
#define		ROW_SEL_E				PORTDbits.RD4		// decoder digit sel E
#define		ROW_SEL_E_DIR			TRISDbits.TRISD4
#define		ROW_SEL_F				PORTDbits.RD5		// decoder digit sel F
#define		ROW_SEL_F_DIR			TRISDbits.TRISD5
#define		ROW_SEL_G				PORTDbits.RD6	// decoder digit sel G
#define		ROW_SEL_G_DIR			TRISDbits.TRISD6
#define		ROW_SEL_H				PORTDbits.RD7	// decoder digit sel G
#define		ROW_SEL_H_DIR			TRISDbits.TRISD7



//Seven segment digit
#define	DIGIT_PORT_1               PORTA
#define DIGIT_PORT_1_DIRECTION     TRISA

#define DIGIT_PORT_2               PORTB
#define DIGIT_PORT_2_DIRECTION     TRISB

#define DIGIT_PORT_3               PORTC
#define DIGIT_PORT_3_DIRECTION     TRISC

#define DIGIT_PORT_4               PORTH
#define DIGIT_PORT_4_DIRECTION     TRISH


//Seven segment data

#define	DATA_PORT    	           PORTJ
#define DATA_PORT_DIRECTION  	   TRISJ
			
/*
*------------------------------------------------------------------------------
* Public Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Macros
*------------------------------------------------------------------------------
*/



#define SYSTEM_CLOCK			(32000000UL)	// 8MHz internal oscillator	with PLL

#define PERIPHERAL_CLOCK			(SYSTEM_CLOCK / 4)UL

#define PERIPHERAL_CLOCK_PERIOD 	(1 / PERIPHERAL_CLOCK)UL



// Direction controle bit is processor specific ,
#define PORT_OUT				(BOOL)(0)
#define PORT_IN					(BOOL)(0xFF)

#define OFF_FOREVER				(BOOL)(0)
#define LOOP_FOREVER			(BOOL)(1)

#define SWITCH_OFF				(BOOL)(0)
#define SWITCH_ON				(BOOL)(1)

#define DISPLAY_DISABLE			(BOOL)(1)
#define DISPLAY_ENABLE			(BOOL)(0)


#define GetSystemClock()		(SYSTEM_CLOCK)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()

#define ENTER_CRITICAL_SECTION()	INTCONbits.GIE = 0;// Disable global interrupt bit.


#define EXIT_CRITICAL_SECTION()		INTCONbits.GIE = 1;// Enable global interrupt bit.

#define ENABLE_GLOBAL_INT()			EXIT_CRITICAL_SECTION()


#define DISABLE_INT0_INTERRUPT()	INTCONbits.INT0IE = 0
#define ENABLE_INT0_INTERRUPT()		INTCONbits.INT0IE = 1
#define CLEAR_INTO_INTERRUPT()		INTCONbits.INT0IF = 0


#define DISABLE_TMR0_INTERRUPT()	INTCONbits.TMR0IE = 0
#define ENABLE_TMR0_INTERRUPT()		INTCONbits.TMR0IE = 1

#define DISABLE_TMR1_INTERRUPT()	PIE1bits.TMR1IE = 0
#define ENABLE_TMR1_INTERRUPT()		PIE1bits.TMR1IE = 1



#define DISABLE_UART2_TX_INTERRUPT()	PIE3bits.TX2IE = 0
#define ENABLE_UART2_TX_INTERRUPT()		PIE3bits.TX2IE = 1

#define DISABLE_UART2_RX_INTERRUPT()	PIE3bits.RC2IE = 0
#define ENABLE_UART2_RX_INTERRUPT()		PIE3bits.RC2IE = 1

#define DISABLE_UART1_TX_INTERRUPT()	PIE1bits.TX1IE = 0
#define ENABLE_UART1_TX_INTERRUPT()		PIE1bits.TX1IE = 1

#define DISABLE_UART_RX_INTERRUPT()		PIE1bits.RC1IE = 0
#define ENABLE_UART_RX_INTERRUPT()		PIE1bits.RC1IE = 1

#define ENB_485_TX()	TX_EN = 1;
#define ENB_485_RX()	TX_EN = 0

#define Delay10us(us)		Delay10TCYx(((GetInstructionClock()/1000000)*(us)))
#define DelayMs(ms)												\
	do																\
	{																\
		unsigned int _iTemp = (ms); 								\
		while(_iTemp--)												\
			Delay1KTCYx((GetInstructionClock()+999999)/1000000);	\
	} while(0)

/*
*------------------------------------------------------------------------------
* Public Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables (extern)
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Public Constants (extern)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Function Prototypes (extern)
*------------------------------------------------------------------------------
*/

extern void BRD_init(void);

#endif
/*
*  End of device.h
*/