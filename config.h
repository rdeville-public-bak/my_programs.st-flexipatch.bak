/* See LICENSE file for copyright and license details. */

/*
 * appearance
 *
 * font: see http://freedesktop.org/software/fontconfig/fontconfig-user.html
 */
static char *font = "Fira Code:pixelsize=14:antialias=true:autohint=true";
#if FONT2_PATCH
/* Spare fonts */
static char *font2[] = {
  "Twemoji Mozilla:pixelsize=14:antialias=true:autohint=true",
  "Twitter Color Emoji:pixelsize=14:antialias=true:autohint=true",
  "JoyPixels:pixelsize=14:antialias=true:autohint=true",
  "Noto Color Emoji:pixelsize=14:antialias=true:autohint=true",
  "Fira Code Nerd Font:pixelsize=14:antialias=true:autohint=true", //Powerline
};
#endif // FONT2_PATCH

#if RELATIVEBORDER_PATCH
/* borderperc: percentage of cell width to use as a border
 *             0 = no border, 100 = border width is same as cell width */
int borderperc = 0;
#else
static int borderpx = 2;
#endif // RELATIVEBORDER_PATCH

#if OPENURLONCLICK_PATCH
static char *url_opener = "xdg-open";
#endif // OPENURLONCLICK_PATCH

/*
 * What program is execed by st depends of these precedence rules:
 * 1: program passed with -e
 * 2: scroll and/or utmp
 * 3: SHELL environment variable
 * 4: value of shell in /etc/passwd
 * 5: value of shell in config.h
 */
static char *shell = "/bin/sh";
char *utmp = NULL;
/* scroll program: to enable use a string like "scroll" */
char *scroll = NULL;
char *stty_args = "stty raw pass8 nl -echo -iexten -cstopb 38400";

/* identification sequence returned in DA and DECID */
#if SIXEL_PATCH
char *vtiden = "\033[?12;4c";
#else
char *vtiden = "\033[?6c";
#endif

/* Kerning / character bounding-box multipliers */
static float cwscale = 1.0;
static float chscale = 1.0;

/*
 * word delimiter string
 *
 * More advanced example: L" `'\"()[]{}"
 */
wchar_t *worddelimiters = L" ";

/* selection timeouts (in milliseconds) */
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;

/* alt screens */
int allowaltscreen = 1;

/* allow certain non-interactive (insecure) window operations such as:
   setting the clipboard text */
int allowwindowops = 0;

/*
 * draw latency range in ms - from new content/keypress/etc until drawing.
 * within this range, st draws when content stops arriving (idle). mostly it's
 * near minlatency, but it waits longer for slow updates to avoid partial draw.
 * low minlatency will tear/flicker more, as it can "detect" idle too early.
 */
static double minlatency = 8;
static double maxlatency = 33;

#if SYNC_PATCH
/*
 * Synchronized-Update timeout in ms
 * https://gitlab.com/gnachman/iterm2/-/wikis/synchronized-updates-spec
 */
static uint su_timeout = 200;
#endif // SYNC_PATCH

/*
 * blinking timeout (set to 0 to disable blinking) for the terminal blinking
 * attribute.
 */
static unsigned int blinktimeout = 800;

/*
 * thickness of underline and bar cursors
 */
static unsigned int cursorthickness = 2;

#if BOXDRAW_PATCH
/*
 * 1: render most of the lines/blocks characters without using the font for
 *    perfect alignment between cells (U2500 - U259F except dashes/diagonals).
 *    Bold affects lines thickness if boxdraw_bold is not 0. Italic is ignored.
 * 0: disable (render all U25XX glyphs normally from the font).
 */
const int boxdraw = 0;
const int boxdraw_bold = 0;

/* braille (U28XX):  1: render as adjacent "pixels",  0: use font */
const int boxdraw_braille = 0;
#endif // BOXDRAW_PATCH

/*
 * bell volume. It must be a value between -100 and 100. Use 0 for disabling
 * it
 */
static int bellvolume = 0;

/* default TERM value */
char *termname = "st-256color";

/*
 * spaces per tab
 *
 * When you are changing this value, don't forget to adapt the »it« value in
 * the st.info and appropriately install the st.info in the environment where
 * you use this st version.
 *
 *  it#$tabspaces,
 *
 * Secondly make sure your kernel is not expanding tabs. When running `stty
 * -a` »tab0« should appear. You can tell the terminal to not expand tabs by
 *  running following command:
 *
 *  stty tabs
 */
unsigned int tabspaces = 8;

#if ALPHA_PATCH
/* bg opacity */
float alpha = 0.75;
#if ALPHA_GRADIENT_PATCH
float grad_alpha = 0.54; //alpha value that'll change
float stat_alpha = 0.46; //constant alpha value that'll get added to grad_alpha
#endif // ALPHA_GRADIENT_PATCH
#if ALPHA_FOCUS_HIGHLIGHT_PATCH
float alphaUnfocused = 0.75;
#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
#endif // ALPHA_PATCH

