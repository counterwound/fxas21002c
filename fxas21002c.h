//*****************************************************************************
// fxas21002c.h - Prototypes for the FXAS21002C Peripheral
//
//  Created on: May 1, 2018
//      Author: Brandon Dixon
//
//*****************************************************************************

#ifndef FXAS21002C_H_
#define FXAS21002C_H_

//*****************************************************************************
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//*****************************************************************************

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
// Register addreses
//*****************************************************************************

//*****************************************************************************
// Functions
//*****************************************************************************

// I2C General Send and receive functions
extern void I2AGReceive(uint32_t ui32SlaveAddress, uint8_t ui32SlaveRegister,
                    uint8_t *pReceiveData, uint8_t ui8NumBytes);
extern void I2CAGSend(uint8_t ui32SlaveAddress, uint8_t ui8NumArgs, ...);

// FXAS21002C functions


//*****************************************************************************
// Mark the end of the C bindings section for C++ compilers.
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* FXAS21002C_H_ */
