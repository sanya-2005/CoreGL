#pragma once

enum Keys
{
	A,
	D,
	S,
	W,
	C,
	Enter,
	Esc,
	UnknownKey
};

enum ModiferKeys
{
	Ctrl,
	Alt,
	Shift,
	None
};

enum KeyActions
{
	KeyUp,
	KeyDown,
};

typedef void (*KeyInputCallback)(Keys key, ModiferKeys modifer, KeyActions action);