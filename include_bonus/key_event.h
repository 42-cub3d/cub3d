/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:20:16 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/27 02:29:56 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_EVENT_H
# define KEY_EVENT_H

enum e_mouse
{
	LEFT_CLICK		= 1,
	RIGHT_CLICK,
	MIDDLE_CLICK,
	SCROLL_UP,
	SCROLL_DOWN
};

enum e_key
{
	KC_A		=	0x00,
	KC_S		=	0x01,
	KC_D		=	0x02,
	KC_F		=	0x03,
	KC_H		=	0x04,
	KC_G		=	0x05,
	KC_Z		=	0x06,
	KC_X		=	0x07,
	KC_C		=	0x08,
	KC_V		=	0x09,
	KC_B		=	0x0B,
	KC_Q		=	0x0C,
	KC_W		=	0x0D,
	KC_E		=	0x0E,
	KC_R		=	0x0F,
	KC_Y		=	0x10,
	KC_T		=	0x11,
	KC_1		=	0x12,
	KC_2		=	0x13,
	KC_3		=	0x14,
	KC_4		=	0x15,
	KC_6		=	0x16,
	KC_5		=	0x17,
	KC_EQUAL	=	0x18,
	KC_9		=	0x19,
	KC_7		=	0x1A,
	KC_MINUS	=	0x1B,
	KC_8		=	0x1C,
	KC_0		=	0x1D,
	KC_RBRC		=	0x1E,
	KC_O		=	0x1F,
	KC_U		=	0x20,
	KC_LBRC		=	0x21,
	KC_I		=	0x22,
	KC_P		=	0x23,
	KC_L		=	0x25,
	KC_J		=	0x26,
	KC_QUOT		=	0x27,
	KC_K		=	0x28,
	KC_SCLN		=	0x29,
	KC_BSLS		=	0x2A,
	KC_COMM		=	0x2B,
	KC_SLSH		=	0x2C,
	KC_N		=	0x2D,
	KC_M		=	0x2E,
	KC_Period	=	0x2F,
	KC_GRV		=	0x32,
	KC_PDOT		=	0x41,
	KC_PAST		=	0x43,
	KC_PPLS		=	0x45,
	KC_NUM		=	0x47,
	KC_PSLS		=	0x4B,
	KC_PENT		=	0x4C,
	KC_PMNS		=	0x4E,
	KC_PEQL		=	0x51,
	KC_P0		=	0x52,
	KC_P1		=	0x53,
	KC_P2		=	0x54,
	KC_P3		=	0x55,
	KC_P4		=	0x56,
	KC_P5		=	0x57,
	KC_P6		=	0x58,
	KC_P7		=	0x59,
	KC_P8		=	0x5B,
	KC_P9		=	0x5C,
	KC_RETN		=	0x24,
	KC_TAB		=	0x30,
	KC_SPC		=	0x31,
	KC_BSPC		=	0x33,
	KC_ESC		=	0x35,
	KC_LGUI		=	0x37,
	KC_LSFT		=	0x38,
	KC_CAPS		=	0x39,
	KC_LALT		=	0x3A,
	KC_LCTL		=	0x3B,
	KC_RGUI		=	0x36,
	KC_RSFT		=	0x3C,
	KC_RALT		=	0x3D,
	KC_RCTL		=	0x3E,
	KC_FUNC		=	0x3F,
	KC_F17		=	0x40,
	KC_VOLU		=	0x48,
	KC_VOLD		=	0x49,
	KC_MUTE		=	0x4A,
	KC_F18		=	0x4F,
	KC_F19		=	0x50,
	KC_F20		=	0x5A,
	KC_F5		=	0x60,
	KC_F6		=	0x61,
	KC_F7		=	0x62,
	KC_F3		=	0x63,
	KC_F8		=	0x64,
	KC_F9		=	0x65,
	KC_F11		=	0x67,
	KC_F13		=	0x69,
	KC_F16		=	0x6A,
	KC_F14		=	0x6B,
	KC_F10		=	0x6D,
	KC_F12		=	0x6F,
	KC_F15		=	0x71,
	KC_Help		=	0x72,
	KC_HOME		=	0x73,
	KC_PGUP		=	0x74,
	KC_DEL		=	0x75,
	KC_F4		=	0x76,
	KC_END		=	0x77,
	KC_F2		=	0x78,
	KC_PGDN		=	0x79,
	KC_F1		=	0x7A,
	KC_LEFT		=	0x7B,
	KC_RIGHT	=	0x7C,
	KC_DOWN		=	0x7D,
	KC_UP		=	0x7E
};

