#ifdef INCLUDE_WINDOW_CONFIG

/* default window dimensions (overwritten via -g option): */
static const int WIN_WIDTH  = 800;
static const int WIN_HEIGHT = 600;

/* colors and font can be overwritten via X resource properties.
 * See nsxiv(1), X(7) section Resources and xrdb(1) for more information.
 *                                      X resource            value (NULL == default) */
static const char *WIN_BG[]   = { "Nsxiv.window.background",   "#212121" };
static const char *WIN_FG[]   = { "Nsxiv.window.foreground",   "#f0f0f0" };
static const char *MARK_FG[]  = { "Nsxiv.mark.foreground",      NULL };
#if HAVE_LIBFONTS
static const char *BAR_BG[]   = { "Nsxiv.bar.background",       NULL };
static const char *BAR_FG[]   = { "Nsxiv.bar.foreground",       NULL };
static const char *BAR_FONT[] = { "Nsxiv.bar.font",            "sans-10-antialias=true-hinting=true" };

/* if true, statusbar appears on top of the window */
static const bool TOP_STATUSBAR = false;
#endif /* HAVE_LIBFONTS */

#endif
#ifdef INCLUDE_IMAGE_CONFIG

/* levels (in percent) to use when zooming via '-' and '+':
 * (first/last value is used as min/max zoom level)
 */
static const float zoom_levels[] = {
	 12.5,  25.0,  50.0,  75.0,
	100.0, 150.0, 200.0, 400.0, 800.0
};

/* default slideshow delay (in sec, overwritten via -S option): */
static const int SLIDESHOW_DELAY = 5;

/* color correction: the user-visible ranges [-CC_STEPS, 0] and
 * (0, CC_STEPS] are mapped to the ranges [0, 1], and (1, *_MAX].
 * Higher step count will have higher granulairy.
 */
static const int    CC_STEPS        = 32;
static const double GAMMA_MAX       = 10.0;
static const double BRIGHTNESS_MAX  = 2.0;
static const double CONTRAST_MAX    = 4.0;

/* command i_scroll pans image 1/PAN_FRACTION of screen width/height */
static const int PAN_FRACTION = 5;

/* percentage of memory to use for imlib2's cache size.
 *   3 means use 3% of total memory which is about 245MiB on 8GiB machine.
 *   0 or less means disable cache.
 * 100 means use all available memory (but not above CACHE_SIZE_LIMIT).
 *
 * NOTE: higher cache size means better image reloading performance, but also
 * higher memory usage.
 */
static const int CACHE_SIZE_MEM_PERCENTAGE = 3;          /* use 3% of total memory for cache */
static const int CACHE_SIZE_LIMIT = 256 * 1024 * 1024;   /* but not above 256MiB */
static const int CACHE_SIZE_FALLBACK = 32 * 1024 * 1024; /* fallback to 32MiB if we can't determine total memory */

#endif
#ifdef INCLUDE_OPTIONS_CONFIG

/* if false, pixelate images at zoom level != 100%,
 * toggled with 'a' key binding (overwritten via `--anti-alias` option)
 */
static const bool ANTI_ALIAS = true;

/* if true, use a checkerboard background for alpha layer,
 * toggled with 'A' key binding (overwritten via `--alpha-layer` option)
 */
static const bool ALPHA_LAYER = false;

/* list of whitelisted/blacklisted directory for thumbnail cache
 * (overwritten via --cache-{allow,deny} option).
 * see THUMBNAIL CACHING section in nsxiv(1) manpage for more details.
 */
static const char TNS_FILTERS[] = "";
/* set to true to treat `TNS_FILTERS` as a blacklist instead */
static const bool TNS_FILTERS_IS_BLACKLIST = false;

#endif
#ifdef INCLUDE_THUMBS_CONFIG

/* thumbnail sizes in pixels (width == height): */
static const int thumb_sizes[] = { 32, 64, 96, 128, 160 };

/* thumbnail size at startup, index into thumb_sizes[]: */
static const int THUMB_SIZE = 3;

#endif
#ifdef INCLUDE_MAPPINGS_CONFIG

/* these modifiers will be used when processing keybindings */
static const unsigned int USED_MODMASK = ShiftMask | ControlMask | Mod1Mask;

/* abort the keyhandler */
static const KeySym KEYHANDLER_ABORT = XK_Escape;

