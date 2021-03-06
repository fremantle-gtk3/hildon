/*
 * This file is a part of hildon
 *
 * Copyright (C) 2008, 2009 Nokia Corporation, all rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation; version 2 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 */

#ifndef                                         __HILDON_GTK_H__
#define                                         __HILDON_GTK_H__

#include                                        <gtk/gtk.h>

G_BEGIN_DECLS

typedef enum {
  HILDON_SIZE_AUTO_WIDTH       = 0 << 0, /* set to automatic width */
  HILDON_SIZE_HALFSCREEN_WIDTH = 1 << 0, /* set to 50% screen width */
  HILDON_SIZE_FULLSCREEN_WIDTH = 2 << 0, /* set to 100% screen width */
  HILDON_SIZE_AUTO_HEIGHT      = 0 << 2, /* set to automatic height */
  HILDON_SIZE_FINGER_HEIGHT    = 1 << 2, /* set to finger height */
  HILDON_SIZE_THUMB_HEIGHT     = 2 << 2, /* set to thumb height */
  HILDON_SIZE_AUTO             = (HILDON_SIZE_AUTO_WIDTH | HILDON_SIZE_AUTO_HEIGHT)
} HildonSizeType;

typedef enum
{
  HILDON_UI_MODE_NORMAL,
  HILDON_UI_MODE_EDIT
} HildonUIMode;

typedef enum
{
  HILDON_GTK_INPUT_MODE_ALPHA             = 1 << 0,
  HILDON_GTK_INPUT_MODE_NUMERIC           = 1 << 1,
  HILDON_GTK_INPUT_MODE_SPECIAL           = 1 << 2,
  HILDON_GTK_INPUT_MODE_HEXA              = 1 << 3,
  HILDON_GTK_INPUT_MODE_TELE              = 1 << 4,
  HILDON_GTK_INPUT_MODE_FULL              = (HILDON_GTK_INPUT_MODE_ALPHA | HILDON_GTK_INPUT_MODE_NUMERIC | HILDON_GTK_INPUT_MODE_SPECIAL),
  HILDON_GTK_INPUT_MODE_NO_SCREEN_PLUGINS = 1 << 27,
  HILDON_GTK_INPUT_MODE_MULTILINE         = 1 << 28,
  HILDON_GTK_INPUT_MODE_INVISIBLE         = 1 << 29,
  HILDON_GTK_INPUT_MODE_AUTOCAP           = 1 << 30,
  HILDON_GTK_INPUT_MODE_DICTIONARY        = 1 << 31
} HildonGtkInputMode;

GtkWidget *
hildon_gtk_menu_new                             (void);

GtkWidget *
hildon_gtk_button_new                           (HildonSizeType size);

GtkWidget *
hildon_gtk_toggle_button_new                    (HildonSizeType size);

GtkWidget *
hildon_gtk_radio_button_new                     (HildonSizeType  size,
                                                 GSList         *group);

GtkWidget *
hildon_gtk_radio_button_new_from_widget         (HildonSizeType  size,
                                                 GtkRadioButton *radio_group_member);

#ifdef MAEMO_GTK
GtkWidget *
hildon_gtk_tree_view_new                        (HildonUIMode mode);

GtkWidget *
hildon_gtk_tree_view_new_with_model             (HildonUIMode  mode,
                                                 GtkTreeModel *model);

void
hildon_gtk_tree_view_set_ui_mode                (GtkTreeView  *treeview,
                                                 HildonUIMode  mode);

GtkWidget *
hildon_gtk_icon_view_new                        (HildonUIMode mode);

GtkWidget *
hildon_gtk_icon_view_new_with_model             (HildonUIMode  mode,
                                                 GtkTreeModel *model);

void
hildon_gtk_icon_view_set_ui_mode                (GtkIconView  *iconview,
                                                 HildonUIMode  mode);
#endif /* MAEMO_GTK */

void
hildon_gtk_window_set_progress_indicator        (GtkWindow *window,
                                                 guint      state);

void
hildon_gtk_window_set_do_not_disturb            (GtkWindow *window,
                                                 gboolean   dndflag);

/**
 * HildonPortraitFlags:
 *
 * These flags are used to tell the window manager whether the current
 * window needs to be in portrait or landscape mode.
 *
 * If no flags are set then the window is meant to be used in
 * landscape mode only.
 *
 * If %HILDON_PORTRAIT_MODE_REQUEST is set then the window is meant to
 * be used in portrait mode only.
 *
 * If only %HILDON_PORTRAIT_MODE_SUPPORT is set then the current
 * orientation will be kept, no matter if it's portrait or landscape.
 *
 * It is important to note that, while these flags can be used to
 * change between portrait and landscape according to the physical
 * orientation of the display, Hildon does not provide any method to
 * obtain this information.
 **/
typedef enum {
    HILDON_PORTRAIT_MODE_REQUEST = 1 << 0,
    HILDON_PORTRAIT_MODE_SUPPORT = 1 << 1
} HildonPortraitFlags;

void
hildon_gtk_window_set_portrait_flags            (GtkWindow           *window,
                                                 HildonPortraitFlags  portrait_flags);

void
hildon_gtk_window_take_screenshot               (GtkWindow *window,
                                                 gboolean   take);
void
hildon_gtk_window_take_screenshot_sync          (GtkWindow *window,
                                                 gboolean   take);

void
hildon_gtk_window_enable_zoom_keys              (GtkWindow *window,
                                                 gboolean   enable);

GtkWidget*
hildon_gtk_hscale_new                           (void);

GtkWidget*
hildon_gtk_vscale_new                           (void);

G_END_DECLS

#endif /* __HILDON_GTK_H__ */
