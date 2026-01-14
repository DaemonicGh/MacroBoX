/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_c_scancodes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:25:27 by daemo             #+#    #+#             */
/*   Updated: 2026/01/14 23:20:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_C_SCANCODES_H
# define MBX_C_SCANCODES_H

// Simplified version of SLD2's scancodes
// [https://wiki.libsdl.org/SDL2/SDL_Scancode]
// Mouse and Window events are put after Keyboard ones

# define MBX_KEY_NONE 0

# define MBX_KEY_A 4
# define MBX_KEY_B 5
# define MBX_KEY_C 6
# define MBX_KEY_D 7
# define MBX_KEY_E 8
# define MBX_KEY_F 9
# define MBX_KEY_G 10
# define MBX_KEY_H 11
# define MBX_KEY_I 12
# define MBX_KEY_J 13
# define MBX_KEY_K 14
# define MBX_KEY_L 15
# define MBX_KEY_M 16
# define MBX_KEY_N 17
# define MBX_KEY_O 18
# define MBX_KEY_P 19
# define MBX_KEY_Q 20
# define MBX_KEY_R 21
# define MBX_KEY_S 22
# define MBX_KEY_T 23
# define MBX_KEY_U 24
# define MBX_KEY_V 25
# define MBX_KEY_W 26
# define MBX_KEY_X 27
# define MBX_KEY_Y 28
# define MBX_KEY_Z 29

# define MBX_KEY_1 30
# define MBX_KEY_2 31
# define MBX_KEY_3 32
# define MBX_KEY_4 33
# define MBX_KEY_5 34
# define MBX_KEY_6 35
# define MBX_KEY_7 36
# define MBX_KEY_8 37
# define MBX_KEY_9 38
# define MBX_KEY_0 39

# define MBX_KEY_RETURN 40
# define MBX_KEY_ENTER 40
# define MBX_KEY_ESCAPE 41
# define MBX_KEY_BACKSPACE 42
# define MBX_KEY_TAB 43
# define MBX_KEY_SPACE 44

# define MBX_KEY_MINUS 45
# define MBX_KEY_EQUALS 46
# define MBX_KEY_LEFTBRACKET 47
# define MBX_KEY_RIGHTBRACKET 48
# define MBX_KEY_BACKSLASH 49
# define MBX_KEY_NONUSHASH 50
# define MBX_KEY_SEMICOLON 51
# define MBX_KEY_APOSTROPHE 52
# define MBX_KEY_GRAVE 53
# define MBX_KEY_COMMA 54
# define MBX_KEY_PERIOD 55
# define MBX_KEY_SLASH 56

# define MBX_KEY_CAPSLOCK 57

# define MBX_KEY_F1 58
# define MBX_KEY_F2 59
# define MBX_KEY_F3 60
# define MBX_KEY_F4 61
# define MBX_KEY_F5 62
# define MBX_KEY_F6 63
# define MBX_KEY_F7 64
# define MBX_KEY_F8 65
# define MBX_KEY_F9 66
# define MBX_KEY_F10 67
# define MBX_KEY_F11 68
# define MBX_KEY_F12 69

# define MBX_KEY_PRINTSCREEN 70
# define MBX_KEY_SCROLLLOCK 71
# define MBX_KEY_PAUSE 72
# define MBX_KEY_INSERT 73
# define MBX_KEY_HOME 74
# define MBX_KEY_PAGEUP 75
# define MBX_KEY_DELETE 76
# define MBX_KEY_END 77
# define MBX_KEY_PAGEDOWN 78
# define MBX_KEY_RIGHT 79
# define MBX_KEY_LEFT 80
# define MBX_KEY_DOWN 81
# define MBX_KEY_UP 82

# define MBX_KEY_NUMLOCKCLEAR 83
# define MBX_KEY_KP_DIVIDE 84
# define MBX_KEY_KP_MULTIPLY 85
# define MBX_KEY_KP_MINUS 86
# define MBX_KEY_KP_PLUS 87
# define MBX_KEY_KP_ENTER 88
# define MBX_KEY_KP_1 89
# define MBX_KEY_KP_2 90
# define MBX_KEY_KP_3 91
# define MBX_KEY_KP_4 92
# define MBX_KEY_KP_5 93
# define MBX_KEY_KP_6 94
# define MBX_KEY_KP_7 95
# define MBX_KEY_KP_8 96
# define MBX_KEY_KP_9 97
# define MBX_KEY_KP_0 98
# define MBX_KEY_KP_PERIOD 99

# define MBX_KEY_LCTRL 224
# define MBX_KEY_LSHIFT 225
# define MBX_KEY_LALT 226
# define MBX_KEY_LGUI 227
# define MBX_KEY_RCTRL 228
# define MBX_KEY_RSHIFT 229
# define MBX_KEY_RALT 230
# define MBX_KEY_RGUI 231

// Mouse events

# define MBX_MOUSE_BUTTON_LEFT 512
# define MBX_MOUSE_BUTTON_MIDDLE 513
# define MBX_MOUSE_BUTTON_RIGHT 514
# define MBX_MOUSE_BUTTON_4 515
# define MBX_MOUSE_BUTTON_5 516

// Window events (not tested)

# define MBX_WINDOW_CLOSE 528
# define MBX_WINDOW_MOVE 529
# define MBX_WINDOW_MINIMIZE 530
# define MBX_WINDOW_MAXIMIZE 531
# define MBX_WINDOW_ENTER 532
# define MBX_WINDOW_FOCUS 533
# define MBX_WINDOW_LEAVE 534
# define MBX_WINDOW_UNFOCUS 535
# define MBX_WINDOW_RESIZE 536

#endif