/* keyboard mappings for image and thumbnail mode: */
static const keymap_t keys[] = {
	/* modifiers    key               function              argument */
	{ ControlMask,  XK_q,             g_quit,               0 },
	{ 0,            XK_Tab,		  g_switch_mode,        None },
	{ 0,            XK_Return,	  g_switch_mode,        None },
	{ 0,            XK_f,             g_toggle_fullscreen,  None },
	{ ShiftMask,	XK_colon,     	  g_prefix_external,    None },
	{ 0,            XK_g,             g_first,              None },
	{ 0,            XK_G,             g_n_or_last,          None },
	{ 0,            XK_r,             g_reload_image,       None },
	{ 0,  		XK_h,             g_scroll_screen,      DIR_LEFT },
	{ 0,  		XK_j,             g_scroll_screen,      DIR_DOWN },
	{ 0,  		XK_k,             g_scroll_screen,      DIR_UP },
	{ 0,  		XK_l,             g_scroll_screen,      DIR_RIGHT },
	{ 0,  		XK_Left,          g_scroll_screen,      DIR_LEFT },
	{ 0,  		XK_Down,          g_scroll_screen,      DIR_DOWN },
	{ 0,  		XK_Up,            g_scroll_screen,      DIR_UP },
	{ 0,  		XK_Right,         g_scroll_screen,      DIR_RIGHT },
	{ 0,            XK_equal,         g_zoom,               +1 },
	{ 0,            XK_minus,         g_zoom,               -1 },
	{ 0,            XK_BackSpace,     i_set_zoom,           100 },
	{ 0,    	XK_w,             i_fit_to_win,         SCALE_FIT },
	{ 0,            XK_e,             i_fit_to_win,         SCALE_WIDTH },
	{ ControlMask,  XK_period,        g_navigate_marked,    +1 },
	{ ControlMask,  XK_comma,         g_navigate_marked,    -1 },
	{ 0,            XK_h,             t_move_sel,           DIR_LEFT },
	{ 0,            XK_Left,          t_move_sel,           DIR_LEFT },
	{ 0,            XK_j,             t_move_sel,           DIR_DOWN },
	{ 0,            XK_Down,          t_move_sel,           DIR_DOWN },
	{ 0,            XK_k,             t_move_sel,           DIR_UP },
	{ 0,            XK_Up,            t_move_sel,           DIR_UP },
	{ 0,            XK_l,             t_move_sel,           DIR_RIGHT },
	{ 0,            XK_Right,         t_move_sel,           DIR_RIGHT },
	{ 0,            XK_r,             t_reload_all,         None },
	{ 0,            XK_period,        i_navigate,           +1 },
	{ 0,            XK_comma,         i_navigate,           -1 },
	{ 0,            XK_greater,  	  i_navigate,           +10 },
	{ 0,            XK_less,          i_navigate,           -10 },
	{ 0,            XK_h,             i_scroll,             DIR_LEFT },
	{ 0,            XK_Left,          i_scroll,             DIR_LEFT },
	{ 0,            XK_j,             i_scroll,             DIR_DOWN },
	{ 0,            XK_Down,          i_scroll,             DIR_DOWN },
	{ 0,            XK_k,             i_scroll,             DIR_UP },
	{ 0,            XK_Up,            i_scroll,             DIR_UP },
	{ 0,            XK_l,             i_scroll,             DIR_RIGHT },
	{ 0,            XK_Right,         i_scroll,             DIR_RIGHT },
	{ 0,            XK_H,             i_scroll_to_edge,     DIR_LEFT },
	{ 0,            XK_J,             i_scroll_to_edge,     DIR_DOWN },
	{ 0,            XK_K,             i_scroll_to_edge,     DIR_UP },
	{ 0,            XK_L,             i_scroll_to_edge,     DIR_RIGHT },
	{ 0,            XK_z,             i_scroll_to_center,   None },
	{ ControlMask,  XK_h,        	  i_rotate,             DEGREE_270 },
	{ ControlMask,  XK_l,       	  i_rotate,             DEGREE_90 },
	{ ControlMask,  XK_j,             i_flip,               FLIP_HORIZONTAL },
	{ ControlMask,  XK_k,    	  i_flip,               FLIP_VERTICAL },
	{ 0,            XK_a,             i_toggle_antialias,   None },
	{ 0,            XK_z,             i_toggle_alpha,       None },
	{ 0,  		XK_x,             i_toggle_animation,   None },
	{ 0,            XK_s,             i_slideshow,          None },
};

/* mouse button mappings for image mode: */
static const button_t buttons_img[] = {
	/* modifiers    button            function              argument */
	{ 0,            1,                i_cursor_navigate,    None },
	{ ControlMask,  1,                i_drag,               DRAG_RELATIVE },
	{ 0,            2,                i_drag,               DRAG_ABSOLUTE },
	{ 0,            3,                g_switch_mode,        None },
	{ 0,            4,                g_zoom,               +1 },
	{ 0,            5,                g_zoom,               -1 },
};

/* mouse button mappings for thumbnail mode: */
static const button_t buttons_tns[] = {
	/* modifiers    button            function              argument */
	{ 0,            1,                t_select,             None },
	{ 0,            3,                t_drag_mark_image,    None },
	{ 0,            4,                t_scroll,             DIR_UP },
	{ 0,            5,                t_scroll,             DIR_DOWN },
	{ ControlMask,  4,                g_scroll_screen,      DIR_UP },
	{ ControlMask,  5,                g_scroll_screen,      DIR_DOWN },
};

/* true means NAV_WIDTH is relative (33%), false means absolute (33 pixels) */
static const bool NAV_IS_REL = true;
/* width of navigation area, 0 disables cursor navigation, */
static const unsigned int NAV_WIDTH = 33;

/* mouse cursor on left, middle and right part of the window */
static const cursor_t imgcursor[3] = {
	CURSOR_LEFT, CURSOR_ARROW, CURSOR_RIGHT
};

#endif
