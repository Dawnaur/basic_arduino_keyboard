/******************************************************************************/
/*        ________                                                            */
/*        \______ \  _____  __  _  __ ____  _____    __ __ _______            */
/*         |    |  \ \__  \ \ \/ \/ //    \ \__  \  |  |  \\_  __ \           */
/*         |    `   \ / __ \_\     /|   |  \ / __ \_|  |  / |  | \/           */
/*        /_______  /(____  / \/\_/ |___|  /(____  /|____/  |__|              */
/*                \/      \/             \/      \/                           */
/*                                                                            */
/* Project:        basic_keyboard                                             */
/* File:           basic_keyboard.ino                                         */
/* Started:        dec. 2020                                                  */
/* Last updated:   16 dec. 2020                                               */
/* License:        MIT (https://opensource.org/licenses/MIT)                  */
/* Comment:        Sketch of basic 24 keys keyboard over serial with soft     */
/*                 realtime                                                   */
/*                                                                            */
/******************************************************************************/

#include "basic_keyboard_values.h"
#include "basic_keyboard.h"

extern	char *__brkval;

/* Unused: return the available memory for debug purpose */
/*unsigned int	get_free_memory(void)
{
	char	top;

	return ((unsigned int)(&top - __brkval));
}*/

void	setup()
{
	unsigned int	i;

	// Opens serial port, sets data rate to 9600 bps
	Serial.begin(9600);

	// Set debouncing mode to 3 cycles
	g_debouncing_mode = K_DEBOUNCE_3_CYCLE;

	// Set scan and polling to 250Hz
	g_cycle_duration = K_CYCLE_DURATION_250_HZ;

	// Init I/O pins
	for(i = 0; i < (sizeof(g_row_pins) / sizeof(g_row_pins[0])) ; ++i)
	{
		pinMode(g_row_pins[i], OUTPUT);
		digitalWrite(g_row_pins[i], HIGH);
	}
	for(i = 0; i < (sizeof(g_col_pins) / sizeof(g_col_pins[0])) ; ++i)
		pinMode(g_col_pins[i], INPUT_PULLUP);

	// Init internal variable to 0
	for(i = 0; i < K_NB_KEYS; ++i)
		g_key_value[i] = 0;

	g_cycle_count = 0;
	g_cycle_start = micros();
	g_margin_time = g_cycle_duration;
}

void	scan_the_matrix(void)
{
	unsigned int	line;
	unsigned int	column;
	unsigned int	key_id;

	/* for each line, set the corresponding pin to 0 (because of input pullup), and acquires all line key stats  */
	for(line = 0; line < (sizeof(g_row_pins) / sizeof(g_row_pins[0])) ; ++line)
	{
		digitalWrite(g_row_pins[line], LOW);

		/* Temporisation to stabilise electrical state */
		delayMicroseconds(50);

		/* For each column, acquires the state, and set it in g_key_value as the bit0 to keep history */
		for(column = 0; column < (sizeof(g_col_pins) / sizeof(g_col_pins[0])) ; ++column)
		{
			key_id = line * K_NB_COL + column;
			/* Shift the history -> if OLD = 0b00110111, NEW = 0b01101110 */
			g_key_value[key_id] <<= 1;
			/* Set the bit0 to acquired value */
			if (!digitalRead(g_col_pins[column]))
				g_key_value[key_id] |= 1;
		}
		digitalWrite(g_row_pins[line], HIGH);
	}
}

void	send_new_keystrokes(void)
{
	unsigned int	key_nb;
	unsigned int	debounced_raw;

	for(key_nb = 0; key_nb < K_NB_KEYS; ++key_nb)
	{
		debounced_raw = (g_key_value[key_nb] & g_debouncing_mode);
		if ((!debounced_raw || (debounced_raw == g_debouncing_mode)) // key not bouncing
			&& (!debounced_raw != !(g_key_value[key_nb] & ~g_debouncing_mode))) // key state changed
		{
			if (debounced_raw & 0x1) // key pressed
			{
				g_key_value[key_nb] = 0xFFFF;
				Serial.write(g_charset[key_nb]);
			}
			else
			{
				g_key_value[key_nb] = 0x0;
				// Send key release if true keyboard managment
			}
		}
	}
}

void	save_rtc_margin(unsigned int	margin_time)
{
	if (g_cycle_count++ % 1000 == 0)
		g_margin_time = g_cycle_duration;
	if (margin_time < g_margin_time)
		g_margin_time =  margin_time;
}

void	wait_cycle_end(void)
{
	unsigned long act_time;

	act_time = micros();
	save_rtc_margin((act_time - g_cycle_start) + g_cycle_duration);

	while (act_time < (g_cycle_start + g_cycle_duration))
		act_time = micros();
	g_cycle_start += g_cycle_duration;
}

void	update_lightning(void)
{
	/* All lightning updates must start here */
}


void	loop()
{
	scan_the_matrix();

	send_new_keystrokes();

	update_lightning();

	wait_cycle_end();
}