typedef enum e_x11_event
{
	KEY_PRESS		=	2,
	KEY_RELEASE,
	BUTTON_PRESS,
	BUTTON_RELEASE,
	MOTION_NITOFY,
	ENTER_NOTIFY,
	LEAVE_NOTIFY,
	FOCUS_IN,
	FOCUS_OUT,
	KEY_MAP_NOTIFY,
	EXPOSE,
	GRAPHICS_EXPOSE,
	NO_EXPOSE,
	VISIBILITY_NOTIFY,
	CREATE_NOTIFY,
	DESTROY_NOTIFY,
	UNMAP_NOTIFY,
	MAP_NOTIFY,
	MAP_REQUEST,
	REPARENT_NOTIFY,
	CONFIGURE_NOTIFY,
	CONFIGURE_REQUEST,
	GRAVITY_NOTIFY,
	RESIZE_REQUEST,
	CIRCULATE_NOTIFY,
	CIRCULATE_REQUEST,
	PROPERTY_NOTIFY,
	SELECTION_CLEAR,
	SELECTION_REQUEST,
	SELECTION_NOTIFY,
	COLORMAP_NOTIFY,
	CLIENT_MESSAGE,
	MAPPING_NOTIFY,
	GENERIC_EVENT,
	LAST_EVENT
}				t_x11_event;

// for Unix OS mask
// 0L		NoEventMask
// (1L<<0)	KeyPressMask
// (1L<<1)	KeyReleaseMask
// (1L<<2)	ButtonPressMask
// (1L<<3)	ButtonReleaseMask
// (1L<<4)	EnterWindowMask
// (1L<<5)	LeaveWindowMask
// (1L<<6)	PointerMotionMask
// (1L<<7)	PointerMotionHintMask
// (1L<<8)	Button1MotionMask
// (1L<<9)	Button2MotionMask
// (1L<<10)	Button3MotionMask
// (1L<<11)	Button4MotionMask
// (1L<<12)	Button5MotionMask
// (1L<<13)	ButtonMotionMask
// (1L<<14)	KeymapStateMask
// (1L<<15)	ExposureMask
// (1L<<16)	VisibilityChangeMask
// (1L<<17)	StructureNotifyMask
// (1L<<18)	ResizeRedirectMask
// (1L<<19)	SubstructureNotifyMask
// (1L<<20)	SubstructureRedirectMask
// (1L<<21)	FocusChangeMask
// (1L<<22)	PropertyChangeMask
// (1L<<23)	ColormapChangeMask
// (1L<<24)	OwnerGrabButtonMask

// int mlx_mouse_hide();
// int mlx_mouse_show();
// int mlx_mouse move(void *win_ptr, int x, int y);
// int mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

// #define KeyPressMask	(1L<<0)
// #define KeyReleaseMask	(1L<<1)
// #define Button3MotionMask	(1L<<10)
// #define Button4MotionMask	(1L<<11)
// #define Button5MotionMask	(1L<<12)
// #define ButtonMotionMask	(1L<<13)
// #define KeymapStateMask	(1L<<14)
// #define ExposureMask	(1L<<15)
// #define VisibilityChangeMask	(1L<<16)
// #define StructureNotifyMask	(1L<<17)
// #define ResizeRedirectMask	(1L<<18)
// #define SubstructureNotifyMask	(1L<<19)
// #define ButtonPressMask	(1L<<2)
// #define SubstructureRedirectMask	(1L<<20)
// #define FocusChangeMask	(1L<<21)
// #define PropertyChangeMask	(1L<<22)
// #define ColormapChangeMask	(1L<<23)
// #define OwnerGrabButtonMask	(1L<<24)
// #define ButtonReleaseMask	(1L<<3)
// #define EnterWindowMask	(1L<<4)
// #define LeaveWindowMask	(1L<<5)
// #define PointerMotionMask	(1L<<6)
// #define PointerMotionHintMask	(1L<<7)
// #define Button1MotionMask	(1L<<8)
// #define Button2MotionMask	(1L<<9)

#endif
