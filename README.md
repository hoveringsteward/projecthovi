# projecthovi
Firmware of the project Hovering Steward

/*****************************************************************************/
/* Project: HOVI_PIC16-Tests_v2
/* 
/* This file is for testing the PIXY-cam, it detects an object (CC or obj)
/* and tests if this is the wanted object.
/* If the wanted object is found it displays the position of the object by
/* setting a LED in which direction it is moved outwards of the center.
/* According to this the following LED's are used: Up, Down, Right, Left
/*
/* List of files:
/*      * main_v2.c         according header: hovi_v2.h
/*      * led_position_v2.c according header: hovi_LED_v2.h
/*      * SPI_com_v2.c      according header: hovi_SPI_v2.h
/*
/* Filecontent:
/*      * main_v2:
/*  Includes the mainroutine and the initialisation of the PIC
/*  Calls Get_Object subroutine to detect an object with the Pixy
/*
/*      * led_position_v2:
/*  Contains the programm that gets the information from the Pixy and processes
/*  it. If the right object is detected it sets a LED according to the direction
/*  the Pixy needs to be moved to get the object into the center.
/*
/*      *SPI_com_v2:
/*  Contains the subroutines for communication.
/*      8 Bit without returning a value
/*      8 Bit with returning a value
/*      16 Bit with returning a value
/*
/*****************************************************************************/