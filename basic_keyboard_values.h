/******************************************************************************/
/*        ________                                                            */
/*        \______ \  _____  __  _  __ ____  _____    __ __ _______            */
/*         |    |  \ \__  \ \ \/ \/ //    \ \__  \  |  |  \\_  __ \           */
/*         |    `   \ / __ \_\     /|   |  \ / __ \_|  |  / |  | \/           */
/*        /_______  /(____  / \/\_/ |___|  /(____  /|____/  |__|              */
/*                \/      \/             \/      \/                           */
/*                                                                            */
/* Project:        basic_keyboard                                             */
/* File:           basic_keyboard_values.h                                    */
/* Started:        dec. 2020                                                  */
/* Last updated:   16 dec. 2020                                               */
/* License:        MIT (https://opensource.org/licenses/MIT)                  */
/* Comment:        Sketch of basic 24 keys keyboard over serial with soft     */
/*                 realtime                                                   */
/*                                                                            */
/******************************************************************************/

#ifndef BASIC_KEYBOARD_VALUES_H
# define BASIC_KEYBOARD_VALUES_H

/* Here are defines cycles duration for most common polling frequencies */
# define K_CYCLE_DURATION_125_HZ	8000
# define K_CYCLE_DURATION_250_HZ	4000
# define K_CYCLE_DURATION_500_HZ	2000
# define K_CYCLE_DURATION_1000_HZ	1000

/* Here are defined bitwise masks for debouncing */
# define K_DEBOUNCE_1_CYCLE			0b00000011
# define K_DEBOUNCE_2_CYCLE			0b00000111
# define K_DEBOUNCE_3_CYCLE			0b00001111
# define K_DEBOUNCE_4_CYCLE			0b00011111
# define K_DEBOUNCE_5_CYCLE			0b00111111


/* Here are defined I/O pins */
# define K_PIN_ROW_1				2
# define K_PIN_ROW_2				3
# define K_PIN_ROW_3				4
# define K_PIN_ROW_4				5
# define K_NB_ROW					4

# define K_PIN_COL_1				6
# define K_PIN_COL_2				7
# define K_PIN_COL_3				8
# define K_PIN_COL_4				9
# define K_PIN_COL_5				10
# define K_PIN_COL_6				11
# define K_NB_COL					6

/* Total number of keys */
# define K_NB_KEYS			(K_NB_ROW * K_NB_COL)

#endif /* BASIC_KEYBOARD_VALUES_H */
