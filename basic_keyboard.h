/******************************************************************************/
/*        ________                                                            */
/*        \______ \  _____  __  _  __ ____  _____    __ __ _______            */
/*         |    |  \ \__  \ \ \/ \/ //    \ \__  \  |  |  \\_  __ \           */
/*         |    `   \ / __ \_\     /|   |  \ / __ \_|  |  / |  | \/           */
/*        /_______  /(____  / \/\_/ |___|  /(____  /|____/  |__|              */
/*                \/      \/             \/      \/                           */
/*                                                                            */
/* Project:        basic_keyboard                                             */
/* File:           basic_keyboard.h                                           */
/* Started:        dec. 2020                                                  */
/* Last updated:   16 dec. 2020                                               */
/* License:        MIT (https://opensource.org/licenses/MIT)                  */
/* Comment:        Sketch of basic 24 keys keyboard over serial with soft     */
/*                 realtime                                                   */
/*                                                                            */
/******************************************************************************/

#ifndef BASIC_KEYBOARD_H
# define BASIC_KEYBOARD_H

/******************************************************************************/
/*                                                                            */
/*                                   MACROS                                   */
/*                                                                            */
/******************************************************************************/

// needs to be modified for ADC of less or more than 10 bits
# define	RANGE(X, MIN, MAX)	(X < MIN ? MIN : (X > MAX ? MAX : X))

/******************************************************************************/
/*                                                                            */
/*                                 ENUMERATIONS                               */
/*                                                                            */
/******************************************************************************/


/******************************************************************************/
/*                                                                            */
/*                               GLOBAL VARIABLES                             */
/*                                                                            */
/******************************************************************************/

unsigned char			g_debouncing_mode;
unsigned long			g_cycle_duration;
unsigned long			g_cycle_start;
unsigned long			g_cycle_count;
unsigned long			g_margin_time;
unsigned int			g_key_value[K_NB_KEYS];
unsigned int			g_row_pins[] = {K_PIN_ROW_1, K_PIN_ROW_2, K_PIN_ROW_3, K_PIN_ROW_4};
unsigned int			g_col_pins[] = {K_PIN_COL_1, K_PIN_COL_2, K_PIN_COL_3, K_PIN_COL_4, K_PIN_COL_5, K_PIN_COL_6};
unsigned char			g_charset[] = {'1', '2', '3', '4', '5', '6', 'A', 'Z', 'E', 'R', 'T', 'Y', 'Q', 'S', 'D', 'F', 'G', 'H', 'W', 'X', 'C', 'V', 'B', 'N'};

//unsigned char			g_col_values[] = {0, 0, 0, 0, 0, 0};


/******************************************************************************/
/*                                                                            */
/*                             FUNCTION PROTOTYPES                            */
/*                                                                            */
/******************************************************************************/



#endif /* BASIC_KEYBOARD_H */