/* Terminal colors (16 first used in escape sequence) */
/* Old terminal color version before using base16 */
static const char *colorname[] = {
  // 8 normal colors
  "#000000", // black
  "#d32f2f", // red_700
  "#388e3c", // green_700
  "#fbc02d", // yellow_700
  "#1976d2", // blue_700
  "#7b1fa2", // purple_700
  "#0097a7", // cyan_700
  "#f5f5f5",
  // 8 bright colors
  "#616161", // grey_700
  "#e57373", // red_300
  "#81c784", // green_300
  "#fff176", // yellow_300
  "#64b5f6", // blue_300
  "#ba68c8", // purple_300
  "#4dd0e1", // cyan_300
  "#e0e0e0", // grey_300

  [255] = 0,

  // more colors can be added after 255 to use with DefaultXX
  "#add8e6", // 256 -> cursor
  "#555555", // 257 -> rev cursor
  "#000000", // 258 -> bg
  "#e5e5e5", // 259 -> fg
  "#eeeeee",
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
#if ALPHA_PATCH && ALPHA_FOCUS_HIGHLIGHT_PATCH
unsigned int defaultbg = 0;
unsigned int bg = 0, bgUnfocused = 8;
#else
unsigned int defaultbg = 0;
#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
unsigned int defaultfg = 7;
unsigned int defaultcs = 13;
unsigned int defaultrcs = 0;

#if VIM_BROWSE_PATCH
unsigned int const currentBg = 8, buffSize = 2048;
/// Enable double / triple click yanking / selection of word / line.
int const mouseYank = 1, mouseSelect = 0;
/// [Vim Browse] Colors for search results currently on screen.
unsigned int const highlightBg = 160, highlightFg = 15;
char const wDelS[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~", wDelL[] = " \t";
char *nmKeys [] = {              ///< Shortcusts executed in normal mode
  "R/Building\nN", "r/Building\n", "X/juli@machine\nN", "x/juli@machine\n",
  "Q?[Leaving vim, starting execution]\n","F/: error:\nN", "f/: error:\n", "DQf"
};
unsigned int const amountNmKeys = sizeof(nmKeys) / sizeof(*nmKeys);
/// Style of the {command, search} string shown in the right corner (y,v,V,/)
Glyph styleSearch = {' ', ATTR_ITALIC | ATTR_BOLD_FAINT, 7, 16};
Glyph style[] = {{' ',ATTR_ITALIC|ATTR_FAINT,15,16}, {' ',ATTR_ITALIC,232,11},
                 {' ', ATTR_ITALIC, 232, 4}, {' ', ATTR_ITALIC, 232, 12}};
#endif // VIM_BROWSE_PATCH

#if BLINKING_CURSOR_PATCH
/*
 * https://invisible-island.net/xterm/ctlseqs/ctlseqs.html#h4-Functions-using-CSI-_-ordered-by-the-final-character-lparen-s-rparen:CSI-Ps-SP-q.1D81
 * Default style of cursor
 * 0: Blinking block
 * 1: Blinking block (default)
 * 2: Steady block ("â–ˆ")
 * 3: Blinking underline
 * 4: Steady underline ("_")
 * 5: Blinking bar
 * 6: Steady bar ("|")
 * 7: Blinking st cursor
 * 8: Steady st cursor
 */
static unsigned int cursorstyle = 1;
static Rune stcursor = 0x2603; /* snowman (U+2603) */
#else
/*
 * Default shape of cursor
 * 2: Block ("█")
 * 4: Underline ("_")
 * 6: Bar ("|")
 * 7: Snowman ("☃")
 */
static unsigned int cursorshape = 2;
#endif // BLINKING_CURSOR_PATCH

/*
 * Default columns and rows numbers
 */

static unsigned int cols = 80;
static unsigned int rows = 24;

#if THEMED_CURSOR_PATCH
/*
 * Default shape of the mouse cursor
 */
static char* mouseshape = "xterm";
#else
/*
 * Default colour and shape of the mouse cursor
 */
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;
#endif // THEMED_CURSOR_PATCH

/*
 * Color used to display font attributes when fontconfig selected a font which
 * doesn't match the ones requested.
 */
static unsigned int defaultattr = 11;

#if XRESOURCES_PATCH
/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
    { "font",         STRING,  &font },
    { "color0",       STRING,  &colorname[0] },
    { "color1",       STRING,  &colorname[1] },
    { "color2",       STRING,  &colorname[2] },
    { "color3",       STRING,  &colorname[3] },
    { "color4",       STRING,  &colorname[4] },
    { "color5",       STRING,  &colorname[5] },
    { "color6",       STRING,  &colorname[6] },
    { "color7",       STRING,  &colorname[7] },
    { "color8",       STRING,  &colorname[8] },
    { "color9",       STRING,  &colorname[9] },
    { "color10",      STRING,  &colorname[10] },
    { "color11",      STRING,  &colorname[11] },
    { "color12",      STRING,  &colorname[12] },
    { "color13",      STRING,  &colorname[13] },
    { "color14",      STRING,  &colorname[14] },
    { "color15",      STRING,  &colorname[15] },
    { "background",   STRING,  &colorname[258] },
    { "foreground",   STRING,  &colorname[259] },
    { "cursorColor",  STRING,  &colorname[256] },
    { "termname",     STRING,  &termname },
    { "shell",        STRING,  &shell },
    { "minlatency",   INTEGER, &minlatency },
    { "maxlatency",   INTEGER, &maxlatency },
    { "blinktimeout", INTEGER, &blinktimeout },
    { "bellvolume",   INTEGER, &bellvolume },
    { "tabspaces",    INTEGER, &tabspaces },
    #if RELATIVEBORDER_PATCH
    { "borderperc",   INTEGER, &borderperc },
    #else
    { "borderpx",     INTEGER, &borderpx },
    #endif // RELATIVEBORDER_PATCH
    { "cwscale",      FLOAT,   &cwscale },
    { "chscale",      FLOAT,   &chscale },
    #if ALPHA_PATCH
    { "alpha",        FLOAT,   &alpha },
    #endif // ALPHA_PATCH
    #if ALPHA_FOCUS_HIGHLIGHT_PATCH
    { "alphaUnfocused",FLOAT,  &alphaUnfocused },
    #endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
};
#endif // XRESOURCES_PATCH

/*
 * Force mouse select/shortcuts while mask is active (when MODE_MOUSE is set).
 * Note that if you want to use ShiftMask with selmasks, set this to an other
 * modifier, set to 0 to not use it.
 */
static uint forcemousemod = ShiftMask;

/*
 * Internal mouse shortcuts.
 * Beware that overloading Button1 will disable the selection.
 */
static MouseShortcut mshortcuts[] = {
  #if UNIVERSCROLL_PATCH
  /* mask                 button   function        argument       release   alt */
  #else
  /* mask                 button   function        argument       release */
  #endif // UNIVERSCROLL_PATCH
  #if CLIPBOARD_PATCH
  { XK_ANY_MOD,           Button2, clippaste,      {.i = 0},      1 },
  #else
  { XK_ANY_MOD,           Button2, selpaste,       {.i = 0},      1 },
  #endif // CLIPBOARD_PATCH
  #if SCROLLBACK_MOUSE_PATCH
  { ShiftMask,            Button4, kscrollup,      {.i = 1} },
  { ShiftMask,            Button5, kscrolldown,    {.i = 1} },
  #elif UNIVERSCROLL_PATCH
  { XK_ANY_MOD,           Button4, ttysend,        {.s = "\033[5;2~"}, 0, -1 },
  { XK_ANY_MOD,           Button5, ttysend,        {.s = "\033[6;2~"}, 0, -1 },
  #else
  { ShiftMask,            Button4, ttysend,        {.s = "\033[5;2~"} },
  { ShiftMask,            Button5, ttysend,        {.s = "\033[6;2~"} },
  #endif // SCROLLBACK_MOUSE_PATCH
  #if SCROLLBACK_MOUSE_ALTSCREEN_PATCH
  { XK_NO_MOD,            Button4, kscrollup,      {.i = 1} },
  { XK_NO_MOD,            Button5, kscrolldown,    {.i = 1} },
  #else
  { XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"} },
  { XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"} },
  #endif // SCROLLBACK_MOUSE_ALTSCREEN_PATCH
};

#if SCROLLBACK_MOUSE_ALTSCREEN_PATCH
static MouseShortcut maltshortcuts[] = {
  /* mask                 button   function        argument       release */
  #if CLIPBOARD_PATCH
  { XK_ANY_MOD,           Button2, clippaste,      {.i = 0},      1 },
  #else
  { XK_ANY_MOD,           Button2, selpaste,       {.i = 0},      1 },
  #endif // CLIPBOARD_PATCH
  { XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"} },
  { XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"} },
};
#endif // SCROLLBACK_MOUSE_ALTSCREEN_PATCH

/* Internal keyboard shortcuts. */
#define MODKEY Mod1Mask
#define TERMMOD (ControlMask|ShiftMask)

#if EXTERNALPIPE_PATCH // example command
static char *openurlcmd[] = { "/bin/sh" , "-c" , "st-urlhandler -o" , "externalpipe" , NULL };
static char *copyurlcmd[] = { "/bin/sh" , "-c" , "st-urlhandler -c" , "externalpipe" , NULL };
#endif // EXTERNALPIPE_PATCH

static Shortcut shortcuts[] = {
  /* mask                 keysym          function         argument */
  { XK_ANY_MOD,           XK_Break,       sendbreak,       {.i =  0} },
  { ControlMask,          XK_Print,       toggleprinter,   {.i =  0} },
  { ShiftMask,            XK_Print,       printscreen,     {.i =  0} },
  { XK_ANY_MOD,           XK_Print,       printsel,        {.i =  0} },
  { TERMMOD,              XK_Prior,       zoom,            {.f = +1} },
  { TERMMOD,              XK_Next,        zoom,            {.f = -1} },
  { TERMMOD,              XK_Home,        zoomreset,       {.f =  0} },
  { TERMMOD,              XK_plus,        zoom,            {.f = +1} },
  { TERMMOD,              XK_degree,      zoom,            {.f = -1} },
  { TERMMOD,              XK_0,           zoomreset,       {.f =  0} },
  { MODKEY,               XK_c,           clipcopy,        {.i =  0} },
  { MODKEY,               XK_v,           clippaste,       {.i =  0} },
  #if SCROLLBACK_PATCH
  { MODKEY|ShiftMask,     XK_U,           kscrollup,       {.i = -1} },
  { MODKEY|ShiftMask,     XK_D,           kscrolldown,     {.i = -1} },
  { MODKEY|ShiftMask,     XK_K,           kscrollup,       {.i = 1} },
  { MODKEY|ShiftMask,     XK_J,           kscrolldown,     {.i = 1} },
  #endif // SCROLLBACK_PATCH
  #if CLIPBOARD_PATCH
  { TERMMOD,              XK_Y,           clippaste,       {.i =  0} },
  { ShiftMask,            XK_Insert,      clippaste,       {.i =  0} },
  #else
  { TERMMOD,              XK_Y,           selpaste,        {.i =  0} },
  { ShiftMask,            XK_Insert,      selpaste,        {.i =  0} },
  #endif // CLIPBOARD_PATCH
  { TERMMOD,              XK_Num_Lock,    numlock,         {.i =  0} },
  #if EXTERNALPIPE_PATCH
  { MODKEY,               XK_o,           externalpipe,    {.v =  openurlcmd} },
  { MODKEY,               XK_y,           externalpipe,    {.v =  copyurlcmd} },
  #endif // EXTERNALPIPE_PATCH
  #if OPENCOPIED_PATCH
  { MODKEY,               XK_o,           opencopied,      {.v = "xdg-open"} },
  #endif // OPENCOPIED_PATCH
  #if NEWTERM_PATCH
  { TERMMOD,              XK_Return,      newterm,         {.i =  0} },
  #endif // NEWTERM_PATCH
  #if KEYBOARDSELECT_PATCH
  { MODKEY|ShiftMask,     XK_Escape,      keyboard_select, { 0 } },
  #endif // KEYBOARDSELECT_PATCH
  #if ISO14755_PATCH
  { TERMMOD,              XK_I,           iso14755,        {.i =  0} },
  #endif // ISO14755_PATCH
  #if INVERT_PATCH
  { TERMMOD,              XK_X,           invert,          { 0 } },
  #endif // INVERT_PATCH
  #if VIM_BROWSE_PATCH
  { TERMMOD,              XK_Escape,      normalMode,      { .i = 0} },
  #endif // VIM_BROWSE_PATCH
};

/*
 * Special keys (change & recompile st.info accordingly)
 *
 * Mask value:
 * * Use XK_ANY_MOD to match the key no matter modifiers state
 * * Use XK_NO_MOD to match the key alone (no modifiers)
 * appkey value:
 * * 0: no value
 * * > 0: keypad application mode enabled
 * *   = 2: term.numlock = 1
 * * < 0: keypad application mode disabled
 * appcursor value:
 * * 0: no value
 * * > 0: cursor application mode enabled
 * * < 0: cursor application mode disabled
 *
 * Be careful with the order of the definitions because st searches in
 * this table sequentially, so any XK_ANY_MOD must be in the last
 * position for a key.
 */

#if !FIXKEYBOARDINPUT_PATCH
/*
 * If you want keys other than the X11 function keys (0xFD00 - 0xFFFF)
 * to be mapped below, add them to this array.
 */
static KeySym mappedkeys[] = { -1 };
#endif // FIXKEYBOARDINPUT_PATCH

/*
 * State bits to ignore when matching key or button events.  By default,
 * numlock (Mod2Mask) and keyboard layout (XK_SWITCH_MOD) are ignored.
 */
static uint ignoremod = Mod2Mask|XK_SWITCH_MOD;

#if !FIXKEYBOARDINPUT_PATCH
/*
 * This is the huge key array which defines all compatibility to the Linux
 * world. Please decide about changes wisely.
 */
static Key key[] = {
  /* keysym           mask            string      appkey appcursor */
  { XK_KP_Home,       ShiftMask,      "\033[2J",       0,   -1},
  { XK_KP_Home,       ShiftMask,      "\033[1;2H",     0,   +1},
  { XK_KP_Home,       XK_ANY_MOD,     "\033[H",        0,   -1},
  { XK_KP_Home,       XK_ANY_MOD,     "\033[1~",       0,   +1},
  { XK_KP_Up,         XK_ANY_MOD,     "\033Ox",       +1,    0},
  { XK_KP_Up,         XK_ANY_MOD,     "\033[A",        0,   -1},
  { XK_KP_Up,         XK_ANY_MOD,     "\033OA",        0,   +1},
  { XK_KP_Down,       XK_ANY_MOD,     "\033Or",       +1,    0},
  { XK_KP_Down,       XK_ANY_MOD,     "\033[B",        0,   -1},
  { XK_KP_Down,       XK_ANY_MOD,     "\033OB",        0,   +1},
  { XK_KP_Left,       XK_ANY_MOD,     "\033Ot",       +1,    0},
  { XK_KP_Left,       XK_ANY_MOD,     "\033[D",        0,   -1},
  { XK_KP_Left,       XK_ANY_MOD,     "\033OD",        0,   +1},
  { XK_KP_Right,      XK_ANY_MOD,     "\033Ov",       +1,    0},
  { XK_KP_Right,      XK_ANY_MOD,     "\033[C",        0,   -1},
  { XK_KP_Right,      XK_ANY_MOD,     "\033OC",        0,   +1},
  { XK_KP_Prior,      ShiftMask,      "\033[5;2~",     0,    0},
  { XK_KP_Prior,      XK_ANY_MOD,     "\033[5~",       0,    0},
  { XK_KP_Begin,      XK_ANY_MOD,     "\033[E",        0,    0},
  { XK_KP_End,        ControlMask,    "\033[J",       -1,    0},
  { XK_KP_End,        ControlMask,    "\033[1;5F",    +1,    0},
  { XK_KP_End,        ShiftMask,      "\033[K",       -1,    0},
  { XK_KP_End,        ShiftMask,      "\033[1;2F",    +1,    0},
  { XK_KP_End,        XK_ANY_MOD,     "\033[4~",       0,    0},
  { XK_KP_Next,       ShiftMask,      "\033[6;2~",     0,    0},
  { XK_KP_Next,       XK_ANY_MOD,     "\033[6~",       0,    0},
  { XK_KP_Insert,     ShiftMask,      "\033[2;2~",    +1,    0},
  { XK_KP_Insert,     ShiftMask,      "\033[4l",      -1,    0},
  { XK_KP_Insert,     ControlMask,    "\033[L",       -1,    0},
  { XK_KP_Insert,     ControlMask,    "\033[2;5~",    +1,    0},
  { XK_KP_Insert,     XK_ANY_MOD,     "\033[4h",      -1,    0},
  { XK_KP_Insert,     XK_ANY_MOD,     "\033[2~",      +1,    0},
  { XK_KP_Delete,     ControlMask,    "\033[M",       -1,    0},
  { XK_KP_Delete,     ControlMask,    "\033[3;5~",    +1,    0},
  { XK_KP_Delete,     ShiftMask,      "\033[2K",      -1,    0},
  { XK_KP_Delete,     ShiftMask,      "\033[3;2~",    +1,    0},
  #if DELKEY_PATCH
  { XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      -1,    0},
  #else
  { XK_KP_Delete,     XK_ANY_MOD,     "\033[P",       -1,    0},
  #endif // DELKEY_PATCH
  { XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      +1,    0},
  { XK_KP_Multiply,   XK_ANY_MOD,     "\033Oj",       +2,    0},
  { XK_KP_Add,        XK_ANY_MOD,     "\033Ok",       +2,    0},
  { XK_KP_Enter,      XK_ANY_MOD,     "\033OM",       +2,    0},
  { XK_KP_Enter,      XK_ANY_MOD,     "\r",           -1,    0},
  { XK_KP_Subtract,   XK_ANY_MOD,     "\033Om",       +2,    0},
  { XK_KP_Decimal,    XK_ANY_MOD,     "\033On",       +2,    0},
  { XK_KP_Divide,     XK_ANY_MOD,     "\033Oo",       +2,    0},
  { XK_KP_0,          XK_ANY_MOD,     "\033Op",       +2,    0},
  { XK_KP_1,          XK_ANY_MOD,     "\033Oq",       +2,    0},
  { XK_KP_2,          XK_ANY_MOD,     "\033Or",       +2,    0},
  { XK_KP_3,          XK_ANY_MOD,     "\033Os",       +2,    0},
  { XK_KP_4,          XK_ANY_MOD,     "\033Ot",       +2,    0},
  { XK_KP_5,          XK_ANY_MOD,     "\033Ou",       +2,    0},
  { XK_KP_6,          XK_ANY_MOD,     "\033Ov",       +2,    0},
  { XK_KP_7,          XK_ANY_MOD,     "\033Ow",       +2,    0},
  { XK_KP_8,          XK_ANY_MOD,     "\033Ox",       +2,    0},
  { XK_KP_9,          XK_ANY_MOD,     "\033Oy",       +2,    0},
  { XK_Up,            ShiftMask,      "\033[1;2A",     0,    0},
  { XK_Up,            Mod1Mask,       "\033[1;3A",     0,    0},
  { XK_Up,         ShiftMask|Mod1Mask,"\033[1;4A",     0,    0},
  { XK_Up,            ControlMask,    "\033[1;5A",     0,    0},
  { XK_Up,      ShiftMask|ControlMask,"\033[1;6A",     0,    0},
  { XK_Up,       ControlMask|Mod1Mask,"\033[1;7A",     0,    0},
  { XK_Up,ShiftMask|ControlMask|Mod1Mask,"\033[1;8A",  0,    0},
  { XK_Up,            XK_ANY_MOD,     "\033[A",        0,   -1},
  { XK_Up,            XK_ANY_MOD,     "\033OA",        0,   +1},
  { XK_Down,          ShiftMask,      "\033[1;2B",     0,    0},
  { XK_Down,          Mod1Mask,       "\033[1;3B",     0,    0},
  { XK_Down,       ShiftMask|Mod1Mask,"\033[1;4B",     0,    0},
  { XK_Down,          ControlMask,    "\033[1;5B",     0,    0},
  { XK_Down,    ShiftMask|ControlMask,"\033[1;6B",     0,    0},
  { XK_Down,     ControlMask|Mod1Mask,"\033[1;7B",     0,    0},
  { XK_Down,ShiftMask|ControlMask|Mod1Mask,"\033[1;8B",0,    0},
  { XK_Down,          XK_ANY_MOD,     "\033[B",        0,   -1},
  { XK_Down,          XK_ANY_MOD,     "\033OB",        0,   +1},
  { XK_Left,          ShiftMask,      "\033[1;2D",     0,    0},
  { XK_Left,          Mod1Mask,       "\033[1;3D",     0,    0},
  { XK_Left,       ShiftMask|Mod1Mask,"\033[1;4D",     0,    0},
  { XK_Left,          ControlMask,    "\033[1;5D",     0,    0},
  { XK_Left,    ShiftMask|ControlMask,"\033[1;6D",     0,    0},
  { XK_Left,     ControlMask|Mod1Mask,"\033[1;7D",     0,    0},
  { XK_Left,ShiftMask|ControlMask|Mod1Mask,"\033[1;8D",0,    0},
  { XK_Left,          XK_ANY_MOD,     "\033[D",        0,   -1},
  { XK_Left,          XK_ANY_MOD,     "\033OD",        0,   +1},
  { XK_Right,         ShiftMask,      "\033[1;2C",     0,    0},
  { XK_Right,         Mod1Mask,       "\033[1;3C",     0,    0},
  { XK_Right,      ShiftMask|Mod1Mask,"\033[1;4C",     0,    0},
  { XK_Right,         ControlMask,    "\033[1;5C",     0,    0},
  { XK_Right,   ShiftMask|ControlMask,"\033[1;6C",     0,    0},
  { XK_Right,    ControlMask|Mod1Mask,"\033[1;7C",     0,    0},
  { XK_Right,ShiftMask|ControlMask|Mod1Mask,"\033[1;8C",0,   0},
  { XK_Right,         XK_ANY_MOD,     "\033[C",        0,   -1},
  { XK_Right,         XK_ANY_MOD,     "\033OC",        0,   +1},
  { XK_ISO_Left_Tab,  ShiftMask,      "\033[Z",        0,    0},
  { XK_Return,        Mod1Mask,       "\033\r",        0,    0},
  { XK_Return,        XK_ANY_MOD,     "\r",            0,    0},
  { XK_Insert,        ShiftMask,      "\033[4l",      -1,    0},
  { XK_Insert,        ShiftMask,      "\033[2;2~",    +1,    0},
  { XK_Insert,        ControlMask,    "\033[L",       -1,    0},
  { XK_Insert,        ControlMask,    "\033[2;5~",    +1,    0},
  { XK_Insert,        XK_ANY_MOD,     "\033[4h",      -1,    0},
  { XK_Insert,        XK_ANY_MOD,     "\033[2~",      +1,    0},
  { XK_Delete,        ControlMask,    "\033[M",       -1,    0},
  { XK_Delete,        ControlMask,    "\033[3;5~",    +1,    0},
  { XK_Delete,        ShiftMask,      "\033[2K",      -1,    0},
  { XK_Delete,        ShiftMask,      "\033[3;2~",    +1,    0},
  #if DELKEY_PATCH
  { XK_Delete,        XK_ANY_MOD,     "\033[3~",      -1,    0},
  #else
  { XK_Delete,        XK_ANY_MOD,     "\033[P",       -1,    0},
  #endif // DELKEY_PATCH
  { XK_Delete,        XK_ANY_MOD,     "\033[3~",      +1,    0},
  { XK_BackSpace,     XK_NO_MOD,      "\177",          0,    0},
  { XK_BackSpace,     Mod1Mask,       "\033\177",      0,    0},
  { XK_Home,          ShiftMask,      "\033[2J",       0,   -1},
  { XK_Home,          ShiftMask,      "\033[1;2H",     0,   +1},
  { XK_Home,          XK_ANY_MOD,     "\033[H",        0,   -1},
  { XK_Home,          XK_ANY_MOD,     "\033[1~",       0,   +1},
  { XK_End,           ControlMask,    "\033[J",       -1,    0},
  { XK_End,           ControlMask,    "\033[1;5F",    +1,    0},
  { XK_End,           ShiftMask,      "\033[K",       -1,    0},
  { XK_End,           ShiftMask,      "\033[1;2F",    +1,    0},
  { XK_End,           XK_ANY_MOD,     "\033[4~",       0,    0},
  { XK_Prior,         ControlMask,    "\033[5;5~",     0,    0},
  { XK_Prior,         ShiftMask,      "\033[5;2~",     0,    0},
  { XK_Prior,         XK_ANY_MOD,     "\033[5~",       0,    0},
  { XK_Next,          ControlMask,    "\033[6;5~",     0,    0},
  { XK_Next,          ShiftMask,      "\033[6;2~",     0,    0},
  { XK_Next,          XK_ANY_MOD,     "\033[6~",       0,    0},
  { XK_F1,            XK_NO_MOD,      "\033OP" ,       0,    0},
  { XK_F1, /* F13 */  ShiftMask,      "\033[1;2P",     0,    0},
  { XK_F1, /* F25 */  ControlMask,    "\033[1;5P",     0,    0},
  { XK_F1, /* F37 */  Mod4Mask,       "\033[1;6P",     0,    0},
  { XK_F1, /* F49 */  Mod1Mask,       "\033[1;3P",     0,    0},
  { XK_F1, /* F61 */  Mod3Mask,       "\033[1;4P",     0,    0},
  { XK_F2,            XK_NO_MOD,      "\033OQ" ,       0,    0},
  { XK_F2, /* F14 */  ShiftMask,      "\033[1;2Q",     0,    0},
  { XK_F2, /* F26 */  ControlMask,    "\033[1;5Q",     0,    0},
  { XK_F2, /* F38 */  Mod4Mask,       "\033[1;6Q",     0,    0},
  { XK_F2, /* F50 */  Mod1Mask,       "\033[1;3Q",     0,    0},
  { XK_F2, /* F62 */  Mod3Mask,       "\033[1;4Q",     0,    0},
  { XK_F3,            XK_NO_MOD,      "\033OR" ,       0,    0},
  { XK_F3, /* F15 */  ShiftMask,      "\033[1;2R",     0,    0},
  { XK_F3, /* F27 */  ControlMask,    "\033[1;5R",     0,    0},
  { XK_F3, /* F39 */  Mod4Mask,       "\033[1;6R",     0,    0},
  { XK_F3, /* F51 */  Mod1Mask,       "\033[1;3R",     0,    0},
  { XK_F3, /* F63 */  Mod3Mask,       "\033[1;4R",     0,    0},
  { XK_F4,            XK_NO_MOD,      "\033OS" ,       0,    0},
  { XK_F4, /* F16 */  ShiftMask,      "\033[1;2S",     0,    0},
  { XK_F4, /* F28 */  ControlMask,    "\033[1;5S",     0,    0},
  { XK_F4, /* F40 */  Mod4Mask,       "\033[1;6S",     0,    0},
  { XK_F4, /* F52 */  Mod1Mask,       "\033[1;3S",     0,    0},
  { XK_F5,            XK_NO_MOD,      "\033[15~",      0,    0},
  { XK_F5, /* F17 */  ShiftMask,      "\033[15;2~",    0,    0},
  { XK_F5, /* F29 */  ControlMask,    "\033[15;5~",    0,    0},
  { XK_F5, /* F41 */  Mod4Mask,       "\033[15;6~",    0,    0},
  { XK_F5, /* F53 */  Mod1Mask,       "\033[15;3~",    0,    0},
  { XK_F6,            XK_NO_MOD,      "\033[17~",      0,    0},
  { XK_F6, /* F18 */  ShiftMask,      "\033[17;2~",    0,    0},
  { XK_F6, /* F30 */  ControlMask,    "\033[17;5~",    0,    0},
  { XK_F6, /* F42 */  Mod4Mask,       "\033[17;6~",    0,    0},
  { XK_F6, /* F54 */  Mod1Mask,       "\033[17;3~",    0,    0},
  { XK_F7,            XK_NO_MOD,      "\033[18~",      0,    0},
  { XK_F7, /* F19 */  ShiftMask,      "\033[18;2~",    0,    0},
  { XK_F7, /* F31 */  ControlMask,    "\033[18;5~",    0,    0},
  { XK_F7, /* F43 */  Mod4Mask,       "\033[18;6~",    0,    0},
  { XK_F7, /* F55 */  Mod1Mask,       "\033[18;3~",    0,    0},
  { XK_F8,            XK_NO_MOD,      "\033[19~",      0,    0},
  { XK_F8, /* F20 */  ShiftMask,      "\033[19;2~",    0,    0},
  { XK_F8, /* F32 */  ControlMask,    "\033[19;5~",    0,    0},
  { XK_F8, /* F44 */  Mod4Mask,       "\033[19;6~",    0,    0},
  { XK_F8, /* F56 */  Mod1Mask,       "\033[19;3~",    0,    0},
  { XK_F9,            XK_NO_MOD,      "\033[20~",      0,    0},
  { XK_F9, /* F21 */  ShiftMask,      "\033[20;2~",    0,    0},
  { XK_F9, /* F33 */  ControlMask,    "\033[20;5~",    0,    0},
  { XK_F9, /* F45 */  Mod4Mask,       "\033[20;6~",    0,    0},
  { XK_F9, /* F57 */  Mod1Mask,       "\033[20;3~",    0,    0},
  { XK_F10,           XK_NO_MOD,      "\033[21~",      0,    0},
  { XK_F10, /* F22 */ ShiftMask,      "\033[21;2~",    0,    0},
  { XK_F10, /* F34 */ ControlMask,    "\033[21;5~",    0,    0},
  { XK_F10, /* F46 */ Mod4Mask,       "\033[21;6~",    0,    0},
  { XK_F10, /* F58 */ Mod1Mask,       "\033[21;3~",    0,    0},
  { XK_F11,           XK_NO_MOD,      "\033[23~",      0,    0},
  { XK_F11, /* F23 */ ShiftMask,      "\033[23;2~",    0,    0},
  { XK_F11, /* F35 */ ControlMask,    "\033[23;5~",    0,    0},
  { XK_F11, /* F47 */ Mod4Mask,       "\033[23;6~",    0,    0},
  { XK_F11, /* F59 */ Mod1Mask,       "\033[23;3~",    0,    0},
  { XK_F12,           XK_NO_MOD,      "\033[24~",      0,    0},
  { XK_F12, /* F24 */ ShiftMask,      "\033[24;2~",    0,    0},
  { XK_F12, /* F36 */ ControlMask,    "\033[24;5~",    0,    0},
  { XK_F12, /* F48 */ Mod4Mask,       "\033[24;6~",    0,    0},
  { XK_F12, /* F60 */ Mod1Mask,       "\033[24;3~",    0,    0},
  { XK_F13,           XK_NO_MOD,      "\033[1;2P",     0,    0},
  { XK_F14,           XK_NO_MOD,      "\033[1;2Q",     0,    0},
  { XK_F15,           XK_NO_MOD,      "\033[1;2R",     0,    0},
  { XK_F16,           XK_NO_MOD,      "\033[1;2S",     0,    0},
  { XK_F17,           XK_NO_MOD,      "\033[15;2~",    0,    0},
  { XK_F18,           XK_NO_MOD,      "\033[17;2~",    0,    0},
  { XK_F19,           XK_NO_MOD,      "\033[18;2~",    0,    0},
  { XK_F20,           XK_NO_MOD,      "\033[19;2~",    0,    0},
  { XK_F21,           XK_NO_MOD,      "\033[20;2~",    0,    0},
  { XK_F22,           XK_NO_MOD,      "\033[21;2~",    0,    0},
  { XK_F23,           XK_NO_MOD,      "\033[23;2~",    0,    0},
  { XK_F24,           XK_NO_MOD,      "\033[24;2~",    0,    0},
  { XK_F25,           XK_NO_MOD,      "\033[1;5P",     0,    0},
  { XK_F26,           XK_NO_MOD,      "\033[1;5Q",     0,    0},
  { XK_F27,           XK_NO_MOD,      "\033[1;5R",     0,    0},
  { XK_F28,           XK_NO_MOD,      "\033[1;5S",     0,    0},
  { XK_F29,           XK_NO_MOD,      "\033[15;5~",    0,    0},
  { XK_F30,           XK_NO_MOD,      "\033[17;5~",    0,    0},
  { XK_F31,           XK_NO_MOD,      "\033[18;5~",    0,    0},
  { XK_F32,           XK_NO_MOD,      "\033[19;5~",    0,    0},
  { XK_F33,           XK_NO_MOD,      "\033[20;5~",    0,    0},
  { XK_F34,           XK_NO_MOD,      "\033[21;5~",    0,    0},
  { XK_F35,           XK_NO_MOD,      "\033[23;5~",    0,    0},
};
#endif // FIXKEYBOARDINPUT_PATCH

/*
 * Selection types' masks.
 * Use the same masks as usual.
 * Button1Mask is always unset, to make masks match between ButtonPress.
 * ButtonRelease and MotionNotify.
 * If no match is found, regular selection is used.
 */
static uint selmasks[] = {
  [SEL_RECTANGULAR] = Mod1Mask,
};

/*
 * Printable characters in ASCII, used to estimate the advance width
 * of single wide characters.
 */
static char ascii_printable[] =
  " !\"#$%&'()*+,-./0123456789:;<=>?"
  "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
  "`abcdefghijklmnopqrstuvwxyz{|}~";

#if RIGHTCLICKTOPLUMB_PATCH
/*
 * plumb_cmd is run on mouse button 3 click, with argument set to
 * current selection and with cwd set to the cwd of the active shell
 */
static char *plumb_cmd = "plumb";
#endif // RIGHTCLICKTOPLUMB_PATCH

#if UNDERCURL_PATCH
/**
 * Undercurl style. Set UNDERCURL_STYLE to one of the available styles.
 *
 * Curly: Dunno how to draw it *shrug*
 *  _   _   _   _
 * ( ) ( ) ( ) ( )
 *   (_) (_) (_) (_)
 *
 * Spiky:
 * /\  /\   /\  /\
 *   \/  \/    \/
 *
 * Capped:
 *  _     _     _
 * / \   / \   / \
 *    \_/   \_/
 */
// Available styles
#define UNDERCURL_CURLY 0
#define UNDERCURL_SPIKY 1
#define UNDERCURL_CAPPED 2
// Active style
#define UNDERCURL_STYLE UNDERCURL_SPIKY
#endif // UNDERCURL_PATCH

/* Material Color UI
red_50           = "#FFEBEE"
red_100          = "#FFCDD2"
red_200          = "#EF9A9A"
red_300          = "#E57373"
red_400          = "#EF5350"
red_500          = "#F44336"
red_600          = "#E53935"
red_700          = "#D32F2F"
red_800          = "#C62828"
red_900          = "#B71C1C"
red_A100         = "#FF8A80"
red_A200         = "#FF5252"
red_A400         = "#FF1744"
red_A700         = "#D50000"

pink_50          = "#FCE4EC"
pink_100         = "#F8BBD0"
pink_200         = "#F48FB1"
pink_300         = "#F06292"
pink_400         = "#EC407A"
pink_500         = "#E91E63"
pink_600         = "#D81B60"
pink_700         = "#C2185B"
pink_800         = "#AD1457"
pink_900         = "#880E4F"
pink_A100        = "#FF80AB"
pink_A200        = "#FF4081"
pink_A400        = "#F50057"
pink_A700        = "#C51162"

purple_50        = "#F3E5F5"
purple_100       = "#E1BEE7"
purple_200       = "#CE93D8"
purple_300       = "#BA68C8"
purple_400       = "#AB47BC"
purple_500       = "#9C27B0"
purple_600       = "#8E24AA"
purple_700       = "#7B1FA2"
purple_800       = "#6A1B9A"
purple_900       = "#4A148C"
purple_A100      = "#EA80FC"
purple_A200      = "#E040FB"
purple_A400      = "#D500F9"
purple_A700      = "#AA00FF"

deep_purple_50   = "#EDE7F6"
deep_purple_100  = "#D1C4E9"
deep_purple_200  = "#B39DDB"
deep_purple_300  = "#9575CD"
deep_purple_400  = "#7E57C2"
deep_purple_500  = "#673AB7"
deep_purple_600  = "#5E35B1"
deep_purple_700  = "#512DA8"
deep_purple_800  = "#4527A0"
deep_purple_900  = "#311B92"
deep_purple_A100 = "#B388FF"
deep_purple_A200 = "#7C4DFF"
deep_purple_A400 = "#651FFF"
deep_purple_A700 = "#6200EA"

indigo_50        = "#E8EAF6"
indigo_100       = "#C5CAE9"
indigo_200       = "#9FA8DA"
indigo_300       = "#7986CB"
indigo_400       = "#5C6BC0"
indigo_500       = "#3F51B5"
indigo_600       = "#3949AB"
indigo_700       = "#303F9F"
indigo_800       = "#283593"
indigo_900       = "#1A237E"
indigo_A100      = "#8C9EFF"
indigo_A200      = "#536DFE"
indigo_A400      = "#3D5AFE"
indigo_A700      = "#304FFE"

blue_50          = "#E3F2FD"
blue_100         = "#BBDEFB"
blue_200         = "#90CAF9"
blue_300         = "#64B5F6"
blue_400         = "#42A5F5"
blue_500         = "#2196F3"
blue_600         = "#1E88E5"
blue_700         = "#1976D2"
blue_800         = "#1565C0"
blue_900         = "#0D47A1"
blue_A100        = "#82B1FF"
blue_A200        = "#448AFF"
blue_A400        = "#2979FF"
blue_A700        = "#2962FF"

light_blue_50    = "#E1F5FE"
light_blue_100   = "#B3E5FC"
light_blue_200   = "#81D4FA"
light_blue_300   = "#4FC3F7"
light_blue_400   = "#29B6F6"
light_blue_500   = "#03A9F4"
light_blue_600   = "#039BE5"
light_blue_700   = "#0288D1"
light_blue_800   = "#0277BD"
light_blue_900   = "#01579B"
light_blue_A100  = "#80D8FF"
light_blue_A200  = "#40C4FF"
light_blue_A400  = "#00B0FF"
light_blue_A700  = "#0091EA"

cyan_50          = "#E0F7FA"
cyan_100         = "#B2EBF2"
cyan_200         = "#80DEEA"
cyan_300         = "#4DD0E1"
cyan_400         = "#26C6DA"
cyan_500         = "#00BCD4"
cyan_600         = "#00ACC1"
cyan_700         = "#0097A7"
cyan_800         = "#00838F"
cyan_900         = "#006064"
cyan_A100        = "#84FFFF"
cyan_A200        = "#18FFFF"
cyan_A400        = "#00E5FF"
cyan_A700        = "#00B8D4"

teal_50          = "#E0F2F1"
teal_100         = "#B2DFDB"
teal_200         = "#80CBC4"
teal_300         = "#4DB6AC"
teal_400         = "#26A69A"
teal_500         = "#009688"
teal_600         = "#00897B"
teal_700         = "#00796B"
teal_800         = "#00695C"
teal_900         = "#004D40"
teal_A100        = "#A7FFEB"
teal_A200        = "#64FFDA"
teal_A400        = "#1DE9B6"
teal_A700        = "#00BFA5"

green_50         = "#E8F5E9"
green_100        = "#C8E6C9"
green_200        = "#A5D6A7"
green_300        = "#81C784"
green_400        = "#66BB6A"
green_500        = "#4CAF50"
green_600        = "#43A047"
green_700        = "#388E3C"
green_800        = "#2E7D32"
green_900        = "#1B5E20"
green_A100       = "#B9F6CA"
green_A200       = "#69F0AE"
green_A400       = "#00E676"
green_A700       = "#00C853"

light_green_50   = "#F1F8E9"
light_green_100  = "#DCEDC8"
light_green_200  = "#C5E1A5"
light_green_300  = "#AED581"
light_green_400  = "#9CCC65"
light_green_500  = "#8BC34A"
light_green_600  = "#7CB342"
light_green_700  = "#689F38"
light_green_800  = "#558B2F"
light_green_900  = "#33691E"
light_green_A100 = "#CCFF90"
light_green_A200 = "#B2FF59"
light_green_A400 = "#76FF03"
light_green_A700 = "#64DD17"

lime_50          = "#F9FBE7"
lime_100         = "#F0F4C3"
lime_200         = "#E6EE9C"
lime_300         = "#DCE775"
lime_400         = "#D4E157"
lime_500         = "#CDDC39"
lime_600         = "#C0CA33"
lime_700         = "#AFB42B"
lime_800         = "#9E9D24"
lime_900         = "#827717"
lime_A100        = "#F4FF81"
lime_A200        = "#EEFF41"
lime_A400        = "#C6FF00"
lime_A700        = "#AEEA00"
yellow_50        = "#FFFDE7"

yellow_100       = "#FFF9C4"
yellow_200       = "#FFF59D"
yellow_300       = "#FFF176"
yellow_400       = "#FFEE58"
yellow_500       = "#FFEB3B"
yellow_600       = "#FDD835"
yellow_700       = "#FBC02D"
yellow_800       = "#F9A825"
yellow_900       = "#F57F17"
yellow_A100      = "#FFFF8D"
yellow_A200      = "#FFFF00"
yellow_A400      = "#FFEA00"
yellow_A700      = "#FFD600"

amber_50         = "#FFF8E1"
amber_100        = "#FFECB3"
amber_200        = "#FFE082"
amber_300        = "#FFD54F"
amber_400        = "#FFCA28"
amber_500        = "#FFC107"
amber_600        = "#FFB300"
amber_700        = "#FFA000"
amber_800        = "#FF8F00"
amber_900        = "#FF6F00"
amber_A100       = "#FFE57F"
amber_A200       = "#FFD740"
amber_A400       = "#FFC400"
amber_A700       = "#FFAB00"

orange_50        = "#FFF3E0"
orange_100       = "#FFE0B2"
orange_200       = "#FFCC80"
orange_300       = "#FFB74D"
orange_400       = "#FFA726"
orange_500       = "#FF9800"
orange_600       = "#FB8C00"
orange_700       = "#F57C00"
orange_800       = "#EF6C00"
orange_900       = "#E65100"
orange_A100      = "#FFD180"
orange_A200      = "#FFAB40"
orange_A400      = "#FF9100"
orange_A700      = "#FF6D00"

deep_orange_50   = "#FBE9E7"
deep_orange_100  = "#FFCCBC"
deep_orange_200  = "#FFAB91"
deep_orange_300  = "#FF8A65"
deep_orange_400  = "#FF7043"
deep_orange_500  = "#FF5722"
deep_orange_600  = "#F4511E"
deep_orange_700  = "#E64A19"
deep_orange_800  = "#D84315"
deep_orange_900  = "#BF360C"
deep_orange_A100 = "#FF9E80"
deep_orange_A200 = "#FF6E40"
deep_orange_A400 = "#FF3D00"
deep_orange_A700 = "#DD2C00"

brown_50         = "#EFEBE9"
brown_100        = "#D7CCC8"
brown_200        = "#BCAAA4"
brown_300        = "#A1887F"
brown_400        = "#8D6E63"
brown_500        = "#795548"
brown_600        = "#6D4C41"
brown_700        = "#5D4037"
brown_800        = "#4E342E"
brown_900        = "#3E2723"

grey_50          = "#FAFAFA"
grey_100         = "#F5F5F5"
grey_200         = "#EEEEEE"
grey_300         = "#E0E0E0"
grey_400         = "#BDBDBD"
grey_500         = "#9E9E9E"
grey_600         = "#757575"
grey_700         = "#616161"
grey_800         = "#424242"
grey_900         = "#212121"

blue_grey_50     = "#ECEFF1"
blue_grey_100    = "#CFD8DC"
blue_grey_200    = "#B0BEC5"
blue_grey_300    = "#90A4AE"
blue_grey_400    = "#78909C"
blue_grey_500    = "#607D8B"
blue_grey_600    = "#546E7A"
blue_grey_700    = "#455A64"
blue_grey_800    = "#37474F"
blue_grey_900    = "#263238"

white            = "#FFFFFF"
black            = "#000000"
*/
